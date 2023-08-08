/*
===========================================================================
*/
/**
  @file VCSNPA.c

  NPA-related functions for the VCS driver.
*/
/*
  ====================================================================

  Copyright (c) 2017- 2019 QUALCOMM Technologies Incorporated.  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================
  $Header: //components/rel/boot.xf/3.2/QcomPkg/Drivers/VcsDxe/VCSNPA.c#2 $
  $DateTime: 2019/08/28 08:45:54 $
  $Author: pwbldsvc $
  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "comdef.h"
#include "DDIPlatformInfo.h"
#include "VCSDriver.h"
#include "pmapp_npa.h"
#include "DALDeviceId.h"
#include "DALSys.h"
#include "npa.h"
#include "npa_resource.h"
#include "VCSSWEVT.h"


/*=========================================================================
      Macros
==========================================================================*/

/*
 * Macros for defining NPA fields.
 */
#define VCS_NPA_UNITS_RAIL              "VLVL Corner"
#define VCS_NPA_NAS_TRIGGER_EVENT_NAME  "VCS NAS Event"

/*
 * Helper macros to access the various aggregations.
 * We re-use the SUPPRESSIBLE2 aggregation for the ACTIVE_FLOOR client type.
 * This will suffice as the SUPPRESSIBLE2 type isn't used for VCS resources.
 */
 #define VCS_NPA_INDEX_ACTIVE_FLOOR NPA_SUPPRESSIBLE2_INDEX

 #define VCS_NPA_REQUEST_ACTIVE_FLOOR(r) \
   MIN((r)->internal_state[VCS_NPA_INDEX_ACTIVE_FLOOR], (r)->active_max)

/*=========================================================================
      Type Definitions
==========================================================================*/

typedef boolean (*VCS_NPAStateComparator)(rail_voltage_level eCornerFrom, rail_voltage_level eCornerTo);


/*=========================================================================
      Prototypes
==========================================================================*/

static npa_resource_state VCS_NPAMaxUpdate(npa_resource *resource, npa_client_handle client);
//static npa_resource_state VCS_NPAMapRequest(npa_client_handle client, npa_resource_state);


/*=========================================================================
      Data
==========================================================================*/

static const npa_resource_plugin VCSNPAMaxPlugin =
{
  .update_fcn = VCS_NPAMaxUpdate,
  .supported_clients =
    NPA_CLIENT_REQUIRED |
    NPA_CLIENT_SUPPRESSIBLE |
    NPA_CLIENT_IMPULSE |
    VCS_NPA_CLIENT_ACTIVE_FLOOR,
};

static const npa_client_type eSupportedTypes[] =
{
  NPA_CLIENT_REQUIRED,
  NPA_CLIENT_SUPPRESSIBLE
};

/*=========================================================================
      Functions
==========================================================================*/


/* =========================================================================
**  Function : VCS_NPAMapToInternalIndex
** =========================================================================*/
/**
  This function returns an index value to use when looking up client type
  overall aggregation within the internal data array.

  @param eType [in] -- Client type.

  @return
  Client type index.

  @dependencies
  None.
*/

static uint32 VCS_NPAMapToInternalIndex
(
  npa_client_type eType
)
{
  switch (eType)
  {
    case NPA_CLIENT_REQUIRED:         return NPA_REQUIRED_INDEX;
    case NPA_CLIENT_SUPPRESSIBLE:     return NPA_SUPPRESSIBLE_INDEX;
    case VCS_NPA_CLIENT_ACTIVE_FLOOR: return VCS_NPA_INDEX_ACTIVE_FLOOR;

    default: break;
  }

  DALSYS_LogEvent(
    0,
    DALSYS_LOGEVENT_FATAL_ERROR,
    "Request from unsupported client type[%lu].",
    eType);

  return 0;

} /* END of VCS_NPAMapToInternalIndex */


/* =========================================================================
**  Function : VCS_NPAMaxUpdate
** =========================================================================*/
/**
  This function performs max aggregation of all requests for this resource.

  This function aggregates the client request along with the set of requests
  from all clients of the same type for the same resource and determines the
  maximum value.

  An active floor is applied if any client requested such.

  @param pResource [in] -- Resource being voted on.
  @param hClient [in] -- Client who issued the request.

  @return
  Overall resource aggregation.

  @dependencies
  None.
*/

static npa_resource_state VCS_NPAMaxUpdate
(
  npa_resource      *pResource,
  npa_client_handle  hClient
)
{
  VCSRailNodeType    *pRail;
  npa_resource_state  nRequest, nActiveMax, nPendingMax;
  npa_resource_state  nActiveFloor;
  uint32              i, nIndex;
  npa_client         *c;

  /*-----------------------------------------------------------------------*/
  /* Sanity.                                                               */
  /*-----------------------------------------------------------------------*/

  pRail = VCS_CLIENT_TO_RAIL(hClient);
  if (pRail == NULL)
  {
    DALSYS_LogEvent(
      0,
      DALSYS_LOGEVENT_FATAL_ERROR,
      "No rail definition for resource[%s].",
      pResource->definition->name);

    return pResource->active_state;
  }

  /*-----------------------------------------------------------------------*/
  /* If client requested NPA_MAX_STATE then map to resource max.           */
  /*-----------------------------------------------------------------------*/

  if (NPA_PENDING_REQUEST(hClient).state == NPA_MAX_STATE)
  {
    NPA_PENDING_REQUEST(hClient).state = pResource->definition->max;
  }

  /*-----------------------------------------------------------------------*/
  /* Get type aggregation.                                                 */
  /*-----------------------------------------------------------------------*/

  nIndex = VCS_NPAMapToInternalIndex(hClient->type);
  nRequest = NPA_PENDING_REQUEST(hClient).state;
  nPendingMax = nActiveMax = pResource->internal_state[nIndex];
  nActiveFloor = VCS_NPA_REQUEST_ACTIVE_FLOOR(pResource);

  /*-----------------------------------------------------------------------*/
  /* Client request is new max value.                                      */
  /*-----------------------------------------------------------------------*/

  if (nRequest > nPendingMax)
  {
    nPendingMax = nRequest;
  }

  /*-----------------------------------------------------------------------*/
  /* Reaggregate requests from clients with same type as this client if:   */
  /* 1) This client's prior request was the max overall and is now         */
  /*    adjusting the vote downward.                                       */
  /* 2) The overall aggregation for this client type was adjusted higher   */
  /*    due to the presence of an ACTIVE_FLOOR request.  Reaggregate with  */
  /*    this new client request in case the overall aggregation is OFF in  */
  /*    which case the ACTIVE_FLOOR request would be ignored in the final  */
  /*    state of this client type.                                         */
  /*-----------------------------------------------------------------------*/

  else if (nActiveMax == NPA_ACTIVE_REQUEST(hClient).state ||
           nActiveMax == nActiveFloor)
  {
    npa_client_handle c = pResource->clients;
    nPendingMax = NPA_PENDING_REQUEST(hClient).state;

    /*
     * Iterate over list of clients with same type for new max.
     */
    while (c)
    {
      if (hClient != c && hClient->type == c->type )
      {
        nRequest = NPA_ACTIVE_REQUEST(c).state;
        if (nRequest > nPendingMax )
        {
          nPendingMax = nRequest;
        }
      }
      c = c->next;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Apply BSP min floor to active floor aggregation.                      */
  /*-----------------------------------------------------------------------*/

  if (hClient->type == VCS_NPA_CLIENT_ACTIVE_FLOOR)
  {
    nPendingMax = MAX(nPendingMax, VCS_RESOURCE_MIN(pResource));
  }

  /*-----------------------------------------------------------------------*/
  /* Apply active floor to other client type aggregations.                 */
  /*-----------------------------------------------------------------------*/

  else if (nPendingMax)
  {
    nPendingMax = MAX(nPendingMax, VCS_NPA_REQUEST_ACTIVE_FLOOR(pResource));
  }

  pResource->internal_state[nIndex] = nPendingMax;

  /*-----------------------------------------------------------------------*/
  /* Any change in active floor state -> re-aggregate all requests.        */
  /*-----------------------------------------------------------------------*/

  if (nActiveFloor != VCS_NPA_REQUEST_ACTIVE_FLOOR(pResource))
  {
    for (i = 0; i < ARR_SIZE(eSupportedTypes); i++)
    {
      /*
       * Find max request for this client type.
       */
      for (nPendingMax = 0, c = pResource->clients; c != NULL; c = c->next)
      {
        if (c->type == eSupportedTypes[i] &&
            NPA_ACTIVE_REQUEST(c).state > nPendingMax)
        {
          nPendingMax = NPA_ACTIVE_REQUEST(c).state;
        }
      }

      /*
       * Apply active/min floor.
       */
      if (nPendingMax)
      {
        nPendingMax = MAX(nPendingMax, VCS_NPA_REQUEST_ACTIVE_FLOOR(pResource));
      }

      /*
       * Update internal state.
       */
      nIndex = VCS_NPAMapToInternalIndex(eSupportedTypes[i]);
      pResource->internal_state[nIndex] = nPendingMax;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Find max of all client types.                                         */
  /*-----------------------------------------------------------------------*/

  nPendingMax = 0;
  for (i = 0; i < ARR_SIZE(eSupportedTypes); i++)
  {
    nIndex = VCS_NPAMapToInternalIndex(eSupportedTypes[i]);
    nPendingMax = MAX(nPendingMax, pResource->internal_state[nIndex]);
  }

  return nPendingMax;

} /* END of VCS_NPAMaxUpdate */


/* =========================================================================
**  Function : VCS_NPARequestDependency
** =========================================================================*/
/**
  This function issues to request to satisfy the dependency.
  The request attributes are propagated from the client request.
  Any resource specific data is preserved across the request.

  @param hClient [in] -- Client who issued the request.
  @param hClientDependency [in] -- Client used to issue dependency request.
  @param eCorner [in] -- Corner state to be applied towards the dependency.

  @return
  None.

  @dependencies
  None.
*/
static void VCS_NPARequestDependency
(
  npa_client_handle  hClient,
  npa_client_handle  hClientDependency,
  rail_voltage_level eCorner
)
{
  /*-----------------------------------------------------------------------*/
  /* Propagate all request attributes to dependency client.                */
  /*-----------------------------------------------------------------------*/

  npa_pass_request_attributes(hClient, hClientDependency);

  /*-----------------------------------------------------------------------*/
  /* Copy resource data for cases where rails need to share data.          */
  /*-----------------------------------------------------------------------*/

  hClientDependency->resource_data = hClient->resource_data;

  /*-----------------------------------------------------------------------*/
  /* Issue vote on dependency.                                             */
  /*-----------------------------------------------------------------------*/

  npa_issue_scalar_request(hClientDependency, eCorner);

  /*-----------------------------------------------------------------------*/
  /* Clear shared resource data after dependency satisfied.                */
  /*-----------------------------------------------------------------------*/

  hClientDependency->resource_data = NULL;

} /* END of VCS_NPARequestDependency */


/* =========================================================================
**  Function : VCS_NPASatisfyDependency
** =========================================================================*/
/**
  This function satisfies the dependency according to the comparator type.
  The client handle used to satisfy the dependency is identified from the
  requesting client.

  @param hClient [in] -- Client who issued the request.
  @param pComparator [in] -- Function pointer to comparator type.

  @return
  None.

  @dependencies
  None.
*/
static void VCS_NPASatisfyDependency
(
  npa_client_handle      hClient,
  VCS_NPAStateComparator pComparator
)
{
  uint32               i, j, nIndex;
  rail_voltage_level   eCorner;
  npa_client_handle    hDependency;
  npa_node_dependency *pDependency;
  npa_node_definition *pNode;

  /*-----------------------------------------------------------------------*/
  /* Sanity.                                                               */
  /*-----------------------------------------------------------------------*/

  if (hClient == NULL || pComparator == NULL)
  {
    return;
  }

  /*-----------------------------------------------------------------------*/
  /* Nothing to do if no dependencies for this resource.                   */
  /*-----------------------------------------------------------------------*/

  pNode = hClient->resource->node;
  if (pNode->dependency_count == 0)
  {
    return;
  }

  /*-----------------------------------------------------------------------*/
  /* Update REQUIRED and SUPPRESSIBLE dependencies with new active floor.  */
  /*-----------------------------------------------------------------------*/

  for (i = 0; i < ARR_SIZE(eSupportedTypes); i++)
  {
    /*
     * Find client handle for this supported dependency type.
     */
    hDependency = NULL;
    for (j = 0; j < pNode->dependency_count; j++)
    {
      pDependency = &pNode->dependencies[j];
      if (pDependency != NULL &&
          pDependency->handle != NULL &&
          pDependency->handle->type == eSupportedTypes[i])
      {
        hDependency = pDependency->handle;
      }
    }

    /*
     * Dependency must exist!
     */
    if (hDependency == NULL)
    {
      DALSYS_LogEvent(
        0,
        DALSYS_LOGEVENT_FATAL_ERROR,
        "Supported dependency type missing from rail[%s].",
        VCS_CLIENT_TO_RAIL(hClient));

      return;
    }

    /*
     * Compare new aggregated state to active request for this client type.
     */
    if (hClient->type == hDependency->type ||
        hClient->type == VCS_NPA_CLIENT_ACTIVE_FLOOR)
    {
      nIndex = VCS_NPAMapToInternalIndex(hDependency->type);
      eCorner = hClient->resource->internal_state[nIndex];
      if (pComparator(NPA_ACTIVE_REQUEST(hDependency).state, eCorner))
      {
        VCS_NPARequestDependency(hClient, hDependency, eCorner);
      }
    }
  }

} /* END of VCS_NPASatisfyDependency */


/* =========================================================================
**  Function : VCS_NPAStateIncreasingComparator
** =========================================================================*/
/**
  This function compares two corners and determines whether the new corner
  is greater than the previous.

  @param eCornerFrom [in] -- Current corner.
  @param eCornerTo [in] -- Destination corner.

  @return
  TRUE if new corner is greater than the previous.
  FALSE if new corner is not greater than the previous.

  @dependencies
  None.
*/
static boolean VCS_NPAStateIncreasingComparator
(
  rail_voltage_level eCornerFrom,
  rail_voltage_level eCornerTo
)
{
  return eCornerTo > eCornerFrom;

} /* END of VCS_NPAStateIncreasingComparator */


/* =========================================================================
**  Function : VCS_NPAStateDecreasingComparator
** =========================================================================*/
/**
  This function compares two corners and determines whether the new corner
  is less than the previous.

  @param eCornerFrom [in] -- Current corner.
  @param eCornerTo [in] -- Destination corner.

  @return
  TRUE if new corner is less than the previous.
  FALSE if new corner is not less than the previous.

  @dependencies
  None.
*/
static boolean VCS_NPAStateDecreasingComparator
(
  rail_voltage_level eCornerFrom,
  rail_voltage_level eCornerTo
)
{
  return eCornerTo < eCornerFrom;

} /* END of VCS_NPAStateDecreasingComparator */


/* =========================================================================
**  Function : VCS_NPAStateChangingComparator
** =========================================================================*/
/**
  This function compares two corners and determines whether the new corner
  is different than the previous.

  @param eCornerFrom [in] -- Current corner.
  @param eCornerTo [in] -- Destination corner.

  @return
  TRUE if new corner is different than the previous.
  FALSE if new corner is not different than the previous.

  @dependencies
  None.
*/
static boolean VCS_NPAStateChangingComparator
(
  rail_voltage_level eCornerFrom,
  rail_voltage_level eCornerTo
)
{
  return eCornerTo != eCornerFrom;

} /* END of VCS_NPAStateChangingComparator */

/* =========================================================================
**  Function : VCS_NPASatisfyIncreasingDependency
** =========================================================================*/
/*
  See VCSDriver.h
*/

void VCS_NPASatisfyIncreasingDependency
(
  npa_client_handle hClient
)
{
  VCS_NPASatisfyDependency(hClient, VCS_NPAStateIncreasingComparator);

} /* END of VCS_NPASatisfyIncreasingDependency */


/* =========================================================================
**  Function : VCS_NPASatisfyDecreasingDependency
** =========================================================================*/
/*
  See VCSDriver.h
*/

void VCS_NPASatisfyDecreasingDependency
(
  npa_client_handle hClient
)
{
  VCS_NPASatisfyDependency(hClient, VCS_NPAStateDecreasingComparator);

} /* END of VCS_NPASatisfyDecreasingDependency */


/* =========================================================================
**  Function : VCS_NPASatisfyChangingDependency
** =========================================================================*/
/*
  See VCSDriver.h
*/

void VCS_NPASatisfyChangingDependency
(
  npa_client_handle hClient
)
{
  VCS_NPASatisfyDependency(hClient, VCS_NPAStateChangingComparator);

} /* END of VCS_NPASatisfyChangingDependency */


/* =========================================================================
**  Function : VCS_NPARailResourceDriverFunc
** =========================================================================*/
/**
  Handle request state changes on a rail's NPA resource.

  This is a generic NPA driver function applicable to all rail resources.
  This function does some common record keeping, and makes use of function
  pointers to invoke rail-specific functions to actually set the voltage.

  @param *pResource [in] -- Pointer to rail resource.
  @param  hClient [in] -- Client handle.
  @param  nState [in] -- New request state.

  @return
  New resource state.

  @dependencies
  None.
*/

static npa_resource_state VCS_NPARailResourceDriverFunc
(
  npa_resource       *pResource,
  npa_client_handle   hClient,
  npa_resource_state  nState
)
{
  DALResult                eResult;
  VCSRailNodeType         *pRail;
  rail_voltage_level       eCorner;
  uint32                   nIndex;

  eCorner = (rail_voltage_level)nState;
  pRail = VCS_RESOURCE_TO_RAIL(pResource);

  /*-----------------------------------------------------------------------*/
  /* Short-circuit for IMPULSE client types.                               */
  /*-----------------------------------------------------------------------*/

  if (hClient->type == NPA_CLIENT_IMPULSE)
  {
    return pRail->eCorner;
  }

  /*-----------------------------------------------------------------------*/
  /* Initialize the corner configuration for this rail.                    */
  /*-----------------------------------------------------------------------*/

  if (hClient->type == NPA_CLIENT_INITIALIZE)
  {
    /*
     * Init corner state.
     */
    pRail->eCorner = eCorner;

    /*
     * Init active floor state.
     */
    nIndex = VCS_NPAMapToInternalIndex(VCS_NPA_CLIENT_ACTIVE_FLOOR);
    pResource->internal_state[nIndex] = VCS_RESOURCE_MIN(pResource);

    return pRail->eCorner;
  }

  /*-----------------------------------------------------------------------*/
  /* Log the corner request.                                               */
  /*-----------------------------------------------------------------------*/

  ULOG_RT_PRINTF_7(
    VCS_GetDrvCtxt()->hVCSLog,
    "Rail[%s] change start: Vote[%lu] Aggregation[%lu] Required[%lu] Suppressible[%lu] NAS[%lu] Pre-State[%lu]",
    VCS_RAIL_NAME(pRail),
    NPA_PENDING_REQUEST(hClient).state,
    eCorner,
    NPA_RESOURCE_REQUIRED_REQUEST(pResource),
    NPA_RESOURCE_SUPPRESSIBLE_REQUEST(pResource),
    npa_request_has_attribute(hClient, NPA_REQUEST_NEXT_AWAKE),
    pRail->eCorner);


  /*-----------------------------------------------------------------------*/
  /* Set requested corner.                                                 */
  /*-----------------------------------------------------------------------*/

  if (pRail->pControl &&
      pRail->pControl->fpSetCorner)
  {
    eResult = pRail->pControl->fpSetCorner(hClient, eCorner);
    if (eResult != DAL_SUCCESS)
    {
      DALSYS_LogEvent(
        0,
        DALSYS_LOGEVENT_FATAL_ERROR,
        "DALLOG Device VCS: Unable to set rail[%s] to corner[%lu]",
        VCS_RAIL_NAME(pRail),
        eCorner);

      return (npa_resource_state)pRail->eCorner;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Schedule completion of update complete events on the next wake up.    */
  /*                                                                       */
  /* Note: Rail types that must handle NAS requests locally on wakeup are  */
  /*       required to update eCornerNAS in the SetCorner function.        */
  /*-----------------------------------------------------------------------*/




  

  /*-----------------------------------------------------------------------*/
  /* Log the voltage corner switch.                                        */
  /*-----------------------------------------------------------------------*/

  ULOG_RT_PRINTF_2(
    VCS_GetDrvCtxt()->hVCSLog,
    "Rail[%s] change end: Post-State[%lu]",
    VCS_RAIL_NAME(pRail),
    pRail->eCorner);

  /*-----------------------------------------------------------------------*/
  /* Return the current rail corner.                                       */
  /*-----------------------------------------------------------------------*/

  return (npa_resource_state)pRail->eCorner;

} /* END VCS_NPARailResourceDriverFunc */


/* =========================================================================
**  Function : VCS_NPARailNodeDriverFunc
** =========================================================================*/
/**
  Handle request for a state change on a rail resource.

  This is a generic NPA driver function applicable to all rail resources.

  @param *pResource [in] -- Pointer to rail resource.
  @param  hClient [in] -- Client handle.
  @param  nState [in] -- New request state.

  @return
  New resource state.

  @dependencies
  None.
*/

static npa_resource_state VCS_NPARailNodeDriverFunc
(
  npa_resource       *pResource,
  npa_client_handle   hClient,
  npa_resource_state  nState
)
{
  VCSRailNodeType    *pRail;
  npa_resource_state  nActiveState;

  pRail = (VCSRailNodeType *)pResource->node->data;
  nActiveState = 0;

  /*-----------------------------------------------------------------------*/
  /* Sanity.                                                               */
  /*-----------------------------------------------------------------------*/

  if (pRail == NULL)
  {
    DALSYS_LogEvent(
      0,
      DALSYS_LOGEVENT_FATAL_ERROR,
      "DALLOG Device VCS: Resource[%s] contains NULL node data",
      pResource->definition->name);

    return (npa_resource_state)0;
  }

  if (pResource == VCS_RAIL_HANDLE(pRail))
  {
    nActiveState =
      VCS_NPARailResourceDriverFunc(
        pResource,
        hClient,
        nState);
  }
  else
  {
    DALSYS_LogEvent(
      0,
      DALSYS_LOGEVENT_FATAL_ERROR,
      "DALLOG Device VCS: Unable to process NPA request for resource[%s]",
      pResource->definition->name);
  }

  return nActiveState;

} /* END VCS_NPARailNodeDriverFunc */


/* =========================================================================
**  Function : VCS_NPADefineRailNode
** =========================================================================*/
/*
  Defines the NPA structures for this rail.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.
  @param *pRail [in] -- Pointer to rail being initialized.

  @return
  DAL_SUCCESS -- Successfully initialized the NPA structures for this rail.
  DAL_ERROR_INVALID_PARAMETER -- Invalid pointer.

  @dependencies
  None.
*/

DALResult VCS_NPADefineRailNode
(
  VCSDrvCtxt      *pDrvCtxt,
  VCSRailNodeType *pRail
)
{
  npa_resource_state       anInitialState[VCS_NPA_RAIL_NUM_RESOURCES];
  npa_resource_definition *pResource;

  /*-----------------------------------------------------------------------*/
  /* Sanity.                                                               */
  /*-----------------------------------------------------------------------*/

  if (pRail == NULL)
  {
    return DAL_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Create alias if defined.                                              */
  /*-----------------------------------------------------------------------*/

  if (pRail->szNameAlias)
  {
    npa_alias_resource(pRail->szNameAlias, pRail->mNode.name, NULL);

    return DAL_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Populate rail resource.                                               */
  /*-----------------------------------------------------------------------*/

  pResource = VCS_RAIL_RES_DEF_RAIL(pRail);
  pResource->units = VCS_NPA_UNITS_RAIL;
  pResource->max = VCS_RAIL_MAX(pRail);
  pResource->plugin = &VCSNPAMaxPlugin;
  pResource->data = (npa_user_data)pRail;

  anInitialState[VCS_NPA_RAIL_RES_IDX_RAIL] = 0;

  /*-----------------------------------------------------------------------*/
  /* Populate node information.                                            */
  /*-----------------------------------------------------------------------*/

  pRail->mNode.driver_fcn = VCS_NPARailNodeDriverFunc;
  pRail->mNode.attributes = NPA_NODE_DEFAULT;
  pRail->mNode.data = (npa_user_data)pRail;
  pRail->mNode.dependencies = pRail->aDependencies;
  pRail->mNode.resource_count = VCS_NPA_RAIL_NUM_RESOURCES;
  pRail->mNode.resources = pRail->aResources;

  /*-----------------------------------------------------------------------*/
  /* Define the NPA node.                                                  */
  /*-----------------------------------------------------------------------*/

  npa_define_node(&pRail->mNode, anInitialState, NULL);

  return DAL_SUCCESS;

} /* END VCS_NPADefineRailNode */


/* =========================================================================
**  Function : VCS_InitNPA
** =========================================================================*/
/*
  See VCSDriver.h
*/

DALResult VCS_InitNPA
(
  VCSDrvCtxt *pDrvCtxt
)
{
  uint32           i;
  DALResult        eResult;
  VCSBSPType      *pBSP;
  VCSRailNodeType *pRail;

  pBSP = pDrvCtxt->pBSP;

  /*-----------------------------------------------------------------------*/
  /* Iterate through all the rails to define rail resources.               */
  /*-----------------------------------------------------------------------*/

  for (i = 0; i < pBSP->nNumRails; i++)
  {
    pRail = &pBSP->pRails[i];

    /*
     * Skip rail if not applicable for this HW version.
     */
    if (!VCS_IsBSPSupported(&pRail->HWVersion))
    {
      continue;
    }

    eResult = VCS_NPADefineRailNode(pDrvCtxt, pRail);
    if (eResult != DAL_SUCCESS)
    {
      DALSYS_LogEvent(
        0,
        DALSYS_LOGEVENT_FATAL_ERROR,
        "DALLOG Device VCS: Failed to create NPA resource for rail[%s].",
        VCS_RAIL_NAME(pRail));

      return eResult;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Done.                                                                 */
  /*-----------------------------------------------------------------------*/

  return DAL_SUCCESS;

} /* END VCS_InitNPA */

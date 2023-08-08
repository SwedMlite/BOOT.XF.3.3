/*============================================================================
  FILE:         PilProxyVoteLib.c

  OVERVIEW:     Implement proxy vote

  DEPENDENCIES: None

                Copyright (c) 2019 Qualcomm Technologies, Inc.
                All Rights Reserved.
                Qualcomm Technologies Confidential and Proprietary.
============================================================================*/

#include <Uefi.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <api/systemdrivers/icbarb.h>
#include <Library/BaseLib.h>
#include <Library/npa.h>
#include <Library/voltage_level.h>
#include <Library/MemoryAllocationLib.h>
#include <scm_sip_interface.h>

/*=========================================================================
      Globals and prototypes
==========================================================================*/

#define ADSP_CLIENT_NAME	"PIL_ADSP"
#define CDSP_CLIENT_NAME	"PIL_CDSP"
#define SLPI_CLIENT_NAME	"PIL_SLPI"
#define NPU_CLIENT_NAME		"PIL_NPU"

typedef struct _PIL_NPA_ENTRY_
{
	LIST_ENTRY		List;
	CONST CHAR8*	ClientName;
	CONST CHAR8* 	ResourceName;
	npa_client_handle	Hdl;
} PIL_NPA_ENTRY;

ICBArb_MasterSlaveType aMasterSlave[] =
 { 
	{ ICBID_MASTER_NPU , ICBID_SLAVE_CDSP_CFG } ,
 };

ICBArb_RequestType aRequest[] =
{
	{ ICBARB_REQUEST_TYPE_3, { {100000000, 100000000} } } ,
};

LIST_ENTRY   PILNpaClientList = INITIALIZE_LIST_HEAD_VARIABLE (PILNpaClientList);


STATIC PIL_NPA_ENTRY* SearchForNPAEntry(CONST CHAR8* ClientName, CONST CHAR8* ResourceName)
{
	LIST_ENTRY*			Node;
	PIL_NPA_ENTRY*		Entry, *RetEntry=NULL;
	
	for (Node = GetFirstNode(&PILNpaClientList); !IsNull(&PILNpaClientList, Node); \
						Node = GetNextNode(&PILNpaClientList, Node))
	{
		Entry = BASE_CR(Node, PIL_NPA_ENTRY, List);
		if (AsciiStrLen(ClientName) == AsciiStrLen(Entry->ClientName) && \
			0 == AsciiStrCmp(ClientName, Entry->ClientName) && \
			AsciiStrLen(ResourceName) == AsciiStrLen(Entry->ResourceName) && 
			0 == AsciiStrCmp(ResourceName, Entry->ResourceName))
		{
			RetEntry = Entry;
			break;
		}
	}
	return RetEntry;
}

STATIC npa_client_handle SearchForHdl(CONST CHAR8* ClientName, CONST CHAR8* ResourceName)
{
	npa_client_handle   RetHdl = NULL;
	PIL_NPA_ENTRY*		Entry = SearchForNPAEntry(ClientName, ResourceName);
	if (Entry != NULL)
		RetHdl = Entry->Hdl;
	
	return RetHdl;
}


/**
  do regulator vote 

  @param[in] ClientName         client name used to createt the NPA client
  @param[in] RailName           resource name used to createt the NPA client
  @param[in] Level              Requested resource state
  
  @retval EFI_SUCCESS           success
  @retval otherwise             fail
**/

STATIC EFI_STATUS RegVote(CONST CHAR8* ClientName, CONST CHAR8* RailName, rail_voltage_level Level)
{
	PIL_NPA_ENTRY*	NpaEntry;
	npa_client_handle Hdl = SearchForHdl(ClientName, RailName);
	if (Hdl == NULL)
	{
		Hdl = npa_create_sync_client(RailName, ClientName, NPA_CLIENT_REQUIRED);
		if (Hdl == NULL)
			return EFI_UNSUPPORTED;
		else {
			// add to list
			NpaEntry = AllocateZeroPool(sizeof(PIL_NPA_ENTRY));
			if (NpaEntry==NULL)
			{
				DEBUG(( EFI_D_ERROR, "PilProxyVoteLib: out of memory\n"));
				npa_destroy_client(Hdl);
				return EFI_OUT_OF_RESOURCES;
			}
			
			NpaEntry->ClientName = ClientName;
			NpaEntry->ResourceName = RailName;
			NpaEntry->Hdl = Hdl;
			InsertTailList(&PILNpaClientList, &NpaEntry->List);
		}
	}
	
	npa_issue_scalar_request(Hdl, Level);
	return EFI_SUCCESS;
}


/**
  do regulator unvote 

  @param[in] ClientName         client name used to createt the NPA client
  @param[in] RailName           resource name used to createt the NPA client
  
  @retval EFI_SUCCESS           success
  @retval otherwise             fail
**/
STATIC EFI_STATUS RegUnvote(CONST CHAR8* ClientName, CONST CHAR8* RailName) 
{
	PIL_NPA_ENTRY* NpaEntry = SearchForNPAEntry(ClientName, RailName);
	
	if (NpaEntry == NULL || NpaEntry->Hdl == NULL)
	{
		DEBUG(( EFI_D_ERROR, "%a: NULL Client for%a\r\n", __func__,"PIL proxy"));
		ASSERT(0);
	}
	
	npa_complete_request(NpaEntry->Hdl);
    npa_destroy_client(NpaEntry->Hdl);
	//remove entry
	RemoveEntryList(&NpaEntry->List);
	FreePool(NpaEntry);
	return EFI_SUCCESS;
}


/**
  do ICB vote 

  @param[in] ClientName         client name used to createt the NPA client
  @param[in] RailName           resource name used to createt the NPA client
  
  @retval EFI_SUCCESS           success
  @retval otherwise             fail
**/
STATIC EFI_STATUS IcbVote(CONST CHAR8* ClientName, CONST CHAR8* ResourceName)
{
	PIL_NPA_ENTRY*	NpaEntry;
	npa_client_handle Hdl = SearchForHdl(ClientName, ResourceName);
	if (Hdl == NULL)
	{
		Hdl = npa_create_sync_client_ex(ResourceName, 
									ClientName, 
									NPA_CLIENT_VECTOR,
									sizeof(aMasterSlave),
									&aMasterSlave);
		if (Hdl == NULL)
			return EFI_UNSUPPORTED;
		else {
			NpaEntry = AllocateZeroPool(sizeof(PIL_NPA_ENTRY));
			if (NpaEntry==NULL)
			{
				DEBUG(( EFI_D_ERROR, "PilProxyVoteLib: out of memory\n"));
				npa_destroy_client(Hdl);
				return EFI_OUT_OF_RESOURCES;
			}
			
			NpaEntry->ClientName = ClientName;
			NpaEntry->ResourceName = ResourceName;
			NpaEntry->Hdl = Hdl;
			InsertTailList(&PILNpaClientList, &NpaEntry->List);
		}
	}
	
	npa_issue_vector_request(Hdl, sizeof(aRequest)/sizeof(npa_resource_state),
						  (npa_resource_state *)aRequest );
	return EFI_SUCCESS;
}


/**
  do ICB unvote 

  @param[in] ClientName         client name used to createt the NPA client
  @param[in] RailName           resource name used to createt the NPA client
  
  @retval EFI_SUCCESS           success
  @retval otherwise             fail
**/
STATIC EFI_STATUS IcbUnvote(CONST CHAR8* ClientName, CONST CHAR8* ResourceName)
{
	PIL_NPA_ENTRY* NpaEntry = SearchForNPAEntry(ClientName, ResourceName);
	
	if (NpaEntry == NULL || NpaEntry->Hdl == NULL)
	{
		DEBUG(( EFI_D_ERROR, "%a: NULL Client for%a\r\n", __func__,"PIL proxy"));
		ASSERT(0);
	}
	
	npa_complete_request(NpaEntry->Hdl);
    npa_destroy_client(NpaEntry->Hdl);
	//remove entry
	RemoveEntryList(&NpaEntry->List);
	FreePool(NpaEntry);
	return EFI_SUCCESS;
}

/**
  do proxy vote 

  @param[in] SubsysId           subsystem ID
  
  @retval EFI_SUCCESS           success
  @retval otherwise             fail
**/
EFI_STATUS PILProxyVote(UINT32 SubsysId)
{
	switch (SubsysId)
	{
		case TZ_PIL_AUTH_QDSP6_PROC:
			if (EFI_SUCCESS != RegVote(ADSP_CLIENT_NAME, "/vcs/vdd_lpi_mx", RAIL_VOLTAGE_LEVEL_NOM_L1))
				return EFI_UNSUPPORTED;
			
			if (EFI_SUCCESS != RegVote(ADSP_CLIENT_NAME, "/vcs/vdd_lpi_cx", RAIL_VOLTAGE_LEVEL_NOM_L1))
				return EFI_UNSUPPORTED;
			
			break;
		
		case TZ_PIL_AUTH_SSC_PROC:
			if (EFI_SUCCESS != RegVote(SLPI_CLIENT_NAME, "/vcs/vdd_lpi_mx", RAIL_VOLTAGE_LEVEL_NOM_L1))
				return EFI_UNSUPPORTED;
				
			if (EFI_SUCCESS != RegVote(SLPI_CLIENT_NAME, "/vcs/vdd_lpi_cx", RAIL_VOLTAGE_LEVEL_NOM_L1))
				return EFI_UNSUPPORTED;
				
			break;
			
		case TZ_PIL_AUTH_CDSP_PROC:
			if (EFI_SUCCESS != RegVote(CDSP_CLIENT_NAME, "/vcs/vdd_mx", RAIL_VOLTAGE_LEVEL_NOM))
				return EFI_UNSUPPORTED;
			
			if (EFI_SUCCESS != RegVote(CDSP_CLIENT_NAME, "/vcs/vdd_cx", RAIL_VOLTAGE_LEVEL_NOM))
				return EFI_UNSUPPORTED;
			
			if (EFI_SUCCESS != IcbVote(CDSP_CLIENT_NAME, "/icb/arbiter"))
				return EFI_UNSUPPORTED;
			
			break;
			
		case TZ_PIL_AUTH_NPU_PROC:
		    if (EFI_SUCCESS != RegVote(NPU_CLIENT_NAME, "/vcs/vdd_mx", RAIL_VOLTAGE_LEVEL_NOM))
				return EFI_UNSUPPORTED;
			
			if (EFI_SUCCESS != RegVote(NPU_CLIENT_NAME, "/vcs/vdd_cx", RAIL_VOLTAGE_LEVEL_NOM))
				return EFI_UNSUPPORTED;
			
			if (EFI_SUCCESS != IcbVote(NPU_CLIENT_NAME, "/icb/arbiter"))
				return EFI_UNSUPPORTED;
			
			break;
			
		default:
			return EFI_UNSUPPORTED;
	}
	return EFI_SUCCESS;
}

/**
  do proxy unvote 

  @param[in] SubsysId           subsystem ID
  
  @retval EFI_SUCCESS           success
  @retval otherwise             fail
**/
EFI_STATUS PILProxyUnvote(UINT32 SubsysId)
{
	switch (SubsysId)
	{
		case TZ_PIL_AUTH_QDSP6_PROC:
			if (EFI_SUCCESS != RegUnvote(ADSP_CLIENT_NAME, "/vcs/vdd_lpi_mx"))
				return EFI_UNSUPPORTED;
			
			if (EFI_SUCCESS != RegUnvote(ADSP_CLIENT_NAME, "/vcs/vdd_lpi_cx"))
				return EFI_UNSUPPORTED;
			
			break;
		
		case TZ_PIL_AUTH_SSC_PROC:
			if (EFI_SUCCESS != RegUnvote(SLPI_CLIENT_NAME, "/vcs/vdd_lpi_mx"))
				return EFI_UNSUPPORTED;
				
			if (EFI_SUCCESS != RegUnvote(SLPI_CLIENT_NAME, "/vcs/vdd_lpi_cx"))
				return EFI_UNSUPPORTED;
				
			break;
			
		case TZ_PIL_AUTH_CDSP_PROC:
			if (EFI_SUCCESS != RegUnvote(CDSP_CLIENT_NAME, "/vcs/vdd_mx"))
				return EFI_UNSUPPORTED;
			
			if (EFI_SUCCESS != RegUnvote(CDSP_CLIENT_NAME, "/vcs/vdd_cx"))
				return EFI_UNSUPPORTED;
			
			if (EFI_SUCCESS != IcbUnvote(CDSP_CLIENT_NAME, "/icb/arbiter"))
				return EFI_UNSUPPORTED;
			
			break;
			
		case TZ_PIL_AUTH_NPU_PROC:
		    if (EFI_SUCCESS != RegUnvote(NPU_CLIENT_NAME, "/vcs/vdd_mx"))
				return EFI_UNSUPPORTED;
			
			if (EFI_SUCCESS != RegUnvote(NPU_CLIENT_NAME, "/vcs/vdd_cx"))
				return EFI_UNSUPPORTED;
			
			if (EFI_SUCCESS != IcbUnvote(NPU_CLIENT_NAME, "/icb/arbiter"))
				return EFI_UNSUPPORTED;
			
			break;
			
		default:
			return EFI_UNSUPPORTED;
	}
	return EFI_SUCCESS;
}


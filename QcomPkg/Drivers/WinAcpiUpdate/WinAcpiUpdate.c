/*
  @file WinAcpiUpdate.c
	Copyright (c) 2016-2018 Qualcomm Technologies, Inc.
	All Rights Reserved.
	Qualcomm Technologies Confidential and Proprietary.
  ============================================================================*/
  
  /*=============================================================================
								EDIT HISTORY
  
  
   when 	  who	  what, where, why
   --------   ---	  -----------------------------------------------------------
	 05/04/18   ltg     Added qwpp and qdss option related changes
   02/17/17   vinitb  Added qccdi option related changes
   01/30/17   vinitb  Added sensors/gpu option related changes
   09/30/16   ltg     Added full implementation for patching ACPI, updating UEFI variable, and protocol API's
   08/4/16	 vahidd   Intial Draft for Patching DSDT tables.
  =============================================================================*/


#include <PiDxe.h>
#include <Protocol/AcpiTable.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/HobLib.h>
#include <Protocol/AcpiSystemDescriptionTable.h>
#include <Library/UefiCfgLib.h>
#include <IndustryStandard/Acpi.h>

/**
WinAcpiUpdate PROTOCOL interfaces
*/
#include <Protocol/EfiWinAcpiUpdate.h>

/*Include QC ACPIPlatform Protocol */
#include <Protocol/EFIAcpiPlatform.h>
#include <Library/QcomBaseLib.h>

/*Include Limits Protocol */
#include <Protocol/EFILimits.h>

/* Include ChipInfo Protocol */
#include <Protocol/EFIChipInfo.h>
#include <Protocol/EFIChipInfoTypes.h>

#include "WinAcpiUpdate.h"


EFI_STATUS
GetFeatureVariable(
IN  EFI_WIN_ACPI_UPDATE_PROTOCOL	*This,
IN EFI_FEATURE_TYPE					Type,
OUT  BOOLEAN						*Enable
)
{
	EFI_STATUS Status = EFI_SUCCESS;
	UINTN  VarSize = sizeof(enabledFeatureBitmask);
	Status = gRT->GetVariable(FEATURE_ENABLE_VAR_NAME, &FeatureEnableVarGuid, NULL, &VarSize, &enabledFeatureBitmask);

	if (EFI_ERROR(Status)) {
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate] Error GetFeatureVariable, Status = (0x%x) \r\n", Status));
	}
	else {
		// check if feature's bit is set or not, and set Enable to T/F accordingly
		*Enable = (enabledFeatureBitmask & (0x1 << Type)) ? TRUE : FALSE;
	}

	return Status;
}

EFI_STATUS
SetFeatureVariable(
IN  EFI_WIN_ACPI_UPDATE_PROTOCOL	*This,
IN  EFI_FEATURE_TYPE				Type,
IN  BOOLEAN							Enable
)
{
	EFI_STATUS Status = EFI_SUCCESS;

	// update global variable
	if (Enable == TRUE)
	{
		enabledFeatureBitmask |= (UINT32)(0x1 << Type);
	}
	else
	{
		enabledFeatureBitmask &= (UINT32)(~(0x1 << Type));
	}

	return Status;
}

EFI_STATUS
CommitFeatureVariable(
IN  EFI_WIN_ACPI_UPDATE_PROTOCOL	*This
)
{
	EFI_STATUS Status = EFI_SUCCESS;
	UINTN VarSize = sizeof(enabledFeatureBitmask);
	UINT32 Attributes = (EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS);

	Status = gRT->SetVariable(FEATURE_ENABLE_VAR_NAME, &FeatureEnableVarGuid, Attributes, VarSize, &enabledFeatureBitmask);

	return Status;
}

EFI_STATUS
SetCPUVariable(
IN  EFI_WIN_ACPI_UPDATE_PROTOCOL	*This,
IN  UINT8				        Core,
IN  BOOLEAN							Disable
)
{
	EFI_STATUS Status = EFI_SUCCESS;

	// update global variable
	if (Disable == TRUE)
	{
		defectiveCPUsBitMask |= (UINT32)(0x1 << Core);
	}
	else
	{
		defectiveCPUsBitMask &= (UINT32)(~(0x1 << Core));
	}

	return Status;
}

EFI_STATUS
CommitCPUVariable(
IN  EFI_WIN_ACPI_UPDATE_PROTOCOL	*This
)
{
	EFI_STATUS Status = EFI_SUCCESS;
	UINTN VarSize = sizeof(defectiveCPUsBitMask);
	UINT32 Attributes = (EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS);

	Status = gRT->SetVariable(CPU_ENABLE_VAR_NAME, &CPUEnableVarGuid, Attributes, VarSize, &defectiveCPUsBitMask);

	return Status;
}

EFI_STATUS
SetDefectivePartsVariable(
IN  EFI_WIN_ACPI_UPDATE_PROTOCOL	*This,
IN  EFI_FEATURE_TYPE				Type,
IN  BOOLEAN							Disable
)
{
	EFI_STATUS Status = EFI_SUCCESS;
	UINTN VarSize = sizeof(defectivePartsBitMask);
	UINT32 Attributes = (EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS);

	// update global variable
	if (Disable == TRUE)
	{
		defectivePartsBitMask |= (UINT32)(0x1 << Type);
	}
	else
	{
		defectivePartsBitMask &= (UINT32)(~(0x1 << Type));
	}

	Status = gRT->SetVariable(DEFECTIVE_PARTS_VAR_NAME, &DefectivePartsVarGuid, Attributes, VarSize, &defectivePartsBitMask);

	return Status;
}

/**
EFI_WIN_ACPI_UPDATE Protocol implementation
*/
EFI_WIN_ACPI_UPDATE_PROTOCOL gEfiWinAcpiUpdateProtocol =
{
	EFI_WIN_ACPI_UPDATE_PROTOCOL_REVISION,
	GetFeatureVariable,
	SetFeatureVariable,
	CommitFeatureVariable,
  SetCPUVariable,
  CommitCPUVariable,
	SetDefectivePartsVariable
};

UINT32  GetTotalNumCPU(VOID)
{
	return FixedPcdGet32(PcdNumCpus);
}

static
EFI_STATUS
isSTAHandle(
IN EFI_ACPI_HANDLE AcpiHandle,
OUT BOOLEAN *isSTA
)
{
	EFI_STATUS Status = EFI_SUCCESS;
	EFI_ACPI_DATA_TYPE DataType;
	CONST UINT8 *Data;
	UINTN DataSize;

	*isSTA = FALSE;

  if (AcpiHandle == NULL)
  {
    goto Error;
  }

	Status = gAcpiSdt->GetOption(AcpiHandle, 0, &DataType, (CONST VOID **) &Data, &DataSize);
	if (EFI_ERROR(Status)){
    DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]isSTAHandle: gAcpiSdt->GetOption failed, Status = (0x%x) \r\n", Status));
    goto Error;
	}
	if ((DataType == EFI_ACPI_DATA_TYPE_OPCODE) && (Data[0] == AML_METHOD_OP)) {
		Status = gAcpiSdt->GetOption(AcpiHandle, 1, &DataType, (CONST VOID **) &Data, &DataSize);
		if (EFI_ERROR(Status)){
      DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]isSTAHandle: gAcpiSdt->GetOption failed, Status = (0x%x) \r\n", Status));
      goto Error;
		}
		if (0 == CompareMem("_STA", Data, DataSize)) {
			*isSTA = TRUE;
		}
	}
Error:
	return Status;
}

static
EFI_STATUS
UpdateACPIGlobal(
IN EFI_ACPI_HANDLE AcpiHandle,
IN BOOLEAN Enabled
)
{
	EFI_STATUS Status = EFI_SUCCESS;
	EFI_ACPI_DATA_TYPE DataType;
	CONST UINT8 *Data;
	UINTN DataSize;
	UINT8 GlobalValue;
	UINTN i = 0;

	if (NULL == AcpiHandle) {
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate] UpdateACPIGlobal: Handle is NULL. Exiting.\n"));
		goto Error;
	}

	// first make sure this is a NAME opcode
	Status = gAcpiSdt->GetOption(AcpiHandle, i, &DataType, (CONST VOID **) &Data, &DataSize);
	if (EFI_ERROR(Status)) {
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateACPIGlobal: Error finding data (opcode for name operation)\n"));
	}
	else {
		if ((DataType != EFI_ACPI_DATA_TYPE_OPCODE) || (Data[0] != AML_NAME_OP)) {
			DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateACPIGlobal: Unexpected data found\n"));
			goto Error;
		}
	}

	// go through indices until we find the value of the global var
	while (DataType != EFI_ACPI_DATA_TYPE_CHILD){
		i++;
		Status = gAcpiSdt->GetOption(AcpiHandle, i, &DataType, (CONST VOID **) &Data, &DataSize);
		if (EFI_ERROR(Status)) {
			DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateACPIGlobal: Error finding data\n"));
		}
	}

	if (Enabled) {
		GlobalValue = 0x1;
	}
	else {
		GlobalValue = 0x0;
	}

	if (Data[0] != GlobalValue) {
		Status = gAcpiSdt->SetOption(AcpiHandle, i, &GlobalValue, sizeof(GlobalValue));
		if ((EFI_ERROR(Status))) {
			DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateACPIGlobal: Error setting global variable value\n"));
			goto Error;
		}
	}

Error:
	if (AcpiHandle){
		gAcpiSdt->Close(AcpiHandle);
	}
	return Status;
}

static
EFI_STATUS
UpdateSTA(
IN EFI_ACPI_HANDLE STAAcpiHandle,
IN BOOLEAN Enabled
)
{
	EFI_ACPI_HANDLE ReturnAcpiHandle = NULL;
	EFI_ACPI_HANDLE ValueAcpiHandle = NULL;
	EFI_ACPI_DATA_TYPE DataType;
	CONST UINT8 *Data;
	UINTN DataSize;
	UINT8 STAValue;
	EFI_STATUS Status = EFI_SUCCESS;

	if (NULL == STAAcpiHandle) 
	{
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate] UpdateSTA: Handle is NULL. Exiting.\n"));
		goto Error;
	}

	Status = gAcpiSdt->GetChild(STAAcpiHandle, &ReturnAcpiHandle);
	if (EFI_ERROR(Status) || (NULL == ReturnAcpiHandle))
	{
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateSTA: No child found\n"));
		goto Error;
	}

	Status = gAcpiSdt->GetOption(ReturnAcpiHandle, 0, &DataType, (CONST VOID **) &Data, &DataSize);
	if ((EFI_ERROR(Status)))
	{
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateSTA: Error finding data (opcode for return statement)\n"));
		goto Error;
	}
	if ((DataType != EFI_ACPI_DATA_TYPE_OPCODE) || (Data[0] != AML_RETURN_OP))
	{
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateSTA: Unexpected data found\n"));
		goto Error;
	}

	Status = gAcpiSdt->GetChild(ReturnAcpiHandle, &ValueAcpiHandle);
	if ((EFI_ERROR(Status)) || (NULL == ValueAcpiHandle))
	{
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateSTA: No child found\n\n"));
		goto Error;
	}

	Status = gAcpiSdt->GetOption(ValueAcpiHandle, 0, &DataType, (CONST VOID **) &Data, &DataSize);
	if ((EFI_ERROR(Status)))
	{
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateSTA: Error finding data\n"));
		goto Error;
	}
	if ((DataType != EFI_ACPI_DATA_TYPE_OPCODE) || (Data[0] != AML_BYTE_PREFIX))
	{
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateSTA: Unexpected data found\n"));
		goto Error;
	}

	// get the value of the return statement
	Status = gAcpiSdt->GetOption(ValueAcpiHandle, 1, &DataType, (CONST VOID **) &Data, &DataSize);
	if ((EFI_ERROR(Status)))
	{
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateSTA: Error finding data (STA return value)\n"));
		goto Error;
	}

	if ((DataType == EFI_ACPI_DATA_TYPE_UINT) && (DataSize == 1)) 
	{
		if (Enabled) 
		{
			STAValue = Data[0];
		}
		else 
		{
			STAValue = 0x0;
		}
		if (Data[0] != STAValue) 
		{
			Status = gAcpiSdt->SetOption(ValueAcpiHandle, 1, &STAValue, sizeof(STAValue));
			if ((EFI_ERROR(Status))){
				DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateSTA: Error setting STA return value\n"));
				goto Error;
			}
		}
	}
	else 
	{
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateSTA: Unexpected data found (STA return value)\n"));
		goto Error;
	}

Error:
	if (ValueAcpiHandle)
	{
		gAcpiSdt->Close(ValueAcpiHandle);
	}
	if (ReturnAcpiHandle)
	{
		gAcpiSdt->Close(ReturnAcpiHandle);
	}
  return Status;
}

static
EFI_STATUS
UpdateACPI(
IN EFI_ACPI_HANDLE AcpiHandle,
IN BOOLEAN Enabled
)
{
	/*
	Check if there is an STA method for this feature:
	If there is one, then use UpdateSTA to patch ACPI
	If there isn't one, then use UpdateACPIGlobal to patch ACPI
	*/
	BOOLEAN isSTA = FALSE;
	EFI_STATUS Status = EFI_SUCCESS;

	if (AcpiHandle == NULL)
	{
		DEBUG((EFI_D_WARN, "[WinAcpiUpdate] UpdateACPI: Handle is NULL. Exiting.\n"));
		return Status;
	}

	Status = isSTAHandle(AcpiHandle, &isSTA);
	if (EFI_ERROR(Status)){
		DEBUG((EFI_D_WARN, "[WinAcpiUpdate]UpdateACPI: Error finding STA method. Exiting.\n"));
		return Status;
	}
	if (FALSE == isSTA) {
		Status = UpdateACPIGlobal(AcpiHandle, Enabled);
	}
	else{
		Status = UpdateSTA(AcpiHandle, Enabled);
	}
  return Status;
}

// Using device's AcpiHandle provided, returns if device is currently 
// enabled or disabled in ACPI
static
EFI_STATUS
GetCurrentStatus(
IN EFI_ACPI_HANDLE AcpiHandle,
OUT BOOLEAN *Enabled
)
{
	EFI_ACPI_HANDLE ReturnAcpiHandle = NULL;
	EFI_ACPI_HANDLE ValueAcpiHandle = NULL;
	EFI_ACPI_DATA_TYPE DataType;
	CONST UINT8 *Data;
	UINTN DataSize;
	EFI_STATUS Status = EFI_SUCCESS;
	UINTN i = 0;
	BOOLEAN isSTA = FALSE;

  // if AcpiHandle is invalid, Exit
  if (AcpiHandle == NULL){
		goto Exit;
  }

	// check if this is a direct handle to _STA
	Status = isSTAHandle(AcpiHandle, &isSTA);
	if (EFI_ERROR(Status)){
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetCurrentStatus: Error finding STA method. Exiting.\n"));
		goto Exit;
	}

	if (isSTA == FALSE)
  {
		// check if this is a global variable
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetCurrentStatus: No STA Method found. Checking if this is set using a global variable...\n"));
		Status = gAcpiSdt->GetOption(AcpiHandle, 0, &DataType, (CONST VOID **) &Data, &DataSize);
		if (EFI_ERROR(Status)){
			DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetCurrentStatus: Error finding data. Exiting.\n"));
			goto Exit;
		}
		if ((DataType != EFI_ACPI_DATA_TYPE_OPCODE) || (Data[0] != AML_NAME_OP)) {
			DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetCurrentStatus: No global variable found. Exiting.\n"));
			goto Exit;
		}
		DEBUG((EFI_D_INFO, "[WinAcpiUpdate]GetCurrentStatus: Global variable found!\n"));

		// search for the value of this global variable
		while (DataType != EFI_ACPI_DATA_TYPE_CHILD){
			i++;
			Status = gAcpiSdt->GetOption(AcpiHandle, i, &DataType, (CONST VOID **) &Data, &DataSize);
			if (EFI_ERROR(Status)) {
				DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetCurrentStatus: Error finding data\n"));
			}
		}
		*Enabled = (Data[0] != 0x0);
		goto Exit;
	}
  else
  {
    Status = gAcpiSdt->GetChild(AcpiHandle, &ReturnAcpiHandle);
    if (EFI_ERROR(Status)) {
      DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetCurrentStatus: No child found\n"));
      goto Exit;
    }

    Status = gAcpiSdt->GetOption(ReturnAcpiHandle, 0, &DataType, (CONST VOID **) &Data, &DataSize);
    if (EFI_ERROR(Status)) {
      DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetCurrentStatus: Error finding data (opcode for return statement)\n"));
      goto Exit;
    }
    if ((DataType != EFI_ACPI_DATA_TYPE_OPCODE) || (Data[0] != AML_RETURN_OP)){
      DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetCurrentStatus: Error finding data (opcode for return statement) - Unexpected data found\n"));
      goto Exit;
    }

    Status = gAcpiSdt->GetChild(ReturnAcpiHandle, &ValueAcpiHandle);
    if ((EFI_ERROR(Status)) || (NULL == ValueAcpiHandle)){
      DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetCurrentStatus: No child found\n\n"));
      goto Exit;
    }

    Status = gAcpiSdt->GetOption(ValueAcpiHandle, 0, &DataType, (CONST VOID **) &Data, &DataSize);
    if (EFI_ERROR(Status)){
      DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetCurrentStatus: Error finding data (prefix for return value)\n"));
      goto Exit;
    }
    if ((DataType != EFI_ACPI_DATA_TYPE_OPCODE) || (Data[0] != AML_BYTE_PREFIX)){
      DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetCurrentStatus: Error finding data (prefix for return value) - Unexpected data found\n"));
      goto Exit;
    }

    // get the value of the return statement
    Status = gAcpiSdt->GetOption(ValueAcpiHandle, 1, &DataType, (CONST VOID **) &Data, &DataSize);
    if (EFI_ERROR(Status)){
      DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetCurrentStatus: Error finding data (STA return value)\n"));
      goto Exit;
    }
    if ((DataType == EFI_ACPI_DATA_TYPE_UINT) && (DataSize == 1)) {
      *Enabled = (Data[0] != 0x0);
    }
    else {
      DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetCurrentStatus: Error finding data (STA return value) - Unexpected data found\n"));
      goto Exit;
    }
  }
Exit:
	if (ValueAcpiHandle){
		gAcpiSdt->Close(ValueAcpiHandle);
	}
	if (ReturnAcpiHandle){
		gAcpiSdt->Close(ReturnAcpiHandle);
	}

	return Status;
}

// Reads appropriate ACPI node (like _STA or as coded) for each FEATURE/DEVICE and based on value read
// updates the corresponding feature's bit position in enabledFeatureBitmask (1 for enabled, 0 for disabled)
EFI_STATUS
InitFeatureVariable(
IN EFI_ACPI_HANDLE					AcpiHandle
)
{
	EFI_STATUS Status = EFI_SUCCESS;
	EFI_ACPI_HANDLE OutHandle = NULL;
	UINTN  VarSize = sizeof(enabledFeatureBitmask);
	UINT32 Attributes = (EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS);
	BOOLEAN enabled = FALSE;

	// loop through all features, check in ACPI if it is enabled/disabled by default, and construct global variable
	for (int i = 0; i < EFI_FEATURE_MAX; i++)
	{
		Status = gAcpiSdt->FindPath(AcpiHandle, (UINT8*)DEVICE_LIST[i], &OutHandle);
		if (EFI_ERROR(Status))
		{
			DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]InitFeatureVariable: Error gAcpiSdt->FindPath, Status = (0x%x) \r\n", Status));
			continue;
		}

		// check ACPI for status of feature (enabled/disabled)
		Status = GetCurrentStatus(OutHandle, &enabled);
		if (EFI_ERROR(Status)) {
			DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]InitFeatureVariable: Error getting current feature config, GetCurrentStatus Status = (0x%x) \r\n", Status));
			continue;
		}

		// update global variable
		if (enabled == TRUE)
		{
			enabledFeatureBitmask |= (UINT32)(0x1 << i);
		}
		else
		{
			enabledFeatureBitmask &= (UINT32)(~(0x1 << i));
		}
	}

	// create the uefi variable
	Status = gRT->SetVariable(FEATURE_ENABLE_VAR_NAME, &FeatureEnableVarGuid, Attributes, VarSize, &enabledFeatureBitmask);
	if (EFI_ERROR(Status)) {
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]InitFeatureVariable: Error gRT->SetVariable, Status = (0x%x) \r\n", Status));
	}

	if (OutHandle){
		gAcpiSdt->Close(OutHandle);
	}
	return Status;
}

static 
EFI_STATUS
UpdateDsdtTable(
  IN EFI_ACPI_SDT_HEADER *Table,  
  IN EFI_ACPI_TABLE_VERSION Version,  
  IN UINTN TableKey )
{
	EFI_STATUS Status = EFI_SUCCESS;
	EFI_ACPI_HANDLE AcpiHandle = NULL;
	EFI_ACPI_HANDLE OutHandle = NULL;
	UINTN  VarSize = sizeof(enabledFeatureBitmask);
	UINT32 enable = 0x1; //used to toggle feature if it's defective

	// open handle with top node of DSDT table
	Status = gAcpiSdt->Open((VOID*)(UINTN)Table+sizeof(EFI_ACPI_SDT_HEADER),&AcpiHandle);
	if (EFI_ERROR (Status))
	{
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateDsdtTable: Error opening the handle for DSDT tables \r\n"));
		goto Error;
	}

	// get uefi variable for bitmask of defective parts
	Status = gRT->GetVariable(DEFECTIVE_PARTS_VAR_NAME, &DefectivePartsVarGuid, NULL, &VarSize, &defectivePartsBitMask);
	if (EFI_ERROR(Status))
	{
		DEBUG((EFI_D_WARN, "[WinAcpiUpdate]UpdateDsdtTable: Error gRT->GetVariable, Status = (0x%x) \r\n", Status));
		defectivePartsBitMask = 0x0;
	}

	// get uefi variable for bitmask of features
	Status = gRT->GetVariable(FEATURE_ENABLE_VAR_NAME, &FeatureEnableVarGuid, NULL, &VarSize, &enabledFeatureBitmask);
	if (EFI_ERROR(Status)) 
	{
		DEBUG((EFI_D_WARN, "[WinAcpiUpdate]UpdateDsdtTable: Error gRT->GetVariable, Status = (0x%x) \r\n", Status));

		// if this failed because the variable doesn't exist, we should create it here
		if (Status == EFI_NOT_FOUND){
			Status = InitFeatureVariable(AcpiHandle);
			if (EFI_ERROR(Status)){
				DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateDsdtTable: Error InitFeatureVariable, Status = (0x%x) \r\n", Status));
				goto Error;
			}
			DEBUG((EFI_D_INFO, "[WinAcpiUpdate]UpdateDsdtTable: Created enabledFeatureBitmask UEFI variable with value (0x%x) \r\n", enabledFeatureBitmask));
		}
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateDsdtTable: Disabling features with defectivePartsBitMask (0x%x)\r\n", defectivePartsBitMask));

		// check if there are any defective parts
		for (int i = 0; i < EFI_FEATURE_MAX; i++)
		{
			if((defectivePartsBitMask >> i) & 0x1)
			{
				DEBUG((EFI_D_INFO, "[WinAcpiUpdate]UpdateDsdtTable: Disabling defective part (0x%x) \r\n", i));
				Status = gAcpiSdt->FindPath(AcpiHandle,(UINT8*)DEVICE_LIST[i],&OutHandle);
				if(EFI_ERROR(Status))
				{
					DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateDsdtTable: Error gAcpiSdt->FindPath, Status = (0x%x) \r\n", Status));
          goto Error;
        }

        // Apply mask
        Status = UpdateACPI(OutHandle, FALSE);
        if(EFI_ERROR(Status))
        {
          DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateDsdtTable: UpdateACPI failed, Status = (0x%x) \r\n", Status));
          goto Error;
        }
			}
		}
		goto Error;
	}
  DEBUG((EFI_D_INFO, "[WinAcpiUpdate]UpdateDsdtTable: Enabling features with enabledFeatureBitmask (0x%x)\r\n", enabledFeatureBitmask));
	DEBUG((EFI_D_INFO, "[WinAcpiUpdate]UpdateDsdtTable: Disabling features with defectivePartsBitMask (0x%x)\r\n", defectivePartsBitMask));

	// loop through features and apply config based on enabledFeatureBitmask & defectiveParts value
	for (int i = 0; i < EFI_FEATURE_MAX; i++)
	{
		Status = gAcpiSdt->FindPath(AcpiHandle,(UINT8*)DEVICE_LIST[i],&OutHandle);
		if(EFI_ERROR(Status))
		{
			DEBUG((EFI_D_ERROR, "[WinAcpiUpdate] Error gAcpiSdt->FindPath, Status = (0x%x) \r\n", Status));
      continue;
		}

    enable = 0x1; //assume part is non-defective
		if((defectivePartsBitMask >> i) & 0x1) //if part is defective
		{
			DEBUG((EFI_D_INFO, "[WinAcpiUpdate]UpdateDsdtTable: Defective part (0x%x) will be disabled\r\n", i));
			enable = 0x0;
		}
		Status = UpdateACPI(OutHandle, ((enabledFeatureBitmask >> i) & enable));
    if(EFI_ERROR(Status))
    {
      DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateDsdtTable: UpdateACPI failed, Status = (0x%x) \r\n", Status));
      goto Error;
    }
  }

Error:
	if (AcpiHandle){
		gAcpiSdt->Close(AcpiHandle);
	}
	if (OutHandle){
		gAcpiSdt->Close(OutHandle);
	}
	return Status;
}

static VOID PrintBlobInfo(ACPI_MULTIPLE_APIC_DESCRIPTION_TABLE *Blob)
{
	UINT8 i=0;
	DEBUG((EFI_D_INFO, "[WinAcpiUpdate]PrintBlobInfo: Printing Only Flags Information from Blob \r\n"));
	for (i = 0; i<NUM_CPU;i++)
	{
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]PrintBlobInfo: LocalGic[%d]: Flag=0x%x, ProcessorID:0x%x \r\n",
															i,
															Blob->LocalGic[i].Flags,
															Blob->LocalGic[i].AcpiProcessorId));			
	}
}

static
EFI_STATUS
UpdateMadtTable(
  IN EFI_ACPI_6_1_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER *Table,
  IN EFI_ACPI_TABLE_VERSION Version,
  IN UINTN TableKey )
  {
    EFI_STATUS Status = EFI_SUCCESS;
    UINTN  VarSize = sizeof(defectiveCPUsBitMask);
    UINT32 Attributes = (EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS);
    UINT8 CPUDisableMask = 0x0;
    ACPI_MULTIPLE_APIC_DESCRIPTION_TABLE* madt = (ACPI_MULTIPLE_APIC_DESCRIPTION_TABLE*) Table;

    // PrintBlobInfo(madt);
    // get uefi variable for bitmask of cpus
    Status = gRT->GetVariable(CPU_ENABLE_VAR_NAME, &CPUEnableVarGuid, NULL, &VarSize, &CPUDisableMask);
    if (EFI_ERROR(Status))
    {
      DEBUG((EFI_D_WARN, "[WinAcpiUpdate]UpdateMadtTable: Error gRT->GetVariable, Status = (0x%x) \r\n", Status));

      // if this failed because the variable doesn't exist, we should create it here and set it to defectiveCPUsBitMask
      if (Status == EFI_NOT_FOUND){
        CPUDisableMask = 0x0;
        Status = gRT->SetVariable(CPU_ENABLE_VAR_NAME, &CPUEnableVarGuid, Attributes, VarSize, &CPUDisableMask);
        if (EFI_ERROR(Status)){
          DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateMadtTable: Error gRT->SetVariable, Status = (0x%x) \r\n", Status));
          goto Error;
        }
        DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateMadtTable: Created CPUDisableMask UEFI variable with value (0x%x) \r\n", CPUDisableMask));
      }
    }
    //CPUDisableMask = 96; //0x60 or 01100000, which is test value to disable 2 of the gold cores (5 and 6) out of 8 total cores
    DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateMadtTable: Disabling CPUs with CPUDisableMask (0x%x)\r\n", CPUDisableMask));

    //If there are some defective CPUs, disable those
    for (int i = 0; i < NUM_CPU; i++)
    {
      if((CPUDisableMask >> i) & 0x1)
      {
        DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateMadtTable: Disabling defective CPU (0x%x) \r\n", i));
        madt->LocalGic[i].Flags = 0x0;
        DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateMadtTable: Disabling Processor 0x%x madt->LocalGic[i].Flags =0x%x \r\n",
          madt->LocalGic[i].AcpiProcessorId,
          madt->LocalGic[i].Flags));
      }
    }
    Error:
      return Status;
  }

static
EFI_STATUS
EFIAPI
AcpiNotification (
	IN EFI_ACPI_SDT_HEADER *Table,
	IN EFI_ACPI_TABLE_VERSION Version,
	IN UINTN TableKey)
{
	EFI_STATUS Status = EFI_SUCCESS;

	if (Table->Signature == EFI_ACPI_6_1_DIFFERENTIATED_SYSTEM_DESCRIPTION_TABLE_SIGNATURE){
		Status = UpdateDsdtTable(Table,Version,TableKey);
	}
  else if (Table->Signature == EFI_ACPI_6_1_MULTIPLE_APIC_DESCRIPTION_TABLE_SIGNATURE) {
		Status = UpdateMadtTable((EFI_ACPI_6_1_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER *) Table, Version, TableKey);
	}

	return Status;
}

static VOID updateDefectivePartsMask (IN  EFIChipInfoPartType defectivePart)
{
	switch(defectivePart)
		{
			case EFICHIPINFO_PART_GPU:
	  	case EFICHIPINFO_PART_VIDEO:
			case EFICHIPINFO_PART_DISPLAY:
  			defectivePartsBitMask |= (UINT32)(0x1 << EFI_FEATURE_GPU);
  			DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]AcpiMADTCallback: Marking EFI_FEATURE_GPU for disabling. Updated defectivePartsBitMask to (0x%x) \r\n", defectivePartsBitMask));
  			break;
  		case EFICHIPINFO_PART_CAMERA:
  			defectivePartsBitMask |= (UINT32)(0x1 << EFI_FEATURE_FRONT_CAMERA);
  			defectivePartsBitMask |= (UINT32)(0x1 << EFI_FEATURE_BACK_CAMERA);  //Verify with ChipInfo if EFICHIPINFO_PART_CAMERA means both cameras
  			DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]AcpiMADTCallback: Marking EFI_FEATURE_FRONT_CAMERA and EFI_FEATURE_BACK_CAMERA for disabling. Updated defectivePartsBitMask to (0x%x) \r\n", defectivePartsBitMask));
  			break;
  		case EFICHIPINFO_PART_AUDIO:
  			defectivePartsBitMask |= (UINT32)(0x1 << EFI_FEATURE_AUDIO);
  			DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]AcpiMADTCallback: Marking EFI_FEATURE_AUDIO for disabling. Updated defectivePartsBitMask to (0x%x) \r\n", defectivePartsBitMask));
  			break;
      case EFICHIPINFO_PART_MODEM:
  			defectivePartsBitMask |= (UINT32)(0x1 << EFI_FEATURE_MODEM);
  			DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]AcpiMADTCallback: Marking EFI_FEATURE_MODEM for disabling. Updated defectivePartsBitMask to (0x%x) \r\n", defectivePartsBitMask));
  			break;
      case EFICHIPINFO_PART_WLAN:
        defectivePartsBitMask |= (UINT32)(0x1 << EFI_FEATURE_WLAN);
        DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]AcpiMADTCallback: Marking EFI_FEATURE_WLAN for disabling. Updated defectivePartsBitMask to (0x%x) \r\n", defectivePartsBitMask));
        break;
      case EFICHIPINFO_PART_COMP:
        defectivePartsBitMask |= (UINT32)(0x1 << EFI_FEATURE_CDSP);
        DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]AcpiMADTCallback: Marking EFI_FEATURE_CDSP for disabling. Updated defectivePartsBitMask to (0x%x) \r\n", defectivePartsBitMask));
        break;
      case EFICHIPINFO_PART_SENSORS:
        defectivePartsBitMask |= (UINT32)(0x1 << EFI_FEATURE_SENSORS);
        DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]AcpiMADTCallback: Marking EFI_FEATURE_SENSORS for disabling. Updated defectivePartsBitMask to (0x%x) \r\n", defectivePartsBitMask));
        break;
      case EFICHIPINFO_PART_NPU:
        defectivePartsBitMask |= (UINT32)(0x1 << EFI_FEATURE_NPU);
        DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]AcpiMADTCallback: Marking EFI_FEATURE_NPU for disabling. Updated defectivePartsBitMask to (0x%x) \r\n", defectivePartsBitMask));
        break;
      case EFICHIPINFO_PART_SPSS:
        defectivePartsBitMask |= (UINT32)(0x1 << EFI_FEATURE_SPSS);
        DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]AcpiMADTCallback: Marking EFI_FEATURE_SPSS for disabling. Updated defectivePartsBitMask to (0x%x) \r\n", defectivePartsBitMask));
        break;
			default:
				break;
		}
	
	return;
}


static
EFI_STATUS
GetDefectiveParts(VOID)
{
	EFI_STATUS Status = EFI_SUCCESS;
	UINT32 nMask = 0x0;
	UINTN  VarSize = sizeof(defectivePartsBitMask);
	UINT32 Attributes = (EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS);

	// get mask from uefi var
	Status = gRT->GetVariable(DEFECTIVE_PARTS_VAR_NAME, &DefectivePartsVarGuid, NULL, &VarSize, &defectivePartsBitMask);
	if (EFI_ERROR(Status))
	{
		DEBUG((EFI_D_WARN, "[WinAcpiUpdate]GetDefectiveParts: Error gRT->GetVariable, Status = (0x%x) \r\n", Status));

		// call chipinfo protocol
		// loop through all features, check in ACPI if it is enabled/disabled by default, and construct global variable
		for (int i = 0; i < EFICHIPINFO_NUM_PARTS; i++)
		{
			Status = pChipInfoProtocol->GetDefectivePart(pChipInfoProtocol, i, &nMask);
			if (EFI_ERROR(Status))
			{
				DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetDefectiveParts: GetDefectivePart failed, Status = (0x%x), default to Non-Defective Part (0x%x) \r\n", Status, i));
			}
			else
			{
				// nMask is non-zero if the part is defective. "non-zero" currently means 1, but that might change in the future
				// if more granularity is needed to determine defectiveness
				if (nMask != 0)
				{
					DEBUG((EFI_D_INFO, "[WinAcpiUpdate]GetDefectiveParts: GetDefectivePart got Defective Part (0x%x) \r\n", i));
					updateDefectivePartsMask((EFIChipInfoPartType)i);  //updates defectivePartsBitMask for defective part
				}
				else
				{
					DEBUG((EFI_D_INFO, "[WinAcpiUpdate]GetDefectiveParts: GetDefectivePart got Non-Defective Part (0x%x) \r\n", i));
				}
			}
		}

		// set value of uefi variable
		Status = gRT->SetVariable(DEFECTIVE_PARTS_VAR_NAME, &DefectivePartsVarGuid, Attributes, VarSize, &defectivePartsBitMask);
		if (EFI_ERROR(Status)){
			DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetDefectiveParts: Error gRT->SetVariable, Status = (0x%x) \r\n", Status));
		}
	}
	return Status;
}

static
EFI_STATUS
GetDefectiveCPUs(VOID)
{
	EFI_STATUS Status = EFI_SUCCESS;
  EFI_LIMITS_PROTOCOL	*pEfiLimitsProtocol = NULL;
  UINT32 APC1Throttle = 0, ACP1ThrottleValue= 0 ;
	UINTN  VarSize = sizeof(defectiveCPUsBitMask);
	UINT32 Attributes = (EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS);

  // Locate the Limits protocol
  Status = gBS->LocateProtocol(&gEfiLimitsProtocolGuid, NULL, (VOID**) &pEfiLimitsProtocol);
  if (EFI_ERROR(Status))
  {
    DEBUG((EFI_D_WARN, "[WinAcpiUpdate]GetDefectiveCPUs: Locate Limits Protocol failed, Status = (0x%x)\r\n", Status));
  }
  else // if protocol is found, find the APC1 throttle and disable gold cores if leakage is at max
  {
    Status = pEfiLimitsProtocol->SubSysThrottle(pEfiLimitsProtocol,
                             EFI_LIMITS_SUBSYS_APC1,
                             &APC1Throttle,
                             &ACP1ThrottleValue);
    if (EFI_ERROR(Status))
    {
      DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetDefectiveCPUs: pEfiLimitsProtocol->SubSysThrottle failed, Status = (0x%x)\r\n", Status));
    }
    if(APC1Throttle == EFI_LIMITS_THROTTLE_MAX_DISABLE)
    {
      DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetDefectiveCPUs: Leakage Value for this Part is more than 10x - Leaving Gold CPUs disabled\r\n"));
      defectiveCPUsBitMask = 0xF0; // Gold cores disabled
      goto Exit;
    }
  }

	// get mask from uefi var
	Status = gRT->GetVariable(CPU_ENABLE_VAR_NAME, &CPUEnableVarGuid, NULL, &VarSize, &defectiveCPUsBitMask);
	if (EFI_ERROR(Status))
	{
		DEBUG((EFI_D_WARN, "[WinAcpiUpdate]GetDefectiveCPUs: Error gRT->GetVariable, Status = (0x%x) \r\n", Status));

		// call chipinfo protocol
	  Status = pChipInfoProtocol->GetDefectiveCPUs(pChipInfoProtocol, cluster_num, &defectiveCPUsBitMask);
	  if (EFI_ERROR(Status))
	  {
	    DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetDefectiveCPUs: GetDefectiveCPUs call failed, Status = (0x%x)\r\n", Status));
	  }
	  else
	  {
	    if (defectiveCPUsBitMask != 0x0)
	    {
	      DEBUG((EFI_D_INFO, "[WinAcpiUpdate]GetDefectiveCPUs: GetDefectiveCPUs got Defective CPU (0x%x) \r\n", defectiveCPUsBitMask));
	    }
	    else
	    {
	      DEBUG((EFI_D_INFO, "[WinAcpiUpdate]GetDefectiveCPUs: GetDefectiveCPUs got Non-Defective CPU (0x%x) \r\n", defectiveCPUsBitMask));
	    }
	  }
	}

Exit:
	Status = gRT->SetVariable(CPU_ENABLE_VAR_NAME, &CPUEnableVarGuid, Attributes, VarSize, &defectiveCPUsBitMask);
	if (EFI_ERROR(Status)){
		DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]GetDefectiveCPUs: Error gRT->SetVariable, Status = (0x%x) \r\n", Status));
	}
	return Status;
}

EFI_STATUS
EFIAPI
UpdateACPIEntry (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
)
{
   EFI_STATUS Status = EFI_SUCCESS;

   Status = gBS->InstallMultipleProtocolInterfaces(&ImageHandle,
	   &gEfiWinAcpiUpdateProtocolGuid,
	   (void *)&gEfiWinAcpiUpdateProtocol,
	   NULL);

   if (EFI_ERROR(Status)) {
	   DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateACPIEntry: Install WinAcpiUpdate Protocol failed, Status = (0x%x)\r\n", Status));
	   goto Error;
   }

   // Locate ACPI SDT Protocol and register for callback for loading of ACPI tables
   Status = gBS->LocateProtocol(&gEfiAcpiSdtProtocolGuid, NULL, (VOID**)&gAcpiSdt);
   if (EFI_ERROR(Status)) {
     DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateACPIEntry: Locate SDT Protocol failed, Status = (0x%x)\r\n", Status));
	   goto Error;
   }

   // Register callback for when any ACPI table is loaded
   gAcpiSdt->RegisterNotify(TRUE,AcpiNotification);

   // Locate ChipInfo Protocol to get Defective Parts and CPUs
   Status = gBS->LocateProtocol(&gEfiChipInfoProtocolGuid, NULL, (VOID **) &pChipInfoProtocol);
   if (EFI_ERROR(Status))
   {
	 DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateACPIEntry: Locate ChipInfo Protocol failed, Status = (0x%x)\r\n", Status));
	 goto Error; 
   }

   // Get defective parts
   Status = GetDefectiveParts();
   if (EFI_ERROR(Status))
   {
     defectivePartsBitMask = 0x0;
  	 DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateACPIEntry: GetDefectiveParts failed, Status = (0x%x)\r\n", Status));
  	 DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateACPIEntry: Using Default defectivePartsBitMask = (0x%x)\r\n", defectivePartsBitMask));
   }
   DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateACPIEntry: GetDefectiveParts succeeded returning defectivePartsBitMask = (0x%x)\r\n", defectivePartsBitMask));

   // Get defective CPUs
   Status = GetDefectiveCPUs();
   if (EFI_ERROR(Status))
   {
    defectiveCPUsBitMask = 0x0;
    DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateACPIEntry: GetDefectiveCPUs failed, Status = (0x%x)\r\n", Status));
    DEBUG((EFI_D_ERROR, "[WinAcpiUpdate]UpdateACPIEntry: Using Default defectiveCPUsBitMask = (0x%x)\r\n", defectiveCPUsBitMask));
   }
   DEBUG((EFI_D_INFO, "[WinAcpiUpdate]UpdateACPIEntry: GetDefectiveCPUs succeeded returning defectiveCPUsBitMask = (0x%x)\r\n", defectiveCPUsBitMask));

Error:
  	return Status;
  
}

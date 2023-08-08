

/*! @file PmicGpioProtocol.c 

*  PMIC-GPIO MODULE RELATED DECLARATION
*  This file contains functions and variable declarations to support 
*  the PMIC GPIO module.
*
* Copyright (c) 2011-2019 Qualcomm Technologies, Inc.  All Rights Reserved. 
* Qualcomm Technologies Proprietary and Confidential.
*/

/*===========================================================================

						EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when	   who	   what, where, why
--------   ---	   ---------------------------------------------------------- 
13/12/13   aa	   PmicLib Dec Addition
06/18/13   al	   Adding API for enabling/disabling dtest line for dig in
01/22/13   al	   Added real time interrupt status
10/25/12   al	   File renamed 
07/27/12   al	   Commented out not regquired for 8974 and compiling for 8960
11/29/11   sm	   Added GpioGetStatus API
05/11/11   dy	   New file.
===========================================================================*/

/*===========================================================================

					 INCLUDE FILES FOR MODULE

===========================================================================*/
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include "pm_gpio.h"
#include "pm_uefi.h"

#include <Protocol/EFIPmicGpio.h>


/*===========================================================================
				  EXTERNAL FUNCTION DECLARATIONS
===========================================================================*/

/**
  EFI_PmGpioEnable()

  @brief
  Enable implementation of EFI_QCOM_PMIC_GPIO_PROTOCOL
 */
EFI_STATUS
EFIAPI
EFI_PmGpioEnable
(
 IN UINT32                   PmicDeviceIndex, 
 IN EFI_PM_GPIO_PERIPH_INDEX Gpio, 
 IN BOOLEAN                  Enable
)
{
	pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

	errFlag = pm_gpio_enable(PmicDeviceIndex, 
		                     (pm_gpio_perph_index) Gpio, 
		                      Enable);

	if (errFlag != PM_ERR_FLAG_SUCCESS)
		{
		return EFI_DEVICE_ERROR;
		}

	return EFI_SUCCESS;
}


/**
  EFI_PmGpioCfgMode()

  @brief
  CfgMode implementation of EFI_QCOM_PMIC_GPIO_PROTOCOL
 */
EFI_STATUS EFIAPI EFI_PmGpioCfgMode
(
 IN UINT32                   PmicDeviceIndex, 
 IN EFI_PM_GPIO_PERIPH_INDEX Gpio, 
 IN EFI_PM_GPIO_CONFIG_TYPE  GpioConfigType
)
{
	pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

	errFlag = pm_gpio_cfg_mode(PmicDeviceIndex, 
		                       (pm_gpio_perph_index) Gpio, 
		                       (pm_gpio_config_type) GpioConfigType);

	if (errFlag != PM_ERR_FLAG_SUCCESS)
		{
		return EFI_DEVICE_ERROR;
		}

	return EFI_SUCCESS;
}


/**
  EFI_PmGpioLevelStatus()

  @brief
  LevelStatus implementation of EFI_QCOM_PMIC_GPIO_PROTOCOL
 */
EFI_STATUS
EFIAPI 
EFI_PmGpioInputLevelStatus
(
 IN  UINT32                   PmicDeviceIndex, 
 IN  EFI_PM_GPIO_PERIPH_INDEX Gpio, 
 OUT EFI_PM_GPIO_LEVEL_TYPE   *GpioLevelStatus
)
{
	pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

	errFlag = pm_gpio_input_level_status(PmicDeviceIndex, 
		                                 (pm_gpio_perph_index) Gpio, 
		                                 (pm_gpio_level_type *) GpioLevelStatus);

	if (errFlag != PM_ERR_FLAG_SUCCESS)
		{
		return EFI_DEVICE_ERROR;
		}

	return EFI_SUCCESS;
}

/**
  EFI_PmGpioIrqEnable()

  @brief
  GpioIrqEnable implementation of EFI_QCOM_PMIC_GPIO_PROTOCOL
 */
EFI_STATUS 
EFIAPI 
EFI_PmGpioIrqEnable
(
 IN UINT32                   PmicDeviceIndex, 
 IN EFI_PM_GPIO_PERIPH_INDEX Gpio, 
 IN BOOLEAN                  Enable
)
{
	pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

	errFlag = pm_gpio_irq_enable(PmicDeviceIndex, 
		                         (pm_gpio_perph_index) Gpio,
		                         (boolean) Enable);

	if (errFlag != PM_ERR_FLAG_SUCCESS)
		{
		return EFI_DEVICE_ERROR;
		}

	return EFI_SUCCESS;
}

/**
  EFI_PmGpioIrqClear()

  @brief
  GpioIrqClear implementation of EFI_QCOM_PMIC_GPIO_PROTOCOL
 */
EFI_STATUS 
EFIAPI 
EFI_PmGpioIrqClear
(
 IN UINT32                   PmicDeviceIndex, 
 IN EFI_PM_GPIO_PERIPH_INDEX Gpio
)
{
	pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

	errFlag = pm_gpio_irq_clear(PmicDeviceIndex, (pm_gpio_perph_index) Gpio);

	if (errFlag != PM_ERR_FLAG_SUCCESS)
		{
		return EFI_DEVICE_ERROR;
		}

	return EFI_SUCCESS;
}



/**
  EFI_PmGpioIrqSetTrigger()

  @brief
  GpioIrqSetTrigger implementation of EFI_QCOM_PMIC_GPIO_PROTOCOL
 */
EFI_STATUS 
EFIAPI 
EFI_PmGpioIrqSetTrigger
(
 IN UINT32                   PmicDeviceIndex, 
 IN EFI_PM_GPIO_PERIPH_INDEX Gpio, 
 IN EFI_PM_IRQ_TRIGGER_TYPE  Trigger
)
{
	pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

	errFlag = pm_gpio_irq_set_trigger(PmicDeviceIndex,
		                              (pm_gpio_perph_index) Gpio, 
		                              (pm_irq_trigger_type) Trigger);

	if (errFlag != PM_ERR_FLAG_SUCCESS)
		{
		return EFI_DEVICE_ERROR;
		}

	return EFI_SUCCESS;
}


/**
  EFI_PmGpioIrqStatus()

  @brief
  PmGpioIrqStatus implementation of EFI_QCOM_PMIC_GPIO_PROTOCOL
 */
EFI_STATUS 
EFIAPI 
EFI_PmGpioIrqStatus
( 
 IN UINT32                    PmicDeviceIndex, 
 IN EFI_PM_GPIO_PERIPH_INDEX  Gpio, 
 IN EFI_PM_IRQ_STATUS_TYPE    Type, 
 OUT BOOLEAN                  *Status
)
{
	pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

	errFlag = pm_gpio_irq_status(PmicDeviceIndex, 
		                         (pm_gpio_perph_index) Gpio,
		                         (pm_irq_status_type) Type, 
		                         (boolean *) Status);

	if (errFlag != PM_ERR_FLAG_SUCCESS)
		{
		return EFI_DEVICE_ERROR;
		}

	return EFI_SUCCESS;
}


/**
  EFI_PmGpioSetVoltageSource()

  @brief
  SetVoltageSource implementation of EFI_QCOM_PMIC_GPIO_PROTOCOL
 */
EFI_STATUS 
EFIAPI 
EFI_PmGpioSetVoltageSource
(
 IN UINT32                    PmicDeviceIndex, 
 IN EFI_PM_GPIO_PERIPH_INDEX  Gpio,
 IN EFI_PM_GPIO_VOLT_SRC_TYPE GpioVoltageSource
 )
{
	pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

	errFlag = pm_gpio_set_voltage_source(PmicDeviceIndex, 
		                                 (pm_gpio_perph_index) Gpio, 
		                                 (pm_gpio_volt_src_type) GpioVoltageSource);

	if (errFlag != PM_ERR_FLAG_SUCCESS)
		{
		return EFI_DEVICE_ERROR;
		}

	return EFI_SUCCESS;
}


/**
  EFI_PmGpioSetOutBufCfg()

  @brief
  SetOutBufCfg implementation of EFI_QCOM_PMIC_GPIO_PROTOCOL
 */
EFI_STATUS 
EFIAPI 
EFI_PmGpioSetOutBufCfg
(
IN UINT32                       PmicDeviceIndex, 
IN EFI_PM_GPIO_PERIPH_INDEX     Gpio, 
IN EFI_PM_GPIO_OUT_BUF_CFG_TYPE GpioOutBufferConfig
)
{
	pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

	errFlag = pm_gpio_set_out_buf_cfg(PmicDeviceIndex, 
		                              (pm_gpio_perph_index) Gpio, 
		                              (pm_gpio_out_buf_cfg_type) GpioOutBufferConfig);

	if (errFlag != PM_ERR_FLAG_SUCCESS)
		{
		return EFI_DEVICE_ERROR;
		}

	return EFI_SUCCESS;
}


/**
  EFI_PmGpioSetOutputLevel()

  @brief
  SetOutputLevel implementation of EFI_QCOM_PMIC_GPIO_PROTOCOL
 */
EFI_STATUS 
EFIAPI 
EFI_PmGpioSetOutputLevel
(
 IN UINT32                   PmicDeviceIndex, 
 IN EFI_PM_GPIO_PERIPH_INDEX Gpio, 
 IN EFI_PM_GPIO_LEVEL_TYPE   GpioLevel
)
{
	pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

	errFlag = pm_gpio_set_output_level(PmicDeviceIndex, 
		                               (pm_gpio_perph_index) Gpio, 
		                               (pm_gpio_level_type) GpioLevel);

	if (errFlag != PM_ERR_FLAG_SUCCESS)
		{
		return EFI_DEVICE_ERROR;
		}

	return EFI_SUCCESS;
}



/**
  EFI_PmGpioSetOutDrvStr()

  @brief
  SetOutDrvStr implementation of EFI_QCOM_PMIC_GPIO_PROTOCOL
 */
EFI_STATUS
EFIAPI 
EFI_PmGpioSetOutDrvStr
(
 IN UINT32                       PmicDeviceIndex, 
 IN EFI_PM_GPIO_PERIPH_INDEX     Gpio, 
 IN EFI_PM_GPIO_OUT_DRV_STR_TYPE GpioOutDrvStr
)
{
	pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

	errFlag = pm_gpio_set_out_drv_str(PmicDeviceIndex, 
		                              (pm_gpio_perph_index) Gpio, 
		                              (pm_gpio_out_drv_str_type) GpioOutDrvStr);

	if (errFlag != PM_ERR_FLAG_SUCCESS)
		{
		return EFI_DEVICE_ERROR;
		}

	return EFI_SUCCESS;
}


/**
  EFI_PmGpioSetOutSrcCfg()

  @brief
  SetOutSrcCfg implementation of EFI_QCOM_PMIC_GPIO_PROTOCOL
 */
EFI_STATUS 
EFIAPI 
EFI_PmGpioSetOutSrcCfg
(
 IN UINT32                   PmicDeviceIndex, 
 IN EFI_PM_GPIO_PERIPH_INDEX Gpio, 
 IN EFI_PM_GPIO_SRC_CFG_TYPE GpioSource
)
{
	pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

	errFlag = pm_gpio_set_out_src_cfg(PmicDeviceIndex, 
		                              (pm_gpio_perph_index) Gpio, 
		                              (pm_gpio_src_cfg_type) GpioSource);

	if (errFlag != PM_ERR_FLAG_SUCCESS)
		{
		return EFI_DEVICE_ERROR;
		}

	return EFI_SUCCESS;
}


/**
  EFI_PmGpioStatusGet()

  @brief
  StatusGet implementation of EFI_QCOM_PMIC_GPIO_PROTOCOL
 */
EFI_STATUS 
EFIAPI 
EFI_PmGpioStatusGet
(
 IN UINT32                   PmicDeviceIndex, 
 IN EFI_PM_GPIO_PERIPH_INDEX Gpio, 
 OUT EFI_PM_GPIO_STATUS_TYPE *GPIOType
)
{
	pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

	errFlag = pm_gpio_status_get(PmicDeviceIndex,  
		                         (pm_gpio_perph_index) Gpio,
		                         (pm_gpio_status_type *) GPIOType);

	if (errFlag != PM_ERR_FLAG_SUCCESS)
		{
		return EFI_DEVICE_ERROR;
		}

	return EFI_SUCCESS;
}


/**
  PMIC GPIO UEFI Protocol implementation
 */
EFI_QCOM_PMIC_GPIO_PROTOCOL PmicGpioProtocolImplementation =
{
	PMIC_GPIO_REVISION, 
	EFI_PmGpioEnable, 
	EFI_PmGpioCfgMode, 
	EFI_PmGpioInputLevelStatus, 
	EFI_PmGpioIrqEnable, 
	EFI_PmGpioIrqClear, 
	EFI_PmGpioIrqSetTrigger, 
	EFI_PmGpioIrqStatus, 
	EFI_PmGpioSetVoltageSource, 
	EFI_PmGpioSetOutBufCfg, 
	EFI_PmGpioSetOutputLevel,
	EFI_PmGpioSetOutDrvStr, 
	EFI_PmGpioSetOutSrcCfg, 
	EFI_PmGpioStatusGet, 
};


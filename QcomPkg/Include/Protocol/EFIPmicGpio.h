/** 
  @file  EFIPmicGpio.h
  @brief PMIC GPIO EFI Protocol for UEFI.
*/
/*=============================================================================
  Copyright (c) 2011-2019 Qualcomm Technologies, Incorporated.
  All rights reserved.
  Qualcomm Technologies, Confidential and Proprietary.
=============================================================================*/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 09/09/16   al      Updating GUID
 10/30/13   ajs     (Tech Pubs) Edited/added Doxygen comments and markup.
 06/18/13   al      Adding API for enabling/disabling dtest line for dig in
 02/27/13   al      Adding IRQ related APIs 
 01/22/13   al      Added real time interrupt status
 10/16/12   al      Fixed out buffer drive strength enum
 08/14/12   llg     (Tech Pubs) Edited/added Doxygen comments and markup.
 07/27/12   al      Commented out not regquired for 8974 and compiling for 8960
 05/03/12   vishalo Merge in Techpubs Doxygen change
 04/19/12   llg     (Tech Pubs) Edited/added Doxygen comments and markup.
 01/26/12   vishalo Merge in Techpubs Doxygen change
 11/29/11   sm      Added GpioGetStatus API
 11/02/11   llg     (Tech Pubs) Edited/added Doxygen comments and markup.
 05/11/11   dy      created

=============================================================================*/

#ifndef __EFIPMICGPIO_H__
#define __EFIPMICGPIO_H__


/*===========================================================================
  INCLUDE FILES
===========================================================================*/
#include "PmicIrq.h"

/*===========================================================================
  MACRO DECLARATIONS
===========================================================================*/
/** @addtogroup efi_pmicGpio_constants 
@{ */
/**
  Protocol version.
*/
#define PMIC_GPIO_REVISION 0x0000000000010001
/** @} */ /* end_addtogroup efi_pmicGpio_constants */

/*  Protocol GUID definition */
/** @ingroup efi_pmicGpio_protocol */
#define EFI_PMIC_GPIO_PROTOCOL_GUID \
     { 0x4BC5C6D7, 0x4CA4, 0x8835, { 0xD1, 0xBC, 0xD2, 0x9C, 0xC2, 0x02, 0x5D, 0x4A } }


/** @cond */
/*===========================================================================
  EXTERNAL VARIABLES
===========================================================================*/
/**
  External reference to the PMIC GPIO Protocol GUID.
*/
extern EFI_GUID gQcomPmicGpioProtocolGuid;


/*===========================================================================
  TYPE DEFINITIONS
===========================================================================*/
/**
  Protocol declaration.
*/
typedef struct _EFI_QCOM_PMIC_GPIO_PROTOCOL   EFI_QCOM_PMIC_GPIO_PROTOCOL;
/** @endcond */

/** @addtogroup efi_pmicGpio_data_types 
@{ */
/** 
  GPIO type.
*/
typedef enum
{
  EFI_PM_GPIO_1,  /**< GPIO 1. */
  EFI_PM_GPIO_2,  /**< GPIO 2. */
  EFI_PM_GPIO_3,  /**< GPIO 3. */
  EFI_PM_GPIO_4,  /**< GPIO 4. */
  EFI_PM_GPIO_5,  /**< GPIO 5. */
  EFI_PM_GPIO_6,  /**< GPIO 6. */
  EFI_PM_GPIO_7,  /**< GPIO 7. */
  EFI_PM_GPIO_8,  /**< GPIO 8. */
  EFI_PM_GPIO_9,  /**< GPIO 9. */
  EFI_PM_GPIO_10, /**< GPIO 10. */
  EFI_PM_GPIO_11, /**< GPIO 11. */
  EFI_PM_GPIO_12, /**< GPIO 12. */
  EFI_PM_GPIO_13, /**< GPIO 13. */
  EFI_PM_GPIO_14, /**< GPIO 14. */
  EFI_PM_GPIO_15, /**< GPIO 15. */
  EFI_PM_GPIO_16, /**< GPIO 16. */
  EFI_PM_GPIO_17, /**< GPIO 17. */
  EFI_PM_GPIO_18, /**< GPIO 18. */
  EFI_PM_GPIO_19, /**< GPIO 19. */
  EFI_PM_GPIO_20, /**< GPIO 20. */
  EFI_PM_GPIO_21, /**< GPIO 21. */
  EFI_PM_GPIO_22, /**< GPIO 22. */
  EFI_PM_GPIO_23, /**< GPIO 23. */
  EFI_PM_GPIO_24, /**< GPIO 24. */
  EFI_PM_GPIO_25, /**< GPIO 25. */
  EFI_PM_GPIO_26, /**< GPIO 26. */
  EFI_PM_GPIO_27, /**< GPIO 27. */
  EFI_PM_GPIO_28, /**< GPIO 28. */
  EFI_PM_GPIO_29, /**< GPIO 29. */
  EFI_PM_GPIO_30, /**< GPIO 30. */
  EFI_PM_GPIO_31, /**< GPIO 31. */
  EFI_PM_GPIO_32, /**< GPIO 32. */
  EFI_PM_GPIO_33, /**< GPIO 33. */
  EFI_PM_GPIO_34, /**< GPIO 34. */
  EFI_PM_GPIO_35, /**< GPIO 35. */
  EFI_PM_GPIO_36, /**< GPIO 36. */
  EFI_PM_GPIO_37, /**< GPIO 37. */
  EFI_PM_GPIO_38, /**< GPIO 38. */
  EFI_PM_GPIO_39, /**< GPIO 39. */
  EFI_PM_GPIO_40, /**< GPIO 40. */
  EFI_PM_GPIO_41, /**< GPIO 41. */
  EFI_PM_GPIO_42, /**< GPIO 42. */
  EFI_PM_GPIO_43, /**< GPIO 43. */
  EFI_PM_GPIO_44,  /**< GPIO 44. */
  EFI_PM_GPIO_INVALID
}EFI_PM_GPIO_PERIPH_INDEX;

/** Select GPIO I/O type
*/
typedef enum
{
    EFI_PM_GPIO_DIG_IN,
    EFI_PM_GPIO_DIG_OUT,
    EFI_PM_GPIO_DIG_IN_OUT,
    EFI_PM_GPIO_ANA_PASS_THRU,
    EFI_PM_GPIO_TYPE_INVALID
} EFI_PM_GPIO_CONFIG_TYPE;

/** Select voltage source.
*/
typedef enum
{
    EFI_PM_GPIO_VIN0,  /**< Voltage input 0. */
    EFI_PM_GPIO_VIN1,  /**< Voltage input 1. */
    EFI_PM_GPIO_VIN_INVALID
}EFI_PM_GPIO_VOLT_SRC_TYPE;

/** Input/Output level Status.
*/
typedef enum
{
    EFI_PM_GPIO_LEVEL_LOW,             /**< Level of pin is low. */
    EFI_PM_GPIO_LEVEL_HIGH,            /**< Level of pin is high.  */
    EFI_PM_GPIO_LEVEL_HIGH_Z,          /**< Level of pin is high-z. */
    EFI_PM_GPIO_LEVEL_INVALID
}EFI_PM_GPIO_LEVEL_TYPE;

/** Select output buffer configuration.
*/
typedef enum
{
    EFI_PM_GPIO_OUT_BUF_CFG_CMOS,             /**< CMOS output. */
    EFI_PM_GPIO_OUT_BUF_CFG_OPEN_DRAIN_NMOS,  /**< Open drain NMOS output. */
    EFI_PM_GPIO_OUT_BUF_CFG_OPEN_DRAIN_PMOS,  /**< Open drain PMOS output. */
    EFI_PM_GPIO_OUT_BUF_CFG_INVALID
}EFI_PM_GPIO_OUT_BUF_CFG_TYPE;

/**set output buffer strength
*/
typedef enum
{
    EFI_PM_GPIO_OUT_DRV_STR_LOW,       /**< Output buffer strength low. */
    EFI_PM_GPIO_OUT_DRV_STR_MEDIUM,    /**< Output buffer strength medium. */
    EFI_PM_GPIO_OUT_DRV_STR_HIGH,      /**< Output buffer strength high. */
    EFI_PM_GPIO_OUT_DRV_STR_INVALID
}EFI_PM_GPIO_OUT_DRV_STR_TYPE;


/** Select current source pulls type.
*/
typedef enum
{
    EFI_PM_GPIO_I_SRC_PULL_UP_30uA,                   /**< Pull up 30 uA. */
    EFI_PM_GPIO_I_SRC_PULL_UP_1_5uA,                  /**< Pull up 1.5 uA. */
    EFI_PM_GPIO_I_SRC_PULL_UP_31_5uA,                 /**< Pull up 31.5 uA. */
    EFI_PM_GPIO_I_SRC_PULL_UP_1_5uA_PLUS_30uA_BOOST,  /**< Pull up 1.5 uA plus 30 uA boost. */
    EFI_PM_GPIO_I_SRC_PULL_DOWN_10uA,                 /**< Pull down 10 uA. */
    EFI_PM_GPIO_I_SRC_PULL_NO_PULL,                   /**< No pull. */
    EFI_PM_GPIO_I_SRC_PULL_INVALID
}EFI_PM_GPIO_I_SRC_PULL_TYPE;

/** GPIO source select.
*/
typedef enum
{
    EFI_PM_GPIO_SRC_GND,                  /**< Ground. */
    EFI_PM_GPIO_SRC_PAIRED_GPIO,          /**< Paired GPIO. */
    EFI_PM_GPIO_SRC_SPECIAL_FUNCTION1,    /**< Special function 1. */
    EFI_PM_GPIO_SRC_SPECIAL_FUNCTION2,    /**< Special function 2. */
    EFI_PM_GPIO_SRC_SPECIAL_FUNCTION3,    /**< Special function 3. */
    EFI_PM_GPIO_SRC_SPECIAL_FUNCTION4,    /**< Special function 4. */
    EFI_PM_GPIO_SRC_DTEST1,               /**< D-test 1. */
    EFI_PM_GPIO_SRC_DTEST2,               /**< D-test 2. */
    EFI_PM_GPIO_SRC_DTEST3,               /**< D-test 3. */
    EFI_PM_GPIO_SRC_DTEST4,               /**< D-test 4. */
    EFI_PM_GPIO_SRC_INVALID
}EFI_PM_GPIO_SRC_CFG_TYPE;

// /** D-test buffer enable/disable.
// */
typedef enum
{
    EFI_PM_GPIO_DTEST_DISABLE,  /**< GPIO D-test disable. */
    EFI_PM_GPIO_DTEST_ENABLE,   /**< GPIO D-test enable. */
    EFI_PM_GPIO_DTEST_INVALID
}EFI_PM_GPIO_DTEST_BUF_EN_TYPE;


/**
* Structure used to return GPIO status. This structure includes all of the
* enums that are used when configuring the GPIOs.
*/
typedef struct 
{
    BOOLEAN                              GpioEnable;                       /**GPIO Enable Config*/
    EFI_PM_GPIO_CONFIG_TYPE              GpioConfig;             /**< GPIO mode selection */
    EFI_PM_GPIO_VOLT_SRC_TYPE            GpioVoltSrc;                /**< GPIO voltage source. */
    EFI_PM_GPIO_OUT_BUF_CFG_TYPE         GpioOutBufCfg;             /**< GPIO output buffer configuration. */
    EFI_PM_GPIO_LEVEL_TYPE               GpioLevel;               /**< GPIO invert EXT_PIN configuration. */
    EFI_PM_GPIO_OUT_DRV_STR_TYPE         GpioOurBufDrvStr;         /**< GPIO output buffer driver strength. */
    EFI_PM_GPIO_I_SRC_PULL_TYPE          GpioISrcPulls;             /**< GPIO current source pulls. */
    EFI_PM_GPIO_SRC_CFG_TYPE             GpioSrcCfg;                 /**< GPIO source configuration. */
    EFI_PM_GPIO_DTEST_BUF_EN_TYPE        GpioDtestBufferOnOff;     /**< GPIO D-text buffer on/off. */
}EFI_PM_GPIO_STATUS_TYPE;

/** @} */ /* end_addtogroup efi_pmicGpio_data_types */


/*===========================================================================
  FUNCTION DEFINITIONS
===========================================================================*/
/* EFI_PM_GPIO_ENABLE */ 
/** @ingroup efi_pmicGpio_digital_input
  @par Summary
  Configures a PMIC GPIO as a digital input. 

  @param[in] PmicDeviceIndex     Primary: 0. Secondary: 1.
  @param[in] Gpio                Which GPIO; see # EFI_PM_GPIO_PERIPH_INDEX for 
                                 details.
  @param[in] Enable              


  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/
typedef
EFI_STATUS (EFIAPI *EFI_PM_GPIO_ENABLE)(
  IN UINT32                                       PmicDeviceIndex,
  IN EFI_PM_GPIO_PERIPH_INDEX                     Gpio,
  IN BOOLEAN                                      Enable
);


/* EFI_PM_GPIO_CFG_MODE */ 
/** @ingroup efi_pmicGpio_digital_output
  @par Summary
  Configures a PMIC GPIO as a digital output.

  @param[in]  PmicDeviceIndex    Primary: 0. Secondary: 1.
  @param[in]  Gpio               Which GPIO; see # EFI_PM_GPIO_PERIPH_INDEX for 
                                 details.
  @param[in]  GpioType           Gpio I/O type; see 
                                 #EFI_PM_GPIO_CONFIG_TYPE for 
                                 details.  
  
  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/
typedef
EFI_STATUS (EFIAPI *EFI_PM_GPIO_CFG_MODE)(
  IN UINT32                                     PmicDeviceIndex,
  IN EFI_PM_GPIO_PERIPH_INDEX                   Gpio,
  IN EFI_PM_GPIO_CONFIG_TYPE                    GpioType
);


/* EFI_PM_GPIO_LEVEL_STATUS */ 
/** @ingroup efi_pmicGpio_get_status
  @par Summary
  Gets the GPIO status.

  @param[in]  PmicDeviceIndex   Primary: 0. Secondary: 1.
  @param[in]  Gpio              Which GPIO; see # EFI_PM_GPIO_PERIPH_INDEX for 
                                details.
  @param[out] GpioLevel_Status  GPIO status; see #EFI_PM_GPIO_LEVEL_TYPE for 
                                details.

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/
typedef
EFI_STATUS (EFIAPI *EFI_PM_GPIO_INPUT_LEVEL_STATUS)(
  IN  UINT32                      PmicDeviceIndex,
  IN  EFI_PM_GPIO_PERIPH_INDEX    Gpio,
  OUT EFI_PM_GPIO_LEVEL_TYPE      *GpioLevel_Status
);



/* EFI_PM_GPIO_IRQ_ENABLE */ 
/** @ingroup efi_pmicGpio_irq_enable
  @par Summary
  Enables/disables IRQ for a GPIO.

  @param[in]  PmicDeviceIndex  Primary: 0. Secondary: 1.
  @param[in]  Gpio             Which GPIO; see # EFI_PM_GPIO_PERIPH_INDEX 
                               for details.
  @param[in]  Enable           If TRUE, enable the interrupt for GPIO; 
                               if FALSE, disable the interrupt for GPIO.

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/
typedef
EFI_STATUS (EFIAPI *EFI_PM_GPIO_IRQ_ENABLE)(
 IN  UINT32                       PmicDeviceIndex,
 IN  EFI_PM_GPIO_PERIPH_INDEX     Gpio,
 IN  BOOLEAN                      Enable
);


/* EFI_PM_GPIO_IRQ_CLEAR */ 
/** @ingroup efi_pmicGpio_irq_clear
  @par Summary
  Clears the GPIO IRQ.

  @param[in]  PmicDeviceIndex  Primary: 0. Secondary: 1.
  @param[in]  Gpio             Which GPIO; see # EFI_PM_GPIO_PERIPH_INDEX 
                               for details.

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/
typedef
EFI_STATUS (EFIAPI *EFI_PM_GPIO_IRQ_CLEAR)(
 IN  UINT32                      PmicDeviceIndex,
 IN  EFI_PM_GPIO_PERIPH_INDEX    Gpio
);


/* EFI_PM_GPIO_IRQ_SET_TRIGGER */ 
/** @ingroup efi_pmicGpio_irq_set_trigger
  @par Summary
  Configures the IRQ trigger for a GPIO.

  @param[in]  PmicDeviceIndex  Primary: 0. Secondary: 1.
  @param[in]  Gpio             Which GPIO; see # EFI_PM_GPIO_PERIPH_INDEX 
                               for details.
  @param[in]  Trigger          IRQ trigger type. Values: \n
                               - EFI_PM_IRQ_TRIGGER_ACTIVE_LOW -- 
                                 Active low
                               - EFI_PM_IRQ_TRIGGER_ACTIVE_HIGH -- 
                                 Active high
                               - EFI_PM_IRQ_TRIGGER_RISING_EDGE -- 
                                 Rising edge
                               - EFI_PM_IRQ_TRIGGER_FALLING_EDGE -- 
                                 Falling edge
                               - EFI_PM_IRQ_TRIGGER_DUAL_EDGE -- 
                                 Dual edge
                               - EFI_PM_IRQ_TRIGGER_INVALID -- 
                                 Invalid trigger @vertspace{-13}

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/
typedef
EFI_STATUS (EFIAPI *EFI_PM_GPIO_IRQ_SET_TRIGGER)(
 IN  UINT32                       PmicDeviceIndex,
 IN  EFI_PM_GPIO_PERIPH_INDEX     Gpio,
 IN  EFI_PM_IRQ_TRIGGER_TYPE      Trigger
);


/* EFI_PM_GPIO_IRQ_STATUS */ 
/** @ingroup efi_pmicGpio_irq_status
  @par Summary
  Gets the GPIO IRQ status.

  @param[in]  PmicDeviceIndex  Primary: 0. Secondary: 1.
  @param[in]  Gpio             Which GPIO; see # EFI_PM_GPIO_PERIPH_INDEX 
                               for details.
  @param[in]  Type             IRQ status to read. Values: \n
                               - EFI_PM_IRQ_STATUS_RT -- Real-time
                               - EFI_PM_IRQ_STATUS_LATCHED -- Latched
                               - EFI_PM_IRQ_STATUS_PENDING -- Pending
                               - EFI_PM_IRQ_STATUS_INVALID -- Invalid status
                               @vertspace{-13}
  @param[out] Status           IRQ status.


  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/
typedef
EFI_STATUS (EFIAPI *EFI_PM_GPIO_IRQ_STATUS)(
 IN  UINT32                       PmicDeviceIndex,
 IN  EFI_PM_GPIO_PERIPH_INDEX     Gpio,
 IN  EFI_PM_IRQ_STATUS_TYPE       Type,
 OUT BOOLEAN                      *Status
);


/* EFI_PM_GPIO_SET_VOLTAGE_SOURCE */ 
/** @ingroup efi_pmicGpio_set_dig_in_ctl
  @par Summary
  Enables/disables a DTEST line for digital input control.

  @param[in]  PmicDeviceIndex  Primary: 0. Secondary: 1.
  @param[in]  Gpio             Which GPIO; see # EFI_PM_GPIO_PERIPH_INDEX 
                               for details.
  @param[in]  Voltage_Source   Voltage source for GPIO; see 
                               #EFI_PM_GPIO_VOLT_SRC_TYPE for details.

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/
typedef
EFI_STATUS (EFIAPI *EFI_PM_GPIO_SET_VOLTAGE_SOURCE)(
 IN  UINT32                             PmicDeviceIndex,
 IN  EFI_PM_GPIO_PERIPH_INDEX           Gpio,
 IN  EFI_PM_GPIO_VOLT_SRC_TYPE          Voltage_Source
);


/* EFI_PM_GPIO_SET_OUT_BUF_CFG */ 
/** @ingroup efi_pm_gpio_ext_pin_config
  @par Summary
  Sets GPIO ext pin configuration.

  @param[in]  PmicDeviceIndex      Primary: 0. Secondary: 1.
  @param[in]  Gpio                 Which GPIO; see # EFI_PM_GPIO_PERIPH_INDEX 
                                   for details.
  @param[in]  Out_Buffer_Config    out buffer config type. Refer #EFI_PM_GPIO_OUT_BUF_CFG_TYPE for more info

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/
typedef
EFI_STATUS (EFIAPI *EFI_PM_GPIO_SET_OUT_BUF_CFG)
(
 IN  UINT32                             PmicDeviceIndex,
 IN  EFI_PM_GPIO_PERIPH_INDEX           Gpio,
 IN  EFI_PM_GPIO_OUT_BUF_CFG_TYPE       Out_Buffer_Config
);

/* EFI_PM_GPIO_SET_OUTPUT_LEVEL */ 
/** @ingroup efi_pm_gpio_ext_pin_config
  @par Summary
  Sets GPIO ext pin configuration.

  @param[in]  PmicDeviceIndex      Primary: 0. Secondary: 1.
  @param[in]  Gpio                 Which GPIO; see # EFI_PM_GPIO_PERIPH_INDEX 
                                   for details.
  @param[in]  Gpio_Level           output level . Refer #EFI_PM_GPIO_LEVEL_TYPE for more info

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/
typedef
EFI_STATUS (EFIAPI *EFI_PM_GPIO_SET_OUTPUT_LEVEL)
(
 IN  UINT32                             PmicDeviceIndex,
 IN  EFI_PM_GPIO_PERIPH_INDEX           Gpio,
 IN  EFI_PM_GPIO_LEVEL_TYPE             Gpio_Level
);



/* EFI_PM_GPIO_SET_OUT_DRV_STR */ 
/** @ingroup efi_pm_gpio_ext_pin_config
  @par Summary
  Sets GPIO ext pin configuration.

  @param[in]  PmicDeviceIndex      Primary: 0. Secondary: 1.
  @param[in]  Gpio                 Which GPIO; see # EFI_PM_GPIO_PERIPH_INDEX 
                                   for details.
  @param[in]  Out_Drv_str          Output Drive Streangth . Refer #EFI_PM_GPIO_OUT_DRV_STR_TYPE for more info

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/
typedef
EFI_STATUS (EFIAPI *EFI_PM_GPIO_SET_OUT_DRV_STR)
(
 IN  UINT32                             PmicDeviceIndex,
 IN  EFI_PM_GPIO_PERIPH_INDEX           Gpio,
 IN  EFI_PM_GPIO_OUT_DRV_STR_TYPE       Out_Drv_str
);

/* EFI_PM_GPIO_SET_OUT_SRC_CFG */ 
/** @ingroup efi_pm_gpio_ext_pin_config
  @par Summary
  Sets GPIO ext pin configuration.

  @param[in]  PmicDeviceIndex      Primary: 0. Secondary: 1.
  @param[in]  Gpio                 Which GPIO; see # EFI_PM_GPIO_PERIPH_INDEX 
                                   for details.
  @param[in]  Gpio_Source          Select the Gpio Source . Refer #EFI_PM_GPIO_SRC_CFG_TYPE for more info

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/
typedef
EFI_STATUS (EFIAPI *EFI_PM_GPIO_SET_OUT_SRC_CFG)
(
 IN  UINT32                             PmicDeviceIndex,
 IN  EFI_PM_GPIO_PERIPH_INDEX           Gpio,
 IN  EFI_PM_GPIO_SRC_CFG_TYPE           Gpio_Source
);

/* EFI_PM_GPIO_STATUS_GET */ 
/** @ingroup efi_pm_gpio_ext_pin_config
  @par Summary
  Sets GPIO ext pin configuration.

  @param[in]  PmicDeviceIndex      Primary: 0. Secondary: 1.
  @param[in]  Gpio                 Which GPIO; see # EFI_PM_GPIO_PERIPH_INDEX 
                                   for details.
  @param[out]  Gpio_Status         Gives the Gpio status . Refer #EFI_PM_GPIO_STATUS_TYPE for more info

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/
typedef
EFI_STATUS (EFIAPI *EFI_PM_GPIO_STATUS_GET)
(
 IN  UINT32                             PmicDeviceIndex,
 IN  EFI_PM_GPIO_PERIPH_INDEX           Gpio,
 OUT EFI_PM_GPIO_STATUS_TYPE            *Gpio_Status
);


/*===========================================================================
  PROTOCOL INTERFACE
===========================================================================*/
/** @ingroup efi_pmicGpio_protocol
  @par Summary
  Qualcomm PMIC GPIO Protocol interface.

  @par Parameters
  @inputprotoparams{pmic_gpio_proto_params.tex} 
*/
struct _EFI_QCOM_PMIC_GPIO_PROTOCOL {
  UINT64                                Revision;
  EFI_PM_GPIO_ENABLE                    Enable;
  EFI_PM_GPIO_CFG_MODE                  CfgMode;
  EFI_PM_GPIO_INPUT_LEVEL_STATUS        InputLevelStatus;
  EFI_PM_GPIO_IRQ_ENABLE                IrqEnable;
  EFI_PM_GPIO_IRQ_CLEAR                 IrqClear;
  EFI_PM_GPIO_IRQ_SET_TRIGGER           IrqSetTrigger;
  EFI_PM_GPIO_IRQ_STATUS                IrqStatus;
  EFI_PM_GPIO_SET_VOLTAGE_SOURCE        SetVoltageSource;
  EFI_PM_GPIO_SET_OUT_BUF_CFG           SetOutBufCfg;
  EFI_PM_GPIO_SET_OUTPUT_LEVEL          SetOutputLevel;
  EFI_PM_GPIO_SET_OUT_DRV_STR           SetOutDrvStr;
  EFI_PM_GPIO_SET_OUT_SRC_CFG           SetOutSrcCfg;
  EFI_PM_GPIO_STATUS_GET                StatusGet;
  };

#endif  /* __EFIPMICGPIO_H__ */

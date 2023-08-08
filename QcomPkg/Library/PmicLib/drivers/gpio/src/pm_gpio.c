

/*! \file pm_gpio.c
 *	\n 
 *	\brief Implementation file for GPIO public APIs. 
 *	\n	
 *	\n &copy; Copyright 2010-2019 QUALCOMM Technologies Incorporated, All 
	Rights Reserved
*/
/*===========================================================================

EDIT HISTORY FOR MODULE

This document is created by a code generator, therefore this section will
not contain comments describing changes made to the module.

$Header: //components/dev/boot.sbl/4.1/akmani.boot.sbl.4.1.b04_55GpioDrUp/boot
	_images/core/pmic/pm/drivers/gpio/src/pm_gpio.c#2 $ 


$Author: pwbldsvc $
$DateTime: 2019/07/05 13:22:03 $
when		   who			what, where, why
--------	   ---			   -----------------------------------------------
	----------- 	
04/10/12	hs				Changed the type for (uint32)gpio from int to uint32.
03/01/12	hs				Updated the driver.
11/01/10	APU 			Porting code over from 7x30
xx/yy/zz	ABC 			Reverse Chronological Order. Next set of comments here.
06/16/13	kt				Created.
===========================================================================*/
/*===========================================================================

					 INCLUDE FILES 

===========================================================================*/
#include "pm_gpio.h"
#include "pm_gpio_driver.h"
#include "pm_comm.h"
#include "CoreVerify.h"

/*===========================================================================

						DEFINITIONS

===========================================================================*/
#define SLAVE_ID				gpio_ptr->comm_ptr->slave_id

#define REG_GPIO(gpio, reg) 	((gpio_ptr->gpio_register->base_address) + \
		((pm_register_address_type)(gpio_ptr->gpio_register->peripheral_offset*(uint32)gpio)) + \
		(gpio_ptr->gpio_register->reg))

#define GET_ERR_FLAG			gpio_ptr == NULL ? PM_ERR_FLAG_FEATURE_NOT_SUPPORTED : \
		PM_ERR_FLAG_INVALID

#define EN_CTL_MASK 			 0x80
#define MODE_CTL_MASK			 0x3
#define DIG_VIN_CTL_MASK		 0x7
#define DIG_OUT_DRV_TYPE_MASK	 0x30
#define DIG_OUT_SRC_TYPE_MASK	 0x80
#define DIG_PULL_CTL_MASK		 0x7
#define DIG_OUT_DRV_SEL_MASK	 0x3
#define DIG_OUT_SRC_SEL_MASK	 0xF
#define INT_MASK				 0x1
#define STATUS_ENABLE_MASK		 0x80
#define STATUS_VALUE_MASK		 0x1
#define DIG_IN_DTEST_ENABLE_MASK 0x80
#define DIG_IN_DTEST_SEL_MASK	 0x7
#define DRV_STR_ENUM_TO_RAW		 0x1
#define DRV_STR_RAW_TO_ENUM      0x0

/*===========================================================================

						FUNCTION PROTOTYPES

===========================================================================*/
void* raw_enum_mapping(void* out_drv_str, uint32 operation);


/*===========================================================================

						FUNCTION DEFINITIONS

===========================================================================*/

/*****************************************************************************
	*
						pm_gpio_enable
******************************************************************************
	*/
pm_err_flag_type pm_gpio_enable(uint32 pmic_chip, 
	pm_gpio_perph_index gpio, 
	boolean enable)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_gpio_data_type * gpio_ptr = pm_gpio_get_data(pmic_chip);
	pm_register_data_type data = 0;

	if ((gpio_ptr == NULL) || (gpio >= gpio_ptr->num_of_peripherals))
		{
		err_flag = GET_ERR_FLAG;

		return err_flag;
		}

	data = (enable == TRUE) ? 0x80: 0x0;

	err_flag = pm_comm_write_byte_mask(SLAVE_ID, 
		REG_GPIO(gpio, en_ctl), 
		EN_CTL_MASK, data);

	return err_flag;
}


/*****************************************************************************
	*
						pm_gpio_cfg_mode
******************************************************************************
	*/
pm_err_flag_type pm_gpio_cfg_mode(uint32 pmic_chip, 
	pm_gpio_perph_index gpio, 
	pm_gpio_config_type type)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_gpio_data_type * gpio_ptr = pm_gpio_get_data(pmic_chip);

	if (gpio_ptr == NULL || gpio >= gpio_ptr->num_of_peripherals ||
		 type >= PM_GPIO_TYPE_INVALID)
		{
		err_flag = GET_ERR_FLAG;

		return err_flag;
		}

	err_flag = pm_comm_write_byte_mask(SLAVE_ID, 
		REG_GPIO(gpio, mode_ctl), MODE_CTL_MASK, 
		(pm_register_data_type) type);

	return err_flag;
}

/*****************************************************************************
	*
						pm_gpio_set_output_level
******************************************************************************
	*/
pm_err_flag_type pm_gpio_set_output_level(uint32 pmic_chip, 
	pm_gpio_perph_index gpio, 
	pm_gpio_level_type level)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_gpio_data_type * gpio_ptr = pm_gpio_get_data(pmic_chip);

	if (gpio_ptr == NULL || gpio >= gpio_ptr->num_of_peripherals ||
		 level >= PM_GPIO_LEVEL_INVALID)
		{
		err_flag = GET_ERR_FLAG;

		return err_flag;
		}

	if (level > PM_GPIO_LEVEL_HIGH)
		{
		return PM_ERR_FLAG_FEATURE_NOT_SUPPORTED;
		}

	err_flag = pm_comm_write_byte_mask(SLAVE_ID, 
		REG_GPIO(gpio, dig_out_src_ctl), 
		DIG_OUT_SRC_TYPE_MASK, (level << 7));

	return err_flag;
}

/*****************************************************************************
	****
							pm_gpio_input_level_status
******************************************************************************
	****/
pm_err_flag_type pm_gpio_input_level_status(uint32 pmic_chip, 
	pm_gpio_perph_index gpio, 
	pm_gpio_level_type * level_status)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_register_data_type status_data = 0;
	pm_register_data_type mode_ctl_data = 0;
	pm_gpio_data_type * gpio_ptr = pm_gpio_get_data(pmic_chip);

	if ((gpio_ptr == NULL) || (gpio >= gpio_ptr->num_of_peripherals) ||
		 (level_status == NULL))
		{
		err_flag = GET_ERR_FLAG;

		return err_flag;
		}

	err_flag = pm_comm_read_byte(SLAVE_ID, REG_GPIO(gpio, status), 
		&status_data);

	err_flag |= pm_comm_read_byte(SLAVE_ID, 
		REG_GPIO(gpio, mode_ctl), &mode_ctl_data);

	if ((status_data & STATUS_ENABLE_MASK) &&
		 (((mode_ctl_data & MODE_CTL_MASK) == PM_GPIO_DIG_IN) ||
		 ((mode_ctl_data & MODE_CTL_MASK) == PM_GPIO_DIG_IN_OUT)))
		{
		*level_status =
			 (status_data & STATUS_VALUE_MASK) ? PM_GPIO_LEVEL_HIGH: PM_GPIO_LEVEL_LOW;
		}
	else 
		{
		err_flag |= PM_ERR_FLAG_FAILURE;
		}

	return err_flag;
}




/*****************************************************************************
	*
						pm_gpio_set_voltage_source
******************************************************************************
	*/
pm_err_flag_type pm_gpio_set_voltage_source(uint32 pmic_chip, 
	pm_gpio_perph_index gpio, 
	pm_gpio_volt_src_type voltage_source)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_gpio_data_type * gpio_ptr = pm_gpio_get_data(pmic_chip);

	if (gpio_ptr == NULL || gpio >= gpio_ptr->num_of_peripherals ||
		 voltage_source >= PM_GPIO_VIN_INVALID)
		{
		err_flag = GET_ERR_FLAG;

		return err_flag;
		}

	err_flag = pm_comm_write_byte_mask(SLAVE_ID, 
		REG_GPIO(gpio, dig_vin_ctl), DIG_VIN_CTL_MASK, 
		(pm_register_data_type) voltage_source);

	return err_flag;
}


/*****************************************************************************
	*
						pm_gpio_set_out_buf_cfg
******************************************************************************
	*/
pm_err_flag_type pm_gpio_set_out_buf_cfg(uint32 pmic_chip, 
	pm_gpio_perph_index gpio, 
	pm_gpio_out_buf_cfg_type out_buffer_config)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_gpio_data_type * gpio_ptr = pm_gpio_get_data(pmic_chip);

	if (gpio_ptr == NULL || gpio >= gpio_ptr->num_of_peripherals ||
		 out_buffer_config >= PM_GPIO_OUT_BUF_CFG_INVALID)
		{
		err_flag = GET_ERR_FLAG;

		return err_flag;
		}

	err_flag = pm_comm_write_byte_mask(SLAVE_ID, 
		REG_GPIO(gpio, dig_out_drv_ctl), DIG_OUT_DRV_TYPE_MASK, 
		(pm_register_data_type) (out_buffer_config << 4));

	return err_flag;
}




/*****************************************************************************
	*
						pm_gpio_set_out_buf_drv_str
******************************************************************************
	*/
pm_err_flag_type pm_gpio_set_out_drv_str(uint32 pmic_chip, 
	pm_gpio_perph_index gpio, 
	pm_gpio_out_drv_str_type out_drv_str)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_gpio_data_type * gpio_ptr = pm_gpio_get_data(pmic_chip);

	if (gpio_ptr == NULL || gpio >= gpio_ptr->num_of_peripherals ||
		 out_drv_str >= PM_GPIO_OUT_DRV_STR_INVALID)
		{
		err_flag = GET_ERR_FLAG;

		return err_flag;
		}
		 
    out_drv_str = * (pm_gpio_out_drv_str_type *) raw_enum_mapping(&out_drv_str, DRV_STR_ENUM_TO_RAW);
	err_flag = pm_comm_write_byte_mask(SLAVE_ID, 
		REG_GPIO(gpio, dig_out_drv_ctl), DIG_OUT_DRV_SEL_MASK, 
		(pm_register_data_type) out_drv_str);

	return err_flag;
}


/*****************************************************************************
	*
						pm_gpio_set_out_src_cfg
******************************************************************************
	*/
pm_err_flag_type pm_gpio_set_out_src_cfg(uint32 pmic_chip, 
	pm_gpio_perph_index gpio, 
	pm_gpio_src_cfg_type source)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_gpio_data_type * gpio_ptr = pm_gpio_get_data(pmic_chip);

	if (gpio_ptr == NULL || (uint32)
	gpio >= gpio_ptr->num_of_peripherals || source >= PM_GPIO_SRC_INVALID)
		{
		err_flag = GET_ERR_FLAG;

		return err_flag;
		}

	err_flag = pm_comm_write_byte_mask(SLAVE_ID, 
		REG_GPIO(gpio, dig_out_src_ctl), DIG_OUT_SRC_SEL_MASK, 
		(pm_register_data_type) (source));

	return err_flag;
}


/*****************************************************************************
	*
						pm_gpio_irq_enable
******************************************************************************
	*/
pm_err_flag_type pm_gpio_irq_enable(uint32 pmic_chip, 
	pm_gpio_perph_index gpio, 
	boolean enable)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_gpio_data_type * gpio_ptr = pm_gpio_get_data(pmic_chip);
	pm_register_address_type IRQ_REG;

	if ((gpio_ptr == NULL) || ((uint32) gpio >= gpio_ptr->num_of_peripherals))
		{
		err_flag = GET_ERR_FLAG;

		return err_flag;
		}

	IRQ_REG = (enable ==
		 TRUE) ? REG_GPIO(gpio, int_en_set): REG_GPIO(gpio, int_en_clr);

	err_flag = pm_comm_write_byte(SLAVE_ID, IRQ_REG, 0x01);
	return err_flag;
}


/*****************************************************************************
	*
						pm_gpio_irq_clear
******************************************************************************
	*/
pm_err_flag_type pm_gpio_irq_clear(uint32 pmic_chip, 
	pm_gpio_perph_index gpio)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_gpio_data_type * gpio_ptr = pm_gpio_get_data(pmic_chip);

	if ((gpio_ptr == NULL) || ((uint32) gpio >= gpio_ptr->num_of_peripherals))
		{
		err_flag = GET_ERR_FLAG;

		return err_flag;
		}

	err_flag = pm_comm_write_byte(SLAVE_ID, 
		REG_GPIO(gpio, int_latched_clr), 0x01);
	return err_flag;
}


/*****************************************************************************
	*
						pm_gpio_irq_set_trigger
******************************************************************************
	*/
pm_err_flag_type pm_gpio_irq_set_trigger(uint32 pmic_chip, 
	pm_gpio_perph_index gpio, 
	pm_irq_trigger_type trigger)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_gpio_data_type * gpio_ptr = pm_gpio_get_data(pmic_chip);
	pm_register_data_type set_type, polarity_high, polarity_low;

	if ((gpio_ptr == NULL) ||
		 ((uint32) gpio >= gpio_ptr->num_of_peripherals) ||
		 (trigger >= PM_IRQ_TRIGGER_INVALID))
		{
		err_flag = GET_ERR_FLAG;

		return err_flag;
		}

	switch (trigger)
		{
		case PM_IRQ_TRIGGER_ACTIVE_LOW:
			set_type = 0x00;
			polarity_high = 0x00;
			polarity_low = 0xFF;
			break;

		case PM_IRQ_TRIGGER_ACTIVE_HIGH:
			set_type = 0x00;
			polarity_high = 0xFF;
			polarity_low = 0x00;
			break;

		case PM_IRQ_TRIGGER_RISING_EDGE:
			set_type = 0xFF;
			polarity_high = 0xFF;
			polarity_low = 0x00;
			break;

		case PM_IRQ_TRIGGER_FALLING_EDGE:
			set_type = 0xFF;
			polarity_high = 0x00;
			polarity_low = 0xFF;
			break;

		case PM_IRQ_TRIGGER_DUAL_EDGE:
			set_type = 0xFF;
			polarity_high = 0xFF;
			polarity_low = 0xFF;
			break;

		default:
			return PM_ERR_FLAG_FEATURE_NOT_SUPPORTED;
		}

	err_flag |= pm_comm_write_byte_mask(SLAVE_ID, 
		REG_GPIO(gpio, int_set_type), 
		INT_MASK, set_type);

	err_flag |= pm_comm_write_byte_mask(SLAVE_ID, 
		REG_GPIO(gpio, int_polarity_high), 
		INT_MASK, polarity_high);

	err_flag |= pm_comm_write_byte_mask(SLAVE_ID, 
		REG_GPIO(gpio, int_polarity_low), 
		INT_MASK, polarity_low);

	return err_flag;
}


/*****************************************************************************
	*
						pm_gpio_irq_status
******************************************************************************
	*/
pm_err_flag_type pm_gpio_irq_status(uint32 pmic_chip, 
	pm_gpio_perph_index gpio, 
	pm_irq_status_type irq_type, 
	boolean * status)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_gpio_data_type * gpio_ptr = pm_gpio_get_data(pmic_chip);
	pm_register_data_type data;
	pm_register_address_type INT_STS;

	if (gpio_ptr == NULL || gpio >= gpio_ptr->num_of_peripherals ||
		 irq_type >= PM_IRQ_STATUS_INVALID || status == NULL)
		{
		err_flag = GET_ERR_FLAG;

		return err_flag;
		}

	switch (irq_type)
		{
		case PM_IRQ_STATUS_RT:
			INT_STS = REG_GPIO(gpio, int_rt_sts);
			break;

		case PM_IRQ_STATUS_LATCHED:
			INT_STS = REG_GPIO(gpio, int_latched_sts);
			break;

		case PM_IRQ_STATUS_PENDING:
			INT_STS = REG_GPIO(gpio, int_pending_sts);
			break;

		case PM_IRQ_STATUS_ENABLE:
			INT_STS = REG_GPIO(gpio, int_en_set);
			break;

		default:
			return PM_ERR_FLAG_FEATURE_NOT_SUPPORTED;
		}

	err_flag |= pm_comm_read_byte_mask(SLAVE_ID, INT_STS, INT_MASK, 
		&data);
	*status = (data ? TRUE: FALSE);

	return err_flag;
}


pm_err_flag_type pm_gpio_status_get(uint32 pmic_chip, 
	pm_gpio_perph_index gpio, 
	pm_gpio_status_type * status)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_register_data_type reg_data = 0;
	pm_register_data_type reg_data2 = 0;
	pm_gpio_data_type * gpio_ptr = pm_gpio_get_data(pmic_chip);

	if (gpio_ptr == NULL || gpio >= gpio_ptr->num_of_peripherals ||
		 status == NULL)
		{
		err_flag = GET_ERR_FLAG;

		return err_flag;
		}

	// Read current source pulls
	err_flag |= pm_comm_read_byte(SLAVE_ID, 
		REG_GPIO(gpio, dig_pull_ctl), 
		&reg_data);

	if (PM_ERR_FLAG_SUCCESS == err_flag)
		{
		reg_data = reg_data & 0x07;
		status->i_src_pulls = (pm_gpio_i_src_pull_type)
		reg_data;
		}

	// Read voltage source
	err_flag |= pm_comm_read_byte(SLAVE_ID, 
		REG_GPIO(gpio, dig_vin_ctl), 
		&reg_data);

	if (PM_ERR_FLAG_SUCCESS == err_flag)
		{
		reg_data = reg_data & 0x01;
		status->volt_src = (pm_gpio_volt_src_type)
		reg_data;
		}

	// Read output buffer config Read output buffer strength
	err_flag |= pm_comm_read_byte(SLAVE_ID, 
		REG_GPIO(gpio, dig_out_drv_ctl), 
		&reg_data);

	if (PM_ERR_FLAG_SUCCESS == err_flag)
		{
		reg_data2 = reg_data & 0x30;
		status->out_buf_cfg = (pm_gpio_out_buf_cfg_type) (reg_data2 >> 4);

		reg_data = reg_data & 0x03;
		reg_data = *(pm_gpio_out_drv_str_type *) raw_enum_mapping(&reg_data, DRV_STR_RAW_TO_ENUM);
			
		status->out_buf_drv_str = (pm_gpio_out_drv_str_type)
		reg_data;
		}

	// Read Source Config from Mode_CTL register 
	err_flag |= pm_comm_read_byte(SLAVE_ID, 
		REG_GPIO(gpio, mode_ctl), &reg_data);

	if (PM_ERR_FLAG_SUCCESS == err_flag)
		{
		switch (reg_data & MODE_CTL_MASK)
			{
			case 0x0:
				status->mode_select = PM_GPIO_DIG_IN;
				break;

			case 0x1:
				status->mode_select = PM_GPIO_DIG_OUT;
				break;

			case 0x2:
				status->mode_select = PM_GPIO_DIG_IN_OUT;
				break;

			case 0x3:
				status->mode_select = PM_GPIO_ANA_PASS_THRU;
				break;

			default:
				status->mode_select = PM_GPIO_TYPE_INVALID;
				break;
			}
		}

	// Read DTEST buffer
	err_flag |= pm_comm_read_byte(SLAVE_ID, 
		REG_GPIO(gpio, dig_in_dtest_sel), &reg_data);

	if (PM_ERR_FLAG_SUCCESS == err_flag)
		{

		reg_data2 = reg_data & DIG_IN_DTEST_ENABLE_MASK;
		status->dtest_buffer_on_off = (reg_data2 ==
			 0) ? PM_GPIO_DTEST_DISABLE: PM_GPIO_DTEST_ENABLE;

		if (status->mode_select == PM_GPIO_DIG_IN &&
			 status->dtest_buffer_on_off == PM_GPIO_DTEST_DISABLE)
			{
			status->src_cfg = PM_GPIO_SRC_INVALID;
			}
		else if (status->mode_select == PM_GPIO_DIG_IN &&
			 status->dtest_buffer_on_off == PM_GPIO_DTEST_ENABLE)
			{
			switch (reg_data & DIG_IN_DTEST_SEL_MASK)
				{
				case 0x0:
					status->src_cfg = PM_GPIO_SRC_DTEST1;
					break;

				case 0x1:
					status->src_cfg = PM_GPIO_SRC_DTEST2;
					break;

				case 0x2:
					status->src_cfg = PM_GPIO_SRC_DTEST3;
					break;

				case 0x3:
					status->src_cfg = PM_GPIO_SRC_DTEST4;
					break;

				default:
					status->src_cfg = PM_GPIO_SRC_INVALID;
					break;
				}
			}
		}

	// GPIO enable status
	err_flag |= pm_comm_read_byte(SLAVE_ID, REG_GPIO(gpio, en_ctl), 
		&reg_data);

	if (PM_ERR_FLAG_SUCCESS == err_flag)
		{
		reg_data = reg_data & EN_CTL_MASK;
		status->enable = (boolean) (reg_data >> 7);
		}
    if((status->mode_select == PM_GPIO_DIG_IN)||(status->mode_select == PM_GPIO_DIG_IN_OUT))
        {
	     err_flag |= pm_gpio_input_level_status(pmic_chip, gpio, 
		  &status->level);
        }

	err_flag |= pm_comm_read_byte(SLAVE_ID, 
		REG_GPIO(gpio, dig_out_src_ctl), &reg_data);

	if (PM_ERR_FLAG_SUCCESS == err_flag)
		{
		if (status->mode_select != PM_GPIO_DIG_IN)
			{
			status->src_cfg =
				 (pm_gpio_src_cfg_type) (reg_data & DIG_OUT_SRC_SEL_MASK);
			}
		}

	return err_flag;
}

pm_err_flag_type
pm_gpio_set_pull_sel(uint32 pmic_chip, pm_gpio_perph_index gpio, pm_gpio_pull_sel_type pull)
{
	pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
	pm_gpio_data_type* gpio_ptr = pm_gpio_get_data(pmic_chip);

	if (NULL == gpio_ptr || gpio >= gpio_ptr->num_of_peripherals || pull >= PM_GPIO_PULL_INVALID)
	{
    return GET_ERR_FLAG;
	}

  err_flag = pm_comm_write_byte_mask(SLAVE_ID, REG_GPIO(gpio, dig_pull_ctl), DIG_PULL_CTL_MASK, (pm_register_data_type)pull);

  return err_flag;
}

void* raw_enum_mapping(void* value, uint32 operation)
{ 
   static pm_gpio_out_drv_str_type out_str_value = PM_GPIO_OUT_DRV_STR_INVALID;
	if(operation == DRV_STR_ENUM_TO_RAW)
    {
     	switch(*(pm_gpio_out_drv_str_type *)value)
     	{ 
     	  case PM_GPIO_OUT_DRV_STR_LOW:
     		   out_str_value = PM_GPIO_OUT_DRV_STR_MEDIUM;
     		   break;
     	  case PM_GPIO_OUT_DRV_STR_MEDIUM:
     		   out_str_value = PM_GPIO_OUT_DRV_STR_HIGH;
     		   break;
     	  case PM_GPIO_OUT_DRV_STR_HIGH:
     		   out_str_value = PM_GPIO_OUT_DRV_STR_INVALID;
     		   break;
     	  case PM_GPIO_OUT_DRV_STR_INVALID:
     		   break;
		  default:
		  	   CORE_VERIFY(0);
     		
     	} 
	    value = &out_str_value;
			 
	}
    else if (operation == DRV_STR_RAW_TO_ENUM)
	{
	    switch(*(uint32 *)value)
     	{ 
     	  case 0:
     		   out_str_value = PM_GPIO_OUT_DRV_STR_INVALID;
     		   break;
          case 1:
     		   out_str_value = PM_GPIO_OUT_DRV_STR_LOW;
     		   break;
     	  case 2:
     		   out_str_value = PM_GPIO_OUT_DRV_STR_MEDIUM;
     		   break;
     	  case 3:
			   out_str_value = PM_GPIO_OUT_DRV_STR_HIGH;
     		   break;
		  default:
		  	   CORE_VERIFY(0);
     	} 
		value = &out_str_value;
    }
	
	
  return value;
}



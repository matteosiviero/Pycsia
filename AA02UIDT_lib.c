/**
 * @defgroup 	AA02UIDT_LIB
 * @file        AA02UIDT_lib.c
 * @brief		Unique ID 24AA02UIDT library source file.
 * @author		Matteo Siviero
 * @version		1.0
 * @date 		31/03/2020
*/

// temporary change
// andrea adds a temporary change
// provo a cambiare io qualcosa
/***************************** Include Files *********************************/
#include "AA02UIDT_lib.h"
#include "stm32l4xx_hal.h"

/**************************** Type Definitions *******************************/



/***************** Macros (Inline Functions) Definitions *********************/



/************************** Function Prototypes ******************************/




/************************** Variable Definitions ******************************/


/**
 * @name    Read_UniqueID
 * @brief   This function reads from AA02UIDT memory the unique ID value
 * @param   *Hi2c Pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for the specified I2C.
 * @param	*ID Value of unique ID
 * @retval  UNIQUE_OK @see AA02UIDT_ErrorEnum
 *
 */
AA02UIDT_ErrorEnum Read_UniqueID(I2C_HandleTypeDef *Hi2c, uint32_t *ID)
{
	HAL_I2C_Init(Hi2c);

	HAL_StatusTypeDef ret;
	uint8_t *AA02UIDT_Data=NULL;

	ret = HAL_I2C_Mem_Read(Hi2c, AA02UIDT_ADDR, AA02UIDT_ID_ADDR, AA02UIDT_ID_MEM_SIZE, AA02UIDT_Data, AA02UIDT_BUFF_SIZE, AA02UIDT_TIMEOUT);
	if(ret!=HAL_OK)
		return ret;

	*ID = ((uint32_t) AA02UIDT_Data);


	return UNIQUE_OK;

}

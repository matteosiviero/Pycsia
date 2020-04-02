/**
 * @defgroup 	AA02UIDT_LIB
 * @file        AA02UIDT_lib.h
 * @brief		Unique ID 24AA02UIDT library header file.
 * @author		Matteo Siviero
 * @version		1.0
 * @date 		31/03/2020
*/

#ifndef INC_AA02UIDT_LIB_H_
#define INC_AA02UIDT_LIB_H_



/***************************** Include Files *********************************/
#include "stm32l4xx_hal.h"



/**************************** Constant Definitions *******************************/
#define AA02UIDT_CONTROL_CODE	0x50														/*!< Fixed address part for AA02UIDT device*/
#define AA02UIDT_USER_CODE		0x00														/*!< From PCB configuration (A2,A1,A0 are connected to GND)*/
#define AA02UIDT_ADDR		    (AA02UIDT_CONTROL_CODE + AA02UIDT_USER_CODE)<<1				/*!< AA02UIDT address to read*/
#define AA02UIDT_ID_ADDR		0xFC														/*!< Memory address where ID is stored*/
#define AA02UIDT_ID_MEM_SIZE	0x03														/*!< Memory size where ID is stored (from datasheet: from 0xFC to 0xFF)*/
#define AA02UIDT_BUFF_SIZE		2															/*!< Amount of data to be sent*/
#define AA02UIDT_TIMEOUT		100															/*!< Timeout duration*/



/**************************** Type Definitions *******************************/

/**
 * @brief Definition of error value for AA02UIDT Unique ID chip
 */
typedef enum _error_AA02UIDT_enum {
	UNIQUE_OK,																				/*!< indicates correct execution*/
	UNIQUE_ERROR,																			/*!< indicates that action is failed*/

} AA02UIDT_ErrorEnum;



/***************** Macros (Inline Functions) Definitions *********************/




/************************** Function Prototypes ******************************/
AA02UIDT_ErrorEnum Read_UniqueID(I2C_HandleTypeDef *Hi2c, uint32_t *ID);





#endif /* INC_AA02UIDT_LIB_H_ */

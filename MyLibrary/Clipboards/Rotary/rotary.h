/**
  ******************************************************************************
  * @file    rotary.h
  * @author  Reiter Roman
  * @version 1.0
  * @date Created on: Jan 23, 2022
  * @brief   Header file of GPIO HAL module.
  ******************************************************************************
  */

#ifndef CLIPBOARDS_ROTARY_ROTARY_H_
#define CLIPBOARDS_ROTARY_ROTARY_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <Clipboards/clipboard.h>
/** @addtogroup MyLibrary
  * @{
  */

/** @addtogroup CLIPBOARDS Clipboards
  * @{
  */

/** @addtogroup ROTARY ROTARY
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @addtogroup ROTARY_Exported_Types ROTARY Exported Types
  * @{
  */

/**
  * @brief  ROTARY Configuration Structure definition
  */

typedef struct
 {
	CLIPBOARD_SPI_TypeDef hclipboard; 	/*!< Clipboard struct */

	TIM_HandleTypeDef * htim;			/*!< Timer struct */

 } MY_ROTARY_HandleTypeDef;


/**
  * @}
  */
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup ROTARY_Exported_Functions
  * @{
  */

/** @addtogroup ROTARY_Exported_Functions_Group1
  * @{
  */
/* Initialization Functions *****************************/
void MY_ROTARY_Init_Strobed(MY_ROTARY_HandleTypeDef * hrotary ,TIM_HandleTypeDef * htim,GPIO_TypeDef* GPIO_MOSI_Port, uint16_t GPIO_MOSI_Pin,GPIO_TypeDef* GPIO_SCK_Port, uint16_t GPIO_SCK_Pin,GPIO_TypeDef* GPIO_CS_Port, uint16_t GPIO_CS_Pin,GPIO_TypeDef* GPIO_ENCA_Port, uint16_t GPIO_ENCA_Pin,GPIO_TypeDef* GPIO_ENCB_Port, uint16_t GPIO_ENCB_Pin,GPIO_TypeDef* GPIO_SWITCH_Port, uint16_t GPIO_SWITCH_Pin);

/**
  * @}
  */

/** @addtogroup ROTARY_Exported_Functions_Group2
  * @{
  */
/* Operation Functions *****************************************************/
void MY_ROTARY_SET_LEDS(MY_ROTARY_HandleTypeDef * hrotary,uint16_t * number,uint8_t * brightness);
uint8_t MY_ROTARY_GetEncoderEvent();
/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/


/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* CLIPBOARDS_ROTARY_ROTARY_H_ */

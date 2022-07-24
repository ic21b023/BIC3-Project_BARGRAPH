/**
  ******************************************************************************
  * @file    bargraph.h
  * @author  Reiter Roman
  * @version 1.0
  * @date Created on: Jan 23, 2022
  * @brief   Header file des BARGRAPH modules
  ******************************************************************************
  */

#ifndef CLIPBOARDS_BARGRAPH_BARGRAPH_H_
#define CLIPBOARDS_BARGRAPH_BARGRAPH_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "Clipboards/clipboard.h"

/** @addtogroup MyLibrary
  * @{
  */

/** @addtogroup CLIPBOARDS CLIPBOARDS
  * @{
  */

/** @addtogroup BARGRAPH BARGRAPH
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @addtogroup BARGRAPH_Exported_Types BARGRAPH Exported Types
  * @{
  */

/**
  * @brief  Bargraph-Hellogkeit Enum definition
  */
typedef enum
{
	MY_BARGRAPH_BRITHNESSMODE_PULSED = 0, 		/*!< Helligkeit mit PWM steuern      */
	MY_BARGRAPH_BRITHNESSMODE_STROBED  = 1 		/*!< Helligkeit mit Frequenz steuern */

} MY_BARGRAPH_BrightnessMode;

/**
  * @brief Bargraph Structure definition
  */
typedef struct
 {
	CLIPBOARD_SPI_TypeDef hclipboardR; 			/*!< Clipboard Handle		*/

	TIM_HandleTypeDef * htimR; 					/*!< Timer Handle			*/

	MY_BARGRAPH_BrightnessMode BrightnessMode; 	/*!< Enum BrightnessMode	*/

 } MY_BARGRAPH_HandleTypeDef;
/**
  * @}
  */
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup BARGRAPH_Exported_Functions
  * @{
  */

/** @addtogroup BARGRAPH_Exported_Functions_Group1
  * @{
  */
/* Initialization Functions *****************************/
void MY_BARGRAPH_Init_Strobed(MY_BARGRAPH_HandleTypeDef * hbargraph ,TIM_HandleTypeDef * htim,GPIO_TypeDef* GPIO_MOSI_Port, uint16_t GPIO_MOSI_Pin,GPIO_TypeDef* GPIO_SCK_Port, uint16_t GPIO_SCK_Pin,GPIO_TypeDef* GPIO_CS_Port, uint16_t GPIO_CS_Pin);
void MY_BARGRAPH_Init_Pulsed(MY_BARGRAPH_HandleTypeDef * hbargraph ,TIM_HandleTypeDef * htim, uint32_t channel, GPIO_TypeDef* GPIO_MOSI_Port, uint16_t GPIO_MOSI_Pin,GPIO_TypeDef* GPIO_SCK_Port, uint16_t GPIO_SCK_Pin,GPIO_TypeDef* GPIO_CS_Port, uint16_t GPIO_CS_Pin);

/**
  * @}
  */

/** @addtogroup BARGRAPH_Exported_Functions_Group2
  * @{
  */

/* Operation Functions *****************************************************/
void MY_BARGRAPH_SET_BITS(MY_BARGRAPH_HandleTypeDef * hbargraph,uint16_t * number,uint8_t * brightness);

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

#endif /* CLIPBOARDS_BARGRAPH_BARGRAPH_H_ */

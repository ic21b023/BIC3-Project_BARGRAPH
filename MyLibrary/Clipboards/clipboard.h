/**
  ******************************************************************************
  * @file    clipboards_conf.h
  * @author  Reiter Roman
  * @version 1.0
  * @date Created on: 24.12.2021
  * @brief   Header file des Clipboards module.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CLIPBOARDS_CLIPBOARDS_DEF_H_
#define CLIPBOARDS_CLIPBOARDS_DEF_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx.h"

/** @addtogroup MyLibrary
  * @{
  */

/** @addtogroup CLIPBOARDS CLIPBOARDS
  * @brief CLIPBOARD Module Drivers
  * @{
  */

/** @addtogroup CLIPBOARD CLIPBOARD
  * @brief CLIPBOARD Module Driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @addtogroup CLIPBOARD_Exported_Types CLIPBOARD Exported Types
  * @{
  */

/**
  * @brief  TIM Time base Configuration Structure definition
  */
 typedef struct
  {
 	 GPIO_TypeDef* GPIO_MOSI_Port;	/*!< MOSI-Port des Clipboards */

  	 uint16_t GPIO_MOSI_Pin;       	/*!< MOSI-Pin des Clipboards */

 	 GPIO_TypeDef* GPIO_SCK_Port;	/*!< SCK-Port des Clipboards */

 	 uint16_t GPIO_SCK_Pin;			/*!< SCK-Pin des Clipboards */

 	 GPIO_TypeDef* GPIO_CS_Port;	/*!< CS-Port des Clipboards */

 	 uint16_t GPIO_CS_Pin;       	/*!< CS-Pin des Clipboards */

  } CLIPBOARD_SPI_TypeDef;
  /**
    * @}
    */

  /* Exported constants --------------------------------------------------------*/
  /* Exported macro ------------------------------------------------------------*/
  /* Private macros ------------------------------------------------------------*/
  /* Exported functions --------------------------------------------------------*/

  /** @addtogroup CLIPBOARD_Exported_Functions CLIPBOARD Exported Functions
    * @{
    */

  /** @addtogroup CLIPBOARD_Exported_Functions_Group1 CLIPBOARD Initialization Functions
    * @brief    Initialization and Configuration Functions
    * @{
    */
  void MY_CLIPBOARD_Init(CLIPBOARD_SPI_TypeDef * hclipboard,GPIO_TypeDef* GPIO_MOSI_Port, uint16_t GPIO_MOSI_Pin,GPIO_TypeDef* GPIO_SCK_Port, uint16_t GPIO_SCK_Pin,GPIO_TypeDef* GPIO_CS_Port, uint16_t GPIO_CS_Pin);
  /**
    * @}
    */

  /** @addtogroup CLIPBOARD_Exported_Functions_Group2 CLIPBOARD SPI-Transfer Functions
    *  @brief   CLIPBOARD SPI-Transfer functions
    * @{
    */
  void MY_CLIPBOARD_SPI_TX(CLIPBOARD_SPI_TypeDef * hclipboard, uint8_t * value);
  uint16_t get_value_bitpositions(uint16_t zahl, uint16_t stelle);

  /**
    * @}
    */


  /**
    * @}
    */

  /**
    * @}
    */

  /**
    * @}
    */

  /**
    * @}
    */

#ifdef __cplusplus
}
#endif

#endif /* CLIPBOARDS_CLIPBOARDS_DEF_H_ */

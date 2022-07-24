/**
  ******************************************************************************
  * @file    clipboards_conf.c
  * @author  Reiter Roman
  * @version 1.0
  * @date Created on: 24.12.2021
  * @brief   GPIO HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the General Purpose Input/Output (GPIO) peripheral:
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <Clipboards/clipboard.h>

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

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @addtogroup CLIPBOARD_Exported_Functions CLIPBOARD Exported Functions
  * @{
  */

/** @addtogroup CLIPBOARD_Exported_Functions_Group1 CLIPBOARD Initialization Functions
 *  @brief    Initialization and Configuration functions
 *
@verbatim
 ===============================================================================
             ##### Initialization Functions  #####
 ===============================================================================
    [..] Dienen fürs initialisieren des Clipboards

@endverbatim
  * @{
  */

/**
  * @brief  Initialize the CLIPBOARDx peripheral according to the specified parameters in the GPIO_Init.
  * @param  GPIOx where x can be (A..H) to select the GPIO peripheral for STM32L4 family
  * @param  GPIO_Init pointer to a GPIO_InitTypeDef structure that contains
  *         the configuration information for the specified GPIO peripheral.
  * @retval None
  */
 void MY_CLIPBOARD_Init(CLIPBOARD_SPI_TypeDef * hclipboard,GPIO_TypeDef* GPIO_MOSI_Port, uint16_t GPIO_MOSI_Pin,GPIO_TypeDef* GPIO_SCK_Port, uint16_t GPIO_SCK_Pin,GPIO_TypeDef* GPIO_CS_Port, uint16_t GPIO_CS_Pin){

	hclipboard->GPIO_MOSI_Port=GPIO_MOSI_Port;
	hclipboard->GPIO_MOSI_Pin=GPIO_MOSI_Pin;

	hclipboard->GPIO_SCK_Port=GPIO_SCK_Port;
	hclipboard->GPIO_SCK_Pin=GPIO_SCK_Pin;

	hclipboard->GPIO_CS_Port=GPIO_MOSI_Port;
	hclipboard->GPIO_CS_Pin=GPIO_CS_Pin;


 }

 /**
   * @}
   */

 /** @addtogroup CLIPBOARD_Exported_Functions_Group2 CLIPBOARD SPI-Transfer functions
  *  @brief CLIPBOARD SPI-Transfer functions
  *
@verbatim
 ===============================================================================
                      #####  SPI-Transfer Functions  #####
 ===============================================================================
    [..] Dienen zur Kommunikation mit dem Clipboard

@endverbatim
   * @{
   */

 /**
   * @brief  Dient dazu um Daten über die SPI-Verbindung an das Clipboard zu senden
   * @param  hclipboard  Clipboard Handler
   * @param  data Daten
   */
 void MY_CLIPBOARD_SPI_TX(CLIPBOARD_SPI_TypeDef * hclipboard, uint8_t * data){

 	HAL_GPIO_WritePin(hclipboard->GPIO_CS_Port, hclipboard->GPIO_CS_Pin, GPIO_PIN_RESET);

 	for(int i=15;i>=0;i--){
 		HAL_GPIO_WritePin(hclipboard->GPIO_MOSI_Port, hclipboard->GPIO_MOSI_Pin, data[i]);
 		HAL_GPIO_WritePin(hclipboard->GPIO_SCK_Port, hclipboard->GPIO_SCK_Pin, GPIO_PIN_SET);
 		HAL_GPIO_WritePin(hclipboard->GPIO_SCK_Port, hclipboard->GPIO_SCK_Pin, GPIO_PIN_RESET);
 	}

 	HAL_GPIO_WritePin(hclipboard->GPIO_CS_Port, hclipboard->GPIO_CS_Pin, GPIO_PIN_SET);

 }

 /**
   * @brief  Dient dazu um das Bit jeder Stelle zu ermitteln
   * @param  zahl  Zahl
   * @param  stelle Stelle
   * @retval Stellenwert
   */
uint16_t get_value_bitpositions(uint16_t zahl, uint16_t stelle){
 	     return (((zahl& ( 0b0000000000000001<<stelle))>>stelle)+(stelle*((zahl& ( 0b0000000000000001<<stelle))>>stelle)));

 }

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

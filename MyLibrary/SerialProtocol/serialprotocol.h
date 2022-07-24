/**
  ******************************************************************************
  * @file    serialprotocol.h
  * @author  Reiter Roman
  * @version 1.0
  * @date Created on: Jan 23, 2022
  * @brief   Header file des SerialProtocol Module.
  ******************************************************************************
  */

#ifndef SERIALPROTOCOL_SERIALPROTOCOL_H_
#define SERIALPROTOCOL_SERIALPROTOCOL_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
/** @addtogroup MyLibrary
  * @{
  */

/** @addtogroup SERIALPROTOCOL SerialProtocol
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @addtogroup SERIALPROTOCOL_Exported_Types SERIALPROTOCOL Exported Types
  * @{
  */

/**
  * @brief  SERIALPROTOCOL Message Status definition
  */
typedef enum
{
	 SERIALPROT_OK = 0x00,					/*!< Nachricht OK */
	 SERIALPROT_ERROR   = 0x01				/*!< Nachricht nicht OK */
} SERIALPROTCOL_StatusTypeDef;


/**
  * @brief  SERIALPROTOCOL Message Kind definition
  */
typedef enum
{
	 MESSAGEKIND_TEXT_NUMBER = 0x00,		/*!< Text-Nummer Nachricht */
	 MESSAGEKIND_NUMBER_NUMBER   = 0x01, 	/*!< Nummer-Nummer Nachricht */
	 MESSAGEKIND_TEXT_TEXT = 0x02,			/*!< Text-Text Nachricht */
	 MESSAGEKIND_NUMBER_TEXT   = 0x03		/*!< Nummer-Text Nachricht */
} SERIALPROTOCOL_MessageKindTypeDef;


/**
  * @brief  SERIALPROTOCOL Status structures definition
  */
typedef struct
{
  uint8_t CommandName[5];        /*!< Kommandoname */

  SERIALPROTOCOL_MessageKindTypeDef MessageKind; /*!< Nachrichtentyp */

  uint8_t Parameter1[15];       /*!< Parameter1 des Kommandos */

  uint8_t Parameter2[15];       /*!< Parameter2 des Kommandos */
}SERIALPROTOCOL_TypeDef;
/**
  * @}
  */
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/** @addtogroup SERIALPROTOCOL_Exported_Macros SerialProtocol Exported Macros
  * @{
  */

/**
  * @brief  SERIALPROT Kommando-Abfragen
  * @param  __HANDLE__ SERIALPROT handle.
  * @param  __COMMANDNAME__ SERIALPROT Kommandoname
  * @param  __PARAMETER1__ SERIALPROT Parameter1 des Kommandos
  * @param  __PARAMETER2__ SERIALPROT Parameter2 des Kommandos
  * @retval None
  */
#define __SERIALPROT_IS_COMMAND(__HANDLE__, __COMMANDNAME__, __PARAMETER1__, __PARAMETER2__) ((!strcmp((__HANDLE__)->CommandName,(__COMMANDNAME__))) && (!strcmp((__HANDLE__)->Parameter1,(__PARAMETER1__))) && (!strcmp((__HANDLE__)->Parameter2,(__PARAMETER2__))))

/**
  * @brief  SERIALPROT Kommando-Abfragen
  * @param  __HANDLE__ SERIALPROT handle.
  * @param  __COMMANDNAME__ SERIALPROT Kommandoname
  * @param  __PARAMETER1__ SERIALPROT Parameter1 des Kommandos
  * @param  __PARAMETER2__ SERIALPROT Parameter2 des Kommandos
  * @retval None
  */
#define __SERIALPROT_IS_COMMANDNAME(__HANDLE__, __COMMANDNAME__)  (!strcmp((__HANDLE__)->CommandName,(__COMMANDNAME__)))

/**
  * @brief  SERIALPROT Kommando-Abfragen
  * @param  __HANDLE__ SERIALPROT handle.
  * @param  __COMMANDNAME__ SERIALPROT Kommandoname
  * @param  __PARAMETER1__ SERIALPROT Parameter1 des Kommandos
  * @param  __PARAMETER2__ SERIALPROT Parameter2 des Kommandos
  * @retval None
  */
#define __SERIALPROT_IS_PARAMETER1(__HANDLE__, __PARAMETER1__)  (!strcmp((__HANDLE__)->Parameter1,(__PARAMETER1__)))

/**
  * @brief  SERIALPROT Kommando-Abfragen
  * @param  __HANDLE__ SERIALPROT handle.
  * @param  __COMMANDNAME__ SERIALPROT Kommandoname
  * @param  __PARAMETER1__ SERIALPROT Parameter1 des Kommandos
  * @param  __PARAMETER2__ SERIALPROT Parameter2 des Kommandos
  * @retval None
  */
#define __SERIALPROT_IS_PARAMETER2(__HANDLE__, __PARAMETER2__)  (!strcmp((__HANDLE__)->Parameter2,(__PARAMETER2__)))
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup SERIALPROTOCOL_Exported_Functions SERIALPROTOCOL Exported Functions
  * @{
  */

/** @addtogroup SERIALPROTOCOL_Exported_Functions_Group1
  * @{
  */
/* Initialization and de-initialization functions *****************************/
void MYLIB_SERIALPROT_XCHANGE(SERIALPROTOCOL_TypeDef *hserialprot,uint8_t * RxBuffer, uint8_t * last );

/**
  * @}
  */

/** @addtogroup SERIALPROTOCOL_Exported_Functions_Group2
  * @{
  */
/* Callback  functions *****************************************************/
uint8_t SERIALPROT_Command_GPO_Callback(SERIALPROTOCOL_TypeDef *hserialprot);
uint8_t SERIALPROT_Command_CRS_Callback(SERIALPROTOCOL_TypeDef *hserialprot);
uint16_t SERIALPROT_Command_CRG_Callback(SERIALPROTOCOL_TypeDef *hserialprot);
uint8_t SERIALPROT_Command_CBS_Callback(SERIALPROTOCOL_TypeDef *hserialprot);
uint16_t SERIALPROT_Command_CBG_Callback(SERIALPROTOCOL_TypeDef *hserialprot);
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

#endif /* SERIALPROTOCOL_SERIALPROTOCOL_H_ */

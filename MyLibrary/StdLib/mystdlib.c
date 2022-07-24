/**
  ******************************************************************************
  * @file    mystdlib.c
  * @author  Reiter Roman
  * @version 1.0
  * @date Created on: 24.12.2021
  * @brief   StdLib
  *          This file provides firmware functions to manage the following
  *          functionalities of the General Purpose Input/Output (GPIO) peripheral:
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================
   [..] Als erstes muss das ROTARY module initialisiert werden, welches auf
    	zwei unterschiedliche Arten erfolgen kann.

    (#) void MY_ROTARY_Init_Strobed(..)
        (++) Mit dieser Initialisierung ist es möglich einzelnen LED's
        	 Ein- und Auszuschalten sowie deren Helligkeit einzelnen einzustellen.


  @endverbatim
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "StdLib/mystdlib.h"

/** @addtogroup MyLibrary
  * @{
  */

/** @addtogroup MYSTDLIB MYSTDLIB
  * @brief MYSTDLIB module driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @addtogroup MYSTDLIB_Exported_Functions MYSTDLIB Exported Functions
  * @{
  */

/** @addtogroup MYSTDLIB_Exported_Functions_Group1 MYSTDLIB Operation functions
 *  @brief    Operation Functions
 *
@verbatim
 ===============================================================================
                      #####  Operation Functions  #####
 ===============================================================================
    [..] Dienen zum steuern des Rotary Moduls
      (+) Dient zum Ein- und Ausschalten der jeweiligen LED's
      (+) Dient zum Einstellen der Helligkeit

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
void MY_STDLIB_Delay(TIM_HandleTypeDef *htim ,uint16_t us){
	//  uint32_t d = HAL_GetTickFreq();
	//__HAL_TIM_SET_PRESCALER(&htim6, 16-1);
	__HAL_TIM_SET_COUNTER(htim,0);  // set the counter value a 0
	while (__HAL_TIM_GET_COUNTER(htim) < us);  // wait for the counter to reach the us input in the parameter
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

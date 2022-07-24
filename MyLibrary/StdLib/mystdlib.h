/**
  ******************************************************************************
  * @file    mystdlib.h
  * @author  Reiter Roman
  * @version 1.0
  * @date Created on: 24.12.2021
  ******************************************************************************
  */
#ifndef STDLIB_MYSTDLIB_H_
#define STDLIB_MYSTDLIB_H_


#ifdef __cplusplus
 extern "C" {
#endif


 /* Includes ------------------------------------------------------------------*/
#include "stm32l4xx.h"

 /** @addtogroup MyLibrary
   * @{
   */

 /** @addtogroup MYSTDLIB MYSTDLIB
   * @{
   */

 /* Exported types ------------------------------------------------------------*/
 /* Exported constants --------------------------------------------------------*/
 /* Exported macro ------------------------------------------------------------*/
 /* Private macros ------------------------------------------------------------*/
 /* Exported functions --------------------------------------------------------*/

 /** @addtogroup MYSTDLIB_Exported_Functions MYSTDLIB Exported Functions
   * @{
   */

 /** @addtogroup MYSTDLIB_Exported_Functions_Group1 MYSTDLIB Operation functions
  */
 void MY_STDLIB_Delay(TIM_HandleTypeDef *htim ,uint16_t us);

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

#endif /* STDLIB_MYSTDLIB_H_ */

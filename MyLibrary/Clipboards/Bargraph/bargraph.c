/**
  ******************************************************************************
  * @file    bargraph.c
  * @author  Reiter Roman
  * @version 1.0
  * @date Created on: Jan 23, 2022
  * @brief   BARGRAPH module driver.
  *          Dieses File dient dazu, um das Bargraph Click-Board anzusteuern bzw.
  *          einzelne Segmente Ein- und Ausgeschaltet sowie die Helligkeit
  *          eingestellt werden.
  *
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================
   [..] Als erstes muss das BARGRAPH module initialisiert werden, welches auf
    	zwei unterschiedliche Arten erfolgen kann.

    (#) void MY_BARGRAPH_Init_Strobed(..)
        (++) Mit dieser Initialisierung ist es möglich die einzelnen Segmente
        	 Ein- und Auszuschalten sowie die Helligkeit jedes einzelnen Moduls
        	 mit der Funktion MY_BARGRAPH_SET_BITS(...) einzustellen.

    (#) void MY_BARGRAPH_Init_Pulsed(..)
        (++) Mit dieser Initialisierung ist es möglich die einzelnen Segmente
        	 Ein- und Auszuschalten sowie die Helligkeit des gesamten Moduls
        	 einzustellen.

  @endverbatim
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "bargraph.h"

/** @addtogroup MyLibrary
  * @{
  */

/** @addtogroup CLIPBOARDS CLIPBOARDS
  * @brief CLIPBOARD Module Drivers
  * @{
  */

/** @addtogroup BARGRAPH BARGRAPH
  * @brief BARGRAPHL Module Driver
  * @{
  */
/* Private typedef -----------------------------------------------------------*/

/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static uint8_t bar_rot[11][16]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}};

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup BARGRAPH_Private_Functions BARGRAPH Private Functions
  * @{
  */

static void MY_BARGRAPH_SET_BRITGHTNESS_PWM(TIM_HandleTypeDef *htim, uint8_t * percent);
static void MY_BARGRAPH_SET_BITS_PULSED(MY_BARGRAPH_HandleTypeDef * hbargraph,uint16_t * bit_array_of_segments,uint8_t * bit_array_of_brightness);
static void MY_BARGRAPH_SET_BITS_PWM(MY_BARGRAPH_HandleTypeDef * hbargraph, uint16_t * bit_array_of_segments);

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup BARGRAPH_Exported_Functions BARGRAPH Exported Functions
  * @{
  */

/** @addtogroup BARGRAPH_Exported_Functions_Group1 BARGRAPH Initialization Functions
 *  @brief   Funktionen fürs initialisieren des Bargraph Modules
 *
@verbatim
 ===============================================================================
             ##### Initialization Functions  #####
 ===============================================================================
    [..] Dienen fürs initialisieren des Bargraph Modules

@endverbatim
  * @{
  */

/**
  * @brief  Initialisiert den Bargraphen mit der Strobed-Helligkeit
  * @param  hbargraph Handle Bargraph
  * @param  htim Handle Timer
  * @param  GPIO_MOSI_Port MOSI-Port des Clipboards
  * @param  GPIO_MOSI_Pin MOSI-Pin des Clipboards
  * @param  GPIO_SCK_Port SCK-Port des Clipboards
  * @param  GPIO_SCK_Pin SCK-Pin des Clipboards
  * @param  GPIO_CS_Port CS-Pin des Clipboards
  * @param  GPIO_CS_Pin CS-Pin des Clipboards
  */
void MY_BARGRAPH_Init_Strobed(MY_BARGRAPH_HandleTypeDef * hbargraph ,TIM_HandleTypeDef * htim,GPIO_TypeDef* GPIO_MOSI_Port, uint16_t GPIO_MOSI_Pin,GPIO_TypeDef* GPIO_SCK_Port, uint16_t GPIO_SCK_Pin,GPIO_TypeDef* GPIO_CS_Port, uint16_t GPIO_CS_Pin){
	MY_CLIPBOARD_Init(&hbargraph->hclipboardR,GPIO_MOSI_Port, GPIO_MOSI_Pin, GPIO_SCK_Port, GPIO_SCK_Pin, GPIO_CS_Port, GPIO_CS_Pin);
	hbargraph->htimR = htim;
	HAL_TIM_Base_Start(htim);
	hbargraph->BrightnessMode = MY_BARGRAPH_BRITHNESSMODE_STROBED;
}

/**
  * @brief  Initialisiert den Bargraphen mit der Pulsed-Helligkeit
  * @param  hbargraph  Handle Bargraph
  * @param  htim  Handle Timer für PWM
  * @param  channel  PWM Channel
  * @param  GPIO_MOSI_Port  MOSI_Port
  * @param  GPIO_MOSI_Pin  MOSI_Pin
  * @param  GPIO_SCK_Port  SCK_Port
  * @param  GPIO_SCK_Pin  SCK_Pin
  * @param  GPIO_CS_Port  CS_Port
  * @param  GPIO_CS_Pin  CS_Pin
  */
void MY_BARGRAPH_Init_Pulsed(MY_BARGRAPH_HandleTypeDef * hbargraph ,TIM_HandleTypeDef * htim, uint32_t channel, GPIO_TypeDef* GPIO_MOSI_Port, uint16_t GPIO_MOSI_Pin,GPIO_TypeDef* GPIO_SCK_Port, uint16_t GPIO_SCK_Pin,GPIO_TypeDef* GPIO_CS_Port, uint16_t GPIO_CS_Pin){
	MY_CLIPBOARD_Init(&hbargraph->hclipboardR,GPIO_MOSI_Port, GPIO_MOSI_Pin, GPIO_SCK_Port, GPIO_SCK_Pin, GPIO_CS_Port, GPIO_CS_Pin);
	hbargraph->htimR = htim;
	HAL_TIMEx_PWMN_Start(htim,channel);
	HAL_TIM_PWM_Start(htim,channel);
	hbargraph->BrightnessMode = MY_BARGRAPH_BRITHNESSMODE_PULSED;
}


/**
  * @}
  */

/** @addtogroup BARGRAPH_Exported_Functions_Group2 BARGRAPH Operation Functions
 *  @brief   Operation functions
 *
@verbatim
 ===============================================================================
                      #####  Operation Functions  #####
 ===============================================================================
    [..] Dienen zum steuern des Bargraph Moduls
      (+) Dient zum Ein- und Ausschalten der jeweiligen Segmente
      (+) Dient zum einstellen der Helligkeit

@endverbatim
  * @{
  */

/**
  * @brief  Setzt die jeweiligen Segmente.
  * @param  hbargraph  Bargraph handle.
  * @param  bit_array_of_leds  Bitarray, welche Segmente Ein- und Ausgeschaltet werden sollen
  * @param  bit_array_of_brightness  Helligkeitsarray - sorgt für die Helligkeit jedes einzelnen Segmenes 0-100.
  */
void MY_BARGRAPH_SET_BITS(MY_BARGRAPH_HandleTypeDef * hbargraph,uint16_t * bit_array_of_segments,uint8_t * bit_array_of_brightness ){

	if(hbargraph->BrightnessMode){
		MY_BARGRAPH_SET_BITS_PULSED(hbargraph,bit_array_of_segments, bit_array_of_brightness );
	}else{
		MY_BARGRAPH_SET_BITS_PWM(hbargraph,bit_array_of_segments);
		MY_BARGRAPH_SET_BRITGHTNESS_PWM(hbargraph->htimR,bit_array_of_brightness );
	}
}

/**
  * @}
  */

/**
  * @}
  */

/* Private functions----------------------------------------------------------*/
/** @addtogroup BARGRAPH_Private_Function
  * @{
  */

/**
  * @brief  Setzt die jeweiligen Segmente mit PWM.
  * @param  hbargraph  Bargraph handle.
  * @param  bit_array_of_segments  Bitarray, welche Segmente Ein- und Ausgeschaltet werden sollen
  * @param  bit_array_of_brightness  Helligkeitsarray - sorgt für die Helligkeit jedes einzelnen Segmenes 0-100.
  */
static void MY_BARGRAPH_SET_BITS_PULSED(MY_BARGRAPH_HandleTypeDef * hbargraph,uint16_t * bit_array_of_segments,uint8_t * bit_array_of_brightness){
	/*
	for(uint8_t i =0;i<10;i++){
		MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[i]);
		MY_STDLIB_Delay(hbargraph->htimR,(100-bit_array_of_brightness[i])*10);
		MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[get_value_bitpositions(bit_array_of_segments,(uint16_t)i)]);
		MY_STDLIB_Delay(hbargraph->htimR,10*bit_array_of_brightness[i]);
	}

		*/
    MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[0]);
  	MY_STDLIB_Delay(hbargraph->htimR,(100-bit_array_of_brightness[0])*10);
  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[get_value_bitpositions(bit_array_of_segments,0)]);
  	MY_STDLIB_Delay(hbargraph->htimR,10*bit_array_of_brightness[0]);

  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[0]);
  	MY_STDLIB_Delay(hbargraph->htimR,(100-bit_array_of_brightness[1])*10);
  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[get_value_bitpositions(bit_array_of_segments,1)]);
  	MY_STDLIB_Delay(hbargraph->htimR,10*bit_array_of_brightness[1]);

  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[0]);
  	MY_STDLIB_Delay(hbargraph->htimR,(100-bit_array_of_brightness[2])*10);
  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[get_value_bitpositions(bit_array_of_segments,(uint32_t)2)]);
  	MY_STDLIB_Delay(hbargraph->htimR,10*bit_array_of_brightness[2]);

  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[0]);
  	MY_STDLIB_Delay(hbargraph->htimR,(100-bit_array_of_brightness[3])*10);
  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[get_value_bitpositions(bit_array_of_segments,3)]);
  	MY_STDLIB_Delay(hbargraph->htimR,10*bit_array_of_brightness[3]);

  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[0]);
  	MY_STDLIB_Delay(hbargraph->htimR,(100-bit_array_of_brightness[4])*10);
  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[get_value_bitpositions(bit_array_of_segments,4)]);
  	MY_STDLIB_Delay(hbargraph->htimR,10*bit_array_of_brightness[4]);

  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[0]);
  	MY_STDLIB_Delay(hbargraph->htimR,(100-bit_array_of_brightness[5])*10);
  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[get_value_bitpositions(bit_array_of_segments,5)]);
  	MY_STDLIB_Delay(hbargraph->htimR,10*bit_array_of_brightness[5]);

  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[0]);
  	MY_STDLIB_Delay(hbargraph->htimR,(100-bit_array_of_brightness[6])*10);
  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[get_value_bitpositions(bit_array_of_segments,6)]);
  	MY_STDLIB_Delay(hbargraph->htimR,10*bit_array_of_brightness[6]);

  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[0]);
  	MY_STDLIB_Delay(hbargraph->htimR,(100-bit_array_of_brightness[7])*10);
  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[get_value_bitpositions(bit_array_of_segments,7)]);
  	MY_STDLIB_Delay(hbargraph->htimR,10*bit_array_of_brightness[7]);

  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[0]);
  	MY_STDLIB_Delay(hbargraph->htimR,(100-bit_array_of_brightness[8])*10);
  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[get_value_bitpositions(bit_array_of_segments,8)]);
  	MY_STDLIB_Delay(hbargraph->htimR,10*bit_array_of_brightness[8]);

  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[0]);
  	MY_STDLIB_Delay(hbargraph->htimR,(100-bit_array_of_brightness[9])*10);
  	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rot[get_value_bitpositions(bit_array_of_segments,9)]);
	MY_STDLIB_Delay(hbargraph->htimR,10*bit_array_of_brightness[9]);

}

/**
  * @brief  Setzt die jeweiligen Segmente mittels PWM.
  * @param  hbargraph  Bargraph handle.
  * @param  bit_array_of_segments  Bitarray, welche Segmente Ein- und Ausgeschaltet werden sollen.
  */
static void MY_BARGRAPH_SET_BITS_PWM(MY_BARGRAPH_HandleTypeDef * hbargraph, uint16_t * bit_array_of_segments){

	uint8_t bar_rotz[16]={0};

	for(uint8_t i=0; i<10;i++){
		if(get_value_bitpositions(bit_array_of_segments,i)>0){
			bar_rotz[get_value_bitpositions(bit_array_of_segments,i)-1]=1;
		}
	}

	MY_CLIPBOARD_SPI_TX(&hbargraph->hclipboardR,bar_rotz);
}

/**
  * @brief  Setzt die jeweiligen Segmente mit PWM.
  * @param  htim  Timer handle.
  * @param  percent  Helligkeit von 0-100.
  */
static void MY_BARGRAPH_SET_BRITGHTNESS_PWM(TIM_HandleTypeDef *htim, uint8_t * percent){

	htim->Instance->CCR3= (htim->Init.Period/100) * (uint32_t) percent;
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

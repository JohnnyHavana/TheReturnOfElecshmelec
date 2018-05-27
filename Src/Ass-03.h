//     $Date: 2018-05-22 06:24:02 +1000 (Tue, 22 May 2018) $
// $Revision: 1330 $
//   $Author: Peter $

// Assignment 3 include file

#ifndef ASS_03_H_
#define ASS_03_H_

// Standard includes
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#include "stm32f4xx_hal.h"
#include "usart.h"
#include "touch_panel.h"
#include "openx07v_c_lcd.h"
#include "fatfs.h"
#include "adc.h"
#include "ff.h"

#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <math.h>


#include "SystemColours.h"
// OS handles
extern osThreadId defaultTaskHandle;
extern osThreadId myTask02Handle;
extern osThreadId myTask03Handle;
extern osThreadId myTask04Handle;
extern osTimerId myTimer01Handle;

extern osSemaphoreId myBinarySem01Handle;
extern osSemaphoreId myBinarySem02Handle;
extern osSemaphoreId myBinarySem03Handle;
extern osSemaphoreId myBinarySem04Handle;
extern osSemaphoreId myBinarySem05Handle;
extern osSemaphoreId myBinarySem06Handle;
extern osMessageQId myQueue01Handle;
extern osMutexId myMutex01Handle; // Protect LCD
extern osMutexId myMutex02Handle; // Protect console output
extern osMutexId myMutex03Handle;


// Assignment tasks
extern void Ass_03_Task_01(void const *argument);
extern void Ass_03_Task_02(void const *argument);
extern void Ass_03_Task_03(void const *argument);
extern void Ass_03_Task_04(void const *argument);

// Library functions
extern uint8_t BSP_TP_Init(void);
extern uint8_t BSP_TP_GetDisplayPoint(Coordinate *pDisplay);

// Front panel input
extern uint8_t getfp(Coordinate *display);

// STEPIEN: Safe printf() to ensure that only one task can write to
//          the console at a time



#define safe_printf(fmt, ...) \
	osMutexWait(myMutex02Handle, osWaitForever); \
	printf(fmt, ##__VA_ARGS__); \
	osMutexRelease(myMutex02Handle);

//
// ADD YOUR CODE
//

#define printSystem() \
	safe_printf("%sSYSTEM%s: ",C_SYSTEM,C_NORMAL);

#define printDebug() \
	safe_printf("%sDEBUG%s: ",C_DEBUG,C_NORMAL);

#define printInput() \
	safe_printf("%sINPUT%s: ",C_INPUT,C_NORMAL);

#define printError() \
	safe_printf("%sERROR%s: ",C_ERROR,C_NORMAL);



#define system_safe_printf(fmt, ...) \
		printSystem(); \
		safe_printf(fmt, ##__VA_ARGS__); \

#define debug_safe_printf(fmt, ...) \
		printDebug(); \
		safe_printf(fmt, ##__VA_ARGS__); \

#define input_safe_printf(fmt, ...) \
		printInput(); \
		safe_printf(fmt, ##__VA_ARGS__); \

#define error_safe_printf(fmt, ...) \
		printError(); \
		safe_printf(fmt, ##__VA_ARGS__); \





#endif /* ASS_03_H_ */

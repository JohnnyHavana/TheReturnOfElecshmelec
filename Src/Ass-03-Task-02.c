//     $Date: 2018-05-22 06:24:02 +1000 (Tue, 22 May 2018) $
// $Revision: 1330 $
//   $Author: Peter $

#include "Ass-03.h"

//
// This task can be used as the main pulse rate application as it takes
// input from the front panel.
//
// *** MAKE UPDATES TO THE CODE AS REQUIRED ***
//
// Draw the boxes that make up the buttons and take action when the
// buttons are pressed. See suggested updates for the touch panel task
// that checks for button presses. Can do more in that task.

#define XOFF 10
#define YOFF 10
#define XSIZE 240
#define YSIZE 160

void Ass_03_Task_02(void const * argument)
{

	uint32_t loop=0;

	Coordinate display;

	osSignalWait(1,osWaitForever);
	system_safe_printf("Hello from Task 2 - Pulse Rate Application (touch screen input)\n");

while (1)
{
	if (getfp(&display) == 0)
    {
		if((display.y > YOFF+5) && (display.y < YOFF+YSIZE-5) &&
			(display.x > XOFF+5) && (display.x < XOFF+XSIZE-5))
		{
			osMutexWait(myMutex01Handle, osWaitForever);
			BSP_LCD_FillCircle(display.x, display.y, 2);
			osMutexRelease(myMutex01Handle);
			loop++;
			system_safe_printf("Task 2: %d (got  %3d,%3d)\n", loop, display.x, display.y);
		}
    }
}
}

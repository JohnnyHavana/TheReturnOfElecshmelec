/**
 * ELEC3730 ASSIGNMENT 3
 * TASK 3 - VALUE SENDER
 * JORDAN HAIGH AND EVAN GRESHAM
 *
 *
 * Class creates a message and puts it onto a message queue to be received by task 2
 * These are values the x and y coordinates of where the using is currently pressing on the display
 *
 * */


#include "Ass-03.h"
#include "Button.h"
#include "Question2.h"

//
// Task that reads input from the front panel display. It uses a timer
// to periodically signal the task to check if the touch panel is being
// pressed. If it has, the position location is put onto a message queue.
// Debouncing of the input is also done to ensure that multiple messages
// are not generated.
//
// Function also provided to read from the message queue.
//
// *** MAKE UPDATES TO THE CODE AS REQUIRED ***
//
// Suggested update is to send a character that represents the button
// being pressed rather than the position on the front panel. Can also improve
// the setting of the DEBOUNCE_COUNT limit

// The number of times to register the front panel as being pressed
#define ON_COUNT   1
#define OFF_COUNT 20

/*
 * Function donated by Peter Stepien
 * Creates a message to put on the message queue containing the x and y coordinates
 * Returns 0 is successful or 1 if not
 * */
uint8_t getfp(Coordinate *display)
{
	osEvent event;

	event = osMessageGet(myQueue01Handle, osWaitForever);
    if (event.status == osEventMessage)
    {
    	display->x = (uint16_t)(event.value.v >> 16);
    	display->y = (uint16_t)(event.value.v);
    	return 0;
    }
    else
    {
    	return 1;
    }
}

/*
 * One of the main entry points to the program
 * Determines debouncing to find if a finger is on the screen.
 * Once it determines finger is on, it will bundle the x and y coords and send it off
 * */
void Ass_03_Task_03(void const * argument)
{
	int8_t pressed_count=ON_COUNT;  // Debounce counter (not pressed)
	uint16_t pressed_num=0;         // Number of times a key is pressed
	Coordinate display;             // Pressed location

	osSignalWait(1,osWaitForever);
	system_safe_printf("Hello from Task 3 - Front Panel (detects touch screen presses)\n");

	while (1)
	{
		if (BSP_TP_GetDisplayPoint(&display) != 0)
		{
			// Not pressed: reset debounce counter
			if (pressed_count < 0)
			{
				pressed_count++;
				if (pressed_count == 0)
				{
					pressed_count = ON_COUNT;
				}
			}
			else
			{
				pressed_count = ON_COUNT;
			}
		}
		else
		{
			// Pressed: count down debounce unless already expired
			if (pressed_count > 0)
			{
				pressed_count--;
				if (pressed_count == 0)
				{
					// Debounced: queue key pressed message
					pressed_num++; //iterator


					//safe_printf("Task 3: %d (sent %3d,%3d)\n", pressed_num, display.x, display.y);
					system_safe_printf("Task 3: %d (sent %3d,%3d)\n", pressed_num, display.x, display.y);

					osMessagePut (myQueue01Handle, (uint32_t)((display.x << 16) + display.y), 0);
					pressed_count = -OFF_COUNT;
				}
			}
			else
			{
				pressed_count = -OFF_COUNT;
			}
		}
		// Wait before checking key pressed again
		osSemaphoreWait(myBinarySem04Handle, osWaitForever);
	}
}

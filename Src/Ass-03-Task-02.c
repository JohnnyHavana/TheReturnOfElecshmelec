/**
 * ELEC3730 ASSIGNMENT 3
 * TASK 2 - VALUE RECEIVER
 * JORDAN HAIGH AND EVAN GRESHAM
 *
 *
 * Class receives values from a message queue
 * These values are the x and y coordinates of where the using is currently pressing on the display
 *
 * */


#include "Ass-03.h"
#include "Question2.h"
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

/*
 * One of the four entry points for the program
 * Continuously waiting for a signal from another thread.
 * Once we get the coordinate, we canbegin to determine what button is currently pressed
 * */
void Ass_03_Task_02(void const * argument)
{

	uint32_t loop=0;

	Coordinate display;

	osSignalWait(1,osWaitForever);
	system_safe_printf("Hello from Task 2 - Pulse Rate Application (touch screen input)\n");

	while (1)
	{
		if (getfp(&display) == 0) //received coordinate
		{
			//create a current button pressed
			Button currentButtonPressed;
			//initialised with these values to prevent warnings. can be changed later
			currentButtonPressed.text = "NOT A BUTTON";
			currentButtonPressed.id = 999;

			//go through button array and figure out which button was being pressed
			for(int i = 0; i < 9;i++)
			{
			  if(buttonHere(display.x, display.y, buttons[i])!= -1) //found a valid
			  {
				  if(debugOn ==1)debug_safe_printf("Found button..\n");
				  currentButtonPressed = buttons[i];
				  break;
			  }
			}

			if(debugOn ==1)debug_safe_printf("I am touching '%s'. ID is %d \n" , currentButtonPressed.text, currentButtonPressed.id);
		//					if(debugOn ==1)printf("TOUCH:  Got (%3d,%3d)\n", display.x, display.y);
			if(currentButtonPressed.id != 999){ //if it is a button, call its function
				buttonPressed(currentButtonPressed);
			}
		}
	}
}

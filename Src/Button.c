/*
 * Button.cpp
 *
 *  Created on: 25 May 2018
 *      Author: c3256730
 */

#include "Button.h"

#ifndef MEBUTTONS
#define MEBUTTONS
Button buttons[10]= {
/*    STARTX  STARTY  WIDTH   HEIGHT    LABEL       ID     VALIDITY*/
		{15,	45,		30,		30,		"START",	1,		1},
		{15,	90,		30,		30,		"STOP",		2,		1},
		{15,	135,	30,		30,		"DEBUG",	3,		1},
		{15,	180,	30,		30,		"SAVE",		4,		1},
		{90,	200,	30,		30,		"LOAD",		5,		1},
		{180,	170,	30,		30,		"S1",		6,		1},
		{250,	160,	30,		30,		"S2",		7,		1},
		{180,	200,	30,		30,		"S3",		8,		1},
		{250,	190,	30,		30,		"S4",		9,		1},
		{NULL,	NULL,	NULL,	NULL,	NULL,		0,		0}
};
#endif
/**************************Button Methods********************************/

/*
 * Initialise buttons with startx, starty, width and height. allocate text depending on id that is given
 * */


/*
 * Determine if a button is being pressed at the x y input coordinates
 * If it is able to determine the button that is being pressed, it will return its id
 * Otherwise return -1
 * */
int buttonHere(int x, int y, Button button)
{
	//returns the button id or -1
	if(button.startX  < x &&
			x < button.startX + button.width &&
			button.startY  < y &&
			y < button.startY + button.height)
		return button.id;
	else
		return -1;
}

/*
 * Show button on LCD Screen
 * */
void showButton(Button button){

	BSP_LCD_DrawRect(button.startX, button.startY, button.width, button.height);
	BSP_LCD_SetFont(&Font20);
	BSP_LCD_DisplayStringAt(button.startX + button.width/2,button.startY + button.height/2 -8,button.text,CENTER_MODE);
}


/*
 * Print all button information to string
 * */
void buttonToString(Button button)
{
	if(debugOn == 1)
	{
		safe_printf("Debug: \n");
		safe_printf("Button startX: %d\n", button.startX);
		safe_printf("Button startY: %d\n", button.startY);
		safe_printf("Button width: %d\n", button.width);
		safe_printf("Button height: %d\n", button.height);
		safe_printf("Button text: %s\n", button.text);
		safe_printf("Button id: %d\n", button.id);
	}

}

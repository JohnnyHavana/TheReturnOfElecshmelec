/*
 * Button.cpp
 *
 *  Created on: 25 May 2018
 *      Author: c3256730
 */

#include "Button.h"

#ifndef MEBUTTONS
#define MEBUTTONS
	#define WIDTH 50
	#define HEIGHT 50
Button buttons[7]= {
/*    STARTX  STARTY    WIDTH       HEIGHT    LABEL       ID     VALIDITY		pressed*/
		{255,	10,		WIDTH+12,	HEIGHT,		"Start",		1,		1,  	1, 		LCD_COLOR_GREEN},
		{255,	70,		WIDTH+12,	HEIGHT,		"Stop",			2,		1,  	0,	 	LCD_COLOR_RED},
		{10,	180,	WIDTH,		HEIGHT,		"Load",			3,		1,  	0,	 	LCD_COLOR_WHITE},
		{70,	180,	WIDTH,		HEIGHT,		"REC",			4,		1,		0,	 	LCD_COLOR_RED},
		{140,	180,	WIDTH,		HEIGHT,		"SAV1",			5,		1,		1,	 	LCD_COLOR_LIGHTBLUE},
		{200,	180,	WIDTH,		HEIGHT,		"SAV2",			6,		1,		0,	 	LCD_COLOR_LIGHTBLUE},
		{260,	180,	WIDTH,		HEIGHT,		"SAV3",			7,		1,		0,	 	LCD_COLOR_LIGHTBLUE}
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



	if(button.pressed){
		BSP_LCD_SetTextColor(button.colour);
		BSP_LCD_SetBackColor(button.colour);
	}else{
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	}


	BSP_LCD_FillRect(button.startX+1, button.startY+1, button.width-1, button.height-2);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_DisplayStringAt(button.startX + button.width/2,button.startY + button.height/2 -8,button.text,CENTER_MODE);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);

}


/*
 * Print all button information to string
 * */
void buttonToString(Button button)
{
	if(debugOn == 1)
	{
		debug_safe_printf("Button %d\n",button.id);
		safe_printf("Button startX: %d\n", button.startX);
		safe_printf("Button startY: %d\n", button.startY);
		safe_printf("Button width: %d\n", button.width);
		safe_printf("Button height: %d\n", button.height);
		safe_printf("Button text: %s\n", button.text);
	}

}




#ifndef BUTTON_H_
#define BUTTON_H_
#include "Ass-03.h"

#include "stm32f4xx_hal.h"

#include "openx07v_c_lcd.h"

#include "touch_panel.h"

#ifndef MEBUTTONSTRUCT
#define MEBUTTONSTRUCT
	//Button struct necessary for multiple buttons - Form of encapsulating
	typedef struct {
		  int startX;
		  int startY;
		  int width;
		  int height;
		  char* text;
		  int id;
		  int valid;
		  int pressed;
		  uint16_t colour;
	}Button;
#endif


Button buttons[9];

int buttonHere(int x, int y, Button button); //Determine if button at X,Y coordinate - return Button ID if true
void showButton(Button button); //Display button on Calculator
void buttonToString(Button button);

#endif /* BUTTON_H_ */

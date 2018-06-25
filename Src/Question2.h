#ifndef QUES2
#define QUES2
#include "Button.h"
#include "Ass-03.h"

/*
 *
 * ELEC3730 ASSIGNMENT 3
 * QUESTION2.H
 * JORDAN HAIGH AND EVAN GRESHAM
 *
 *
 * Class stores relevant methods that are used to build functionality for question 2
 *
 * */
//Checks for what button is being pressed
void buttonPressed(Button buttonNutton);
//Determines if start pressed, does functionality for that
void startPressed();
//Stop button pressed - grabs semaphore and stops writing
void stopPressed();
//Recording pressed, locks down board so that no other buttons can be pressed
void recordPressed();
//Load pressed - loads in save file
void loadPressed();
//Save pressed, writes to argument save file
void savePressed(uint8_t saveNo);
//Increases time scale if allowed
void zoomInPressed();
//Decreases time scale if allowed
void zoomOutPressed();
//Updates speed for writing on LCD
void updateSpeed();
//Updates time span string on screen
void updateTimeSpan(char* newTimeScale);

#endif

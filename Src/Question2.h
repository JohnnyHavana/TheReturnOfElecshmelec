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

void buttonPressed(Button buttonNutton);
void startPressed();
void stopPressed();
void recordPressed();
void loadPressed();
void savePressed(uint8_t saveNo);
void zoomInPressed();
void zoomOutPressed();
void updateSpeed();
void updateTimeSpan(char* newTimeScale);

#endif

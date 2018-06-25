#ifndef QUES2
#define QUES2
#include "Button.h"
#include "Ass-03.h"

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

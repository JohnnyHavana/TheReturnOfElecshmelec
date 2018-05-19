#include "Ass-03.h"
#include "SystemColours.h"

void analyseCommands();
void helpDesk(uint8_t argNum, char *argStrings[]);
void analog(uint8_t argNum, char *argStrings[]);
void ls(uint8_t argNum, char *argStrings[]);
void cd(uint8_t argNum, char *argStrings[]);
void mkdir(uint8_t argNum, char *argStrings[]);
void cp(uint8_t argNum, char *argStrings[]);
void rm(uint8_t argNum, char *argStrings[]);


uint8_t checkForNumericArgument(uint8_t processingIntegerFlag,uint8_t argNum, char* argStrings[]);
uint8_t checkArgumentLength(uint8_t flag, uint8_t expectedWordCount, uint8_t argNum);

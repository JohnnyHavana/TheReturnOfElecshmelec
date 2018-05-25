#ifndef COMMANDLIST_H_
#define COMMANDLIST_H_


#include "Ass-03.h"
#include "SystemColours.h"
#include "ff.h"
#include "Debug.h"
#include <string.h>

void analyseCommands(uint8_t argNum, char *argStrings[]);
void helpDesk(uint8_t argNum, char *argStrings[]);
void analog(uint8_t argNum, char *argStrings[]);
void ls(uint8_t argNum, char *argStrings[]);
void cd(uint8_t argNum, char *argStrings[]);
void mkdir(uint8_t argNum, char *argStrings[]);
void cp(uint8_t argNum, char *argStrings[]);
void rm(uint8_t argNum, char *argStrings[]);
void scan_files (char* path);


uint8_t checkForNumericArgument(uint8_t processingIntegerFlag,uint8_t argNum, char* argStrings[]);
uint8_t checkArgumentLength(uint8_t flag, uint8_t expectedWordCount, uint8_t argNum);


char currentFilePath[100];

#endif

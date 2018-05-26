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
	void scan_files (char* path);

void cd(uint8_t argNum, char *argStrings[]);
	void moveForwardDirectory(char* argStrings[], char* previousDirectory);
	void moveBackwardDirectory(char* previousDirectory);

void mkdir(uint8_t argNum, char *argStrings[]);

void cp(uint8_t argNum, char *argStrings[]);

	int checkFileFolderExists(char* directoryOfInterest);
	void copyObjectToObject(char* source, char* destination);
	void fileToFile(char* source, char* destination);
	void folderToFolder(char* source, char* destination);

void rm(uint8_t argNum, char *argStrings[]);

void mkfil(int argNum, char* argStrings[]);
void read(int argNum, char* argStrings[]);
void write(int argNum, char* argStrings[]);







uint8_t checkForNumericArgument(uint8_t processingIntegerFlag,uint8_t argNum, char* argStrings[]);
uint8_t checkArgumentLength(uint8_t flag, uint8_t expectedWordCount, uint8_t argNum);


char currentFilePath[100];

#endif

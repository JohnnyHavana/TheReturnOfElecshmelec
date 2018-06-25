#ifndef COMMANDLIST_H_
#define COMMANDLIST_H_


#include "Ass-03.h"

/*
 *
 * ELEC3730 ASSIGNMENT 3
 * QUESTION1.H
 * JORDAN HAIGH AND EVAN GRESHAM
 *
 *
 * Class stores relevant methods that are used to build functionality for question 1
 *
 * */



void analyseCommands(uint8_t argNum, char *argStrings[]);
void helpDesk(uint8_t argNum, char *argStrings[]);
void analog(uint8_t argNum, char *argStrings[]);
void ls(uint8_t argNum, char *argStrings[]);
	void scan_files (char* path);

void cd(uint8_t argNum, char *argStrings[]);
	void moveForwardDirectory(char* argStrings[], char* previousDirectory);
	void moveBackwardDirectory(char* previousDirectory);

void mkdir(uint8_t argNum, char *argStrings[]);
void mkdir2(char* folderToMake);


void cp(uint8_t argNum, char *argStrings[]);

	int checkFileFolderExists(char* directoryOfInterest);
	void copyObjectToObject(char* source, char* destination);
	void fileToFile(char* source, char* destination);
	void fileToFolder(char* source, char* destination);
	//void folderToFolder(char* source, char* destination);

void rm(uint8_t argNum, char *argStrings[]);
void rm2(char* directoryToRemove);

void mkfil(int argNum, char* argStrings[]);
void mkfilForRecording(char* string);
void read(int argNum, char* argStrings[]);
void write(int argNum, char* argStrings[]);
void write2(char* fileToWriteTo, char* stringToWrite);







uint8_t checkForNumericArgument(uint8_t processingIntegerFlag,uint8_t argNum, char* argStrings[]);
uint8_t checkArgumentLength(uint8_t flag, uint8_t expectedWordCount, uint8_t argNum);




#endif

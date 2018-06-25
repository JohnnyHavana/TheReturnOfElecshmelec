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


//Hub for command list
void analyseCommands(uint8_t argNum, char *argStrings[]);
//Prints help messages
void helpDesk(uint8_t argNum, char *argStrings[]);
//Updates analog value for board
void analog(uint8_t argNum, char *argStrings[]);
//Lists contents of directory
void ls(uint8_t argNum, char *argStrings[]);
	//Main scanning method for ls
	void scan_files (char* path);

//Changes directory depending on argument
void cd(uint8_t argNum, char *argStrings[]);
	//Move forward a directory, can move forward multiple directories
	void moveForwardDirectory(char* argStrings[], char* previousDirectory);
	//Move backward a directory, can only move back once
	void moveBackwardDirectory(char* previousDirectory);

//Main mkdir method, makes a new directory if doesnt exist
void mkdir(uint8_t argNum, char *argStrings[]);
//Alternative mkdir, bypasses argc argv stuff
void mkdir2(char* folderToMake);

//Copy function - multiple things to check
void cp(uint8_t argNum, char *argStrings[]);
	//Boolean check to determine if file or folder exists
	int checkFileFolderExists(char* directoryOfInterest);
	//Main copying function - transferring bytes
	void copyObjectToObject(char* source, char* destination);
	//Copies file to file in same directory
	void fileToFile(char* source, char* destination);
	//Copies file to folder - folder can be many layers deep
	void fileToFolder(char* source, char* destination);

//Main remove function, can remove file or folder - folder must be empty
void rm(uint8_t argNum, char *argStrings[]);
// Alternative rm method - bypasses argc, argv
void rm2(char* directoryToRemove);

//Make file method - makes a file, not a folder
void mkfil(int argNum, char* argStrings[]);
//Make file alternative, bypasses argc argv
void mkfilForRecording(char* string);
//Reads a file - not a folder
void read(int argNum, char* argStrings[]);
//Writes to a file
void write(int argNum, char* argStrings[]);
//Alternative write method, KISS
void write2(char* fileToWriteTo, char* stringToWrite);







uint8_t checkForNumericArgument(uint8_t processingIntegerFlag,uint8_t argNum, char* argStrings[]);
uint8_t checkArgumentLength(uint8_t flag, uint8_t expectedWordCount, uint8_t argNum);




#endif

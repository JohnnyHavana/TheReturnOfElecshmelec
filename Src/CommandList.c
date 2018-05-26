
#include "CommandList.h"


//Here is your bible. Fucking use it.
//http://www.elm-chan.org/fsw/ff/00index_e.html

#define DEBUG "debug"
#define HELP "help"
#define ANALOG "analog"
#define LS "ls"
#define CD "cd"
#define MKDIR "mkdir"
#define CP "cp"
#define RM "rm"

#define MKFIL "mkfil"
#define READ "read"
#define WRITE "write"

#include "ff.h"
#include "ffconf.h"
void analyseCommands(uint8_t argNum, char *argStrings[])
{
	if(argNum == 0)
	{
		printf("No arguments. Seek help\n");
		return;
	}

	char* firstKeyword = argStrings[0];

	if(strcmp(firstKeyword, DEBUG) == 0)
	{
		debugMode(argNum, argStrings);
	}
	else if(strcmp(firstKeyword, HELP) == 0)
	{
		helpDesk(argNum, argStrings);
	}
	else if(strcmp(firstKeyword,ANALOG) == 0)
	{
		analog(argNum, argStrings);
	}
	else if(strcmp(firstKeyword,LS) == 0)
	{
		ls(argNum,argStrings);

	}
	else if(strcmp(firstKeyword, CD) == 0)
	{
		cd(argNum,argStrings);

	}
	else if(strcmp(firstKeyword, MKDIR) == 0)
	{
		mkdir(argNum,argStrings);

	}
	else if(strcmp(firstKeyword, CP) == 0)
	{
		cp(argNum,argStrings);

	}
	else if(strcmp(firstKeyword, RM) == 0)
	{
		rm(argNum,argStrings);
	}
	else if(strcmp(firstKeyword, MKFIL) == 0)
	{
		mkfil(argNum,argStrings);
	}
	else if(strcmp(firstKeyword, READ) == 0)
	{
		read(argNum,argStrings);
	}
	else if(strcmp(firstKeyword, WRITE) == 0)
	{
		write(argNum, argStrings);
	}
	else
		printf("Error. Invalid command. Seek help.\n");
}


/*
 * Help desk supplies all help information about math functions
 * If no arguments supplied, prints all information about functions
 * If one SPECIFIC math function supplied, prints information about THAT function
 * */
void helpDesk(uint8_t argNum, char* argStrings[])
{
	if(argNum < 2)
	{
		printf("debug <on|off> : Turn debug messages on or off.\n");
		printf("help [command] : Prints help information for a command\n");
		printf("analog [time] : Plot analog input for given period of time\n");
		printf("ls : List the contents of the current folder\n");
		printf("cd <dir> : Change folder to directory\n");
		printf("mkdir <dir> : Make directory <dir>\n");
		printf("cp <source> <destination> : Copies <source> to new file <destination>\n");
		printf("rm <file> : Deletes file\n");
		printf("mkfil <name> : Creates a new file\n");
		printf("read <file> : Reads the contents of a file\n");
		printf("write <file> <String> : Writes a string to the file\n");

	}
	else if(argNum == 2)
	{
		char * secondKeyword =  (argStrings)[1];
		if(strcmp(secondKeyword, DEBUG) == 0)
			printf("debug <on|off> : Turn debug messages on or off.\n");
		else if(strcmp(secondKeyword,HELP) == 0)
			printf("help [command] : Prints help information for a command\n");
		else if(strcmp(secondKeyword, ANALOG) == 0)
			printf("analog [time] : Plot analog input for given period of time\n");
		else if(strcmp(secondKeyword, LS) == 0)
			printf("ls : List the contents of the current folder\n");
		else if(strcmp(secondKeyword, CD) == 0)
			printf("cd <dir> : Change folder to directory\n");
		else if(strcmp(secondKeyword, MKDIR) == 0)
			printf("mkdir <dir> : Make directory <dir>\n");
		else if(strcmp(secondKeyword, CP) == 0)
			printf("cp <source> <destination> : Copies <source> to new file <destination>\n");
		else if(strcmp(secondKeyword, RM) == 0)
			printf("rm <file> : Deletes file\n");
		else if(strcmp(secondKeyword, MKFIL) == 0)
			printf("mkfil <name> : Creates a new file\n");
		else if(strcmp(secondKeyword, READ) == 0)
			printf("read <file> : Reads the contents of a file\n");
		else if(strcmp(secondKeyword, WRITE) == 0)
			printf("write <file> <String> : Writes a string to the file\n");
		else
			printf("Error. Unrecognised command. Seek help.\n");
	}
	else
		printf("Error. Unrecognised command. Seek help\n");
}

void analog(uint8_t argNum, char *argStrings[])
{
	printf("Found analog\n");

	if(argNum != 2)
	{
		printf("Error. Analog must take one argument\n");
		return;
	}

	if(checkForNumericArgument(1,argNum, argStrings) == 0)
	{
		printf("Error. Argument provided is not numeric\n");
		return;
	}
	//todo missing implementation


}



void ls(uint8_t argNum, char *argStrings[])
{
	printf("Found ls\n");
	if(argNum > 1)
	{
		printf("Error. Ls must not have any arguments\n");
		return;
	}


	scan_files(currentFilePath);

}

//Modified from http://www.elm-chan.org/fsw/ff/doc/readdir.html
void scan_files (char* path) /* Start node to be scanned (***also used as work area***) */
{
    FRESULT res;
    DIR dir;
    static FILINFO fno;


    res = f_opendir(&dir, path);                       /* Open the directory */
    if (res != FR_OK)
    {
    	safe_printf("ERROR: Directory could not be opened.\n");
    	return;
    }

    res = f_readdir(&dir, &fno);
	if(res != FR_OK)
	{
		safe_printf("ERROR: Could not read directory");
		f_closedir(&dir);
		return;
	}
	safe_printf("=================Current Directory=================\n");
	while(res == FR_OK)
	{
		if(fno.fname[0] == 0) //null
		{
			break;
		}

		safe_printf("%s",fno.fname);
		if(fno.fattrib == AM_DIR) //if folder
		{
			safe_printf("\t (Folder)\n");
		}
		else
		{
			safe_printf("\n");
		}

		res = f_readdir(&dir, &fno);
	}
	safe_printf("=================End of Directory=================\n");
	res = f_closedir(&dir);

}

void cd(uint8_t argNum, char *argStrings[])
{
	printf("Found cd\n");

	char previousDirectory[256];
	strcpy(previousDirectory, currentFilePath);



	if(argNum > 2)
	{
		safe_printf("Error. Cd must require at most one argument\n");
		return;
	}
	else if(argNum  == 2)
	{
		if(strcmp(argStrings[1],"..") == 0)
		{
			safe_printf("Moving backward directory..\n");
			moveBackwardDirectory(previousDirectory);

		}
		else
		{
			safe_printf("Moving forward directory..\n");
			moveForwardDirectory(argStrings,previousDirectory);
		}
	}
	else
	{
		//move to root
		strcpy(previousDirectory,"/");
		strcpy(currentFilePath,"/");

		FRESULT changingDirectory = f_chdir(currentFilePath);
		if(changingDirectory != FR_OK)
		{
			safe_printf("Error. Could not transfer back to root\n");
			strcpy(currentFilePath, previousDirectory);
		}
		else
		{
			safe_printf("Moved to Root\n");
		}
	}
}

void moveForwardDirectory(char* argStrings[], char* previousDirectory)
{

	char* directoryToMoveTo = argStrings[1];

	FILINFO fno;
	strcat(currentFilePath,"/");
	strcat(currentFilePath,directoryToMoveTo);
	FRESULT directoryResult = f_stat(currentFilePath ,&fno);


	FRESULT changingDirectory;

	switch(directoryResult)
	{
		case FR_OK:

			changingDirectory = f_chdir(currentFilePath);

			if(changingDirectory != FR_OK)
			{
				safe_printf("Something went wrong when changing directory.\n");
				strcpy(currentFilePath, previousDirectory);

				//currentFilePath = previousDirectory;
			}
			else
			{
				safe_printf("Changed directory to %s\n",currentFilePath);
			}
			break;

		case FR_NO_FILE:
		{
			safe_printf("Error. Directory does not exist\n");
			strcpy(currentFilePath, previousDirectory);

			break;

		}
		default:
		{
			safe_printf("Error. Something went wrong.\n");
			strcpy(currentFilePath, previousDirectory);

		}

	}
}

void moveBackwardDirectory(char *previousDirectory)
{
	if(strlen(currentFilePath) <= 1)
	{
		safe_printf("Cant go back from nothing dummy.\n");
		//dont do anything
		return;
	}
	else
	{
		strcpy(previousDirectory, currentFilePath);

		for(int i = strlen(currentFilePath); i>1 ;i--)
		{
			currentFilePath[i] = 0;

			if(currentFilePath[i-1] == '/')
			{
				currentFilePath[i-1] = 0;
				break;
			}
			else
				currentFilePath[i-1] = 0;

		}

		safe_printf("New filepath =>%s\n",currentFilePath);

		FRESULT changingDirectory = f_chdir(currentFilePath);
		if(changingDirectory != FR_OK)
		{
			safe_printf("Error. Could not transfer back a folder\n");
			strcpy(currentFilePath, previousDirectory);
		}
		else
		{
			safe_printf("Moved back a folder\n");
		}


	}
}

void mkdir(uint8_t argNum, char *argStrings[])
{
	safe_printf("Found mkdir\n");

	if(argNum != 2)
	{
		safe_printf("Error. Mkdir must require one argument\n");
		return;
	}

	char* directoryToMake = argStrings[1];

	FRESULT mkdirResult = f_mkdir(directoryToMake);
	if(mkdirResult)
	{
		safe_printf("Error occurred making directory.\n");
	}
	else
	{
		safe_printf("Created: %s\n", directoryToMake);
		//die(mkdirResult);
	}

}

void cp(uint8_t argNum, char *argStrings[])
{
	safe_printf("Found cp\n");

	if(argNum != 3)
	{
		safe_printf("Error. Cp must require two arguments\n");
		return;
	}

	char* source = argStrings[1];
	char* destination = argStrings[2];

	char* foundDotInSource = strstr(source, ".");
	char* foundDotInDestination = strstr(destination,".");
	if(foundDotInSource && foundDotInDestination)
	{
		fileToFile(source, destination);
	}
	else if(foundDotInSource && !foundDotInDestination)
	{
		//Should throw an error in the early stages,
		//todo if enough time at the end, implement mkdir inside here
		safe_printf("Error. Cannot copy a file to a folder.\n");

		//Copying a file to a folder
		//Make sure the source exists
		//Make sure the destination folder doesn't already exist
		//If the folder doesn't exist, make the folder
	}
	else if(!foundDotInSource && !foundDotInDestination)
	{
		//Making a copy of a folder
		//FOLDER->FOLDER


		folderToFolder(source, destination);


		//Make sure the source exists
		//Make sure the destionation folder doesnt already exist
		//if the destination folder doesnt exist, make the folder
	}
	else
	{
		safe_printf("Hey. Invalid Copying. Cannot copy a folder to a file????\n");
	}
}


int checkFileFolderExists(char* directoryOfInterest)
{

	FILINFO fno;
	FRESULT directoryResult = f_stat(directoryOfInterest ,&fno);
	switch(directoryResult)
	{
		case FR_OK:
		{
			return 1;
		}
		case FR_NO_FILE:
		{
			return 2;
		}
		default:
		{
			return 0;
		}
	}
}

void fileToFile(char* source, char* destination)
{
	//FILE->FILE
	//Make sure that they source exists
	char filePathPlusSource[256];
	for(int i = 0; i < 256;i++)
	{
		filePathPlusSource[i] = 0;
	}
	strcat(filePathPlusSource, currentFilePath);
	strcat(filePathPlusSource, source);

	int sourceExistenceCheck = checkFileFolderExists(filePathPlusSource);
	printf("filepathplussource =>%s\n",filePathPlusSource);
	if(sourceExistenceCheck != 1)
	{
		safe_printf("Error. Source File does not exist");
		return;
	}

	//Make sure that destination doesnt exist
	char filePathPlusDestination[256];
	for(int i = 0; i < 256;i++)
	{
		filePathPlusDestination[i] = 0;
	}
	strcat(filePathPlusDestination, currentFilePath);
	strcat(filePathPlusDestination, destination);

	int destinationExistenceCheck = checkFileFolderExists(filePathPlusDestination);
	if(destinationExistenceCheck == 0)
	{
		safe_printf("Error. File %s already exists. Remove before copying.\n", destination);
		return;
	}
	else
	{
		//Making a copy of a file
		copyObjectToObject(filePathPlusSource, filePathPlusDestination);
		return;
	}

}


void folderToFolder(char* source, char* destination)
{
	//FILE->FILE
	//Make sure that they source exists
	char filePathPlusSource[256];
	for(int i = 0; i < 256;i++)
	{
		filePathPlusSource[i] = 0;
	}
	strcat(filePathPlusSource, currentFilePath);
	strcat(filePathPlusSource, source);
	//strcat(filePathPlusSource,"/");

	int sourceExistenceCheck = checkFileFolderExists(filePathPlusSource);
	printf("filepathplussource =>%s\n",filePathPlusSource);
	if(sourceExistenceCheck != 1)
	{
		safe_printf("Error. Source folder does not exist");
		return;
	}

	//Make sure that destination doesnt exist
	char filePathPlusDestination[256];
	for(int i = 0; i < 256;i++)
	{
		filePathPlusDestination[i] = 0;
	}
	strcat(filePathPlusDestination, currentFilePath);
	strcat(filePathPlusDestination, destination);
	//strcat(filePathPlusDestination,"/");


	int destinationExistenceCheck = checkFileFolderExists(filePathPlusDestination);
	if(destinationExistenceCheck == 0)
	{
		safe_printf("Error. File %s already exists. Remove before copying.\n", destination);
		return;
	}
	else
	{
		//Making a copy of a file
		copyObjectToObject(filePathPlusSource, filePathPlusDestination);
		return;
	}

}



void copyObjectToObject(char* source, char* destination)
{
	//Modified from
	//http://elm-chan.org/fsw/ff/doc/open.html
	safe_printf("Inside copy obkect to object\n");

	FIL fsrc, fdst;      /* File objects */
	BYTE buffer[4096];   /* File copy buffer */
	FRESULT fr;
	UINT br, bw;         /* File read/write count */

	/* Open source file on the drive 1 */
	fr = f_open(&fsrc, source, FA_READ);
	if (fr)
	{
		safe_printf("Unable to open source object\n");
		return;
	}

	/* Create destination file on the drive 0 */
	fr = f_open(&fdst, destination, FA_WRITE | FA_CREATE_ALWAYS);
	if (fr)
	{
		safe_printf("Unable to open destination object\n");
		return;
	}

	/* Copy source to destination */
	for (;;) {
		fr = f_read(&fsrc, buffer, sizeof buffer, &br);  /* Read a chunk of source file */
		if (fr || br == 0) break; /* error or eof */
		fr = f_write(&fdst, buffer, br, &bw);            /* Write it to the destination file */
		if (fr || bw < br) break; /* error or disk full */
	}

	/* Close open files */
	f_close(&fsrc);
	f_close(&fdst);

}


void rm(uint8_t argNum, char *argStrings[])
{
	safe_printf("Found rm\n");

	if(argNum < 2 || argNum > 2)
	{
		safe_printf("Error. Rm must require one argument\n");
		return;
	}

	char* directoryToRemove = argStrings[1];

	FRESULT rmResult = f_unlink(directoryToRemove);
	if(rmResult)
	{
		safe_printf("Unable to remove file (May not exist)\n");
	}
	else
	{
		safe_printf("Deleted: %s\n",directoryToRemove);
	}
}


void mkfil(int argNum, char* argStrings[])
{
	if(argNum != 2)
	{
		safe_printf("Error. Invalid number of arguments.\n")
		return;
	}

	char* newFileName = argStrings[1];
	char* foundDot = strstr(newFileName,".");
	if(!foundDot)
	{
		safe_printf("Error. Seems you're trying to make a folder dummy\n");
		return;
	}

	char pathAndFileName[256];
	for(int i = 0; i < 256;i++)
	{
		pathAndFileName[i] = 0;
	}

	strcat(pathAndFileName, currentFilePath);
	strcat(pathAndFileName, "/");
	strcat(pathAndFileName, newFileName);

	FRESULT res;
	FIL newFile;

	// Open file There.txt
		if((res = f_open(&newFile, pathAndFileName, FA_CREATE_ALWAYS | FA_WRITE)) != FR_OK)
		{
			safe_printf("ERROR: Opening '%s'\n", pathAndFileName);
			return;
		}
		safe_printf("Task 1: Opened file '%s'\n", pathAndFileName);

		// Close file
		f_close(&newFile);

}


void read(int argNum, char* argStrings[])
{
	if(argNum != 2)
	{
		safe_printf("Error. Read must require a second argument\n");
		return;
	}

	FIL file;
	#define BUFF_SIZE 256
	uint8_t rtext[BUFF_SIZE];
	FRESULT res;
	uint32_t bytesread;


	char* fileToRead = argStrings[1];

	char pathPlusFile[256];
	for(int i = 0; i < 256; i++)
	{
		pathPlusFile[i] = 0;
	}

	strcat(pathPlusFile, currentFilePath);
	strcat(pathPlusFile, fileToRead);
	////todo add global and local check rather than global.
	int fileExistenceCheck = checkFileFolderExists(fileToRead);
	if(fileExistenceCheck != 1)
	{
		safe_printf("Error. The File does not exist\n");
		return;
	}

	// Open file Hello.txt
	if((res = f_open(&file, fileToRead, FA_READ)) != FR_OK)
	{
		safe_printf("ERROR: Opening '%s'\n", fileToRead);
		return;
	}
	safe_printf("Task 1: Opened file '%s'\n", fileToRead);

	// Read data from file
	if ((res = f_read(&file, rtext, BUFF_SIZE-1, &bytesread)) != FR_OK)
	{
		safe_printf("ERROR: Reading '%s'\n", fileToRead);
		f_close(&file);
		return;
	}
	rtext[bytesread] = '\0';
	safe_printf("Task 1: Read: '%s'\n", rtext);

	// Close file
	f_close(&file);
}

void write(int argNum, char* argStrings[])
{
	if(argNum < 3)
	{
		safe_printf("Error. Write must contain at least 2 additional arguments\n");
		return;
	}

	char* fileToWriteTo = argStrings[1];

	char pathPlusFile[256];
	for(int i = 0; i < 256; i++)
	{
		pathPlusFile[i] = 0;
	}

	strcat(pathPlusFile, currentFilePath);
	strcat(pathPlusFile, fileToWriteTo);
	////todo add global and local check rather than global.
	int fileExistenceCheck = checkFileFolderExists(fileToWriteTo);
	if(fileExistenceCheck != 1)
	{
		safe_printf("Error. The File does not exist\n");
		return;
	}

	int writeStringLength = 0;
	char stringToWrite[256];
	//blank out the string. otherwise corrupted shit at the beginning
	for(int i = 0; i < 256;i++)
	{
		stringToWrite[i] = 0;
	}

	//start concatenating arguments
	for(int i = 2; i < argNum;i++)
	{
		safe_printf("testing word %d\n",i);
		if(writeStringLength + (int)strlen(argStrings[i]) < 255)
		{
			strcat(stringToWrite, argStrings[i]);
			strcat(stringToWrite, " ");
			safe_printf("concatenated word %s\n",argStrings[i]);

		}
		else
			break;
	}

	strcat(stringToWrite, "\n");
	safe_printf("writing %s\n",stringToWrite);



	FIL file;
	FRESULT res;
	UINT byteswritten;

	// Open file There.txt
	if((res = f_open(&file, fileToWriteTo, 	FA_OPEN_APPEND | FA_WRITE)) != FR_OK)
	{
		safe_printf("ERROR: Opening '%s'\n", fileToWriteTo);
		return;
	}
	safe_printf("Task 1: Opened file '%s'\n", fileToWriteTo);

	// Write to file
	if ((res = f_write(&file, stringToWrite, strlen(stringToWrite), &byteswritten)) != FR_OK)
	{
		safe_printf("ERROR: Writing '%s'\n", fileToWriteTo);
		f_close(&file);
		return;
	}
	safe_printf("Task 1: Written: %d bytes\n", byteswritten);

	// Close file
	f_close(&file);
}

/*
 * Validity check used by mathematical functions. It will return true or false depending whether the argument is all
 * numerals or not. Also takes into account the positioning of the decimal point (decimal point cant be placed twice for same number)
 * */
uint8_t checkForNumericArgument(uint8_t processingIntegerFlag,uint8_t argNum, char* argStrings[])
{
	uint8_t foundDecimalPoint = 0;

	for(int i = 1; i < argNum; i++)
	{

		for(int j = 0; argStrings[i][j] != '\0'; j++) //check each letter in the word
		{
			if(argStrings[i][j] == '.')
			{ //searching for decimal point

				if(foundDecimalPoint == 0)
					foundDecimalPoint = 1;
				else
				{
					safe_printf("Error. Not a valid input\n");
					return 0;
				}
			}

			else if(!(argStrings[i][j] >= 48 && argStrings[i][j] <= 57) && !argStrings[i][j] == '-')
			{
				//if the number is not within 0-9 (non numeric)

				safe_printf("Error. Not a valid input\n");
				return 0;
			}

			else if(processingIntegerFlag == 1 && foundDecimalPoint == 1 && (argStrings[i][j] >= 48 && argStrings[i][j] <= 57)) //if a decimal point is found and numerals trail it, it must be a decimal
			{
				safe_printf("Error. Not a valid Input\n");
				return 0;
			}

		}
		//new word, reset decimal point
		foundDecimalPoint = 0;
	}

	return 1;
}


/*
 * Validity check used by mathematical functions. Depending on the flag and expected word count, it will
 * return 1 for true and 0 for false.
 * Add and mul can accept any number of arguments
 * Sub, div, and other functions require two arguments
 * */
uint8_t checkArgumentLength(uint8_t flag, uint8_t expectedWordCount, uint8_t argNum)
{
	if(argNum == 1)
		return 0;

	if(flag == 0) //used for addition and subtraction. N number of arguments supported
		return 1;
	else //flag must be 1. flag is used in the operations where a number of arguments is specified, i.e sub, div, sqrt, sbrt, mod, pow
	{
		if(argNum < expectedWordCount || argNum > expectedWordCount)
			return 0;
		else
			return 1;

	}
}


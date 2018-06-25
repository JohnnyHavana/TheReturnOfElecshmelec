#include "Question1.h"
#include "Question2.h"

//char **array_of_words;
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



#define ON "on"
#define OFF "off"




int analogValue = 10;
void debugMode(uint8_t argNum, char* argStrings[]);




/*
 * Allows for debug messages to be turned on or off
 * If no arguments supplied, it will print the current status of debug
 * If one argument supplied <on | off> it will toggle the current status
 * If more than one argument, seek help
 * */
void debugMode(uint8_t argNum, char* argStrings[])
{
	if(argNum < 2)
	{
		safe_printf("%sDEBUG%s: \t Debug status: %d\n", C_DEBUG,C_NORMAL, debugOn);
	}

	else if(argNum ==2)
	{

		char * secondKeyword =  (argStrings)[1];
		if(strcmp(secondKeyword, ON) == 0)
		{
			if(debugOn == 1)
			{
				safe_printf("%sSYSTEM%s: Debug is already on.\n", C_SYSTEM,C_NORMAL);
			}
			else
			{
				safe_printf("%sSYSTEM%s: \t Debug message will be displayed\n", C_SYSTEM,C_NORMAL);
				debugOn = 1;
			}
		}
		else if(strcmp(secondKeyword, OFF) == 0)
		{
			if(debugOn == 0)
			{
				safe_printf("%sSYSTEM%s: Debug is already off.\n", C_SYSTEM,C_NORMAL);
			}
			else
			{
				debugOn = 0;
				safe_printf("%sSYSTEM%s: \t Debug message will not be displayed\n", C_SYSTEM,C_NORMAL);
			}
		}
		else
		{
			safe_printf("%sERROR%s: \t Error. Not a valid input for debug keyword. Seek help.\n", C_ERROR,C_NORMAL);
		}
	}
	else
	{
		safe_printf("%sERROR%s: \t Error. Debug command must take zero or one argument. Seek help.\n", C_ERROR,C_NORMAL);
		return;
	}
}





void analyseCommands(uint8_t argNum, char *argStrings[])
{
	if(argNum == 0)
	{
		error_safe_printf("No arguments. Seek help\n");
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
		printf("%sError%s. Invalid command. Seek help.\n",C_ERROR,C_NORMAL);
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
		system_safe_printf("Help Commands:\n");
		safe_printf("debug <on|off> : Turn debug messages on or off.\n");
		safe_printf("help [command] : Prints help information for a command\n");
		safe_printf("analog [time] : Plot analog input for given period of time\n");
		safe_printf("ls : List the contents of the current folder\n");
		safe_printf("cd <dir> : Change folder to directory\n");
		safe_printf("mkdir <dir> : Make directory <dir>\n");
		safe_printf("cp <source> <destination> : Copies <source> to new file <destination>\n");
		safe_printf("rm <file> : Deletes file\n");
		safe_printf("mkfil <name> : Creates a new file\n");
		safe_printf("read <file> : Reads the contents of a file\n");
		safe_printf("write <file> <String> : Writes a string to the file\n");

	}
	else if(argNum == 2)
	{
		char * secondKeyword =  (argStrings)[1];
		if(strcmp(secondKeyword, DEBUG) == 0)
		{
			safe_printf("debug <on|off> : Turn debug messages on or off.\n");
		}
		else if(strcmp(secondKeyword,HELP) == 0)
		{
			safe_printf("help [command] : Prints help information for a command\n");
		}
		else if(strcmp(secondKeyword, ANALOG) == 0)
		{
			safe_printf("analog [time] : Plot analog input for given period of time\n");
		}
		else if(strcmp(secondKeyword, LS) == 0)
		{
			safe_printf("ls : List the contents of the current folder\n");
		}
		else if(strcmp(secondKeyword, CD) == 0)
		{
			safe_printf("cd <dir> : Change folder to directory\n");
		}
		else if(strcmp(secondKeyword, MKDIR) == 0)
		{
			safe_printf("mkdir <dir> : Make directory <dir>\n");
		}
		else if(strcmp(secondKeyword, CP) == 0)
		{
			safe_printf("cp <source> <destination> : Copies <source> to new file <destination>\n");
		}
		else if(strcmp(secondKeyword, RM) == 0)
		{
			safe_printf("rm <file> : Deletes file\n");
		}
		else if(strcmp(secondKeyword, MKFIL) == 0)
		{
			safe_printf("mkfil <name> : Creates a new file\n");
		}
		else if(strcmp(secondKeyword, READ) == 0)
		{
			safe_printf("read <file> : Reads the contents of a file\n");
		}
		else if(strcmp(secondKeyword, WRITE) == 0)
		{
			safe_printf("write <file> <String> : Writes a string to the file\n");
		}
		else
		{
			error_safe_printf("Command not found in list. Seek help.\n");
		}
	}
	else
	{
		error_safe_printf("Unrecognised command. Seek help\n");

	}
}



void analog(uint8_t argNum, char *argStrings[])
{
	//safe_printf("Found analog\n");

		if(argNum == 1)
		{
			system_safe_printf("Current Analog Value =>%d\n", analogValue);
			return;
		}
		if(argNum > 2)
		{
			error_safe_printf("Analog must take one argument\n");
			return;
		}

		if(checkForNumericArgument(1,argNum, argStrings) == 0)
		{
			error_safe_printf("Argument provided is not numeric OR not an integer\n");
			return;
		}

		if(!paused){
			error_safe_printf("Pulse rate monitor needs to be paused before an analog command\n");
			return;
		}



		analogValue = atoi(argStrings[1]);
//		system_safe_printf("Analog value has been updated to %d\n", analogValue);


		//need to update the speed at which the board is running
		//analog 10 - 10 seconds  = 500
		//analog 1 - 1 second = 50;
		//		speedValue = analogValue * 50;


//		BSP_LCD_SetFont(&Font8);
//		char newTimeValue[10];
//		sprintf(newTimeValue, "%ds", analogValue);
//		updateTimeSpan(newTimeValue);
		analogTimer = analogValue*1000;
		isAnaloging =1;

}



void ls(uint8_t argNum, char *argStrings[])
{
	if(argNum > 1)
	{
		error_safe_printf("Ls must not have any arguments\n");
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
    	error_safe_printf("Directory could not be opened.\n");
    	return;
    }

    res = f_readdir(&dir, &fno);
	if(res != FR_OK)
	{
		error_safe_printf("Could not read directory\n");
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
	char previousDirectory[256];
	strcpy(previousDirectory, currentFilePath);



	if(argNum > 2)
	{
		error_safe_printf("Cd must require at most one argument\n");
		return;
	}
	else if(argNum  == 2)
	{
		if(strcmp(argStrings[1],"..") == 0)
		{
			moveBackwardDirectory(previousDirectory);

		}
		else
		{
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
			error_safe_printf("Could not transfer back to root\n");
			strcpy(currentFilePath, previousDirectory);
		}
		else
		{
			if(debugOn == 1)
			{
				debug_safe_printf("Moved to root\n");
			}
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
				error_safe_printf("Something went wrong when changing directory.\n");
				strcpy(currentFilePath, previousDirectory);

				//currentFilePath = previousDirectory;
			}
			else
			{
				if(debugOn == 1)
				{
					debug_safe_printf("Changed directory to %s\n",currentFilePath);
				}
			}
			break;

		case FR_NO_FILE:
		{
			error_safe_printf("Directory does not exist\n");
			strcpy(currentFilePath, previousDirectory);

			break;

		}
		default:
		{
			error_safe_printf("Something went wrong.\n");
			strcpy(currentFilePath, previousDirectory);

		}

	}
}

void moveBackwardDirectory(char *previousDirectory)
{
	if(strlen(currentFilePath) <= 1)
	{
		error_safe_printf("Cant go back from nothing dummy.\n");
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

		if(debugOn == 1)
		{
			debug_safe_printf("New filepath =>%s\n",currentFilePath);
		}

		FRESULT changingDirectory = f_chdir(currentFilePath);
		if(changingDirectory != FR_OK)
		{
			error_safe_printf("Error. Could not transfer back a folder\n");
			strcpy(currentFilePath, previousDirectory);
		}
		else
		{
			if(debugOn == 1)
			{
				debug_safe_printf("Moved back a folder\n");
			}
		}


	}
}

void mkdir(uint8_t argNum, char *argStrings[])
{
	//safe_printf("Found mkdir\n");

	if(argNum != 2)
	{
		error_safe_printf("Mkdir must require one argument\n");
		return;
	}

	char* directoryToMake = argStrings[1];

	FRESULT mkdirResult = f_mkdir(directoryToMake);
	if(mkdirResult)
	{
		error_safe_printf("Error occurred making directory.\n");
	}
	else
	{
		if(debugOn == 1)
		{
			debug_safe_printf("Created: %s\n", directoryToMake);
			//die(mkdirResult);
		}

	}

}

void cp(uint8_t argNum, char *argStrings[])
{
	//safe_printf("Found cp\n");

	if(argNum != 3)
	{
		error_safe_printf("Cp must require two arguments\n");
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
		//Copying a file to a folder
		error_safe_printf("Cannot copy a file to a folder.\n");

	}
	else if(!foundDotInSource && !foundDotInDestination)
	{
		//Making a copy of a folder
		//FOLDER->FOLDER
		error_safe_printf("Cannot copy Folder to Folder\n");
	}
	else
	{
		error_safe_printf("Invalid Copying. Cannot copy a folder to a file????\n");
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
	strcat(filePathPlusSource, "/");
	strcat(filePathPlusSource, source);

	int sourceExistenceCheck = checkFileFolderExists(filePathPlusSource);

	//printf("filepathplussource =>%s\n",filePathPlusSource);

	if(sourceExistenceCheck != 1)
	{
		error_safe_printf("Source File does not exist\n");
		return;
	}

	//Make sure that destination doesnt exist
	char filePathPlusDestination[256];
	for(int i = 0; i < 256;i++)
	{
		filePathPlusDestination[i] = 0;
	}
	strcat(filePathPlusDestination, currentFilePath);
	strcat(filePathPlusDestination, "/");
	strcat(filePathPlusDestination, destination);

	int destinationExistenceCheck = checkFileFolderExists(filePathPlusDestination);
	if(destinationExistenceCheck == 0)
	{
		error_safe_printf("File %s already exists. Remove before copying.\n", destination);
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
	//safe_printf("Inside copy obkect to object\n");

	FIL fsrc, fdst;      /* File objects */
	BYTE buffer[4096];   /* File copy buffer */
	FRESULT fr;
	UINT br, bw;         /* File read/write count */

	/* Open source file on the drive 1 */
	fr = f_open(&fsrc, source, FA_READ);
	if (fr)
	{
		error_safe_printf("Unable to open source object\n");
		return;
	}

	/* Create destination file on the drive 0 */
	fr = f_open(&fdst, destination, FA_WRITE | FA_CREATE_ALWAYS);
	if (fr)
	{
		error_safe_printf("Unable to open destination object\n");
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
	//safe_printf("Found rm\n");
	if(argNum < 2 || argNum > 2)
	{
		error_safe_printf("Rm must require one argument\n");
		return;
	}

	char pathAndFileName[256];
	for(int i = 0; i < 256;i++)
	{
		pathAndFileName[i] = 0;
	}

	strcat(pathAndFileName, currentFilePath);
	strcat(pathAndFileName, "/");
	strcat(pathAndFileName, argStrings[1]);




    //char* directoryToRemove = argStrings[1];

    FRESULT rmResult = f_unlink(pathAndFileName);
	if(rmResult)
	{
        //check if we're trying to remove a folder instead
        strcat(pathAndFileName,"/");
        FRESULT rmResult = f_unlink(pathAndFileName);
        if(rmResult)
        {
            error_safe_printf("Unable to remove object (May not exist)\n");
        }
        else
        {
            system_safe_printf("Deleted: %s\n",pathAndFileName);
        }


		error_safe_printf("Unable to remove file (May not exist)\n");
	}
	else
	{
        system_safe_printf("Deleted: %s\n",pathAndFileName);
	}
}

void rm2(char *directoryToRemove)
{
	//safe_printf("Found rm\n");

	if(!directoryToRemove)
	{
		error_safe_printf("Missing char array for argument\n");
		return;
	}


	FRESULT rmResult = f_unlink(directoryToRemove);

	if(rmResult)
	{
		error_safe_printf("Unable to remove file (May not exist)\n");
	}
	else
	{
		if(debugOn == 1)
		{
			safe_printf("Deleted: %s\n",directoryToRemove);
		}
	}
}


void mkfil(int argNum, char* argStrings[])
{
	if(argNum != 2)
	{
		error_safe_printf("Invalid number of arguments.\n")
		return;
	}

	char* newFileName = argStrings[1];
	char* foundDot = strstr(newFileName,".");
	if(!foundDot)
	{
		error_safe_printf("Please include file type (You were trying to make a folder) fileName:%s\n", newFileName);
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
			error_safe_printf("Could not open '%s'\n", pathAndFileName);
			return;
		}
		if(debugOn == 1)
		{
			system_safe_printf("Created blank file'%s'\n", pathAndFileName);
		}
		// Close file
		f_close(&newFile);

}


void mkfilForRecording(char* string)
{
	char* foundDot = strstr(string,".");
	if(!foundDot)
	{
		error_safe_printf("Please include file type (You were trying to make a folder) fileName:%s\n", string);
		return;
	}



	FRESULT res;
	FIL newFile;

	// Open file There.txt
		if((res = f_open(&newFile, string, FA_CREATE_ALWAYS | FA_WRITE)) != FR_OK)
		{
			error_safe_printf("Could not open '%s'\n", string);
			return;
		}
		if(debugOn == 1)
		{
			system_safe_printf("Created blank file'%s'\n", string);
		}
		// Close file
		f_close(&newFile);

}



void read(int argNum, char* argStrings[])
{
	if(argNum != 2)
	{
		error_safe_printf("Read must require a second argument\n");
		return;
	}

	FIL file;
	#define BUFF_SIZE 256
	uint8_t rtext[BUFF_SIZE];
	FRESULT res;
	uint32_t bytesread;
	uint32_t totalBytesRead = 0;


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
		error_safe_printf("The File does not exist\n");
		return;
	}

	// Open file Hello.txt
	if((res = f_open(&file, fileToRead, FA_READ)) != FR_OK)
	{
		error_safe_printf("Opening '%s'\n", fileToRead);
		return;
	}
	system_safe_printf("Opened file '%s'\n", fileToRead);
	// Read data from file
	if ((res = f_read(&file, rtext, BUFF_SIZE-1, &bytesread)) != FR_OK)
	{
		error_safe_printf("Reading '%s'\n", fileToRead);
		f_close(&file);
		return;
	}
	//todo jordan - you will need to make sure to update the total bytes read such that you can stick a null terminator on the end (perhaps)
	totalBytesRead += bytesread;

	rtext[totalBytesRead] = '\0';
	system_safe_printf("Read:\n '%s'\n", rtext);

	// Close file
	f_close(&file);
}

void write(int argNum, char* argStrings[])
{
	if(argNum < 3)
	{
		error_safe_printf("Write must contain at least 2 additional arguments\n");
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
		error_safe_printf("File does not exist\n");
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
		//safe_printf("testing word %d\n",i);
		if(writeStringLength + (int)strlen(argStrings[i]) < 255)
		{
			strcat(stringToWrite, argStrings[i]);
			strcat(stringToWrite, " ");
			//safe_printf("concatenated word %s\n",argStrings[i]);

		}
		else
			break;
	}

	strcat(stringToWrite, "\n");
	//safe_printf("writing %s\n",stringToWrite);



	FIL file;
	FRESULT res;
	UINT byteswritten;

	// Open file There.txt
	if((res = f_open(&file, fileToWriteTo, 	FA_OPEN_APPEND | FA_WRITE)) != FR_OK)
	{
		error_safe_printf("Couldn't open'%s'\n", fileToWriteTo);
		return;
	}
	system_safe_printf("Opened file '%s'\n", fileToWriteTo);

	// Write to file
	if ((res = f_write(&file, stringToWrite, strlen(stringToWrite), &byteswritten)) != FR_OK)
	{
		safe_printf("ERROR: Could not write to '%s'\n", fileToWriteTo);
		f_close(&file);
		return;
	}
	safe_printf("Task 1: Written: %d bytes\n", byteswritten);

	// Close file
	f_close(&file);
}


void write2(char* fileToWriteTo, char* stringToWrite)
{
	//note  -- fileto write to includes the current directory and the file extension

	strcat(stringToWrite, ", ");
	//safe_printf("writing %s\n",stringToWrite);


	FIL file;
	FRESULT res;
	UINT byteswritten;

	// Open file There.txt
	if((res = f_open(&file, fileToWriteTo, 	FA_OPEN_APPEND | FA_WRITE)) != FR_OK)
	{
		error_safe_printf("Couldn't open'%s'\n", fileToWriteTo);
		return;
	}
	system_safe_printf("Opened file '%s'\n", fileToWriteTo);

	// Write to file
	if ((res = f_write(&file, stringToWrite, strlen(stringToWrite), &byteswritten)) != FR_OK)
	{
		safe_printf("ERROR: Could not write to '%s'\n", fileToWriteTo);
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
					error_safe_printf("Not a valid input\n");
					return 0;
				}
			}

			else if(!(argStrings[i][j] >= 48 && argStrings[i][j] <= 57) && !(argStrings[i][j] == '-'))
			{
				//if the number is not within 0-9 (non numeric)

				error_safe_printf("Not a valid input\n");
				return 0;
			}

			else if(processingIntegerFlag == 1 && foundDecimalPoint == 1 && (argStrings[i][j] >= 48 && argStrings[i][j] <= 57)) //if a decimal point is found and numerals trail it, it must be a decimal
			{
				error_safe_printf("Not a valid Input\n");
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





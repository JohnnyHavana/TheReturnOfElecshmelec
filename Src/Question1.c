#include "Question1.h"
#include "Question2.h"

/*
 *
 * ELEC3730 ASSIGNMENT 3
 * QUESTION1.C
 * JORDAN HAIGH AND EVAN GRESHAM
 *
 *
 * Class stores relevant methods that are used to build functionality for question 1
 *
 * */



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




/*
 * Hub to determine what command has been entered by the user
 * Error checks in place for no arguments, or invalid argument
 * */
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


/*
 * Plots "the analog input for the given period of time <time>"
 * Error checking to determine values
 * */
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
		clearBoard();



}


void clearBoard(){
	#define XOFF 10
	#define YOFF 10
	#define XSIZE 240
	#define YSIZE 160
	 BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	 BSP_LCD_FillRect(XOFF-1,YOFF-1,XSIZE+1,YSIZE+1);
	 BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	 BSP_LCD_DrawRect(XOFF-1,YOFF-1,XSIZE+1,YSIZE+1);
	 clear =1;

}


/*
 * Lists the contents of a current directory
 * */
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

    int numberOfFiles = 0;
    int numberOfFolders = 0;


    res = f_opendir(&dir, path);                       /* Open the directory */
    if (res != FR_OK) //if problem with opening directory
    {
    	error_safe_printf("Directory could not be opened.\n");
    	return;
    }

    res = f_readdir(&dir, &fno); //read directory and store its contents and information
	if(res != FR_OK)
	{
		error_safe_printf("Could not read directory\n");
		f_closedir(&dir);
		return;
	}
	safe_printf("=================Current Directory=================\n");
	while(res == FR_OK) //if good, keep reading
	{
		if(fno.fname[0] == 0) //null - reached end of reading directory
		{
			break;
		}

		numberOfFiles++;

		safe_printf("%s",fno.fname); //print the name of the file/folder found
		if(fno.fattrib == AM_DIR) //if folder
		{
			safe_printf("\t (Folder)\n"); //print extra info to make it known its a folder
			numberOfFiles--;
			numberOfFolders++;
		}
		else
		{
			safe_printf("\n");
		}


		res = f_readdir(&dir, &fno); //prime for next line
	}

	safe_printf("Files: %d\n", numberOfFiles);
	safe_printf("Folders: %d\n",numberOfFolders);
	safe_printf("=================End of Directory=================\n");
	res = f_closedir(&dir); //finished

}

/*
 * Change directory
 * if no arguments, go to root
 * If one argument
 * 		If argument is .. - go back a folder
 * 	    Else go forward folder
 * Else - error
 * */
void cd(uint8_t argNum, char *argStrings[])
{
	char previousDirectory[256]; //used when we cant go forward, so we revert back to this.
	strcpy(previousDirectory, currentFilePath);

	if(argNum > 2)
	{
		error_safe_printf("Cd must require at most one argument\n");
		return;
	}
	else if(argNum  == 2)
	{
		if(strcmp(argStrings[1],"..") == 0) //move back a folder
		{
			moveBackwardDirectory(previousDirectory);

		}
		else
		{
			//move forward a folder
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
			//successful
			if(debugOn == 1)
			{
				debug_safe_printf("Moved to root\n");
			}
		}
	}
}

/*
 * Move forward a directory.
 * Need to make sure that the directory actually exists
 * If it doesnt, we print an error message and return to the previous directory
 * */
void moveForwardDirectory(char* argStrings[], char* previousDirectory)
{

	char* directoryToMoveTo = argStrings[1];

	FILINFO fno;
	strcat(currentFilePath,"/");
	strcat(currentFilePath,directoryToMoveTo);
	FRESULT directoryResult = f_stat(currentFilePath ,&fno); //making sure it actually exists


	FRESULT changingDirectory; //Directory we want to change to

	switch(directoryResult)
	{
		case FR_OK: //All is well, we can change directory

			changingDirectory = f_chdir(currentFilePath);

			if(changingDirectory != FR_OK) //if there was an issue with this, revert to old directory
			{
				error_safe_printf("Something went wrong when changing directory.\n");
				strcpy(currentFilePath, previousDirectory);

				//currentFilePath = previousDirectory;
			}
			else
			{
				//successful change directory
				if(debugOn == 1)
				{
					debug_safe_printf("Changed directory to %s\n",currentFilePath);
				}
			}
			break;

		case FR_NO_FILE:
		{
			//directory doesnt exist
			error_safe_printf("Directory does not exist\n");
			strcpy(currentFilePath, previousDirectory);

			break;

		}
		default:
		{
			//something else went wrong, shouldnt be able to access this area anyways
			error_safe_printf("Something went wrong.\n");
			strcpy(currentFilePath, previousDirectory);

		}

	}
}

/*
 * Move backwards a directory
 * checks if we are already at the root or not - error message if we are
 * searches backwards from the end of the string to find the first forward slash, thats where we will move back to
 * */
void moveBackwardDirectory(char *previousDirectory)
{
	if(strlen(currentFilePath) <= 1)
	{
		error_safe_printf("Can't move back from root.\n");
		//dont do anything
		return;
	}
	else
	{
		strcpy(previousDirectory, currentFilePath);

		for(int i = strlen(currentFilePath); i>1 ;i--)
		{
			currentFilePath[i] = 0; //null terminate as we go along

			if(currentFilePath[i-1] == '/') //if next char across is a back slash, we have found our directory
			{
				currentFilePath[i-1] = 0;
				break; //finished
			}
			else
				currentFilePath[i-1] = 0;

		}

		//print new file path
		if(debugOn == 1)
		{
			debug_safe_printf("New filepath =>%s\n",currentFilePath);
		}

		//change the directory
		FRESULT changingDirectory = f_chdir(currentFilePath);
		if(changingDirectory != FR_OK)
		{
			//shouldnt get to this area since we know that it already exists
			//maybe if the sd card is removed
			error_safe_printf("Error. Could not transfer back a folder\n");
			strcpy(currentFilePath, previousDirectory);
		}
		else
		{
			//successful
			if(debugOn == 1)
			{
				debug_safe_printf("Moved back a folder\n");
			}
		}


	}
}

/*
 * Makes a new directory
 *	Ensures that there is only one argument and that the directory doesnt already exist
 * */
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
		//In the event that the directory already exists
		error_safe_printf("Error occurred making directory.\n");
	}
	else
	{
		//Successful
		if(debugOn == 1)
		{
			debug_safe_printf("Created: %s\n", directoryToMake);
			//die(mkdirResult);
		}

	}

}

/*
 * Alternative mkdir method
 * People calling this already have done the checks
 * */
void mkdir2(char* folderToMake)
{
	if(!folderToMake)
	{
		error_safe_printf("Folder to make is null\n");
		return;
	}


	FRESULT mkdirResult = f_mkdir(folderToMake);
	if(mkdirResult)
	{
		//In the event that the directory already exists
		error_safe_printf("Error occurred making directory.\n");
	}
	else
	{
		//Successful
		if(debugOn == 1)
		{
			debug_safe_printf("Created: %s\n", folderToMake);
			//die(mkdirResult);
		}

	}


}

/*
 * Copying file to file
 * Can only work on file to file, anything else is too hard and I would require more time
 * Makes sure that three arguments are requried
 * Checks that each extra argument includes a dot, meaning that they ARE files
 * */
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

	//Find substring dot in string
	char* foundDotInSource = strstr(source, ".");
	char* foundDotInDestination = strstr(destination,".");

	//If the char pointers are not null, we have found it
	if(foundDotInSource && foundDotInDestination)
	{
		fileToFile(source, destination);
	}
	else if(foundDotInSource && !foundDotInDestination)
	{
		//Copying a file to a folder
		fileToFolder(source, destination);

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

/*
 * Validity check to ensure that the file/folder exists
 *  1 = File does exist
 *  2 = File does not exist
 *  0 = Default (Shouldn't happen?)
 * */
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

/*
 * Copying file to file
 * Creates the appropriate file paths to write to
 *
 * */
void fileToFile(char* source, char* destination)
{
	//FILE->FILE
	//Make sure that they source exists
	//Creating the concatenation of the current file path and the source file
	char filePathPlusSource[256];
	for(int i = 0; i < 256;i++)
	{
		filePathPlusSource[i] = 0;
	}
	strcat(filePathPlusSource, currentFilePath);
	strcat(filePathPlusSource, "/");
	strcat(filePathPlusSource, source);

	//make sure it exists
	int sourceExistenceCheck = checkFileFolderExists(filePathPlusSource);

	//printf("filepathplussource =>%s\n",filePathPlusSource);

	if(sourceExistenceCheck != 1)
	{
		error_safe_printf("Source File does not exist\n");
		return;
	}

	//start concatenation for destination file
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
		//now we can start copying bytes from source to destination
		copyObjectToObject(filePathPlusSource, filePathPlusDestination);
		return;
	}

}

/*
 * Copies file to another folder
 * Makes sure that the file exists, the folder exists and if the destination file exists
 * */
void fileToFolder(char* sourceFile, char* destinationFolder)
{
	//concatenate path plus source file
	char filePathPlusSource[256];
	for(int i = 0; i < 256;i++)
	{
		filePathPlusSource[i] = 0;
	}
	strcat(filePathPlusSource,currentFilePath);
	strcat(filePathPlusSource,"/");
	strcat(filePathPlusSource, sourceFile);

	//Source is now concatenated
	//Determine source exists
	if(checkFileFolderExists(filePathPlusSource)!= 1)
	{
		error_safe_printf("File does not exist\n");
		return;
	}

	//Need to determine if destination folder exists

	//build concat string
	//set to nulls to initiate
	char filePathPlusDestination[256];
	for(int i = 0; i < 256; i++)
	{
		filePathPlusDestination[i] = 0;
	}

	strcat(filePathPlusDestination,currentFilePath);
	strcat(filePathPlusDestination, "/");
	strcat(filePathPlusDestination, destinationFolder);
	//strcat(filePathPlusDestination,"/");


	//use FILINFO to determine if directory exists
	FILINFO fno;
	FRESULT directoryResult = f_stat(filePathPlusDestination ,&fno);

	switch(directoryResult)
	{
		case FR_OK:
		{
			//directory does exist
			strcat(filePathPlusDestination, "/");
			strcat(filePathPlusDestination, sourceFile);
			int fileExistenceCheck = checkFileFolderExists(filePathPlusDestination);
			if(fileExistenceCheck == 1)
			{
				//file already exists in folder, remove before copying
				error_safe_printf("Destination file already exists, remove before copying\n");
				return;
			}
			else if(fileExistenceCheck == 2)
			{
				//doesnt exist, we can copy
				copyObjectToObject(filePathPlusSource, filePathPlusDestination);
			}
			else
			{
				error_safe_printf("Unexpected error. Could not complete operation - Line 769\n")
				return;
			}
			break;
		}
		case FR_NO_FILE:
		{
			//if it doesnt exist, make the directory
			mkdir2(filePathPlusDestination);
			//then we can do copy to folder
			strcat(filePathPlusDestination, "/");
			strcat(filePathPlusDestination, sourceFile);
			copyObjectToObject(filePathPlusSource, filePathPlusDestination);
			break;
		}

		default:
		{
			error_safe_printf("Unexpected error. Cannot complete operation - Line 879\n");
			return;
		}

	}

	system_safe_printf("Copying file to folder successful\n");

}



/*
 * Writes bytes from source to destination files
 * modified from 	//http://elm-chan.org/fsw/ff/doc/open.html
 *
 * */
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


/*
 * Remove function
 * Ensures that one file is being removed
 * Folders can be removed once they contain no files inside
 * Ensures that the file/folder does exist
 * */
void rm(uint8_t argNum, char *argStrings[])
{
	//safe_printf("Found rm\n");
	if(argNum < 2 || argNum > 2)
	{
		error_safe_printf("Rm must require one argument\n");
		return;
	}

	//start concatenation for file to be removed

	char pathAndFileName[256];
	for(int i = 0; i < 256;i++)
	{
		pathAndFileName[i] = 0;
	}

	strcat(pathAndFileName, currentFilePath);
	strcat(pathAndFileName, "/");
	strcat(pathAndFileName, argStrings[1]);

    //char* directoryToRemove = argStrings[1];

	//remove file
    FRESULT rmResult = f_unlink(pathAndFileName);
	if(rmResult) //successful for files
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

/*
 * Alternative remove method, doesnt deal with the argc,argv argumetns
 * */
void rm2(char *directoryToRemove)
{
	//safe_printf("Found rm\n");
	//people calling this method have already been through the checks. This can be error checked later
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


/*
 * Make file
 * Extra method made by us
 * Creates a file
 * */
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


/*
 * Alternative method for mkfilk
 * People calling this have already been through the process of error checks
 * */
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


/*
 * Extra method used to read file
 * Greatly useful when we are checking that the recording was working
 * */
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

	//start concatenation for fatfs methods
	char pathPlusFile[256];
	for(int i = 0; i < 256; i++)
	{
		pathPlusFile[i] = 0;
	}

	strcat(pathPlusFile, currentFilePath);
	strcat(pathPlusFile, fileToRead);

	//make sure this exists before we start reading junk
	int fileExistenceCheck = checkFileFolderExists(fileToRead);
	if(fileExistenceCheck != 1)
	{
		error_safe_printf("The File does not exist\n");
		return;
	}

	// Open file Hello.txt
	//Now we can start reading the file
	//buff ize is set to 256, though should not be that. it shouldbe reading the entire thing..
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

	totalBytesRead += bytesread;

	rtext[totalBytesRead] = '\0';
	system_safe_printf("Read:\n '%s'\n", rtext);

	// Close file
	f_close(&file);
}

/*
 * Extra function developed by us to write N arguments to a file
 * useful when determining if a file can store values
 * error checks to determine all is well
 * */
void write(int argNum, char* argStrings[])
{
	if(argNum < 3)
	{
		error_safe_printf("Write must contain at least 2 additional arguments\n");
		return;
	}

	char* fileToWriteTo = argStrings[1];


	//concatenation to build file path
	char pathPlusFile[256];
	for(int i = 0; i < 256; i++)
	{
		pathPlusFile[i] = 0;
	}

	strcat(pathPlusFile, currentFilePath);
	strcat(pathPlusFile, fileToWriteTo);

	//make sure the file exists
	int fileExistenceCheck = checkFileFolderExists(fileToWriteTo);
	if(fileExistenceCheck != 1)
	{
		error_safe_printf("File does not exist\n");
		return;
	}

	int writeStringLength = 0;
	char stringToWrite[256];
	//blank out the string. otherwise corrupted values at the beginning
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


/*
 * Secondary write method
 * Removes the need for multiple args. just straight file to write to and string to write.
 **/
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





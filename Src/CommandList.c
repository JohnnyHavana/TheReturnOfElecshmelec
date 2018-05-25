
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
		//Making a copy of a file
		//Make sure that they source exists
		//Make sure that destination doesnt exist
	}
	else if(foundDotInSource && !foundDotInDestination)
	{
		//Should throw an error in the early stages, if enough time at the end, implement mkdir inside here


		//Copying a file to a folder
		//Make sure the source exists
		//Make sure the destination folder doesn't already exist
		//If the folder doesn't exist, make the folder
	}
	else if(!foundDotInSource && !foundDotInDestination)
	{
		//Making a copy of a folder
		//Make sure the source exists
		//Make sure the destionation folder doesnt already exist
		//if the destination folder doesnt exist, make the folder
	}
	else
	{
		safe_printf("Hey. Invalid Copying. Cannot copy a folder to a file????\n");
	}






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


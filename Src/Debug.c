#include "Debug.h"

uint8_t debugOn = 1;


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
		printf("%sDEBUG%s: \t Debug status: %d\n", C_DEBUG,C_NORMAL, debugOn);
	}
	else if(argNum > 2)
	{
		printf("%sERROR%s: \t Error. Debug command must take zero or one argument. Seek help.\n", C_ERROR,C_NORMAL);
		return;
	}
	else
	{
		char * secondKeyword =  (argStrings)[1];
		if(secondKeyword[0] == 'o' && secondKeyword[1] == 'n' && secondKeyword[2] == '\0')
		{
			if(debugOn == 1)
				printf("%sSYSTEM%s: \t Debug is already on.\n", C_SYSTEM,C_NORMAL);
			else
			{
				debugOn = 1;
				printf("%sSYSTEM%s: \t Debug message will be displayed\n", C_SYSTEM,C_NORMAL);
			}
		}
		else if(secondKeyword[0] == 'o' && secondKeyword[1] == 'f' && secondKeyword[2] == 'f' && secondKeyword[3] == '\0')
		{
			if(debugOn == 0)
				printf("%sSYSTEM%s: \t Debug is already off.\n", C_SYSTEM,C_NORMAL);
			else
			{
				debugOn = 0;
				printf("%sSYSTEM%s: \t Debug message will not be displayed", C_SYSTEM,C_NORMAL);
			}
		}
		else
			printf("%sERROR%s: \t Error. Not a valid input for debug keyword. Seek help.", C_ERROR,C_NORMAL);
	}
}

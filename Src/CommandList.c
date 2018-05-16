#include "CommandList.h"
#include "Debug.h"
#include <string.h>


#define DEBUG "debug"
#define HELP "help"
#define ANALOG "analog"
#define LS "ls"
#define CD "cd"
#define MKDIR "mkdir"
#define CP "cp"
#define RM "rm"

void analyseCommands(int argNum, char* argStrings[])
{
	if(argNum == 0)
	{
		printf("No arguments. Seek help\n");
		return;
	}

	char* firstKeyword = argStrings[0];

	if(strcmp(firstKeyword, DEBUG) == 0)
	{
		printf("Found debug\n");
		debugMode(argNum, argStrings);
	}
	else if(strcmp(firstKeyword, HELP) == 0)
	{
		printf("Found help\n");

	}
	else if(strcmp(firstKeyword,ANALOG) == 0)
	{
		printf("Found analog\n");

	}
	else if(strcmp(firstKeyword,LS) == 0)
	{
		printf("Found ls\n");

	}
	else if(strcmp(firstKeyword, CD) == 0)
	{
		printf("Found cd\n");

	}
	else if(strcmp(firstKeyword, MKDIR) == 0)
	{
		printf("Found mkdir\n");

	}
	else if(strcmp(firstKeyword, CP) == 0)
	{
		printf("Found cp\n");

	}
	else if(strcmp(firstKeyword, RM) == 0)
	{
		printf("Found rm\n");

	}
	else
		printf("Error. Invalid command. Seek help.\n");

}

void helpDesk(int argNum, char* argStrings[])
{
	}

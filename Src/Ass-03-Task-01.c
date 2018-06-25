//     $Date: 2018-05-22 06:24:02 +1000 (Tue, 22 May 2018) $
// $Revision: 1330 $
//   $Author: Peter $
#include "Question1.h"
#include "Ass-03.h"
#include "Button.h"

// This is the console task. Can use your code from the previous assignment
// and expand.
//
// The example code is very basic, showing access to the SD card. Note that
// if the SD card is access from both this task and the pulse rate monitor
// task, a MUTEX will be required.
//
// *** MAKE UPDATES TO THE CODE AS REQUIRED ***
//


FIL MyFile;
FIL MyFile2, MyFile3;
FRESULT Status;

int length;
char newString[100];
int stringIndex = 0;
int wordCount = 0;
uint8_t buildInputStringFirstTime;
char **array_of_words;
uint8_t debugOn = 1;
uint8_t paused = 0;
uint8_t record = 0;
uint8_t globalSaveNo = 1;
uint8_t loading = 0;
uint8_t loadingBufferNo = 0;
uint8_t bufferCounter = 0;
char saveChar = '1';

void buildInputString2(uint8_t c);
void parseInputString();
void releaseAndFreeBuiltStrings();
void printArrayOfWords();
int string_parser(char *inp, char **array_of_words_p[]);

void Ass_03_Task_01(void const * argument)
{

  uint32_t loop=0;
//  uint8_t ts[100];
//  uint16_t i;
//  Coordinate display;
  char c;

  safe_printf("Hello from Task 1 - Console (serial input)\n");
  safe_printf("INFO: Initialise LCD and TP first...\n");

  // STEPIEN: Initialize and turn on LCD and calibrate the touch panel
  BSP_LCD_Init();
  BSP_LCD_DisplayOn();
  BSP_TP_Init();
  //
  // Signal other tasks to start
  osSignalSet(myTask02Handle, 1);
  osSignalSet(myTask03Handle, 1);
  osSignalSet(myTask04Handle, 1);

  // Display welcome message
  osMutexWait(myMutex01Handle, osWaitForever);
  BSP_LCD_Clear(LCD_COLOR_WHITE);
  BSP_LCD_SetFont(&Font8);
  BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
  //BSP_LCD_DisplayStringAt(5, 5, (uint8_t*)"ELEC3730 Assignment 3 (v03 $Rev: 1330 $)",LEFT_MODE);
  //BSP_LCD_DisplayStringAt(5,20, (uint8_t*)"This demonstration code can be used",LEFT_MODE);
  //BSP_LCD_DisplayStringAt(5,35, (uint8_t*)"as a starting point for the assignment.",LEFT_MODE);
  for(int i = 0; i< 9 ;i++)
  {
	  showButton(buttons[i]);
  }

  BSP_LCD_SetFont(&Font8);
  BSP_LCD_DisplayStringAt(10, 172, "0s", LEFT_MODE);
  BSP_LCD_DisplayStringAt(235, 172, "10s", LEFT_MODE);

  osMutexRelease(myMutex01Handle);

  currentFilePath[0] = '/';


  int consoleIndex = 0;
  int firstFlag = 1;
  fflush(stdout);
  while (1)
  {
	  if(firstFlag == 1)
	  {
		  firstFlag = 0;
		  safe_printf("%s>",currentFilePath);
		  fflush(stdout);
	  }
	  //HAL_GPIO_TogglePin(GPIOD, LD3_Pin);
	  c = getchar();
	  while((c != '\r' && c != '\n'))
	  {
		  if((c == 8 || c == 127) && consoleIndex == 0){}
		  else if((c == 8 || c == 127) && consoleIndex > 0)
		  {
			  consoleIndex--;
			  safe_printf("%c",c);
			  		  fflush(stdout);
			  		  buildInputString2(c);
		  }
		  else
		  {
			  consoleIndex++;
			  safe_printf("%c",c);
			  		  fflush(stdout);
			  		  buildInputString2(c);
		  }


		  c = getchar();
	  }

	  consoleIndex = 0;
	  firstFlag = 1;
	  safe_printf("\n");

	  parseInputString();
	  analyseCommands(wordCount, array_of_words);
	  releaseAndFreeBuiltStrings();

	  //safe_printf("%s>",currentFilePath);
	  fflush(stdout);




      loop++;

      //myReadFile();
      //myWriteFile();
  }

}

/*
 * Builds input string from command line
 * gets char by char and keeps reallocating till finished with input string
 * Once enter is hit, it will begin to parse the string into keywords and begin analysing
 * */
void buildInputString2(uint8_t c)
{
	newString[stringIndex] = c;

	stringIndex++;
	if(stringIndex == 100)
	{
		safe_printf("%sSYSTEM%s - Cannot create an input of anything longer than 100. Continuing...\n", C_SYSTEM,C_NORMAL);
		parseInputString();
	}
}

void parseInputString()
{
	newString[stringIndex] = '\0';

	wordCount = string_parser(newString, &array_of_words);
	if(debugOn == 1) printArrayOfWords();



}

void releaseAndFreeBuiltStrings()
{
	free(array_of_words);
	stringIndex = 0;
	for(int i = 0; newString[i] != '\0'; i++)
		newString[i] = ' ';
}

/*
 * If the program has found more than 1 word, print out each word found
 * */
void printArrayOfWords()
{

	if (wordCount != 0) {
		printf("%sDEBUG%s: \t count = %d\n", C_DEBUG,C_NORMAL,wordCount);
		for (int j=0;j<wordCount;j++) {
		  printf("%sDEBUG%s: \t Word(%d): '%s'\n", C_DEBUG, C_NORMAL, j+1, (array_of_words)[j]);
		}
	  }
	else
		printf("%sDEBUG%s: \t No words found\n", C_DEBUG,C_NORMAL);
}

/*
 * String parser from Assignment 2
 * Same as before, goes through string and determines new string without backspaces
 * Loops to determine number of words, number of characters in each word
 * Allocates accordingly
 * */
int string_parser(char *inp, char **array_of_words_p[])
{
	/**********************************SETUP**********************************/

	int numberOfWords = 0;
	int currentWordLength = 0;

	//If input is an empty string, returns straight away
	if(inp[0] == '\0')
		return 0;

	int lengthOfInput = 1; //start from 1 for null terminator
	for(int i = 0; inp[i] != '\0';i++)
		lengthOfInput++;

	//Allocate memory, take into account backspaces for now
	char* convertedInput = (char*)malloc((size_t)lengthOfInput * sizeof(char)); //null terminator

	/**********************************REMOVING BACKSPACES**********************************/
	int reader = 0; //Reading inp variable
	int writer = 0; //Writing to converted Input
	while(inp[reader] != '\0') {
		if(inp[reader] == 127 || inp[reader] == 8) { //backspace char or delete char
			if(writer > 0) //taken into account so the writer isn't being subtracted to a negative index
				writer--;
		}
		else {
			convertedInput[writer] = inp[reader]; //store char from reader into writer
			writer++;
		}
		reader++; //always incrementing writer
	}
	convertedInput[writer] = '\0'; //add null terminator


	/**********************************FIND NUMBER OF WORDS**********************************/
	for(int i = 0; convertedInput[i] != '\0'; i++) { //Iterate until end of the input string
		if(convertedInput[i] != ' ') {
			currentWordLength++;

			//Found a valid character
			if(convertedInput[i+1] == '\0') { //If the next char is the end of the file
				//This gets around the edge case of the for loop stopping when it reaches '\0'
				if(currentWordLength > 0)
					numberOfWords++;
				currentWordLength = 0; //Reset
				continue;
			}

		}
		else {
			//Invalid Character
			if(convertedInput[i-1] == ' ' || convertedInput[i-1] == 127 || convertedInput[i-1] == 8)
				continue;
			else {
				//word is finished
				if(currentWordLength > 0)
					numberOfWords++;
				currentWordLength = 0;
			}
		}
	}

	//allocate single char pointers for number of words
	(*array_of_words_p) = (char**)malloc(sizeof(char*) * (size_t)numberOfWords);


	/**********************************FIND NUMBER OF WORDS**********************************/
	//Reset variables
	currentWordLength = 0;
	int wordIndex = 0; //Used in array indexes
	for(int i = 0; convertedInput[i] != '\0'; i++) {
		if(convertedInput[i] != ' ') { 	//not a space - valid character
			currentWordLength++;

			if(convertedInput[i+1] == '\0' && currentWordLength > 0) {
				//next character is the end, it would not pick up the end of the word
				(*array_of_words_p)[wordIndex] = (char*)malloc(sizeof(char) * (size_t)(currentWordLength + 1)); //Plus 1 is for null terminator
				currentWordLength = 0;
			}
		}
		else {
			//Invalid Character
			if(convertedInput[i-1] == ' ' || convertedInput[i-1] == 127 || convertedInput[i-1] == 8)
				continue;
			else {
				//End of word
				(*array_of_words_p)[wordIndex] = (char*)malloc(sizeof(char) * (size_t)(currentWordLength)+1); //Plus 1 is for null terminator
				wordIndex++;
				currentWordLength = 0;
			}
		}
	}

	/**********************************FIND NUMBER OF LETTERS IN EACH WORD**********************************/
	currentWordLength = 0;
	wordIndex = 0;
	int letterIndex = 0;

	for(int i = 0; convertedInput[i] != '\0'; i++) {
		if(convertedInput[i] != ' ') {
			//valid character
			(*array_of_words_p)[wordIndex][letterIndex] = convertedInput[i];

			letterIndex++;
			if(convertedInput[i+1] == '\0') { //End of string
				(*array_of_words_p)[wordIndex][letterIndex] = '\0';
				wordIndex++;
				letterIndex = 0;
			}
		}
		else {
			//Invalid Character
			if(convertedInput[i-1] == ' ' || convertedInput[i-1] == 127 || convertedInput[i-1] == 8)
				continue;
			else
			{
				//reached end of word
				(*array_of_words_p)[wordIndex][letterIndex] = '\0';
				wordIndex++;
				letterIndex = 0;
			}
		}
	}

	//free the converted input as we do not need it anymore
	free(convertedInput);

	return numberOfWords;
}


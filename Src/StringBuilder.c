#include "Stringbuilder.h"
#include "Debug.h"
#include <malloc.h>
#include <stdio.h>
char **array_of_words;

//int length = 10;
int stringIndex = 0;
int wordCount = 0;
//uint8_t buildInputStringFirstTime = 1;


///*
// * Builds input string from command line
// * gets char by char and keeps reallocating till finished with input string
// * Once enter is hit, it will begin to parse the string into keywords and begin analysing
// * */
//void buildInputString(uint8_t c){
//	if(buildInputStringFirstTime == 1)	  {
//	  newString = (char*)malloc(sizeof(char*) * length); //start of string. will have reallocation of memory if string is longer
//	  buildInputStringFirstTime = 0; //now not the first run through
//	  if(c == '\0' || c == 10) {
//		  newString[stringIndex] = '\0';
//
//		  wordCount = string_parser(newString, &array_of_words);
//
//		  //analyseKeywords(wordCount, array_of_words);
//		  freeStrings();
//
//		  buildInputStringFirstTime = 1; //reset
//		  length = 10;
//	  }
//	  else{
//		  newString[stringIndex] = c;
//		  stringIndex++;
//
//	  }
//
//	}
//	else{
//		newString = (char*)realloc(newString, sizeof(newString)+1);
//
//		if(c == '\0' || c == 10){ //if enter
//		  newString[stringIndex] = '\0'; //null terminate string
//		  //begin parse
//		  wordCount = string_parser(newString, &array_of_words);
//		  if(debugOn == 1) printArrayOfWords();
//		  //begin analysis of keywords
//		  //analyseKeywords(wordCount, array_of_words);
//		  freeStrings();
//
//
//		  buildInputStringFirstTime = 1; //reset
//		  stringIndex = 0; //reset
//
//		}
//		else{
//		  newString[stringIndex] = c; //keep appending
//		  stringIndex++;
//		  if(stringIndex == length) //if string length is maxed out
//		  {
//			  length *=2; //allocate more memory
//			  newString = (char*)realloc(newString,sizeof(char*) * length);
//		  }
//		}
//	}
//}

void buildInputString2(uint8_t c)
{
	if(c == '\n' || c == 10 || c == '\0' || c == '\r')
		parseInputString();
	else
	{
		newString[stringIndex] = c;

		stringIndex++;
		if(stringIndex == 100)
		{
			printf("%sSYSTEM%s - Cannot create an input of anything longer than 100. Continuing...\n", C_SYSTEM,C_NORMAL);
			parseInputString();
		}
	}


}

void parseInputString()
{
	newString[stringIndex] = '\0';

	printf("yes bitch you made it\n");

	wordCount = string_parser(newString, &array_of_words);
	if(debugOn == 1) printArrayOfWords();

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
 * Used to free global char arrays - newString(created from newString), array_of_words
 * */
void freeStrings()
{
	//free(newString);
	//free(array_of_words);
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



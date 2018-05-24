#ifndef STRINGBUILDER_H_
#define STRINGBUILDER_H_


#include <stdint.h>

int length;
char newString[100];
int stringIndex;
int wordCount;
uint8_t buildInputStringFirstTime;
char **array_of_words;



void buildInputString2(uint8_t c);
void parseInputString();
void releaseAndFreeBuiltStrings();
void printArrayOfWords();
void freeStrings();
int string_parser(char *inp, char **array_of_words_p[]);


#endif

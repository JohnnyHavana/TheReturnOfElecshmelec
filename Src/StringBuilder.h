#include <stdint.h>

int length;
char* newString;
int stringIndex;
int wordCount;
uint8_t buildInputStringFirstTime;


void buildInputString(uint8_t c);
void printArrayOfWords();
void freeStrings();
int string_parser(char *inp, char **array_of_words_p[]);



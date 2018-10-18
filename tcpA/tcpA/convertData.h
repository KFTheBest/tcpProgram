#include <stdio.h>
#include <stdbool.h>

const short TYPE_SIZE = 1;
int getType(FILE*);
bool isEndofLine(unsigned);
void readFile(const char*);
int numsReadIn(FILE*);
int translateZero(FILE*);
int translateOne(FILE*);
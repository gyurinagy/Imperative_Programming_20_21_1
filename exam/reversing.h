#ifndef REVERSING_H
#define REVERSING_H

#include "stdio.h"

#define INITCAP 8
#define BUFSIZE 1024

char** read(FILE* fp,char** lines, int* lSize);

void write(char** lines,int lSize);

void reverse(FILE* fp);

#endif


#include<stdlib.h>
#include<stdio.h>

void *createArray(int n,  int dataTypeSize);
int getArraySize(void *array);
void freeArray(void* array);
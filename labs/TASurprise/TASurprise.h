#include <stdio.h>
#include <stdlib.h>

int descendingBinarySearch(int *array, int element);
int isSortedDescending(int *array);
int ascendingBinarySearch(int *array, int element);
int isSortedAscending(int *array);

// Starter Code

void * createArray(size_t elementSize, int numElements);
int getSize(int *array);
void freeArray(void *array);

//Lab10 Code
int linearSearch(int *array, int element);
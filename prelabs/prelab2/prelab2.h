#include<stdio.h>
#include<stdlib.h>
/* Allocate and return a float array containing values read from a file
    The first entry int he file will be an integer specifying how many floats will follow
    fptr is the file, length lets the caller know how many elements are in the resultant array */
float* readFloatFileIntoArray(FILE *fptr, int *length);
/* Free the array and set the array pointer to NULL so the user doesn't accidentally
    reference freed memory */
void freeFloatArray(float **array);
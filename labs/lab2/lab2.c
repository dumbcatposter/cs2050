/*******************************
 * Name: Jacob Groves
 * Course: CS2050
 * Lab: Lab 2
 * Date: February 4, 2022
 * Semester: SS2022
 * Pawprint: JSGGBG
 * ******************************/
#include "lab2.h"

// Takes a file pointer and an int pointer, uses the first int in the file for the size of the array
int * createIntArrayFromFile(FILE *file, int *size)
{
    // Check if we were passed any NULL pointers
    if(NULL == file)
    {
        *size = -1;
        fprintf(stderr, "File pointer is null!\n");
        return NULL;
    }
    if(NULL == size)
    {
        fprintf(stderr, "size pointer is null!\n");
        return NULL;
    }

    //Retrieve the size and malloc the array
    fscanf(file, "%d", size);
    int *returnArray = malloc(*size * sizeof(int));

    //Check if malloc failed
    if(NULL == returnArray)
    {
        fprintf(stderr,"Malloc failed!\n");
        return NULL;
    }

    //Scan ints into the array and return it
    for(int i=0; i<*size; i++)
    {
        fscanf(file,"%d", returnArray+i);
    }
    return returnArray;
}

//Stores the address of the last instance of a given element in result
//Returns 0/1 on success/failure
int lastAddressOf(int *array, int size, int **result, int element)
{
    //Checking inputs
    if(NULL == array)
    {
        fprintf(stderr, "array pointer is NULL!\n");
        return 1;
    }
    if(NULL == result)
    {
        fprintf(stderr, "result pointer is NULL!\n");
    }
    if(size < 1)
    {
        fprintf(stderr, "Invalid size!\n");
    }

    int flagSuccess=1; // If nothing is found, this will stay one
    for(int i = 0; i < size; i++)
    {
        if( element == *(array+i))
        {
            //We found something! Set the flag to success
            //Because this moves through the entire array, this result pointer will get updated again if a later result is found
            flagSuccess=0;
            *result = array+i;
        }
    }
    return flagSuccess;
}

//Takes an array pointer, and frees the memory allocated to it.
void freeArray(int *array)
{
    free(array); // Will do nothing if passed a NULL pointer
}

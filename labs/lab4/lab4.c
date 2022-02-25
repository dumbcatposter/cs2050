#include "lab4.h"

//Create an array of integers with size <size>
//Store the size before the array
int * createIntArray(size_t size)
{
    //Check that the size makes sense
    if(size<0) 
    {
        fprintf(stderr, "Invalid array size!\n");
        return NULL;
    }
    //Create an array of <size> ints, check if malloc was successful
    size_t *returnArray = malloc(size*sizeof(int) + sizeof(size_t));
    if(returnArray == NULL)
    {
        fprintf(stderr, "Out of memory!\n");
        return NULL;
    }
    //Plug in the size, move 1 forward, cast to int * and return
    *returnArray = size;
    returnArray++;
    return (int *) returnArray;
}
//Return the size of an array <array> created by createIntArray
//Returns 0 in case of error, or if you have an array with size 0 for some reason
size_t getSize(int *array)
{
    if(NULL == array) return 0;
    //Move back 1 size_t and return it 
    size_t* returnArray = (size_t*) array - 1;
    return returnArray[0];
}
//Print the contents of an int array <array> on one line, then print a newline
//Prints an error message on error
void printArray(int *array)
{
    //Get the size, and print an error if the array is unprintable because size is 0
    size_t size = getSize(array);
    if(0==size)
    {
        printf("Array passed to printArray is size 0!\n");
        return;
    }
    //Print a { to indicate start of the array, print the contents of the array, then } to signify the end, and a newline
    printf("{ ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
    printf("}\n");
}
//Return the sum of array <array>'s  odd indices
//Returns -1 on error, or if the sum is actually -1
int sumOddIndices(int *array)
{
    if(NULL==array)
    {
        printf("Array passed to sumOddIndices is NULL!\n");
        return -1;
    }
    //Get the size, and print an error if the array is unsummable because size is 0
    size_t size = getSize(array);
    if(0==size)
    {
        printf("Array passed to sumOddIndices is size 0!\n");
        return -1;
    }
    int sum = 0;
    for(int i = 0; i <size; i++)
    {
        //Check if the index is odd, and add it to the sum if it is
        if((i%2)==1)
        {
            sum += array[i];
        }
    }
    return sum;
}
// Free an array <array> created by createIntArray
void freeArray(int *array)
{
    size_t *head = (size_t*) array - 1;
    free(head);
}

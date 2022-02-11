#include "lab3.h"

// Returns a pointer to the middle of an array with size <size>
// Returns NULL if size is even (there is no middle)
int * createCenteredArray(int size)
{
    //Check that the size is valid and if so create the array
    if((size%2) == 0) 
    {   
        fprintf(stderr,"Invalid size passed to createCenteredArray!\n");
        return NULL;
    }
    int *returnArray = malloc(size*sizeof(int));

    //Check that malloc worked
    if(NULL==returnArray)
    {
        fprintf(stderr,"Out of Memory!\n");
        return NULL;
    }

    // Move pointer to the middle of the array, and return it
    /*
    <----------->
    ^---->^    
    before/after     
     */
    returnArray += (size/2);
    return returnArray;
}
//Takes a centered array <array>, its size <size>, and the index of an element you want <index>
//Returns the element if the index is valid, or 1 if the index is invalid 
int getAtIndex(int *array, int size, int index)
{
    if(NULL==array)
    {
        fprintf(stderr,"NULL pointer passed to getAtIndex!\n");
        return 1;
    }
    if((size <= 0) || ((size%2) == 0))
    {
        fprintf(stderr,"Invalid size passed to getAtIndex!\n");
        return 1;
    }
    //Check if the index is valid
    //Index is valid if positive and less than size/2 or negative and greater than negative size/2 or zero
    if(
        (index >= 0 && index <= (size/2))
        || 
       (index < 0 && index >= -(size/2))
       )
       {
           return array[index];
       }
    else 
    {
        fprintf(stderr,"Invalid index passed to getAtIndex! Writing error messages is tiring, you know.\n");
        return 1;
    }

}
// Takes a centered array <array> and its size <size> and returns the average of all elements with index >= 0
// Returns -0.0 on error
float averageUpperHalf(int *array, int size)
{
    if(NULL == array)
    {
        fprintf(stderr,"NULL pointer passed to averageUpperHalf!\n");
        return -0.0;
    }
    if((size <= 0) || ((size%2) == 0))
    {
        fprintf(stderr, "Invalid size passed to averageUpperHalf!\n");
        return -0.0;
    }
    const int halfsize = size/2;
    int sum = 0;
    /*
    <-----*----->
            ^     ^
            0     5
    For an array of size 11, we want to add array[0] through array[5]
    */
    for(int i = 0; i <= halfsize; i++)
    {
        sum += array[i];
    }
    return (float) sum/ (float) (halfsize+1); // Including the zeroth element, we've added halfsize+1 elements
}
//Takes a centered array <array> and its size <size> and frees it
void freeCenteredArray(int *array, int size)
{
    if(NULL == array) 
    {
        fprintf(stderr,"NULL pointer given to freeCenteredArray! Either something is wrong or you are testing my patience.\n");
        return;
    }
    if((size%2)==0)
    {
        fprintf(stderr,"This isn't a centered array! Or it is, and you're just bad at counting.\n");
        return;
    }
    /*
    <-----*----->
     ^<----^    
     head/array
     */
    int *head = array - (size/2);
    free(head);
}

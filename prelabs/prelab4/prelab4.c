#include "prelab4.h"

void *createArray(const int n,  const int dataTypeSize)
{
    if(n<0) 
    {
        fprintf(stderr, "Invalid array size!\n");
        return NULL;
    }
    int *returnArray = malloc((n*dataTypeSize) + sizeof(int));
    if(returnArray == NULL)
    {
        fprintf(stderr, "Out of memory!\n");
        return NULL;
    }
    *returnArray = n;
    returnArray++;
    return (void*) returnArray;
}
int getArraySize(void* const array)
{
    int* returnArray = (int*) array - 1;
    return returnArray[0];
}
void freeArray(void* const array)
{
    int *head = (int*) array - 1;
    free(head);
}
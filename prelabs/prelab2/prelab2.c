#include "prelab2.h"

float* readFloatFileIntoArray(FILE *fptr, int *length)
{
    if(NULL == fptr)
    {
        *length = -1;
        fprintf(stderr, "File pointer is null!\n");
        return NULL;
    }
    if(NULL == length)
    {
        fprintf(stderr, "Length pointer is null!\n");
        return NULL;
    }
    fscanf(fptr, "%d", length);
    float *returnArray = malloc(*length * sizeof(float));
    if(NULL == returnArray)
    {
        fprintf(stderr,"Out of memory!\n");
        return NULL;
    }
    for(int i=0; i<*length; i++)
    {
        fscanf(fptr,"%f", returnArray+i);
    }
    return returnArray;

}
void freeFloatArray(float** array)
{
    free(*array);
    *array = NULL;
}
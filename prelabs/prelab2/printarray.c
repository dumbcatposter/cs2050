#include "printarray.h"
#include "printarray.h"
void printFloatArray(float* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%f\n", array[i]);
    }
}
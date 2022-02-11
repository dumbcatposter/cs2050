#include "prelab4.h"

int main(void)
{
    double *doubleArray = createArray(1000, sizeof(double));
    for(int i = 0; i<1000; i++)
    {
        doubleArray[i] = i;
    }
    printf("doubleArray[55] = %lf\n", doubleArray[55]);
    printf("doubleArray size = %d\n", getArraySize(doubleArray));
    freeArray(doubleArray);
}
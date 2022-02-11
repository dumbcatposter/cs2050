#include "lab3.h"

int main(void)
{
    //Check that it works
    const int size = 11;
    const int halfsize = size/2;
    int *testArray = createCenteredArray(size);
    for(int i = -halfsize; i <= halfsize; i++)
    {
        testArray[i] = i;
        printf("array[%d]=%d\n",i, getAtIndex(testArray,size,i));
    }
    printf("averageUpperHalf=%f\n",averageUpperHalf(testArray, size));

    //See what happens if it don't
    int* nullArray = NULL;
    createCenteredArray(8);
    freeCenteredArray(nullArray, 1);
    freeCenteredArray(testArray,10);
    averageUpperHalf(nullArray, 11);
    averageUpperHalf(testArray, 10);
    getAtIndex(testArray, size,23912039);
    getAtIndex(nullArray,size,-5);
    getAtIndex(testArray,0,4);
    getAtIndex(testArray, 8, 4);

    //Kids, always free your arrays
    freeCenteredArray(testArray, size);
}
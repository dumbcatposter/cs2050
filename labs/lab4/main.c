#include "lab4.h"

int main(void)
{
    const int arraySize = 10;
    const int testSum = 1 + 3 + 5 + 7+ 9; 
    int* testArray = createIntArray(arraySize);
    //int* nullArray = NULL;
    for(int i = 0; i < arraySize; i++)
    {
        testArray[i] = i;
    }
    printArray(testArray);
    printf("Size Test: %d == %zu? %s\n", arraySize, getSize(testArray), arraySize==getSize(testArray)? "Pass":"Fail");
    printf("Sum Test: %d == %d? %s\n", testSum, sumOddIndices(testArray), testSum==sumOddIndices(testArray)? "Pass": "Fail");
    freeArray(testArray);
}
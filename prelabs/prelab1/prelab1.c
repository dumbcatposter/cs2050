#include <stdio.h>

/* This function finds the highest number lower than the given number, and puts it in result. Returns 0 for success, 1 for failure. */
int findLEQ(float* array, int arraySize, float num, float *result);

int main(void)
{
    //Testing code goes here
    printf("Prelab 1 \n");
    float testArray[10] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0, 9.0, 10.0};
    float result = 0.0;
    
    for(float i = 0.0; i <= 10.0; i+=0.5)
    {
        printf("Input: %lf, Success (0 is good): %d, Result: %lf\n", i, findLEQ(testArray, 10, i, &result), result);
    }
}

int findLEQ(float* array, int arraySize, float num, float *result)
{
    *result = 0;
    int success = 0;
    for(int i = 0; i < arraySize; i++)
    {
        if (array[i] < num && array[i] > *result) {*result = array[i]; success=1;}
    }
    if (success == 0) return 1;
    else return 0;
}

/*******************************
 * Name: Jacob Groves
 * Course: CS2050
 * Lab: Lab 1
 * Date: Fri Jan 28
 * Semester: SS2022
 * Pawprint: JSGGBG
 * ******************************/
#include "lab1.h"

// REQUIRED FUNCTION IMPLEMENTATIONS

// avgEven: Returns the average of all the even numbers in an array of floats. Will return 0 and put -0.0 in the result pointer if no even numbers are found.
int avgEven(int *array, int size, float *result)
{
    int returnValue =0; // 0 if unsuccessful, number of elements averaged if successful
    int sumEvens =0; // Sum of all even numbers in array

    for(int i = 0; i<size;i++)
    {
        if((array[i] % 2) ==0)
        {
            sumEvens += array[i];
            returnValue++;
        }
    }
    if(0 != returnValue) *result = (float) sumEvens/returnValue; // Dividing by 0 causes headaches
    else *result = -0.0; // -0 is a valid float value that will let the user know something went wrong
    return returnValue;
}
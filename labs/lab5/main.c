#include "lab5.h"
#include<assert.h>

int main(void)
{
    //Creating Cars Array
    const int numCars = 5;
    Car *array = createArray(sizeof(Car), numCars);
    for(int i = 0; i < numCars; i++)
    {
        array[i].vin = 0;
        array[i].numberOfAccidents =0;
        array[i].milesDriven = 0;
    }
    //Testing getSize
    assert(getSize(array) == numCars);
    //Testing getMilesDriven and getWithMostAccidents
    array[0].numberOfAccidents = 13;
    array[4].numberOfAccidents = 14;
    assert(getWithMostAccidents(array) == (array+4));
    incrementNumberOfAccidents(array);
    incrementNumberOfAccidents(array);
    assert(getWithMostAccidents(array) == array);
    //Testing updateMilesDriven
    array[0].milesDriven = 12;
    updateMilesDriven(array, 3.0);
    assert(array->milesDriven==15);
    //Testing printCars
    printCars(array);
    //Testing error helper functions
    assert(getWithMostAccidents(NULL) == NULL);
    assert(getVin(NULL) == -1);
    //assert(getVin(NULL)==0);
    Car * emptyarray  = createArray(sizeof(Car), 0);
    printCars(emptyarray);
    freeArray(emptyarray);
    //Testing Free Array
    freeArray(array);
}
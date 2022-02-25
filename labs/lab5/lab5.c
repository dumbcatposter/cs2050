#include "lab5.h"

//Helper function, prints an error and returns a null pointer
void * errorArrayNULL(char * functionName)
{
    fprintf(stderr, "NULL pointer passed to %s\n", functionName);
    return NULL;
}
//Helper function, prints an error and returns -1
int errorArrayNegOne(char * functionName)
{  
    fprintf(stderr, "NULL pointer passed to %s\n", functionName);
    return -1;
}
void * errorArrayInvalidSize(char * functionName)
{
    fprintf(stderr, "Invalid size passed to %s\n", functionName);
    return NULL;
}

//[Mostly copied from Lab 4]
//Creates an array of <numElements> elements of size <elementSize>
//Returns NULL on error
void * createArray(size_t elementSize, int numElements)
{
    //You can have an array of size 0 (really it will be sizeof(int)), it will just be empty
    //But you cannot have a negatively sized array
    if(numElements<0) 
    {
        fprintf(stderr, "Invalid array size!\n");
        return NULL;
    }
    //You can also have elementSize of 0, if you really wanted it
    //We do not have to check elementSize for being negative because it is unsigned by default

    //Create an array of <numElements> elements, check if malloc was successful
    int *returnArray = malloc((elementSize*numElements) + sizeof(int));
    if(returnArray == NULL)
    {
        fprintf(stderr, "Out of memory!\n");
        return NULL;
    }
    //Plug in the size, move 1 forward, cast to void * and return
    *returnArray = numElements;
    returnArray++;
    return (void *) returnArray;
}

//[Mostly copied from Lab 4]
//Return the size of an array <array> created by createIntArray
//Returns 0 in case of error, or if you have an array with size 0 for some reason
int getSize(void *array)
{
    if(NULL == array) return 0;
    //Move back 1 int and return it 
    int* returnArray = (int*) array - 1;
    return returnArray[0];
}

//Getters 
//All return -1 on error
int getVin(Car *car)
{
    if(NULL == car) return errorArrayNegOne("getVin");
    return car->vin;
}
float getMilesDriven(Car *car)
{
    if(NULL == car) return errorArrayNegOne("getMilesDriven");
    return car->milesDriven;
}
int getNumberOfAccidents(Car *car)
{
    if(NULL == car) return errorArrayNegOne("getNumberOfAccidents");
    return car->numberOfAccidents;
}

//Setters

//Adds <milesToAdd> to Car <car>'s milesDriven
//Does not update milesDriven on error, or invalid input
void updateMilesDriven(Car *car , float milesToAdd)
{
    if(0 > milesToAdd)
    {
        fprintf(stderr,"You can't drive negative miles!\nIf you could, gas would be a lot cheaper. (Invalid input to updateMilesDriven)\n");
        return;
    }
    //This one does not use the helper function because it is *funny*
    if(NULL == car)
    {
        fprintf(stderr,"We've found the Invisible Boatmobile! (NULL car passed to updateMilesDriven)\n");
        return;
    }
    car->milesDriven += milesToAdd;
}

//Increments numberOfAccidents on Car <car> (I hope everyone's OK!)
//Does not update the car on error
void incrementNumberOfAccidents(Car *car)
{
    if(car==NULL)
    {
        fprintf(stderr,"There was nothing left, huh? (NULL car passed to incrementNumberOfAccidents)\n");
        return;
    }
    car->numberOfAccidents += 1;
}

//Returns the car with VIN <VIN> in Car array <array>
//Returns NULL on error
Car * getCarByVIN(Car *array, int VIN)
{
    //Check input array
    if(NULL == array) return errorArrayNULL("getCarByVIN");
    //Get array size and check it has at least 1 car
    int arraysize = getSize(array);
    if(arraysize < 1) errorArrayInvalidSize("getCarByVIN");
    //Initialize the Car * to NULL in case no car is found with vin <VIN>
    Car *returnCar = NULL;
    //Iterate through all Cars in <array> and check if it is the Car we are looking for
    for(int i = 0; i < arraysize; i++)
    {
        if((getVin(array+ i)) == VIN)
        {
            returnCar = (array + i);
        }
    }
    return returnCar;
}


//Returns the Car with the most accidents (or, with the most reckless driver)
//Returns NULL on error
Car * getWithMostAccidents(Car *array)
{
    //Check array
    if(NULL == array) return errorArrayNULL("getWithMostAccidents");
    //Get size and check it
    int arraysize = getSize(array);
    if(arraysize < 1) return errorArrayInvalidSize("getWithMostAccidents");
    //Initialize the returned Car to the first car in the array for comparison to other cars
    Car * returnCar = array;
    //Start comparing at 1 since array[0] is already in returnCar
    for(int i = 1; i<arraysize;i++)
    {
        if(getNumberOfAccidents(returnCar) < getNumberOfAccidents(array+ i))
        {
            returnCar = (array +i);
        }
    }
    return returnCar;
}

//[Mostly copied from Lab 4]
//Print each Car in a Car array <array> on its own line
//Prints an error message on error
void printCars(Car *array)
{
    if(NULL==array)
    {
        errorArrayNULL("printCars");
        return;
    }
    //Get the size, and print an error if the array is unprintable because size is 0 or less
    int size = getSize(array);
    if(0>=size)
    {
        errorArrayInvalidSize("printCars");
        return;
    }
    //For each car, Fetch each value and print it
    for(int i = 0; i < size; i++)
    {
        printf("Car VIN:%d\tMiles Driven:%f\tNumber of Accidents:%d\n", 
        getVin(array+i), getMilesDriven(array+i),getNumberOfAccidents(array+i));
    }
}

//[Mostly copied from Lab 4]
// Free an array <array> with an integer size stored before it 
void freeArray(void *array)
{
    int *head = (int*) array - 1;
    free(head);
}


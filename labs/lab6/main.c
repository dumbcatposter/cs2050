#include "lab6.h"
#include<assert.h>
#include<math.h>
#include<string.h>

int main(int argc, char **argv)
{
    srand(atoi(argv[1]));
    Node * carList = initList();
    const int numCars = 5;
    Car * car;
    for(int i = 0; i < numCars; i++)
    {
        Car * car = malloc(sizeof(Car));
        assert(0 == insertAtHead(&carList, car));
    }
    assert(carList != NULL);
    for(Node * iCar = carList; iCar != NULL; iCar = iCar->next)
    {
        car = iCar->data;
        car->milesDriven =  fmod(rand(), 100000.0);
        car->vin = (int) rand() % 100;
        car->numberOfAccidents = 10;
    }
    printf("Car with least miles driven has driven %f miles.\n", getWithLeastMilesDriven(carList)->milesDriven);
    printCars(carList);
    car = carList->data;
    assert(getSize(carList) == 5);
    assert(car = removeFromHead(&carList));
    printf("\n\n");
    printCars(carList);
    assert(getSize(carList) == 4);
    freeList(&carList);
}
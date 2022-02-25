#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int empID, jobType;
    float salary;
} Employee;

//Implemented
Employee createEmployee(int empID, int jobType, float salary);
Employee * readEmployeeArray(FILE *fp) ;
int getSize(void *array);
void freeArray(void *array);

//Unimplemented
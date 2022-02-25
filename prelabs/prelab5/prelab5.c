#include "prelab5.h"

Employee createEmployee(int empID, int jobType, float salary)
{
    Employee returnEmp;
    returnEmp.empID = empID;
    returnEmp.jobType = jobType;
    returnEmp.salary = salary;
    return returnEmp;
}
Employee * readEmployeeArray(FILE *fp) 
{
    //Read size from file
    int size;
    fscanf(fp, "%d", &size);
    if(0==size) return NULL;

    //Allocate array
    int *head = malloc(sizeof(int) + (size*sizeof(Employee)));
    if(NULL == head) return NULL;
    
    //Embed size
    *head = size;
    head += 1;

    //Build array
    Employee* empArray = (Employee *) head;
    int empID, jobType;
    float salary;
    for(int i  = 0; i<size;i++)
    {
        fscanf(fp,"%d %d %f", &empID, &jobType, &salary);
        empArray[i] = createEmployee(empID,jobType,salary);
    }

    //Return array
    return empArray;
}

int getSize(void* const array)
{
    int* head = (int*) array - 1;
    return head[0];
}
void freeArray(void* const array)
{
    int *head = (int*) array - 1;
    free(head);
}
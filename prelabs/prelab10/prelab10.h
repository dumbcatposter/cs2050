//
// Created by jacob on 4/25/2022.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct empstruct
{
    int id, ssn;
    char *Name;
} Employee;
typedef struct nstruct
{
    struct nstruct *left, *right;
    Employee * obj;
} Node;
typedef struct empdb
{
    Node *sorted_bySSN, *sorted_byID;
    int ec, size;
} EmpDatabase;

EmpDatabase createSearchableEmployeeDB(); // Just inits your struct
EmpDatabase insertEmp(Employee *employee, EmpDatabase empdb);
Employee * findEmpBySSN(int, EmpDatabase*);
Employee * findEmpByID(int, EmpDatabase*);
void freeEmpDatabase(EmpDatabase);
int getErrorCode(EmpDatabase);
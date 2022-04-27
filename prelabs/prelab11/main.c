//
// Created by jacob on 4/25/2022.
//
#include "prelab11.h"

int main(void)
{
    Employee emp1 = {1, 132881234, "Portia"};
    Employee emp2 = {2, 119641657, "Antonio"};
    Employee emp3 = {3, 127778843, "Shylock"};
    Employee emp4 = {4, 124389424, "Lancelot Gobbo"};
    Employee emp5 = {5, 135548392, "Lorenzo"};

    puts("Creating database...");
    EmpDatabase empdb = createSearchableEmployeeDB();
    empdb = insertEmp(&emp4, empdb);
    empdb = insertEmp(&emp2, empdb);
    empdb = insertEmp(&emp1, empdb);
    empdb = insertEmp(&emp3, empdb);
    empdb = insertEmp(&emp5, empdb);

    puts("Beginning database search test...");
    int ssn = emp3.ssn;
    Employee * result = findEmpBySSN(ssn, &empdb);
    if(result != NULL) printf("SSN Search:\n\tExpected employee: %s\n\tGot employee: %s\n", emp3.Name, result->Name);
    else {
        puts("SSN Search Failed!");
        printf("Error code: %d\n", getErrorCode(empdb));
    }
    result = findEmpByID(3, &empdb);
    if(result != NULL) printf("ID Search:\n\tExpected employee: %s\n\tGot employee: %s\n", emp3.Name, result->Name);
    else
    {
        puts("ID Search Failed!");
        printf("Error code: %d\n", getErrorCode(empdb));
    }
    freeEmpDatabase(empdb);
    return 0;
}
//
// Created by jacob on 4/25/2022.
//

#include "prelab11.h"

EmpDatabase createSearchableEmployeeDB()
{
    EmpDatabase empdb = {NULL, NULL, 0};
    return empdb;
}
EmpDatabase insertEmp(Employee *employee, EmpDatabase empdb)
{
/*
 * Assume that we have a new node containing
    the value m. Let top be a reference to the top
    of the tree.
    REPEAT:
    If top is an empty tree, then set it equal to the
    node containing m.  Return.
    If top is not empty, then compare m to the key
    stored in the root.  If m is less than the key in
    the root, then set top equal to the left subtree;
    otherwise set top equal to the right subtree.
 */
    // Create a new node for the Employee to sit in
    Node *empNode = malloc(sizeof(Node));
    empNode->obj = employee;
    empNode->left = NULL; empNode->right = NULL;
    // Insert into SSN Tree
    if(empdb.sorted_bySSN == NULL) empdb.sorted_bySSN = empNode;
    else
    {
        // "top" will eventually refer to the point where our new Node should be
        // "attachPoint" is where the Node will attach to the rest of the tree
        Node *top = empdb.sorted_bySSN;
        Node *attachPoint = top;
        while(top != NULL)
        {
            attachPoint = top;
            if(employee->ssn < top->obj->ssn) top = top->left;
            else top = top->right;
        }
        if(employee->ssn < attachPoint->obj->ssn)
        {
            attachPoint->left = empNode;
        }
        else
        {
            attachPoint->right = empNode;
        }
    }
    // Insert into ID Tree
    if(empdb.sorted_byID == NULL) empdb.sorted_byID = empNode;
    else
    {
        Node *top = empdb.sorted_byID;
        Node *attachPoint = top;
        while(top != NULL)
        {
            attachPoint = top;
            if(employee->id < top->obj->id) top = top->left;
            else top = top->right;
        }
        if(employee->id < attachPoint->obj->id)
        {
            attachPoint->left = empNode;
        }
        else
        {
            attachPoint->right = empNode;
        }
    }
    return empdb;
}
Employee * findEmpBySSN(int ssn, EmpDatabase empdb)
{

}
Employee * findEmpByID(int id, EmpDatabase empdb)
{

}
void freeEmpDatabase(EmpDatabase empdb)
{

}
int getErrorCode(EmpDatabase empdb)
{

}
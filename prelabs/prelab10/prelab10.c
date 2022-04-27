//
// Created by jacob on 4/25/2022.
//

#include "prelab10.h"

/*
 * Error codes:
 *  0: everything fine
 *  241: Could not find value in empRecursiveBinarySearch
 *  242: empRecursiveBinarySearch received NULL pointer
 *  243: comparison function failed
 */
EmpDatabase createSearchableEmployeeDB()
{
    EmpDatabase empdb = {NULL, NULL, 0, 0};
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
    // Create a new node for the Employee to sit in the SSN Tree
    Node *empSSNNode = malloc(sizeof(Node));
    empSSNNode->obj = employee;
    empSSNNode->left = NULL;
    empSSNNode->right = NULL;
    // Insert into SSN Tree
    if(empdb.sorted_bySSN == NULL) empdb.sorted_bySSN = empSSNNode;
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
            attachPoint->left = empSSNNode;
        }
        else
        {
            attachPoint->right = empSSNNode;
        }
    }
    //Create a new node for the employee to sit in the ID Tree
    Node *empIDNode = malloc(sizeof(Node));
    empIDNode->obj = employee;
    empIDNode->left = NULL;
    empIDNode->right = NULL;
    // Insert into ID Tree
    if(empdb.sorted_byID == NULL) empdb.sorted_byID = empIDNode;
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
            attachPoint->left = empIDNode;
        }
        else
        {
            attachPoint->right = empIDNode;
        }
    }
    empdb.ec = 0;
    empdb.size += 1;
    return empdb;
}
int cmpSSN(const int key, const Employee * const emp)
{
    int cmp = emp->ssn - key;
    if(cmp == 0) return 0; // Keys are the same
    if(cmp > 0) return -1; // SSN < key value
    else return 1; // SSN > key value
}
int cmpID(const int key, const Employee * const emp)
{
    int cmp = emp->id - key;
    if(cmp == 0) return 0; // Keys are the same
    if(cmp > 0) return -1; // ID < key value
    else return 1; // ID > key value
}

Employee * empRecursiveBinSearch(int key, Node *Tree , EmpDatabase *empdb, int (*compar)(const int key, const Employee * const emp))
{
    /*
     * 1. Compare key to the obj in Tree using compar()
     * 2. If key == obj, return obj
     * 3. If key > obj, go left
     * 4. If key < obj, go right
     */

    //Error checking section
    if( Tree == NULL ||
        empdb->sorted_byID == NULL)
    {
        empdb->ec = 242;
        return NULL;
    }

    Employee *emp = Tree->obj;
    int cmp = compar(key,emp);
    switch(cmp)
    {
        case -1:
            if(Tree->left == NULL)
            {
                empdb->ec = 241;
                return NULL;
            }
            return empRecursiveBinSearch(key, Tree->left, empdb, compar);
        case 0:
            empdb->ec = 0;
            return emp;
        case 1:
            if(Tree->right == NULL)
            {
                empdb->ec = 241;
                return NULL;
            }
            return empRecursiveBinSearch(key, Tree->right, empdb, compar);
        default:
            empdb->ec = 243;
            return NULL;
    }
}
Employee * findEmpBySSN(int ssn, EmpDatabase *empdb)
{
    return empRecursiveBinSearch(ssn, empdb->sorted_bySSN, empdb, cmpSSN);
}
Employee * findEmpByID(int id, EmpDatabase *empdb)
{
    return empRecursiveBinSearch(id, empdb->sorted_byID, empdb, cmpID);
}
void freeTree(Node *t)
{
    if (t == NULL) return;
    freeTree(t->left);
    freeTree(t->right);
    free(t);
}
void freeEmpDatabase(EmpDatabase empdb)
{
    freeTree(empdb.sorted_byID);
    freeTree(empdb.sorted_bySSN);
}
int getErrorCode(EmpDatabase empdb)
{
    return empdb.ec;
}
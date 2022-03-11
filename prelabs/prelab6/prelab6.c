#include "prelab6.h"
//#define DEBUG


List * initList(int *ec)
{
    List * list = malloc(sizeof(List));
    if (list == NULL)
    {
        *ec = 1;
        return NULL;
    }
    else
    {
        *ec = 0;
        list->object = NULL;
        list->next = NULL;
        return list;
    }
}

List * insertAtHead(void* objToInsert, List* listToInsert, int* ec)
{
    int eHandler = 0;
    List *node = initList(&eHandler);
    if(eHandler == 1)
    {
        //If there is not enough memory to create a new node,
        //Return the original list and change the error code to 1
        *ec = 1;
        return listToInsert;
    }
    //If creating the new node was successful,
    //Plug the address of the object into the node, make it point to the beginning of the list, and return its address as the new head
    node->object = objToInsert;
    node->next = listToInsert;
    #ifdef DEBUG
    printf("Node object: %p\n", node->object);
    printf("Next node: %p\n", node->next);
    #endif

    return node;
}

void * getAtIndex(int index, List* listToIndex)
{
    //First node is Index 1
    List *curNode = listToIndex;
    for(int i = 1; i < index; i++)
    {
        curNode = curNode->next;
    }
    if(NULL==curNode) return NULL;
    else return curNode->object;
}

int getListLength(List* listToMeasure)
{
    List *curNode = listToMeasure;
    int length =0;
    while(curNode != NULL)
    {
        length++;
        curNode = curNode->next;
    }
    return length;
}

List * freeList(List* listToFree)
{
    List *curNode = listToFree;
    while(curNode != NULL)
    {
        free(curNode->object);
        curNode = curNode->next;
        free(listToFree);
        listToFree = curNode;
    }
    return NULL;
}

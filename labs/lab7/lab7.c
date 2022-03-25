#include "lab7.h"

//Returns the Node in list <list> at index <index> or the NULL
Node *getNodeAtIndex(Node *list, int index)
{
    //Check that the index is valid
    if(NULL==list ||index > getSize(list))
        return NULL;
    /* Return the dummy node if index is -1
        Used for inserting at the head */
    if(index == -1) 
        return list;
    Node *curNode = list->next; // curNode starts at index 0
    //Move <index> - 1 nodes forward
    for(int i = 0; i < index; i++)
    {
        curNode = curNode->next; 
    }
    //Return what we found
    return curNode;
}

//Creates a new Node with given obj <obj> and next <next> pointers
//Returns NULL on failure
Node *createNewNode(void *obj, Node *next)
{
    //Malloc a node, populate its fields, return it
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        return NULL;
    newNode->data = obj;
    newNode->next = next;
    return newNode;
}

//Initializes an empty list and returns a pointer to that list
//Will return NULL on error
Node * initList()
{
    //Create a dummy node
    Node *dummyNode = malloc(sizeof(Node));
    if(dummyNode == NULL)
        return NULL;

    //Create a size int to put in the dummy node 
    int *size = malloc(sizeof(int));
    if(size == NULL)
        return NULL;
    //Size starts at 0, dummy node starts pointing at NULL, data field of dummy node is used for size
    *size = 0;
    dummyNode->next = NULL;
    dummyNode->data = size;
    //Return that node as our initialized, empty list
    return dummyNode;
}
//Returns the size of a list <list>, or -1 on error
int getSize(Node *list)
{
    //Check that the list isn't null and that it has a properly initalized dummy node
    if(list == NULL)
        return -1;
    if(list->data == NULL)
        return -1;
    //Size of list is stored in the dummy node
    return *(int *)(list->data);
}
//Inserts a void* <data> onto the list <list> at index <index>
//Returns 0 on success, 1 on failure
int insertAtIndex(Node *list, void *data, int index)
{
    //Check that the list and index are valid
    if (list == NULL || index > getSize(list) || index < 0)
    {
        return 1;
    }
    //Make a pointer that points to the node before the index we're interested in
    Node *curNode = getNodeAtIndex(list, index-1); 
    //Create a new node that points to the next in line to curNode
    Node *newNode;
    newNode = createNewNode(data, curNode->next);
    if(newNode == NULL)
        return 1;
    //insert new node at index
    curNode->next = newNode;
    //Increment size in the dummy node
    int *size = list->data;
    *size = getSize(list) + 1;
    return 0;
}
//Returns the data at index <index> in list <list> WITHOUT removing it from the list
//Returns NULL if index is invalid
void * getAtIndex(Node *list, int index)
{
    // Get the Node at the Index
    Node *curNode = getNodeAtIndex(list, index);
    if(NULL==curNode)
        return NULL;
    // And return its data
    return curNode->data;

}
//Returns the data at index <index> in list <list> AND removes it from the list
//Returns NULL if the index is invalid
void * removeAtIndex(Node *list, int index)
{
    //Find the node to remove
    Node *nodeToRemove = getNodeAtIndex(list, index);
    if(NULL==nodeToRemove)
        return NULL;
    //Pull the data from it
    void *dataToRetrieve = nodeToRemove->data;
    //Mend the list
    Node *nodePrev = getNodeAtIndex(list, index-1);
    nodePrev->next = nodeToRemove->next;
    //Update the size
    int *size = list->data;
    *size = getSize(list) - 1;
    list->data = size;
    //Free the node and return the data
    free(nodeToRemove);
    return dataToRetrieve;
}
//Removes the last node of list <list> and returns the data stored inside
//Returns NULL on error (list is empty)
void * removeAtTail(Node *list)
{
    //Remove the tail
    void *returnValue = removeAtIndex(list, getSize(list)-1);
    //Return what we got
    return returnValue;
}
//Frees a list <list> and all memory associated with it
//Will set the list pointer to NULL so you don't use it again
void freeList(Node **list)
{
    // Initialize freeingList at the dummy node
    Node * freeingList = *list;
    // Free the int used to store size
    free(freeingList->data); 
    //Free each node in sequence
    for(Node *next; freeingList->next != NULL; freeingList = next)
    {
        next = freeingList->next;
        free(freeingList);
    }
    //Set the list to NULL
    *list = NULL;
}



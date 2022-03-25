#include "prelab8.h"

/* This function returns the error code from the most 
   recently executed queue operation. 0 implies success, 
   1 implies out-of-memory error. Some functions may 
   document additional error conditions. NOTE: All  
   queue functions assign an error code.   */  
int getQueueErrorCode(Queue queueToCheck)
{
    return *(queueToCheck.ec);
}

//Sets the error code of the given queue <queueToSet> to <ec>
void setQueueErrorCode(Queue queueToSet, int ec)
{
    *(queueToSet.ec) = ec;
}
//Adds the given number <change> to queue <queueToSet>'s size value
void setQueueSize(Queue queueToSet, int change)
{
    *(queueToSet.size) += change;
}

/* This function returns an initialized Queue variable.  
   Every queue variable must be initialized before      
   applying subsequent queue functions. */  
Queue queueInit()
{
    Queue newQueue;
    newQueue.ec = malloc(sizeof(int));
    newQueue.size = malloc(sizeof(int));
    newQueue.dummy = malloc(sizeof(Node));

    if(newQueue.ec == NULL || newQueue.size == NULL || newQueue.dummy ==NULL)
    {
        //If the user's computer can't spare memory the size of an int or a Node, something's gone terribly wrong.
        //Try to free everything first
        free(newQueue.ec);
        free(newQueue.size);
        free(newQueue.dummy);
        //And, because we have to return something, return a queue that does not look right
        newQueue.ec = NULL;
        newQueue.size = NULL;
        newQueue.dummy = NULL;
        return newQueue;
    }

    *(newQueue.ec) = 0;
    newQueue.dummy->next = NULL; // dummy->next is the "tail" of the queue
    newQueue.dummy->obj = NULL;
    *(newQueue.size) = 0;
    return newQueue;
    
}
 
/* This function enqueues an object into the queue.  
   For convenience, error code is returned directly 
   (and also can be obtained via getQueueErrorCode) */  
int enqueue(void *obj, Queue queueToAdd)
{
    //Increment size
    setQueueSize(queueToAdd, 1);
    //tail variable for convenience
    Node *tail = queueToAdd.dummy->next;
    //Create a new node, put the object in it
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL)
    {
        //If memory allocation failed, set the error flag and decrement the size back to what it used to be
        setQueueErrorCode(queueToAdd, 1);
        setQueueSize(queueToAdd, -1);
        return 1;
    }
    newNode->obj = obj;
    //Special case: The queue is empty (tail == NULL)
    if(tail == NULL)
    {
        //Our new node just becomes the tail
        queueToAdd.dummy->next = newNode;
        //It's the only element in the list, so it points to itself
        newNode->next = newNode;
        //Update the error code and return before we enter segfault-town
        setQueueErrorCode(queueToAdd, 0);
        return 0;
    }
    //The new node's next should point to dummy->next (tail)'s next pointer
    //Which will be the "front" of the list
    newNode->next = tail->next;
    //The old tail should point to our new node
    tail->next = newNode;
    //Now the new tail should be the the node we just added
    queueToAdd.dummy->next = newNode;
    //Update ec and return
    setQueueErrorCode(queueToAdd, 0);
    return 0;
}
 
/* This function performs dequeue and returns  
   object at front of queue. NULL is returned 
   if queue is empty and error code is set to 2.  
   NOTE: User should check error code if null  
   objects are permitted in the queue. */   
void * dequeue(Queue queueToRemove)
{
    Node *tail = queueToRemove.dummy->next;
    //List is empty
    if(tail == NULL)
    {
        setQueueErrorCode(queueToRemove ,2);
        return NULL;
    }
    //Get "head" of list
    Node* head = queueToRemove.dummy->next->next;
    //If the head of the list doesn't exist for some reason
    if(head == NULL)
    {
        setQueueErrorCode(queueToRemove, 2);
        return NULL;
    }
    //Remove the node from the list
    Node *newHead = head->next;
    tail->next = newHead;
    //Remove the object from the node, free the node struct
    void *obj = head->obj;
    free(head);
    //Update the queue and return the object
    setQueueErrorCode(queueToRemove, 0);
    setQueueSize(queueToRemove, -1);
    return obj;

}
 
/* This function returns the number of objects 
   in the queue. */  
int getQueueSize(Queue queueToMeasure)
{
    return *(queueToMeasure.size);
}
 
/* This function uninitializes a queue and frees all  
   memory associated with it. NOTE: value of Queue  
   variable is undefined after this function is  
   applied, i.e., it should not be used unless 
   initialized again using queueInit. */   
void freeQueue(Queue queueToFree)
{
    //If the size of the Queue is 0, there's nothing inside it to free, and trying to execute the block of code below will result in an invalid read
    if(getQueueSize(queueToFree) == 0)
    {
        goto freeQueue;
    }
    //Free all the Nodes in the Queue
    Node *head = queueToFree.dummy->next->next;
    for(Node *nodeToFree = head; nodeToFree != head; nodeToFree = nodeToFree->next)
    {
        free(nodeToFree);
    }

    //Free the queue itself
    freeQueue:
    free(queueToFree.ec);
    free(queueToFree.size);
    free(queueToFree.dummy);
}

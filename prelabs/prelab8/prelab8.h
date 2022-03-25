#include<stdlib.h>
#include<stdio.h>

typedef struct nstruct{
    void* obj;
    struct nstruct *next;
} Node;

typedef struct qstruct {
    Node *dummy;
    int *size, *ec;
} Queue;

//Diagram for illustrative purposes
/*
Circular Linked List
   v-------------next--------------<
   |                               |
   |                               |
   v                               ^
[Node 1] -next> [Node 2] -next> [Node 3] <- tail (located in dummy node)
   ^ remove here                    ^ add here
*/

int getQueueErrorCode(Queue);
Queue queueInit(); 
int enqueue(void *, Queue);
void * dequeue(Queue);
int getQueueSize(Queue);
void freeQueue(Queue);
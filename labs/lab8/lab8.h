#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;

Queue * initQueue();
int getSize(Queue *q);
int enQueue(Queue *q, void *data);
void * peek(Queue *q);
void * deQueue(Queue *q);
void freeQueue(Queue *q);

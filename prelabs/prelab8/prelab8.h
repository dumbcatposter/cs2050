#include<stdlib.h>
#include<stdio.h>

typedef struct nstruct {
    void *obj;
    struct nstruct *next;
} Node;

typedef struct qstruct {
    Node *front, *rear;
    int *size, *ec;
} Queue;


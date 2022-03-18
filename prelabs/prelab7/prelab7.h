#include<stdio.h>
#include<stdlib.h>

typedef struct nstruct{
    void* obj;
    struct nstruct *next;
} Node;

typedef struct{ 
         Node *head; 
} List;

/* These functions insert the object of the first parameter  
   at the head/tail of the list and returns an error code:  
   0 = success, 1 means there was insufficient memory 
   and the list is not changed. */  
int insertAtHead(void*, List);
int insertAtTail(void*, List);
 
/* These functions delete and return the object at 
   the head/tail. If list is empty, NULL is returned. */     
void * removeHead(List);
void * removeTail(List);

List initList();
void freeList(List);



#include<stdlib.h>
#include<stdio.h>

typedef struct listStruct { 
      void *object; 
      struct listStruct *next; 
} List; 

/* This function returns an empty List object, i.e., this must 
   be called before operations are performed on the list. The 
   parameter is a reference to an error code. 0 signifies the 
   operation was performed correctly, 1 means there was  
   insufficient memory available to initialize the list. */  
List * initList(int*);

 /* This function inserts the object of the first parameter  
   at the head of the list. The last parameter is an error  
   code (0 implies success, 1 implies insufficient memory). 
   Returns pointer to updated list if there is no error; 
   otherwise returns the given list without change.   */  
List * insertAtHead(void*, List*, int*);

 /* This function returns the object at the index location  
   (starting at 1 for the head) of the first parameter. */  
void * getAtIndex(int, List*);

 /* This function returns the number of objects in the list. */  
int getListLength(List*);

 /* This function frees all memory allocated for a list and  
   returns NULL. */  
List * freeList(List*) ;
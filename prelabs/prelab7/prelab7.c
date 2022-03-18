#include "prelab7.h"
#define DEBUG

Node * createNewNode(void *obj, Node *next)
{
   Node *newNode;
   if( (newNode = malloc(sizeof(Node))) )
   {
      newNode->obj = obj;
      newNode->next = next;
      return newNode;
      #ifdef DEBUG
      printf("Creating a node with obj pointer %p pointing to %p\n", newNode->obj, newNode->next);
      #endif
   }
   else return NULL;
}

//Initializes a list variable
//Will return NOTHING on fail
List initList()
{
   //List in case either malloc fails
   List failList = {NULL};
   //Create a dummy node
   Node* dummy;
   if( (dummy = malloc(sizeof(Node))) )
   {
      dummy->obj = NULL;
      dummy->next = NULL;
   }
   else return failList;
   //Create a list with the dummy node as its head
   List createdList;
   createdList.head = dummy;
   return createdList;
}
/* These functions insert the object of the first parameter  
   at the head/tail of the list and returns an error code:  
   0 = success, 1 means there was insufficient memory 
   and the list is not changed. */  
int insertAtHead(void* obj, List listToInsert)
{
   Node *newNode = createNewNode(obj, listToInsert.head->next);
   if( newNode != NULL )
   {
      //Make the new node the head
      listToInsert.head->next = newNode;
      return 0;
   }
   else return 1; 
}
int insertAtTail(void* obj, List listToInsert)
{
   Node *newNode = createNewNode(obj, NULL);
   Node *tail = listToInsert.head;
   if( newNode != NULL )
   {
      while(tail->next != NULL)
         tail = tail->next;
      tail->next = newNode;
      return 0;
   }
   else return 1;
}
 
/* These functions delete and return the object at 
   the head/tail. If list is empty, NULL is returned. */     
void * removeHead(List listToRemove)
{
   Node *removedNode = listToRemove.head->next;
   if( (removedNode != NULL) ){
      void *obj = removedNode->obj;
      listToRemove.head->next = removedNode->next;
      free(removedNode);
      return obj;
   }
   else return NULL;

}
void * removeTail(List listToRemove)
{
   Node *removedNode = listToRemove.head->next;
   if( removedNode != NULL ) //if the list is not empty
   {
      Node *newTail = listToRemove.head;
      while( (removedNode->next != NULL) )
         {
            removedNode = removedNode->next;
            newTail = newTail->next;
         }
      newTail->next = NULL;
      void *obj = removedNode->obj;
      free(removedNode);
      return obj;
   }
   else return NULL;
}


// Frees a List
// NOTE: Will not free any of the objects in the list
void freeList(List list)
{
    Node * currentNode = list.head;
    for(Node * nextNode; currentNode!=NULL; currentNode = nextNode)
    {
        nextNode = currentNode->next;
        free(currentNode->obj);
        free(currentNode);
    }
}
#include "prelab6.h"
#include<assert.h>

int main(void)
{
    int eHandler, *elem,i;
    List *list = initList(&eHandler);
    assert(eHandler ==0);
    for(i = 0; i < 6; i++)
    {
        elem = malloc(sizeof(int));
        *elem = i;
        list = insertAtHead(elem, list, &eHandler);
        assert(eHandler ==0);
        
    }
    List *curNode = list;
    i = 1;
    while(curNode->next != NULL)
    {
        printf("%p -> %p\n",curNode, curNode->next);
        printf("Node %d: %d\n", i, *((int*)getAtIndex(i,list)));
        curNode = curNode ->next;
        i++;
    }
    list = freeList(list);
}
#include "lab7.h"
#include<assert.h>
int main(void)
{
    Node * list = initList();
    assert(list != NULL);
    printf("Dummy Node is Located at %p\n", list);
    int a=1, b=2, c=3, d=4,e=5;
    assert( 0 == insertAtIndex(list, &a, 0));
    insertAtIndex(list, &b, 0);
    insertAtIndex(list, &c, 0);
    insertAtIndex(list, &d, 2);
    insertAtIndex(list, &e, getSize(list));
    printf("Size is %d\n", getSize(list));
    printf("debug %p->%p->%p\n", list, list->next, list->next->next);
    for(int i = 0, *j; i< getSize(list); i++)
    {
        j = getAtIndex(list, i);
        if ( j != NULL )
        {
            printf("Node %d = %d\n", i, *j);
            //free(j);
        }
        else
            puts("removeAtIndex(list,0) returned NULL!\n");
    }
    int size = getSize(list);
    for(int i = 0, *j; i < size; i++)
    {
        j = removeAtTail(list);
        if ( j != NULL )
        {
            printf("%d removed tail = %d\n", i, *j);
            printf("Size is now %d\n", getSize(list));
        }
    }

    freeList(&list);
}

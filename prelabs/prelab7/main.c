#include "prelab7.h"

int main(void)
{
    List list = initList();
    printf("List is Located at %p\nDummy node is Located at %p\n", &list, list.head);
    for(int i = 1, *j; i<=5; i++)
    {
        j = malloc(sizeof(int));
        *j = i;
        insertAtHead(j, list);
    }
    for(int i = 5, *j; i>=1; i--)
    {
        j = malloc(sizeof(int));
        *j = i;
        insertAtTail(j, list);
    }
    for(int i = 1, *j; i<= 5; i++)
    {
        j = removeHead(list);
        if ( j != NULL )
        {
            printf("Node %d = %d\n", i, *j);
            free(j);
        }
        else
            puts("removeHead returned NULL!\n");
    }
    for(int i = 6, *j; i <= 10; i++)
    {
        j = removeTail(list);
        if ( j != NULL )
        {
            printf("Node %d = %d\n", i, *j);
            free(j);
        }
        else
            puts("removeTail returned NULL!\n");
    }
    freeList(list);
}
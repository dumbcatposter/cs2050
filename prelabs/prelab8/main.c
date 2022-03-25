#include "prelab8.h"
#include<assert.h>
int main(void)
{
    int a=1, b=2, c=3, d=4;
    Queue queue = queueInit();
    enqueue(&a, queue);
    assert(getQueueErrorCode(queue) == 0);
    enqueue(&b, queue);
    assert(getQueueErrorCode(queue) == 0);
    enqueue(&c, queue);
    assert(getQueueErrorCode(queue) == 0);
    enqueue(&d, queue);
    printf("Initial queue size: %d\n", getQueueSize(queue));

    for(int i = 1; i<5; i++)
    {
        int *j = dequeue(queue);
        int size = getQueueSize(queue);
        printf("Node %d: %d\nSize is now:%d\n", i, *j, size);
        assert(getQueueErrorCode(queue) == 0);
    }

    freeQueue(queue);
}
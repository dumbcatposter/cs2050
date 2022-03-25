#include "lab8.h"

int main(void)
{
    Queue * myQ;
    myQ = initQueue();
    int a=1,b=2,c=3;
    enQueue(myQ, &a);
    enQueue(myQ, &b);
    enQueue(myQ, &c);
    printf("Peeking: %d\n", *((int*)peek(myQ)));
    for(int i = 1; i < 4; i++)
    {
        printf("Node %d deQueued: %d\n",i, *((int*)deQueue(myQ)));
    }
    freeQueue(myQ);
}
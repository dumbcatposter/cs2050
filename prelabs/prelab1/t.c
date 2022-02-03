#include<stdio.h>
#include<stdlib.h>
#define SEGFAULT 0
#define MEMPEEK 0
#define ZEROSIZEMALLOC 1

int main(void)
{
    #if SEGFAULT
    int *p = NULL;
    printf("%d",*p); 
    /* Segmentation fault*/
    #endif
    #if MEMPEEK
    int n[100];
    for(int i = 0; i < 100; i++)
    {
        printf("n[%02d]=%015d memory location = %p\n", i, *(n+i), n+i);
    }
    #endif
    #if ZEROSIZEMALLOC
    void *p = malloc(0);
    printf("%p\n NULL? %s\n",p, (p==NULL ? "Yes" : "No"));
    free(p);
    #endif
}
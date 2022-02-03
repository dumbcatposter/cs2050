#include "prelab2.h"
#include "printarray.h"

int main(void)
{  
    FILE *fptr = fopen("test.txt", "r");

    int floatArrayLength;
    float * floatArray = readFloatFileIntoArray(fptr, &floatArrayLength);

    if (-1 == floatArrayLength) return -1;

    printFloatArray(floatArray, floatArrayLength);
    fclose(fptr);
    freeFloatArray(&floatArray);

    if(floatArray == NULL) printf("Array freed!\n");
}


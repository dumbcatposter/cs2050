#include "lab2.h"

int main() {
    //Testing code
    FILE *fp = fopen("numbers.txt", "r");
    int size, *array, *result, element, elementFound, elementCorrect;
    //createIntArrayFromFile test
    array = createIntArrayFromFile(fp, &size);
    printf("Array created: %s\n", (array == NULL) ? "Fail": "Pass");
    //lastAddressOf test
    element = 58; // 58 is on line 9 and 18 of numbers.txt, which corresponds to elements 7 and 16 of the array
    elementFound = lastAddressOf(array,size,&result, element);
    if(result == (array+16)) elementCorrect = 1;
    else elementCorrect = 0;
    printf("lastAddressOf: element found: %s, element correct: %s\n", elementFound ? "Fail": "Pass", elementCorrect ? "Pass" : "Fail");
    printf("Element 7 (incorrect): %d, Element 16 (correct): %d\n", *(array+7), array[16]);
    //freeArray test
    freeArray(array);
}


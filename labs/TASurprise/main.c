#include "TASurprise.h"
#include<time.h>



int main() {
    //Setting up variables for time complexity testing
    int size = 1000000;
    int BIG_BIG_ARRAY[size];
    BIG_BIG_ARRAY[0] = size;
    for(int i = 1; i < size; i++)
    {
        BIG_BIG_ARRAY[i] = i-1;
    }
    int *bigArray = BIG_BIG_ARRAY + 1;
    clock_t startTime;
    float timeElapsed;
    int result;
    //Testing binary search
    puts("Timing binary search (Result should be 121902)...");
    startTime = clock();
    const int element = 121902;
    result = ascendingBinarySearch(bigArray, element);
    timeElapsed = (float) (clock() - startTime) / CLOCKS_PER_SEC;
    printf("Time elapsed for binary search (result: %d): %.10f seconds\n", result,timeElapsed);
    puts("Timing linear search (Result should be 121902)...");
    startTime= clock();
    result = linearSearch(bigArray, element);
    timeElapsed = ((float) (clock() - startTime)) / CLOCKS_PER_SEC;
    printf("Time elapsed for linear search (result: %d): %.10f seconds\n", result,timeElapsed);
}

void * createArray(size_t elementSize, int numElements) {
	int *array = malloc(sizeof(int) + elementSize * numElements);

	if(!array) {
		return NULL;
	}

	*array = numElements;

	return ++array;
}

void freeArray(void *array) {
	int *arr = array;
	free(arr - 1);
}

int getSize(int *array) {
	return array[-1];
}

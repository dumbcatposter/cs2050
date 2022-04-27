#include "TASurprise.h"

int recursiveDescendingBinarySearch(int *array, int element, int min, int max) {
    if(max < min) {
        return -1;
    }

    int median = min + (max - min) / 2;

    if(array[median] == element) {
        return median;
    } else if(array[median] < element) {
        max = median - 1;
    } else {
        min = median + 1;
    }

    return recursiveDescendingBinarySearch(array, element, min, max);
}

int isSortedDescending(int *array) {
    int size = getSize(array);

    for(int i = 1; i < size; ++i) {
        if(array[i] > array[i - 1]) {
            return 0;
        }
    }

    return 1;
}

int descendingBinarySearch(int *array, int element) {
    if(!isSortedDescending(array)) {
        return -1;
    }

    return recursiveDescendingBinarySearch(array, element, 0, getSize(array) - 1);
}

int recursiveAscendingBinarySearch(int *array, int element, int min, int max) {
    if(max < min) {
        return -1;
    }

    int median = min + (max - min) / 2;

    if(array[median] == element) {
        return median;
    } else if(array[median] > element) {
        max = median - 1;
    } else {
        min = median + 1;
    }

    return recursiveAscendingBinarySearch(array, element, min, max);
}

int isSortedAscending(int *array) {
    int size = getSize(array);

    for(int i = 1; i < size; ++i) {
        if(array[i] < array[i - 1]) {
            return 0;
        }
    }

    return 1;
}

int ascendingBinarySearch(int *array, int element) {
    if(!isSortedAscending(array)) {
        return -1;
    }

    return recursiveAscendingBinarySearch(array, element, 0, getSize(array) - 1);
}
//Perform a linear search of array <array> for given element <element>
//Returns -1 if element not found
int linearSearch(int *array, int element)
{
    int size = getSize(array);
    for(int i = 0; i < size; i++)
    {
        if(array[i] == element) return i;
    }
    return -1;
}

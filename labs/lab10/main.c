#include "lab10.h"
#include<time.h>

#define PRINT_TO_TERMINAL
//#define PRINT_TO_NULL

int main()
{
    clock_t Timer;
    float timeElapsed;
    int result, element;
    srand(clock());


    puts("Creating BST...");
    Timer = clock();
    BST *bst = initBST();
    timeElapsed = (float) (clock() - Timer) / CLOCKS_PER_SEC;
    printf("Creating BST took %f seconds\n", timeElapsed);

    puts("Inserting one million random elements into the BST...");
    Timer = clock();
    for(int i = 0; i < 1000000; i++)
    {
        element = rand() % 20000002;
        insertBST(bst, element);
    }
    timeElapsed = (float) (clock() - Timer) / CLOCKS_PER_SEC;
    printf("Inserting elements took %f seconds.\n", timeElapsed);

    puts("Searching for an element in the tree, and one not in the tree...");
    Timer = clock();
    result = BSTContains(bst, element);
    printf("Search %s\n", result ? "Passed (expected)" : "Failed (uh-oh!)");
    result = BSTContains(bst, 20000003);
    printf("Search %s\n", result ? "Passed (uh-oh)" : "Failed (expected)");
    timeElapsed = (float) (clock() - Timer) / CLOCKS_PER_SEC;
    printf("Searching took %f seconds.\n", timeElapsed);

    puts("Printing all elements of the tree in sorted order...");
    Timer = clock();
#ifdef PRINT_TO_TERMINAL
    printInOrder(bst);
#endif
#ifdef PRINT_TO_NULL
    puts("(Printing to null instead...)");
    FILE *null;
    null = fopen("/dev/null", "w");
    printInOrderToFile(bst, null);
    fclose(null);
#endif
    timeElapsed = (float) (clock() - Timer) / CLOCKS_PER_SEC;
    printf("Printing took %f seconds.\n", timeElapsed);

    puts("Finding the minimum element in the tree...");
    Timer = clock();
    result = getMin(bst);
    timeElapsed = (float) (clock() - Timer) / CLOCKS_PER_SEC;
    printf("Search done. Result: %d in %f seconds.\n", result, timeElapsed);

    puts("Freeing tree...");
    Timer = clock();
    freeTree(bst);
    timeElapsed = (float) (clock() - Timer) / CLOCKS_PER_SEC;
    printf("Tree freed in %f seconds.\n", timeElapsed);

    return 0;
}


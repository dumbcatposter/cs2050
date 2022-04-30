#include "lab10.h"

// suggested implementation
typedef struct Node Node;

typedef struct AList{
    int *array;
    int *index;
} ArrayList;

struct Node {
	int obj;
	Node *left;
	Node *right;
};

typedef struct BST {
	Node *root;
	int size;
} BST;

// O(1)
// Returns a pointer to an empty BST, or NULL if out of memory
BST * initBST()
{
    BST *bst = malloc(sizeof(BST));
    if(bst == NULL) return NULL;
    bst->root = NULL;
    bst->size = 0;
    return bst;
}
// O(log(n))
// Insert the integer <data> into the BST <tree>
// Returns 0 on success, 1 on failure
int insertBST(BST *tree, int data)
{
    if(tree == NULL) {return 1;}
    // Create a new node for the Employee to sit in the SSN Tree
    Node *node = malloc(sizeof(Node));
    if(node == NULL) {return 1;}
    node->obj = data;
    node->left = NULL;
    node->right = NULL;
    // Insert into SSN Tree
    if(tree->root == NULL) tree->root = node;
    else {
        // "top" will eventually refer to the point where our new Node should be
        // "attachPoint" is where the Node will attach to the rest of the tree
        Node *top = tree->root;
        Node *attachPoint = top;
        while (top != NULL) {
            attachPoint = top;
            if (data < top->obj) top = top->left;
            else top = top->right;
        }
        if (data < attachPoint->obj) {
            attachPoint->left = node;
        } else {
            attachPoint->right = node;
        }
    }
    tree->size++;
    return 0;
}
int recursiveBinSearch(int key, Node *Tree)
{
    /*
     * 1. Compare key to the obj in Tree using subtraction
     * 2. If key == obj, return obj
     * 3. If key > obj, go left
     * 4. If key < obj, go right
     */

    //Error checking section
    if( Tree == NULL)
    {
        return 0;
    }

    int cmp = 0;    // Keys are the same
    int diff = Tree->obj - key;
    if(diff > 0) { cmp = -1; }// Value in node < key value
    else if (diff < 0 ){ cmp = 1; } // Value in node > key value

    switch(cmp)
    {
        case -1:
            if(Tree->left == NULL)
            {
                return 0;
            }
            return recursiveBinSearch(key, Tree->left);
        case 0:
            return 1;
        case 1:
            if(Tree->right == NULL)
            {
                return 0;
            }
            return recursiveBinSearch(key, Tree->right);
        default:
            return 0;
    }
}
// O(log(n))
// Returns 1 if the given number <data> exists in tree <tree>, 0 if otherwise
int BSTContains(BST *tree, int data)
{
    return recursiveBinSearch(data, tree->root);
}

// Prints the contents of an integer array, and then a new line
void printIntArrayToFile(int*array, int size, FILE *fp){
    if(size > 1000)
    {
        puts("Absolutely huge array. Truncating to first and last 10 ints.");
        for(int i = 0; i < 10; i++)
        {
            fprintf(fp, "%d, ", array[i]);
        }
        fprintf(fp,"... ,");
        for(int i = size-10; i < size; i++)
        {
            fprintf(fp, "%d, ", array[i]);
        }
        fprintf(fp, "\n");
        return;
    }
    for(int i = 0; i < size; i++)
    {
        fprintf(fp, "%d, ", array[i]);
    }
    fprintf(fp,"\n");
}

//flattens a binary search tree
void flattenBST(Node *node, ArrayList arrayList)
{
    if(node == NULL){return;}
    flattenBST(node->left, arrayList);
    *(arrayList.array + *(arrayList.index)) = node->obj;
    *(arrayList.index) += 1;
    flattenBST(node->right, arrayList);

}


void printInOrderToFile(BST *tree, FILE *fp)
{
    if(tree == NULL) {return;}
    if(tree->size <= 0) {return;}
    int *flattenedTree = malloc(sizeof(int)*tree->size);
    int *index = malloc(sizeof(int));
    *index = 0;
    if(flattenedTree == NULL) {return;}
    ArrayList arrayList = {flattenedTree, index};
    flattenBST(tree->root, arrayList);
    printIntArrayToFile(arrayList.array, tree->size, fp);
    free(index);
    free(flattenedTree);
}
// O(n)
// Prints all the elements of BST <tree> in sorted order
void printInOrder(BST *tree)
{
    printInOrderToFile(tree, stdout);
}

// O(log(n))
// Returns the minimum element in BST <tree>
int getMin(BST *tree)
{
    int *flattenedTree = malloc(sizeof(int)*tree->size);
    int *index = malloc(sizeof(int));
    *index = 0;
    ArrayList arrayList = {flattenedTree, index};
    flattenBST(tree->root, arrayList);
    int min = arrayList.array[0];
    free(index);
    free(flattenedTree);
    return min;
}
void freeNodes(Node *t)
{
    if (t == NULL) return;
    freeNodes(t->left);
    freeNodes(t->right);
    free(t);
}
// Frees a BST <tree>
void freeTree(BST *tree)
{
    freeNodes(tree->root);
    free(tree);
}


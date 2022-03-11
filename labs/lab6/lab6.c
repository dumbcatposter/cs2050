#include "lab6.h"

//Initializes a list and returns a pointer to it
Node * initList()
{
    //We do not use placeholder nodes, so this just returns NULL
    return NULL;
}

//Returns the size of the list
int getSize(Node *list)
{
    Node *curNode = list;
    int length =0;
    //Increment length for every non-NULL node
    while(curNode != NULL)
    {
        length++;
        curNode = curNode->next;
    }
    return length;
}

//Inserts a pointer <data> at the head of the list
//Returns 0 on success, 1 on failure
int insertAtHead(Node **list , void *data)
{
    //Create a node
    Node *node = malloc(sizeof(Node));
    if(NULL==node) return 1;
    //Populate the node with the user's data and a pointer to the next node
    node->data = data;
    node->next = *list; // list == Node**, *list == Node*
    //Move the head of the list
    *list = node; // node == Node*, &node == Node**
    return 0;
}

//Returns the first element of the list, removing it in the process
void * removeFromHead(Node **list)
{
    if(*list==NULL) return NULL; //If the list is empty, return NULL
    //Prepare a holding spot for the node in question and its value
    Node *head = *list;
    void * returnValue;
    //Move the list pointer to remove the head
    *list = (*list)->next;
    //Free the struct we removed from the list to prevent memory leak
    returnValue = head->data;
    free(head->data);
    free(head);
    return returnValue;
}

//Frees the list and makes it NULL so you won't accidentally try to use it after free
void freeList(Node **list)
{
    Node *curNode = *list;
    if(NULL == curNode)  return; // List is already freed
    do{
        //Free whatever is inside the node
        //My thinking is that if you're using a data structure like this, you're certainly not going to be using static memory, you're going to be dynamically allocating it
        free(curNode->data);
        //Move our node pointer ahead one
        curNode = curNode->next;
        //Free the node itself
        free(*list);
        //Move the head of the list
        *list = curNode;
    } while(curNode != NULL);
    *list = NULL;
}
//[Copied from Lab 5]
//Getters 
//All return -1 on error
int getVin(Car *car)
{
    if(NULL == car) return -1;
    return car->vin;
}
float getMilesDriven(Car *car)
{
    if(NULL == car) return -1;
    return car->milesDriven;
}
int getNumberOfAccidents(Car *car)
{
    if(NULL == car) return -1;
    return car->numberOfAccidents;
}

//Returns a pointer to the Car struct in list <list> with the least Miles Driven, or NULL on error
Car * getWithLeastMilesDriven(Node *list)
{
    //Check array
    if(NULL == list) return NULL;
    //Iterate through the linked list with a for loop
    Node *returnCar = list;
    for(Node * iCar = list; iCar->next != NULL; iCar = iCar->next)
    {
        //If the current car's miles driven is less than the current candidate for returning, update the candidate
        if(getMilesDriven(iCar->data) < getMilesDriven(returnCar->data))
        {
            returnCar = iCar;
        }
    }
    return returnCar->data;
}

//Prints all of the data for each car in the linked list on one line
void printCars(Node *list)
{
    Car * car;
    //Iterate through each car in the linked list
    for(Node * iCar = list; iCar != NULL; iCar = iCar->next)
    {
        //Print each car with getter functions from Lab 5
        car = iCar->data;
        printf("Car VIN:%d\tMiles Driven:%f\tNumber of Accidents:%d\n", 
        getVin(car), getMilesDriven(car),getNumberOfAccidents(car));
    }
}
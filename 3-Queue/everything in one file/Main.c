#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *first;
    Node *last;
} Queue;

void Enqueue(Queue *queue, int value);
int Dequeue(Queue *queue);
bool QUEUE_IsEmpty(Queue queue);
void QUEUE_Display(Queue *queue);
void QUEUE_AddToBegining(Queue *queue, int value);
void QUEUE_AddToEnding(Queue *queue, int value);
int QUEUE_DeleteFromBegining(Queue *queue);
int QUEUE_DeleteFromEnding(Queue *queue);
void QUEUE_SortAsc(Queue *queue);
void QUEUE_SortDesc(Queue *queue);
void QUEUE_Reverse(Queue *queue);
void QUEUE_RemoveDuplicated(Queue *queue);
int QUEUE_size(Queue *queue);
int QUEUE_sum(Queue *queue);

int main(int argc, char **argv)
{
    system("cls");
    Queue queue = {NULL, NULL};

    Enqueue(&queue, 10);
    Enqueue(&queue, 10);
    Enqueue(&queue, 12);
    Enqueue(&queue, 10);
    Enqueue(&queue, 12);

    // QUEUE_Display(&queue);

    QUEUE_AddToBegining(&queue, 10);
    QUEUE_AddToEnding(&queue, 12);
    // printf("%d   ", QUEUE_sum(&queue));
    // QUEUE_RemoveDuplicated(&queue);
    // printf("%d   ", QUEUE_sum(&queue));

    QUEUE_SortAsc(&queue);
    QUEUE_Display(&queue);
    QUEUE_Reverse(&queue);
    // QUEUE_SortDesc(&queue);

    // QUEUE_DeleteFromBegining(&queue);
    // QUEUE_DeleteFromEnding(&queue);

    QUEUE_Display(&queue);
    printf("size : %d\n", QUEUE_size(&queue));
    return 0;
}

// insert a new node with data=value at the tail of the queue
// this function will be used by the rest of functions
void Enqueue(Queue *queue, int value)
{
    // create a new node (new) with data=value and insert it at the very end (tail) of the queue
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;

    if (queue->first == NULL)
    {
        queue->first = new;
        queue->last = new;
    }
    else
    {
        queue->last->next = new;
        queue->last = new;
    }
}

// get the data of the node thats on top (the head) of the queue and delete it
// this function will be used by the rest of functions
int Dequeue(Queue *queue)
{
    // if the stack is empty then return the value 0
    // else delete the first element (the head) and return its value
    if (queue->first != NULL)
    {
        Node *toDelete = queue->first;
        int dataToReturn = toDelete->data;
        queue->first = toDelete->next;
        free(toDelete);
        return dataToReturn;
    }
    else
    {
        return 0;
    }
}

// this function tests if the queue is empty or not
bool QUEUE_IsEmpty(Queue Queue)
{
    // it returns true if the queue is empty, else it returns false
    return (Queue.first == NULL);
}

// Display the content of the Queue (queue)
// using this format %d-->%d--->...%d--->NULL
void QUEUE_Display(Queue *queue)
{
    // dequeue all elements of the queue element by element and enqueue them in a temporary queue, everytime we dequeue an element wwe print it
    // in the end we put all elements back to the queue and print NULL
    Queue tempQueue = {NULL, NULL};

    while (!QUEUE_IsEmpty(*queue))
    {
        int data = Dequeue(queue);
        printf("%d-->", data);
        Enqueue(&tempQueue, data);
    }
    printf("NULL\n");

    while (!QUEUE_IsEmpty(tempQueue))
    {
        Enqueue(queue, Dequeue(&tempQueue));
    }
}

// insert a new node with data=value at the top (head) of the stack
void QUEUE_AddToBegining(Queue *queue, int value)
{
    // create a temporary queue that and put in it the new element we want to add then follow it with the rest of elements from the main queue , then put everything back to the main queue
    Queue tempQueue = {NULL, NULL};
    Enqueue(&tempQueue, value);

    while (!QUEUE_IsEmpty(*queue))
    {
        Enqueue(&tempQueue, Dequeue(queue));
    }
    while (!QUEUE_IsEmpty(tempQueue))
    {
        Enqueue(queue, Dequeue(&tempQueue));
    }
}

// this function inserts a new node with data=value at to bottom (end) of the queue (the tail)
void QUEUE_AddToEnding(Queue *queue, int value)
{
    // just call Enqueue because it does the same functionality
    Enqueue(queue, value);
}

// get the data of the node thats on top of the queue (the heaed) and delete it
int QUEUE_DeleteFromBegining(Queue *queue)
{
    // just call Dequeue because it does the same functionality
    return Dequeue(queue);
}

// this functions gets data in and deletes the node thats in the bottom of the queue (the tail)
int QUEUE_DeleteFromEnding(Queue *queue)
{
    // moving all items from the main queue to a temporary queue and calculate the size of the main queue
    // put back all elements to the main queue and leave the last (using the size so "size - 1")
    // delete the node that is left
    int size = 0;
    Queue tempQueue = {NULL, NULL};
    while (!QUEUE_IsEmpty(*queue))
    {
        Enqueue(&tempQueue, Dequeue(queue));
        size++;
    }
    for (int i = 0; i < size - 1; i++)
    {
        Enqueue(queue, Dequeue(&tempQueue));
    }
    int data = Dequeue(&tempQueue);
    return data;
}

// this function arranges the data of queue in ascending order
void QUEUE_SortAsc(Queue *queue)
{
    // dequeue one by ne all elements of the main queue and put them in a temp queue
    // everytime we dequeue we test if the value is the minimum in this queue
    // after knowing what the min is, we put back all elements in the main queue, but we keep one item with data=min and put it in another temp queue (this would be the final result)
    // we repeat this process till the main queue wents empty and the second temp queue is full of sorted elements
    // we put back all elements from 2nd temp queue to main queue
    Queue tempQueue1 = {NULL, NULL};
    Queue tempQueue2 = {NULL, NULL};
    int min;
    while (!QUEUE_IsEmpty(*queue))
    {
        min = Dequeue(queue);
        Enqueue(queue, min);
        while (!QUEUE_IsEmpty(*queue))
        {
            int data = Dequeue(queue);
            if (data < min)
            {
                min = data;
            }
            Enqueue(&tempQueue1, data);
        }
        bool recherche = true;
        while (!QUEUE_IsEmpty(tempQueue1))
        {
            int data = Dequeue(&tempQueue1);
            if ((data == min) && (recherche))
            {
                recherche = false;
                Enqueue(&tempQueue2, data);
            }
            else
            {
                Enqueue(queue, data);
            }
        }
    }
    while (!QUEUE_IsEmpty(tempQueue2))
    {
        Enqueue(queue, Dequeue(&tempQueue2));
    }
}

// this function arranges the data of queue in descending order
void QUEUE_SortDesc(Queue *queue)
{
    // dequeue one by ne all elements of the main queue and put them in a temp queue
    // everytime we dequeue we test if the value is the maximaum in this queue
    // after knowing what the max is, we put back all elements in the main queue, but we keep one item with data=max and put it in another temp queue (this would be the final result)
    // we repeat this process till the main queue wents empty and the second temp queue is full of sorted elements
    // we put back all elements from 2nd temp queue to main queue
    Queue tempQueue1 = {NULL, NULL};
    Queue tempQueue2 = {NULL, NULL};
    int max;
    while (!QUEUE_IsEmpty(*queue))
    {
        max = Dequeue(queue);
        Enqueue(queue, max);
        while (!QUEUE_IsEmpty(*queue))
        {
            int data = Dequeue(queue);
            if (data > max)
            {
                max = data;
            }
            Enqueue(&tempQueue1, data);
        }
        bool recherche = true;
        while (!QUEUE_IsEmpty(tempQueue1))
        {
            int data = Dequeue(&tempQueue1);
            if ((data == max) && (recherche))
            {
                recherche = false;
                Enqueue(&tempQueue2, data);
            }
            else
            {
                Enqueue(queue, data);
            }
        }
    }
    while (!QUEUE_IsEmpty(tempQueue2))
    {
        Enqueue(queue, Dequeue(&tempQueue2));
    }
}

// this function reverses the content of the queue
void QUEUE_Reverse(Queue *queue)
{
    // move all elements from the main queue to a temporary queue, but we need to insert those element one by one at the begining of the temp queue
    // once we do that we have the queue reversed in the temp queue, now we put it back to the main queue.
    Queue tempQueue = {NULL, NULL};

    while (!QUEUE_IsEmpty(*queue))
    {
        QUEUE_AddToBegining(&tempQueue, Dequeue(queue));
    }
    while (!QUEUE_IsEmpty(tempQueue))
    {
        Enqueue(queue, Dequeue(&tempQueue));
    }
}

// this function removes duplicate elements of the queue
void QUEUE_RemoveDuplicated(Queue *queue)
{
    // for each element of the main queue put it in the tempqueue2 and ignore its duplicates (delete them)
    // we use the main queue and tempqueue1 to dequeue and Enqueue data throught out to be able to test it
    // in the end we will have tempqueue2 with all elements that are not duplicated, and the main queue wiil be empty, now we put back all data from temp 2 to the main queue
    // and now we have removed all duplicated values of the queue
    Queue tempQueue1 = {NULL, NULL};
    Queue tempQueue2 = {NULL, NULL};
    while (!QUEUE_IsEmpty(*queue))
    {
        int dataToKeep = Dequeue(queue);
        Enqueue(&tempQueue2, dataToKeep);

        while (!QUEUE_IsEmpty(*queue))
        {
            int dataToTest = Dequeue(queue);
            if (dataToTest != dataToKeep)
            {
                Enqueue(&tempQueue1, dataToTest);
            }
        }
        while (!QUEUE_IsEmpty(tempQueue1))
        {
            Enqueue(queue, Dequeue(&tempQueue1));
        }
    }
    while (!QUEUE_IsEmpty(tempQueue2))
    {
        Enqueue(queue, Dequeue(&tempQueue2));
    }
}

// this returns the size of the queue
int QUEUE_size(Queue *queue)
{
    // dequeue all elements of the main queue one by one and Enqueue them in a temp queue
    // everytime we dequeue we increment a counter of the size
    // put back all elements in the main queue and return the size
    int size = 0;
    Queue tempQueue = {NULL, NULL};
    while (!QUEUE_IsEmpty(*queue))
    {
        Enqueue(&tempQueue, Dequeue(queue));
        size++;
    }
    while (!QUEUE_IsEmpty(tempQueue))
    {
        Enqueue(queue, Dequeue(&tempQueue));
    }
    return size;
}

// this returns the sum of the elements of the queue
int QUEUE_sum(Queue *queue)
{
    // dequeue all elements of the main queue one by one and enqueue them in a temp queue
    // everytime we dequeue we add the value of the dequeueped element to a variable sum
    // put back all elements in the main queue and return the sum
    int sum = 0;
    Queue tempQueue = {NULL, NULL};
    while (!QUEUE_IsEmpty(*queue))
    {
        int data = Dequeue(queue);
        sum += data;
        Enqueue(&tempQueue, data);
    }
    while (!QUEUE_IsEmpty(tempQueue))
    {
        Enqueue(queue, Dequeue(&tempQueue));
    }
    return sum;
}
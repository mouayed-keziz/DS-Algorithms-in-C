#include <stdbool.h>
#ifndef __QUEUE__H__
#define __QUEUE__H__

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

#endif
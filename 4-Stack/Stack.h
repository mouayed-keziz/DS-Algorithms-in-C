#include <stdbool.h>
#ifndef __STACK__H__
#define __STACK__H__

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *first;
} Stack;

void Push(Stack *stack, int value);
int Pop(Stack *stack);
bool STACK_IsEmpty(Stack stack);
void STACK_Display(Stack *stack);
void STACK_AddToBegining(Stack *stack, int value);
void STACK_AddToEnding(Stack *stack, int value);
int STACK_DeleteFromBegining(Stack *stack);
int STACK_DeleteFromEnding(Stack *stack);
void STACK_SortAsc(Stack *stack);
void STACK_SortDesc(Stack *stack);
void STACK_Reverse(Stack *stack);
void STACK_RemoveDuplicated(Stack *stack);
int STACK_size(Stack *stack);
int STACK_sum(Stack *stack);

#endif
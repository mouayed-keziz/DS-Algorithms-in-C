#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void main(int argc, char *argv[])
{
    Stack stack;
    stack.first = NULL;
    Push(&stack, 10);
    Push(&stack, 10);
    Push(&stack, 11);
    Push(&stack, 10);
    Push(&stack, 12);
    Push(&stack, 12);
    Push(&stack, 10);
    Push(&stack, 12);
    STACK_AddToEnding(&stack, 13);
    // printf("%d\n", Pop(&stack));
    // printf("%d\n", STACK_DeleteFromBegining(&stack));
    STACK_Display(&stack);
    STACK_RemoveDuplicated(&stack);
    // STACK_SortDesc(&stack);
    // STACK_Reverse(&stack);
    // printf("%d\n", STACK_sum(&stack));
    STACK_Display(&stack);
}

// insert a new node with data=value at the top of the stack
// this function will be used by the rest of functions
void Push(Stack *stack, int value)
{
    // create a new node (new) with data=value and insert it at the beggining (the top)
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->next = stack->first;
    stack->first = new;
}

// get the data of the node thats on top of the stack and delete it
// this function will be used by the rest of functions
int Pop(Stack *stack)
{
    // if the stack is empty then return the value 0
    // else delete the first element (which is on top) and return its value
    if (STACK_IsEmpty(*stack))
    {
        return 0;
    }
    else
    {
        Node *toDelete = stack->first;
        stack->first = stack->first->next;
        int dataToReturn = toDelete->data;
        free(toDelete);
        return dataToReturn;
    }
}

// this function tests if the stack is empty or not
bool STACK_IsEmpty(Stack stack)
{
    // it returns true if the stack is empty, else it returns false
    return (stack.first == NULL);
}

// Display the content of the Stack (stack)
// using this format %d-->%d--->...%d--->NULL
void STACK_Display(Stack *stack)
{
    // pop all elements of the stack element by element and push them in a temporary stack, everytime we pop an element wwe print it
    // in the end we put all elements back to the stack and print NULL
    Stack tempStack;
    tempStack.first = NULL;
    while (!STACK_IsEmpty(*stack))
    {
        int data = Pop(stack);
        printf("%d-->", data);
        Push(&tempStack, data);
    }
    printf("NULL\n");
    while (!STACK_IsEmpty(tempStack))
    {
        Push(stack, Pop(&tempStack));
    }
}

// insert a new node with data=value at the top of the stack
void STACK_AddToBegining(Stack *stack, int value)
{
    // just call Push because it does the same functionality
    Push(stack, value);
}

// this function inserts a new node with data=value at to bottom of the stack
void STACK_AddToEnding(Stack *stack, int value)
{
    // pop all elements of the stack and push them in a temporary stack one by one
    // push the new element in the main stack
    // push the rest of the elements (from the temporary stack) to the main stack
    Stack tempStack;
    tempStack.first = NULL;

    while (!STACK_IsEmpty(*stack))
    {
        Push(&tempStack, Pop(stack));
    }

    Push(stack, value);

    while (!STACK_IsEmpty(tempStack))
    {
        Push(stack, Pop(&tempStack));
    }
}

// get the data of the node thats on top of the stack and delete it
int STACK_DeleteFromBegining(Stack *stack)
{
    // just call pop because it does the same functionality
    return Pop(stack);
}

// this functions gets data in and deletes the node thats in the bottom of the stack
int STACK_DeleteFromEnding(Stack *stack)
{
    // pop all elements and push them in a temporary stack
    // pop the first element(whicih is on top) of the temp stack
    // this element was the last in the main stack and the first in temp stack (this is the node we want to delete)
    // after poping it from the temp stack we pop the rest and push them in the main stack, so all elements are back but not the one in the bottom
    // now we can return it
    Stack tempStack;
    tempStack.first = NULL;

    while (!STACK_IsEmpty(*stack))
    {
        Push(&tempStack, Pop(stack));
    }

    int dataToReturn = Pop(&tempStack);

    while (!STACK_IsEmpty(tempStack))
    {
        Push(stack, Pop(&tempStack));
    }

    return dataToReturn;
}

// this function arranges the data of stack in ascending order
void STACK_SortAsc(Stack *stack)
{
    // pop one by ne all elements of the main stack and put them in a temp stack
    // everytime we pop we test if the value is the minimum in this stack
    // after knowing what the min is, we put back all elements in the main stack, but we keep one item with data=min and put it in another temp stack (this would be the final result)
    // we repeat this process till the main stack wents empty and the second temp stack is full of sorted elements
    // we put back all elements from 2nd temp stack to main stack
    Stack tempStack1;
    Stack tempStack2;
    tempStack1.first = NULL;
    tempStack2.first = NULL;
    int min;
    while (!STACK_IsEmpty(*stack))
    {
        min = Pop(stack);
        Push(stack, min);
        while (!STACK_IsEmpty(*stack))
        {
            int data = Pop(stack);
            if (data < min)
            {
                min = data;
            }
            Push(&tempStack1, data);
        }
        bool recherche = true;
        while (!STACK_IsEmpty(tempStack1))
        {
            int data = Pop(&tempStack1);
            if ((data == min) && (recherche))
            {
                recherche = false;
                Push(&tempStack2, data);
            }
            else
            {
                Push(stack, data);
            }
        }
    }
    while (!STACK_IsEmpty(tempStack2))
    {
        Push(stack, Pop(&tempStack2));
    }
}

// this function arranges the data of stack in descending order
void STACK_SortDesc(Stack *stack)
{
    // pop one by ne all elements of the main stack and put them in a temp stack
    // everytime we pop we test if the value is the maximaum in this stack
    // after knowing what the max is, we put back all elements in the main stack, but we keep one item with data=max and put it in another temp stack (this would be the final result)
    // we repeat this process till the main stack wents empty and the second temp stack is full of sorted elements
    // we put back all elements from 2nd temp stack to main stack
    Stack tempStack1;
    Stack tempStack2;
    tempStack1.first = NULL;
    tempStack2.first = NULL;
    int max;
    while (!STACK_IsEmpty(*stack))
    {
        max = Pop(stack);
        Push(stack, max);
        while (!STACK_IsEmpty(*stack))
        {
            int data = Pop(stack);
            if (data > max)
            {
                max = data;
            }
            Push(&tempStack1, data);
        }
        bool recherche = true;
        while (!STACK_IsEmpty(tempStack1))
        {
            int data = Pop(&tempStack1);
            if ((data == max) && (recherche))
            {
                recherche = false;
                Push(&tempStack2, data);
            }
            else
            {
                Push(stack, data);
            }
        }
    }
    while (!STACK_IsEmpty(tempStack2))
    {
        Push(stack, Pop(&tempStack2));
    }
}

// this function reverses the content of the stack
void STACK_Reverse(Stack *stack)
{
    // when poping all elements and pushing them in a temp stack, the order is reversed
    // but when poping them again from temp stack and pushing them to the main one
    // they'r reversed again so nothing happend
    // so to be able to reverse a stack we need the main stack and 2 temp stacks
    // pop everything from main to temp1   (data is reversed)
    // pop everything from temp1 to temp2 (data is back to its init state)
    // pop everything frmo temp2 to main (data is reversed)
    // so the data is reversed!
    Stack tempStack1;
    Stack tempStack2;
    tempStack1.first = NULL;
    tempStack2.first = NULL;
    while (!STACK_IsEmpty(*stack))
        Push(&tempStack1, Pop(stack));
    while (!STACK_IsEmpty(tempStack1))
        Push(&tempStack2, Pop(&tempStack1));
    while (!STACK_IsEmpty(tempStack2))
        Push(stack, Pop(&tempStack2));
}

// this function removes duplicate elements of the stack
void STACK_RemoveDuplicated(Stack *stack)
{
    // for each element of the main stack put it in the tempstack2 and ignore its duplicates (delete them)
    // we use the main stack and tempstack1 to pop and push data throught out to be able to test it
    // in the end we will have tempstack2 with all elements that are not duplicated, and the main stack wiil be empty, now we put back all data from temp 2 to the main stack
    // and now we have removed all duplicated values of the stack
    Stack tempStack1;
    Stack tempStack2;
    tempStack1.first = NULL;
    tempStack2.first = NULL;
    while (!STACK_IsEmpty(*stack))
    {
        int dataToKeep = Pop(stack);
        Push(&tempStack2, dataToKeep);

        while (!STACK_IsEmpty(*stack))
        {
            int dataToTest = Pop(stack);
            if (dataToTest != dataToKeep)
            {
                Push(&tempStack1, dataToTest);
            }
        }
        while (!STACK_IsEmpty(tempStack1))
        {
            Push(stack, Pop(&tempStack1));
        }
    }
    while (!STACK_IsEmpty(tempStack2))
    {
        Push(stack, Pop(&tempStack2));
    }
}

// this returns the size of the stack
int STACK_size(Stack *stack)
{
    // pop all elements of the main stack one by one and push them in a temp stack
    // everytime we pop we increment a counter of the size
    // put back all elements in the main stack and return the size
    int size = 0;
    Stack tempStack;
    tempStack.first = NULL;
    while (!STACK_IsEmpty(*stack))
    {
        size++;
        Push(&tempStack, Pop(stack));
    }
    while (!STACK_IsEmpty(tempStack))
    {
        Push(stack, Pop(&tempStack));
    }
    return size;
}

// this returns the sum of the elements of the stack
int STACK_sum(Stack *stack)
{
    // pop all elements of the main stack one by one and push them in a temp stack
    // everytime we pop we add the value of the popped element to a variable sum
    // put back all elements in the main stack and return the sum
    int sum = 0;
    Stack tempStack;
    tempStack.first = NULL;
    while (!STACK_IsEmpty(*stack))
    {
        int data = Pop(stack);
        sum += data;
        Push(&tempStack, data);
    }
    while (!STACK_IsEmpty(tempStack))
    {
        Push(stack, Pop(&tempStack));
    }
    return sum;
}
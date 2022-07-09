#include <stdio.h>
#include "Stack.h"

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
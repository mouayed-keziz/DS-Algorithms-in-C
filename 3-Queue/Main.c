#include <stdio.h>
#include "Queue.h"

int main(int argc, char **argv)
{
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
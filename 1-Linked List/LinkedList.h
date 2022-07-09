#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void swap(int *x, int *y);
void LLC_Display(Node *root);
void LLC_AddToBegining(Node **root, int value);
void LLC_AddToEnding(Node **root, int value);
void LLC_DeleteFromBegining(Node **root);
void LLC_DeleteFromEnding(Node **root);
void LLC_SortAsc(Node **root);
void LLC_SortDesc(Node **root);
void LLC_Reverse(Node **root);
void LLC_RemoveDuplicated(Node **root);
int LLC_size(Node *root);
int LLC_sum(Node *root);

#endif

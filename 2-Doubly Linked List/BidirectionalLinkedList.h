#ifndef __B_LINKEDLIST__H__
#define __B_LINKEDLIST__H__

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
} Node;

void swap(int *x, int *y);
void LLDC_Display(Node *root);
void LLDC_AddToBegining(Node **root, int value);
void LLDC_AddToEnding(Node **root, int value);
void LLDC_DeleteFromBegining(Node **root);
void LLDC_DeleteFromEnding(Node **root);
void LLDC_SortAsc(Node **root);
void LLDC_SortDesc(Node **root);
void LLDC_Reverse(Node **root);
void LLDC_RemoveDuplicated(Node **root);
int LLDC_size(Node *root);
int LLDC_sum(Node *root);

#endif

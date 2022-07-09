#include <stdio.h>
#include "BidirectionalLinkedList.h"

int main(int argc, char *argv[])
{
    Node *root = NULL;

    LLDC_AddToBegining(&root, 1);
    LLDC_AddToEnding(&root, 12);
    LLDC_AddToEnding(&root, 21);
    LLDC_AddToBegining(&root, 21);
    LLDC_AddToBegining(&root, 12);
    LLDC_AddToBegining(&root, 11);
    LLDC_AddToBegining(&root, 12);
    LLDC_Display(root);
    LLDC_Reverse(&root);
    LLDC_Display(root);
    printf("size of list : %d\nsome of list %d\n", LLDC_size(root), LLDC_sum(root));
}

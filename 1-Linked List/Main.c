#include <stdio.h>
#include "LinkedList.h"

void main(int argc, char *argv[])
{
    Node *root = NULL;
    LLC_AddToBegining(&root, 21);
    LLC_AddToBegining(&root, 43);
    LLC_AddToBegining(&root, 41);
    LLC_AddToBegining(&root, 21);
    LLC_AddToBegining(&root, 12);
    LLC_AddToBegining(&root, 11);
    LLC_AddToBegining(&root, 12);
    LLC_Display(root);
    LLC_RemoveDuplicated(&root);
    LLC_Display(root);
    printf("some of list %d\n", LLC_sum(root));
}

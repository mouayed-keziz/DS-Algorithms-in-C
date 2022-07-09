#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
} Node;

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

void swap(int *x, int *y);

// this swaps two variable using a temporary variable
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

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

// Display the content of the linked list (root)
// using this format %d-->%d--->...%d--->NULL
void LLDC_Display(Node *root)
{
    // edurate through the linked list with a temporary pointer
    // printing the data stored in every node every eduration
    // printing NULL at the end of the process
    Node *temp = root;
    while (temp != NULL)
    {
        printf("%d--->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// insert a new node with the data (value)
// at the begining of the linked list (root)
void LLDC_AddToBegining(Node **root, int value)
{
    // create a pointer to a node with data = value
    // the pointer to the next node has to point to the root
    // the pointer to the previous node has to point to nothing
    // the root's previous point has to point to the new node
    // so the root becomes second node
    // and the new node becomes the first node (root)
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->next = *root;
    new->previous = NULL;

    if (*root != NULL)
        (*root)->previous = new;

    *root = new;
}

// insert a new node with the data (value)
// at the ending of the linked list (root)
void LLDC_AddToEnding(Node **root, int value)
{
    // create a pointer to a node with data = value
    // the pointer to the next node has to be null
    // the pointer to the previous node has to be null
    // if our linked list is empty .. the list is going
    // to contain just one node which is the new node
    // if our linked list is not empty we edurate through
    // its nodes till the last one using a temprorary node
    // we link the last node with the new node so the new
    // node becomes the last node
    Node *new = malloc(sizeof(Node));
    new->next = NULL;
    new->previous = NULL;
    new->data = value;

    if (*root == NULL)
        *root = new;
    else
    {
        Node *temp = *root;
        while (temp->next != NULL)
            temp = temp->next;
        new->previous = temp;
        temp->next = new;
    }
}

// delete the first node in the linked list (root)
void LLDC_DeleteFromBegining(Node **root)
{
    // if our linked list is empty we do nothing..else
    // we point to the first node with toDelete pointer
    // the root has to becomes the second node of the list
    // delete the first node (*toDelete)
    // so the new list starts from the second node
    if (*root != NULL)
    {
        Node *toDelete = *root;
        *root = (*root)->next;
        if (*root != NULL)
            (*root)->previous = NULL;
        free(toDelete);
    }
}

// delete the last node in the lisked list (root)
void LLDC_DeleteFromEnding(Node **root)
{
    // if our linked list is empty we do nothing..else
    // if it has just 1 node we use (DeleteFromBegining)
    // else.. we edurate to the last node.. we cut the list here
    // so the last Node would be free to delete
    // finally we delete tha last node (toDelete)
    if (*root != NULL)
    {
        Node *toDelete = *root;
        while (toDelete->next != 0)
            toDelete = toDelete->next;
        if (toDelete->previous != NULL)
            toDelete->previous->next = NULL;
        else
            *root = NULL;
        free(toDelete);
    }
}

// sort the linked list (root) from the maximaum value
// going down to the minimaum value
void LLDC_SortDesc(Node **root)
{
    // we edurate throught the linked list using the pointer i
    // every single eduration we find the max in the range(i to the end)
    // we swap the value of the pointer that has the max with the value
    // stored in i ... so we put the maximaum at the begining every eduration
    // this is called bubble sort
    for (Node *i = *root; i != NULL; i = i->next)
    {
        int max = i->data;
        Node *index = i;
        for (Node *j = i; j != NULL; j = j->next)
        {
            if (j->data > max)
            {
                max = j->data;
                index = j;
            }
        }
        swap(&(index->data), &(i->data));
    }
}

// sort the linked list (root) from the minimaum value
// going up to the maximaum value
void LLDC_SortAsc(Node **root)
{
    // we edurate throught the linked list using the pointer i
    // every single eduration we find the min in the range(i to the end)
    // we swap the value of the pointer that has the min with the value
    // stored in i ... so we put the minimaum at the begining every eduration
    // this is called bubble sort
    for (Node *i = *root; i != NULL; i = i->next)
    {
        int min = i->data;
        Node *index = i;
        for (Node *j = i; j != NULL; j = j->next)
        {
            if (j->data < min)
            {
                min = j->data;
                index = j;
            }
        }
        swap(&(index->data), &(i->data));
    }
}

// Reverse the linked lists(Reverse the order of its content)
void LLDC_Reverse(Node **root)
{
    // we create a new linked list (newRoot)
    // we keep deleting the first element of our linked list and add
    // the value stored in the deleted node to the new linked list
    // in the end our linked list becomes empty and the new one is
    // the Reversed version of our linked list
    // so we replace the old linked link with the new one
    Node *newRoot = NULL;

    while (*root != NULL)
    {
        LLDC_AddToBegining(&newRoot, (*root)->data);
        LLDC_DeleteFromBegining(root);
    }
    *root = newRoot;
}

// Delete duplicated values in the linked list (root)
void LLDC_RemoveDuplicated(Node **root)
{
    // for every element we do this profess (eduration with pointer i)
    // we compare the element with the rest (eduration with pointer j)
    // if duplicated then delete it (free the pointer duplicated)
    // else .. keep edurating till the end
    Node *i = *root;
    Node *duplicated;
    while (i != NULL && i->next != NULL)
    {
        Node *j = i;
        while (j->next != NULL)
        {
            if (i->data == j->next->data)
            {
                duplicated = j->next;
                if (j->next->next != NULL)
                {
                    j->next->next->previous = j;
                    j->next = j->next->next;
                }
                else
                    j->next = NULL;
                free(duplicated);
            }
            else
                j = j->next;
        }
        i = i->next;
    }
}

// returns the number of nodes in our linked list(root)
int LLDC_size(Node *root)
{
    // inisialize the size to 0
    // edurate throught the list using a temporary pointer
    // increment the size every eduration
    // return the size
    int size = 0;
    Node *temp = root;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

// returns the some of all data stored in our linked list (root)
int LLDC_sum(Node *root)
{
    int some = 0;
    for (Node *p = root; p != NULL; p = p->next)
        some = some + p->data;
    return some;
}
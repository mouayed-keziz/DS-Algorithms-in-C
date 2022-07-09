#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

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

void swap(int *x, int *y);

// this swaps two variable using a temporary variable
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void main(int argc, char *argv[])
{
    // 77   2   4   42

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

// Display the content of the linked list (root)
// using this format %d-->%d--->...%d--->NULL
void LLC_Display(Node *root)
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
void LLC_AddToBegining(Node **root, int value)
{
    // create a pointer to a node with data = value
    // the pointer to the next node has to point to the root
    // so the root becomes second node
    // and the new node becomes the first node (root)
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->next = *root;
    *root = new;
}

// insert a new node with the data (value)
// at the ending of the linked list (root)
void LLC_AddToEnding(Node **root, int value)
{
    // create a pointer to a node with data = value
    // the pointer to the next node has to be null
    // cause the new node is going to be the last node
    // so there is no more nodes after it
    // if our linked list is empty .. the list is going
    // to contain just one node which is the new node
    // if our linked list is not empty we edurate through
    // its nodes till the last one using a temprorary node
    // we link the last node with the new node so the new
    // node becomes the last node
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;

    if (*root == NULL)
        *root = new;
    else
    {
        Node *temp = *root;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new;
    }
}

// delete the first node in the linked list (root)
void LLC_DeleteFromBegining(Node **root)
{
    // if our linked list is empty we do nothing..else
    // we point to the first node with toDelete pointer
    // the root becomes the second node of the list
    // delete the first node (*toDelete)
    // so the new list starts from the second node
    if (*root != NULL)
    {
        Node *toDelete = *root;
        *root = (*root)->next;
        free(toDelete);
    }
}

// delete the last node in the lisked list (root)
void LLC_DeleteFromEnding(Node **root)
{
    // if our linked list is empty we do nothing..else
    // if it has just 1 node we use (DeleteFromBegining)
    // else.. we edurate to the node the come just before
    // the last node .. we point to the last node with
    // toDelete pointer .. the we cut this node from the list
    // finally we delete tha last node (toDelete)
    if (*root != NULL)
    {
        if ((*root)->next == NULL)
            LLC_DeleteFromBegining(root);
        else
        {
            Node *temp = *root;
            while (temp->next->next)
                temp = temp->next;
            Node *toDelete = temp->next;

            temp->next = NULL;
            free(toDelete);
        }
    }
}

// sort the linked list (root) from the maximaum value
// going down to the minimaum value
void LLC_SortDesc(Node **root)
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
void LLC_SortAsc(Node **root)
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
void LLC_Reverse(Node **root)
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
        LLC_AddToBegining(&newRoot, (*root)->data);
        LLC_DeleteFromBegining(root);
    }
    *root = newRoot;
}

// Delete duplicated values in the linked list (root)
void LLC_RemoveDuplicated(Node **root)
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
                j->next = j->next->next;
                free(duplicated);
            }
            else
                j = j->next;
        }
        i = i->next;
    }
}

// returns the number of nodes in our linked list(root)
int LLC_size(Node *root)
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
int LLC_sum(Node *root)
{
    int some = 0;
    for (Node *p = root; p != NULL; p = p->next)
        some = some + p->data;
    return some;
}

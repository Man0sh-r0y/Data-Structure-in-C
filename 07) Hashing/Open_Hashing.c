#include <stdio.h>
#include <stdlib.h>

#define size 7

void init();
void insert(int value);
int search(int value);
int del(int value);
void print();

struct node
{
    int data;
    struct node *next;
};

struct node *chain[size];

int main()
{
    // init array of list to NULL
    init();

    insert(7);
    insert(1);
    insert(3);
    insert(10);
    insert(4);
    insert(5);

    int val = 3;
    if (search(val))
    {
        printf("%d is present in the Hash Table\n", val);
    }

    if (del(val))
    {
        printf("%d is deleted\n", val);
    }
    print();

    return 0;
}

void init()
{
    int i;
    for (i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value)
{
    // create a newnode with value
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    // calculate hash key
    int key = value % size;

    // check if chain[key] is empty
    if (chain[key] == NULL)
        chain[key] = newNode;
    // collision
    else
    {
        // add the node at the end of chain[key].
        struct node *temp = chain[key];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

/*
 * return 1, search found
 * return 0, Otherwise
 */
int search(int value)
{
    int key = value % size;
    struct node *temp = chain[key];
    while (temp != NULL)
    {
        if (temp->data == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

/*
 * return 1, successful delete
 * return 0, value not found
 */
int del(int value)
{
    int key = value % size;
    struct node *temp = chain[key];
    struct node *dealloc;
    if (temp != NULL)
    {
        if (temp->data == value)
        {
            dealloc = temp;
            temp = temp->next;
            chain[key] = temp;
            free(dealloc);
            return 1;
        }
        else
        {
            while (temp->next != NULL)
            {
                if (temp->next->data == value)
                {
                    dealloc = temp->next;
                    temp->next = temp->next->next;
                    free(dealloc);
                    return 1;
                }
                temp = temp->next;
            }
        }
    }

    return 0;
}

void print()
{
    int i;

    for (i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->", i);
        while (temp != NULL)
        {
            printf("%d -->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *push(struct node *Top, int data);
struct node *pop(struct node *Top);

int main()
{
    struct node *Top; // head of the stack
    Top = push(Top, 1);
    Top = push(Top, 2);
    Top = push(Top, 3);
    Top = pop(Top);
    Top = pop(Top);
    Top = pop(Top);
    return 0;
}

struct node *push(struct node *Top, int element)
{
    if (Top == NULL)
    {
        struct node *Top = (struct node *)malloc(sizeof(struct node));
        Top->data = element;
        Top->next = NULL;
        printf("\n%d is pushed\n", Top->data);
        return Top;
    }
    // addFirst() function of LinkedList
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = element;
    newNode->next = Top;
    Top = newNode;
    printf("\n%d is pushed\n", Top->data);
    return Top;
}

struct node *pop(struct node *Top)
{
    if (Top == NULL)
    {
        printf("Stack is Empty\n");
        return NULL;
    }
    // deleteFirst() function of LinkedList
    struct node *temp = Top;
    Top = Top->next;
    printf("\n%d is popped\n", temp->data);
    free(temp);
    return Top;
}

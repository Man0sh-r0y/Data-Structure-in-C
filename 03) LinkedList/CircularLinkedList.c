#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void addFirst(int element);
void addLast(int element);
void deleteFirst();
void deleteLast();
void display();

int main()
{
    addFirst(2);
    addLast(3);
    addLast(4);
    addFirst(1);
    addFirst(0);
    display();
    deleteFirst();
    deleteLast();
    display();

    return 0;
}
void addFirst(int element)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = element;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        ptr->next = head;
        temp->next = ptr;
        head = ptr;
    }
}
void addLast(int element)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = element;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
    }
}

void deleteFirst()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("UNDERFLOW \n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
    }

    else
    {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = head->next;
        free(head);
        head = ptr->next;
    }
}
void deleteLast()
{
    struct node *ptr, *preptr;
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("Nothing to print");
        return;
    }
    printf("Printing values ... \n");
    struct node *ptr = head;
    while (ptr->next != head)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *addFirst(struct node *head, int element)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = element;
        head->next = NULL;
        head->prev = NULL;
        return head;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = element;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    return head;
}

struct node *addLast(struct node *head, int element)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = element;
        head->next = NULL;
        head->prev = NULL;
        return head;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = element;
    temp->next = ptr;
    ptr->prev = temp;
    ptr->next = NULL;
    return head;
}

struct node *deleteFirst(struct node *head)
{
    if (head == NULL)
    {
        printf("LinkedList is Empty\n");
        return head;
    }
    struct node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

struct node *deleteLast(struct node *head)
{
    if (head == NULL)
    {
        printf("LinkedList is Empty\n");
        return head;
    }
    struct node *slow = head;
    struct node *fast = head->next;
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
    free(fast);
    return head;
}

struct node *reverseLinkedList(struct node *head)
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    head = prev;

    return head;
}

void printLinkedList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    int choice, element, indx;
    while (1)
    {
        printf(" 1: addFirst\n 2: addLast\n 3: deleteFirst\n 4: deleteLast\n 5: print Linked List\n 6:Reverse Linked List\n 7: exit\n Choose any one: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &element);
            head = addFirst(head, element);
            break;
        case 2:
            printf("Enter element: ");
            scanf("%d", &element);
            head = addLast(head, element);
            break;
        case 3:
            head = deleteFirst(head);
            break;
        case 4:
            head = deleteLast(head);
            break;
        case 5:
            printLinkedList(head);
            break;
        case 6:
            head = reverseLinkedList(head);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid Input\n");
            break;
        }
    }

    return 0;
}
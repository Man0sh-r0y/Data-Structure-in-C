#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *addFirst(struct node *head, int data)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
        return head;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

struct node *addLast(struct node *head, int data)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
        return head;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node *addAtIndx(struct node *head, int indx, int data)
{
    if (indx == 0)
    {
        head = addFirst(head, data);
        return head;
    }
    struct node *temp = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    int i = 0;
    while (i < indx - 1)
    {
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    temp->next = ptr;
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

struct node *deleteAtIndx(struct node *head, int indx)
{
    if (indx == 0)
    {
        head = deleteFirst(head);
        return head;
    }
    struct node *temp = head;
    int i = 0;
    while (i < indx - 1)
    {
        temp = temp->next;
        i++;
    }
    struct node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
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
        printf("%d -> ", temp->data);
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
        printf(" 1: addFirst\n 2: addLast\n 3: addAtIndx\n 4: deleteFirst\n 5: deleteLast\n 6: deleteAtIndx\n 7: print Linked List\n, 8:Reverse Linked List\n 9: exit\n Choose any one: ");
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
            printf("Enter element: ");
            scanf("%d", &element);
            printf("Enter the Index: ");
            scanf("%d", &indx);
            head = addAtIndx(head, indx, element);
            break;
        case 4:
            head = deleteFirst(head);
            break;
        case 5:
            head = deleteLast(head);
            break;
        case 6:
            printf("Enter the Index: ");
            scanf("%d", &indx);
            head = deleteAtIndx(head, indx);
            break;
        case 7:
            printLinkedList(head);
            break;
        case 8:
            head = reverseLinkedList(head);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid Input\n");
            break;
        }
    }

    return 0;
}
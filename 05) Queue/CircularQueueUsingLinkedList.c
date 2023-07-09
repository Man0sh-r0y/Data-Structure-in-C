#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *createNode(int data);
void enQueue(int element);
void deQueue();
void display();
int isEmpty();

int main()
{
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    display();
    deQueue();
    deQueue();
    display();
    return 0;
}

int isEmpty()
{
    if (rear == NULL && front == NULL)
    {
        return 1;
    }
    return 0;
}

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enQueue(int data) // insert at the last
{
    if (isEmpty())
    {
        struct node *newNode = createNode(data);
        front = rear = newNode;
        rear->next = front; // as it's a circular queue
        printf("%d is inserted\n", data);
        return;
    }
    struct node *newNode = createNode(data);
    rear->next = newNode;
    rear = newNode;
    rear->next = front; // as it's circular queue
    printf("%d is inserted\n", data);
}

void deQueue() // delete the first element
{
    int deletedElement;
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    if (front == rear)
    { // if there is only 1 element left
        deletedElement = front->data;
        front = rear = NULL;
    }
    struct node *temp = front;
    deletedElement = front->data;
    front = front->next;
    rear->next = front;
    free(temp);
    printf("%d is deleted\n", deletedElement);
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements are: ");
    struct node *temp = front;
    while (temp->next != front)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
    printf("\n");
}

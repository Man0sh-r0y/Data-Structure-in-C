#include <stdio.h>
#include <stdlib.h>

#define size 10
int queue[size];
int front = -1, rear = -1;
void enQueue(int element);
void deQueue();
void display();
int isFull();
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

int isFull()
{
    if (rear == size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    return 0;
}

void enQueue(int element)
{
    if (isFull())
    { // when queue is Full
        printf("Queue is Full\n");
        return;
    }

    if (isEmpty())
    { // inserting 1st element
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1; // updating the rear value
    }
    queue[rear] = element;
    printf("%d is inserted\n", element);
}

void deQueue()
{
    int deletedElement;
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    if (front == rear)
    { // when there is left one element in the queue
        deletedElement = queue[front];
        front = rear = -1;
    }
    else
    {
        deletedElement = queue[front];
        front = front + 1; // updating front value
    }
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
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
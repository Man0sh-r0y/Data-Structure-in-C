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
    if ((rear + 1) % size == front)
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
    {
        printf("Queue is Full\n");
        return;
    }

    if (isEmpty())
    { // inserting the 1st element
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % size; // updating the rear value
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
    { // when 1 element is left in the queue
        deletedElement = queue[front];
        front = rear = -1;
    }
    else
    {
        deletedElement = queue[front];
        front = (front + 1) % size; // incrementing the front value
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

    int i = front;
    printf("Queue elements are: ");
    while (i <= rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % size;
    }
    printf("\n");
}
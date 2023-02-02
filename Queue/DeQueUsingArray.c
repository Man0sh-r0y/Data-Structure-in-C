#include <stdio.h>
#include <stdlib.h>

#define size 10
int queue[size];
int front = -1;
int rear = -1;

int isFull();
int isEmpty();
void addFront(int element);
void addRear(int element);
void deleteFront();
void deleteRear();
void display();

int main()
{
    addFront(2);
    addFront(1);
    addFront(0);
    addRear(3);
    addRear(4);
    addRear(5);
    addRear(6);
    display();
    deleteFront();
    deleteRear();
    display();
    return 0;
}

int isFull()
{
    if ((front == 0 && rear == size - 1) || front == rear + 1)
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

void addFront(int element)
{
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }

    if (isEmpty()) // when queue is empty
    {
        front = rear = 0;
    }
    else if (front == 0) // when front is at 0th index but queue has some elements and rear is pointing to the last element.
    {
        front = size - 1; // then front will be relocated to last position of the array and insertion will be done there.
    }
    else // here front isn't at the 0th index but queue has some elements. This stage happens when some elements have been deleted from the front part and then front has been incremented.
    {
        front = front - 1;
    }
    queue[front] = element;
    printf("%d is inserted\n", element);
}

void addRear(int element)
{
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }

    if (isEmpty()) // when queue is empty
    {
        rear = 0;
    }
    else if (rear == size - 1)
    {
        rear = 0; // when rear is at the last position in the array then it is relocated atv the 1st position of the array and insertion will be done from there. And no overlapping of element will be happened there as there are isFull() function who will check this.
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = element;
    printf("%d is inserted\n", element);
}

void deleteFront()
{
    int deleteElement;
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    if (front == rear)
    {
        // when there is only 1 element left in the queue
        deleteElement = queue[front];
        front = rear = -1;
    }
    else if (front == size - 1)
    {
        deleteElement = queue[front];
        front = 0;
    }
    else
    {
        deleteElement = queue[front];
        front = front + 1;
    }
    printf("%d is deleted\n", deleteElement);
}

void deleteRear()
{
    int deleteElement;
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    if (front == rear)
    {
        // when there is only 1 element left in the queue
        deleteElement = queue[rear];
        front = rear = -1;
    }
    else if (rear == 0)
    {
        deleteElement = queue[rear];
        rear = size - 1;
    }
    else
    {
        deleteElement = queue[rear];
        rear = rear - 1;
    }
    printf("%d is deleted\n", deleteElement);
}

void display()
{
    int i = front;
    printf("Queue elements are: ");
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % size;
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void enQueue(struct queue *q, int element);
void deQueue(struct queue *q);
void display(struct queue *q);
int isFull(struct queue *q);
int isEmpty(struct queue *q);

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    display(q);
    deQueue(q);
    deQueue(q);
    display(q);

    return 0;
}

int isFull(struct queue *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    return 0;
}

void enQueue(struct queue *q, int element)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }

    if (isEmpty(q))
    { // inserting the 1st element
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size; // updating the rear value
    }
    q->arr[q->rear] = element;
    printf("%d is inserted\n", element);
}

void deQueue(struct queue *q)
{
    int deletedElement;
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }

    if (q->front == q->rear)
    { // when 1 element is left in the queue
        deletedElement = q->arr[q->front];
        q->front = q->rear = -1;
    }
    else
    {
        deletedElement = q->arr[q->front];
        q->front = (q->front + 1) % q->size; // incrementing the front value
    }
    printf("%d is deleted\n", deletedElement);
}

void display(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }

    int i = q->front;
    printf("Queue elements are: ");
    while (i <= q->rear)
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}
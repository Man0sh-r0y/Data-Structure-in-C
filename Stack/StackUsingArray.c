#include <stdio.h>
#include <stdlib.h>

int Top = -1;

int isEmpty(int *ptr);
int isFull(int *ptr, int size);
void push(int *ptr, int size, int element);
int pop(int *ptr);
int peek(int *ptr, int index);
int stackTop(int *ptr);
int stackBottom(int *ptr);

int main()
{
    int size;
    printf("Enter the size of the Stack: ");
    scanf("%d", &size);
    int *stack = (int *)malloc(size * sizeof(int));
    while (1)
    {
        int check, element, val;
        printf("Enter 1 for pushing, 2 for popping, 3 for exit: ");
        scanf("%d", &check);
        switch (check)
        {
        case 1:
            printf("Enter the Element you want to Push: ");
            scanf("%d", &element);
            push(stack, size, element);
            break;
        case 2:
            val = pop(stack);
            printf("%d is popped from stack\n", val);
            break;
        case 3:
            free(stack);
            exit(1);
        }
    }

    return 0;
}

int isEmpty(int *ptr)
{
    if (ptr[Top] == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(int *ptr, int size)
{
    if (ptr[Top] == size - 1)
    {
        return 1;
    }
    return 0;
}
void push(int *ptr, int size, int element)
{
    if (isFull(ptr, size))
    {
        printf("Stack OverFlow\n");
    }
    else
    {
        Top++;
        ptr[Top] = element;
        printf("%d is pushed in Stack\n", element);
    }
}
int pop(int *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack UnderFlow\n");
    }
    else
    {
        int val = ptr[Top];
        Top--;
        return val;
    }
}

int peek(int *ptr, int index)
// peek() returs the element at the given position
{
    int arrIndex = Top - index + 1;
    if (arrIndex < 0)
    {
        printf("Given index isn't a valid index\n");
        return -1;
    }
    return ptr[arrIndex];
}

int stackTop(int *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    return ptr[Top];
}

int stackBottom(int *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    return ptr[0];
}
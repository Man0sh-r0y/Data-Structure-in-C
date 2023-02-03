#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int Top;
    int size;
    int *arr;
};

int isEmpty(struct stack *ptr);
int isFull(struct stack *ptr);
void push(struct stack *ptr, int element);
int pop(struct stack *ptr);

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->Top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
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
            push(sp, element);
            break;
        case 2:
            val = pop(sp);
            printf("%d is popped from stack\n", val);
            break;
        case 3:
            exit(1);
        }
    }

    return 0;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->Top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct stack *ptr)
{
    if (ptr->Top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *ptr, int element)
{
    if (isFull(ptr))
    {
        printf("Stack OverFlow\n");
    }
    else
    {
        ptr->Top++;
        ptr->arr[ptr->Top] = element;
        printf("%d is pushed in Stack\n", element);
    }
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack UnderFlow\n");
    }
    else
    {
        int val = ptr->arr[ptr->Top];
        ptr->Top--;
        return val;
    }
}

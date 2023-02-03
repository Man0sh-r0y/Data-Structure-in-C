#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100
char stack[size];
int Top = -1;
void push(char element);
char pop();
int isEmpty();
int isFull();
char stackTop();
int isOperator(char ch);
int precedence(char ch);
char *infixToPostfix(char *infix);

int main()
{
    char *infix = "x-y/z-k*d";
    printf("PostFix is %s", infixToPostfix(infix));
    return 0;
}

int isEmpty()
{
    if (Top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if (Top == size - 1)
    {
        return 1;
    }
    return 0;
}

char stackTop()
{
    return stack[Top];
}

void push(char element)
{
    if (isFull())
    {
        printf("Stack is Full\n");
        return;
    }
    Top++;
    stack[Top] = element;
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        char val = stack[Top];
        Top--;
        return val;
    }
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    return 0;
}

char *infixToPostfix(char *infix)
{
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // track the infix traversal
    int j = 0; // track the postfix traversal
    while (infix[i] != '\0')
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix[j] = infix[i];
            j++;
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty() && stackTop() != '(')
            {
                postfix[j] = pop();
                j++;
            }
            if (!isEmpty())
            {
                pop();
            }
        }
        else
        {
            while (!isEmpty() && precedence(stackTop()) >= precedence(infix[i]))
            {
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
        }
        i++;
    }
    while (!isEmpty())
    {
        postfix[j] = pop();
        j++;
    }
    return postfix;
}
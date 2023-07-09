#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    // creating nodes
    struct node *p = createNode(1);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(1);
    // linking the root with the left and right children
    p->left = p1;
    p->right = p2;
    return 0;
}
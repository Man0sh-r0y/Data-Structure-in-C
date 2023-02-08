#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data);
struct node *binaryTree();

int main()
{
    struct node *root = NULL;
    root = binaryTree();
    return 0;
}

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *binaryTree()
{
    int choice;
    printf("\nPress 0 to exit: \n");
    printf("Press 1 for new Node: \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 0)
    {
        return NULL;
    }
    else if (choice == 1)
    {
        int data;
        printf("\nEnter the data: ");
        scanf("%d", &data);
        struct node *newNode = createNode(data);
        printf("\nEnter the left Child of %d: ", data);
        newNode->left = binaryTree();
        printf("\nEnter the right Child of %d: ", data);
        newNode->right = binaryTree();
        return newNode;
    }
}
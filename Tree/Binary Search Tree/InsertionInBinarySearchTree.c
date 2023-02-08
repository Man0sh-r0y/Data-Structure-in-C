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

// insertion in Binary Search Tree (Iterative Approarch)
void iterativeInsertion(struct node *root, int value)
{
    struct node *temp = root;
    struct node *prev = NULL;
    while (temp != NULL)
    {
        prev = temp;
        if (temp->data == value)
        {
            printf("\nCan't insert as it's already present in binray search tree\n");
            return; // as there shouldn't be same node in Binary Search Tree
        }
        else if (temp->data > value)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    struct node *newNode = createNode(value);
    if (value < prev->data)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
}
// Recursive approach
struct node *recursiveInsertion(struct node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value); // return a new Node if tree is empty
    }

    if (root->data > value)
    {
        root->left = recursiveInsertion(root, value);
    }
    else
    {
        root->right = recursiveInsertion(root, value);
    }
    return root;
}

// inorder traversal
void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main()
{
    // creating nodes
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(7);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(8);
    // our binary search tree structure
    //      5
    //     / \
    //    3   7
    //   / \   \
    //  1   4   8
    // linking nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    inOrder(p);               // printing the tree
    iterativeInsertion(p, 6); // insering node
    printf("\n");
    inOrder(p); // printing the tree
    return 0;
}
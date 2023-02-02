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
// in binary search tree, inorder traversal gives sorted accending order list
int isBST(struct node *root)
{
    // inorder traversal => left-root-right
    if (root == NULL)
    {
        return 1; // true
    }
    static struct node *prev = NULL;
    int leftChild = isBST(root->left);
    // binary search tree condition
    if (prev != NULL && prev->data >= root->data)
    {
        return 0; // false
    }
    prev = root;
    return isBST(root->right);
}

int main()
{
    // creating nodes
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(7);
    // our binary search tree structure
    //      5
    //     / \
    //    3   6
    //   / \   \
    //  1   4   7
    // linking nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    if (isBST(p))
    {
        printf("It is a Binary Search Tree\n");
    }
    else
    {
        printf("It is not a Binary Search Tree\n");
    }
    return 0;
}
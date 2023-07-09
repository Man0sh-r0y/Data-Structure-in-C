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

struct node *findLastRightNode(struct node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return findLastRightNode(root->right);
}

struct node *helper(struct node *root)
{
    if (root->left == NULL)
    {
        return root->right;
    }
    if (root->right == NULL)
    {
        return root->left;
    }
    struct node *rightChild = root->right;
    struct node *lastRight = findLastRightNode(root->left);
    lastRight->right = rightChild;
    return root->left;
}
// suppose we have to delete the 5 node
//                 9
//               /   \
//              8    12
//             /    /  \
//            5    10   13
//          /  \    \
//         3     7   11
//        / \   / \
//       2   4 6   8
//      /
//     1
// After deleteing the node it will looks like :
// deleted the node whose value is 5
//                     9
//                   /   \
//                  8    12
//                 /    /  \
//                3    10   13
//               / \     \
//              2   4     11
//             /     \
//            1       7
//                   / \
//                  6   8

struct node *delete(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return helper(root);
    }
    struct node *temp = root;
    while (root != NULL)
    {
        if (root->data > key)
        {
            if (root != NULL && root->left->data == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != NULL && root->right->data == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return temp;
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
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(8);
    // our binary search tree structure
    //      5
    //     / \
    //    3   6
    //   / \   \
    //  1   4   8
    // linking nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    inOrder(p);
    printf("\n");
    p = delete (p, 6);
    inOrder(p);
    return 0;
}
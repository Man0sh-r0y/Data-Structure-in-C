#include <stdio.h>

#define MAX 1000 // Max size of Heap

void swap(int *a, int *b);
void heapify(int arr[], int n, int i);
void insertNode(int arr[], int n, int Key);
void printArray(int arr[], int n);

int main()
{
    // Array representation of Max-Heap
    //    10
    //    / \
    //   5   3
    //  / \
    // 2   4
    int arr[MAX] = {10, 5, 3, 2, 4};
    int n = 5;
    int key = 15;
    insertNode(arr, n, key);
    printArray(arr, n);
    // Final Heap will be:
    //       15
    //      /   \
    //     5     10
    //    / \   /
    //   2   4 3

    return 0;
}

/*
some keypoints:
If a node is at index i, then
it's left child is at 2*i+1 index
it's right child at 2*i + 2
it's parent at floor value of i-1/2
*/

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Function to heapify ith node in a Heap
// of size n following a Bottom-up approach
void heapify(int arr[], int n, int i)
{
    // Find parent
    int parent = (i - 1) / 2;

    if (arr[parent] > 0)
    {
        // For Max-Heap
        // If current node is greater than its parent
        // Swap both of them and call heapify again
        // for the parent
        if (arr[i] > arr[parent])
        {
            swap(&arr[i], &arr[parent]);

            // Recursively heapify the parent node
            heapify(arr, n, parent);
        }
    }
}

// Function to insert a new node to the Heap
void insertNode(int arr[], int n, int Key)
{
    // Increase the size of Heap by 1
    n = n + 1; // n = size of the heap

    // Insert the element at end of Heap
    arr[n - 1] = Key;

    // Heapify the new node following a Bottom-up approach
    heapify(arr, n, n - 1);
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

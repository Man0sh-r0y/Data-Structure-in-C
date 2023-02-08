// Heap Sort in C
#include <stdio.h>

void swap(int *a, int *b);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void printArray(int arr[], int n);

int main()
{
    int arr[] = {5, 3, 10, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Array representation of Max-Heap
    //     5
    //    / \
    //   3   10
    //  / \
    // 2   4
    // this is not a MAX heap Tree. We have to make it a heap tree

    heapSort(arr, n);

    printf("Sorted array is \n");
    printArray(arr, n);
}

// Function to swap the the position of two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
/*
Some KeyPoints:
in a Heap Tree Data Structure,
if n = size of the Array then,
internal nodes are from 1 to floor value of n/2
Leaf nodes are from floor value of n/2 to n
Floort value gives the largest nearest integer of the specified value
*/

// Array representation of Max-Heap
//    10
//    / \
//   5   3
//  / \
// 2   4

// Main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

// Print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

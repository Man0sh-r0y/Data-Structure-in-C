#include <stdio.h>

void swap(int *a, int *b);
void heapify(int arr[], int n, int i);
void heapTree(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
    // Array representation of Max-Heap
    //    10
    //    / \
	//   5   3
    //  / \
	// 2   4
    int arr[] = {2, 3, 5, 10, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    heapTree(arr, n);
    printArray(arr, n);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// To heapify a subtree rooted with node i which is
// an index of arr[] and n is the size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    // n=size of the heap
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapTree(int arr[], int n)
{
    // build max heap tree
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

/*A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
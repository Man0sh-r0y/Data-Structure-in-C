#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void modifiedBubbleSort(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // For number of pass
    {
        int isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return; // now no need to sort more number of times
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;
    printArray(A, n);         // Printing the array before sorting
    modifiedBubbleSort(A, n); // Function to sort the array
    printArray(A, n);         // Printing the array before sorting
    return 0;
}

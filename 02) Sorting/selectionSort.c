#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int currIndx = i;
        for (int j = i + 1; j <= size; j++)
        {
            if (ptr[j] < ptr[currIndx])
            {
                currIndx = j;
            }
        }
        if (currIndx != i)
        {
            int temp = ptr[currIndx];
            ptr[currIndx] = ptr[i];
            ptr[i] = temp;
        }
    }
}

void printArray(int *ptr, int size)
{
    printf("After Sorting Array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }
}

int main()
{
    int size;
    printf("Enter the size of Array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, size);
    printArray(arr, size);
    free(arr);
    return 0;
}
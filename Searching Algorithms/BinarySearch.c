#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int *creatArray(int size);
void bubbleSort(int *arr, int size);
int BinarySearch(int *arr, int size, int searchElement);

int main()
{
    int size, searchElement;
    printf("Enter the size of an Array: ");
    scanf("%d", &size);
    int *ptr = creatArray(size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the Array Element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }
    bubbleSort(ptr, size);
    printf("Which Element You want to find? ");
    scanf("%d", &searchElement);
    int searchIndex = BinarySearch(ptr, size, searchElement);
    if (searchIndex == -1)
        printf("Element not Found\n");
    else
        printf("Your Searched Element is found at Index %d\n", searchIndex);

    free(ptr);
    return 0;
}

int *creatArray(int size)
{
    int *ptr = (int *)calloc(size, sizeof(int));
    return ptr;
}

void bubbleSort(int *arr, int size)
{
    bool swapped;
    for (int i = 0; i < size; i++)
    {
        swapped = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int BinarySearch(int *arr, int size, int searchElement)
{
    int low = 0, mid, high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == searchElement)
            return mid;
        else if (arr[mid] < searchElement)
            low = mid + 1;
        else if (arr[mid] > searchElement)
            high = mid - 1;
    }
    return -1;
}
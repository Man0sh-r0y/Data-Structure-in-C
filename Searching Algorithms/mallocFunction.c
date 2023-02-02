#include <stdio.h>
#include <stdlib.h>

int *creatArray(int size);
void removeElement(int *ptr, int size, int removeIndex);
int *resizeArray(int *ptr, int resize);
void insertElement(int *ptr, int oldsize, int resize);

int main()
{
    int size, removeIndex, oldsize, resize;
    printf("Enter the Size of an Array: ");
    scanf("%d", &size);
    int *ptr = creatArray(size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the Element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }
    printf("Enter the Index of Which You want to delete the Element? ");
    scanf("%d", &removeIndex);
    removeElement(ptr, size, removeIndex);
    printf("After Deleting Array Element--\n");
    for (int i = 0; i < size - 1; i++)
    {
        printf("Array Element %d is %d\n", i + 1, ptr[i]);
    }
    printf("Enter the new size of the Array: ");
    scanf("%d", &resize);
    oldsize = size - 1;
    insertElement(ptr, oldsize, resize);
    printf("After inserting Array Element---\n");
    for (int i = 0; i < resize; i++)
    {
        printf("Array Element %d is %d\n", i + 1, ptr[i]);
    }

    free(ptr);
    return 0;
}

int *creatArray(int size)
{
    int *ptr = (int *)calloc(size, sizeof(int));
    return ptr;
}

void removeElement(int *ptr, int size, int removeIndex)
{
    for (int i = removeIndex; i < size - 1; i++)
    {
        ptr[i] = ptr[i + 1];
    }
}

int *resizeArray(int *ptr, int resize)
{
    ptr = realloc(ptr, resize * sizeof(int));
    return ptr;
}

void insertElement(int *ptr, int oldsize, int resize)
{
    ptr = resizeArray(ptr, resize);
    for (int i = oldsize; i < resize; i++)
    {
        printf("Enter the Array Element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }
}
#include <stdio.h>

int getMin(int a, int b);
int getMax(int a, int b);
int findMin(int A[], int n); // minimum element finding
int findMax(int A[], int n); // maximum element finding

int main()
{
    int A[] = {1, 4, 45, 6, -50, 10, 2};
    int length = sizeof(A) / sizeof(A[0]);
    int minNum = findMin(A, length);
    int maxNum = findMax(A, length);
    printf("Minimum in Array: %d \n", minNum);
    printf("Maximum in Array: %d \n", maxNum);
    return 0;
}

int getMin(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

int getMax(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int findMin(int A[], int n)
{
    // if size = 0 means whole array has been traversed
    if (n == 1)
        return A[0];

    return getMin(A[n - 1], findMin(A, n - 1));
}

int findMax(int A[], int n)
{
    // if size = 0 means whole array has been traversed
    if (n == 1)
        return A[0];

    return getMax(A[n - 1], findMax(A, n - 1));
}
#include <stdio.h>
int linearSearch(int a[], int n, int val)
{
    // Going through array sequencially
    for (int i = 0; i < n; i++)
    {
        if (a[i] == val)
            return i + 1;
    }
    return -1;
}
int main()
{
    int a[] = {70, 40, 30, 11, 57, 41, 25, 14, 52}; // given array
    int val = 41;                                   // value to be searched
    int n = sizeof(a) / sizeof(a[0]);               // size of array
    int searchElement = linearSearch(a, n, val);    // Store searchElement
    printf("Element to be searched is - %d", val);
    if (searchElement == -1)
        printf("Element is not psearchElementent in the array\n");
    else
        printf("Element is psearchElementent at %d position of array\n", searchElement);
    return 0;
}
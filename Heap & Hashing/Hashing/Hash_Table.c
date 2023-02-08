#include <stdio.h>

#define size 7

int arr[size];

void init(); // initialize the hash table data with -1
void insert(int value);
void del(int value);
void search(int value);
void print();

int main()
{
    init();     // initialize the hash table
    insert(10); // key = 10 % 7 ==> 3 // hash number of this value
    insert(4);  // key = 4 % 7  ==> 4 // hash number of this value
    insert(2);  // key = 2 % 7  ==> 2 // hash number of this value
    insert(3);  // key = 3 % 7  ==> 3 (collision)

    printf("Hash table\n");
    print();

    printf("Deleting value 10..\n");
    del(10);
    printf("After the deletion hash table\n");
    print();

    printf("Searching value 4..\n");
    search(4);
    return 0;
}

void init()
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
}

void insert(int value)
{
    // k mod n hashing where k is the value and n is the size of the hash table
    int key = value % size;

    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
        return;
    }
    printf("Collision : arr[%d] has element %d already!\n", key, arr[key]);
    printf("Unable to insert %d\n", value);
}

void del(int value)
{
    int key = value % size;
    if (arr[key] == value)
    {
        arr[key] = -1;
        return;
    }
    printf("%d not present in the hash table\n", value);
}

void search(int value)
{
    int key = value % size;
    if (arr[key] == value)
    {
        printf("Search Found\n");
        return;
    }
    printf("Search Not Found\n");
}

void print()
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    printf("\n");
}
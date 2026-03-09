#include <stdio.h>
void display(int arr[], int n)
{
    printf("array elements-->");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("/n");
}

void insert(int arr[], int n, int x, int pos)
{
    if (pos < 0 || pos >= n)
    {
        printf("overflow");
    }
}
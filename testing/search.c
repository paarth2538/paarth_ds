#include <stdio.h>
int lsearch_ite(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}
int bsearch_ite(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int bsearch_rec(int arr[], int n, int x, int low, int high)
{
    if (low > high)
    {
        printf("zyada hoshiyaari nahi !!");
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] > x)
    {
        return bsearch_rec(arr, n, x, low, mid - 1);
    }
    else
    {
        return bsearch_rec(arr, n, x, mid + 1, high);
    }
}
int bsearch_foc(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            if (arr[mid - 1] != arr[mid] || arr[mid] == 0)
            {
                return mid;
            }
            high = mid - 1;
        }
    }
    return -1;
}
int bsearch_loc(int arr[],int n,int x){
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else{
            if(arr[mid]!=arr[mid+1] || arr[mid]==n){
                return mid;
            }
            low=mid+1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1,2,2,3,3,3,4,4,4,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("%d", lsearch_ite(arr, n, 1));
    printf("%d", bsearch_ite(arr, n, 2));
    printf("%d", bsearch_rec(arr, n, 3, 0, n - 1));
    printf("%d", bsearch_foc(arr, n, 4));
    printf("%d", bsearch_loc(arr, n, 4));
}

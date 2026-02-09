#include<stdio.h>
int lsearch(int arr[],int n,int x){ //returns the index of the element if present in array if not found returns -1
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}
int bsearch(int arr[],int n,int x){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(x>arr[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int bsearchf(int arr[],int n,int x){ //first occurence of a given number in the array
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(x>arr[mid]){
            low=mid+1;
        }
        else if(x<arr[mid]){
            high=mid-1;
        }
        else{
            if(arr[mid]!=arr[mid-1] || mid==0){
            return mid;
            }
            high=mid-1;
        }

    }
    return -1;
}   
int bsearch_rec(int arr[],int n,int x,int low,int high){
    if (low>high){
        return -1;
    }
    int mid=(low+high)/2;
    if(arr[mid]==x){
        return mid;
    }
    else if(arr[mid]>x){
        return bsearch_rec(arr,n, x,low,mid-1);
    }
    else{
        return bsearch_rec(arr,n,x,mid+1,high);
    }
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int n=8;
    printf("%d",lsearch(arr,n,4));
    printf("%d",bsearch(arr,n,4));
    printf("%d",bsearch_rec(arr,n,4,0,n-1));
    int arr[]={1,1,2,2,2,3,3,3,3,4,4};
    int n=11;
    printf("%d",bsearchf(arr,n,3));
}
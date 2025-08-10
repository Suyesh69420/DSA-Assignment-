#include <stdio.h>

void heapify(int arr[], int n, int i, int isMax){
    int ext=i, l=2*i+1, r=2*i+2;
    if(isMax){
        if(l<n && arr[l]>arr[ext]) ext=l;
        if(r<n && arr[r]>arr[ext]) ext=r;
    } else {
        if(l<n && arr[l]<arr[ext]) ext=l;
        if(r<n && arr[r]<arr[ext]) ext=r;
    }
    if(ext!=i){ int t=arr[i]; arr[i]=arr[ext]; arr[ext]=t; heapify(arr,n,ext,isMax); }
}

void forgeHeap(int arr[], int n, int isMax){
    for(int i=n/2-1;i>=0;--i) heapify(arr,n,i,isMax);
}

void printArr(int a[], int n){ for(int i=0;i<n;++i) printf("%d ", a[i]); printf("\n"); }

int main(){
    int a[]={4,10,3,5,1}, n=5;
    int maxArr[5]; int minArr[5];
    for(int i=0;i<n;++i){ maxArr[i]=a[i]; minArr[i]=a[i]; }
    forgeHeap(maxArr,n,1);
    forgeHeap(minArr,n,0);
    printf("Max Heap: "); printArr(maxArr,n);
    printf("Min Heap: "); printArr(minArr,n);
    return 0;
}

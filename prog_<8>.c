#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int a[], int n, long *cmp, long *swp){
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            (*cmp)++;
            if(a[j]>a[j+1]){ int t=a[j]; a[j]=a[j+1]; a[j+1]=t; (*swp)++; }
        }
    }
}
void selectionSort(int a[], int n, long *cmp, long *swp){
    for(int i=0;i<n-1;++i){
        int min=i;
        for(int j=i+1;j<n;++j){ (*cmp)++; if(a[j]<a[min]) min=j; }
        if(min!=i){ int t=a[i]; a[i]=a[min]; a[min]=t; (*swp)++; }
    }
}
void insertionSort(int a[], int n, long *cmp, long *swp){
    for(int i=1;i<n;++i){
        int key=a[i], j=i-1;
        while(j>=0){ (*cmp)++; if(a[j]>key){ a[j+1]=a[j]; (*swp)++; j--; } else break; }
        a[j+1]=key;
    }
}
void sortFlow(int a[], int n, int choice, long *cmp, long *swp){
    if(choice==1) bubbleSort(a,n,cmp,swp);
    else if(choice==2) selectionSort(a,n,cmp,swp);
    else insertionSort(a,n,cmp,swp);
}

int main(){
    srand((unsigned)time(NULL));
    int N=10;
    int arr[100];
    for(int i=0;i<N;++i) arr[i]=rand()%1000+1;
    long cmp=0, swp=0;
    sortFlow(arr,N,1,&cmp,&swp);
    printf("After sort: "); for(int i=0;i<N;++i) printf("%d ", arr[i]); printf("\nCmp=%ld Swp=%ld\n",cmp,swp);
    return 0;
}

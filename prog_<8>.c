#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int a[], int n, long *cmp, long *swp){
    for(int i=0;i<n-1;++i)
        for(int j=0;j<n-i-1;++j){
            (*cmp)++;
            if(a[j]>a[j+1]){ int t=a[j]; a[j]=a[j+1]; a[j+1]=t; (*swp)++; }
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
void merge(int a[], int l, int m, int r, long *cmp){
    int n1=m-l+1, n2=r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;++i) L[i]=a[l+i];
    for(int j=0;j<n2;++j) R[j]=a[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        (*cmp)++;
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}
void mergeSortRec(int a[], int l, int r, long *cmp){
    if(l<r){
        int m=(l+r)/2;
        mergeSortRec(a,l,m,cmp);
        mergeSortRec(a,m+1,r,cmp);
        merge(a,l,m,r,cmp);
    }
}
void mergeSort(int a[], int n, long *cmp, long *swp){
    (void)swp; mergeSortRec(a,0,n-1,cmp);
}

void sortFlow(int a[], int n, int choice, long *cmp, long *swp){
    *cmp = 0; *swp = 0;
    if(choice==1) bubbleSort(a,n,cmp,swp);
    else if(choice==2) selectionSort(a,n,cmp,swp);
    else if(choice==3) insertionSort(a,n,cmp,swp);
    else if(choice==4) mergeSort(a,n,cmp,swp);
}

int main(){
    srand((unsigned)time(NULL));
    int N;
    printf("Enter N (max 100): "); if(!(scanf("%d",&N))||N<=0||N>100) return 0;
    int arr[100], before[100];
    for(int i=0;i<N;++i){ arr[i]=rand()%1000+1; before[i]=arr[i]; }
    printf("Before Sorting:\n");
    for(int i=0;i<N;++i) printf("%d ", before[i]); printf("\n");
    printf("Choose Algorithm: 1.Bubble 2.Selection 3.Insertion 4.Merge\n");
    int choice; scanf("%d",&choice);
    long cmp=0, swp=0;
    sortFlow(arr,N,choice,&cmp,&swp);
    printf("After Sorting:\n");
    for(int i=0;i<N;++i) printf("%d ", arr[i]); printf("\n");
    printf("Comparisons: %ld\nSwaps: %ld\n", cmp, swp);
    return 0;
}

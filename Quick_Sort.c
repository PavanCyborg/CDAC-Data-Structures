#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void printArray(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}
int Partition(int A[],int low,int high)
{
    int pivot=A[low];
    int i=low+1,j=high;
    do{
        while(A[i]<=pivot)
            i++;
        while(A[j]>pivot)
            j--;
        if(i<j)
            swap(&A[i],&A[j]);
    }while(i<j);
    swap(&A[low],&A[j]);
    return j;
}
void QuickSort(int A[],int low,int high)
{
    int Pivot_Index;
    if(low<high)
    {
        Pivot_Index=Partition(A,low,high);
        QuickSort(A,low,Pivot_Index-1);//left sub array
        QuickSort(A,Pivot_Index+1,high);//right sub array
    }
}
int main()
{
    int A[]={4,3,7,9,2,6,0,1};
    int n=8;
    printArray(A,n);
    printf("Sorted arry is :\n");
    QuickSort(A,0,n-1);
    printArray(A,n);
    return 0;
}

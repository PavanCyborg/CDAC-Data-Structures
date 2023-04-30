#include<stdio.h>
void printArray(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}
void merge(int A[],int low,int mid,int high)
{
    int i,j,k,B[100];
    i=low;j=mid+1;k=low;
    while(i<=mid && j<=high)
    {
        if(A[i]<A[j])
        {
            B[k]=A[i];
            i++;
            k++;
        }
        else
        {
            B[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        B[k]=A[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        B[k]=A[j];
        k++;
        j++;
    }
    for(i=0;i<=high;i++)
    {
        A[i]=B[i];
    }
}
void MergeSort(int A[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}
int main()
{
    int A[]={4,3,7,9,2,6,0,1};
    int n=8;
    printArray(A,n);
    printf("Sorted arry is :\n");
    MergeSort(A,0,n-1);
    printArray(A,n);
    return 0;
}

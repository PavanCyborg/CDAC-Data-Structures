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
void InsertionSort(int A[],int n)
{
    int i,j,temp;
    for(i=1;i<=n-1;i++)  // We are starting from 1 because we are assuming "This is Loop for Passes"
    {                   // 1st element is in sorted array & remaining are in unsorted array
        temp=A[i];      //Array is {4,3,7,9,2,6,0,1} index-0 -> 4 & index-(n-1) ->1. 
        //In 1st iteration a[1]=3 is stored in temp & j is a limiter pointing to index-0.
        j=i-1;          
        while(j>=0 && A[j]>temp)
        {
            swap(&A[j],&A[j+1]);
            j--;
        }
        
    }                    
}
int main()
{
    int A[]={4,3,7,9,2,6,0,1};
    int n=8;
    printArray(A,n);
    printf("Sorted arry is :\n");
    InsertionSort(A,n);
    printArray(A,n);
    return 0;
}

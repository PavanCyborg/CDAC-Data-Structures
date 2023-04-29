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
void bubbleSort(int A[],int n)
{
    int i=0,j=0;
    for(i=0;i<n-1;i++) //Because we have n-1 Passes
    {
        for(j=0;j<n-i-1;j++) //For n-i-1 steps
        {
            if(A[j]>A[j+1])
                swap(&A[j],&A[j+1]);
        }
    }
}
int main()
{
    int A[]={4,3,7,9,2,6,0,1};
    int n=8;
    printArray(A,n);
    printf("Sorted arry is :\n");
    bubbleSort(A,n);
    printArray(A,n);
    return 0;
}

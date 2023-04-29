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
void SelectionSort(int A[],int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++) //Because we have n-1 Passes
    {
        min=i;
        for(j=i;j<n;j++) //For n-i-1 steps
        {
            if(A[j]<A[min])
                swap(&A[j],&A[min]);
        }
    }
}
int main()
{
    int A[]={4,3,7,9,2,6,0,1};
    int n=8;
    printArray(A,n);
    printf("Sorted arry is :\n");
    SelectionSort(A,n);
    printArray(A,n);
    return 0;
}

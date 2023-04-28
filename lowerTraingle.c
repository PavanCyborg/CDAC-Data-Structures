#include<stdio.h>
int main()
{
    int m,n,i,j,sum=0;
    printf("Enter the size of matrix m and n:\n");
    printf("Note: The matrix should be square Matrix.....\n");
    scanf("%d %d",&m,&n);
    int arr[m][n];
    printf("Enter the array elements:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Array Elements are:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("a%d%d : %d \t",i,j,arr[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<=i;j++)
        {
            sum+=arr[i][j];
        }
    }
    if(m==n)
        printf("Sum of lower triangular elements is : %d",sum);
    else
        printf("Given matrix is not square matrix. Diagonal only exists for square matrix.\n");
    return 0;
}
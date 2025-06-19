//make an array and take  rows & columns as input from the user 
#include <stdio.h>
int main()
{
   int rows,cols;
   printf("enter no. of rows");
   scanf("%d",&rows);
    printf("enter no. of columns");
    scanf("%d",&cols);
    int arr[rows][cols];
    printf("enter the elements of the array:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("arr[%d][%d]=",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\nthe %d*%d array is:\n",i,j);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;


}


#include <stdio.h>

int main() 
{
    int rows, cols;

    // Taking user input for rows and columns
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Declaring a 2D array (Only works if VLAs are supported)
    int arr[rows][cols];

    // Taking input for the array elements
    printf("Enter the elements of the array:\n");
    int i,j;
    for ( i = 0; i < rows; i++)
	{
        for (j = 0; j < cols; j++) 
		{
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Corrected output statement
    printf("\nThe %d x %d array is:\n", rows, cols);
    for (i = 0; i < rows; i++)
	 {
        for ( j = 0; j < cols; j++)
	    {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}



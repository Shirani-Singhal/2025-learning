#include <stdio.h>

int main() {
    int a[100], n, i, search, found = 0;

    // Input the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);  // Corrected syntax

    // Input array elements
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Input the search element
    printf("Enter the number to search: ");
    scanf("%d", &search);

    // Perform linear search
    for (i = 0; i < n; i++) {
        if (a[i] == search) {
            found = 1;
            break; // Exit loop when the element is found
        }
    }

    // Output the result
    if (found)
        printf("Element found at position %d.\n", i + 1);  // Using 1-based index for user clarity
    else
        printf("Element not found.\n");

    return 0;
}

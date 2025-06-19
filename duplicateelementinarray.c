#include <stdio.h>

int main() {
    int n;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Using Variable Length Array (VLA)

    // Input elements
    printf("Enter the elements:\n");
    int i,j;
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Finding duplicates
    printf("Duplicate elements in the array: ");
    int found = 0; // Flag to check if duplicates exist
    for ( i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                found = 1;
                break; // To avoid printing the same duplicate multiple times
            }
        }
    }

    if (!found) {
        printf("None");
    }

    return 0;
}

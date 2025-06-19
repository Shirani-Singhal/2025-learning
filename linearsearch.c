#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index where the key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int n, key;
    
    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];

    // Input array elements
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the key to search for
    printf("Enter the number to search: ");
    scanf("%d", &key);

    // Call linear search function
    int result = linearSearch(arr, n, key);

    // Print result
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}

#include <stdio.h>

// Binary Search Function
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

      
        if (arr[mid] == target)
            return mid;

      
        else if (arr[mid] > target)
            high = mid - 1;

       
        else
            low = mid + 1;
    }

    return -1;
}

int main()
 {
    int arr[] = {2, 3, 4, 10, 15, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, 0, size - 1, target);

    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}

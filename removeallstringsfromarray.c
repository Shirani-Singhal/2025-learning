#include <stdio.h>
#include <string.h>

int main() {
    char str[100][100], srch[100];
    int n,i,j;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    // Input strings
    for ( i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", str[i]);
    }

    // Input the string to delete
    printf("Enter string to delete: ");
    scanf("%s", srch);

    // Deletion logic
    for ( i = 0; i < n; i++) {
        if (strcmp(str[i], srch) == 0) {
            // Shift all strings after i to left
            for ( j = i; j < n - 1; j++) {
                strcpy(str[j], str[j + 1]);
            }
            n--;    // Reduce the total count
            i--;    // Stay at the same index after shifting
        }
    }

    // Print remaining strings
    printf("Updated list of strings:\n");
    for ( i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}

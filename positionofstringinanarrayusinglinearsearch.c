#include <stdio.h>
#include <string.h>

int main() {
    int n,i, found = 0, position = -1;
    char srch[100];

    printf("Enter number of strings: ");
    scanf("%d", &n);

    char arr[n][100];

    printf("Enter strings:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    printf("Enter string to search: ");
    scanf("%s", srch);

    for ( i = 0; i < n; i++) {
        if (strcmp(arr[i], srch) == 0) {
            found = 1;
            position = i;
            break;
        }
    }

    if (found)
        printf("String found at position %d\n", position);
    else
        printf("String not found in the array\n");

    return 0;
}

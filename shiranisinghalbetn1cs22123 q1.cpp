#include <stdio.h>

int main() {
    int num;
    int sum = 0;

    // Read input until EOF
    while (scanf("%d", &num) != EOF) {
        if (num % 2 != 0) {  // Check if number is odd
            sum += num;
        }
    }

    printf("%d\n", sum);
    return 0;
}

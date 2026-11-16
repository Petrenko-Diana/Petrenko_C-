//(г)
#include <stdio.h>
#include <stdbool.h>

// Функція для перевірки, чи є число цілим ступенем двійки
bool isPowerOfTwo(int x) {
    if (x <= 0) return false;
    return (x & (x - 1)) == 0;
}

int main() {
    int n;
    printf("Enter the size of the array N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int count = 0;
    printf("Enter %d natural numbers:\n", n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (isPowerOfTwo(x)) {
            count++;
        }
    }

    printf("Number of elements that are powers of two: %d\n", count);
    return 0;
}

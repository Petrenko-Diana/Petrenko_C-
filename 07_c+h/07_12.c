#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter the size of the array N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int *A = (int *)malloc(n * sizeof(int));
    if (A == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Знаходимо максимальну частоту повторення елементів
    int max_freq = 0;
    for (int i = 0; i < n; i++) {
        int freq = 0;
        for (int j = 0; j < n; j++) {
            if (A[i] == A[j]) {
                freq++;
            }
        }
        if (freq > max_freq) {
            max_freq = freq;
        }
    }

    // Виводимо всі елементи, чия частота дорівнює max_freq
    printf("Mode(s) (max frequency %d):\n", max_freq);
    int printed_count = 0;
    for (int i = 0; i < n; i++) {
        int already_printed = 0;
        for (int k = 0; k < i; k++) {
            if (A[k] == A[i]) {
                already_printed = 1;
                break;
            }
        }
        if (already_printed) continue;

        // Рахуємо частоту поточного елемента
        int freq = 0;
        for (int j = 0; j < n; j++) {
            if (A[i] == A[j]) {
                freq++;
            }
        }

        if (freq == max_freq) {
            printf("%d ", A[i]);
            printed_count++;
        }
    }
    printf("\n");

    free(A);
    return 0;
}
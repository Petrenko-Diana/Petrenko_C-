#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    printf("Enter rows (n) and columns (m): ");
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("Invalid dimensions\n");
        return 1;
    }

    // Виділення пам'яті для матриці
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the matrix elements (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Знаходимо максимальний елемент для кожного стовпця
    int *max_col = (int *)malloc(m * sizeof(int));
    for (int j = 0; j < m; j++) {
        int max_val = matrix[0][j];
        for (int i = 1; i < n; i++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
            }
        }
        max_col[j] = max_val;
    }

    // Переставляємо рядки так, щоб рядки з максимумами опинилися на останньому місці
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == max_col[j] && i != n - 1) {
                int *temp = matrix[i];
                matrix[i] = matrix[n - 1];
                matrix[n - 1] = temp;
                break;
            }
        }
    }

    printf("\nModified matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Звільнення пам'яті
    free(max_col);
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
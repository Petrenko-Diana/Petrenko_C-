#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    printf("Enter rows (n) and columns (m): ");
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("Invalid dimensions\n");
        return 1;
    }

    // Виділення пам'яті для вихідної матриці n x m
    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(m * sizeof(double));
    }

    printf("Enter the matrix elements (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // 3находження стовпця з найбільшою сумою елементів
    int max_col_idx = 0;
    double max_sum = 0.0;

    for (int j = 0; j < m; j++) {
        double current_sum = 0.0;
        for (int i = 0; i < n; i++) {
            current_sum += matrix[i][j];
        }
        if (j == 0 || current_sum > max_sum) {
            max_sum = current_sum;
            max_col_idx = j;
        }
    }

    printf("\nColumn with max sum is index %d (sum = %.2f)\n", max_col_idx, max_sum);

    // Створення нової матриці розміром n x (m + 1)
    double **new_matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        new_matrix[i] = (double *)malloc((m + 1) * sizeof(double));
    }

// (ч)
    for (int i = 0; i < n; i++) {
        int new_j = 0;
        for (int j = 0; j < m; j++) {
            new_matrix[i][new_j++] = matrix[i][j];
            
            if (j == max_col_idx) {
                new_matrix[i][new_j++] = 0.0; 
            }
        }
    }

    printf("\nMatrix after inserting new column after column %d:\n", max_col_idx);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m + 1; j++) {
            printf("%8.2f ", new_matrix[i][j]);
        }
        printf("\n");
    }

    //Звільнення динамічної пам'яті
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
        free(new_matrix[i]);
    }
    free(matrix);
    free(new_matrix);

    return 0;
}
#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double mat1[n][n], mat2[n][n], sum[n][n], prod[n][n];

    printf("Enter matrix 1:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &mat1[i][j]);

    printf("Enter matrix 2:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &mat2[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum[i][j] = mat1[i][j] + mat2[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prod[i][j] = 0;
            for (int k = 0; k < n; k++) {
                prod[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Sum:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%lf ", sum[i][j]);
        printf("\n");
    }

    printf("Product:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%lf ", prod[i][j]);
        printf("\n");
    }

    return 0;
}
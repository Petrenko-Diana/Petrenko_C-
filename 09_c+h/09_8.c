#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int run = 1;
    
    while (run) {
        int n;
        printf("\nEnter the size of the vector N (or 0 to exit): ");
        if (scanf("%d", &n) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        
        if (n == 0) {
            break;
        }
        
        if (n < 0) {
            printf("Size cannot be negative. Try again.\n");
            continue;
        }

        // Виділення динамічної пам'яті для дійсних чисел (double)
        double *arr = (double *)malloc(n * sizeof(double));
        if (arr == NULL) {
            printf("Memory allocation error!\n");
            return 1;
        }

        printf("Enter %d real numbers:\n", n);
        double sum = 0.0;
        for (int i = 0; i < n; i++) {
            scanf("%lf", &arr[i]);
            sum += arr[i];
        }

        // Обчислення середнього арифметичного та дисперсії
        double mean = sum / n;

        double variance_sum = 0.0;
        for (int i = 0; i < n; i++) {
            variance_sum += pow(arr[i] - mean, 2);
        }
        double variance = (n > 0) ? (variance_sum / n) : 0.0;

        printf("------------------------------------\n");
        printf("Arithmetic mean: %.4f\n", mean);
        printf("Variance (Dispersion): %.4f\n", variance);
        
        free(arr);
    }

    return 0;
}
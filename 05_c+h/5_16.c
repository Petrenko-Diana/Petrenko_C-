#include <stdio.h>
#include <math.h>

//k

int main() {
    double x, eps;

    // Введення x та перевірка (|x| < 1)
    printf("Enter x (|x| < 1): ");
    if (scanf("%lf", &x) != 1 || fabs(x) >= 1.0) {
        printf("Error: |x| must be less than 1!\n");
        return 1;
    }

    // Введення заданої точності eps
    printf("Enter precision eps: ");
    if (scanf("%lf", &eps) != 1 || eps <= 0) {
        printf("Error: invalid precision!\n");
        return 1;
    }

    double sum = 1.0; 
    int k = 1;

    // Цикл наближеного обчислення суми членів ряду за точністю eps
    while (1) {
        double current_term = 1.0;
        double sign = (k % 2 == 1) ? 1.0 : -1.0;
        
        if (k == 1) {
            current_term = 0.5 * x;
        } else {
            double num_prod = 1.0;
            for (int i = 1; i <= k - 1; i++) {
                num_prod *= (2.0 * i - 1.0);
            }
            double den_prod = 1.0;
            for (int i = 1; i <= k; i++) {
                den_prod *= (2.0 * i);
            }
            current_term = sign * (num_prod / den_prod) * pow(x, k);
        }

        // Припиняємо, якщо модуль члена стає меншим за точність eps
        if (fabs(current_term) < eps) {
            break;
        }

        sum += current_term;
        k++;
    }

    printf("\n Results\n");
    printf("Approximate sum  = %.6f\n", sum);
    printf("Value sqrt(1 + x) = %.6f\n", sqrt(1.0 + x));

    return 0;
}
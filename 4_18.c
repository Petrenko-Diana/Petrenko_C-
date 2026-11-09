#include <stdio.h>

int main() {
    double x;
    int n; // к-сть членів послідовності

    printf("Enter the value of x: ");
    if (scanf("%lf", &x) != 1) return 1;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("\n Calculating the elements of the sequence\n");

    // Для k = 0: x_0 = ((-1)^0 * x^0) / 0! = 1 / 1 = 1
    double current_el = 1.0; 

    for (int k = 0; k < n; k++) {
        printf("x_%d = %.6f\n", k, current_el);

        // Використовуєм рекурентну формулу: x_{k+1} = x_k * (-x^2) / ((2k + 1) * (2k + 2))
        current_el = current_el * (-x * x) / ((2.0 * k + 1.0) * (2.0 * k + 2.0));
    }

    return 0;
}
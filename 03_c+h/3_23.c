#include <stdio.h>
#include <math.h>

double softExponential(double a, double x) {
    if (a < 0) {
        return log(1.0 - a * (x + a)) / a;
    } else if (a == 0) {
        return x;
    } else {
        return (exp(a * x) - 1.0) / a + a;
    }
}

// Функція для похідної 
double softExponentialDerivative(double a, double x) {
    if (a < 0) {
        double denominator = 1.0 - a * (x + a);
        // Перевіряємо на наяність ділення на 0 чи безкінечність а також 0 під логорифмом
        if (denominator == 0) return INFINITY; 
        return -1.0 / denominator;
    } else if (a == 0) {
        return 1.0;
    } else {
        return exp(a * x);
    }
}

int main() {
    double a, x;

    printf("Enter parameter a: ");
    if (scanf("%lf", &a) != 1) return 1;

    printf("Enter the value of x: ");
    if (scanf("%lf", &x) != 1) return 1;

    double val = softExponential(a, x);
    double deriv = softExponentialDerivative(a, x);

    printf("\n Results: \n");
    printf("softExponential(%.2f, %.2f) = %.4f\n", a, x, val);
    printf("Derivative = %.4f\n", deriv);

    return 0;
}
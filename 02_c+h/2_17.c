#include <stdio.h>
#include <math.h>

// f(x) = sigmweight(x)
double sigmweight(double x) {
    return x / (1.0 + exp(-x));
}

// f'(x) = (1 / (1 + e^(-x))) + (x * e^(-x)) / (1 + e^(-x))^2
double sigmweight_derivative(double x) {
    double exp_neg_x = exp(-x);
    double denominator = 1.0 + exp_neg_x;
    double t1 = 1.0 / denominator;
    double t2 = (x * exp_neg_x) / (denominator * denominator);
    return t1 + t2;
}

int main() {
    double x;

    printf("Enter the value of x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Input error!\n");
        return 1;
    }

    double result = sigmweight(x);
    double deriv = sigmweight_derivative(x);

    printf("\nResult:\n");
    printf("f(%.2f) = %.4f\n", x, result);
    printf("f'(%.2f) = %.4f\n", x, deriv);

    return 0;
}
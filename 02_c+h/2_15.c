#include <stdio.h>
#include <math.h>

int main() {
    double x, y;

    printf("Enter the value of x: ");
    if (scanf("%lf", &x) != 1) return 1;

    printf("Enter the value of y: ");
    if (scanf("%lf", &y) != 1) return 1;

    // b) f(x, y) = x^2 * y^2 + x^3 * y^3 + x^4 * y^4 
    double res_b = pow(x * y, 2) + pow(x * y, 3) + pow(x * y, 4);

    // v) f(x, y) = x + y + x^2 + y^2 + x^3 + y^3 + x^4 + y^4 
    double res_v = x + y + pow(x, 2) + pow(y, 2) + pow(x, 3) + pow(y, 3) + pow(x, 4) + pow(y, 4);

    printf("\nResults:\n");
    printf("b) f(x, y) = %.2f\n", res_b);
    printf("v) f(x, y) = %.2f\n", res_v);

    return 0;
}
#include <stdio.h>

int main() {
    double x;
    printf("Input intrger x: ");
    scanf("%lf", &x);

    double x2 = x * x; //x^2 = x * x
    double x3 = x2 * x; //x^3 = x^2 * x
    double x5 = x3 * x2; //x^5 = x^3 * x^2
    double x10 = x5 * x5; //x^10 = x^5 * x^5
    double x15 = x10 * x5; //x^15 = x^10 * x^5

    printf("x^15 = %lf\n", x15);
}
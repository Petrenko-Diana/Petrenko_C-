#include <stdio.h>
#include <math.h> // fabs, floor, ceil, round functions

double avg(double a, double b) {
    return (a + b) / 2.0;
}

double harmonic(double a, double b) {
    return 2.0 / ((1.0 / a) + (1.0 / b));
}

int main() {
    double x, y;
    
    printf("Input real x, y:\n");
    scanf("%lf %lf", &x, &y);

    printf("Difference: %lf\n", x - y);
    printf("Multiplication: %lf\n", x * y);
    printf("Average: %lf\n", avg(x, y));
    printf("Harmonic: %lf\n", harmonic(x, y));
}
#include <stdio.h>
#include <math.h>

double calc(double x, unsigned n) {
    double sum = 0.0;
    
    for (int i = n; i >= 0; i--) {
        sum += pow(x, i);
    }
    
    return sum;
}

int main() {
    unsigned n = 3;
    double x = 2.0;

    double result = calc(x, n);

    printf("For n = %u, x = %.1lf\n", n, x);
    printf("The result is: %.1lf\n", result);

    return 0;
}

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int task5() {
    int x1, x2, x3, x, k = 4;
    x1 = x2 = x3 = -99;
    x = x1 + x3 + 100;
    while (x <= 0) {
        x = x1 + x3 + 100;
        x1 = x2;
        x2 = x3;
        x3 = x;
        k++;
    }
    printf("the first x greater 0 is");
    printf("x =&d with index %d", x, k);
}

double continious_fraction(double b, int n) {
    double y = b + 1 / b;
    for (int i = 0; i < n; i++) {
        y = b + 1 / y;
    }
    return y;
}

double sum_culc(int n) {
    double a1, a2, a, b1, b2, b, sum, pow;
    sum = 2 / (a1 = b1);
    if (n == 1) return sum;

    a1 = 0; a2 = 1;
    b1 = 1; b2 = 0;

    pow = 4;
    sum += 4 / (a2 = b2);
    if ( n == 2) return sum;

    for (int k = 2; k <= n; k++) {
        b = b2 + a2;
        a = a2 / k + b;
        a1 = a2; a2 = a;
        b1 = b2; b2 = b;
        pow *= 2;
        sum += pow / (a + b);
    }
    return sum;
}

double tailor_exp(double x, double eps) {
    double term = 1.0, sum = term;
    int k = 1;
    while (fabs(term) > eps/2) {
        term *= (x / k);
        k++;
        sum += term;
    }
    return sum;
}
#include <stdio.h>
#include <math.h>

double a(unsigned n) {
    double rez = 0.0;
    for (unsigned i = 0; i < n; i++) {
        rez = sqrt(2.0 + rez);
    }
    return rez;
}

double b(unsigned n) {
    double rez = 0.0;
    for (unsigned i = n; i >= 1; i--) {
        rez = sqrt(3.0 * i + rez);
    }
    return rez;
}

int main() {
    unsigned n;
    printf("Input n: ");
    scanf("%u", &n);

    double rez_a = a(n);
    double rez_b = b(n);

    printf("a: %lf\n", rez_a);
    printf("b: %lf\n", rez_b);

    return 0;
}

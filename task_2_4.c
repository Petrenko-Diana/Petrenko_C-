#include <stdio.h>

double calc(double x) {
    //x * (x * (x * (x + 1) + 1) + 1) + 1
    return x * (x * (x * (x + 1) + 1) + 1) + 1;
}

int main() {
    double x, y;

    printf("Input x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Incorrect number\n");
        return 1;
    }

    y = calc(x);
    printf("Result: y = %lf\n", y);

    return 0;
}

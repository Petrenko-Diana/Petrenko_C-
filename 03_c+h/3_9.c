#include <stdio.h>
#include <math.h>

int main() {
    double x, y, z;

    printf("Enter the value of x: ");
    if (scanf("%lf", &x) != 1) return 1;

    printf("Enter the value of y: ");
    if (scanf("%lf", &y) != 1) return 1;

    printf("Enter the value of z: ");
    if (scanf("%lf", &z) != 1) return 1;

    // а) max(x + y + z, xy - xz + yz, xyz)
    double t1 = x + y + z;
    double t2 = x * y - x * z + y * z;
    double t3 = x * y * z;

    // Скористаємось послідовним порівнянням через fmax
    double res_a = fmax(fmax(t1, t2), t3);

    // б) max(xy, xz, yz)
    double p1 = x * y;
    double p2 = x * z;
    double p3 = y * z;

    double res_b = fmax(fmax(p1, p2), p3);

    printf("\n Results: \n");
    printf("a) max(x+y+z, xy-xz+yz, xyz) = %.2f\n", res_a);
    printf("b) max(xy, xz, yz) = %.2f\n", res_b);

    return 0;
}
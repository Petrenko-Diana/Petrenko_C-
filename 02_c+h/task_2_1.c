#include <stdio.h>
#include <math.h> // fabs, floor, ceil, round functions

int main(){
    double x, y;
    printf("Input real x:\n");
    scanf("%lf", &x);

    y = cosh(x);
    printf("Cosh: %lf\n", y);
}

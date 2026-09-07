#include <stdio.h>
#include <math.h>

int main(){
    double x;
    printf("Input real x:");
    scanf("%1f", &x);
    
    int x_int = (int) x; // Integer cast
    printf("Integer part: %d", x_int);

    double fractional_part = x - x_int;
    printf("\nFractional part: %lf", fabs(fractional_part)); // Absolute value of the fractional part

    int x_floor = floor(x); // max integer less than or equal to x
    printf("\nFloor value: %d", x_floor);

    int x_ceil = ceil(x); // min integer greater than or equal to x
    printf("\nCeil value: %d", x_ceil);

    int x_round = round(x); // nearest integer to x
    printf("\nRound value: %d", x_round);

    return 0;
}
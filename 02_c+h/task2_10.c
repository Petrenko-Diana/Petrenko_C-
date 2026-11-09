#include <stdio.h>
#include <math.h> 

const double M_PI = 3.14159265358979323846;

int main() {
    double a, b, c;
    printf("Enter the lengths of the three sides of the triangle (a b c): ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    double alpha, beta, gamma;
    double alpha_rad = acos((b*b + c*c - a*a) / (2*b*c));
    double beta_rad  = acos((a*a + c*c - b*b) / (2*a*c));
    double gamma_rad = acos((a*a + b*b - c*c) / (2*a*b));
    
    alpha = alpha_rad * (180.0 / M_PI);
    beta  = beta_rad * (180.0 / M_PI);
    gamma = gamma_rad * (180.0 / M_PI);
    
    printf("The angles of the triangle are: %.2f, %.2f, %.2f radians\n", alpha_rad, beta_rad, gamma_rad);
    printf("The angles of the triangle are: %.2f, %.2f, %.2f degrees\n", alpha, beta, gamma);
    
    return 0;
}

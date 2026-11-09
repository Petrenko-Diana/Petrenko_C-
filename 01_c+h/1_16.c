#include <stdio.h>
#include <math.h>

//(ширина 10 символів, вирівнювання по центру)
void printTextCell(const char* text) {
    printf("|%10s ", text);
}

void printDoubleCell(double value) {
    printf("|%10.2f ", value);
}

void printIntCell(double value) {
    printf("|%10d ", (int)value);
}

int main() {
    double x_values[] = {-1.0, -2.0, -3.0, -4.0, -5.0};
    int n = 5;
    int i;

    // a): F(x) = e^(-x^2) 
    printf("a) F(x) = exp(-x^2):\n");
    
    // Рядок x
    printTextCell("x");
    for (i = 0; i < n; i++) {
        printIntCell(x_values[i]);
    }
    printf("|\n");

    printf("------------------------------------------------------------------------\n");

    // Рядок F(x)
    printTextCell("F(x)");
    for (i = 0; i < n; i++) {
        double y = exp(-x_values[i] * x_values[i]);
        printDoubleCell(y);
    }
    printf("|\n\n");

    // б): F(x) = sqrt(|x|)
    printf("b) F(x) = sqrt(|x|):\n");
    
    printTextCell("x");
    for (i = 0; i < n; i++) {
        printIntCell(x_values[i]);
    }
    printf("|\n");

    printf("------------------------------------------------------------------------\n");

    printTextCell("F(x)");
    for (i = 0; i < n; i++) {
        double y = sqrt(fabs(x_values[i]));
        printDoubleCell(y);
    }
    printf("|\n");

    
    return 0;
}
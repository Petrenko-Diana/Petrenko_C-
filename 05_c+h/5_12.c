#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Incorrect n!\n");
        return 1;
    }

    double sum = 0.0;

    // Для k = 1
    double a_2 = 0; 
    double a_1 = 1.0; 
    double b_1 = 1.0; 
    
    double power_2 = 1.0; // 2^k
    double factorial = 1.0;  // k!

    for (int k = 1; k <= n; k++) {
        double ak, bk;

        if (k == 1) {
            ak = 1.0;
            bk = 1.0;
        } else if (k == 2) {
            //рекурента формула a_2 = 3*a_1 + 2*a_0
            ak = 3.0 * a_1 + 2.0 * 1.0; // зсув
            bk = 2.0 * a_1 + b_1;
        } else {
            // Для k >= 3
            ak = 3.0 * a_1 + 2.0 * a_2;
            bk = 2.0 * a_1 + b_1;
        }

        // Оновлюємо значення для наступної ітерації
        if (k > 1) {
            a_2 = a_1;
            a_1 = ak;
            b_1 = bk;
        }

        //2^k та k!
        power_2 *= 2.0;
        factorial *= k;

        double term = power_2 / ((1.0 + ak + bk) * factorial);
        sum += term;
    }

    printf("\nResults:\n");
    printf("Summ S_%d = %.6f\n", n, sum);

    return 0;
}

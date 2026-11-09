#include <stdio.h>

int main() {
    long long n, m;

    printf("Enter numerator n: ");
    if (scanf("%lld", &n) != 1) return 1;

    printf("Enter denominator m: ");
    if (scanf("%lld", &m) != 1 || m == 0) {
        printf("Invalid denominator!\n");
        return 1;
    }

    printf("\n Results: \n");
    printf("%lld / %lld = %lld", n, m, n / m);

    long long remainder = n % m;
    if (remainder == 0) {
        printf(".0 (finite fraction)\n");
        return 0;
    }

    printf(".");

    // Масиви для збереження залишків та позицій їх появи
    long long remainders[100000];
    long long positions[100000];
    
    for (int i = 0; i < m; i++) {
        positions[i] = -1;
    }

    int index = 0;
    while (remainder != 0 && positions[remainder] == -1) {
        positions[remainder] = index;
        remainders[index] = remainder;
        
        remainder *= 10;
        printf("%lld", remainder / m);
        
        remainder %= m;
        index++;
    }

    if (remainder == 0) {
        printf(" (finite fraction)\n");
    } else {
        printf(" (repeating, period length: %d)\n", index - (int)positions[remainder]);
    }

    return 0;
}
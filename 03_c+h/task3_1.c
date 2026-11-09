#include <stdio.h>

int digits_sum(short unsigned n) {
    short unsigned hundreds = n / 100; // integer division to get hundreds place
    short unsigned tens = (n / 10) % 10;
    short unsigned units = n % 10;
    return hundreds + tens + units;
}

int inverse_number(short unsigned n) {
    short unsigned hundreds = n / 100; // integer division to get hundreds place
    short unsigned tens = (n / 10) % 10;
    short unsigned units = n % 10;
    return units * 100 + tens * 10 + hundreds;
}


int main() {
    short unsigned n; 
    
    printf("Enter 3-digit number: ");
    scanf("%hu", &n);
    
    short unsigned hundreds = n / 100;
    short unsigned tens = (n / 10) % 10;
    short unsigned units = n % 10;
    
    printf("Hundreds: %hu\n", hundreds);
    printf("Tens: %hu\n", tens);
    printf("Units: %hu\n", units);
}

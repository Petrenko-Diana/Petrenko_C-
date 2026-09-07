#include <stdio.h>
#include <stdint.h> // for fixed-width integer types like uint8_t, uint16_t, int32_t etc.


/*
C Integer types: 
Usual (most likely 4 bytes):
int - integer  %d
unsigned - unsigned integer (natural number) %u

Short (most likely 2 bytes): 
short - short integer
unsigned short - unsigned short integer (natural number) 2^16 >1000

Very short ( 1 byte):
char - very short integer
unsigned char - unsigned very short integer (natural number)

Long (most likely 4 or 8 bytes):
long long - long long integer - %lld
unsigned long long - unsigned long integer (natural number) %llu

long long

sizeof() - operator to get the size of a data type or variable in bytes


*/

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
    //int n; // integer type  
    short unsigned n; // unsigned integer (natural number) 

    printf("Enter 3-digit number: ");
    scanf("%hu", &n);

    if(n < 100 || n > 999) {
        printf("Error: Number is not a 3-digit number.\n");
        return 1;
    }
    
    short unsigned hundreds = n / 100; // integer division to get hundreds place
    short unsigned tens = (n / 10) % 10;
    short unsigned units = n % 10;

    printf("Hundreds: %hu\n", hundreds);
    printf("Tens: %hu\n", tens);
    printf("Units: %hu\n", units);
    printf("Sum of digits: %d\n", digits_sum(n));
    printf("Inverse number: %d\n", inverse_number(n));

    printf("Size of n: %zu bytes\n", sizeof(n));
}
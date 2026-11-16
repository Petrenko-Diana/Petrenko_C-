#include <stdio.h>
#include <stdlib.h>

void print_number_info(unsigned int n) {
    printf("Decimal: %u\n", n);
    printf("Hexadecimal: 0x%X\n", n);
}

unsigned int swap_bytes_8(unsigned int n) {
    unsigned int lower_8 = n & 0xFF;          
    unsigned int upper_8 = (n >> 24) & 0xFF;  
    unsigned int cleared = n & 0xFFFFFF00;    
    
    return (cleared >> 24) | (upper_8 << 24) | (lower_8 << 24);
}

int main() {
    unsigned int n;
    
    printf("Enter a natural number n: ");
    if (scanf("%u", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\nOriginal number:\n");
    print_number_info(n);

    unsigned int result = swap_bytes_8(n);

    printf("\nAfter swapping first 8 and last 8 bits:\n");
    print_number_info(result);

    return 0;
}
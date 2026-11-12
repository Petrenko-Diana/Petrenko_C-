#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int task1_a(double a) {
    int k = 1;
    double sum - 0.0;
    while (sum < a) {
        sum += 1.0 / k;
        k++;
    }
    return k;
}

int task1() {
    double a;
    printf("a=");
    scanf_s("%lf", &a);
    int n = task1_a(a);
    printf("First n,"
    "that makes harmonic row greater than"
    "%lf is %d\n", a, n);
    return EXIT_SUCCESS; // 0
}

unsigned long long fobonacci(int n){
    unsigned long long f0, f1, f;
    f0 = 1UL;
    f1 = 1UL;

    f = f0 + f1;
    for(int k=2;k<=n;k++){
        f = f0 + f1;
        f0 = f1; f1 = f;
    }
    return f;
}

int task2_a() {

    int n;
    printf("n=");
    if (scanf("%d", &n) != 1) {
        printf("Incorrect input");
        return -1;
    }
    unsigned long long f = fibonacci(n);
    printf("F(%d)=%llu\n", n, f);
}


int find_max_fib_index(int a) {
    if (a < 0) {
        return -1;
    }

    int f0 = 0;
    int f1 = 1;
    int index = 0;

    while (f1 <= a) {
        int next = f0 + f1;
        f0 = f1;
        f1 = next;
        index++;
    }

    return index;
}

int task6() {
    int a;
    printf("a=");
    scanf("%d",&a);
    int result = find_max_fib_index(a);

    if (result != -1) {
        printf("%d\n",result);
    } else {
        printf(" 0\n");
    }

    return 0;
}

 
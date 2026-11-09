#include <stdio.h>
#include <math.h>


int main() {
    //Обчислюємо дріб знизу вгору :
    double part1 = 1.0 + 1.0 / 3.0;
    double part2 = 7.0 + 1.0 / part1;
    double part3 = 4.0 + 1.0 / part2;
    
    double T = 365.0 + 1.0 / part3;
    
    printf("Rotaition period (T) = %.6f days\n", T);
    
    return 0;
}



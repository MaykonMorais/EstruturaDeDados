#include <stdio.h>

void factorial(int num) {
    int i = 1;
    double factor = 1;
    for(i; i <= num; i++) {
        factor *= i;
        
    }

    printf("%d! = %.2f\n", num, factor);
}
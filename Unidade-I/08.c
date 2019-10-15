#include <stdio.h>

int main() {
    double x, y;
    printf("Digite um numero: ");
    scanf("%lf", &x);
    
    printf("Digite outro numero: ");
    scanf("%lf", &y);

    if(y == 0) {
        printf("Divisao impossivel");
    } else {
        double result = x / y;
        printf("%.2f / %.2f = %.2f", x, y, result);
    }
    return 0;
}

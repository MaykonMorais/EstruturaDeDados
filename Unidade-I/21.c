#include <stdio.h>
#include "21.h"
int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    factorial(num);
    return 0;
}

#include <stdio.h>

void somatorio(int num1, int num2);
int main() {
    int num1, num2;

    printf("Digite o inicio: ");
    scanf("%d", &num1);

    printf("Digite o final: ");
    scanf("%d", &num2);

    somatorio(num1, num2);
    return 0;
}

void somatorio(int num1, int num2) {
    int summation = 0;
    for(num1; num1 <= num2; num1++) {
        summation += num1;
    } 
    printf("Somatório: %d\n", summation);
}
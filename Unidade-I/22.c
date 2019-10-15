#include <stdio.h>
void verificaPrimo(int num);

int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);
    verificaPrimo(num);

    return 0;
}
void verificaPrimo(int num) {
    int i = 1;
    int teste = 0;
    for(i; i <= num; i++) {
        if((num % i == 0)) { // se é primo
            ++teste;
        }
    }

    if(teste == 2) {
        printf("O numero eh primo\n");
    } else {
        printf("O numero nao eh primo\n");
    }
}
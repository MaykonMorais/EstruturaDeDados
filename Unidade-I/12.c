#include <stdio.h>
void transfer(double * conta1, double * conta2, double valor);

int main() {
    double conta1 = 100;
    double conta2 = 100;
    double valor;

    printf("======= Area de Transferencia: ======= \nDigite a quantidade Desejada Para Transferencia: R$ ");
    scanf("%lf", &valor);
    
    transfer(&conta1, &conta2, valor);
    
    printf("\nConta 1: R$ %.2f\n", conta1);
    printf("Conta 2: R$ %.2f\n", conta2);

    return 0;
}
void transfer(double * conta1, double * conta2, double valor) {
    if(valor <= *conta1) {
        *conta1-=valor;
        *conta2+=valor;
        printf("Transferencia realizada com sucesso!");
    } else {
        printf("Valor Muito alto, digite um valor menor");
    }
}
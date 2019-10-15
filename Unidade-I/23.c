#include <stdio.h>
#include <math.h>
#include "21.h"

int main() {
    int sair = 0;
    
    int opcao = 0;
    do {
        int num;
        int expoente;
        printf("\n1 - Potenciacao\n2 - Raiz Quadrada\n3 - Fatorial\n0 - Sair\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um numero: ");
            scanf("%d", &num);
            
            printf("Digite a Expoente: ");
            scanf("%d", &expoente);

            printf("%d^%d = %.2f\n", num, expoente, pow(num, expoente));
            break;
        case 2:
            printf("Digite um numero: ");
            scanf("%d", &num);
            printf("Raiz Quadrada de %d = %.2f\n", num, sqrt(num));
            break;

        case 3: 
            printf("Digite um numero: ");
            scanf("%d", &num);
            factorial(num);
            break;
        case 4:
            printf("Saindo...\n");
            sair = 1;
            break;
        default:
            printf("Digite uma opcao valida");
            break;
        }
    } while(opcao != 0);

    return 0;
}
#include <stdio.h>

int main() {
    int idade;
    char nomeCompleto[20];
    float altura;
    char letraNome;

    printf("Digite seu nome Completo: ");
    fgets(nomeCompleto, 20, stdin);

    printf("Digite a primeira letra do seu nome: ");
    scanf("%c", &letraNome);
    
    fseek(stdin, 0, SEEK_END); // clear keyboard buffer

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua altura: ");
    scanf("%f", &altura);

    printf("\n\nDados Pessoais\n");

    printf("Primeira Letra: %c\n", letraNome);
    printf("Nome Completo: %s", nomeCompleto);
    printf("Idade: %d\n", idade);
    printf("Altura: %.2f\n", altura);

    return 0;
}

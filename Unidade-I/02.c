#include <stdio.h>

int main() {
    int idade = 21;
    char nomeCompleto[20] = "Maykon Morais";
    float altura = 1.8;
    char letraNome = nomeCompleto[0];

    printf("Primeira Letra: %c\n", letraNome);
    printf("Nome Completo: %s\n", nomeCompleto);
    printf("Idade: %d\n", idade);
    printf("Altura: %.2f\n", altura);

    return 0;
}
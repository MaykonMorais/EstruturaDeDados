#include <stdio.h>
#include <stdlib.h>

int main() {
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    int * vet = (int *)malloc(tam * sizeof(int)); // alocação dinamica

    int i = 1;
    for(i; i < tam; i++) { // vetor irá ser preenchido automaticamente
        vet[i] = i * 2;
    }

    size_t tamanhoVetor= sizeof(vet) / sizeof(int); // tamanho do vetor calculado
    
    i = 1;
    for(i; i < tam; i++) {
        printf(" %d", vet[i]);
    }
    return 0;
}
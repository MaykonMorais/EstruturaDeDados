#include <stdio.h>
#include <stdlib.h>

int * vetorInverso(int * vet, int tam);
int main() {
    int vet[] = {2, 4, 6, 8, 10};

    int tam = sizeof(vet) / sizeof(int);

    printf("Vetor normal: ");
    int i = 0;
    for(i; i < tam; i++) {
        printf(" %d", vet[i]);
    }
    printf("\nVetor Invertido: ");

    int * inverso =  vetorInverso(vet, tam);

    
    i = 0;
    for(i; i < tam; i++) {
        printf(" %d", inverso[i]);
    }
    printf("\n");
    return 0;
}
int * vetorInverso(int * vet, int tam) {
    int * inverso = (int *)malloc(tam * sizeof(int)); 

    int i = 0;
    for(i; i < tam; i++) {
        inverso[i] = vet[tam-i-1];
    }
    return inverso;
}


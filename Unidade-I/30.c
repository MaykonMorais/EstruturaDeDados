#include <stdio.h>

int main() {
    int vet[] = {0, 1, 2, 3 , 4};

    int tam = sizeof(vet) / sizeof(int);
    int i = 1;
    
    for(i; i < tam; i++) {
        int intermediario = vet[tam-i-1];
        vet[tam-i-1] = vet[tam-i];

        vet[tam-i] = intermediario;
    }
    printf("Vetor: ");
    i = 0;
    for(i; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
    return 0;
}
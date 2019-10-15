#include <stdio.h>

int maior(int * vet, int tam);
int menor(int * vet, int tam);

int main() {
    int vet[] = {2,3,1,2,5,1};

    int tam = sizeof(vet) / sizeof(int);
    int i = 0;
    printf("Vetor: ");
    for(i; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\nMaior Numero: %d",maior(vet, tam));
    printf("\nMenor Numero: %d", menor(vet, tam));
    return 0;
}
int maior(int * vet, int tam) {
    int i = 0;
    int suspectNumber = 0;
    for(i; i < tam; i++) {
        if(vet[i] > suspectNumber) {
            suspectNumber = vet[i];
        }
    }
    return suspectNumber;
}
int menor(int * vet, int tam) {
    int i = 1;
    int suspectNumber = vet[0];
    for(i; i < tam; i++) {
        if(vet[i] < suspectNumber) {
            suspectNumber = vet[i];
        }
    }
    return suspectNumber;
}
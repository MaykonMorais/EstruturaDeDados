#include <stdio.h>

int main() {
    int vet[2][2];

    int i = 0;
    int j;
    printf("Preencha o valores da matriz 2x2 (linha): ");
    for(i; i < 2; i++) { // linha i
        j = 0;
        for(j; j < 2; j++) {
            scanf("%d", &vet[i][j]);
        }
    }

    i = 0;
    j = 0;
    for(i; i < 2; i++) { // linha
        for(j; j < 2; j++) {
            printf("%d ", vet[i][j]);
        }
        j = 0;
        printf("\n");
    }
    return 0;
}
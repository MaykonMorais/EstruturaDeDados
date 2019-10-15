#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas, colunas;

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &linhas);

    printf("Digite a quantidade de colunas: ");
    scanf("%d", &colunas);

    // vetor de ponteiros (linha)
    int ** pMatriz = (int **)malloc(linhas * sizeof(int *));

    int i = 0;
    // ponteiros de inteiros(coluna)
    for(i; i < linhas; i++) {
        pMatriz[i] = (int *) malloc(colunas * sizeof(int));
    }

    i = 0;
    int j = 0;
    for(i = 0; i < linhas; i++) {
        for(j; j < colunas; j++) {
            pMatriz[i][j] = pMatriz[i][j-1] + 4;
        }
        j = 0;
    }


    for(i = 0; i < linhas; i++) {
        for(j; j < colunas; j++) {
            printf("%d ", pMatriz[i][j]);
        }
        j = 0;
        printf("\n");
    }
    return 0;
}
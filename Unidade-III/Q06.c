#include <stdio.h>
#include <stdlib.h>

#define SIZE_ARRAY 5

typedef struct {
    int id;
    char nome[30];
} tPessoa;

void bubbleSort(tPessoa * pessoa, int tam);
void showArray(tPessoa pessoas[], int tam);

int main() {
    tPessoa pessoas[SIZE_ARRAY] = {// static array
                          {6, "Maria"},
                          {12, "Fernando"},
                          {1, "Lucas"},
                          {7, "Joao"},
                          {6, "Cristo"}};
    
    //showArray(pessoas, SIZE_ARRAY);
    
    printf("Vetor Ordenado\n");
    bubbleSort(pessoas, SIZE_ARRAY);
    //showArray(pessoas, SIZE_ARRAY);

    return 0;
}

void bubbleSort(tPessoa * pessoa, int tam) {
    int i;
    for(i = 0; i < tam-1; i++) {
        int j;
        for(j = 0; j < tam-1; i++) {
            if(pessoa[j].id > pessoa[j+1].id) {
              tPessoa temp = pessoa[j];
              pessoa[j] = pessoa[j+1];
              pessoa[j+1] = temp;  
            }
        }
    }
}
void showArray(tPessoa pessoas[], int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        printf("ID %d: %s", pessoas[i].id, pessoas[i].nome);
    }
}
#include <stdio.h>
#define SIZE_ARRAY 5

typedef struct
{
  int id;
  char nome[30];
} tPessoa;

void insertSort(tPessoa *pessoas, int tam);
void showArray(tPessoa pessoas[], int tam);

int main()
{
  tPessoa pessoas[SIZE_ARRAY] = {// static array
                                 {6, "Maria"},
                                 {12, "Fernando"},
                                 {1, "Lucas"},
                                 {7, "Joao"},
                                 {8, "Cristo"}};

  printf("Vetor desordenado...\n");
  showArray(pessoas, SIZE_ARRAY);

  insertSort(pessoas, SIZE_ARRAY);
  printf("\nVetor Ordenado...\n");
  showArray(pessoas, SIZE_ARRAY);
  return 0;
}

void insertSort(tPessoa *pessoas, int tam)
{
  int i;
  for (int i = 1; i <= tam - 1; i++)
  {
    tPessoa eleito = pessoas[i];
    int j = i - 1;

    while ((j >= 0) && (eleito.id) < pessoas[j].id)
    {
      pessoas[j + 1] = pessoas[j];
      j -= 1;
    }
    pessoas[j + 1] = eleito;
  }
}

void showArray(tPessoa pessoas[], int tam)
{
  int i;
  for (i = 0; i < tam; i++)
  {
    printf("ID %d: %s\n", pessoas[i].id, pessoas[i].nome);
  }
}

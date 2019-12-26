#include <stdio.h>

#define SIZE_ARRAY 5

typedef struct
{
  int id;
  char nome[30];
} tPessoa;

void selectSort(tPessoa *pessoas, int tam);
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

  selectSort(pessoas, SIZE_ARRAY);
  printf("\nVetor Ordenado...\n");
  showArray(pessoas, SIZE_ARRAY);

  return 0;
}

void selectSort(tPessoa *pessoas, int tam)
{
  int i;
  for (i = 0; i <= tam - 1; i++)
  {
    int menor = i;
    int j;

    for (j = i + 1; j <= tam - 1; j++)
    {
      if (pessoas[j].id < pessoas[menor].id)
      {
        menor = j;
      }
    }
    if (i != menor)
    {
      tPessoa temp = pessoas[i];
      pessoas[i] = pessoas[menor];
      pessoas[menor] = temp;
    }
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

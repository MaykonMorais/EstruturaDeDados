#include <stdio.h>

#define SIZE_ARRAY 5
typedef struct
{
  int id;
  char nome[30];
} tPessoa;
void shellSort(tPessoa *pessoas, int tam);
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

  shellSort(pessoas, SIZE_ARRAY);

  printf("\nVetor Ordenado...\n");
  showArray(pessoas, SIZE_ARRAY);
  return 0;
}
void shellSort(tPessoa *pessoas, int tam)
{
  int h = 0;
  while (h < tam)
  {
    h = 3 * h + 1;
  }

  while (h > 1)
  {
    h = h / 3;
    int i;

    for (i = h; i <= tam - 1; i++)
    {
      tPessoa eleito = pessoas[i];
      int j = i - h;

      while ((j >= 0) && (eleito.id < pessoas[j].id))
      {
        pessoas[j + h] = pessoas[j];
        j = j - h;
      }
      pessoas[j + h] = eleito;
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
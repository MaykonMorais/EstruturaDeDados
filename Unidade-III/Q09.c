#include <stdio.h>

#define SIZE_ARRAY 5
typedef struct
{
  int id;
  char nome[30];
} tPessoa;

void showArray(tPessoa pessoas[], int tam);
void quickSort(tPessoa *pessoas, int initArray, int Array);

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

  int init = 0;
  int end = SIZE_ARRAY - 1;

  quickSort(pessoas, init, end);
  printf("\nVetor Ordenado...\n");
  showArray(pessoas, SIZE_ARRAY);

  return 0;
}

void quickSort(tPessoa *pessoas, int initArray, int endArray)
{
  int i = initArray;
  int j = endArray;

  tPessoa pivo = pessoas[(initArray + endArray) / 2]; //  middle array (pivot)

  while (i < j)
  {
    while (pessoas[i].id < pivo.id)
    { // increase the init variable
      i += 1;
    }
    while (pessoas[j].id > pivo.id)
    { // decrease the end variable
      j -= 1;
    }

    if (i <= j)
    { // swap
      tPessoa aux = pessoas[i];
      pessoas[i] = pessoas[j];
      pessoas[j] = aux;

      i += 1;
      j -= 1;
    }
  }

  if (j > initArray)
  {
    quickSort(pessoas, initArray, j);
  }
  if (i < endArray)
  {
    quickSort(pessoas, i, endArray);
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
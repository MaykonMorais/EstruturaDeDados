#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE_ARRAY 100000

typedef struct
{
  int id;
  char nome[30];
} tPessoa;

void bubbleSort(tPessoa *pessoa, int tam);
void insertSort(tPessoa *pessoas, int tam);
void selectSort(tPessoa *pessoas, int tam);
void quickSort(tPessoa *pessoas, int initArray, int endArray);
void shellSort(tPessoa *pessoas, int tam);
void showArray(tPessoa pessoas[], int tam);
void generateArray(tPessoa pessoas[]);

int main()
{
  clock_t tInicio, tFim, tDecorrido;

  tPessoa pessoas[SIZE_ARRAY];
  generateArray(pessoas);

  tInicio = clock();
  bubbleSort(pessoas, SIZE_ARRAY);
  tFim = clock();

  tDecorrido = tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
  printf("Bubble Sort: %ld ms\n", tDecorrido);

  generateArray(pessoas);

  tInicio = clock();
  insertSort(pessoas, SIZE_ARRAY);
  tFim = clock();
  tDecorrido = tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
  printf("Insert Sort: %ld ms\n", tDecorrido);

  generateArray(pessoas);

  tInicio = clock();
  selectSort(pessoas, SIZE_ARRAY);
  tFim = clock();
  tDecorrido = tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
  printf("Select Sort: %ld ms\n", tDecorrido);

  generateArray(pessoas);

  tInicio = clock();
  quickSort(pessoas, 0, SIZE_ARRAY - 1);
  tFim = clock();
  tDecorrido = tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
  printf("Quick Sort: %ld ms\n", tDecorrido);

  generateArray(pessoas);

  tInicio = clock();
  shellSort(pessoas, SIZE_ARRAY);
  tFim = clock();
  tDecorrido = tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
  printf("Shell Sort: %ld ms\n", tDecorrido);

  return 0;
}

void generateArray(tPessoa *pessoas)
{
  int i;
  int j = SIZE_ARRAY - 1;
  for (i = 0; i < SIZE_ARRAY; i++, j--)
  {
    pessoas[i].id = j;
  }
}

void bubbleSort(tPessoa *pessoa, int tam)
{
  int i;
  for (int i = 0; i < tam - 1; i++)
  {
    int j = 0;
    for (int j = 0; j < tam - 1; j++)
    {
      if (pessoa[j].id > pessoa[j + 1].id)
      {
        tPessoa temp = pessoa[j];
        pessoa[j] = pessoa[j + 1];
        pessoa[j + 1] = temp;
      }
    }
  }
}

void insertSort(tPessoa *pessoas, int tam)
{
  int i;
  for (i = 1; i <= tam - 1; i++)
  {
    tPessoa eleito = pessoas[i];
    int j = i - 1;

    while ((j >= 0) && (eleito.id < pessoas[j].id))
    {
      pessoas[j + 1] = pessoas[j];
      j -= 1;
    }
    pessoas[j + 1] = eleito;
  }
}

void selectSort(tPessoa *pessoas, int tam)
{
  int i;
  for (i = 0; i <= tam - 1; i++)
  {
    int menor = i;
    int j;
    for (j = i + 1; j <= tam - 1; j++) // setando qual o menor numero
    {
      if (pessoas[j].id < pessoas[menor].id)
      {
        menor = j;
      }
    }

    if (i != menor) // trocando de lugar com o indice atual
    {
      tPessoa temp = pessoas[i];
      pessoas[i] = pessoas[menor];
      pessoas[menor] = temp;
    }
  }
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
    printf("%d° - ID %d: %s\n", i, pessoas[i].id, pessoas[i].nome);
  }
}
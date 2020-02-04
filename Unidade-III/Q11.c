#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

typedef struct
{
  int id;
  char nome[30];
} tPessoa;

void amontoar(tPessoa *pessoas, int size, int i);
void swap(tPessoa *element1, tPessoa *element2);
void heapSort(tPessoa *pessoas, int tam);
void showArray(tPessoa pessoas[], int tam);

int main()
{
  tPessoa *pessoas = (tPessoa *)calloc(SIZE, sizeof(tPessoa));

  pessoas[0].id = 2;
  strcpy(pessoas[0].nome, "Maria");

  pessoas[1].id = 5;
  strcpy(pessoas[0].nome, "Fernando");

  pessoas[2].id = 55;
  strcpy(pessoas[0].nome, "Denilson");

  pessoas[3].id = 1;
  strcpy(pessoas[3].nome, "Mateus");

  pessoas[4].id = 82;
  strcpy(pessoas[4].nome, "Joao");

  heapSort(pessoas, SIZE);
  printf("Vetor Organizado\n");
  showArray(pessoas, SIZE);

  return 0;
}

void amontoar(tPessoa *pessoas, int size, int i)
{
  int maior = i;
  int esquerda = 2 * i + 1;
  int direita = 2 * i + 2;

  if (esquerda < size && pessoas[esquerda].id > pessoas[maior].id)
  {
    maior = esquerda;
  }
  if (direita < size && pessoas[direita].id > pessoas[maior].id)
  {
    maior = direita;
  }

  if (maior != i)
  {
    swap(&pessoas[i], &pessoas[maior]);
    // chamada recursiva
    amontoar(pessoas, size, maior);
  }
}

// troca
void swap(tPessoa *element1, tPessoa *element2)
{
  tPessoa aux = *element1;
  element1 = element2;
  element2 = element1;
}
void heapSort(tPessoa *pessoas, int tam)
{
  int i;
  for (i = tam / 2 - 1; i >= 0; i--)
  {
    amontoar(pessoas, tam, i);

    for (i = tam - 1; i >= 0; i--)
    {
      swap(&pessoas[0], &pessoas[i]);

      amontoar(pessoas, tam, 0);
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
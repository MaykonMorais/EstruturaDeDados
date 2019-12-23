#include <stdio.h>

#define MAX 5

typedef struct
{
  int id;
  char nome[30];
} tPessoa;

int binarySearch(tPessoa *pessoas, int tam, int id);

int main()
{
  tPessoa pessoas[MAX] = {// static array
                          {1, "Maria"},
                          {2, "Fernando"},
                          {3, "Lucas"},
                          {4, "Joao"},
                          {5, "Cristo"}};

  int id;
  printf("Digite o ID desejado: ");
  scanf("%d", &id);

  int result = binarySearch(pessoas, MAX, id);

  printf("result: %d\n", result);
  if (result != -1)
  {
    printf("Pessoa encontrada: \nID: %d\nNome: %s\n", pessoas[result].id, pessoas[result].nome);
  }
  else
  {
    printf("Elemento nao encontrado!!\n");
  }

  return 0;
}

int binarySearch(tPessoa *pessoas, int tam, int id)
{
  int inicio = 0;
  int fim = tam - 1;
  int result = -1; // result of search array if will not find element  (default)

  while (inicio <= fim)
  {
    int meio = (inicio + fim) / 2;

    if (id < pessoas[meio].id)
    {
      fim = meio - 1;
    }
    else
    {
      if (id > pessoas[meio].id)
      {
        inicio = meio + 1;
      }
      else
      {
        inicio = tam; // stop search on the array
        result = meio;
      }
    }
  }
  return result;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int id;
  char nome[20];
} tPessoa;

int linearSearch(tPessoa *pessoas, int id, int tam);
void showPeoples(tPessoa pessoas[], int tam);

int main()
{
  int tam;
  printf("Digite a quantidade de pessoas que deseja adicionar: ");
  scanf("%d", &tam);

  tPessoa *pessoas = (tPessoa *)calloc(tam, sizeof(tPessoa));

  int i = 0;

  while (i < tam)
  {
    pessoas[i].id = i;
    printf("Digite %d o nome: ", i + 1);
    scanf("%s", pessoas[i].nome);

    i++;
  }

  showPeoples(pessoas, tam);
  int id;
  printf("\nDigite o ID desejado: ");
  scanf("%d", &id);

  int result = linearSearch(pessoas, id, tam);

  printf("result: %d\n", result);
  if (result != -1)
  {
    printf("\nPessoa encontrada: \nID: %d\nNome: %s\n", pessoas[result].id, pessoas[result].nome);
  }
  else
  {
    printf("Elemento nao encontrado!!\n");
  }

  return 0;
}

int linearSearch(tPessoa *pessoas, int id, int tam)
{
  int result = -1;
  int i = 0;
  for (i; i < tam; i++)
  {
    if (id == pessoas[i].id)
    {
      return i; // return position
    }
  }
  return result;
}

void showPeoples(tPessoa pessoas[], int tam)
{
  int i = 0;
  printf("\nPessoas Cadastradas: \n");
  for (i; i < tam; i++)
  {
    printf("ID: %d\nNome: %s\n", pessoas[i].id, pessoas[i].nome);
  }
}
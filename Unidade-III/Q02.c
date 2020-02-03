#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int id;
  char nome[20];
} tPessoa;

struct Node
{
  tPessoa pessoa;
  struct Node *next;
};

void adicionar(struct Node **cabeca, tPessoa pessoa);
linearSearch(struct Node *cabeca, int id);
void showPeoples(tPessoa pessoas[], int tam);

int main()
{
  struct Node *head = NULL;
  tPessoa pessoa;

  pessoa.id = 1;
  strcpy(pessoa.nome, "Maria");
  adicionar(&head, pessoa);

  pessoa.id = 8;
  strcpy(pessoa.nome, "Maria");
  adicionar(&head, pessoa);

  pessoa.id = 2;
  strcpy(pessoa.nome, "Maria");
  adicionar(&head, pessoa);

  linearSearch(head, 9) ? printf("SIM") : printf("NAO");
  return 0;
}
void adicionar(struct Node **cabeca, tPessoa pessoa)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  new_node->pessoa = pessoa;

  new_node->next = (*cabeca);

  (*cabeca) = new_node;
}
linearSearch(struct Node *cabeca, int id)
{
  struct Node *noAtual = cabeca;
  while (noAtual != NULL)
  {
    if (noAtual->pessoa.id == id)
    {
      return 1;
    }
    noAtual = noAtual->next;
  }
  return 0;
}

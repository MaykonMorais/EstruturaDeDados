#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int id;
  char nome[30];
  int valor;
} tDado;

typedef struct
{
  tDado dado;
  struct sElemento *proximo;
} tElemento;

void inserirInicio(tElemento **ppInicio, tDado dado)
{
  tElemento *pNovo = (tElemento *)calloc(1, sizeof(tElemento));

  pNovo->dado = dado;
  pNovo->dado.id = time(NULL);
  pNovo->proximo = NULL;

  if (*ppInicio == NULL)
  { // novo elemento sera o primeiro da lista
    *ppInicio = pNovo;
  }
  else
  {
    pNovo->proximo = *ppInicio;
    *ppInicio = pNovo;
  }
}
int percorrer(tElemento *pInicio)
{
  int i = 0;
  tElemento *p = pInicio->proximo;

  if (p == NULL)
  {
    return 0;
  }
  else
  {
    while (p != NULL)
    {
      i++;
      printf("i: %d\n", i);
      printf("ID: %d\n", p->dado.id);
      printf("Nome: %s\n", p->dado.nome);
      printf("Valor: %d\n", p->dado.valor);
      printf("\n");

      p = p->proximo;
    }
  }
  printf("Quantidade de elementos: %d\n", i);
  return i;
}

void inserirFim(tElemento **ppInicio, tDado dado)
{
  tElemento *pNovo = (tElemento *)calloc(1, sizeof(tElemento));

  pNovo->dado = dado;
  pNovo->dado.id = time(NULL);
  pNovo->proximo = NULL;

  if (*ppInicio == NULL)
  {
    *ppInicio = pNovo;
  }
  else
  {
    tElemento *p = *ppInicio;
    while (p->proximo != NULL)
    {
      p = p->proximo;
    }
    p->proximo = pNovo;
  }
}

tElemento *buscarAnterior(tElemento *pInicio, int id)
{
  tElemento *p = pInicio;
  tElemento *pAnterior = NULL;

  if (p->proximo == NULL)
  {
    printf("ID Encontrado!!\n");
    return NULL;
  }
  else
  {
    while (p->proximo != NULL)
    {
      pAnterior = p;
      p = p->proximo;

      if (p != NULL && p->dado.id == id)
      {
        return p;
      }
    }
    return NULL;
  }
}

void remover(tElemento **ppInicio, int id)
{
  tElemento *anterior = NULL;
  tElemento *atual = NULL;

  if (*ppInicio == NULL)
  {
    printf("Lista Vazia!!! \n");
    return;
  }

  anterior = buscarAnterior(*ppInicio, id); // NULL: ID no 1o elemento OU não existe

  if (anterior == NULL)
  {
    if ((*ppInicio)->dado.id == id)
    {
      atual = *ppInicio;

      if (atual->proximo == NULL)
      {
        *ppInicio = NULL;
      }
      else
      {
        printf("Remove o primeiro elemento \n");
        *ppInicio = atual->proximo;
        atual->proximo = NULL;
      }
    }
  }
  else
  {
    atual = anterior->proximo;

    anterior->proximo = atual->proximo;
    atual->proximo = NULL;
  }

  free(atual);
}

int main()
{
  tElemento *lista = NULL;
  tDado dado;

  strcpy(dado.nome, "Maria");
  dado.valor = 10;
  inserirInicio(&lista, dado);
  printf("Inserindo...\n");
  percorrer(lista);

  printf("\nInserindo..\n");
  strcpy(dado.nome, "Joao");
  dado.valor = 20;
  inserirFim(&lista, dado);

  percorrer(lista);
  return 0;
}
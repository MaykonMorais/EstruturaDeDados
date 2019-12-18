#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tDado
{
  char nome[20];
  float valor;
} tDado;

typedef struct tLista
{
  int id;
  tDado dado;
  struct tLista *listaProx;
  struct tLista *listaAnte;
} Lista;

void adicionarInicio(Lista **lista, tDado dado);
void adicionarFim(Lista **lista, tDado dado);
void remover(Lista **lista, int id);
void exibir(Lista **lista);
int getId(Lista **lista);
Lista *buscar(Lista *lista, int id);

int main()
{
  tDado dado[4];

  strcpy(dado[0].nome, "Maria");
  dado[0].valor = 19;

  strcpy(dado[1].nome, "Maykon");
  dado[1].valor = 12;

  strcpy(dado[2].nome, "Lucas");
  dado[2].valor = 130;

  strcpy(dado[3].nome, "Judson");
  dado[3].valor = 30;
  Lista *lista = NULL;

  adicionarInicio(&lista, dado[0]);
  adicionarInicio(&lista, dado[1]);
  adicionarFim(&lista, dado[2]);
  adicionarInicio(&lista, dado[3]);
  remover(&lista, 1);
  exibir(&lista);
  return 0;
}
void adicionarInicio(Lista **lista, tDado dado)
{
  Lista *pNovo = (Lista *)calloc(1, sizeof(Lista));
  pNovo->id = getId(lista);
  strcpy(pNovo->dado.nome, dado.nome);
  pNovo->dado.valor = dado.valor;

  if (*lista == NULL)
  {
    *lista = pNovo;
    pNovo->listaProx = NULL;
    pNovo->listaAnte = pNovo;
  }
  else
  {
    pNovo->listaProx = (*lista);
    pNovo->listaAnte = (*lista)->listaAnte;
    (*lista)->listaAnte = pNovo;
    (*lista) = pNovo;
  }
}
void adicionarFim(Lista **lista, tDado dado)
{
  Lista *pNovo = (Lista *)calloc(1, sizeof(Lista));
  pNovo->id = getId(lista);
  strcpy(pNovo->dado.nome, dado.nome);
  pNovo->dado.valor = dado.valor;
  pNovo->listaProx = NULL;
  if (*lista != NULL)
  {
    Lista *ultimoElem = (*lista)->listaAnte;
    ultimoElem->listaProx = pNovo;
    pNovo->listaAnte = ultimoElem;
    (*lista)->listaAnte = pNovo;
  }
}
void remover(Lista **lista, int id)
{
  Lista *elemento = buscar(*lista, id);
  if ((*lista)->listaAnte == elemento)
  {
    (*lista)->listaAnte = elemento->listaAnte;
    elemento->listaAnte->listaProx = NULL;
  }
  else if ((*lista) == elemento)
  {
    *lista = elemento->listaProx;
    elemento->listaProx->listaAnte = elemento->listaAnte;
  }
  else
  {

    elemento->listaAnte->listaProx = elemento->listaProx;
    elemento->listaProx->listaAnte = elemento->listaAnte;
  }

  elemento->listaProx = NULL;
  elemento->listaAnte = NULL;
  free(elemento);
}

int getId(Lista **lista)
{
  if (*lista == NULL)
  {
    return 1;
  }

  Lista *elemento = *lista;
  int maior = 1;
  while (elemento != NULL)
  {
    if (elemento->id > maior)
    {
      maior = elemento->id;
    }
    elemento = elemento->listaProx;
  }
  return maior + 1;
}

Lista *buscar(Lista *lista, int id)
{
  if (lista->id == id)
  {
    return NULL;
  }
  Lista *p = lista;
  while (p->id != id && p != NULL)
  {
    p = p->listaProx;
  }
  if (p->id != id)
  {
    printf("Lista vazia");
  }
  return p;
}
void exibir(Lista **lista)
{
  if (lista == NULL)
  {
    printf("\nLista vazia");
  }
  else
  {
    Lista *p = *lista;
    while (p != NULL)
    {
      printf("\n");
      printf("ID: %d\n", p->id);
      printf("Nome: %s\n", p->dado.nome);
      printf("\n");
      p = p->listaProx;
    }
  }
}
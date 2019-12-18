#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tDado
{
  char nome[20];
  float valor;
} Dado;

typedef struct tLista
{
  int id;
  Dado dado;
  struct tLista *listaProx;
  struct tLista *listaAnte;
} Lista;

Lista inicializarLista();
void adicionarFim(Lista *lista, Dado dado);
void removerInicio(Lista *lista);
void exibir(Lista lista);
Lista *buscar(Lista *lista, int id);
int main()
{
  Dado dado[4];

  strcpy(dado[0].nome, "Maria");
  dado[0].valor = 19;

  strcpy(dado[1].nome, "Mateus");
  dado[1].valor = 12;

  Lista lista = inicializarLista();

  adicionarFim(&lista, dado[1]);
  adicionarFim(&lista, dado[2]);
  removerInicio(&lista);
  removerInicio(&lista);
  adicionarFim(&lista, dado[0]);
  exibir(lista);

  return 0;
}

Lista inicializarLista()
{
  Lista lista;
  lista.id = 1;
  lista.listaProx = NULL;
  lista.listaAnte = NULL;
  return lista;
}
void adicionarFim(Lista *lista, Dado dado)
{
  Lista *novoElemento = (Lista *)calloc(1, sizeof(Lista));
  novoElemento->id = lista->id;

  strcpy(novoElemento->dado.nome, dado.nome);
  novoElemento->dado.valor = dado.valor;
  novoElemento->listaProx = NULL;

  Lista *ultimoElem = lista->listaAnte;
  if (ultimoElem == NULL)
  {
    lista->listaProx = novoElemento;
  }
  else
  {
    ultimoElem->listaProx = novoElemento;
    novoElemento->listaAnte = ultimoElem;
  }
  lista->listaAnte = novoElemento;
  lista->id++;
}
void removerInicio(Lista *lista)
{
  if (lista->listaProx != NULL)
  {
    Lista *p = lista->listaProx;
    lista->listaProx = p->listaProx;
    if (lista->listaAnte == p)
    {
      lista->listaAnte = NULL;
    }
    if (p->listaProx != NULL)
    {
      p->listaProx->listaAnte = lista;
    }
    p->listaProx = NULL;
    p->listaAnte = NULL;
    free(p);
  }
}

Lista *buscar(Lista *lista, int id)
{
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

void exibir(Lista lista)
{
  Lista *p = lista.listaProx;
  if (p == NULL)
  {
    printf("\nLista vazia");
  }

  while (p != NULL)
  {
    printf("\n");
    printf("ID: %d\n", p->id);
    printf("Nome: %s\n", p->dado.nome);
    printf("\n");
    p = p->listaProx;
  }
}
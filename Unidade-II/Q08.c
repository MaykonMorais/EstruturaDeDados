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
  struct tLista *prox;
  struct tLista *ante;
} tLista;

tLista inicializarLista();
void adicionarFim(tLista *lista, Dado dado);
void removerFim(tLista *lista);
void exibir(tLista lista);
tLista *buscar(tLista *lista, int id);
int main()
{
  Dado dado[4];

  strcpy(dado[0].nome, "Maria");
  dado[0].valor = 19;

  strcpy(dado[1].nome, "Miranda");
  dado[1].valor = 30;
  tLista lista = inicializarLista();

  printf("adicionando...\n");
  adicionarFim(&lista, dado[1]);
  printf("adicionando...\n");
  adicionarFim(&lista, dado[2]);

  printf("removendo...\n");
  removerFim(&lista);
  printf("removendo...\n");
  removerFim(&lista);
  printf("adicionando...\n");
  adicionarFim(&lista, dado[0]);
  exibir(lista);

  return 0;
}

tLista inicializarLista()
{
  tLista lista;
  lista.id = 1;
  lista.prox = NULL;
  lista.ante = NULL;
  return lista;
}
void adicionarFim(tLista *lista, Dado dado)
{
  tLista *novoElemento = (tLista *)calloc(1, sizeof(tLista));
  novoElemento->id = lista->id;

  strcpy(novoElemento->dado.nome, dado.nome);
  novoElemento->dado.valor = dado.valor;
  novoElemento->prox = NULL;

  tLista *ultimoElem = lista->ante;
  if (ultimoElem == NULL)
  {
    lista->prox = novoElemento;
  }
  else
  {
    ultimoElem->prox = novoElemento;
    novoElemento->ante = ultimoElem;
  }
  lista->ante = novoElemento;
  lista->id++;
}
void removerFim(tLista *lista)
{
  if (lista->prox != NULL)
  {
    tLista *elemento = lista->ante;
    if (elemento->ante != NULL)
    {
      tLista *elementoAnte = elemento->ante;
      elementoAnte->prox = NULL;
      lista->ante = elementoAnte;
    }
    else
    {
      lista->ante = NULL;
      lista->prox = NULL;
    }

    elemento->prox = NULL;
    elemento->ante = NULL;
    free(elemento);
  }
}

tLista *buscar(tLista *lista, int id)
{
  tLista *listaRef = lista;
  while (listaRef->id != id && listaRef != NULL)
  {
    listaRef = listaRef->prox;
  }
  if (listaRef->id != id)
  {
    printf("tLista vazia");
  }
  return listaRef;
}

void exibir(tLista lista)
{
  tLista *listaRef = lista.prox;
  if (listaRef == NULL)
  {
    printf("\nLista vazia");
  }

  while (listaRef != NULL)
  {
    printf("\n");
    printf("Elemento: %d \n", listaRef);
    printf("ID: %d\n", listaRef->id);
    printf("Nome: %s\n", listaRef->dado.nome);
    printf("Proximo: %d\n", listaRef->prox);
    printf("Anterior: %d\n", listaRef->ante);
    printf("\n");
    listaRef = listaRef->prox;
  }
}
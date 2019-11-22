#include <stdio.h>
#include <string.h>

#define MAX 3
#define FLAG_OK 1
#define FLAG_FAIL 0

typedef struct
{
  char nome[10];
  int valor;
} tDado;

typedef struct
{
  tDado vetor[MAX];
  int inicio, fim;
} tFila;

int inserir(tFila *fila, tDado valor)
{
  int fimTemp = (fila->fim + 1) % MAX;

  printf("Inserindo...\n");
  if (fimTemp == fila->inicio)
  {
    printf("Fila cheia!!!\n");
    return FLAG_FAIL;
  }

  fila->fim = fimTemp;
  fila->vetor[fila->fim] = valor;

  if (fila->inicio == -1)
  { // caso seja inserido o primeiro elemento
    fila->inicio = 0;
  }
  return FLAG_OK;
}

int remover(tFila *fila, tDado *retorno)
{
  printf("\nRemovendo...\n");
  if (fila->inicio == -1)
  {
    printf("Fila Vazia!!!\n");
    return FLAG_FAIL;
  }

  *retorno = fila->vetor[fila->inicio];

  if (fila->inicio == fila->fim)
  { // remover o ultimo elemento
    fila->inicio = -1;
    fila->fim = -1;
  }
  else
  {
    fila->inicio = (fila->inicio + 1) % MAX;
  }
  return FLAG_OK;
}

void exibir(tFila fila)
{
  printf("\nExibindo...\n");

  int cont = fila.inicio;

  while (cont != fila.fim)
  {
    printf("Posicao %d\n -- %s e %d \n", cont, fila.vetor[cont].nome, fila.vetor[cont].valor);
    cont++;

    if (cont == MAX)
    {
      cont = 0;
    }
  }
  printf("Posicao %d\n -- %s e %d \n", cont, fila.vetor[cont].nome, fila.vetor[cont].valor);
  printf("Inicio: %d    Fim: %d\n", fila.inicio, fila.fim);
}

tFila inicializar()
{
  tFila fila;
  fila.inicio = -1;
  fila.fim = -1;

  return fila;
}

int main()
{
  tFila fila = inicializar();
  tDado dado;

  strcpy(dado.nome, "Maria");
  dado.valor = 10;
  inserir(&fila, dado);

  strcpy(dado.nome, "Joao");
  dado.valor = 20;
  inserir(&fila, dado);

  strcpy(dado.nome, "Julia");
  dado.valor = 30;
  inserir(&fila, dado);

  strcpy(dado.nome, "Julia");
  dado.valor = 30;
  inserir(&fila, dado);
  exibir(fila);

  tDado retorno;
  if (remover(&fila, &retorno))
  {
    printf("Removido:\n --%s, %d\n\n", retorno.nome, retorno.valor);
  }

  if (remover(&fila, &retorno))
  {
    printf("Removido:\n --%s, %d\n", retorno.nome, retorno.valor);
  }
  return 0;
}
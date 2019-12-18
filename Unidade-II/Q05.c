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
  struct sElemento *pAnte;
  struct sElemento *pProx;
} tElemento;

tElemento *criarNovo(tElemento *pInicio, tDado dado)
{
  tElemento *pNovo = (tElemento *)calloc(1, sizeof(tElemento));

  pNovo->dado = dado;
  pNovo->dado.id = pInicio->dado.id;
  pNovo->pAnte = NULL;
  pNovo->pProx = NULL;

  // INCREMENTA ELEMENTO CABEÇA
  pInicio->dado.id += 1;
  return pNovo;
}

tElemento *inicializar()
{
  tElemento *pNovo = (tElemento *)calloc(1, sizeof(tElemento));

  pNovo->dado.id = 1;
  pNovo->pAnte = NULL;
  pNovo->pProx = NULL;

  return pNovo;
}

void inserirInicio(tElemento *pInicio, tDado dado)
{
  tElemento *pNovo = criarNovo(pInicio, dado);

  // anexar
  pNovo->pAnte = pInicio;
  pNovo->pProx = pInicio->pProx;

  // backup do elemento a direita de pInicio
  tElemento *pDireita = pInicio->pProx;

  if (pDireita == NULL) // inserindo o primeiro elemento
  {
    pInicio->pAnte = pNovo;
  }
  else
  {
    pDireita->pAnte = pNovo;
  }
}

int percorrer(tElemento *pInicio)
{
  int i = 0;
  tElemento *p;

  if (p == NULL)
  {
    printf("Lista vazia!!");
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

      p = p->pProx;
    }
  }
  printf("Quantidade de Elementos: %d\n", i);
  return i;
}
void inserirFim(tElemento *pInicio, tDado dado)
{
  tElemento *pNovo = (tElemento *)calloc(1, sizeof(tElemento));

  // anexa
  tElemento *pUltimo = pInicio->pAnte;

  if (pUltimo == NULL)
  {
    pInicio->pAnte = pInicio;
    pInicio->pProx = pNovo;
  }
  else
  {
    pNovo->pAnte = pUltimo;
    pUltimo->pProx = pNovo;
  }
  pInicio->pAnte = pNovo;
}
tElemento *buscar(tElemento *pInicio, int id)
{
  tElemento *p = pInicio->pProx;

  while (p != NULL)
  {
    if (p->dado.id == id)
    {
      return p;
    }
    p = p->pProx;
  }
  return NULL;
}

tDado remover(tElemento *pInicio, int key)
{
  tDado dadoRetorno;
  dadoRetorno.id = -1;

  tElemento *p = buscar(pInicio, key);

  if (p == NULL)
  {
    printf("ID nao encontrado \n");
    return dadoRetorno;
  }

  // Faz backup dos elementos ao redor de P
  tElemento *pEsquerda = p->pAnte;
  tElemento *pDireita = p->pProx;

  // Anexar
  pEsquerda->pProx = pDireita;

  if (pDireita == NULL)
  {
    // Cenario: elemento na ultima posicao
    if (pInicio->pAnte == pInicio->pProx)
    {
      // Cenario: resta apenas um elemento
      pInicio->pAnte = NULL;
    }
    else
    {
      // Cenario: ha dois ou mais elementos
      pInicio->pAnte = pEsquerda;
    }
  }
  else
  {
    // Cenario: elemento no meio
    pDireita->pAnte = pEsquerda;
  }

  // Monta retorno
  dadoRetorno = p->dado;
  free(p);

  return dadoRetorno;
}

int main()
{
  tElemento *lista = inicializar();

  tDado dado;

  strcpy(dado.nome, "Maria");
  dado.valor = 10;
  inserirInicio(lista, dado);
  printf("Inserindo...\n");
  percorrer(lista);

  printf("\nInserindo..\n");
  strcpy(dado.nome, "Joao");
  dado.valor = 20;
  inserirFim(lista, dado);

  percorrer(lista);

  return 0;
}
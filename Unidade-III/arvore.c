#include "stdio.h"

typedef struct
{
  int id;
  char nome[30];
  float valor;
} tDado;

typedef struct
{
  int id;
  struct sElemento *esq;
  struct sElemento *dir;
} tElemento;

int main()
{
  int i;
}
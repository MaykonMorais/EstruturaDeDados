/* Aluno: Maycon Morais da Silva */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define FLAG_OK 1
#define FLAG_FAIL 0

typedef struct
{
  char simbolo;
  int prioridade;
} tSimbolo;

typedef struct
{
  tSimbolo vetor[MAX];
  int topo;
} tPilha;

typedef struct
{
  double num[MAX];
  int topo;
} tPilha1; // para numeros

tPilha inicializarPilha();
int empilhar(tPilha *ex, tSimbolo simbolo);
int empilharNumeros(tPilha1 *ex, double num);
int desempilhar(tPilha *ex, tSimbolo *retorno);
int desempilharNumero(tPilha1 *ex, double *retorno);
tSimbolo findPriority(char letra, tSimbolo *vetor);
double findValueOfOperando(char simbolo);
void inicializarSimbolos(tSimbolo *t);

//somente letra minuscula (a, b, c, d)
int main()
{
  tSimbolo vetorSimbolo[5];

  vetorSimbolo[0].simbolo = '(';
  vetorSimbolo[0].prioridade = 1;

  vetorSimbolo[1].simbolo = '+';
  vetorSimbolo[1].prioridade = 2;

  vetorSimbolo[2].simbolo = '-';
  vetorSimbolo[2].prioridade = 2;

  vetorSimbolo[3].simbolo = '*';
  vetorSimbolo[3].prioridade = 3;

  vetorSimbolo[4].simbolo = '/';
  vetorSimbolo[4].prioridade = 3;

  tPilha pilha = inicializarPilha();

  char operacao[50];
  printf("Digite a operação desejada (ex. a*b+c): ");
  scanf("%s", operacao);

  printf("Expressao Posfixa: ");
  char *posfixa = (char *)malloc(strlen(operacao) * sizeof(char));

  int i = 0;
  int j = 0;
  int pos;

  tSimbolo retorno;
  int k = 0;
  while (operacao[i] != '\0')
  {
    if (operacao[i] == '+' || operacao[i] == '-' || operacao[i] == '*' || operacao[i] == '/')
    {
      tSimbolo simbolo = findPriority(operacao[i], vetorSimbolo);

      if (pilha.topo == -1)
      {
        empilhar(&pilha, simbolo);
      }

      else // topo != -1 tem elemento na pilha
      {
        if (pilha.vetor[pilha.topo].prioridade >= simbolo.prioridade)
        {
          desempilhar(&pilha, &retorno);
          printf("%c", retorno.simbolo);

          posfixa[k++] = retorno.simbolo;

          empilhar(&pilha, simbolo);
        }
        else
        {
          empilhar(&pilha, simbolo);
        }
      }
    }
    else if (operacao[i] == '(')
    {
      tSimbolo simbolo = findPriority(operacao[i], vetorSimbolo);
      empilhar(&pilha, simbolo);
    }

    else if (operacao[i] == ')')
    {
      // laço for
      for (j; j < MAX; j++)
      {
        if (pilha.vetor[j].simbolo != '(')
        {
          desempilhar(&pilha, &retorno);
          printf("%c", retorno.simbolo);

          posfixa[k++] = retorno.simbolo;
        }
        else if (pilha.vetor[j].simbolo == '(')
        {
          desempilhar(&pilha, &retorno);
          break;
        }
      }
    }
    else
    {
      printf("%c", operacao[i]);

      posfixa[k++] = operacao[i];
    }
    i++;
  }

  // esvaziar pilha
  while (pilha.topo != -1)
  {
    desempilhar(&pilha, &retorno);
    printf("%c", retorno.simbolo);

    posfixa[k++] = retorno.simbolo;
  }
  printf("\n");

  // algoritmo de avaliação de expressao na notação posfixa
  i = 0;
  tSimbolo simbolo;

  // inicializar pilha
  tPilha1 pilhaNumero;
  pilhaNumero.topo = -1;

  while (posfixa[i] != 0)
  {
    if ((posfixa[i] == '+') || (posfixa[i] == '-') || (posfixa[i] == '*') || (posfixa[i] == '/'))
    {
      if (posfixa[i] == '+')
      {
        double aux;
        double ret;

        desempilharNumero(&pilhaNumero, &ret);
        printf("%.2lf +", ret);

        aux = ret;

        desempilharNumero(&pilhaNumero, &ret);
        printf("%.2lf = ", ret);

        aux += ret;

        empilharNumeros(&pilhaNumero, aux);

        printf("%.2lf\n\n", pilhaNumero.num[pilhaNumero.topo]);
      }

      else if (posfixa[i] == '-')
      {
        double aux;
        double ret;

        desempilharNumero(&pilhaNumero, &ret); // desempilhando o numero
        aux = ret;

        printf("%.2lf - ", ret);

        desempilharNumero(&pilhaNumero, &ret);
        aux -= ret;

        printf("%.2lf = ", ret);

        empilharNumeros(&pilhaNumero, aux);

        printf("%.2lf\n\n", pilhaNumero.num[pilhaNumero.topo]);
      }
      else if (posfixa[i] == '/')
      {
        double aux;
        double ret;

        desempilharNumero(&pilhaNumero, &ret);
        aux = ret;

        printf("%.2lf / ", ret);

        desempilharNumero(&pilhaNumero, &ret);
        aux /= ret;

        printf("%.2lf = ", ret);

        empilharNumeros(&pilhaNumero, aux);

        printf("%.2lf\n\n", pilhaNumero.num[pilhaNumero.topo]);
      }
      else if (posfixa[i] == '*')
      {
        double aux;
        double ret;

        desempilharNumero(&pilhaNumero, &ret);
        aux = ret;

        printf("%.2lf * ", ret);

        desempilharNumero(&pilhaNumero, &ret);
        aux *= ret;

        printf("%.2lf = ", ret);

        empilharNumeros(&pilhaNumero, aux);
        printf("%.2lf\n\n", pilhaNumero.num[pilhaNumero.topo]);
      }
    }

    else
    {
      int num = findValueOfOperando(posfixa[i]);
      printf("Empilhei: %c\n", posfixa[i]);
      empilharNumeros(&pilhaNumero, num);
    }
    i++;
  }

  printf("\nResultado: %lf\n", pilhaNumero.num[pilhaNumero.topo]);
}

tPilha inicializarPilha()
{
  tPilha pilha;
  pilha.topo = -1;
  return pilha;
}

tSimbolo findPriority(char letra, tSimbolo *vetor)
{
  tSimbolo s;
  int i = 0;
  for (i; i < 5; i++)
  {
    if (vetor[i].simbolo == letra)
    {
      s.simbolo = letra;
      s.prioridade = vetor[i].prioridade;
    }
  }
  return s;
}

double findValueOfOperando(char simbolo)
{
  if (simbolo == 'a')
  {
    return 7;
  }
  else if (simbolo == 'b')
  {
    return 3;
  }
  else if (simbolo == 'c')
  {
    return 6;
  }
  else if (simbolo == 'd')
  {
    return 4;
  }
}

int empilhar(tPilha *ex, tSimbolo simbolo)
{
  //printf("Empilhando...\n");
  if (ex->topo == MAX - 1)
  {
    printf("Erro: Pilha cheia!!\n");
    return FLAG_FAIL;
  }

  else
  {
    ex->topo += 1;
    ex->vetor[ex->topo] = simbolo;
    return FLAG_OK;
  }
}

// empilhar numeros
int empilharNumeros(tPilha1 *ex, double num)
{
  //printf("Empilhando...\n");
  if (ex->topo == MAX - 1)
  {
    printf("Erro: Pilha cheia!!\n");
    return FLAG_FAIL;
  }

  else
  {
    ex->topo += 1;
    ex->num[ex->topo] = num;
    return FLAG_OK;
  }
}

int desempilhar(tPilha *ex, tSimbolo *retorno)
{
  //printf("Desempilhando...\n");
  if (ex->topo == -1)
  {
    printf("Erro: pilha vazia!");
    return FLAG_FAIL;
  }
  else
  {
    *retorno = ex->vetor[ex->topo];
    ex->topo -= 1;
    return FLAG_OK;
  }
}

int desempilharNumero(tPilha1 *ex, double *retorno)
{
  //printf("Desempilhando...\n");
  if (ex->topo == -1)
  {
    printf("Erro: pilha vazia!");
    return FLAG_FAIL;
  }
  else
  {
    *retorno = ex->num[ex->topo];
    ex->topo -= 1;
    return FLAG_OK;
  }
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 2
typedef struct tPilha
{
  float operando[SIZE];
  int top;
} Pilha;

Pilha iniciaPilha();
void empilhar(Pilha *pilha, float operando);
void desempilhar(Pilha *pilha);
void exibir(Pilha pilha);
void calc(Pilha *Pilha, char *exp);
void operando(Pilha *pilha, char operador);
int main()
{
  char exp[20];
  printf("Digite uma exp: \n");
  fgets(exp, sizeof(char) * 20, stdin);

  Pilha pilha = iniciaPilha();
  calc(&pilha, exp);
  exibir(pilha);
  return 0;
}

Pilha iniciaPilha()
{
  Pilha pilha;
  pilha.top = -1;
  return pilha;
}

void calc(Pilha *pilha, char *exp)
{
  int inicio = 0;
  int i = 0;
  int fim = 0;
  while (fim == 0)
  {
    if (exp[i] == '\0' || exp[i] == '\n')
    {
      fim = 1;
    }

    if (exp[i] == '\0' || exp[i] == ' ' || exp[i] == '\n')
    {
      exp[i] = '\0';
      char *result = &exp[inicio];
      float valor;
      switch (result[0])
      {
      case '+':
      case '-':
      case '/':
      case '*':
        operando(pilha, *result);
        break;
      default:
        sscanf(result, "%f", &valor);
        empilhar(pilha, valor);
        break;
      }
      inicio = i + 1;
    }
    i++;
  }
}
void operando(Pilha *pilha, char operador)
{
  float resultado;
  switch (operador)
  {
  case '+':
    resultado = pilha->operando[pilha->top - 1] + pilha->operando[pilha->top];
    break;
  case '-':
    resultado = pilha->operando[pilha->top - 1] - pilha->operando[pilha->top];
    break;
  case '*':
    resultado = pilha->operando[pilha->top - 1] * pilha->operando[pilha->top];
    break;
  case '/':
    resultado = pilha->operando[pilha->top - 1] / pilha->operando[pilha->top];
    break;
  default:
    break;
  }
  desempilhar(pilha);
  desempilhar(pilha);
  empilhar(pilha, resultado);
}
void empilhar(Pilha *pilha, float operando)
{
  if (pilha->top < SIZE - 1)
  {
    pilha->top++;
    pilha->operando[pilha->top] = operando;
  }
  else
  {
    printf("\nPilha cheia!");
  }
}
void desempilhar(Pilha *pilha)
{
  if (pilha->top > -1)
  {
    pilha->top--;
  }
  else
  {
    printf("Pilha está vazia");
  }
}

void exibir(Pilha pilha)
{
  int i;
  if (pilha.top > -1)
  {
    for (i = 0; i <= pilha.top; i++)
    {
      printf("\nResultado: %f\n", pilha.operando[i]);
    }
  }
  else
  {
    printf("Pilha está vazia");
  }
}
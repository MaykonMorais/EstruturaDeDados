#include <stdio.h>
#include <string.h>

#define MAX 4
#define FLAG_OK 1
#define FLAG_FAIL 0

typedef struct
{
  char nome[10];
  int valor;
} tDado;

typedef struct
{
  tDado dados[MAX];
  int topo;
} tPilha;

int push(tPilha *stack, tDado data)
{
  printf("\nPushing...\n");
  if (stack->topo == MAX - 1)
  {
    printf("The stack is full!!\n");
    return FLAG_FAIL;
  }
  else
  {
    stack->topo += 1;
    stack->dados[stack->topo] = data;
    return FLAG_OK;
  }
}

int pop(tPilha *stack, tDado *dataReturn)
{
  printf("Poping...\n");
  if (stack->topo == -1)
  {
    printf("The stack is empty!!\n");
    return FLAG_FAIL;
  }
  else
  {
    *dataReturn = stack->dados[stack->topo];
    stack->topo -= 1;
    return FLAG_OK;
  }
}
tPilha stackInit()
{
  tPilha stack;

  stack.topo = -1;
  return stack;
}

int main()
{
  tPilha stack = stackInit();

  tDado dado;
  strcpy(dado.nome, "Maria");
  dado.valor = 10;
  push(&stack, dado);

  strcpy(dado.nome, "Joao");
  dado.valor = 20;
  push(&stack, dado);

  strcpy(dado.nome, "Fernando");
  dado.valor = 30;
  push(&stack, dado);

  strcpy(dado.nome, "Fernanda");
  dado.valor = 35;
  push(&stack, dado);

  strcpy(dado.nome, "Murilo");
  dado.valor = 340;
  push(&stack, dado); // erro

  tDado dataReturn;
  if (pop(&stack, &dataReturn))
  {
    printf("Removed:\n %s and %d\n\n", dataReturn.nome, dataReturn.valor);
  };

  if (pop(&stack, &dataReturn))
  {
    printf("Removed:\n %s and %d\n\n", dataReturn.nome, dataReturn.valor);
  };

  if (pop(&stack, &dataReturn))
  {
    printf("Removed:\n %s and %d\n\n", dataReturn.nome, dataReturn.valor);
  };

  if (pop(&stack, &dataReturn))
  {
    printf("Removed:\n %s and %d\n\n", dataReturn.nome, dataReturn.valor);
  };

  if (pop(&stack, &dataReturn)) // stack empty
  {
    printf("Removed:\n %s and %d\n\n", dataReturn.nome, dataReturn.valor);
  };

  return 0;
}
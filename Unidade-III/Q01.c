#include <stdio.h>

#define MAX 5

typedef struct {
  int id;
  char nome[20];
} tPessoa;

int linearSearch(tPessoa * pessoas, int id);

int main() {
  tPessoa pessoas[MAX] = {
    {1, "Maria"},
    {2, "Fernando"},
    {3, "Lucas"},
    {4, "Joao"},
    {5, "Cristo"}
  };
  int id;
  printf("Digite o ID desejado: ");
  scanf("%d", &id);

  int result = linearSearch(pessoas, id);

  printf("result: %d\n", result);
  if(result != -1) {
    printf("Pessoa encontrada: \nID: %d\nNome: %s\n", pessoas[result].id, pessoas[result].nome);
  }
  else {
    printf("Elemento nao encontrado!!\n");
  }


  return 0;
}

int linearSearch(tPessoa * pessoas, int id)
{
  int result = -1;
  int i = 0;
  for(i; i < MAX;  i++) {
    if(id == pessoas[i].id) {
      return i; // return position
    }
  }
  return result;
}

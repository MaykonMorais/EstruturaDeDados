// perguntar pra bruno

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *inverte(char *frase, char *vet, int tam);
int main()
{
  char frase[30];

  printf("Digite a frase desejada: ");
  fgets(frase, 30, stdin);

  int tam = strlen(frase);

  char *vet = (char *)calloc(tam, sizeof(char));

  vet = inverte(frase, vet, tam);

  printf("%s", vet);
  return 0;
}

char *inverte(char *frase, char *vet, int tam)
{
  // b o m     d i a  '\0'
  // 0 1 2  3  4 5 6    7
  int i = 0;
  int j = tam - 1;
  for (i, j; i < tam; i++, j--)
  {
    vet[i] = frase[j];
  }
  //vet[i] = '\0';

  printf("\n");
  return vet;
}
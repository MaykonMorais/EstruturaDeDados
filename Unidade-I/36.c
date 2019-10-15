#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  char letra;
  int qtd;
} palavra;

int main()
{

  char word[30];
  printf("Digite uma palavra: ");
  scanf("%s", &word);

  palavra *p = (palavra *)calloc(strlen(word) - 1, sizeof(palavra)); // alocação dinamica de palavras

  int i;
  for (i = 0; i < (strlen(word) - 1); i++)
  {
    int j = i + 1;
    //int cont = 0;
    p[i].letra = word[i];
    p[i].qtd = 1;

    for (j; j < strlen(word); j++)
    {
      if (p[i].letra == word[j])
      {
        p[i].qtd++;
      }
    }
  }

  printf("Estatísticas das letras: \n");
  for (i = 0; i < strlen(word); i++)
  {
    if (p[i].qtd != 0)
    {
      printf("Letra %c\n", p[i].letra);
      printf("Qtd %d\n\n", p[i].qtd);
    }
  }
  return 0;
}
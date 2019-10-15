#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  char palavra[30];
  int repeated; // bool value
} palavras;

int main()
{
  char frase[50];
  char *retorno;

  printf("Digite uma frase: ");
  fgets(frase, 50, stdin);

  if (frase[1] == '\0')
  {
    printf("Digite uma frase valida!\n");
    return 1;
  }

  int i = 0;
  int qtdWords = 1;
  while (frase[i] != '\0')
  {
    if (frase[i] != ' ' && frase[i + 1] == ' ')
    {
      ++qtdWords;
    }
    i++;
  }

  palavras *p = (palavras *)calloc(qtdWords, sizeof(palavras));
  printf("Quantidade de palavras: %d\n\n", qtdWords);

  retorno = strtok(frase, " ");
  if (retorno)
  {
    qtdWords = 1;
  }
  strcpy(p[0].palavra, retorno);

  i = 1;

  do
  {
    retorno = strtok(NULL, " \n");

    if (retorno)
    {
      strcpy(p[i].palavra, retorno);
      ++qtdWords;
    }
    i++;
  } while (retorno);

  int j;

  int qtd = 1, k;
  for (j = 0; j < qtdWords; j++)
  {
    qtd = 1;
    if (p[j].repeated != 1)
    {

      printf("Palavra: %s\n", p[j].palavra);

      for (k = j + 1; k < qtdWords; k++)
      {
        if (!strcmp(p[j].palavra, p[k].palavra))
        {
          ++qtd;
          p[k].repeated = 1;
        }
      }
      printf("Quantidade: %d\n\n", qtd);
    }
  }
  return 0;
}
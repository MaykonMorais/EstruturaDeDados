#include <stdio.h>
#include <string.h>

int main()
{
  char frase[50] = "Esta uma manha linda";
  char *retorno;

  retorno = strtok(frase, " ");

  printf("Primeira palavra: %s\n", retorno);

  do
  {
    retorno = strtok('\0', " ");

    if (retorno)
    {
      printf("palavras: %s\n", retorno);
    }
  } while (retorno);

  return 0;
}
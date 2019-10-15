#include <stdio.h>
#include <string.h>

int main()
{
  char palavra[30];
  printf("Digite uma frase: ");
  fgets(palavra, 30, stdin);

  int tam = strlen(palavra);
  int i = 0;
  int j = tam - 1;

  for (i; i < tam; i++)
  {
    printf("%c", palavra[tam - i - 1]);
  }

  return 0;
}

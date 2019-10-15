#include <stdio.h>
#include <time.h>

int somatorio(int num1, int num2);
void somatorioNormal(int num1, int num2);

int main()
{
  int num1, num2;
  clock_t t;

  printf("Digite um numero: ");
  scanf("%d", &num1);

  printf("Digite outro numero: ");
  scanf("%d", &num2);
  t = clock();
  somatorioNormal(num1, num2);
  t = clock() - t;

  double tempo_decorrido = ((double)t / CLOCKS_PER_SEC); // em segundos
  printf("Tempo decorrido: %lfms\n\n", tempo_decorrido);

  t = clock();
  int soma = somatorio(num1, num2);
  t = clock() - t;
  printf("Somatório recursivo: %d\n", soma);
  tempo_decorrido = ((double)t / CLOCKS_PER_SEC);
  printf("Tempo decorrido: %lfms\n", tempo_decorrido);
  return 0;
}

int somatorio(int num1, int num2)
{

  if (num1 < num2)
  {
    int soma = num1 + somatorio(num1 + 1, num2);
    return soma;
  }
}

void somatorioNormal(int num1, int num2)
{
  int soma = 0;
  for (num1; num1 <= num2; num1++)
  {
    soma += num1;
  }
  printf("somatorio normal: %d\n", soma);
}

// a complexidade envolvendo o somatório normal é maior
// visto que há atribuições, somatorio

// enquanto no somatório recursivo, há somente chamadas recursivas usando a soma, basicamente
#include <stdio.h>

double factorial(int num);
int main()
{
  int num;
  printf("Digite um numero: ");
  scanf("%d", &num);

  printf("Fatorial: %.0lf\n", factorial(num));
  return 0;
}

double factorial(int num)
{
  if (num < 1)
  {
    return 1;
  }
  else
  {
    return num * factorial(num - 1);
  }
}
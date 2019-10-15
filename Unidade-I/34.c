#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Pessoa
{
  char nome[30];
  int idade;
  char sexo;
  float altura;
  float peso;
};

void clear();
float imc(float altura, float peso);

int main()
{
  int tam;
  printf("Digite a quantidade de pessoas pra o cadastro: ");
  scanf("%d", &tam);

  struct Pessoa *p = malloc(tam * sizeof(struct Pessoa));

  int i = 0;
  for (i; i < tam; i++)
  {
    clear();

    printf("Nome: ");
    fgets(p[i].nome, 30, stdin);

    printf("Sexo: ");
    scanf("%c", &p[i].sexo);

    printf("idade: ");
    scanf("%d", &p[i].altura);

    printf("Altura: ");
    scanf("%f", &p[i].altura);

    printf("Peso: ");
    scanf("%f", &p[i].peso);
    printf("\n");
  }
  i = 0;

  for (i; i < tam; i++)
  {
    printf("\n%d° Pessoa: \n", i + 1);
    printf("Nome: %s", p[i].nome);
    printf("Sexo: %c", p[i].sexo);
    printf("\nIdade: %d", p[i].idade);
    printf("\nAltura: %.2f\n", p[i].altura);
    printf("IMC: %.2f\n", imc(p[i].altura, p[i].peso));
  }
  return 0;
}
float imc(float altura, float peso)
{ // altura (m), peso kg
  return ((peso) / pow(altura, 2));
}

void clear()
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}
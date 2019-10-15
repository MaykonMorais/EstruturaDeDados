#include <stdio.h>
#include <math.h>

struct Pessoa
{
  char nome[30];
  int idade;
  float peso;
  char sexo;
  float altura;
};

void clear();
float imc(float altura, float peso);

int main()
{
  struct Pessoa p[3];

  int i = 0;
  printf("Digite o dado de 3 Pessoas: \n");
  for (i; i < 3; i++)
  {
    printf("Nome: ");
    fgets(p[i].nome, 30, stdin);

    printf("Sexo: ");
    scanf("%c", &p[i].sexo);

    printf("idade: ");
    scanf("%d", &p[i].idade);

    printf("Altura(m): ");
    scanf("%f", &p[i].altura);

    printf("Peso(kg): ");
    scanf("%f", &p[i].peso);

    clear();

    printf("\n");
  }

  i = 0;
  for (i; i < 3; i++)
  {
    printf("\n%d° Pessoa: \n", i + 1);
    printf("Nome: %s", p[i].nome);
    printf("Sexo: %c", p[i].sexo);
    printf("\nIdade: %d", p[i].idade);
    printf("\nAltura: %.2f\n", p[i].altura);
    printf("IMC: %f\n", imc(p[i].altura, p[i].peso));
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
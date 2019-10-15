#include <stdio.h>

int main()
{
  FILE *pArquivo = fopen("dados.csv", "r");

  if (pArquivo == NULL)
  {
    printf("Impossivel abrir arquivo para leitura!");
    return 1;
  }

  char produto[15];
  float preco;

  while (fscanf(pArquivo, "%s\t%f", &produto, &preco) != EOF)
  {
    printf("Produto: %s\nPreco: R$ %.2f\n", produto, preco);
  }
  fclose(pArquivo);

  pArquivo = fopen("dados.csv", "a");
  if (pArquivo == NULL)
  {
    printf("Impossivel abrir arquivo para escrita!");
    return 1;
  }

  printf("\nAdicionando Produtos\nDigite o nome do produto: ");
  scanf("%s", &produto);
  printf("Preco: ");
  scanf("%f", &preco);

  fprintf(pArquivo, "%s\t%f\n", produto, preco);
  fclose(pArquivo);

  return 0;
}
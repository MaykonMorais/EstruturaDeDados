#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tDado
{
  char palavra[20];
  int qtd;
} tDado;

typedef struct tElemento
{
  int id;
  tDado tDado;
  struct tElemento *pProx;
} tElemento;

tElemento iniciaLista();
void adicionarInicio(tElemento *lista, char *palavra);
void addDadoInicio(tElemento *lista, tDado dado);
int searchRepeatWords(tElemento *lista, char *palavra);
void exibir(tElemento lista);
int exibirMenu();
void organizaRepeticoes(char *frase);
void exibeBinario();

int main()
{
  FILE *pFile;
  int menu;
  do
  {
    menu = exibirMenu();
    switch (menu)
    {
    case 1:
      pFile = fopen("texto.txt", "r"); // abertura do arquivo
      if (pFile == NULL)
      {
        printf("file not found!!.");
      }
      else
      {
        char frase[100];
        fgets(frase, sizeof(frase), pFile);
        organizaRepeticoes(frase);
      }

      fclose(pFile);
      break;
    case 2:
      exibeBinario();
      break;
    case 0:
      printf("Saindo...");
      break;
    default:
      printf("\nOpcao invalida.");
      break;
    }
  } while (menu != 0);
  return 0;
}
int exibirMenu()
{
  int menu;
  printf("\nMENU\n");
  printf("[1] Ler mensagem:\n");
  printf("[2] Ler arquivo binario\n");
  printf("[0] sair\n");
  scanf("%d", &menu);
  return menu;
}
void exibeBinario()
{
  FILE *pFile;
  pFile = fopen("fraseQ7.bin", "rb");
  if (pFile == NULL)
  {
    printf("Arquivo nao encontrado.");
  }
  else
  {
    tElemento lista = iniciaLista();
    tDado dado;
    while (fread(&dado, sizeof(tDado), 1, pFile) > 0)
    {
      addDadoInicio(&lista, dado);
    }
    fclose(pFile);
    exibir(lista);
  }
}

void organizaRepeticoes(char *frase)
{
  tElemento lista = iniciaLista();
  int fim = 0;
  int i = 0;
  int initWord = i;
  while (fim != 1)
  {
    if (frase[i] == '\0')
    {
      fim = 1;
    }

    if (frase[i] == ' ' || frase[i] == '\0')
    {
      frase[i] = '\0';
      char *palavra = &frase[initWord];
      if (searchRepeatWords(&lista, palavra) == 0)
      {
        adicionarInicio(&lista, palavra);
      }

      initWord = i + 1;
    }
    i++;
  }

  FILE *pFile;
  pFile = fopen("fraseQ7.bin", "wb");
  tElemento *listaRef = lista.pProx;
  while (listaRef != NULL)
  {
    fwrite(&(listaRef->tDado), sizeof(tDado), 1, pFile);
    listaRef = listaRef->pProx;
  }
  fclose(pFile);
  exibir(lista);
}

tElemento iniciaLista()
{
  tElemento novoElemento;
  novoElemento.id = 1;
  novoElemento.pProx = NULL;
  return novoElemento;
}

void adicionarInicio(tElemento *lista, char *palavra)
{
  tElemento *novoElemento = (tElemento *)malloc(sizeof(tElemento));
  strcpy(novoElemento->tDado.palavra, palavra);
  novoElemento->id = lista->id;
  novoElemento->tDado.qtd = 1;
  novoElemento->pProx = lista->pProx;
  lista->pProx = novoElemento;
  lista->id++;
}

void addDadoInicio(tElemento *lista, tDado dado)
{
  tElemento *novoElemento = (tElemento *)malloc(sizeof(tElemento));
  novoElemento->id = lista->id;
  strcpy(novoElemento->tDado.palavra, dado.palavra);
  novoElemento->tDado.qtd = dado.qtd;
  novoElemento->pProx = lista->pProx;
  lista->pProx = novoElemento;
  lista->id++;
}
int searchRepeatWords(tElemento *lista, char *palavra)
{
  tElemento *p = lista->pProx;
  int encontrou = 0;
  while (encontrou == 0 && p != NULL)
  {
    if (strcmp(palavra, p->tDado.palavra) == 0)
    {
      p->tDado.qtd++;
      encontrou = 1;
    }
    p = p->pProx;
  }
  return encontrou;
}

void exibir(tElemento lista)
{
  tElemento *p = lista.pProx;
  while (p != NULL)
  {
    printf("\n");
    printf("tElemento: %d \n", p);
    printf("ID: %d\n", p->id);
    printf("Palavra: %s\n", p->tDado.palavra);
    printf("Quantidade: %d\n", p->tDado.qtd);
    printf("Proximo: %d\n", p->pProx);
    printf("\n");
    p = p->pProx;
  }
}
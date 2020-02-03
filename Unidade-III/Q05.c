#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

typedef struct
{
  int id;
  char nome[10];
} tPessoa;

int calculateHash(int key);
void inserir(tPessoa *tableHash, tPessoa pessoa);
void showHashTable(tPessoa *pessoas);

int main()
{
  tPessoa *hashTable = (tPessoa *)calloc(SIZE, sizeof(tPessoa));

  tPessoa pessoa;

  pessoa.id = 8;
  strcpy(pessoa.nome, "Maria");
  inserir(hashTable, pessoa);

  pessoa.id = 1;
  strcpy(pessoa.nome, "Denilson");
  inserir(hashTable, pessoa);

  pessoa.id = 3;
  strcpy(pessoa.nome, "Mateus");
  inserir(hashTable, pessoa);

  pessoa.id = 5;
  strcpy(pessoa.nome, "Joao");
  inserir(hashTable, pessoa);

  pessoa.id = 6;
  strcpy(pessoa.nome, "Ricardo");
  inserir(hashTable, pessoa);

  showHashTable(hashTable);
  return 0;
}
int calculateHash(int key)
{
  return key % SIZE;
}

void inserir(tPessoa *tableHash, tPessoa pessoa)
{
  int pos = calculateHash(pessoa.id);

  if (tableHash[pos].id != 0)
  { // há um item
    int i;
    for (i = 0; i < SIZE; i++)
    {
      if (tableHash[i].id == 0)
      {
        printf("Inserindo em outra posicao vazia...\n");
        tableHash[i] = pessoa;
        return;
      }
    }
    printf("A lista está cheia!!\n");
  }
  else
  {
    printf("Inserindo de primeira! \n");
    tableHash[pos] = pessoa;
    return;
  }
}

void showHashTable(tPessoa *pessoas)
{
  int i;
  printf("Mostrando HashTable: \n");
  for (i = 0; i < SIZE; i++)
  {
    printf("%d ID: %d\t Nome: %s\n", i, pessoas[i].id, pessoas[i].nome);
  }
}
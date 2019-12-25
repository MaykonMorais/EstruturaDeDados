#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHTABLE_SIZE 5

typedef struct
{
  int id;
  char nome[30];
} tPessoa;

void insertTableHash(tPessoa pessoas[], tPessoa dado);
int calculateHash(int id);
void showHashTable(tPessoa *pessoas);

int main()
{
  tPessoa *hashTable = (tPessoa *)calloc(HASHTABLE_SIZE, sizeof(tPessoa));

  tPessoa pessoa;

  pessoa.id = 293;

  strcpy(pessoa.nome, "Mateus");
  insertTableHash(hashTable, pessoa);

  pessoa.id = 13;
  strcpy(pessoa.nome, "Joao");
  insertTableHash(hashTable, pessoa);

  pessoa.id = 13;
  strcpy(pessoa.nome, "Maria");
  insertTableHash(hashTable, pessoa);

  pessoa.id = 28;
  strcpy(pessoa.nome, "Pedro");
  insertTableHash(hashTable, pessoa);

  pessoa.id = 28;
  strcpy(pessoa.nome, "Lucas");
  insertTableHash(hashTable, pessoa);

  pessoa.id = 28;
  strcpy(pessoa.nome, "Maria Luiza");
  insertTableHash(hashTable, pessoa);

  showHashTable(hashTable);

  return 0;
}

void insertTableHash(tPessoa *hashTable, tPessoa dado)
{
  int tam = strlen(dado.nome);
  int pos = calculateHash(tam);

  if (hashTable[pos].id != 0) // insere caso o espaco esteja preenchido
  {
    int i;
    for (i = 0; i < HASHTABLE_SIZE; i++)
    {
      if (hashTable[i].id == 0)
      {
        printf("Inseriu...\n");
        hashTable[i] = dado;
        break;
      }
    }
  }
  else // insere caso a posicao seja vazia
  {
    hashTable[pos] = dado;
    printf("Inseriu no segundo caso\n%s\n\n", hashTable[pos].nome);
  }
}

// primeiro calculo, desconsidera colisão
int calculateHash(int id)
{
  return id % HASHTABLE_SIZE;
}

void showHashTable(tPessoa *pessoas)
{
  int i;
  printf("Mostrando Tabela\n");
  for (i = 0; i < HASHTABLE_SIZE; i++)
  {
    printf("%d : ID -%d\tNome- %s\n", i, pessoas[i].id, pessoas[i].nome);
  }
}

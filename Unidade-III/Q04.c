#include <stdio.h>
#include <stdlib.h>

#define HASHTABLE_SIZE 11

typedef struct node
{
  int value;
  struct node *pProx;
} node;

void inserir(node **head, int value)
{
  node *new_node = calloc(1, sizeof(node));
  new_node->value = value;
  new_node->pProx = NULL;

  if (*head == NULL) // caso nao haja nenhum elemento
  {
    *head = new_node;
  }
  else
  {
    // percorrer ate o ultimo elemento para adicionar
    node *current = *head;
    while (current->pProx != NULL)
    {
      current = current->pProx;
    }
    current->pProx = new_node;
  }
}

// criar hastable
node **get_hashtable()
{
  node **hastable = calloc(HASHTABLE_SIZE, sizeof(node));

  return hastable;
}

int getLocation(int value)
{
  return value % HASHTABLE_SIZE;
}

void insert_into_table(node **hashtable, int value)
{
  int location = getLocation(value);

  if (hashtable[location] == NULL)
  {
    // aloco espaco para o novo elemento
    hashtable[location] = calloc(1, sizeof(node *));

    node *head = NULL;     // lista encadeada para cada indice da tabela
    inserir(&head, value); // inseri na lista

    hashtable[location] = head;
  }
  else
  {
    node *head = hashtable[location];
    inserir(&head, value);

    hashtable[location] = head;
  }
}

void displayTable(node **hashTable)
{
  int i = 0;
  for (i = 0; i < HASHTABLE_SIZE; i++)
  {
    node *head = hashTable[i];

    printf("%d: ", i);

    if (head == NULL)
    {
      printf("NULL\n");
    }
    else
    {
      node *current = head;
      while (current != NULL)
      {
        printf("%d ", current->value);
        current = current->pProx;
      }
    }

    printf("\n");
  }
}

int main()
{
  node **table = get_hashtable();

  insert_into_table(table, 10);
  insert_into_table(table, 12);
  insert_into_table(table, 30);
  insert_into_table(table, 40);
  insert_into_table(table, 11);
  insert_into_table(table, 33);
  insert_into_table(table, 55);
  insert_into_table(table, 66);
  insert_into_table(table, 11);

  insert_into_table(table, 22);
  insert_into_table(table, 33);
  insert_into_table(table, 40);
  insert_into_table(table, 51);

  displayTable(table);
  return 0;
}
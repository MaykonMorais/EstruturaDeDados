#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
	char nome[10];
	int valor;
} tDado;

typedef struct
{
	tDado dado;
	struct sElemento *proximo;
} tElemento;

tElemento *inicializar()
{
	tElemento *pNovo = (tElemento *)calloc(1, sizeof(tElemento));

	pNovo->dado.id = 1;
	pNovo->proximo = NULL;

	return pNovo;
}

void inserirInicio(tElemento *pInicio, tDado dado)
{
	tElemento *pNovo = (tElemento *)calloc(1, sizeof(tElemento));

	pNovo->dado = dado;
	pNovo->dado.id = pInicio->dado.id;
	pNovo->proximo = NULL;

	// incrementa
	pInicio->dado.id += 1;

	// anexa
	pNovo->proximo = pInicio->proximo;
	pInicio->proximo = pNovo;
}

int percorrer(tElemento *pInicio)
{
	int i = 0;
	tElemento *p = pInicio->proximo; // pula o elemento cabeca

	if (p == NULL)
	{
		printf("lista vazia!!\n");
		return 0;
	}
	else
	{
		while (p != NULL)
		{
			i++;
			printf("ID: %d\n", p->dado.id);
			printf("Nome: %s\n", p->dado.nome);
			printf("Valor: %d\n", p->dado.valor);

			printf("\n");
			p = p->proximo;
		}
		printf("Quantidade de elementos: %d\n", i);
		return i;
	}
}

void inserirFim(tElemento *pInicio, tDado dado)
{
	tElemento *pNovo = (tElemento *)calloc(1, sizeof(tElemento));
	pNovo->dado = dado;
	pNovo->dado.id = pInicio->dado.id;
	pNovo->proximo = NULL;

	// atualiza elemento cabeca
	pInicio->dado.id += 1;

	tElemento *p = pInicio;
	while (p->proximo != NULL)
	{
		p = p->proximo;
	}
	p->proximo = pNovo;
}
tElemento *buscarAnterior(tElemento *pInicio, int id)
{
	tElemento *p = pInicio;
	tElemento *pAnterior = NULL;

	if (p->proximo == NULL)
	{
		printf("lista vazia!!\n");
		return NULL;
	}
	else
	{
		while (p != NULL)
		{
			pAnterior = p;
			p = p->proximo;

			if (p != NULL && p->dado.id == id)
			{
				return p;
			}
		}
	}
	return NULL;
}

void remover(tElemento *pInicio, int id)
{
	tElemento *pAnterior = buscarAnterior(pInicio, id);
	tElemento *p = NULL;

	if (pAnterior == NULL)
	{
		printf("Nao existe elemento com esse id!!\n");
		return;
	}
	else
	{
		p = pAnterior->proximo; // pega o proximo do anterior
		pAnterior->proximo = p->proximo;
		p->proximo = NULL;
	}
}

int main()
{
	// lembre de inicializar
	tElemento *lista = inicializar();
	tDado dado;

	strcpy(dado.nome, "Maria");
	dado.valor = 10;
	inserirInicio(lista, dado);
	printf("Inserindo...\n");
	percorrer(lista);

	printf("\nInserindo..\n");
	strcpy(dado.nome, "Joao");
	dado.valor = 20;
	inserirFim(lista, dado);

	percorrer(lista);

	printf("\nRemovendo Maria...\n");
	remover(lista, 1);

	percorrer(lista);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Pessoa
{
	char* nome;
	int idade;
	char* endereco;
	char* email;
	char* telefone;
};

struct Lista
{
	struct Pessoa pessoa;
	struct Lista* prev;
	struct Lista* next;
};

typedef struct Lista lista;

int is_empty(lista** l)
{
	if(l)
	{
		if(*l){
			return 1;
		
		else
			return -2;
	}
	else
		return -3;
}

int main(void)
{

	lista* l = malloc(sizeof(lista *));

	if (!l)
		return -1;

	



	return 0;
}

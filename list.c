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

int main(void)
{



	return 0;
}

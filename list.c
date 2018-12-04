#include <stdio.h>
#include <stdlib.h>
#include "header_list.h"

typedef struct Lista lista;

void criar_lista(lista** l)
{
	if(!l)
		return;
	*l = NULL;
}

int vazia(lista** l)
{
	if(!l)
		return -1;

	if(*l == NULL)
		return 1;
	return 0;
}

int retornar_opcao()
{
	int opcao;

	printf("1 - Ver Contatos");
	printf("2 - Adicionar Contato");
	printf("3 - Remover Contatos");
	printf("4 - Salvar");
	printf("5 - Sair");

	printf("Digite a opcao: ");
	scanf("%d", &opcao);

	return opcao;
}


void processar_solicitacoes(lista** l)
{
	int opcao = retornar_opcao();




}

int main(void)
{
	lista** l = (lista **) malloc(sizeof(lista));
	criar_lista(l);




	return 0;
}

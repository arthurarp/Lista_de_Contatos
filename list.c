#include <stdio.h>
#include <stdlib.h>
#include "header_list.h"

typedef struct Lista lista;

int quantidade_contatos = 0;

void Sincronizar(lista** l, FILE* f);

int QuantidadeContatos(FILE* f)
{
	if(!f)
		printf("arquivo zuado!\n");
	int quantidade_de_contatos = 0;
	char c = fgetc(f);


	while(c != EOF)
	{
		if(c == '$')
			quantidade_de_contatos++;

		c = fgetc(f);
	}

	return quantidade_de_contatos;
}


void Criar_Lista(lista** l, FILE* f)
{
	if(!l)
		return;
	*l = NULL;

	Sincronizar(l, f);
}

int vazia(lista** l)
{
	if(!l)
		return -1;

	if(*l == NULL)
		return 1;
	return 0;
}

int OrdemAlfabetica(char* atual, char* novo)
{
	int i = 0;

	if(atual[i] < novo[i])
		return 1;

	else if(atual[i] == novo[i])
	{
		i++;
		return OrdemAlfabetica(&atual[i], &novo[i]);
	}

	else
		return 0;
}


// -------------------------------------------------------------------
void AdicionarElemento(lista** l, lista* n)
{
	lista* novo = n;

	if(*l == NULL)
	{
		novo->ant = NULL;
		novo->prox = NULL;

		*l = novo;
		quantidade_contatos++;
	}

	else
	{
		lista *ant, *atual = *l;

		while(atual != NULL && OrdemAlfabetica(atual->dados.nome, novo->dados.nome))
		{
			ant = atual;
			atual = atual->prox;

		}

		if(atual == *l)
        	{
            		novo->ant = NULL;
            		(*l)->ant = novo;
            		novo->prox = (*l);
            		*l = novo;
					quantidade_contatos++;
        	}

        	else
        	{
            		novo->prox = ant->prox;
            		novo->ant = ant;
            		ant->prox = novo;
					quantidade_contatos++;

            		if(atual != NULL)
                		atual->ant = novo;
        	}

	}


	printf("\n\n");
}

void Sincronizar(lista** l, FILE*  f)
{
	int i = 0, qtd_contatos = QuantidadeContatos(f);
	printf("contatos: %d\n", qtd_contatos);

	if(qtd_contatos == 0)
	{
		return;
	}
	else
	{
		char nome[200];
		rewind(f);

		while(i < qtd_contatos)
		{
			lista* novo = (lista *) malloc(sizeof(lista));

			fscanf(f, " %[^\n]", novo->dados.nome);
			fscanf(f, "%s", novo->dados.telefone);
			fscanf(f, " %[^\n]", novo->dados.endereco);
			fscanf(f, "%u", &novo->dados.cep);
			fscanf(f, "%s", novo->dados.nascimento);

			AdicionarElemento(l, novo);

			fseek(f, 2 * sizeof(char), SEEK_CUR);
			i++;
		}

	}
}




// -------------------------------------------------------------------

int Retornar_Opcao()
{
	int opcao;

	printf("1 - Ver Contatos\n");
	printf("2 - Adicionar Contato\n");
	printf("3 - Remover Contatos\n");
	printf("4 - Salvar\n");
	printf("5 - Sair\n");

	printf("Digite a opcao: ");
	scanf("%d", &opcao);

	return opcao;
}

void ImprimirLista(lista** l)
{
	lista* aux = *l;

	printf("---------------------------------------------\n");
	printf("            LISTA DE CONTATOS, (%d) registro(s)\n", quantidade_contatos);
	printf("---------------------------------------------\n");
	while(aux != NULL)
	{
		printf("Nome: %s\n", aux->dados.nome);
		printf("Telefone: %s\n", aux->dados.telefone);
		printf("Endereco: %s\n", aux->dados.endereco);
		printf("Cep: %u\n", aux->dados.cep);
		printf("Data de nascimento: %s\n", aux->dados.nascimento);

		printf("---------------------------------------------\n");
		aux = aux->prox;
	}

	printf("\n\n");

}

void Processar_Solicitacoes(lista** l)
{
	int opcao = Retornar_Opcao();

		switch(opcao)
		{
			case 1:
				ImprimirLista(l);

			break;

			case 2:
			break;

			case 3:
			break;

			case 4:
			break;

			case 5:
			break;


		}


}

int main(void)
{
	lista** l = (lista **) malloc(sizeof(lista));
	FILE* f = fopen("contatos.txt", "r+");
	if(!f)
	{
		printf("Nenhum registro previamente salvo! Arquivo 'contatos.txt' criado com sucesso!\n\n");
		f = fopen("contatos.txt", "w+");
		f = fopen("contatos.txt", "r+");
	}

	Criar_Lista(l, f);


	while(1)
		Processar_Solicitacoes(l);





	return 0;
}

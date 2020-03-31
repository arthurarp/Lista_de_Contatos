#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void create(list** l)
{
	*l = NULL;
}

int is_empty(list** l)
{
	if(l)
	{
		if(*l == NULL)
			return 1;
		return 0;
	}
	else
	{
		printf("Ponteiro duplo mal alocado!");
		return -1;
	}
	
}

list* get_person_data()
{
	list* new = (list *) malloc(sizeof(list)); 

	printf("Nome: ");
	scanf("%s", new->person.name);

	printf("Idade: ");
	scanf("%d", &new->person.age);

	printf("Endereço: ");
	scanf("%s", new->person.adress);

	printf("E-mail: ");
	scanf("%s", new->person.email);

	printf("Número: ");
	scanf("%s", new->person.number);

	return new;
}


void push(list** l)
{
	list* new = get_person_data();

	if(is_empty(l))
	{
		new->prev = NULL;
		new->next = NULL;
		*l = new;
	}
}

void print(list** l)
{
	if(is_empty(l))
	{
		printf("Lista vazia!\n");
		return;
	}

	list* aux = *l;

	while(aux)
	{
		printf("Nome: %s\nIdade: %d\nEndereço: %s\nE-mail: %s\nNúmero: %s\n", aux->person.name, aux->person.age, aux->person.adress, aux->person.email, aux->person.number);
		aux = aux->next;
	}
}

int options()
{
	int option;

	// system("clear");
	do
	{
		printf("1 - Adicionar contatos\n");
		printf("2 - Excluir contatos\n");
		printf("3 - Listar contatos\n");
		printf("4 - Sair\n");

		scanf("%d", &option);

	} while (option < 1 || option > 4);
			
	return option;
}

void menu(list** l)
{
	switch (options())
	{
		case 1:
			push(l);
			break;
		case 2:
			printf("vsf!\n");
			break;
		case 3:
			print(l);
			break;
		
		default:
			break;
	}
}

int main(void)
{
	list** l = (list **) malloc(sizeof(list *));
	create(l);

	for(;;)
		menu(l);


	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int is_empty(list* l)
{
	if(l)
		return 1;

	return 0;	
}

list* get_person_data()
{
	list* new = (list *) malloc(sizeof(list)); 

	printf("Please, tell us your name: ");
	scanf("%s", new->person.name);

	printf("\nPlease, tell us your age: ");
	scanf("%d", &new->person.age);

	return new;
}


void add_person_to_list(list* l)
{
	list* new = get_person_data();

	if(is_empty(l))
	{
		l = new;
		new->prev = new;
		new->next = new;
	}
}

int main(void)
{
	list* l = (list *) malloc(sizeof(list));

	



	return 0;
}

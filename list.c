#include <stdio.h>
#include <stdlib.h>

struct Person
{
	char* name;
	int age;
	char* adress;
	char* email;
	char* number;
};

struct List
{
	struct Person person;
	struct List* prev;
	struct List* next;
};

typedef struct List list;

int is_empty(list** l)
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

list** get_person_data()
{
	list** new = malloc(sizeof(list*)); 

	printf("Please, tell us your name: ")
	scanf("%s", new->name);

	printf("\nPlease, tell us your age: ");
	scanf("%d", &new->age);

	return new;
}


void add_person_to_list(list** l)
{
	list** new = get_person_data();

	if(is_empty(l))
	{
		*l = new;
		new->prev = new;
		new->next = new;
	}
}

int main(void)
{

	list* l = malloc(sizeof(list *));

	if (!l)
		return -1;


	



	return 0;
}

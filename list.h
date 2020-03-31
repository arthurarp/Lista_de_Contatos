struct Person
{
	char name[100];
	int age;
	char adress[100];
	char email[50];
	char number[11];
};

struct List
{
	struct Person person;
	struct List* prev;
	struct List* next;
};

typedef struct List list;
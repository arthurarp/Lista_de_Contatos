struct Dados
{
  char nome[100];
  char telefone[10];
  char endereco[100];
  int cep;
  char nascimento[11];

};

struct Lista
{
  struct Dados dados;
  struct List* ant;
  struct List* prox;

};

typedef struct Lista lista;

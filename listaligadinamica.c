#include <stdio.h>
#include <malloc.h>

typedef struct estrutura {
  int chave;
  int info;
  struct estrutura *prox;
} NO;

typedef struct {
  NO* inicio;
} LISTA;

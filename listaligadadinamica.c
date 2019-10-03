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

void inicializarLista (LISTA* l) {
  l->inicio = NULL;
}

void exibirLista (LISTA l) {
  NO* p = l.inicio;
  while (p) {
    printf("%d ", p->chave);
    p = p->prox;
  }
}

NO* primeiroElemLista (LISTA l) {
  return l.inicio;
}

NO* ultimoElemLista (LISTA l, int n) {
  NO* p = l.inicio;
  if (p) {
    while (p->prox){
      p = p->prox;
    }
  }
  return p;
}

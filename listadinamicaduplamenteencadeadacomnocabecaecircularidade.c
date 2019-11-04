#include <stdio.h>
#include <malloc.h>

typedef struct estrutura {
    int chave;
    struct estrutura *prox;
    struct estrutura *ant;
} NO;

typedef struct {
    NO* cabeca;
} LISTA;

void inicializarLista (LISTA* l) {
    l->cabeca = (NO*) malloc(sizeof(NO));
    l->cabeca->prox = l->cabeca;
    l->cabeca->ant = l->cabeca;
}

NO* ultimoElemLista (LISTA l) {
    if (l.cabeca->ant == l.cabeca) return NULL;
    return (l.cabeca->ant);
}

//sem duplicacao
bool inserirElemListaOrd (int ch, LISTA *l) {
    NO* p = l->cabeca->prox;
    while (p != l->cabeca) {
        if (p->chave >= ch) break;
        p = p->prox;
    }
    if (p->chave == ch) return false;
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = p;
    novo->ant = p->ant;
    p->ant->prox = novo;
    p->ant = novo;
    return true;
}

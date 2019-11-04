#include <stdio.h>
#include <malloc.h>

typedef struct estrutura {
    int chave;
    struct estrutura *prox;
    struct estrutura *ant;
} NO;

typedef struct {
    NO* inicio1;
    NO* inicio2;
} DEQUE;

void inicializarDeque (DEQUE *d) {
    d->inicio1 = NULL;
    d->inicio2 = NULL;
}

int tamanhoDeque (DEQUE d) {
    NO* p = d.inicio1;
    int i = 0;
    while (p) {
        i++;
        p = p->prox;
    }
    return i;
}

void entrarDeque1 (int ch, DEQUE *d) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->ant = NULL;
    novo->prox = d->inicio1;
    if (!d->inicio2) d->inicio2 = novo;
    else d->inicio1->ant = novo;
    d->inicio1 = novo;
}

int sairDeque1 (DEQUE *d) {
    if (!d->inicio1) return -1;
    int ch = d->inicio1->chave;
    if (d->inicio1 == d->inicio2) {
        free(d->inicio1);
        d->inicio1 = NULL;
        d->inicio2 = NULL;
    } else {
        d->inicio1 = d->inicio1->prox;
        free(d->inicio1->ant);
        d->inicio1->ant = NULL;
    }
    return ch;
}

void destruirDeque (DEQUE *d) {
    NO* p = d->inicio1;
    NO* ant = NULL;
    while (p) {
        ant = p->prox;
        free(p);
        p = ant;
    }
    d->inicio1 = NULL;
    d->inicio2 = NULL;
}

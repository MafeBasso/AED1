#include <stdio.h>
#include <malloc.h>

typedef struct estrutura {
    int chave;
    struct estrutura *prox;
} NO;

typedef struct {
    NO* inicio;
    NO* fim;
} Fdin;

void inicializarFdin (Fdin *p) {
    f->inicio = NULL;
    f->fim = NULL;
}

int tamanhoFdin (Fdin f) {
    NO* p = f.inicio;
    int tam = 0;
    while (p) {
        tam++;
        p = p->prox;
    }
    return tam;
}

void entrarFdin (int ch; Fdin *f) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    if (!f->inicio) {
        f->fim = novo;
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    novo->prox = NULL;
}

int sairFdin (Fdin *f) {
    if (!f->inicio) return -1;
    int ch = f->inicio->chave;
    if (f->inicio == f->fim) {
        free(f->fim);
        f->fim = NULL;
        f->inicio = NULL;
    } else {
        NO* p = f->inicio->prox;
        free(f->inicio);
        f->inicio = p;
    }
    return ch;
}

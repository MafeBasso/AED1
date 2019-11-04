#include <stdio.h>

#define MAX 15

typedef struct {
    int chave;
} RegistroEstat;

typedef struct {
    int inicio;
    int fim;
    RegistroEstat A[MAX];
} Festat;

void inicializarFestat (Festat *f) {
    f->inicio = -1;
    f->fim = -1;
}

bool entrarFestat(int ch, Festat *f) {
    int nroElem = (f->fim)-(f->inicio);
    if (nroElem < 0) nroElem *= -1;
    if (nroElem+1 >= MAX) return false;
    f->fim = (f->fim + 1) % MAX;
    f->A[f->fim].chave = ch;
    if (f->inicio < 0) f->inicio = 0;
    return true;
}

int sairFestat (Festat *f) {
    if (f->inicio < 0) return -1;
    int ch = f->A[f->inicio].chave;
    if (f->inicio == f->fim) {
        f->inicio = -1;
        f->fim = -1;
    } else f->inicio = (f->inicio + 1) % MAX;
    return ch;
}

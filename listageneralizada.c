#include <stdio.h>
#include <malloc.h>

typedef struct estrutura {
    int tipo; //1=elem 2=sublista
    union {
        int chave;
        struct estrutura *sublista;
    }
    struct estrutura *prox;
} NO;

void inicializarLista (NO* *p) {
    *p = NULL;
}

int contarChaves (NO* p) {
    int nroChaves = 0;
    while (p) {
        if (p->tipo == 1) nroChaves++;
        else nroChaves += contarChaves(p->sublista);
        p = p->prox;
    }
    return nroChaves;
}

int contarNos (NO* p) {
    int nroNos = 0;
    while (p) {
        if (p->tipo == 2) nroNos += contarNos(p->sublista);
        nroNos++;
        p = p->prox;
    }
    return nroNos;
}

int profundidade (NO* p) {
    int profundidade1 = 0;
    int profundidade2 = 0;
    while (p) {
        if (p->tipo == 2) {
            profundidade1++;
            profundidade1 += profundidade(p->sublista);
            if (p->prox) profundidade2 += profundidade(p->prox);
            if (profundidade2 > profundidade1) profundidade1 = profundidade2;
        } else p = p->prox;
    }
    return profundidade1;
}

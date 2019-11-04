#include <stdio.h>
#include <malloc.h>

#define MAXLIN 4

typedef struct estrutura {
    int lin;
    int col;
    int chave;
    struct estrutura *proxL;
    struct estrutura *proxC;
} NO;

typedef struct {
    NO* inicio;
    NO* lin[MAXLIN+1];
    NO* col[MAXCOL+1];
} LISTACR;

void inicializarMatriz (LISTACR *m) {
    for (int i = 1; i <= MAXLIN; i++) m->lin[i] = NULL;
    for (int i = 1; i <= MAXCOL; i++) m->col[i] = NULL;
}

int contaElementos (LISTACR *m) {
    int cont = 0;
    NO* p;
    for (int j = 1; j <= MAXCOL; j++) {
        p = m->col[j];
        while (p) {
            cont++;
            p=p->proxL;
        }
    }
    return cont;
}

void excluir (NO* *linha, NO* *coluna, NO* esq, NO* acima, NO* p) {
    if (!p) return;
    if (acima) acima->proxL = p->proxL;
    else *coluna = p->proxL;
    if (esq) esq->proxC = p->proxC;
    else *linha = p->proxC;
    free(p);
}

void excluirProdutos (LISTACR m, int c1, int c2) {
    NO* p1 = m.col[c1];
    NO* p2 = m.col[c2];
    int i = 1;
    while (p1 && p2) {
        if (p1->lin == i && p2->lin == i) {
            printf("Linha %d: %d*%d\n", i, p1->chave, p2->chave);
            p1 = p1->proxL;
            p2 = p2->proxL;
        } else {
            printf("Linha %d: 0\n", i);
            if (p1->lin == i) p1 = p1->proxL;
            else if (p2->lin == i) p2 = p2->proxL;
        }
        i++;
    }
    if (i <= MAXLIN) {
        while (i <= MAXLIN) {
            printf("Linha %d: 0\n", i);
            i++;
        }
    }
}

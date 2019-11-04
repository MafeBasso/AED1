#include <stdio.h>

#define MAX 15
#define NP 5

typedef struct {
    int base[NP+1];
    int topo[NP+1];
    int A[MAX];
} PILHAS;

//tem uma pilha a mais, "falsa"

void inicializarPilhas (PILHAS *p) {
    for (int i = 0; i < NP+1; i++) {
        p->base[i] = (i * (MAX/NP)) % MAX;
        p->topo[i] = p->base[i];
    }
}

bool pilhaKCheia (PILHAS p, int k) {
    if(p.topo[k]==p.base[k+1]) return true;
    return false;
}

bool paraDireita (PILHAS *p, int k) {
    if (k <= 0 || k > NP) return false;
    for (int i = k; i < NP+1; i++) {
        if (p->topo[i] == p->base[i+1]) continue;
        for (int m = p->topo[i]; m > p->base[k]; m--) {
            p->A[m+1] = p->A[m];
            if (m == ((p->base[i])+1)) {
                p->topo[i]++;
                p->base[i]++;
                i--;
            }
        }
        return true;
    }
    return false;
}

bool paraEsquerda (PILHAS *p, int k) {
    if (k <= 0 || k > NP) return false;
    for (int i = k; i > 0; i--) {
        if (p->topo[i-1] == p->base[i]) continue;
        for (int m = p->base[i]; m < p->topo[k]; m++) {
            p->A[m-11] = p->A[m];
            if (m == ((p->topo[i])-1)) {
                p->topo[i]--;
                p->base[i]--;
                i++;
            }
        }
        return true;
    }
    return false;
}

int pushK (int ch, PILHAS *p, int k) {
    if (k < 0 || k > NP) return false;
    if (p->topo[k] == p->base[k+1]) {
        bool mover = paraDireita(p, k+1);
        if (!mover) mover = paraEsquerda(p, k-1);
        if (!mover) return false;
    }
    A[p->topo[k]+1].chave = ch;
    p->topo[k]++;
    return true;
}

int popK (PILHAS *p, int k) {
    if (k < 0 || k > NP || (p->topo[k]==p->base[k])) return -1;
    int ch = p->A[p->topo[k]].chave;
    p->topo--;
    free(A[p->topo[k]+1]);
    return ch;
}

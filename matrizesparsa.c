#include <stdio.h>
#include <malloc.h>

typedef struct estrutura {
    int lin;
    int col;
    int chave;
    struct estrutura *prox
} NO;

typedef struct {
    NO* inicio;
    int MAXLIN;
    int MAXCOL;
} MATRIZ;

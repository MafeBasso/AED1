#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
typedef int bool;

typedef struct estrutura {
  int chave;
  struct estrutura *prox;
} NO;

typedef struct {
  NO* cabeca;
} LISTA;

void inicializarLista (LISTA *l) {
    l->cabeca = (NO*) malloc (sizeof(NO));
    l->cabeca->prox = l->cabeca;
}

void exibirLista (LISTA l) {
    NO* p = l.cabeca->prox;
    while (p != l.cabeca) {
        printf("%d ", p->chave);
        p = p->prox;
    }
}

NO* primeiroElemLista (LISTA l) {
    if (l.cabeca->prox == l.cabeca) return NULL;
    return (l.cabeca->prox);
}

NO* ultimoElemLista (LISTA l) {
    NO* p = l.cabeca->prox;
    while (p->prox != l.cabeca) p = p->prox;
    if (p==l.cabeca) return NULL;
    return p;
}

NO* enesimoElemLista (LISTA l, int n) {
    NO* p = l.cabeca->prox;
    for (int i = 1; i < n; i++) {
        if (p==l.cabeca) return NULL;
        p = p->prox;
    }
    if (p==l.cabeca) return NULL;
    return p;
}

int tamanhoLista (LISTA l) {
    NO* p = l.cabeca->prox;
    if(p==l.cabeca) return 0;
    int i = 1;
    while (p->prox != l.cabeca) {
        p = p->prox;
        i++;
    }
    return i;
}

NO* buscaSeqOrd (int ch, LISTA l, NO* *ant) {
    NO* p = l.cabeca->prox;
    *ant = l.cabeca;
    while (p != l.cabeca) {
        if (p->chave >= ch) break;
        *ant = p;
        p = p->prox;
    }
    if ((p==l.cabeca) || (p->chave != ch)) return NULL;
    return p;
}

//sem duplicidade
bool inserirElemListaOrd (int ch, LISTA *l) {
    NO* p;
    NO* ant;
    p = buscaSeqOrd (ch, *l, &ant);
    if (p) return NULL;
    NO* novo = (NO*) malloc (sizeof(NO));
    novo->chave = ch;
    novo->prox = ant->prox;
    ant->prox = novo;
    return true;
}

void destruirLista (LISTA *l) {
    NO* p = l->cabeca->prox;
    NO* ant = l->cabeca;
    while (p != l->cabeca) {
        ant = p->prox;
        free(p);
        p = ant;
    }
    l->cabeca->prox = l->cabeca;
}

int main(){
    LISTA l;
    int ch, ant, n;
    bool condicao = true;
    inicializarLista(&l);


    while(condicao) {
        int comando = 0;
        printf("Escolha um comando: \n");
        printf("1- Inserir lista ordenada sem duplicacao \n");
        printf("2- Exibir \n");
        printf("3- Buscar lista ordenada \n");
        printf("4- Primeiro Elemento \n");
        printf("5- Ultimo Elemento \n");
        printf("6- Enesimo Elemento \n");
        printf("7- Destruir Lista \n");
        printf("8- Tamanho da Lista \n");
        printf("9- Fechar \n");
        printf("Digite o numero: ");
        scanf("%d", &comando);

        switch(comando) {
            case 1:
                printf("Digite a chave: ");
                scanf("%d", &ch);
                inserirElemListaOrd(ch, &l);
                break;

            case 2:
                exibirLista (l);
                printf("\n");
                break;

            case 3:
                printf("Digite a chave: ");
                scanf("%d", &ch);
                NO* p = buscaSeqOrd (ch, l, &ant);
                if(!p) printf("A chave nao existe \n");
                else {
                    printf("O anterior: ");
                    if (ant) {
                        NO* b = ant;
                        printf("%d\n", b->chave);
                    } else printf("nao existe \n");
                    printf("A chave: ");
                    printf ("%d\n", p->chave);
                }
                break;

            case 4:
                printf("%d\n", primeiroElemLista(l));
                break;

            case 5:
                printf("%d\n", ultimoElemLista(l));
                break;

            case 6:
                printf("Digite a chave: ");
                scanf("%d", &n);
                printf("%d\n", enesimoElemLista(l, n));
                break;

            case 7:
                destruirLista(&l);
                break;

            case 8:
                printf("%d\n", tamanhoLista(l));
                break;

            case 9:
                condicao = false;
                break;

            default:
                printf("Digite um comando valido: ");
                scanf("%d", &comando);
                printf("\n");
                break;
        }
    }
    return 0;
}

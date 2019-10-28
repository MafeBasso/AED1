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
    NO* inicio;
    NO* sentinela;
} LISTA;

void inicializarLista (LISTA *l) {
    l->sentinela = (NO*) malloc(sizeof(NO));
    l->inicio = l->sentinela;
}

void exibirLista (LISTA l) {
    NO* p = l.inicio;
    while (p != l.sentinela) {
        printf("%d ", p->chave);
        p = p->prox;
    }
}

NO* primeiroElemLista (LISTA l) {
    if (l.inicio == l.sentinela) return NULL;
    return (l.inicio);
}

NO* ultimoElemLista (LISTA l) {
    NO* p = l.inicio;
    while (p->prox != l.sentinela) p = p->prox;
    if (p == l.sentinela) return NULL;
    return p;
}

NO* enesimoElemLista (LISTA l, int n) {
    NO* p = l.inicio;
    if (n<=0) return NULL;
    for (int i = 1; i < n; i++) {
        if (p == l.sentinela) return NULL;
        p = p->prox;
    }
    if (p == l.sentinela) return NULL;
    return p;
}

int tamanhoLista (LISTA l) {
    NO* p = l.inicio;
    int i = 0;
    while (p != l.sentinela) {
        p = p->prox;
        i++;
    }
    return i;
}

NO* buscaSeqOrd (int ch, LISTA l, NO* *ant) {
    l.sentinela->chave = ch;
    NO* p = l.inicio;
    *ant = NULL;
    while (p->chave < ch) {
        *ant = p;
        p = p->prox;
    }
    if ((p != l.sentinela) && (p->chave = ch)) return p;
    return NULL;
}

//sem repeticao
bool inserirElemListaOrd (int ch, LISTA* l) {
    NO* p;
    NO* ant;
    p = buscaSeqOrd (ch, *l, &ant);
    if(p) return false;
    NO* novo = (NO*) malloc (sizeof(NO));
    novo->chave = ch;
    if (!ant) {
        novo->prox = l->inicio;
        l->inicio = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return true;
}

void anexarElemLista (int ch, LISTA *l) {
    NO* novo = (NO*) malloc (sizeof(NO));
    novo->chave = ch;
    if (l->inicio == l->sentinela) {
        novo->prox = l->sentinela;
        l->inicio = novo;
    } else {
        NO* p = l->inicio;
        while (p->prox != l->sentinela) p = p->prox;
        novo->prox = l->sentinela;
        p->prox = novo;
    }
}

void destruirLista (LISTA *l) {
    NO* p = l->inicio;
    NO* ant;
    while (p != l->sentinela) {
        ant = p->prox;
        free (p);
        p = ant;
    }
    l->inicio = l->sentinela;
}

int main () {
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
        printf("9- Anexar Elemento na Lista \n");
        printf("10- Fechar \n");
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
                    if (ant) printf ("%d\n", ant);
                    else printf("nao existe \n");
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
                printf("Digite a chave: ");
                scanf("%d", &ch);
                anexarElemLista(ch, &l);
                printf("Exibindo a lista: ");
                exibirLista (l);
                printf("\n");
                break;

            case 10:
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

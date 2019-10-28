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
} LISTA;

void inicializarLista (LISTA* l) {
  l->inicio = NULL;
}

void exibirLista (LISTA l) {
  NO* p = l.inicio;
  while (p) {
    printf("%d ", p->chave);
    p = p->prox;
  }
}

NO* primeiroElemLista (LISTA l) {
  return l.inicio;
}

NO* enesimoElemLista(LISTA l, int n) {
    NO* p = l.inicio;
    for (int i = 1; i <= n; i++) {
        if (!p) return NULL;
        if (i == n) return p;
        p = p->prox;
    }
    return NULL;
}

NO* ultimoElemLista (LISTA l) {
  NO* p = l.inicio;
  if (p) {
    while (p->prox){
      p = p->prox;
    }
  }
  return p;
}

int tamanhoLista (LISTA l) {
    int i = 0;
    NO* p = l.inicio;
    while (p) {
        i++;
        p = p->prox;
    }
    return i;
}

NO* buscaSeqOrd(int ch, LISTA l, NO* *ant) {
    NO* p = l.inicio;
    *ant = NULL;
    while (p) {
        if (p->chave >= ch) break;
        *ant = p;
        p = p->prox;
    }
    if (p)
        if (p->chave == ch) return p;
    return NULL;
}

//Sem duplicacoes
bool inserirElemListaOrd(int ch, LISTA* l) {
    NO* ant;
    NO* p = l->inicio;
    p = buscaSeqOrd(ch,*l,&ant);
    if (p) return false;
    NO* novo =(NO*)malloc(sizeof(NO));
    novo->chave = ch;
    if (!ant||!l->inicio) {
        novo->prox = l->inicio;
        l->inicio = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return true;
}

void anexarElemLista (int ch, LISTA* l) {
    NO* ant = NULL;
    NO* novo = (NO*)malloc(sizeof(NO));
    if (!l->inicio) {
        l->inicio = novo;
        novo->prox = NULL;
    } else {
        NO* p = l->inicio;
        while (p) {
            ant->prox = p;
            p = p->prox;
        }
        ant->prox = novo;
        novo->prox = NULL;
    }
}

NO* busca (int ch, LISTA l, NO* *ant) {
    *ant = NULL;
    NO* p = l.inicio;
    while (p) {
        if (p->chave == ch) return p;
        *ant = p;
        p = p->prox;
    }
    return NULL;
}

bool excluirElemLista(int ch, LISTA* l) {
    NO* p;
    NO* ant;
    p = busca(ch, *l, &ant);
    if (!p) return false;
    if(!ant) l->inicio = p->prox;
    else ant->prox = p->prox;
    free(p);
    return true;
}

void destruirLista (LISTA* l) {
    NO* p;
    NO* ant = l->inicio;
    while (ant) {
        p = ant->prox;
        free(ant);
        ant = p;
    }
    l->inicio = NULL;
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
        printf("2- Excluir \n");
        printf("3- Exibir \n");
        printf("4- Buscar lista ordenada \n");
        printf("5- Buscar \n");
        printf("6- Primeiro Elemento \n");
        printf("7- Ultimo Elemento \n");
        printf("8- Enesimo Elemento \n");
        printf("9- Destruir Lista \n");
        printf("10- Tamanho da Lista \n");
        printf("11- Fechar \n");
        printf("Digite o numero: ");
        scanf("%d", &comando);

        switch(comando) {
            case 1:
                printf("Digite a chave: ");
                scanf("%d", &ch);
                inserirElemListaOrd(ch, &l);
                break;

            case 2:
                printf("Digite a chave: ");
                scanf("%d", &ch);
                excluirElemLista(ch, &l);
                break;

            case 3:
                exibirLista (l);
                printf("\n");
                break;

            case 4:
                printf("Digite a chave: ");
                scanf("%d", &ch);
                NO* p = buscaSeqOrd (ch, l, &ant);
                if(!p) printf("A chave nao existe \n");
                else {
                    printf("O anterior: ");
                    if (ant) {
                        NO* b = ant;
                        printf ("%d\n", b->chave);
                    } else printf("nao existe \n");
                    printf("A chave: ");
                    printf ("%d\n", p->chave);
                }
                break;

            case 5:
                printf("Digite a chave: " );
                scanf("%d", &ch);
                NO* b = busca (ch, l, &ant);
                if(!b) printf("A chave nao existe \n");
                else {
                    printf("O anterior: ");
                    if (ant) printf ("%d\n", ant);
                    else printf("nao existe \n");
                    printf("A chave: ");
                    printf ("%d\n", b->chave);
                }
                break;

            case 6:
                printf("%d\n", primeiroElemLista(l));
                break;

            case 7:
                printf("%d\n", ultimoElemLista(l));
                break;

            case 8:
                printf("Digite a chave: ");
                scanf("%d", &n);
                printf("%d\n", enesimoElemLista(l, n));
                break;

            case 9:
                destruirLista(&l);
                break;

            case 10:
                printf("%d\n", tamanhoLista(l));
                break;

            case 11:
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

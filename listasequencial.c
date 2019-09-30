#include <stdio.h>

#define MAX 50
#define true 1
#define false 0
typedef int bool;

typedef struct {
    int chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int nroElem;
} LISTA;

void inicializarListaSequencial(LISTA* l) {
    l->nroElem = 0;
}

void exibirListaSequencial (LISTA l) {
    for (int i = 0; i < l.nroElem; i++) {
        printf("%d ", l.A[i].chave);
    }
}

int tamanhoLista (LISTA l) {
    return(l.nroElem);
}

int primeiroElem (LISTA l) {
    if (l.nroElem > 0) return l.A[0].chave;
    else return -1;
}

int ultimoElem (LISTA l) {
    if (l.nroElem > 0) return l.A[l.nroElem-1].chave;
    else return -1;
}

int enesimoElem (LISTA l, int n) {
    if (n <= l.nroElem) return l.A[n-1].chave;
    else return -1;
}

void destruirLista (LISTA* l) {
    l->nroElem = 0;
}

bool inserirElemListaSeq (int ch, int i, LISTA* l)  {
    if (l->nroElem >= MAX || l->nroElem < 0 || i < 0 || i > l->nroElem) return false;
    for (int j = l->nroElem; j > i; j--) {
        l->A[j] = l->A[j-1];
    }
    l->A[i].chave = ch;
    l->nroElem++;
    return true;
}

int buscaSeq (int ch, LISTA l) {
    if (l.nroElem <= 0) return -1;
    for (int i = 0; i < l.nroElem; i++) {
        if (l.A[i].chave == ch) return i;
    }
    return -1;
}

int buscaSent (int ch, LISTA l) {
    int i = 0;
    l.A[l.nroElem].chave = ch;
    while (l.A[i].chave < ch) i++;
    if (i >= l.nroElem || l.A[i].chave != ch) return -1;
    else return i;
}

int buscaBin (int ch, LISTA l) {
    int ini = 0, fim = l.nroElem-1;
    while (ini <= fim) {
        if (l.A[(ini+fim)/2].chave > ch) {
            fim = -1 + (ini+fim)/2;
        } else if (l.A[(ini+fim)/2].chave < ch) {
            ini = 1 + (ini+fim)/2;
        } else if (l.A[(ini+fim)/2].chave == ch) {
            return (ini+fim)/2;
        }
    }
    return -1;
}

//sem duplicação com sentinela
bool inserirElemListOrd (int ch, LISTA* l) {
    if (l->nroElem >= MAX) return false;
    l->A[l->nroElem].chave = ch;
    int i = 0;
    while (l->A[i].chave < ch) i++;
    if (l->A[i].chave == ch && i < l->nroElem) return false;
    else return inserirElemListaSeq (ch, i, l);
}

bool excluirElemLista (int ch, LISTA* l) {
    if(l->nroElem <= 0) return false;
    for (int i = 0; i < l->nroElem; i++) {
        if (l->A[i].chave == ch) {
            for (int j = i; i < l->nroElem-1; j++) {
                l->A[j] = l->A[j+1];
            }
            l->nroElem--;
            return true;
        }
    }
    return false;
}

int main(){
    LISTA l;
    int ch, i, n = l.nroElem;
    bool condicao = true;
    inicializarListaSequencial(&l);


    while(condicao) {
        int comando = 0;
        printf("Escolha um comando: \n");
        printf("1- Inserir \n");
        printf("2- Excluir \n");
        printf("3- Exibir \n");
        printf("4- Buscar \n");
        printf("5- Tamanho \n");
        printf("6- Ultimo elemento \n");
        printf("7- Enesimo elemento \n");
        printf("8- Fechar \n");
        printf("9- Primeiro elemento \n");
        printf("10- Destruir lista \n");
        printf("11- Busca com sentinela \n");
        printf("12- Busca binaria \n");
        printf("13- Inserir sem duplicacao com sentinela \n");
        printf("Digite o numero: ");
        scanf("%d", &comando);

        switch(comando) {
            case 1:
                printf("Digite a chave: ");
                scanf("%d", &ch);
                printf("Digite a posicao: ");
                scanf("%d", &i);
                inserirElemListaSeq (ch, i, &l);
                break;

            case 2:
                printf("Digite a chave: ");
                scanf("%d", &ch);
                excluirElemLista (ch, &l);
                break;

            case 3:
                exibirListaSequencial (l);
                printf("\n");
                break;

            case 4:
                printf("Digite a chave: " );
                scanf("%d", &ch);
                printf ("%d\n", buscaSeq (ch, l));
                break;

            case 5:
                printf ("%d\n", tamanhoLista (l));
                break;

            case 6:
                printf ("%d\n", ultimoElem (l));
                break;

            case 7:
                scanf("%d", &i);
                printf("%d\n", enesimoElem(l, n));
                break;

            case 8:
                condicao = false;
                break;

            case 9:
                printf("%d\n", primeiroElem (l));
                break;
            case 10:
                destruirLista (&l);
                break;
            case 11:
                printf("Digite a chave: ");
                scanf("%d", &ch);
                printf("%d\n", buscaSeq (ch, l));
                break;
            case 12:
                printf("Digite a chave: ");
                scanf("%d", &ch);
                printf("%d\n", buscaBin (ch, l));
                break;
            case 13:
                printf("Digite a chave: ");
                scanf("%d", &ch);
                printf("%d\n", inserirElemListOrd (ch, &l));
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

#include <stdio.h>

#define MAX 50
#define true 1
#define false 0
typedef int bool;

typedef struct {
    int chave;
    int prox;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int inicio;
    int dispo;
} LISTA;


void inicializarListaDinamicaEstatica(LISTA* l) {
    l->inicio = -1;
    l->dispo = 0;
    for (int i = 0; i < MAX-1; i++) l->A[i].prox = i+1;
    l->A[MAX-1].prox = -1;
}

void exibirLista (LISTA l) {
    int i = l.inicio;
    while (i != l.dispo) { //while (i > -1)
        printf("%d ", l.A[i].chave);
        i = l.A[i].prox;
    }
}
//insercao lista ordenada sem duplicacao
bool inserirElemListaEncOrd (int ch, LISTA* l) {
    int ant, i;
    int i = buscaSeqOrd(ch, *l, &ant);
    if (l->dispo < 0 || i != -1) return false;
    i = obterNo(l);
    if (busca) return false;
    int p = l->A[0];
    while(p != -1) {
        if(p->prox == -1) ant = p;
    }
    if (ant = -1) l->A[0].chave = ch;
    l->dispo = ;
    ant->prox = ch;
    l->A[p+1].prox =
}

bool excluirElemListaEnc (int ch, LISTA* l) {
    return true;
}

int buscaSeqOrd (int ch, LISTA l, int *ant) {
    return 0;
}

int obterNo (LISTA* l) {
    return 0;
}

void devolverNo (LISTA* l, int j) {
    return;
}

int main(){
    LISTA l;
    int ch, j, ant;
    bool condicao = true;
    inicializarListaDinamicaEstatica(&l);


    while(condicao) {
        int comando = 0;
        printf("Escolha um comando: \n");
        printf("1- Inserir lista ordenada sem duplicacao \n");
        printf("2- Excluir \n");
        printf("3- Exibir \n");
        printf("4- Buscar \n");
        printf("5- Obter no disponivel \n");
        printf("6- Devolver no para disponivel \n");
        printf("7- Fechar \n");
        printf("Digite o numero: ");
        scanf("%d", &comando);

        switch(comando) {
            case 1:
                printf("Digite a chave: ");
                scanf("%d", &ch);
                inserirElemListaEncOrd (ch, &l);
                break;

            case 2:
                printf("Digite a chave: ");
                scanf("%d", &ch);
                excluirElemListaEnc (ch, &l);
                break;

            case 3:
                exibirLista (l);
                printf("\n");
                break;

            case 4:
                printf("Digite a chave: " );
                scanf("%d", &ch);
                printf ("%d\n", buscaSeqOrd (ch, l, &ant));
                break;

            case 5:
                printf ("%d\n", obterNo (&l));
                break;

            case 6:
                printf("Digite a posicao: ");
                scanf("%d", &j);
                devolverNo(&l, j);
                break;

            case 7:
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

#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
} no;

// função insere(no)
//  insere := -1
//      se topo ≠ M então
//      topo := topo + 1
//      P[topo] := no
//      insere := topo

/*
    @param p: pilha
    @param m: tamanho máximo da pilha
    @param *topo: tamanho atual da pilha
    @param x: no que será inserido
*/
int inserePilha(no p[], int m, int *topo, no x)
{

    int retorno = -1;
    if (*topo < m - 1)
    {
        (*topo)++; // topo = topo + 1
        p[*topo] = x;
        retorno = *topo;
    }

    return retorno;
}

// topo = 2
no *removePilha(no p[], int *topo)
{
    no *retorno = NULL;
    if (*topo != -1)
    {
        retorno = malloc(sizeof(no *));
        (*retorno).chave = p[*topo].chave;
        (*retorno).valor = p[*topo].valor;
        (*topo)--;
    }

    return retorno;
}

void imprimePilha(no p[], int topo)
{
    for (int i = topo; i >= 0; i--)
    {
        printf("\n Chave: %d", p[i].chave);
        printf("\n Valor: %d\n", p[i].valor);
        printf("===============================");
    }
}

int main()
{
    int m;
    printf("Qual o tamanho da pilha: ");
    scanf("%d", &m);
    no pilha[m];
    int saida = 1;
    int topo = -1;

    no x;

    while (saida)
    {
        printf("\nO que quer fazer:\n");
        printf("0: sair\n");
        printf("1: inserir na pilha\n");
        printf("2: remove da pilha\n");
        printf("3: imprime pilha\n");

        scanf("%d", &saida);
        if (saida == 1)
        {
            printf("\n Digite a chave do nó que quer adicionar: ");
            scanf("%d", &x.chave);
            printf("\n Digite o valor do nó que quer adicionar: ");
            scanf("%d", &x.valor);
            if (inserePilha(pilha, m, &topo, x) == -1)
            {
                printf("\n A pilha ta cheia");
            }
        }
        if (saida == 2)
        {
            if (topo < 0)
            {
                printf("\n *pilha vazia*");
            }
            else
            {
                no *temp = removePilha(pilha, &topo);
                printf("\n Chave removida: %d", (*temp).chave);
                printf("\n Valor removido: %d", (*temp).valor);
                printf("\n===============================");
            }
        }
        if (saida == 3)
        {
            imprimePilha(pilha, topo);
        }
    }

    return 0;
}
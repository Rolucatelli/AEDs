#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
    struct no_ *prox;
} no;

void inserir(no **topo, no *novoNo)
{
    novoNo->prox = *topo;
    *topo = novoNo;
}

no *remover(no **topo)
{
    if (*topo != NULL)
    {
        no *retorno = *topo;
        *topo = retorno->prox;
        return retorno;
    }
    return NULL;
}

no *alocarNo()
{
    no *retorno = malloc(sizeof(no));
    printf("Informe a chave: ");
    scanf("%d", &retorno->chave);
    printf("Informe o valor: ");
    scanf("%d", &(*retorno).valor);
    retorno->prox = NULL;
    return retorno;
}

void ler_menu(int *resposta)
{
    printf("\n-----------------------\n");
    printf("escolha uma das opcoes:\n");
    printf("0 - sair\n");
    printf("1 - inserir\n");
    printf("2 - remover\n");
    printf("3 - imprimir\n");
    scanf("%d", resposta);
    printf("-----------------------\n\n");
}

void imprimir(no *topo)
{
    if (topo == NULL)
    {
        printf("pilha vazia");
        return;
    }

    printf("topo --> \n");
    while (topo != NULL)
    {
        printf("\t%d:%d", topo->chave, topo->valor);
        topo = topo->prox;
        printf("\n \t| \n");
    }
    printf("\tNULL\n");
}

int main()
{
    no *topo = NULL;
    int resposta = 1;
    while (resposta)
    {
        ler_menu(&resposta);
        if (resposta == 1)
        {
            no *novoNo = alocarNo();
            inserir(&topo, novoNo);
        }
        if (resposta == 2)
        {
            no *temp = remover(&topo);
            if (temp != NULL)
            {
                printf("\n Chave removida: %d\n", temp->chave);
                printf("\n Valor removido: %d\n", temp->valor);
            }
            else
            {
                printf("\n **pilha vazia**");
            }
        }
        if (resposta == 3)
        {
            imprimir(topo);
        }

        // switch (resposta)
        // {
        // case 1:
        //     /* inserir */
        //     break;
        // case 2:
        //     /* remover */
        //     break;
        // case 3:
        //     /* imprimir */
        //     break;
        // case 4:
        //     /* buscar */
        //     break;
        // default:
        //     break;
        // }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
    struct no_ *prox;
} no;

void buscar(no *ptlista, int x, no **ant, no **pont)
{
    *pont = NULL;
    *ant = ptlista;
    no *ptr = ptlista->prox;

    while (ptr != NULL)
    {
        if (ptr->chave < x)
        {
            *ant = ptr;
            ptr = ptr->prox;
        }
        else
        {
            if (ptr->chave == x)
            {
                *pont = ptr;
            }
            ptr = NULL; // break;
        }
    }
}

no *inserir(no *ptlista, no *novo_no)
{
    no *ant, *pont;
    buscar(ptlista, novo_no->chave, &ant, &pont);
    if (pont == NULL)
    {
        novo_no->prox = ant->prox;
        ant->prox = novo_no;
        return NULL;
    }
    return pont;
}

no *remover(no *ptlista, int x)
{
    no *ant, *pont;
    buscar(ptlista, x, &ant, &pont);
    if (pont != NULL)
    {
        ant->prox = pont->prox;
        return pont;
    }
    else
    {
        return NULL;
    }
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
    printf("4 - buscar\n");
    scanf("%d", resposta);
    printf("-----------------------\n\n");
}

void imprimir(no *ptlista)
{
    if (ptlista->prox == NULL)
    {
        printf("<lista vazia!>");
        return;
    }

    ptlista = ptlista->prox;
    while (ptlista != NULL)
    {
        printf("%d:%d", ptlista->chave, ptlista->valor);
        ptlista = ptlista->prox;
        printf(" -> ");
        if (ptlista == NULL)
            printf("NULL");
    }
}

int main()
{
    no *ptlista = malloc(sizeof(no));
    ptlista->prox = NULL;
    int resposta = 1;
    while (resposta)
    {
        ler_menu(&resposta);
        if (resposta == 1)
        {
            no *novoNo = alocarNo();
            inserir(ptlista, novoNo);
        }
        if (resposta == 2)
        {
            int x;
            printf("\n Digite a chave que quer remover: ");
            scanf("%d", &x);
            no *temp = remover(ptlista, x);
            if (temp != NULL)
            {
                printf("\n Chave removida: %d\n", temp->chave);
                printf("\n Valor removido: %d\n", temp->valor);
            }
            else
            {
                printf("\n **Lista vazia ou valor não encontrado**");
            }
        }
        if (resposta == 3)
        {
            imprimir(ptlista);
        }
        if (resposta == 4)
        {
            int x;
            printf("\n Digite a chave que quer buscar: ");
            scanf("%d", &x);
            no *ant, *pont;
            buscar(ptlista, x, &ant, &pont);
            if (pont != NULL)
            {
                printf("\n Valor encontrado: %d", pont->valor);
            }
            else
            {
                printf("\n Valor não encontrado!");
            }
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
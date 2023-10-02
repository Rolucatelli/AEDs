#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
    struct no_ *prox;
    struct no_ *ant;
} no;

void buscarCabeca(no *cabeca, no *cauda, int x, no **pont)
{
    *pont = NULL;
    no *ptr = cabeca->prox;
    printf("\n 16");
    while (ptr->prox != NULL)
    {
        printf("\n 19");
        if (ptr->chave < x)
        {
            printf("\n 22");
            ptr = ptr->prox;
        }
        else
        {
            if (ptr->chave == x)
            {
                printf("\n 29");
                *pont = ptr;
            }
            printf("\n 32");
            break;
        }
    }
}

void buscarCauda(no *cauda, int x, no **pont)
{
    *pont = NULL;
    no *ptr = cauda->prox;

    while (ptr != NULL)
    {
        if (ptr->chave > x)
        {

            ptr = ptr->ant;
        }
        else
        {
            if (ptr->chave == x)
            {
                *pont = ptr;
            }
            ptr = NULL;
        }
    }
}

no *inserirLista(no *cabeca, no *cauda, no *novoNo)
{
    no *pont;
    buscarCabeca(cabeca, cauda, novoNo->chave, &pont);
    printf("\n BUSCA FEITA");
    if (pont == NULL)
    {
        if (cabeca->prox->prox == NULL)
        {
            novoNo->prox = cabeca->prox->prox;
            cabeca->prox->prox->ant = novoNo;
            cabeca->prox->prox = novoNo;
            novoNo->ant = cabeca->prox;
        }
        else
        {

            novoNo->prox = pont->prox;
            pont->prox->ant = novoNo;
            pont->prox = novoNo;
            novoNo->ant = pont;
        }
    }
    return pont;
}

no *removerLista(no *cabeca, no *cauda, int x)
{
    no *pont;
    no *retorno = malloc(sizeof(no));
    buscarCabeca(cabeca, cauda, x, &pont);
    if (pont != NULL)
    {
        retorno = pont;
        pont->ant = pont->prox;
        pont->prox = pont->ant;
    }
    return retorno;
}

no *alocar_no()
{
    no *novo_no = malloc(sizeof(no));
    printf("informe a chave: ");
    scanf("%d", &novo_no->chave);
    printf("informe o valor: ");
    scanf("%d", &novo_no->valor);
    printf("\n");
    novo_no->prox = NULL;
    novo_no->ant = NULL;
    return novo_no;
}

void imprimir(no *cabeca)
{
    if (cabeca->ant == NULL && cabeca->prox->prox == NULL)
    {
        printf("Lista vazia");
        return;
    }

    printf("cabeca --> ");
    while (cabeca->prox != NULL)
    {
        printf("%d:%d", cabeca->prox->chave, cabeca->prox->valor);
        cabeca = cabeca->prox;
        if (cabeca->prox != NULL)
            printf(" -> ");
    }
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

int main()
{
    no *cabeca = malloc(sizeof(no)), *cauda = malloc(sizeof(no));

    cabeca->prox = cauda;
    cauda->prox = cabeca;
    int resposta = 1;

    while (resposta != 0)
    {
        ler_menu(&resposta);
        if (resposta == 0)
        {
            // sair
            // desalocar
        }
        if (resposta == 1)
        {
            // inserir
            no *novo_no = alocar_no();
            printf("nó criado\n");
            printf("chave: %d\n", novo_no->chave);
            printf("valor: %d\n", novo_no->valor);
            inserirLista(cabeca, cauda, novo_no);
        }
        else if (resposta == 2)
        {
            // remover
            int x;
            printf("\n Que chave deseja remover? ");
            scanf("%d", &x);
            no *no_removido = removerLista(cabeca, cauda, x);
            if (no_removido != NULL)
            {
                printf("nó removido\n");
                printf("chave: %d\n", no_removido->chave);
                printf("valor: %d\n", no_removido->valor);
                free(no_removido);
            }
            else
            {
                printf("lista vazia");
            }
        }
        else if (resposta == 3)
        {
            // imprimir
            imprimir(cabeca);
        }
        else
        {
            printf("Opcao invalida\n");
        }
    }

    return 0;
}

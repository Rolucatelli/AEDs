#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
    struct no_ *prox;
    struct no_ *ant;
} no;

void buscarCabeca(no *cabeca, int x, no **pont, no **prev)
{
    *pont = NULL;
    *prev = cabeca;
    no *ptr = cabeca->prox;
    while (ptr->prox != NULL)
    {
        if (ptr->chave < x)
        {
            *prev = ptr;
            ptr = ptr->prox;
        }
        else
        {
            if (ptr->chave == x)
            {
                *prev = ptr;
                *pont = ptr;
            }
            return;
        }
    }
}

void buscarCauda(no *cauda, int x, no **pont, no **prev)
{
    *pont = NULL;
    *prev = cauda;
    no *ptr = cauda->ant;

    while (ptr->ant != NULL)
    {
        if (ptr->chave > x)
        {
            *prev = ptr;
            ptr = ptr->ant;
        }
        else
        {
            if (ptr->chave == x)
            {

                *pont = ptr;
            }
            return;
        }
    }
}

no *inserirLista(no *cabeca, no *novoNo)
{
    no *pont, *prev;
    buscarCabeca(cabeca, novoNo->chave, &pont, &prev);
    if (pont == NULL)
    {
        if (cabeca->prox->prox == NULL)
        {
            novoNo->prox = cabeca->prox;
            cabeca->prox->ant = novoNo;
            cabeca->prox = novoNo;
            novoNo->ant = cabeca;
        }
        else
        {

            novoNo->prox = prev->prox;
            prev->prox->ant = novoNo;
            prev->prox = novoNo;
            novoNo->ant = prev;
        }
    }
    return pont;
}

no *removerLista(no *cabeca, int x)
{
    no *pont, *prev;
    no *retorno = NULL;
    buscarCabeca(cabeca, x, &pont, &prev);
    if (pont != NULL)
    {
        retorno = malloc(sizeof(no));
        *retorno = *pont;
        pont->ant->prox = pont->prox;
        pont->prox->ant = pont->ant;
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

void imprimirCabeca(no *cabeca)
{
    if (cabeca->ant == NULL && cabeca->prox->prox == NULL)
    {
        printf("Lista vazia");
        return;
    }

    printf("cabeca --> ");
    while (cabeca->prox->prox != NULL)
    {
        printf("%d:%d", cabeca->prox->chave, cabeca->prox->valor);
        cabeca = cabeca->prox;
        if (cabeca->prox->prox != NULL)
            printf(" <-> ");
    }
    printf(" <-- cauda ");
}

void imprimirCauda(no *cauda)
{
    if (cauda->prox == NULL && cauda->ant->ant == NULL)
    {
        printf("Lista vazia");
        return;
    }

    printf("cauda --> ");
    while (cauda->ant->ant != NULL)
    {
        printf("%d:%d", cauda->ant->chave, cauda->ant->valor);
        cauda = cauda->ant;
        if (cauda->ant->ant != NULL)
            printf(" <-> ");
    }
    printf(" <-- cabeca ");
}

void desalocarLista(no *cabeca)
{
    no *tmp = cabeca->prox;
    while (cabeca != NULL)
    {
        free(cabeca);
        cabeca = tmp;
        if (tmp->prox != NULL)
        {
            tmp = tmp->prox;
        }
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
    cauda->ant = cabeca;
    int resposta = 1;

    while (resposta != 0)
    {
        ler_menu(&resposta);
        if (resposta == 0)
        {
            // sair
            // desalocar
            return 0;
        }
        if (resposta == 1)
        {
            // inserir
            no *novo_no = alocar_no();
            printf("chave: %d\n", novo_no->chave);
            printf("valor: %d\n", novo_no->valor);
            inserirLista(cabeca, novo_no);
        }
        else if (resposta == 2)
        {
            // remover
            int x;
            printf("\n Que chave deseja remover? ");
            scanf("%d", &x);
            no *no_removido = removerLista(cabeca, x);
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
            // imprimir'
            imprimirCabeca(cabeca);
        }
        else
        {
            printf("Opcao invalida\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int valor;
    struct no_ *esq;
    struct no_ *dir;
} no;

/**
 * ok
 */
no *busca(no *raiz, int valor)
{
    if (raiz == NULL || raiz->valor == valor)
        return raiz;
    if (valor < raiz->valor)
        return busca(raiz->esq, valor);
    else
        return busca(raiz->dir, valor);
}

no *buscaPai(no *raiz, no *n)
{
    if (raiz == NULL || raiz == n)
        return NULL;
    if (raiz->esq == n || raiz->dir == n)
        return raiz;
    if (n->valor < raiz->valor)
        return buscaPai(raiz->esq, n);
    else
        return buscaPai(raiz->dir, n);
}

/**
 * ok
 */
no *insere(no *raiz, no *n)
{
    if (raiz == NULL)
        return n;
    if (raiz->valor > n->valor)
        raiz->esq = insere(raiz->esq, n);
    else
        raiz->dir = insere(raiz->dir, n);

    return raiz;
}

/*
no *removeRaiz(no *raiz)
{
    if (raiz->esq == NULL)
        return raiz->dir;
    if (raiz->dir == NULL)
        return raiz->esq;
    no *temp = raiz->esq;
    while (temp->dir != NULL)
    {
        temp = temp->dir;
    }
    no *tempPai = buscaPai(raiz, temp);
    tempPai->dir = temp->esq;
    temp->dir = raiz->dir;
    temp->esq = raiz->esq;
    return temp;
}*/

no *removeRaiz(no *raiz)
{
    if (raiz->esq == NULL)
    {
        no *tmp = raiz->dir;
        free(raiz);
        return (tmp);
    }
    if (raiz->dir == NULL)
    {
        no *tmp = raiz->esq;
        free(raiz);
        return (tmp);
    }
    no *p = raiz;
    no *q = raiz->esq;
    while (q->dir != NULL)
    {
        p = q;
        q = q->dir;
    }
    if (p != raiz)
    {
        p->dir = q->esq;
        q->esq = raiz->esq;
    }
    q->dir = raiz->dir;
    free(raiz);
    return q;
}

/**
 * ok
 */
no *removeNo(no *raiz, int x)
{
    no *n = busca(raiz, x);
    if (n != NULL)
    {
        no *pai = buscaPai(raiz, n);
        if (pai != NULL)
        {
            if (pai->dir == n)
            {
                pai->dir = removeRaiz(n);
            }
            else
            {
                pai->esq = removeRaiz(n);
            }
        }
        else
        {
            raiz = removeRaiz(n);
        }
    }
    return raiz;
}

void imprimirPreOrdem(no *raiz)
{
    if (raiz != NULL)
    {
        printf("%d => ", raiz->valor);
        if (raiz->esq != NULL)
            imprimirPreOrdem(raiz->esq);
        if (raiz->dir != NULL)
            imprimirPreOrdem(raiz->dir);
    }
}

void imprimirEmOrdem(no *raiz)
{
    if (raiz != NULL)
    {
        if (raiz->esq != NULL)
            imprimirEmOrdem(raiz->esq);
        printf("%d => ", raiz->valor);
        if (raiz->dir != NULL)
            imprimirEmOrdem(raiz->dir);
    }
}

void imprimirPosOrdem(no *raiz)
{
    if (raiz != NULL)
    {
        if (raiz->esq != NULL)
            imprimirPosOrdem(raiz->esq);
        if (raiz->dir != NULL)
            imprimirPosOrdem(raiz->dir);
        printf("%d => ", raiz->valor);
    }
}

no *alocarNo()
{
    int n;
    printf("\n Digite o valor do no: ");
    scanf("%d", &n);
    no *novoNo = malloc(sizeof(no));
    novoNo->valor = n;
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    return novoNo;
}

void desalocarArvore(no *raiz)
{
    if (raiz != NULL)
    {
        if (raiz->esq != NULL)
            desalocarArvore(raiz->esq);
        if (raiz->dir != NULL)
            desalocarArvore(raiz->dir);
        free(raiz);
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
    int resposta = 1;
    no *raiz = NULL;

    while (resposta)
    {
        ler_menu(&resposta);

        if (resposta == 0)
        {

            desalocarArvore(raiz);
        }
        else if (resposta == 1)
        {

            no *novoNo = alocarNo();
            if (busca(raiz, novoNo->valor) == NULL)
            {
                raiz = insere(raiz, novoNo);
            }
            else
            {
                printf("\n Ja existe no com esse valor!");
            }
        }
        else if (resposta == 2)
        {

            int x;
            printf("\n Digite o valor que quer remover: ");
            scanf("%d", &x);
            raiz = removeNo(raiz, x);
        }
        else if (resposta == 3)
        {
            int ordem;
            printf("escolha a maneira de imprimir:\n");
            printf("1 - pre-ordem\n");
            printf("2 - em-ordem\n");
            printf("3 - pos-ordem\n");
            scanf("%d", &ordem);
            printf("-----------------------\n\n");

            printf("Arvore: ");
            switch (ordem)
            {
            case 1:
                imprimirPreOrdem(raiz);
                break;
            case 2:
                imprimirEmOrdem(raiz);
                break;
            case 3:
                imprimirPosOrdem(raiz);
                break;

            default:
                printf("Opção inválida\n");
                break;
            }
        }
        else
        {

            printf("Opção inválida\n");
        }
    }

    return 0;
}

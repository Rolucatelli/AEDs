#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef char *string;

typedef struct node_
{
    int info;
    struct node *esq;
    struct node *dir;
} Node;

Node *insere(Node *raiz, Node *n)
{
    if (raiz == NULL)
        return n;
    if (raiz->info > n->info)
        raiz->esq = insere(raiz->esq, n);
    else
        raiz->dir = insere(raiz->dir, n);

    return raiz;
}

void imprimirPreOrdem(Node *raiz)
{
    printf("%d => ", raiz->info);
    if (raiz->esq != NULL)
        imprimirPreOrdem(raiz->esq);
    if (raiz->dir != NULL)
        imprimirPreOrdem(raiz->dir);
}

void imprimirEmOrdem(Node *raiz)
{
    if (raiz->esq != NULL)
        imprimirEmOrdem(raiz->esq);
    printf("%d => ", raiz->info);
    if (raiz->dir != NULL)
        imprimirEmOrdem(raiz->dir);
}

void imprimirPosOrdem(Node *raiz)
{
    if (raiz->esq != NULL)
        imprimirPosOrdem(raiz->esq);
    if (raiz->dir != NULL)
        imprimirPosOrdem(raiz->dir);
    printf("%d => ", raiz->info);
}

Node *remover(Node *raiz, int valor)
{
    if (!raiz) // raiz == NULL
    {
        return raiz;
    }

    if (raiz->info == valor)
    {
        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            free(raiz);
            return NULL;
        }
        if (raiz->esq == NULL)
        {
            Node *temp = raiz->dir;
            free(raiz);
            return temp;
        }
        if (!raiz->dir)
        {
            Node *temp = raiz->esq;
            free(raiz);
            return temp;
        }
        Node *temp = raiz->esq;
        Node *anterior = temp;
        while (temp->dir != NULL)   
        {
            anterior = temp;
            temp = temp->dir;
        }




        
    }
    else if (raiz->info > valor)
    {
        raiz->esq = remover(raiz->esq, valor);
    }
    else
    {
        raiz->dir = remover(raiz->dir, valor);
    }
}

int main()
{
    Node *raiz;

    return 0;
}

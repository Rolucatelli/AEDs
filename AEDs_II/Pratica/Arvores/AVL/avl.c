#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int info, fb;
    struct node *esq, *dir;
}Node;

Node *busca(Node *raiz, int valor)
{
    if (raiz == NULL || raiz->info == valor)
        return raiz;
    if (valor < raiz->info)
        return busca(raiz->esq, valor);
    else
        return busca(raiz->dir, valor);
}

Node *buscaPai(Node *raiz, Node *n)
{
    if (raiz == NULL || raiz->esq == n || raiz->dir == n)
        return raiz;
    if (n->info < raiz->info)
        return buscaPai(raiz->esq, n);
    else
        return buscaPai(raiz->dir, n);
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

// Node *insere(Node *raiz, Node *n)
// {
//     if (raiz == NULL)
//         return n;
//     if (raiz->info > n->info)
//         raiz->esq = insere(raiz->esq, n);
//     else
//         raiz->dir = insere(raiz->dir, n);

//     return raiz;
// }

Node *RSE(Node *raiz){
    Node* temp = raiz->dir;
    raiz->dir = temp->esq;
    temp->esq = raiz;
    return temp;
}

Node *RSD(Node *raiz){
    Node* temp = raiz->esq;
    raiz->esq = temp->dir;
    temp->dir = raiz;
    return temp;
}














int main()
{
    
    return 0;
}

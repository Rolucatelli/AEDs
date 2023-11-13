#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    int fb;
    struct no *esq;
    struct no *dir;
} Node;

/*
    1                       2
        2               1       3
            3
*/

Node *rotacaoEsquerda(Node *raiz)
{
    // Sem consultar o que foi feito semana passada :)
}

/*
        3               2
    2               1       3
1
*/

Node *rotacaoDireita(Node *raiz)
{
    Node* temp = raiz->esq;
    raiz->esq = temp->dir;
    temp->dir = raiz;
    return temp;

    // Node *temp = raiz;
    // raiz = raiz->esq;
    // temp->esq = raiz->dir;
    // raiz->dir = temp;
    // return raiz;

}

int main()
{
    Node *n1 = (Node *)malloc(sizeof(Node));
    n1->info = 3;
    Node *n2 = (Node *)malloc(sizeof(Node));
    n2->info = 2;
    Node *n3 = (Node *)malloc(sizeof(Node));
    n3->info = 1;
    n1->esq = n2;
    n2->esq = n3;
    Node *raiz = n1;
    raiz = rotacaoDireita(raiz);
    return 1;
}
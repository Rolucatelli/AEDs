#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info, fb;
    struct node *esq, *dir;
} Node;

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

Node *RSE(Node *raiz)
{
    Node *temp = raiz->dir;
    raiz->dir = temp->esq;
    temp->esq = raiz;
    raiz->fb = 0;
    temp->fb++;
    return temp;
}

Node *RSD(Node *raiz)
{
    Node *temp = raiz->esq;
    raiz->esq = temp->dir;
    temp->dir = raiz;
    return temp;
}

Node *RDD(Node *raiz)
{
    raiz->dir = RSE(raiz->dir);
    return RSD(raiz);
}

Node *RDE(Node *raiz)
{
    raiz->esq = RSD(raiz->esq);
    return RSE(raiz);
}

int calcularFB(Node *no){
    int altEsq = 0, altDir = 0;
    while (no->esq != NULL)
    {
        altEsq++;
        no->esq = no->esq->esq;
    }
    
    // Ta ERRADO!

    while (no->dir != NULL)
    {
        altDir++;
        no->dir = no->dir->dir;
    }
    
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Node *alocarNo()
{
    int n;
    printf("\n Digite o valor do no: ");
    scanf("%d", &n);
    Node *novoNo = malloc(sizeof(Node));
    novoNo->info = n;
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    novoNo->fb = 0;
    return novoNo;
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
    Node *raiz = alocarNo();

    Node *no1 = alocarNo(), *no2 = alocarNo();
    raiz->esq = no1;
    no1->dir = no2;


    while (resposta)
    {
        ler_menu(&resposta);

        if (resposta == 0)
        {
        }
        else if (resposta == 1)
        {
            Node *novoNo = alocarNo();
        }
        else if (resposta == 2)
        {
            // remover
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
        else if (resposta == 4)
        {
            int ordem;
            printf("escolha a rotação:\n");
            printf("1 - RSE\n");
            printf("2 - RSD\n");
            printf("3 - RDE\n");
            printf("4 - RDD\n");
            scanf("%d", &ordem);
            printf("-----------------------\n\n");


            switch (ordem)
            {
            case 1:
                raiz = RSE(raiz);
                break;
            case 2:
                raiz = RSD(raiz);
                break;
            case 3:
                raiz = RDE(raiz);
                break;
            case 4:
                raiz = RDD(raiz);
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
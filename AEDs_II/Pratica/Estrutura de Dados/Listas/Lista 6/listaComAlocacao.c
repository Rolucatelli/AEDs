#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct no
{
    int info;
    struct no *prox;
    struct no *ant;
} Node;

typedef struct
{
    struct no *comeco;
} Lista;

// Iniciar a lista
void iniciaLista(Lista *lista)
{
    lista->comeco = NULL;
}

// Mostrar/Exibir a lista
void mostraLista(Lista lista)
{
    Node *aux = lista.comeco;

    // Um primeiro acesso para entrar no while
    printf("%d \t", aux->info);
    aux = aux->prox;
    while (aux != lista.comeco)
    {
        printf("%d \t", aux->info);
        aux = aux->prox;
    }
}

void mostraListaInversa(Lista lista)
{
    Node *aux = lista.comeco->ant;

    // Um primeiro acesso para entrar no while
    printf("%d \t", aux->info);
    aux = aux->ant;
    while (aux != lista.comeco->ant)
    {
        printf("%d \t", aux->info);
        aux = aux->ant;
    }
}

// Inserir na lista DE FORMA ORDENADA
void insere(Lista *lista, int valor)
{

    Node *novoNoh = (Node *)malloc(sizeof(Node));
    novoNoh->info = valor;
    // LISTA VAZIA
    if (lista->comeco == NULL)
    {
        lista->comeco = novoNoh;
        novoNoh->prox = novoNoh->ant = novoNoh;

    }else if(lista->comeco->info > valor){
        novoNoh->prox = lista->comeco;
        novoNoh->ant = lista->comeco->ant;
        lista->comeco->ant->prox = novoNoh;
        lista->comeco->ant = novoNoh;
        lista->comeco = novoNoh;
    }
    else
    { // LISTA NÃO VAZIA
        Node *aux = lista->comeco->prox;
        while (aux != lista->comeco && aux->info < valor)
        {
            aux = aux->prox;
        }
        novoNoh->prox = aux;
        novoNoh->ant = aux->ant;
        novoNoh->ant->prox = novoNoh;
        aux->ant = novoNoh;
    }
}

// Remover um elemento da lista
int removeDaLista(Lista *lista, int valor)
{
    if (lista->comeco == NULL)
    {
        printf("Lista vazia. Impossível remover!\n");
        return FALSE;
    }
    Node *atual = lista->comeco;
    // LISTA: 1 -> 3 -> 4 -> 8
    // REMOVER: 1
    if (lista->comeco->info == valor)
    {
        lista->comeco = lista->comeco->prox;
        lista->comeco->ant->ant->prox = lista->comeco;
        lista->comeco->ant = lista->comeco->ant->ant;
        free(atual);
        return TRUE;
    }
    atual = atual->prox;
    while (atual != lista->comeco)
    {
        if (atual->info == valor)
        {
            atual->ant->prox = atual->prox;
            atual->prox->ant = atual->ant;
            free(atual);
            return TRUE;
        }
        atual = atual->prox;
    }
    return FALSE;
}

int main()
{
    Lista lista;
    iniciaLista(&lista);
    int a = removeDaLista(&lista, 5);
    printf("Valor removido: %d\n", a);
    insere(&lista, 5);
    insere(&lista, 6);
    insere(&lista, 3);
    insere(&lista, 4);
    insere(&lista, 8);
    insere(&lista, 2);
    insere(&lista, 1);
    insere(&lista, 7);
    insere(&lista, -1);
    mostraLista(lista);
    printf("\n\n");
    mostraListaInversa(lista);
    removeDaLista(&lista, 6);
    removeDaLista(&lista, 8);
    removeDaLista(&lista, -1);
    int elemento = removeDaLista(&lista, 99);
    printf("\nValor foi removido? %d", elemento);
    printf("\n\n");
    mostraLista(lista);
    printf("\n\n");
    mostraListaInversa(lista);
}
#include <stdio.h>
#define TAM 8

typedef struct
{
    int info;
    int prox;
} Node;

int comeco, disponivel;

void iniciaLista(Node *lista, int *comeco, int *disponivel)
{
    for (int i = 0; i < TAM - 1; i++)
    {
        lista[i].info = 0;
        lista[i].prox = i + 1;
    }
    lista[TAM - 1].info = 0;
    lista[TAM - 1].prox = -1;
    *comeco = -1;
    *disponivel = 0;
}
// Comeco == 0
void imprimeLista(Node *lista, int comeco, int disponivel)
{
    if (comeco == -1)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        int proximo = lista[comeco].prox;
        printf("Lista / Info: %d, Prox: %d\n", lista[comeco].info, lista[comeco].prox);
        while (proximo != -1 && proximo != disponivel)
        {
            printf("Lista / Info: %d, Prox: %d\n", lista[proximo].info, lista[proximo].prox);
            proximo = lista[proximo].prox;
        }
    }
}

void adicionaNaLista(Node *lista, int *comeco, int *disponivel, int valor)
{
    if (*disponivel == -1)
    {
        printf("Lista cheia! Impossivel adicionar o valor %d na lista \n", valor);
    }
    else
    {
        if (*comeco == -1)
        {
            *comeco = *disponivel;
        }
        lista[*disponivel].info = valor;
        *disponivel = lista[*disponivel].prox;
        printf("Valor %d adicionado com sucesso na lista!\n", valor);
    }
}


void removerDaLista(Node *lista, int *comeco, int *disponivel)
{
    // Verifica se a lista não está vazia
    if (*comeco != -1)
    {
        //Cria uma variável para armazenar o próximo elemento
        int proximo = lista[*comeco].prox;
        printf("Valor removido: %d \n", lista[*comeco].info);
        // Verifica se tem só um elemento na lista
        if (*disponivel == 1)
        {
            //Deixa a lista vazia
            *disponivel = *comeco;
            *comeco = -1;
        }
        else
        {
            int i;
            //Puxa os elementos para a frente da lista
            for (i = 0; i < (*disponivel) - 1; i++)
            {
                lista[i].info = lista[proximo].info;
                proximo = lista[proximo].prox;
            }
            //Atualiza o disponivel
            *disponivel = lista[i - 1].prox;
        }
    }
    else
    {
        printf("Lista vazia!\n");
    }
}

int main()
{
    
    Node lista[TAM];
    iniciaLista(lista, &comeco, &disponivel);
    imprimeLista(lista, comeco, disponivel);
    adicionaNaLista(lista, &comeco, &disponivel, 18);
    adicionaNaLista(lista, &comeco, &disponivel, 22);
    adicionaNaLista(lista, &comeco, &disponivel, 3);
    adicionaNaLista(lista, &comeco, &disponivel, 28);
    adicionaNaLista(lista, &comeco, &disponivel, 21);
    adicionaNaLista(lista, &comeco, &disponivel, 17);
    adicionaNaLista(lista, &comeco, &disponivel, 8);
    adicionaNaLista(lista, &comeco, &disponivel, 9);
    adicionaNaLista(lista, &comeco, &disponivel, 30);
    removerDaLista(lista, &comeco, &disponivel);
    imprimeLista(lista, comeco, disponivel);

    return 1;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
    struct no_ *ant;
    struct no_ *prox;
} no;

no *buscar(no *ptlista, int x)
{
    no *ultimo = ptlista->ant;

    if (ultimo != ptlista && ultimo->chave >= x)
    {
        while (ptlista->prox->chave < x && ptlista->prox != ultimo->prox)
        {
            ptlista = ptlista->prox;
        }
        return ptlista->prox;        
    }
    
    return ptlista;
}

no *inserir(no *ptlista, no *novo_no)
{
    no *pont = buscar(ptlista, novo_no->chave);

    if (pont->chave != novo_no->chave)
    {
        novo_no->prox = pont;
        novo_no->ant = pont->ant;
        pont->ant->prox = novo_no;
        pont->ant = novo_no;
        return NULL;
    }
    
    return pont;
}

no *remover(no *ptlista, int x)
{
    no *pont = buscar(ptlista, x);

    if (pont->chave == x)
    {
        pont->ant->prox = pont->prox;
        pont->prox->ant = pont->ant;
        return pont;
    }
    return NULL;
}

no *alocarNo()
{
    no *retorno = malloc(sizeof(no));
    printf("Informe a chave: ");
    scanf("%d", &retorno->chave);
    printf("Informe o valor: ");
    scanf("%d", &(*retorno).valor);
    retorno->prox = NULL;
    retorno->ant = NULL;
    return retorno;
}

void ler_menu(int *resposta)
{
    printf("\n-----------------------\n");
    printf("escolha uma das opcoes:\n");
    printf("0 - sair\n");
    printf("1 - inserir\n");
    printf("2 - remover\n");
    printf("3 - imprimir crescente\n");
    printf("4 - imprimir decrescente\n");
    scanf("%d", resposta);
    printf("-----------------------\n\n");
}

void desalocar_lista(no *ptlista)
{
    no *proximo = ptlista->prox;
    while (proximo != ptlista)
    {
        no *temp = proximo->prox;
        free(proximo);
        proximo = temp;
    }
    free(ptlista);
}

void inicia_lista(no **ptlista)
{
    *ptlista = malloc(sizeof(no));

    (*(*ptlista)).ant = (*ptlista);
    (*(*ptlista)).prox = (*ptlista);
}

void imprimir_crescente(no *ptlista)
{


    no *proximo = ptlista->prox;
    if (proximo == ptlista)
    {
        printf("\n<lista vazia>");
    }
    else
    {
        while (proximo != ptlista)
        {
            printf("%d:%d", proximo->chave, proximo->valor);
            proximo = proximo->prox;
            if (proximo != ptlista)
                printf(" <-> ");
        }
    }
    printf("\n");

}

void imprimir_decrescente(no *ptlista)
{
    no *anterior = ptlista->ant;
    if (anterior == ptlista)
    {
        printf("<lista vazia!>");
    }
    else
    {
        while (anterior != ptlista)
        {
            printf("%d:%d", anterior->chave, anterior->valor);
            anterior = anterior->ant;
            if (anterior != ptlista)
                printf(" <-> ");
        }
    }
    printf("\n");

}

// // Fila
// void imprimir(no * inicio){
//     if(inicio == NULL){
//         printf("fila vazia");
//         return;
//     }

//     printf("inicio --> ");
//     while(inicio != NULL){
//         printf("%d:%d", inicio->chave, inicio->valor);
//         inicio = inicio->prox;
//         if(inicio != NULL)
//             printf(" -> ");
//         else
//             printf(" <-- fim");
//     }
// }

// // Lista
// void imprimir(no *ptlista)
// {
//     if (ptlista->prox == NULL)
//     {
//         printf("<lista vazia!>");
//         return;
//     }

//     ptlista = ptlista->prox;
//     while (ptlista != NULL)
//     {
//         printf("%d:%d", inicio->chave, inicio->valor);
//         ptlista = ptlista->prox;
//         printf(" -> ");
//         if (ptlista == NULL)
//             printf("NULL");
//     }
// }

// // Pilha
// void imprimir(no *topo)
// {
//     if (topo == NULL)
//     {
//         printf("pilha vazia");
//         return;
//     }

//     printf("topo --> \n");
//     while (topo != NULL)
//     {
//         printf("\t%d:%d", topo->chave, topo->valor);
//         topo = topo->prox;
//         printf("\n | \n");
//     }
//     printf("\tNULL\n");
// }

void main(int argc, char **argv)
{
    no *ptlista;
    inicia_lista(&ptlista);

    int resposta = 1;
    while (resposta != 0)
    {
        ler_menu(&resposta);

        if (resposta == 0)
        {
            // sair
            desalocar_lista(ptlista);
            return;
        }
        else if (resposta == 1)
        {
            // inserir

            no *novo_no = alocarNo();
            if (inserir(ptlista, novo_no) != NULL)
            {
                free(novo_no);
            }
        }
        else if (resposta == 2)
        {
            // remover
            int x;
            printf("\n\t Digite a chave: ");
            scanf("%d", &x);
            no *no_removido = remover(ptlista, x);
            if (no_removido != NULL)
            {
                free(no_removido);
            }
        }
        else if (resposta == 3)
        {
            // imprimir ordem crescente
            imprimir_crescente(ptlista);
        }
        else if (resposta == 4)
        {
            // imprimir ordem decrescente
            imprimir_decrescente(ptlista);
        }
        else
        {
            printf("Opção inválida\n");
        }
    }
}

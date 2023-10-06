#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
    struct no_ *prox;
} no;

no *alocarNo()
{
    no *retorno = malloc(sizeof(no));
    printf("Informe a chave: ");
    scanf("%d", &retorno->chave);
    printf("Informe o valor: ");
    scanf("%d", &(*retorno).valor);
    retorno->prox = NULL;
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
//         printf("%d:%d", ptlista->chave, ptlista->valor);
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

    int resposta = 1;
    while (resposta != 0)
    {
        ler_menu(&resposta);

        if (resposta == 0)
        {
            // sair
            return;
        }
        else if (resposta == 1)
        {
            // inserir

            no *novo_no = alocarNo();
            
        }
        else if (resposta == 2)
        {
            // remover
            int x;
            printf("\n\t Digite a chave: ");
            scanf("%d", &x);

            
        }
        else if (resposta == 3)
        {
            // imprimir ordem crescente
            //imprimir(ptlista);
        }
        else
        {
            printf("Opção inválida\n");
        }
    }
}

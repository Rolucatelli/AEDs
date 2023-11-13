#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 20

int pai(int i){
    return (i-1) / 2;
}

int filhoEsquerda(int i){
    return (2*i) + 1;
}

int filhoDireita(int i){
    return (2*i) + 2;
}

void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

int inserir(int chave, int *heapSize, int arvore[]){

    if (CAPACITY == *heapSize)
    {
        return -1;
    }
    
    (*heapSize)++;
    int i = heapSize -1;
    arvore[i] = chave;

    while (i != 0 && arvore[pai(i)] > arvore[i])
    {
        swap(&arvore[i], &arvore[pai(i)]);
        i = pai(i);
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
    int arvore[CAPACITY];
    int heapSize = 0;

    while (resposta)
    {
        ler_menu(&resposta);

        if (resposta == 0)
        {}
        else if (resposta == 1)
        {
            int valor;
            printf("\n Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            inserir(valor, &heapSize, arvore);
        }
        else if (resposta == 2)
        {

            //remover
        }
        else if (resposta == 3)
        {
            //imprimir
        }
        else
        {

            printf("Opção inválida\n");
        }
    }

    return 0;
}
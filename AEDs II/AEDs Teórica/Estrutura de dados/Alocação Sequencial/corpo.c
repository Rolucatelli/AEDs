#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
} no;

no *alocarNo()
{
    no *retorno = malloc(sizeof(no));
    printf("Informe a chave: ");
    scanf("%d", &retorno->chave);
    printf("Informe o valor: ");
    scanf("%d", &(*retorno).valor);
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

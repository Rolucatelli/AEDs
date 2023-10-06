#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
} no;

int busca(no *L, int n, int x)
{
    L[n].chave = x;
    int i = 0;
    while (L[i].chave != x)
    {
        i++;
    }
    if (i != n)
    {
        return i;
    }
    return -1;
}

int buscaBin(no *L, int n, int x)
{
    int inf = 0, sup = n, meio;
    while (inf < n)
    {
        meio = (inf + sup) / 2;
        if (L[meio].chave == x)
        {
            return meio;
        }
        else
        {
            if (L[meio].chave < x)
            {
                inf = meio + 1;
            }
            else
            {
                sup = meio - 1;
            }
        }
    }
    return -1;
}

int inserir(no *L, int n, int m, no x)
{
    if (n < m)
    {
        if (busca(L, n, x.chave) == -1)
        {
            L[n] = x;
            n++;
            return n - 1;
        }
        return -1;
    }
    return -2;
}

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
            // imprimir(ptlista);
        }
        else
        {
            printf("Opção inválida\n");
        }
    }
}

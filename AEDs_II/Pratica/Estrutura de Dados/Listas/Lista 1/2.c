// Usando somente aritmética de ponteiros, faça um programa que leia
// os valores de uma matriz de 2 por 2. Ao final, exibir na tela os valores lidos na tela.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas = 2;
    int colunas = 2;

    int **p = malloc(2 * sizeof(int *));

    for (int i = 0; i < linhas; i++)
    {
        *(p + i) = malloc(colunas * sizeof(int));
        for (int j = 0; j < colunas; j++)
        {
            printf("\n Insira o valor M[%d][%d]: ", i, j);
            scanf("%d", *(p + i) + j);
        }
    }

    for (int i = 0; i < linhas; i++)
    {
        printf("\n \t( %d  ", *(*(p + i) + 0));
        printf(" %d )", *(*(p + i) + 1));
    }
    printf("\n");
    return 0;
}

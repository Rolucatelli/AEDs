// Usando somente aritmética de ponteiros, faça um programa que some dois vetores
// (de mesmo tamanho e já preenchidos) e armazene o resultado da soma em um terceiro vetor (inicialmente vazio).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v1 = malloc(5 * sizeof(int));
    int *v2 = malloc(5 * sizeof(int));
    int *v3 = malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        *(v1 + i) = i;
        *(v2 + i) = 2 * i;
        *(v3 + i) = (*(v1 + i)) + (*(v2 + i));
        printf(" %d", *(v3 + i));
    }
    printf("\n");

    return 0;
}

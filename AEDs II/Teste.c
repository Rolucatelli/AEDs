#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

struct aluno
{
    char ra[14];
    struct niver
    {
        int dia;
        int mes;
        int ano;
    };
    struct notas
    {
        int aeds;
        int arq;
        int calculo;
    };
    int presenca;
};


int main(int argc, char const *argv[])
{
    struct aluno RodrigoLucatelli = {"2023.1.08.019", {29, 04, 2005}, {9, 8, 7}, 80};
    int n, n1, n2;
    int *a, *p1 = &n1, *p2 = &n2;

    scanf("%d", &n);

    a = (int*)malloc(n * sizeof(int)); // Cria um bloco de memória de tamanho n*4 bytes, vulgo n variáveis int

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", a[i]);
    }
    

    scanf("%d %d", p1, p2);
    troca(p1, p2);
    printf("%d %d\n", n1, n2);

    return 0;
}

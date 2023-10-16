#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
    struct binaria *esq;
    struct binaria *dir;
} no;



int main(int argc, char const *argv[])
{
    no * ptraiz = malloc(sizeof(no));
    ptraiz->esq = NULL;
    ptraiz->dir = NULL;
    return 0;
}

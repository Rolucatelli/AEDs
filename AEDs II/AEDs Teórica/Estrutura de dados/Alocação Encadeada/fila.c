#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
    struct no_ *prox;
} no;

/*
    f: quem tá a mais tempo na fila
    r: quem acabou de chegar na fila
*/
void inserir(no **f, no **r, no *novoNo)
{
    if (*r == NULL)
    {
        *f = *r = novoNo;
    }
    else
    {
        (*r)->prox = novoNo;
        *r = novoNo;
    }
}

no *remover(no **f, no **r)
{
    no *retorno = NULL;
    if (*f != NULL)
    {
        retorno = *f;
        *f = retorno->prox;
        if (*f == NULL)
        {
            *r = *f;
        }
    }
    return retorno;
}

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
    printf("3 - imprimir\n");
    scanf("%d", resposta);
    printf("-----------------------\n\n");
}

void imprimir(no *inicio)
{
    if (inicio == NULL)
    {
        printf("fila vazia");
        return;
    }

    printf("inicio --> ");
    while (inicio != NULL)
    {
        printf("%d:%d", inicio->chave, inicio->valor);
        inicio = inicio->prox;
        if (inicio != NULL)
            printf(" -> ");
        else
            printf(" <-- fim");
    }
}

int main()
{
    no *f = NULL, *r = NULL;
    int resposta = 1;
    while (resposta)
    {
        ler_menu(&resposta);
        if (resposta == 1)
        {
            no *novoNo = alocarNo();
            inserir(&f, &r, novoNo);
        }
        if (resposta == 2)
        {
            no * temp = remover(&f, &r);
            if (temp != NULL)
            {
                printf("\n Chave removida: %d\n", temp->chave);
                printf("\n Valor removido: %d\n", temp->valor);
            }
            else
            {
                printf("\n **fila vazia**");
            }
            
        }
        if (resposta == 3)
        {
            imprimir(f);
        }

        // switch (resposta)
        // {
        // case 1:
        //     /* inserir */
        //     break;
        // case 2:
        //     /* remover */
        //     break;
        // case 3:
        //     /* imprimir */
        //     break;
        // case 4:
        //     /* buscar */
        //     break;
        // default:
        //     break;
        // }
    }

    return 0;
}
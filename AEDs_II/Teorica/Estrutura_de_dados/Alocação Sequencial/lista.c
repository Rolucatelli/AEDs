#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
} no;

int busca(no l[], int x, int m)
{
    l[m].chave = x;
    int i = 0;
    while (l[i].chave != x)
    {
        i++;
    }
    if (i == m)
    {
        return -1;
    }
    return i;
}

int buscaBin(no l[], int x, int m)
{

    int inf = 0, sup = m - 1, meio = (m - 1) / 2;
    while (inf <= sup)
    {
        if (l[meio].chave < x)
        {
            sup = meio - 1;
            meio = (inf + sup) / 2;
        }
        else
        {
            if (l[meio].chave == x)
            {
                return meio;
            }
            else
            {
                inf = meio + 1;
                meio = (inf + sup) / 2;
            }
        }
    }
    return -1;
}

int insereLista(no l[], int *n, int m, no x)
{
    if (*n < (m - 1))
    {
        (*n)++;
        l[*n] = x;
        return 1;
    }
    return -1;
}

no *removeLista(no l[], int *n, int x, int m)
{
    no *retorno = NULL;
    int temp = busca(l, x, m);
    if (temp >= 0)
    {
        retorno = malloc(sizeof(no *));
        *retorno = l[temp];
        for (int i = temp; i < *n; i++)
        {
            l[i] = l[i + 1];
        }
        (*n)--;
    }
    return retorno;
}

void imprimeLista(no l[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("\n Chave: %d", l[i].chave);
        printf("\n Valor: %d\n", l[i].valor);
        printf("===============================");
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
    printf("4 - buscar\n");
    scanf("%d", resposta);
    printf("-----------------------\n\n");
}

int main()
{
    int m;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &m);
    no lista[m + 1];
    // n é o indice do ultimo elemento
    int n = -1;
    int resposta = 1;

    while (resposta)
    {
        ler_menu(&resposta);

        if (resposta == 1)
        {
            no x;
            printf("\n Digite a chave que quer inserir: ");
            scanf("%d", &x.chave);
            printf("\n Digite o valor que quer inserir: ");
            scanf("%d", &x.valor);
            if (insereLista(lista, &n, m, x) == 1)
            {
                printf("\n Elemento inserido na posição %d", n);
            }
            else
            {
                printf("\n Lista cheia!");
            }
        }
        if (resposta == 2)
        {
            int x;
            printf("Digite a chave que quer remover: ");
            scanf("%d", &x);
            no *temp = removeLista(lista, &n, x, m);
            if (temp != NULL)
            {
                printf("\n Chave removida: %d", temp->chave);
                printf("\n Valor removido: %d", temp->valor);
                printf("\n Posição na lista: %d", n);
            }
        }
        if (resposta == 3)
        {
            imprimeLista(lista, n);
        }
        if (resposta == 4 && n >= 0)
        {
            int x;
            printf("Digite a chave que quer buscar: ");
            scanf("%d", &x);
            int temp = buscaBin(lista, x, m);
            if (temp == -1)
            {
                printf("\n Valor não encontrado!");
            }
            else
            {
                printf("\n Chave encontrada: %d", lista[temp].chave);
                printf("\n Valor encontrado: %d", lista[temp].valor);
                printf("\n Posição na lista: %d", temp);
            }
        }
        else
        {
            printf("\n Lista vazia");
        }
    }

    return 0;
}
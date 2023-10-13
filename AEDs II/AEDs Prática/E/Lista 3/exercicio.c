#include <stdio.h>
// reviver
#define TAM 7

void empilhar(char *pilha, int *topo, char valor)
{
    if (*topo >= TAM - 1)
    {
        printf("Pilha cheia!\n");
    }
    else
    {
        *topo = *topo + 1;
        pilha[*topo] = valor;
    }
}

void desempilhar(char *pilha, int *topo)
{
    if (*topo == -1)
    {
        printf("Pilha vazia! Impossível remover.\n");
    }
    else
    {
        printf("Valor desempilhado: %c\n", pilha[*topo]);
        *topo = *topo - 1;
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
    printf("4 - palíndromo\n");
    scanf("%d", resposta);
    printf("-----------------------\n\n");
}

void imprimePilha(char p[], int topo)
{
    printf("\n===============================");
    for (int i = topo; i >= 0; i--)
    {
        printf("\n\t%c", p[i]);
    }
    printf("\n===============================");
}

void palindromo(char p[], int topo)
{
    int i = 0, j = topo;
    while (i < j)
    {
        if (p[i] != p[j])
        {
            printf("\nNão é palíndromo!\n");
            return;
        }
        i++;
        j--;
    }

    printf("\nÉ palíndromo!\n");    
}

int main()
{
    char pilha[TAM];
    int topo = -1;
    int resposta = 1;

    while (resposta)
    {
        ler_menu(&resposta);
        switch (resposta)
        {
        // sair
        case 0:
            break;

        // inserir
        case 1:
            printf("Digite um valor para inserir na pilha: ");
            char valor;
            scanf(" %c", &valor);
            empilhar(pilha, &topo, valor);
            break;

        // remover
        case 2:
            desempilhar(pilha, &topo);
            break;

        // imprimir
        case 3:
            imprimePilha(pilha, topo);
            break;
        // Verificar se é palindromo
        case 4:
            palindromo(pilha, topo);
            break;

        default:
            break;
        }
    }

    return 0;
}

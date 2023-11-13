#include <stdio.h>
#define TAM 8

typedef struct _Pessoa
{
    char nome[20];
    int idade;
} Pessoa;

void mostraFila(Pessoa *fila, int comeco, int fim, int tamanho)
{
    if (tamanho == 0)
    {
        printf("Fila vazia!\n");
    }
    else
    {
        // FILA CIRCULAR
        // COMEÇO → FIM

        //Esse printf é necessário pois, quando há somente um elemento na fila, não entra no while
        printf("Pessoa #%d \t Nome: %s \t Idade: %d\n", comeco, fila[comeco].nome, fila[comeco].idade);
        while (comeco != fim)
        {
            //Alteração na maneira de incrementar o começo para ajustar com o printf acima
            comeco = (comeco == TAM - 1) ? 0 : comeco + 1;
            printf("Pessoa #%d \t Nome: %s \t Idade: %d\n", comeco, fila[comeco].nome, fila[comeco].idade);
        }
    }
}

void insereNaFila(Pessoa *fila, Pessoa pessoa, int *fim, int *tamanho)
{
    if (*tamanho == TAM)
    {
        printf("Fila Cheia! \n"); // Queue
    }
    else
    {
        *fim = (*fim == TAM - 1) ? 0 : *fim + 1;
        fila[*fim] = pessoa;
        *tamanho = *tamanho + 1;
    }
}

void removeDaFila(Pessoa *fila, int *comeco, int *tamanho)
{
    if (*tamanho == 0)
    {
        printf("Fila vazia! \n");
    }
    else
    {
        printf("Pessoa removida: %s\n", fila[*comeco].nome);
        *comeco = (*comeco == TAM - 1) ? 0 : *comeco + 1;
        *tamanho = *tamanho - 1;
    }
}

void lerPessoa(Pessoa *pessoa)
{
    printf("Digite o nome: ");
    scanf("%s", pessoa->nome);
    printf("Digite a idade: ");
    scanf("%d", &pessoa->idade);
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
    Pessoa fila[TAM];
    Pessoa p;
    int comeco = 0;
    int fim = -1;
    int tamanho = 0;
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

            lerPessoa(&p);
            insereNaFila(fila, p, &fim, &tamanho);
            break;

        // remover
        case 2:
            removeDaFila(fila, &comeco, &tamanho);
            break;

        // imprimir
        case 3:
            mostraFila(fila, comeco, fim, tamanho);
            break;

        default:
            break;
        }
    }

    return 0;
}
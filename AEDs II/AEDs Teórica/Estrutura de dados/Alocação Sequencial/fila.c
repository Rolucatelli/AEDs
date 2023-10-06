#include <stdio.h>

typedef struct no_
{
    int chave;
    int valor;
} no;

// função insere(no)
//  insere := -1
//  prov := (r mod M) + 1
//  se prov ≠ f então
//      r := prov
//      F[r] := no
//      insere := r
//          se f = 0 então
//          f := 1

/*  @param fila[]: É a fila
    @param m: É o tamanho máximo da fila
    @param r: É a posição do item que acabou de entrar na fila
    @param f: É a posição do item que está a mais tempo na fila
    @param x: nó que deseja ser inserido
*/
int insereFila(no fila[], int m, int *r, int *f, no x)
{
    // Essa variavel será retornada no final da função
    int retorno = -1;

    int temp = ((*r) + 1) % m; // Indica a próxima posição da fila
    if (temp != *f)
    {
        *r = temp;
        fila[*r] = x;
        retorno = *r;
        if (*f == -1)
        {
            *f = 0;
        }
    }
    return retorno;
}

/*  @param fila[]: É a fila
    @param m: É o tamanho máximo da fila
    @param r: É a posição do item que acabou de entrar na fila
    @param f: É a posição do item que está a mais tempo na fila
*/
no *removeFila(no fila[], int m, int *f, int *r)
{
    no *retorno = NULL;
    if (*f != -1)
    {
        retorno = malloc(sizeof(no));
        (*retorno) = fila[*f];
        if (*f == *r)
        {
            *f = *r = -1;
        }
        else
        {
            *f = ((*f) + 1) % m;
        }
    }
    return retorno;
}

void imprimeFila(no fila[], int f, int r)
{
    for (int i = f; i <= r; i++)
    {
        printf("\n Chave: %d", fila[i].chave);
        printf("\n Valor: %d\n", fila[i].valor);
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
    scanf("%d", resposta);
    printf("-----------------------\n\n");
}

int main()
{
    int m;
    printf("\n Digite o tamanho da fila: ");
    scanf("%d", &m);

    no fila[m];
    int r = -1, f = -1;
    int saida = 1;

    while (saida)
    {
        ler_menu(&saida);

        if (saida == 1)
        {
            no x;
            printf("\n Digite a chave do nó que quer adicionar: ");
            scanf("%d", &x.chave);
            printf("\n Digite o valor do nó que quer adicionar: ");
            scanf("%d", &x.valor);
            if (insereFila(fila, m, &r, &f, x) == -1)
            {
                printf("\n A fila ta cheia");
            }
        }
        if (saida == 2)
        {
            if (f == -1)
            {
                printf("\n *fila vazia*");
            }
            else
            {
                no *temp = removeFila(fila, m, &f, &r);
                printf("\n Chave removida: %d", temp->chave);
                printf("\n Valor removido: %d", temp->valor);
                printf("\n===============================");
            }
        }
        if (saida == 3)
        {
            if (f == -1)
            {
                printf("\n *fila vazia*");
            }
            else
            {
                imprimeFila(fila, f, r);
            }
        }
    }
    return 0;
}
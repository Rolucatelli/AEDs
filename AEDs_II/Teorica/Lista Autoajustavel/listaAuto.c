#include <stdio.h>
#include <stdlib.h>

typedef struct no_
{
    int chave;
    int valor;
    int fq;
    struct no_ *prox;
} no;

void lerMenu(int *opcao)
{
    printf("======================================\n");
    printf("Escolha uma opcao:\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Buscar\n");
    printf("4 - Imprimir\n");
    scanf("%d", opcao);
    printf("======================================\n");
}

no *alocarNo()
{
    no *retorno = malloc(sizeof(no));
    printf("Informe a chave: ");
    scanf("%d", &retorno->chave);
    printf("Informe o valor: ");
    scanf("%d", &(*retorno).valor);
    retorno->prox = NULL;
    retorno->fq = 0;
    return retorno;
}

void buscar(no *ptlista, int x, no **ant, no **pont)
{
    *pont = NULL;
    *ant = ptlista;
    no *ptr = ptlista->prox;

    while (ptr != NULL)
    {
        if (ptr->chave != x)
        {
            *ant = ptr;
            ptr = ptr->prox;
        }else{
            *pont = ptr;
            break;
        }
    }
}

no *inserir(no *ptlista, no *novo_no)
{
    no *ant, *pont;
    buscar(ptlista, novo_no->chave, &ant, &pont);
    if (pont == NULL)
    {
        novo_no->prox = ant->prox;
        ant->prox = novo_no;
        return NULL;
    }
    return pont;
}

no *remover(no *ptlista, int x)
{
    no *ant, *pont;
    buscar(ptlista, x, &ant, &pont);
    if (pont != NULL)
    {
        ant->prox = pont->prox;
        return pont;
    }
    else
    {
        return NULL;
    }
}

void imprimir(no *ptlista)
{
    if (ptlista->prox == NULL)
    {
        printf("<lista vazia!>\n");
        return;
    }

    ptlista = ptlista->prox;
    while (ptlista != NULL)
    {
        printf("\033[0;34m%d\033[0m:\033[0;32m%d\033[0m:\033[0;33m%d\033[0m", ptlista->chave, ptlista->valor, ptlista->fq);
        ptlista = ptlista->prox;
        printf(" -> ");
        if (ptlista == NULL)
            printf("NULL\n");
    }
}

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void moverPraFrente(no *ptlista, no *ptr, no *ant)
{
    ant->prox = ptr->prox;
    ptr->prox = ptlista->prox;
    ptlista->prox = ptr;
}

void transposicao(no *ptr, no *ant, no *ant2)
{
    ant->prox = ptr->prox;
    ptr->prox = ant;
    ant2->prox = ptr;
}

void contadorDeFrequencia(no *ptlista, no *ptr, no *ant)
{
    no *aux = ptlista->prox, *antAux = ptlista;
    while (aux->fq >= ptr->fq && aux != ptr)
    {
        antAux = aux;
        aux = aux->prox;
    }
    if (aux != ptr)
    {
        ant->prox = ptr->prox;
        ptr->prox = aux;
        antAux->prox = ptr;
    }
}

no *buscarAuto(no *ptlista, int x)
{
    no *ptr = ptlista->prox, *ant = ptlista;
    no *ant2 = ptlista;

    while (ptr != NULL)
    {
        if (ptr->chave == x)
        {
            ptr->fq++;
            if (ptlista->prox != ptr)
            {
                // moverPraFrente(ptlista, ptr, ant);
                transposicao(ptr, ant, ant2);
                // contadorDeFrequencia(ptlista, ptr, ant);
            }

            return ptr;
        }
        else
        {
            ant2 = ant;
            ant = ptr;
            ptr = ptr->prox;
        }
    }
    return NULL;
}

int main()
{
    no *ptLista = malloc(sizeof(no));
    ptLista->prox = NULL;

    int opcao = 1;

    while (opcao)
    {
        lerMenu(&opcao);
        switch (opcao)
        {
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            if (inserir(ptLista, alocarNo()) != NULL)
            {
                printf("Já existe um nó com essa chave!\n");
            }
            else
            {
                printf("\033[0;32mInserido com sucesso!\033[0m\n");
            }
            break;
        case 2:
            int x = 0;
            printf("Digite a chave do no que quer remover: ");
            scanf("%d", &x);
            no *temp = remover(ptLista, x);
            if (temp == NULL)
            {
                printf("Nó não encontrado!\n");
            }
            else
            {
                printf("Nó removido!\n");
                printf("Chave: %d Valor: %d Acessos: %d\n", temp->chave, temp->valor, temp->fq);
            }
            break;
        case 3:
            int y = 0;
            printf("Digite a chave do no que deseja buscar: ");
            scanf("%d", &y);
            no *aux = buscarAuto(ptLista, y);
            if (aux == NULL)
            {
                printf("Nó não encontrado!\n");
            }
            else
            {
                printf("Chave: %d Valor: %d Acessos: %d\n", aux->chave, aux->valor, aux->fq);
            }
            break;
        case 4:
            imprimir(ptLista);
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }

    return 0;
}

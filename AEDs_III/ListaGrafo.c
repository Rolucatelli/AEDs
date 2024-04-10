#include <stdio.h>
#include <stdlib.h>

#define VALORINICIAL 0

/**
 * name: Nome do vértice
 * weight: Peso do vértice
 * next: Próximo vértice
 * adjacencies: Vértices adjacentes (arestas)
*/
typedef struct node_
{
    char name;
    int weight;
    struct node_ *next;
    struct node_ *adjacencies;
} node;

void buscar(node *ptlista, char v, node **ant, node **pont)
{
    *pont = NULL;
    *ant = ptlista;
    node *ptr = ptlista->next;

    while (ptr != NULL)
    {
        if (ptr->name == v)
        {
            *pont = ptr;
        }
        ptr = NULL; // break;
    }
}

node *inserir(node *ptlista, node *novo_no)
{
    node *ant, *pont;
    buscar(ptlista, novo_no->name, &ant, &pont);
    if (pont == NULL)
    {
        novo_no->next = ant->next;
        ant->next = novo_no;
        return NULL;
    }
    return pont;
}

node *remover(node *ptlista, int x)
{
    node *ant, *pont;
    buscar(ptlista, x, &ant, &pont);
    if (pont != NULL)
    {
        ant->next = pont->next;
        return pont;
    }
    else
    {
        return NULL;
    }
}

node *alocar_node(char name, int weight)
{
    node *novo_no = (node *)malloc(sizeof(node));
    novo_no->name = name;
    novo_no->weight = weight;
    novo_no->next = NULL;
    return novo_no;
}

void ler_menu(int *resposta)
{
    printf("\n-----------------------\n");
    printf("Escolha uma das opcoes:\n");
    printf("0 - Sair\n");
    printf("1 - Inserir vértice\n");
    printf("2 - Remover vértice\n");
    printf("3 - Imprimir vértice\n");
    printf("4 - Imprimir Grafo\n");
    scanf("%d", resposta);
    printf("-----------------------\n\n");
}

void main()
{
    node **ptlista = (node **)malloc(sizeof(node *));
    int resposta = 0;

    do
    {
        ler_menu(&resposta);
        switch (resposta)
        {
        case 0:
            // Sair
            printf("Saindo...\n");
            break;
        case 1:
            // Inserir
            /**
             * 1.1 - Alocar um novo nó
             * 1.2 - Inserir o nó na lista
             * 1.3 - Se o nó já existir, passar para as adjacências
             * 1.4 - Se o nó não existir, inserir na lista
             * while true para ler as adjacências
            */

            node *novo_no = alocar_node('A', VALORINICIAL);
            inserir(*ptlista, novo_no);

            break;
        case 2:
            // Remover
            break;
        case 3:
            // Imprimir vertice
            break;
        case 4:
            // Imprimir Grafo
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }

    } while (resposta != 0);
}
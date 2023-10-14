// 1. Faça uma alocação dinâmica de matriz

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;

    printf("Digite o número de linhas: ");
    scanf("%d", &n);
    printf("Digite o número de colunas: ");
    scanf("%d", &m);

    // Alocação dinâmica da matriz
    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matriz[i] = (int *)malloc(m * sizeof(int));
    }


    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Linha %d:\n", i + 1);
        for (int j = 0; j < m; j++)
        {
            printf("\tColuna %d: ", j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz:\n");
    for (int i = 0; i < n; i++)
    {
        printf("| ");
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("|\n");
    }
    
    return 0;
}

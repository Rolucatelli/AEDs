// 2. Reescreva o exemplo do maior CDA dos alunos usando realloc. Ao invés de solicitar o número de alunos, o tamanho do vetor deverá ser
//    aumentado automaticamente a cada interação. Caso o usuário digite um número negativo, o sistema deverá calcular o maior CDA.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, cda = 0, maior = 0;
    int *vetor = (int *)malloc(sizeof(int));

    // Um scan inicial para entrar no while
    printf("Digite a média do aluno %d: ", n + 1);
    scanf("%d", &cda);

    while (cda >= 0)
    {
        vetor[n] = cda;
        n++;
        vetor = (int *)realloc(vetor, (n + 1) * sizeof(int));

        if (cda > maior)
        {
            maior = cda;
        }

        printf("Digite a média do aluno %d: ", n + 1);
        scanf("%d", &cda);
    }

    printf("O maior CDA é %d.\n", maior);

    return 0;
}

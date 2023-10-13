// Usando somente aritmética de ponteiros,
// faça uma função que verifique se uma string está contido na outra.

#include <stdio.h>
#include <stdlib.h>

int contido(char *s1, char *s2, int tam1, int tam2)
{
    for (int i = 0; i < tam1; i++)

        if (*(s1 + i) == *s2)
        {
            int j = 1;
            while (j < tam2)
            {

                if (*(s1 + i + j) == *(s2 + j))
                {
                    j++;
                    if (j == tam2)
                        return 1;
                }
                else
                    break;
            }
        }

    return 0;
}

int main()
{
    int tam1, tam2;

    printf("\n\t Digite o tamanho da sua primeira palavra: ");
    scanf("%d", &tam1);

    char *string1 = malloc(tam1 * sizeof(char));

    printf("\n\t Digite sua primeira palavra de %d caracteres: ", tam1);
    scanf("%s", string1);

    printf("\n\t Digite o tamanho da sua segunda palavra: ");
    scanf("%d", &tam2);

    char *string2 = malloc(tam2 * sizeof(char));

    printf("\n\t Digite sua segunda palavra de %d caracteres: ", tam2);
    scanf("%s", string2);

    printf("\n\n\t ");
    if (contido(string1, string2, tam1, tam2))
    {
        printf("A segunda palavra esta contida na primeira!\n");
    }
    else
    {
        printf("A segunda palavra nao esta contida!\n");
    }

    return 0;
}

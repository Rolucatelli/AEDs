// Usando somente aritmética de ponteiros,
// faça uma função que verifique se uma string está contido na outra.

#include <stdio.h>
#include <stdlib.h>

#define TAM1 7
#define TAM2 3

int contido(char *s1, char *s2)
{
    for (int i = 0; i < TAM1; i++)
    {
        for (int j = 0; j < TAM2; j++)
        {
            if (s1[i] == s2[j] && s1[i] == s2[j] && s1[i] == s2[j])
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    char string1[TAM1] = "Rodrigo";
    char string2[TAM2] = "dri";

    if (contido(string1, string2))
    {
        printf("\n\t A segunda string está contida na primeira!\n");
    }
    else
    {
        printf("\n\t A string nao esta contida!\n");
    }

    return 0;
}

/*
+-------------------------------------------------------------+
| UNIFAL – Universidade Federal de Alfenas.                   |
| BACHARELADO EM CIENCIA DA COMPUTACAO.                       |
| Trabalho..: Validacao de arquivos XML                       |
| Disciplina: Algoritmos e Estrutura de Dados II – Pratica    |
| Professor.: Fellipe Rey                                     |
| Aluno(s)..: Rodrigo Luís Gasparino Lucatelli                |
|             José Olavo Monteiro Travassos Pereira da Silva  |
|             João Felipe Martins Santana                     |
| Data......: 15/09/2023                                      |
+-------------------------------------------------------------+
*/


#include <stdio.h>
#include <stdlib.h>

typedef char *string;

int tamString(string texto){
    int i = 0;
    while (texto[i] != "\0")
    {
        i++;
    }
    return i-1;
}

string concatena(string string1, string string2){
    string retorno;
    int tam1 = tamString(string1), tam2 = tamString(string2), i = 0;
    while (i < tam1)
    {
        retorno[i] = string1[i];
        i++;
    }
    int j = 0;
    while (i< tam1+tam2)
    {
        retorno[i] = string2[j];
        j++;
    }
    retorno[i] = "\0";
    return retorno;
}

int main(int argc, char const *argv[])
{
    string s1 = "Olá, ", s2;

    printf("\n Digite seu nome: ");
    // scanf("%s", s2);

    printf("%d", sizeof(s1));

    return 0;
}

/* 
 * File:   main.cpp
 * Autor: Rodrigo Luís Gasparino Lucatelli
 * Matrícula: 2023.1.08.019
 *
 * Created on 29 de maio de 2023, 16:11
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

    char nome[30], sobrenome[30], nomeCompleto[60];
    int i, j;

    i = j = 0;

    nome[0] = 'R';
    nome[1] = 'o';
    nome[2] = 'd';
    nome[3] = 'r';
    nome[4] = 'i';
    nome[5] = 'g';
    nome[6] = 'o';
    nome[7] = ' ';
    nome[8] = 'L';
    nome[9] = 'u';
    nome[10] = 'i';
    nome[11] = 's';
    nome[12] = '\0';

    //printf("\n\t Nome: %s", nome);

    sobrenome[0] = 'G';
    sobrenome[1] = 'a';
    sobrenome[2] = 's';
    sobrenome[3] = 'p';
    sobrenome[4] = 'a';
    sobrenome[5] = 'r';
    sobrenome[6] = 'i';
    sobrenome[7] = 'n';
    sobrenome[8] = 'o';
    sobrenome[9] = ' ';
    sobrenome[10] = 'L';
    sobrenome[11] = 'u';
    sobrenome[12] = 'c';
    sobrenome[13] = 'a';
    sobrenome[14] = 't';
    sobrenome[15] = 'e';
    sobrenome[16] = 'l';
    sobrenome[17] = 'l';
    sobrenome[18] = 'i';
    sobrenome[19] = '\0';

    //printf("\n\t Sobrenome: %s", sobrenome);

    while (nome[j] != '\0') {
        nomeCompleto[i] = nome[j];
        i++;
        j++;
    }
    nomeCompleto[i] = ' ';
    i++;
    j = 0;
    while (sobrenome[j] != '\0') {
        nomeCompleto[i] = sobrenome[j];
        i++;
        j++;
    }
    nomeCompleto[i] = '\0';

    printf("\n\t Nome Completo: %s", nomeCompleto);


    //Exercício 2

    char c1[30], c2[30];

    c1[0] = 'L';
    c1[1] = 'o';
    c1[2] = 'g';
    c1[3] = 'i';
    c1[4] = 'c';
    c1[5] = 'a';
    c1[6] = ' ';
    c1[7] = 'D';
    c1[8] = 'i';
    c1[9] = 'g';
    c1[10] = 'i';
    c1[11] = 't';
    c1[12] = 'a';
    c1[13] = 'l';
    c1[14] = '\0';


    c2[0] = 'L';
    c2[1] = 'o';
    c2[2] = 'g';
    c2[3] = 'i';
    c2[4] = 'c';
    c2[5] = 'a';
    c2[6] = ' ';
    c2[7] = 'D';
    c2[8] = 'i';
    c2[9] = 'g';
    c2[10] = 'i';
    c2[11] = 't';
    c2[12] = 'a';
    c2[13] = 'l';
    c2[14] = '\0';

    i = 0;

    while (c1[i] != '\0' && c2[i] != '\0') {
        if (c1[i] != c2[i] || c1[i + 1] == '\0' && c2[i + 1] != '\0' || c1[i + 1] != '\0' && c2[i + 1] == '\0') {
            printf("\n\t As palavras são diferentes!");
        }
        i++;
    }

    //Exercicio 3: Faça um código para verificar se um nome está contido em um nome completo

    char nome2[30];
    int naoRepete = 1;

    nome2[0] = 'R';
    nome2[1] = 'o';
    nome2[2] = 'd';
    nome2[3] = 'r';
    nome2[4] = 'i';
    nome2[5] = 'g';
    nome2[6] = 'o';
    nome2[7] = ' ';
    nome2[8] = 'L';
    nome2[9] = 'u';
    nome2[10] = 'i';
    nome2[11] = 's';
    nome2[12] = '\0';

    i = 0;

    while (naoRepete) {
        if (nome[i] != nome2[i]) {
            
        }
        i++;

    }


    //Exercicio 4: Faça um código para colocar todas as letras de um nome completo em maíusculo
    //Dica: nome[3] = 'l' - 32



    //Exercicio 5: Faça um código para retirar os acentos de uma variável que armazena o número de CPF em caracteres


    //Exercicio 6: Faça um código para contar o múmero de caracteres de uma string

    return 0;
}


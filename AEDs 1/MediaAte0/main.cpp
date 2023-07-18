/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2023.1.08.019
 *
 * Created on 18 de abril de 2023, 17:06
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    float valor, i, soma, maior, menor;
    i = 1;
    soma = 0;

    printf("\n\t Média de valores\n");
    printf("\n\t Lembrando: se o valor digitado for 0, a média será calculada!!!\n\n");

    printf("\n\t Digite o valor %1.0f: ", i);
    scanf(" %f", &valor);
    while (valor < 0.0) {
        printf("\n\t Valor inválido. Digite novamente o valor %1.0f: ", i);
        scanf(" %f", &valor);
    };

    maior = valor;
    menor = valor;

    while (valor != 0) {

        soma = soma + valor;
        i++;
        printf("\n\t Digite o valor %1.0f: ", i);
        scanf(" %f", &valor);
        while (valor < 0.0) {
            printf("\n\t Valor inválido. Digite novamente o valor %1.0f: ", i);
            scanf(" %f", &valor);
        };
        if (valor > maior) {
            maior = valor;
        };

        if (valor < menor && valor != 0) {
            menor = valor;
        };
    };

    printf("\n\t A média dos valores deu: %f ", soma / (i - 1));
    printf("\n\t O menor valor foi: %f ", menor);
    printf("\n\t O maior valor foi: %f ", maior);

    return 0;
}


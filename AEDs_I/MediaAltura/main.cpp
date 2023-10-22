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

    float altura, soma, pessoas, cont, media;
    cont = 0;
    soma = 0;
    
    printf("\n\t Média de alturas\n");
    
    printf("\n\t Digite quantas pessoas irão fazer a média de alturas? ");
        scanf(" %f", &pessoas);
        while (pessoas <= 0.0) {
            printf("\n\t Valor inválido. Digite novamente quantas pessoas irão fazer a média de alturas: ");
            scanf(" %f", &pessoas);
        };
    
    while(pessoas != cont){
        
        printf("\n\t Digite a altura %1.0f em centímetros: ", cont + 1);
        scanf(" %f", &altura);
        while (altura <= 0.0) {
            printf("\n\t Valor inválido. Digite novamente a altura %1.0f em centímetros: ", cont + 1);
            scanf(" %f", &altura);
        };
        soma = soma + altura;
        cont = cont + 1;
    };
    
    media = soma / pessoas;
    printf("\n\t A média de alturas deu: %f centímetros", media);
    
    return 0;
}


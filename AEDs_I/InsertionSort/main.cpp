/* 
 * File:   main.cpp
 * Author: 2023.1.08.019
 *
 * Created on 19 de junho de 2023, 16:17
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(void) {

    int vetor[100], temp = 0;
    ifstream teclado("entrada.txt");
    if (!teclado.is_open()) {
        cout << "\nErro: Arquivo não encontrado. \n";
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        teclado >> vetor[i];
    }


    for (int i = 1; i < 100; i++) {
        int j = i - 1;
        temp = vetor[i];

        while ((j >= 0) && (vetor[j] > temp)) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = temp;
    }

    /*1.Pegar o numero á esquerda do vetor e colocar no temp
     *2.Começar a comparar esses numeros com o vetor da direita pra esquerda
     *3.mover o numero para a esquerda até o próximo numero ser menor que ele
     *4. 
     */




    for (int i = 0; i < 100; i++) {
        cout << " " << vetor[i];
    }

    return 0;
}


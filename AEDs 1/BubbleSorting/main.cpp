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

    int vetor[100], temp;
    ifstream teclado("entrada.txt");
    if (!teclado.is_open()) {
        cout << "\nErro: Arquivo não encontrado. \n";
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        teclado >> vetor[i];
    }
    int x = 0, y = 0;
    for (int i = 100; i >= 1; i--) {
        for (int j = 0; j < 100; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
    cout << x;
    for (int i = 0; i < 100; i++) {
        cout << " " << vetor[i];
    }

    return 0;
}


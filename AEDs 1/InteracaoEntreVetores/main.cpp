/*
 * File:   main.cpp
 * Author: Rodrigo Luís Gasparino Lucatelli
 *
 * Created on 6 de junho de 2023, 15:56
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(int argc, char **argv) {

    int vet1[10] = {40, 11, 27, 30, 4, 25, 16, 27, 87, 9};
    int vet2[10] = {54, 30, 10, 84, 92, 13, 44, 29, 88, 65};
    int vet3[10];
    int i, valor, intervalom, intervaloM, tmp;

    // Exercício 1

    cout << "\n\nExercício 1:";

    for (i = 0; i < 10; i++) {
        vet3[i] = vet1[i] + vet2[i];
    }

    cout << "\n\t Vetor Ex 1: ";
    for (i = 0; i < 10; i++) {
        if (vet3[i] != 0) {
            cout << vet3[i] << " ";
        }
    }

    // Exercício 2

    cout << "\n\nExercício 2:";

    cout << "\n\t Digite um valor para multiplicar o segundo vetor: ";
    cin >> valor;
    for (i = 0; i < 10; i++) {
        vet3[i] = vet1[i] + (valor * vet2[i]);
    }

    cout << "\n\t Vetor Ex 2: ";
    for (i = 0; i < 10; i++) {
        if (vet3[i] != 0) {
            cout << vet3[i] << " ";
        }
    }

    // Exercício 3

    cout << "\n\nExercício 3:";

    int vet4[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    cout << "\n\t Digite um valor para ser o mínimo do intervalo: ";
    cin >> intervalom;
    cout << "\t Digite um valor para ser o máximo do intervalo: ";
    cin >> intervaloM;

    for (i = 0; i < 10; i++) {
        if (vet1[i] >= intervalom && vet1[i] <= intervaloM) {
            vet4[i] = vet1[i];
        }
    }

    cout << "\n\t Vetor Ex 3: ";

    for (i = 0; i < 10; i++) {
        if (vet4[i] != 0) {
            cout << vet4[i] << " ";
        }
    }

    // Exercício 4

    cout << "\n\nExercício 4:";

    for (i = 0; i < 10; i++) {
        tmp = vet1[i];
        for (int j = i + 1; j < 10; j++) {
            if (vet1[j] == tmp) {
                vet1[j] = 0;
            }
        }
    }

    cout << "\n\t Vetor Ex 4: ";
    for (i = 0; i < 10; i++) {
        if (vet1[i] != 0) {
            cout << vet1[i] << " ";
        }
    }

    // Exercício 5

    cout << "\n\nExercício 5:";

    int vetor1[10] = {34, 78, 65, 14, 29, 51, 10, 02, 46, 43};
    int vetor2[10] = {34, 65, 21, 03, 48, 94, 76, 69, 13, 64};
    int vetor3[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (i = 0; i < 10; i++) {
        vetor3[i] = vetor1[i];
        vetor3[i + 10] = vetor2[i];
    }

    for (i = 0; i < 20; i++) {
        tmp = vetor3[i];
        for (int j = i + 1; j < 20; j++) {
            if (vetor3[j] == tmp) {
                vetor3[j] = 0;
            }
        }
    }

    cout << "\n\t Vetor Ex 5: ";
    for (i = 0; i < 20; i++) {
        if (vetor3[i] != 0) {
            cout << vetor3[i] << " ";
        }
    }

    // Exercício 6

    cout << "\n\nExercício 6:";

    int vetor4[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int k = 0;

    for (i = 0; i < 10; i++) {
        tmp = vetor1[i];
        for (int j = 0; j < 10; j++) {
            if (vetor1[i] == vetor2[j]) {
                vetor4[k] = vetor1[i];
                k++;
            }
        }
    }

    cout << "\n\t Vetor Ex 6: ";
    for (i = 0; i < 20; i++) {
        if (vetor4[i] != 0) {
            cout << vetor4[i] << " ";
        }
    }

    return 0;
}

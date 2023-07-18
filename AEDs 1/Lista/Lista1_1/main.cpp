#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

    float altura, i, im, altm, fmenor170, maior180;
    string sexo;
    ifstream teclado("entrada.txt");
    if (!teclado.is_open()) {
        cout << "\nErro: Arquivo não encontrado. \n";
        return 1;
    }

    i = 0;
    im = 0;
    fmenor170 = 0;
    maior180 = 0;
    teclado >> altura;

    while (altura > 0) {

        teclado >> sexo;

        if (altura > 180) {
            maior180 = maior180 + 1;
        }
        if (sexo == "M") {
            im = im + 1;
            altm = altm + altura;
        }
        if (sexo == "F" && altura < 170) {
            fmenor170 = fmenor170 + 1;
        }

        i = i + 1;
        teclado >> altura;
    }

    cout << "\t A porcentagem de pessoas com altura maior que 1,80 m é: " << (maior180 / i)*100 << "%" << endl;
    cout << "\t A média de altura dos homens é " << altm / im << " cm" << endl;
    cout << "\t A porcentagem de mulheres menores que 1,70 m entre todas as pessoas é: " << (fmenor170 / i)* 100 << "%" << endl;
    return 0;
}


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char **argv) {

    float cN, mV, i, iH, c24;
    string sexo;
    ifstream teclado("entrada.txt");
    if (!teclado.is_open()) {
        cout << "\nErro: Arquivo não encontrado. \n";
        return 1;
    }

    i = iH = c24 = 0;

    teclado >> cN;
    teclado >> sexo;
    teclado >> mV;
    while (sexo != "sair") {
        if (sexo == "masculino") {
            iH++;
        }
        if (mV <= 24) {
            c24++;
        }
        i++;
        teclado >> sexo;
        teclado >> mV;
    }

    cout << "\n\t Porcentagem de crianças mortas no período: " << (i / cN) * 100 << "%" << endl;
    cout << "\t Porcentagem de crianças do sexo masculino mortas no período: " << (iH / i) * 100 << "%" << endl;
    cout << "\t Porcentagem de crianças que viveram 24 meses ou menos no período: " << (c24 / i) * 100 << "%" << endl;

    return 0;
}

 #include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

    float x, y, z, volumeTotal, areaTotal;
    string obj;
    ifstream teclado("cena.txt");
    if (!teclado.is_open()) {
        cout << "\nErro: Arquivo não encontrado. \n";
        return 1;
    }

    cout << "\n\t Calculo da Area Total e do Volume Total de uma cena:" << endl << endl;


    areaTotal = 0;
    volumeTotal = 0;
    teclado >> obj;

    while (obj != "fim") {

        if (obj == "esfera") {

            teclado >> x;
            volumeTotal = volumeTotal + ((4 * M_PI * x * x * x) / 3);
            areaTotal = areaTotal + (4 * M_PI * x * x);
        }

        if (obj == "cilindro") {

            teclado >> x;
            teclado >> y;
            volumeTotal = volumeTotal + (M_PI * x * x * y);
            areaTotal = areaTotal + (2 * M_PI * x * x) + (2 * M_PI * x * y);
        }

        if (obj == "cubo") {

            teclado >> x;
            volumeTotal = volumeTotal + (x * x * x);
            areaTotal = areaTotal + (6 * x * x);
        }

        if (obj == "piramide_de_base_quadrada") {

            teclado >> x;
            teclado >> y;
            volumeTotal = volumeTotal + ((x * x * y) / 3);
            areaTotal = areaTotal + ((x * x) + (2 * x * y));
        }

        teclado >> obj;
    }

    cout << "\t O Volume Total da cena foi: " << volumeTotal << endl;
    cout << "\t A Area Total da cena foi: " << areaTotal << endl;


    return 0;
}


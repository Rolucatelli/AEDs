#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char **argv)
{

    float x1, x2, y1, y2, distancia;
    ifstream teclado("entrada.txt");
    if (!teclado.is_open())
    {
        cout << "\nErro: Arquivo não encontrado. \n";
        return 1;
    }

    printf("\n\t GPS\n");
    printf("\n\t Lembrando: se os valores digitados forem 0, a distância será calculada!!!\n\n");

    teclado >> x1;
    teclado >> y1;
    teclado >> x2;
    teclado >> y2;

    while (x2 != 0 && y2 != 0)
    {

        distancia = distancia + sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
        x1 = x2;
        y1 = y2;
        teclado >> x2;
        teclado >> y2;
        cout << distancia << endl;
    }

    cout << "\tA distância entre as cordenadas é: " << distancia;
    return 0;
}

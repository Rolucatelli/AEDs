#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char **argv) {

    float mI, mF;
    int h, m, s;

    h = m = s = 0;

    cout << "\n\t Insira a massa inicial (em gramas): ";
    cin >> mF;
    mI = mF;
    while (mF >= 0.5) {
        mF = mF / 2;
        s += 50;
        if (s > 60) {
            s -= 60;
            m++;
        }
        if (m > 60) {
            m -= 60;
            h++;
        }
    }

    cout << "\n\t Massa inicial: " << mI << endl;
    cout << "\t Massa final: " << mF << endl;
    cout << "\t Tempo percorrido: " << h << "h " << m << "m " << s << "s";
    return 0;
}

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

    float x, f, g, h;

    x = 1;
    f = g = h = 0;

    while (x <= 10) {
        h = (x * x) - 16;
        if (h >= 0) {
            f = h;
        } else {
            f = 1;
        }
        if (f == 0) {
            g = (x * x) + 16;
        }
        if (f > 0) {
            g = 0;
        }


        cout << "x: " << x << endl;
        cout << "y: " << f + g << endl;
        x = x + 1;
    }


    return 0;
}


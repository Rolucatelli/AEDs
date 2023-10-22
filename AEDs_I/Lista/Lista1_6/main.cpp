#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

    float anos, a, b;
    
    a = 90000000;  // 90 milhoes
    b = 200000000; //200 milhoes
    anos = 0;
    while (a<=b) {
        a = a + (a*0.03);
        b = b + (b*0.015);
        anos++;
    }
    
    cout << "\n\t Anos necessários para A superar B: " << anos;

    return 0;
}

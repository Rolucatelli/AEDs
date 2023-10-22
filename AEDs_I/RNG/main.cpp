/* 
 * File:   main.cpp
 * Author: 2023.1.08.019
 *
 * Created on 20 de junho de 2023, 17:10
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int i, n, m, vetor[99999];
    ofstream saida("saida.txt");
    srand(time(NULL));

    cin >> n;
    cin >> m;

    for (i = 0; i < n; i++) {
        int rn = rand() % m;
        vetor[i] = rn;
        saida << " " << rn;
    }




    return 0;
}


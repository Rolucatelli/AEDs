#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

    float lucroP, lucroM, lucroG, lucroT, compraT, vendaT, precoC, precoV, lucro;
    string merc;
    ifstream teclado("entrada.txt");
    if (!teclado.is_open()) {
        cout << "\nErro: Arquivo não encontrado. \n";
        return 1;
    }

    cout << "\n\tExercício 5 da lista" << endl;
    
    //Inicialização de Variáveis
    lucroT = compraT = vendaT = lucroP = lucroM = lucroG = 0;

    //Leitura do arquivo
    teclado >> merc;
    teclado >> precoC;
    teclado >> precoV;

    while (merc != "fim") {
        
        //Calculo do porcentual de lucro
        lucro = precoV / precoC;

        if (lucro < 1.1) {
            lucroP++;
        } else if (lucro <= 1.2 && lucro >= 1.1) {
            lucroM++;
        } else {
            lucroG++;
        }

        //Calculando o total
        lucroT += precoV - precoC;
        compraT += precoC;
        vendaT += precoV;

        //Leitura dos próximos valores
        teclado >> merc;
        teclado >> precoC;
        teclado >> precoV;


    }

    cout << "\tValor total de compra das mercadorias: " << compraT << endl;
    cout << "\tValor total de venda das mercadorias: " << vendaT << endl;
    cout << "\tValor total do lucro das mercadorias: " << lucroT << endl << endl;

    cout << "\tQuantidade de mercadorias que proporcionam lucro menor que 10%: " << lucroP << endl;
    cout << "\tQuantidade de mercadorias que proporcionam lucro entre 10% e 20%: " << lucroM << endl;
    cout << "\tQuantidade de mercadorias que proporcionam lucro maior que 20%: " << lucroG << endl;
    return 0;
}


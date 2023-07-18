#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

    float pamax, pamin, idade, i, alvo;
    string tipo, rh, quit;
    ifstream teclado("entrada.txt");
    if (!teclado.is_open()) {
        cout << "\nErro: Arquivo não encontrado. \n";
        return 1;
    }

    cout << "\n\t Pesquisa do Exercício 2 da lista" << endl;
    cout << "\t Lembre-se, se o tipo sanguíneo da pessoa for P, o resultado será mostrado" << endl << endl;

    tipo = "S";
    alvo = 0;
    i = 0;

    while (tipo != "P") {

        
        teclado >> tipo;
        teclado >> rh;
        teclado >> pamax;
        teclado >> pamin;
        teclado >> idade;


        if (tipo != "O" && tipo != "A" && tipo != "B" && tipo != "AB" && tipo != "P") {
            tipo = "P";
            cout << "\t ERRO: foi detectado um tipo sanguíneo incorreto, o programa será abortado" << endl;
            cout << "\t Aperte qualquer tecla para continuar: ";
            cin >> quit;
        }
        if (rh != "-" && rh != "+") {
            tipo = "P";
            cout << "\t ERRO: foi detectado um fator RH incorreto, o programa será abortado" << endl;
            cout << "\t Aperte qualquer tecla para continuar: ";
            cin >> quit;
        }
        if (pamax < 7 || pamax > 25) {
            tipo = "P";
            cout << "\t ERRO: foi detectado uma pressão arterial máxima incorreta, o programa será abortado" << endl;
            cout << "\t Aperte qualquer tecla para continuar: ";
            cin >> quit;
        }
        if (pamin < 2 || pamin > 20) {
            tipo = "P";
            cout << "\t ERRO: foi detectado uma pressão arterial mínima incorreta, o programa será abortado" << endl;
            cout << "\t Aperte qualquer tecla para continuar: ";
            cin >> quit;
        }
        if (idade < 18 || idade > 130) {
            tipo = "P";
            cout << "\t ERRO: foi detectado uma idade incorreta, o programa será abortado" << endl;
            cout << "\t Aperte qualquer tecla para continuar: ";
            cin >> quit;
        }

        if (pamax > 14 || pamin > 10) {
            i = i + 1;
            if (rh == "-") {
                if (tipo == "A" || tipo == "B") {
                    alvo = alvo + 1;
                }
            }
        }


    }
  
    cout << "\t A porcentagem de pessoas com sangue A- ou B- ,dentre as pessoas que possuem pressão alta, é de ";
    cout << (alvo / i)*100 << "%" << endl;

    return 0;
}


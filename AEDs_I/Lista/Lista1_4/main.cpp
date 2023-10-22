#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

    float m, n, x, y, maior, xmax, ymax;

    //Lendo valores
    cout << "\n\t Exercicio 4 da lista";
    cout << "\n\t Digite o valor de m: ";
    cin >> m;
    cout << "\n\t Digite o valor de n: ";
    cin >> n;
    
    //Inicialização de variáveis
    x = y = 1;
    xmax = ymax = 0;
    maior = (x * y)-((x * x) + y);
    
    //Começo das repetições
    while (x < m) {
        
        //Verificando todos os valores de y para um valor de x
        while (y < n) {
            if ((x * y)-((x * x) + y) > maior) {
                maior = (x * y)-((x * x) + y);
                xmax = x;
                ymax = y;
            }
            y++;
        }
        
        
        y = 1;
        if ((x * y)-((x * x) + y) > maior) {
            maior = (x * y)-((x * x) + y);
            xmax = x;
            ymax = y;
        }
        //Aumentando o x para testar outras combinações
        x++;
    }
    
    //Imprimindo restultados
    cout << "\n\t O maior valor da expressao: "<< maior << endl;
    cout <<"\t O valor de x da tal expressao: " <<xmax << endl << "\t O valor de y da tal expressao: "<< ymax << endl;
    

    return 0;
}
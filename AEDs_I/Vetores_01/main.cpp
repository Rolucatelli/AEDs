
/* 
 * File:   main.cpp
 * Autor: Rodrigo Luís Gasparino Lucatelli
 * Matrícula: 2023.1.08.019
 *
 * Created on 29 de maio de 2023, 16:11
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int notas[10] = {40, 11, 27, 30, 4, 25, 16, 27, 87, 9};
    float media, temp, maior, menor, valor;
    int i, iMaior, iMenor, achouValor, iValor;

    media = achouValor = iValor = 0;
    menor = notas[0];
    maior = notas[0];
    for (i = 0; i < 10; i++) {
        media += notas[i];
    }

    media = media / i;
    cout << "\n\n\t A média das notas é: " << media << endl;
    cout << "\n\t Valores acima da média: ";
    for (i = 0; i < 10; i++) {
        if (notas[i] > media) {
            cout << "\n\t O " << i + 1 << "º Valor é: " << notas[i] << endl;
        }
    }

    for (i = 0; i < 5; i++) {
        temp = notas[i];
        notas[i] = notas[9 - i];
        notas[9 - i] = temp;
    }

    //Exercício 1 do outro dia:

    for (i = 0; i < 10; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
            iMaior = i;
        }
        if (notas[i] < menor) {
            menor = notas[i];
            iMenor = i;
        }
    }
    cout << "\n\t O maior número é " << maior << " e ele é o " << iMaior << "º valor";
    cout << "\n\t O menor número é " << menor << " e ele é o " << iMenor << "º valor";

    //Exercício 2 da segunda aula

    cout << "\n\n\t Digite um valor que queira buscar no vetor: ";
    cin >> valor;

    for (i = 0; i < 10; i++) {
        if (notas[i] == valor) {
            achouValor = 1;
            cout << "\n\t " << i + 1 << "º posição";
        }
    }
    if (!achouValor) {
        cout << "\n\t Não foi encontrado o valor digitado";
    }

    //Exercício 3 da segunda aula

    cout << "\n\n\n\t Digite um valor para saber quantas vezes ele aparece no vetor: ";
    cin >> valor;
    for (i = 0; i < 10; i++) {
        if (notas[i] == valor) {
            iValor++;
        }
    }
    if (iValor == 0) {
        cout << "\n\t Esse valor não aparece no vetor";
    } else {
        cout << "\n\t Esse valor aparece " << iValor << " vezes";
    }


    //Exercício 4 da segunda aula

    for (i = 0; i < 10; i++) {
        if (notas[i] % 2 != 0) {
            notas[i] = 0;
        } else {
            notas[i] = notas[i] * 2;
        }
    }


    for (i = 0; i < 10; i++) cout << "\n\t " << notas[i];

    //Exercício 5

    int numeros[10] = {40, 11, 27, 30, 4, 25, 16, 27, 87, 9};

    cout << "\n\n\n\t Digite um valor para incrementar ao vetor: ";
    cin >> valor;

    for (i = 0; i < 10; i++) {
        numeros[i] += valor;
        if (numeros[i] > 255) {
            numeros[i] = 255;
        } else if (numeros[i] < 0) {
            numeros[i] = 0;
        }
    }
    
    for (i = 0; i < 10; i++) cout << "\n\t " << numeros[i];

    return 0;
}


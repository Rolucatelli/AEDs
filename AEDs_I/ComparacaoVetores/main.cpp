/* 
 * Arquivo:   main.cpp
 * 
 * Autor: Rodrigo Luís Gasparino Lucatelli
 * Matrícula: 2023.1.08.019
 * Autor: José Olavo Monteiro Travassos Pereira da Silva
 * Matrícula: 2023.1.08.009
 *
 * Created on 20 de junho de 2023, 17:10
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

//Declarando uma variável que será usada tanto nas funções quanto fora delas
long int mudanca;

void bubbleSort(int vetor[], int tamanho) {
    int tmp;
    mudanca = 0;
    for (int i = tamanho - 1; i >= 1; i--)
        for (int j = 0; j < i; j++) {
            mudanca += 2;
            if (vetor[j] > vetor[j + 1]) {
                tmp = vetor[j];
                mudanca++;
                vetor[j] = vetor[j + 1];
                mudanca += 2;
                vetor[j + 1] = tmp;
                mudanca++;
            }

        }
}

void selectionSort(int vetor[], int tamanho) {
    int min, tmp;
    mudanca = 0;
    for (int i = 0; i < (tamanho - 1); i++) {
        min = i;
        for (int j = (i + 1); j < tamanho; j++) {
            mudanca += 2;
            if (vetor[j] < vetor[min])
                min = j;
        }
        if (i != min) {
            tmp = vetor[i];
            mudanca++;
            vetor[i] = vetor[min];
            mudanca++;
            vetor[min] = tmp;
            mudanca++;
        }
    }
}

void insertionSort(int vetor[], int tamanho) {
    int j, escolhido;
    mudanca = 0;
    for (int i = 1; i < tamanho; i++) {
        mudanca++;
        escolhido = vetor[i];
        j = i - 1;
        while ((j >= 0) && (escolhido < vetor[j])) {
            mudanca += 2;
            vetor[j + 1] = vetor[j];
            j--;
        }
        mudanca++;
        vetor[j + 1] = escolhido;
    }

}

void imprimeVetor(int vetor[], int tamanho) {
    cout << "\t";
    for (int i = 0; i < tamanho; i++)
        cout << " " << vetor[i];
    cout << endl;
}

int main(int argc, char** argv) {

    //Declarando variáveis
    int tamVetor, aleatoriedade, seletor;
    ofstream saida("saida.txt");

    //Lendo o tamanho dos vetores
    cout << "\n\t Digite o tamanho do vetor (até 1000): ";
    cin >> tamVetor;
    while (tamVetor > 1000 || tamVetor < 1) {
        cout << "O número digitado deve ser entre 1 e 1000: ";
        cin >> tamVetor;
    }

    //Declarando os vetores
    int crescente[tamVetor], decrescente[tamVetor], aleatorio[tamVetor];

    //Gerando a seed aleatória
    srand(time(NULL));

    //Lendo a aleatoriedade
    cout << "\n\t Digite o maior número aleatório possível: ";
    cin >> aleatoriedade;
    while (aleatoriedade <= tamVetor) {
        cout << "\n\t O Número tem que ser maior que o tamanho do vetor! Digite novamente: ";
        cin >> aleatoriedade;
    }

    //Gerando o vetor aleatório
    for (int i = 0; i < tamVetor; i++) {
        int random = 0;
        //Gerando 5 números e calculando a média entre eles
        for (int j = 0; j < 5; j++)
            random += rand() % aleatoriedade;
        aleatorio[i] = random / 5;
        random = 0;
        //Conferindo se 
        if (aleatorio[i] == 0)
            i--;
        for (int j = 0; j < i; j++)
            if (aleatorio[i] == aleatorio[j])
                i--;
    }

    //Igualando os vetores e escrevendo no arquivo
    for (int i = 0; i < tamVetor; i++) {
        saida << aleatorio[i] << endl;
        crescente[i] = aleatorio[i];
        decrescente[i] = aleatorio[i];
    }

    //Organizando um vetor na ordem crescente
    for (int i = tamVetor - 1; i >= 1; i--) {
        int tmp;
        for (int j = 0; j < i; j++)
            if (crescente[j] > crescente[j + 1]) {
                tmp = crescente[j];
                crescente[j] = crescente[j + 1];
                crescente[j + 1] = tmp;
            }

    }

    //Organizando um vetor na ordem decrescente
    for (int i = tamVetor - 1; i >= 1; i--) {
        int tmp;
        for (int j = 0; j < i; j++)
            if (decrescente[j] < decrescente[j + 1]) {
                tmp = decrescente[j];
                decrescente[j] = decrescente[j + 1];
                decrescente[j + 1] = tmp;
            }

    }

    //Escolhendo o método de organização
    cout << "\n\t Que método de utilização deseja utilizar?" << endl;
    cout << "\n\t Digite 1 para o BubbleSorting, 2 para o Selection e 3 para o Insertion: ";
    cin >> seletor;
    while (seletor != 1 && seletor != 2 && seletor != 3) {
        cout << "\n\t Você digitou um número errado!" << endl;
        cout << "\n\t Digite 1 para o BubbleSorting, 2 para o Selection e 3 para o Insertion: ";
        cin >> seletor;
    }

    //Imprimindo os Vetores
    cout << "\n\t Vetor na ordem crescente: " << endl;
    imprimeVetor(crescente, tamVetor);
    cout << "\n\t Vetor na ordem aleatória: " << endl;
    imprimeVetor(aleatorio, tamVetor);
    cout << "\n\t Vetor na ordem decrescente: " << endl;
    imprimeVetor(decrescente, tamVetor);


    if (seletor == 1) {
        bubbleSort(crescente, tamVetor);
        cout << "\n\n\t Operações realizadas pelo vetor na ordem crescente organizado por Bubble Sorting: " << mudanca << endl;

        bubbleSort(aleatorio, tamVetor);
        cout << "\n\n\t Operações realizadas pelo vetor na ordem aleatório organizado por Bubble Sorting: " << mudanca << endl;

        bubbleSort(decrescente, tamVetor);
        cout << "\n\n\t Operações realizadas pelo vetor na ordem decrescente organizado por Bubble Sorting: " << mudanca << endl;
    }
    if (seletor == 2) {
        selectionSort(crescente, tamVetor);
        cout << "\n\n\t Operações realizadas pelo vetor na ordem crescente organizado por Selection Sorting: " << mudanca << endl;

        selectionSort(aleatorio, tamVetor);
        cout << "\n\n\t Operações realizadas pelo vetor na ordem aleatório organizado por Selection Sorting: " << mudanca << endl;

        selectionSort(decrescente, tamVetor);
        cout << "\n\n\t Operações realizadas pelo vetor na ordem decrescente organizado por Selection Sorting: " << mudanca << endl;
    }
    if (seletor == 3) {
        insertionSort(crescente, tamVetor);
        cout << "\n\n\t Operações realizadas pelo vetor na ordem crescente organizado por Insertion Sorting: " << mudanca << endl;

        insertionSort(aleatorio, tamVetor);
        cout << "\n\n\t Operações realizadas pelo vetor na ordem aleatório organizado por Insertion Sorting: " << mudanca << endl;

        insertionSort(decrescente, tamVetor);
        cout << "\n\n\t Operações realizadas pelo vetor na ordem decrescente organizado por Insertion Sorting: " << mudanca << endl;
    }

    return 0;
}


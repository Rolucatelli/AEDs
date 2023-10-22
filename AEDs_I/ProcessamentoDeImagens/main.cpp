/*
 * File:   main.cpp
 * Autor: Rodrigo Luís Gasparino Lucatelli
 * Matrícula: 2023.1.08.019
 *
 * Created on 10 de julho de 2023, 15:47
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
typedef int tImagem[1000][1000];
string erro;

/**
 * Carrega a imagem
 * @param nome: nome do arquivo
 * @param img: matriz que representa a imagem
 * @param lin: linhas da matriz
 * @param col: colunas da matriz
 * @param tons: valor máximo de tonalização de pixel;
 * @return 
 */
int carregaPGM(string nome, tImagem img, int *lin, int *col, int *tons) {

    string tipo;
    ifstream arquivo(nome);
    if (!arquivo.is_open()) {
        erro = "Erro: Arquivo não encontrado.";
        return 1;
    }

    arquivo >> tipo;
    if (tipo != "P2") {
        erro = "Erro: Arquivo não está no formato pgm.";
        return 2;
    }

    arquivo >> *col >> *lin >> *tons;
    for (int i = 0; i < *lin; i++) {
        for (int j = 0; j < *col; j++) {
            arquivo >> img[i][j];
        }
    }
    arquivo.close();
    return 0;
}

int salvaPGM(string nome, tImagem img, int lin, int col, int tons) {
    ofstream arquivo(nome);
    if (!arquivo.is_open()) {
        erro = "Erro: Arquivo não encontrado.";
        return 1;
    }

    arquivo << "P2" << endl << col << " " << lin << endl << tons << endl;
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            arquivo << img[i][j] << " ";
        }
        arquivo << endl;
    }

    arquivo.close();
    return 0;
}

void brilho(tImagem entrada, tImagem saida, int lin, int col, int tons, int clarear) {

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            saida[i][j] = entrada[i][j] + clarear;
            if (entrada[i][j] < 0) {
                saida[i][j] = 0;
            } else if (entrada[i][j] > tons) {
                saida[i][j] = tons;
            }
        }
    }

    return;
}

void binarizar(tImagem entrada, tImagem saida, int lin, int col, int tons, int numero) {

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (entrada[i][j] < numero)
                saida[i][j] = 0;
            else if (entrada[i][j] >= numero)
                saida[i][j] = tons;
        }
    }

    return;
}

void girarEsquerda(tImagem entrada, tImagem saida, int lin, int col, int tons) {

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            saida[j][i] = entrada[i][col - 1 - j];
        }
    }
    return;
}

void girarDireita(tImagem entrada, tImagem saida, int lin, int col, int tons) {



    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            saida[j][i] = entrada[lin - 1 - i][j];
        }
    }
    return;
}

void iconizar(tImagem entrada, tImagem saida, int lin, int col, int tons) {

    int temp = 0;

    for (int i = 0; i < lin / 64; i++) {
        for (int j = 0; j < col / 64; j++) {
            temp += entrada[i][j];
            saida[i][j] = temp / 64;
        }
    }
    return;
}

int main(void) {
    tImagem imgEntrada, imgSaida;
    string arqEntrada, arqSaida, filtro;
    int coluna, linha, cinza;

    cout << " Entre com o nome da imagem de entrada: ";
    cin >> arqEntrada;
    arqEntrada = arqEntrada + ".pgm";
    if (carregaPGM(arqEntrada, imgEntrada, &linha, &coluna, &cinza) != 0) {
        cout << "\n" + erro + "\n";
        return 1;
    }

    cout << "\n Escolha o filtro para aplicar à imagem: " << endl;
    cout << " Esclarecer/escurecer" << endl;
    cout << " Binarizar" << endl;
    cout << " Rotacionar" << endl;
    cout << " Iconizar" << endl;
    cout << " Passa-baixa" << endl << endl << " ";

    cin >> filtro;
    if (filtro == "esclarecer" || filtro == "escurecer" || filtro == "Esclarecer/escurecer") {
        int esclarecer;
        cout << "\n Digite o quanto quer esclarecer a imagem, lembrando, se o número for negativo, irá escurecer a imagem: ";
        cin >> esclarecer;
        brilho(imgEntrada, imgSaida, linha, coluna, cinza, esclarecer);
    } else if (filtro == "binarizar") {
        int limiar;
        cout << "\n Digite o valor para binarizar a imagem: ";
        cin >> limiar;
        binarizar(imgEntrada, imgSaida, linha, coluna, cinza, limiar);
    } else if (filtro == "rotacionar") {
        string orientacao;
        cout << "\n Para qual lado deseja rotacionar? Esquerda ou direita? ";
        cin >> orientacao;
        if (orientacao == "esquerda") {
            girarEsquerda(imgEntrada, imgSaida, linha, coluna, cinza);
            int temp = linha;
            linha = coluna;
            coluna = temp;
        } else if (orientacao == "direita") {
            girarDireita(imgEntrada, imgSaida, linha, coluna, cinza);
            int temp = linha;
            linha = coluna;
            coluna = temp;
        }
    } else if (filtro == "iconizar") {
        iconizar(imgEntrada, imgSaida, linha, coluna, cinza);
    } else if (filtro == "passa-baixa") {

    }

    cout << "\n Entre com o nome da imagem de saída: ";
    cin >> arqSaida;
    arqSaida = arqSaida + ".pgm";
    if (salvaPGM(arqSaida, imgSaida, linha, coluna, cinza) != 0) {
        cout << "\n" + erro + "\n";
        return 1;
    }

    return 0;
}


/* Disciplina: AEDs I
 * Professor: Paulo Alexandre Bressan
 * Atividade: 01 Estatística em Base de Dados de Veículos
 * 
 * Arquivo:   main.cpp
 * Autor 1: Rodrigo Luís Gasparino Lucatelli
 * Matrícula: 2023.1.08.019
 * 
 * Autor 2: José Olavo Monteiro Travassos Pereira da Silva
 * Matrícula: 2023.1.08.009
 *
 */

#include <iostream> //Essa biblioteca permite ler/escrever coisas a partir do console
#include <fstream>  //Essa biblioteca permite ler dados a partir de um arquivo
#include <math.h>   //Essa biblioteca têm uma função que facilita o calculo de potências

using namespace std;

int main(int argc, char** argv) {

    //Nesse código estou considerando o valor do juros mensal do financiamento como 3,96% e o valor do seguro como 6,5% do veículo
    //Esse código está coletando dados a partir de um arquivo chamado entrada.txt

    //Declaração das variáveis
    float valorBarato, valorCaro, kmTotal, km, valor, i;
    int autoHidro, hatch, suv, pickUp, sedan, passeio, van, tipoD, ano, portas, iVelho;
    string placaBarato, placaCaro, modelo, marca, tipo, combustivel, cambio, direcao, cor, motor, placa;

    //Permitindo o código a ler um arquivo
    ifstream teclado("entrada.txt");
    if (!teclado.is_open()) {
        cout << "\nErro: Arquivo não encontrado. \n";
        return 1;
    }

    //Indicando o programa
    cout << endl << "\tAnálise de veículos:" << endl << endl;

    //Inicializando as variáveis
    hatch = suv = pickUp = sedan = passeio = van = tipoD = i = kmTotal = autoHidro = iVelho = 0;
    valorBarato = 999999999; //Inicializei essa variável com um valor muito alto para, praticamente, qualquer valor ser capaz de substituí-la futuramente
    valorCaro = -1; //Inicializei essa variável com um valor negativo para qualquer valor ser capaz de substituí-la futuramente

    //Fazendo uma primeira leitura para entrar na função while
    teclado >> modelo;

    while (modelo != "FIM") {

        //Leitura do resto do veículo
        teclado >> marca;       //Essa variável não é utilizada pra nada além de auxiliar a leitura dos outros valores, porém, caso esse código tenha que ser modificado para atender outras funções, ela já está com seu valor
        teclado >> tipo;
        teclado >> ano;
        teclado >> km;
        teclado >> motor;
        teclado >> combustivel;
        teclado >> cambio;
        teclado >> direcao;
        teclado >> cor;         //Essa variável não é utilizada pra nada além de auxiliar a leitura dos outros valores, porém, caso esse código tenha que ser modificado para atender outras funções, ela já está com seu valor
        teclado >> portas;      //Essa variável não é utilizada pra nada além de auxiliar a leitura dos outros valores, porém, caso esse código tenha que ser modificado para atender outras funções, ela já está com seu valor
        teclado >> placa;
        teclado >> valor;

        //Verificando e contando quantos veículos têm de cada tipo
        if (tipo == "Hatch") hatch++;
        else if (tipo == "SUV") suv++;
        else if (tipo == "Pick-up") pickUp++;
        else if (tipo == "Sedã" || tipo == "Sedan") sedan++;
        else if (tipo == "Passeio") passeio++;
        else if (tipo == "Van") van++;
        else tipoD++;

        //Contando os veículos que têm câmbio automático e direção hidráulica
        if (cambio == "Automático" && direcao == "Hidráulica") autoHidro++;

        //Encontrando o valor do veículo mais barato de motor 1.0
        if (motor == "1.0" && valor < valorBarato) {
            valorBarato = valor;
            placaBarato = placa;
        }

        //Encontrando o veículo mais caro que tem direção hidráulica e combustível flex
        if (direcao == "Hidráulica" && combustivel == "Flex" && valor > valorCaro) {
            valorCaro = valor;
            placaCaro = placa;
        }

        //Contando a quantos quilômetros os veículos com 5 anos ou mais rodaram
        if (ano <= 2018) {
            kmTotal += km;
            iVelho++;
        }

        //A variável i está contando a quantidade total de veículos
        i++;
        
        //Caso essa última leitura seja FIM, o código não lê outras coisas além da palavra FIM
        teclado >> modelo;
    }

    
    //Imprimindo o primeiro tópico
    cout << "\tPorcentagem de veículos de tipo Hatch: " << (hatch / i)*100 << "%" << endl;
    cout << "\tPorcentagem de veículos de tipo SUV: " << (suv / i)*100 << "%" << endl;
    cout << "\tPorcentagem de veículos de tipo Pick-Up: " << (pickUp / i)*100 << "%" << endl;
    cout << "\tPorcentagem de veículos de tipo Sedan: " << (sedan / i)*100 << "%" << endl;
    cout << "\tPorcentagem de veículos de tipo Passeio: " << (passeio / i)*100 << "%" << endl;
    cout << "\tPorcentagem de veículos de tipo Van: " << (van / i)*100 << "%" << endl;
    cout << "\tPorcentagem de veículos de tipo não reconhecido: " << (tipoD / i)*100 << "%" << endl << endl;
    
    //Imprimindo o segunto tópico
    cout << "\tPorcentagem de veículos com câmbio automático e direção hidráulica: " << (autoHidro / i)*100 << "%" << endl << endl;
    
    //Imprimindo o terceiro tópico
    cout << "\tPlaca do veículo mais barato com motor 1.0: " << placaBarato << endl;
    cout << "\tPreço do veículo mais barato com motor 1.0: " << valorBarato << endl;
    cout << "\tValor total do financiamento: " << (valorBarato * pow(1.0396, 48)) << endl;  //Nessa linha, o calculo do valor total do financiamento será feito
    cout << "\tParcela do financiamento: " << (valorBarato * pow(1.0396, 48)) / 48 << endl << endl;  //Nessa linha, o calculo do valor de uma parcela do financiamento será feito
    
    //Imprimindo o quarto tópico
    cout << "\tPlaca do veículo mais caro com direção hidráulica e combustível flex: " << placaCaro << endl;
    cout << "\tPreço do veículo mais caro com direção hidráulica e combustível flex: " << valorCaro << endl;
    cout << "\tValor do seguro estimado: " << (valorCaro * 0.065) << endl << endl;  //Nessa linha, o calculo do valor do seguro será feito
    
    //Imprimindo o quinto tópico
    cout << "\tQuantidade total dos quilômetros rodados por veículos com 5 anos ou mais: " << kmTotal << "km" << endl;
    cout << "\tMédia dos quilômetros rodados por veículos com 5 anos ou mais: " << kmTotal / iVelho << "km" << endl;
    
    return 0;
}


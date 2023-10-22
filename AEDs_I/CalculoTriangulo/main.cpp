#include <cstdlib>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

    float lado1, lado2, lado3;

    printf("\n\t Categorização de Triângulo\n\n");

    printf("\n\t Digite o primeiro lado do triângulo: ");
    scanf(" %f", &lado1);
    while (lado1 < 0.0) {
        printf("\n\tValor inválido. Digite novamente o lado: ");
        scanf(" %f", &lado1);
    };

    printf("\n\t Digite o segundo lado do triângulo: ");
    scanf(" %f", &lado2);
    while (lado2 < 0.0) {
        printf("\n\tValor inválido. Digite novamente o lado: ");
        scanf(" %f", &lado2);
    };

    printf("\n\t Digite o terceiro lado do triângulo: ");
    scanf(" %f", &lado3);
    while (lado3 < 0.0) {
        printf("\n\tValor inválido. Digite novamente o lado: ");
        scanf(" %f", &lado3);
    };



    if (lado1 + lado2 >= lado3 && lado2 + lado3 >= lado1) {
        if (lado1 == lado2 && lado2 == lado3) {
            printf("\n\n\t Esse triângulo é um Triângulo equilátero");
        } else {
            if (lado1 == lado2 || lado3 == lado2 || lado1 == lado3) {
                printf("\n\n\t Esse triângulo é um Triângulo Isóceles");
            } else {
                if ((lado1 * lado1) + (lado2 * lado2) == (lado3 * lado3) || (lado2 * lado2) + (lado3 * lado3) == (lado1 * lado1) || (lado1 * lado1) + (lado3 * lado3) == (lado2 * lado2)) {
                    printf("\n\n\t Esse triângulo é um Triângulo Retângulo");
                } else {
                    printf("\n\n\t Esse triângulo é um Triângulo Escaleno");
                };

            };
        }


    } else {
        printf("\n\n\tEsse Triângulo não existe\n");
    };











    return 0;
}


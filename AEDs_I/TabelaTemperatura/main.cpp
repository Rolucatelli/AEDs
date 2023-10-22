#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    float tempcel, tempfah, incremento;
    
    printf("\n\t Tabela de conversão de temperatura\n");

    printf("\n\t Digite um valor de temperatura em Celsius menor que 101: ");
    scanf(" %f", &tempcel);
    while (tempcel > 100) {
        printf("\n\t Valor inválido. Digite novamente um valor de temperatura em Celsius menor que 101: ");
        scanf(" %f", &tempcel);
    };
    
    printf("\n\t Digite o quanto vai aumentar a temperatura de 1 a 10: ");
    scanf(" %f", &incremento);
    while (incremento <= 0.0 || incremento > 10) {
        printf("\n\t Valor inválido. Digite novamente quanto vai aumentar a temperatura de 1 a 10: ");
        scanf(" %f", &incremento);
    };
    
    printf("\n\t==================================\n"
            "\t===== Celsius     Fahrenheit =====\n"
            "\t==================================\n");

    while (tempcel <= 100) {

        tempfah = tempcel * 9 / 5 + 32;
        printf("\t=== %f   %f  ===\n", tempcel, tempfah);
        tempcel = tempcel + incremento;
    }
    printf("\t==================================");
    return 0;
}


#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    float altura, peso, imc;
    
    printf("\n\t Cálculo de IMC\n\n");
    
    
    printf("\n\t Digite o peso: ");
    scanf(" %f", &peso);
    while(peso<0.0){
        printf("\n\tValor inválido. Digite novamente o peso: ");
        scanf(" %f", &peso);
    };
    
    printf("\n\t Digite a altura: ");
    scanf(" %f", &altura);
    while(altura<0.0){
        printf("\n\tValor inválido. Digite novamente a altura: ");
        scanf(" %f", &altura);
    };
    
    imc = (peso/(altura*altura));
    printf("\n\n\n\n\n\t O IMC é: %f\n", imc);
    
    
    if(imc<18.5) {
        printf("\n\tVocê está na categoria: Magreza\n\n\n");
    }else{
        if(imc<=24.9) {
        printf("\n\tVocê está na categoria: Normal\n\n\n\n");
    }else{
        if(imc<=29.9) {
        printf("\n\tVocê está na categoria: Soprepeso (Grau I de Obesidade)\n\n\n\n");
    }else{
        if(imc<=39.9) {
        printf("\n\tVocê está na categoria: Obesidade (Grau II de Obesidade)\n\n\n\n");
    }else{
        printf("\n\tVocê está na categoria: Obesidade Grave (Grau III de Obesidade)\n\n\n\n");
    };};};};
    
    
    return 0;
}


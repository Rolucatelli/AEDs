#include <stdio.h>

int main() {

    float nota1, nota2, notaTrab, media;
    printf("\n\t Cáuculo da Média de AEDs I \n\n");
    
    printf("\n\tDigite a Nota 1: ");
    scanf(" %f", &nota1);
    while(nota1>10.0 || nota1<0.0) {
        printf("\n\tValor inválido, digite novamente a Nota 1: ");
        scanf(" %f", &nota1);
    };
    
    printf("\n\tDigite a Nota 2: ");
    scanf(" %f", &nota2);
    while(nota2>10.0 || nota2<0.0) {
        printf("\n\tValor inválido, digite novamente a Nota 2: ");
        scanf(" %f", &nota2);
    };
    
    printf("\n\tDigite a Nota do Trabalho: ");
    scanf(" %f", &notaTrab);
    while(notaTrab>10.0 || notaTrab<0.0) {
        printf("\n\tValor inválido, digite novamente a Nota do Trabalho: ");
        scanf(" %f", &notaTrab);
    };
    
    

    
    media = (3*nota1 + 3*nota2 + 4*notaTrab)/10;
    printf("\n\n\n\n\n\t Média de AEDs I : %2.2f\n\n", media);

    if (media >= 6.0) {
    printf("\t Você está aprovado!\n\n\n\n");
  } else {
    printf("\t Você está reprovado!\n\n\n\n");
  };
  
  return 0;
}
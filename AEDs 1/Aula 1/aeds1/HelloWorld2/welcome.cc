#include <stdio.h>

int main(){
  float nota1 = 3.0, nota2 = 8.0, notaTrab = 6.0;
  
  float media = (3*nota1+3*nota2+4*notaTrab)/10;
    
  printf("\n\t Olá Mundo!!! \n\n");
  printf("\t Média de AEDs I : %2.2f \n\n", media);
  
  if (media >= 6.0) {
      
    printf("\t Você está aprovado!\n\n");
  
  } else {
  
    printf("\t Você está reprovado!\n");
  
  }
  return 0;
}
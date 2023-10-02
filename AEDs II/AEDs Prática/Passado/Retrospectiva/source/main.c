#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main()
{
    int valor;
    conta cliente[100];
    cliente[0].dinheiro = 1000.0;
    cliente[1].dinheiro = 0.0;

    printf("Você têm R$:%.2f em sua conta\n", cliente[0].dinheiro);
    printf("Quanto deseja pagar? ");
    scanf("%d", &valor);

    if(pagamento(cliente, 0, 1, valor)){
        printf("Ocorreu um erro!\n");
    }else{
        printf("Pagamento realizado com sucesso!\n");
    }
    printf("Saldo Pagador: %f, Saldo Recebidor: %f\n", cliente[0].dinheiro, cliente[1].dinheiro);
    return 0;
}

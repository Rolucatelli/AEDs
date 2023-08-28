#include <stdio.h>
#include <stdlib.h>

typedef struct conta_{
    float dinheiro;
    float limite;
    char nome[100], chavePix[100];
    struct endereco_{
        char rua[100], estado[100], cidade[100];
        int num;
    } endereco;

}conta;

void pagamento(conta conta[], int iPagador, int iRecebidor, float valor) {

    if (conta[iPagador].dinheiro < valor){
        printf("Não foi possível realizar o pagamento porque o pagador não possui dinheiro o suficiente!\n");
    }else{
        conta[iPagador].dinheiro -= valor;
        conta[iRecebidor].dinheiro += valor;
        printf("Pagamento realizado com sucesso\n");
    }
}
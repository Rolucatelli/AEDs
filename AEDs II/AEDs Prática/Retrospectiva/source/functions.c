#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

int pagamento(conta conta[], int iPagador, int iRecebidor, float valor) {

    if (conta[iPagador].dinheiro < valor){
        return 1;
    }else{
        conta[iPagador].dinheiro -= valor;
        conta[iRecebidor].dinheiro += valor;
        return 0;
    }
}
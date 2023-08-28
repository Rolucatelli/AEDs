#ifndef _H_EXISTE
#define _H_EXISTE

typedef struct conta_{
    float dinheiro;
    float limite;
    char nome[100], chavePix[100];
    struct endereco_{
        char rua[100], estado[100], cidade[100];
        int num;
    } endereco;

}conta;

void pagamento(conta conta[], int iPagador, int iRecebidor, float valor);

#endif
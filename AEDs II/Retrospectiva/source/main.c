#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main()
{
    conta cliente[100];
    cliente[0].dinheiro = 1000.0;
    cliente[1].dinheiro = 100.0;
    pagamento(cliente, 0, 1, 50);

    printf("Saldo Pagador: %f, Saldo Recebidor: %f\n", cliente[0].dinheiro, cliente[1].dinheiro);




    return 0;
}

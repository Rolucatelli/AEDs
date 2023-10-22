#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n){
    int a = 0, b = 1, aux, i;

    printf("\n\t Sequência de fibonacci até o %d° número: \n\t", n);

    for (i = 0; i < n; i++)
    {
        aux = a + b;
        a = b;
        b = aux;

        printf("%d ", aux);
    }
    printf("\n");
    
}
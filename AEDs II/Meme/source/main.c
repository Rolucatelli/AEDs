#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"


int main(void)
{
    int n;
    printf("\n\t Quantos números da sequência quer?\n\t")/
    scanf("%d", &n);
    fibonacci(n);
    
    return 0;
}

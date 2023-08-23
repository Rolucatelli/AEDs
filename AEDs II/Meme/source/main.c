#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"


int main(int argc, char const *argv[])
{
    int n;
    printf("\n\t Quantos números da sequência quer?\n\t")/
    scanf("%d", &n);
    fibonacci(n);
    
    return 0;
}

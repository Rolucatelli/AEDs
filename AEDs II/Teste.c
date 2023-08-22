#include <stdio.h>
void troca (int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(int argc, char const *argv[])
{   
    int n1, n2;
    int *p1 = &n1, *p2 = &n2;
    scanf("%d %d", p1, p2);
    troca(p1, p2);
    printf("%d %d\n", n1, n2);
    
    return 0;
}

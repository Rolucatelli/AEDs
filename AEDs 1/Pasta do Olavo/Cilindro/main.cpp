#include <cstdlib>
#include <cstdio>

using namespace std;


int main(int argc, char** argv) {
    float altura, raio;
     
     printf("\n\t Digite a altura: ");
     scanf (" %f", &altura);
     printf("\n\t Digite a raio: ");
     scanf (" %f", &raio);
             
     
     printf("\t Volume do cilindro: %f\n\n", altura*raio*raio*3.14);
     printf("\t Área do cilindro: %f\n\n", 2*3.14*raio*altura + 2*3.14*raio*raio);

    return 0;
}


#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> vetor;
    vector<int> vetorIntervalo;
    int valor, limiteInferior, limiteSuperior;

    cout << "Digite os elementos do vetor separados por espaco (-1 para terminar):" << endl;
    while (cin >> valor && valor != -1)
    {
        vetor.push_back(valor);
    }

    cout << "Digite o limite inferior do intervalo: ";
    cin >> limiteInferior;
    cout << "Digite o limite superior do intervalo: ";
    cin >> limiteSuperior;

    for (int elemento : vetor)
    {
        if (elemento >= limiteInferior && elemento <= limiteSuperior)
        {
            vetorIntervalo.push_back(elemento);
        }
    }

    cout << "Valores no intervalo [" << limiteInferior << ", " << limiteSuperior << "]: ";
    for (int elemento : vetorIntervalo)
    {
        cout << elemento << " ";
    }
    cout << endl;

    return 0;
}

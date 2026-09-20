#include <iostream>
#include <vector>
using namespace std;

void maxSubarraySum(vector<int> &trechos, int rota) {
    int melhorSoma = trechos[0];
    int somaAtual = trechos[0];

    int melhorInicio = 0, melhorFim = 0;
    int inicioAtual = 0;

    for (int indice = 1; indice < trechos.size(); indice++) {
        // Reinicia o intervalo somente quando isso produz uma soma estritamente maior.
        if (somaAtual + trechos[indice] < trechos[indice]) {
            somaAtual = trechos[indice];
            inicioAtual = indice;
        } else {
            somaAtual += trechos[indice];
        }

        // Uma soma maior sempre substitui a resposta anterior.
        if (somaAtual > melhorSoma) {
            melhorSoma = somaAtual;
            melhorInicio = inicioAtual;
            melhorFim = indice;
        }
        // Com somas iguais, permanece o intervalo que possui mais trechos.
        else if (somaAtual == melhorSoma) {
            if ((indice - inicioAtual) > (melhorFim - melhorInicio)) {
                melhorInicio = inicioAtual;
                melhorFim = indice;
            }
        }
    }

    if (melhorSoma <= 0) {
        cout << "Route " << rota << " has no nice parts" << endl;
    } else {
        cout << "The nicest part of route " << rota
             << " is between stops " << melhorInicio + 1
             << " and " << melhorFim + 2 << endl;
    }
}

int main() {
    int quantidadeRotas;
    cin >> quantidadeRotas;

    if (quantidadeRotas >= 1 && quantidadeRotas <= 100) {
        for (int indiceRota = 0; indiceRota < quantidadeRotas; indiceRota++) {
            int quantidadeParadas;
            cin >> quantidadeParadas;

            vector<int> valores;
            for (int indiceTrecho = 0; indiceTrecho < quantidadeParadas - 1; indiceTrecho++) {
                int valor;
                cin >> valor;
                valores.push_back(valor);
            }

            maxSubarraySum(valores, indiceRota + 1);
        }
    }

    return 0;
}

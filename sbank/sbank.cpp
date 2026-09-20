#include <iostream>
#include <vector>
#include <string>
using namespace std;

string juntarConta(string parte1, string parte2, string parte3, string parte4, string parte5, string parte6) {
    return parte1 + parte2 + parte3 + parte4 + parte5 + parte6;
}

string formatarConta(string conta) {
    return conta.substr(0, 2) + " " +
           conta.substr(2, 8) + " " +
           conta.substr(10, 4) + " " +
           conta.substr(14, 4) + " " +
           conta.substr(18, 4) + " " +
           conta.substr(22, 4);
}

void countingSortPorDigito(vector<string> &contas, int indiceDigito) {
    vector<int> frequencias(10, 0);
    vector<string> ordenadas(contas.size());

    for (int indice = 0; indice < contas.size(); indice++) {
        int digito = contas[indice][indiceDigito] - '0';
        frequencias[digito]++;
    }

    for (int digito = 1; digito < 10; digito++) {
        frequencias[digito] += frequencias[digito - 1];
    }

    for (int indice = contas.size() - 1; indice >= 0; indice--) {
        int digito = contas[indice][indiceDigito] - '0';
        ordenadas[frequencias[digito] - 1] = contas[indice];
        frequencias[digito]--;
    }

    for (int indice = 0; indice < contas.size(); indice++) {
        contas[indice] = ordenadas[indice];
    }
}

void radixSort(vector<string> &contas) {
    if (contas.empty()) {
        return;
    }

    int quantidadeDigitos = contas[0].size();

    for (int indiceDigito = quantidadeDigitos - 1; indiceDigito >= 0; indiceDigito--) {
        countingSortPorDigito(contas, indiceDigito);
    }
}

void imprimirContasOrdenadas(vector<string> &contas) {
    if (contas.empty()) {
        cout << endl;
        return;
    }

    int quantidadeRepeticoes = 1;

    for (int indice = 1; indice < contas.size(); indice++) {
        if (contas[indice] == contas[indice - 1]) {
            quantidadeRepeticoes++;
        } else {
            cout << formatarConta(contas[indice - 1]) << " " << quantidadeRepeticoes << endl;
            quantidadeRepeticoes = 1;
        }
    }

    cout << formatarConta(contas[contas.size() - 1]) << " " << quantidadeRepeticoes << endl;
    cout << endl;
}

int main() {
    int quantidadeCasos;
    cin >> quantidadeCasos;

    for (int casoAtual = 0; casoAtual < quantidadeCasos; casoAtual++) {
        int quantidadeContas;
        cin >> quantidadeContas;

        vector<string> contas;
        string parte1, parte2, parte3, parte4, parte5, parte6;

        for (int indice = 0; indice < quantidadeContas; indice++) {
            cin >> parte1 >> parte2 >> parte3 >> parte4 >> parte5 >> parte6;
            contas.push_back(juntarConta(parte1, parte2, parte3, parte4, parte5, parte6));
        }

        radixSort(contas);
        imprimirContasOrdenadas(contas);
    }

    return 0;
}

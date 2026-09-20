#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long merge_and_count(vector<int>& valores, vector<int>& auxiliar, int inicio, int meio, int fim) {
    // Cada indice controla uma parte do processo de intercalacao.
    int indiceEsquerda = inicio;
    int indiceDireita = meio + 1;
    int indiceAuxiliar = inicio;
    // Guarda quantos pares fora de ordem aparecem entre as duas metades.
    long long inversoes = 0;

    while (indiceEsquerda <= meio && indiceDireita <= fim) {
        // Em caso de igualdade, o item da esquerda vem primeiro e nao gera inversao.
        if (valores[indiceEsquerda] <= valores[indiceDireita]) {
            auxiliar[indiceAuxiliar] = valores[indiceEsquerda];
            indiceEsquerda += 1;
        } else {
            // O item da direita e menor que todos os itens ainda nao copiados
            // da metade esquerda, formando uma inversao com cada um deles.
            auxiliar[indiceAuxiliar] = valores[indiceDireita];
            inversoes += meio - indiceEsquerda + 1;
            indiceDireita += 1;
        }
        indiceAuxiliar += 1;
    }

    // Transfere os valores restantes do lado esquerdo.
    while (indiceEsquerda <= meio) {
        auxiliar[indiceAuxiliar] = valores[indiceEsquerda];
        indiceEsquerda += 1;
        indiceAuxiliar += 1;
    }

    // Transfere os valores restantes do lado direito.
    while (indiceDireita <= fim) {
        auxiliar[indiceAuxiliar] = valores[indiceDireita];
        indiceDireita += 1;
        indiceAuxiliar += 1;
    }

    // Devolve ao vetor principal o intervalo que acabou de ser ordenado.
    for (int indice = inicio; indice <= fim; indice += 1) {
        valores[indice] = auxiliar[indice];
    }

    return inversoes;
}

long long merge_sort_and_count(vector<int>& valores, vector<int>& auxiliar, int inicio, int fim) {
    // Intervalos unitarios ou vazios nao possuem inversoes.
    if (inicio >= fim) {
        return 0;
    }

    // Separa o intervalo em duas partes aproximadamente iguais.
    int meio = (inicio + fim) / 2;

    // Conta as inversoes internas de cada metade e as que cruzam as metades.
    long long inversoes = merge_sort_and_count(valores, auxiliar, inicio, meio);
    inversoes += merge_sort_and_count(valores, auxiliar, meio + 1, fim);
    inversoes += merge_and_count(valores, auxiliar, inicio, meio, fim);

    return inversoes;
}

long long count_minimum_exchanges(const vector<int>& entrada) {
    // Nenhuma troca e necessaria quando nao existem elementos.
    if (entrada.empty()) {
        return 0;
    }

    // A copia permite ordenar sem modificar o vetor recebido pela funcao.
    vector<int> valores = entrada;
    // O mesmo vetor auxiliar e reutilizado por todas as chamadas do Merge Sort.
    vector<int> auxiliar(valores.size(), 0);
    return merge_sort_and_count(valores, auxiliar, 0, static_cast<int>(valores.size()) - 1);
}

int main() {
    int quantidade;
    vector<string> resultados;

    while (cin >> quantidade) {
        // O valor zero encerra a sequencia de casos de teste.
        if (quantidade == 0) {
            break;
        }

        // Armazena os numeros pertencentes ao caso atual.
        vector<int> numeros(quantidade);
        for (int indice = 0; indice < quantidade; indice += 1) {
            cin >> numeros[indice];
        }

        // Uma troca entre vizinhos elimina exatamente uma inversao.
        long long trocasMinimas = count_minimum_exchanges(numeros);
        resultados.push_back("Minimum exchange operations : " + to_string(trocasMinimas));
    }

    // Mantem exatamente o formato de saida solicitado pelo problema.
    for (size_t indice = 0; indice < resultados.size(); indice += 1) {
        if (indice > 0) {
            cout << '\n';
        }
        cout << resultados[indice];
    }
    cout << "\n";

    return 0;
}

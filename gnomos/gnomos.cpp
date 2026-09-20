#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find_award_index(const vector<int>& limites, int pontuacao, int inicio, int fim) {
    // Ao esvaziar o intervalo, inicio representa a primeira faixa acima da pontuacao.
    if (inicio > fim) {
        return inicio;
    }

    // Examina o limite localizado no centro do intervalo atual.
    int meio = (inicio + fim) / 2;

    // Se o limite central ultrapassa a pontuacao, continua pela metade esquerda.
    if (pontuacao < limites[meio]) {
        return find_award_index(limites, pontuacao, inicio, meio - 1);
    }

    // Caso a pontuacao alcance o limite, a faixa correta fica depois dele.
    return find_award_index(limites, pontuacao, meio + 1, fim);
}

int main() {
    int quantidadeFaixas;
    int quantidadeAlunos;

    if (!(cin >> quantidadeFaixas >> quantidadeAlunos)) {
        return 0;
    }

    // Estes valores determinam onde cada nova faixa comeca.
    vector<int> limites(quantidadeFaixas - 1);
    for (int indice = 0; indice < quantidadeFaixas - 1; indice += 1) {
        cin >> limites[indice];
    }

    // Cada posicao guarda o premio referente a uma faixa.
    vector<int> premios(quantidadeFaixas);
    for (int indice = 0; indice < quantidadeFaixas; indice += 1) {
        cin >> premios[indice];
    }

    // As pontuacoes devem ser respondidas na mesma ordem da entrada.
    vector<int> pontuacoes(quantidadeAlunos);
    for (int indice = 0; indice < quantidadeAlunos; indice += 1) {
        cin >> pontuacoes[indice];
    }

    vector<string> resultado;
    for (int pontuacao : pontuacoes) {
        // A busca retorna diretamente a posicao do premio correspondente.
        int indicePremio = find_award_index(
            limites, pontuacao, 0, static_cast<int>(limites.size()) - 1
        );
        resultado.push_back(to_string(premios[indicePremio]));
    }

    // Separa os premios por um unico espaco, sem espaco depois do ultimo.
    for (size_t indice = 0; indice < resultado.size(); indice += 1) {
        if (indice > 0) {
            cout << " ";
        }
        cout << resultado[indice];
    }
    cout << "\n";

    return 0;
}

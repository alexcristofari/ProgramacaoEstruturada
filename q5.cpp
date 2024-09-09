#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Função para popular o vetor de nomes
void popularVetor(vector<string> &nomes, int quantidade) {
    string nome;
    for (int i = 0; i < quantidade; i++) {
        cout << "Digite o nome " << i + 1 << ": ";
        getline(cin >> ws, nome); // ws para ignorar espaços em branco
        nomes.push_back(nome); // Adiciona o nome ao vetor
    }
}

// Função para exibir o conteúdo do vetor de nomes
void exibirVetor(const vector<string> &nomes) {
    cout << "\nLista de nomes cadastrados:\n";
    for (size_t i = 0; i < nomes.size(); i++) {
        cout << i + 1 << ": " << nomes[i] << endl;
    }
}

// Função para localizar um nome no vetor
int localizarNome(const vector<string> &nomes, const string &nomeProcurado) {
    for (size_t i = 0; i < nomes.size(); i++) {
        if (nomes[i] == nomeProcurado) {
            return i; // Retorna a posição do nome encontrado
        }
    }
    return -27; // Retorna -27 se o nome não for encontrado
}

int main() {
    vector<string> nomes; // Vetor de nomes
    int quantidade, opcao;
    string nomeProcurado;

    cout << "Digite a quantidade de nomes que deseja cadastrar: ";
    cin >> quantidade;

    // Chama a função para popular o vetor de nomes
    popularVetor(nomes, quantidade);

    // Exibe o conteúdo do vetor
    exibirVetor(nomes);

    // Localizar um nome no vetor
    cout << "\nDigite o nome que deseja localizar: ";
    getline(cin >> ws, nomeProcurado); // ws para ignorar espaços em branco

    int posicao = localizarNome(nomes, nomeProcurado);
    if (posicao != -27) {
        cout << "Nome encontrado na posição: " << posicao + 1 << endl;
    } else {
        cout << "Nome não encontrado." << endl;
    }

    return 0;
}

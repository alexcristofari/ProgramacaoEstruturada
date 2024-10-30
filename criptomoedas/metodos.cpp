#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "metodos.h"

using namespace std;

// Fun��o para dividir uma string
void split(std::string vetor[], std::string str, std::string deli) {
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start, end - start);
}

// Fun��o para carregar os dados do CSV no array Lista
int conectarComBase(std::string nomeArquivo, Cripto Lista[], int n) {
    ifstream procuradorLeitura;
    procuradorLeitura.open(nomeArquivo);
    string linha;
    int indice = 0;

    if (!procuradorLeitura.is_open()) {
        cout << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return 0;
    }

    while (!procuradorLeitura.eof() && indice < n) {
        getline(procuradorLeitura, linha);
        if (linha.empty()) {
            continue;
        }

        string vetorLinha[3];
        split(vetorLinha, linha, ";");

        Lista[indice].nome = vetorLinha[0];

        try {
            Lista[indice].valor = stod(vetorLinha[1]);  // Converte para double
        } catch (invalid_argument &e) {
            cout << "Erro: o valor '" << vetorLinha[1] << "' n�o � um n�mero v�lido." << endl;
            continue;
        }

        Lista[indice].data = vetorLinha[2];
        indice++;
    }

    procuradorLeitura.close();
    return indice;
}

// Fun��o do menu
void menu(Cripto Lista[], int &totalCadastrados) {
    int opcao;
    do {
        cout << "\nMenu de Op��es\n";
        cout << "1. Listar Criptomoedas\n";
        cout << "2. Cadastrar Nova Criptomoeda\n";
        cout << "3. Sair\n";
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                if (totalCadastrados == 0) {
                    cout << "Nenhuma criptomoeda cadastrada.\n";
                } else {
                    for (int i = 0; i < totalCadastrados; i++) {
                        cout << "Nome: " << Lista[i].nome 
                             << " | Valor: " << Lista[i].valor 
                             << " | Data: " << Lista[i].data << endl;
                    }
                }
                break;
            case 2:
                if (totalCadastrados < TAM) {
                    Cripto novaCripto;
                    cout << "Digite o nome da criptomoeda: ";
                    cin >> novaCripto.nome;
                    cout << "Digite o valor de mercado: ";
                    cin >> novaCripto.valor;
                    cout << "Digite a data da �ltima atualiza��o (formato dd/mm/aaaa): ";
                    cin >> novaCripto.data;
                    Lista[totalCadastrados] = novaCripto;
                    totalCadastrados++;

                    ofstream arquivo("criptomoedas.csv", ios::app);
                    if (arquivo.is_open()) {
                        arquivo << novaCripto.nome << ";" 
                                << novaCripto.valor << ";" 
                                << novaCripto.data << "\n";
                        arquivo.close();
                        cout << "Criptomoeda cadastrada e salva com sucesso no arquivo!\n";
                    } else {
                        cout << "Erro ao abrir o arquivo para salvar a nova criptomoeda!\n";
                    }

                } else {
                    cout << "N�o � poss�vel cadastrar mais criptomoedas (limite atingido).\n";
                }
                break;
            case 3:
                cout << "Saindo do programa...\n";
                break;
            default:
                cout << "Op��o inv�lida. Tente novamente.\n";
        }
    } while(opcao != 3);
}


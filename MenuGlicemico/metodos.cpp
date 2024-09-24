#include <fstream>
#include <iostream>
#include <sstream>
#include <string>        // Necessário para usar std::string e std::stoi
#include <stdexcept>     // Necessário para capturar std::invalid_argument
#include "metodos.h"

using namespace std;

// Função para dividir uma string
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

// Função para carregar os dados do CSV no array Lista
int conectarComBase(std::string nomeArquivo, Glicemia Lista[], int n) {
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
            continue;  // Ignora linhas vazias
        }

        string vetorLinha[2];
        split(vetorLinha, linha, ";");

        // Verifica se a primeira parte (valor) é realmente um número
        try {
            Lista[indice].valor = stoi(vetorLinha[0]);  // Converte para int
        } catch (invalid_argument &e) {
            cout << "Erro: o valor '" << vetorLinha[0] << "' não é um número válido." << endl;
            continue;  // Pula essa linha e vai para a próxima
        }

        Lista[indice].data = vetorLinha[1];
        indice++;
    }

    procuradorLeitura.close();
    return indice;  // Retorna o total de registros cadastrados
}

// Função do menu
void menu(Glicemia Lista[], int &totalCadastrados) {
    int opcao;
    do {
        cout << "\nMenu de Opções\n";
        cout << "1. Listar os Índices Glicêmicos\n";
        cout << "2. Cadastrar Novo Índice Glicêmico\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                // Listar os índices glicêmicos
                if (totalCadastrados == 0) {
                    cout << "Nenhum índice glicêmico cadastrado.\n";
                } else {
                    for (int i = 0; i < totalCadastrados; i++) {
                        cout << "Valor: " << Lista[i].valor 
                             << " | Data: " << Lista[i].data << endl;
                    }
                }
                break;
            case 2:
                // Cadastrar novo índice glicêmico
                if (totalCadastrados < TAM) {
                    Glicemia novoIndice;
                    cout << "Digite o valor da glicemia: ";
                    cin >> novoIndice.valor;
                    cout << "Digite a data (formato dd/mm/aaaa): ";
                    cin >> novoIndice.data;
                    Lista[totalCadastrados] = novoIndice;
                    totalCadastrados++;

                    // Abrir o arquivo CSV em modo append e gravar o novo índice
                    ofstream arquivo("glicemia.csv", ios::app);
                    if (arquivo.is_open()) {
                        arquivo << novoIndice.valor << ";" << novoIndice.data << "\n";
                        arquivo.close();
                        cout << "Índice glicêmico cadastrado e salvo com sucesso no arquivo!\n";
                    } else {
                        cout << "Erro ao abrir o arquivo para salvar o novo índice!\n";
                    }

                } else {
                    cout << "Não é possível cadastrar mais índices (limite atingido).\n";
                }
                break;
            case 3:
                cout << "Saindo do programa...\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while(opcao != 3);
}

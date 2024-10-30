#ifndef METODOS_H
#define METODOS_H

#include <fstream>
#include <string>

#define TAM 100  // Definindo TAM no arquivo de cabeçalho

// Definição da estrutura Cripto
struct Cripto {
    std::string nome;     // Nome da criptomoeda
    double valor;         // Valor de mercado da criptomoeda
    std::string data;     // Data da última atualização
};

// Função para dividir uma string (útil para ler o CSV)
void split(std::string vetor[], std::string str, std::string deli = " ");

// Função para conectar com o arquivo base (CSV) e carregar os dados no array
int conectarComBase(std::string nomeArquivo, Cripto Lista[], int n);

// Função para exibir o menu e manipular as opções
void menu(Cripto Lista[], int &totalCadastrados);

#endif


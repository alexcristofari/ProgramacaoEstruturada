#ifndef METODOS_H
#define METODOS_H

#include <fstream>
#include <string>

#define TAM 100  // Definindo TAM no arquivo de cabe�alho

// Defini��o da estrutura Cripto
struct Cripto {
    std::string nome;     // Nome da criptomoeda
    double valor;         // Valor de mercado da criptomoeda
    std::string data;     // Data da �ltima atualiza��o
};

// Fun��o para dividir uma string (�til para ler o CSV)
void split(std::string vetor[], std::string str, std::string deli = " ");

// Fun��o para conectar com o arquivo base (CSV) e carregar os dados no array
int conectarComBase(std::string nomeArquivo, Cripto Lista[], int n);

// Fun��o para exibir o menu e manipular as op��es
void menu(Cripto Lista[], int &totalCadastrados);

#endif


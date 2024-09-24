#ifndef METODOS_H
#define METODOS_H

#include <fstream>
#include <string>

#define TAM 100  // Definindo TAM no arquivo de cabeçalho

// Definição da estrutura Glicemia
struct Glicemia {
    int valor;
    std::string data;
};

// Função para dividir uma string (útil para ler o CSV)
void split(std::string vetor[], std::string str, std::string deli = " ");

// Função para conectar com o arquivo base (CSV) e carregar os dados no array
int conectarComBase(std::string nomeArquivo, Glicemia Lista[], int n);

// Função para exibir o menu e manipular as opções
void menu(Glicemia Lista[], int &totalCadastrados);

#endif

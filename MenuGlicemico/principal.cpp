#include <iostream>
#include <string>
#include "metodos.h"

#define TAM 100
using namespace std;

int main(){
    Glicemia Lista[TAM];
    int totalCadastrados = 0;

    // Carregar dados do arquivo CSV
    totalCadastrados = conectarComBase("glicemia.csv", Lista, TAM);

    // Chamar o menu para interagir com o usuário
    menu(Lista, totalCadastrados);

    return 0;
}

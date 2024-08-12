#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define TAMANHO 5

int main() {
    system("cls");
    int matriz[TAMANHO][TAMANHO];
    int soma = 0, maior, soma_diagonal = 0, soma_primeira_linha = 0, soma_ultima_coluna = 0;

    srand(time(NULL));
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            matriz[i][j] = rand() % 10;
            cout << matriz[i][j] << " ";
            soma += matriz[i][j];
            if (i == 0) soma_primeira_linha += matriz[i][j];
            if (i == j) soma_diagonal += matriz[i][j];
            if (j == TAMANHO - 1) soma_ultima_coluna += matriz[i][j];
        }
        cout << endl;
    }

    maior = matriz[0][0];
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
    }

    float media = soma / (float)(TAMANHO * TAMANHO);

    cout << "Soma dos elementos: " << soma << endl;
    cout << "Média dos elementos: " << media << endl;
    cout << "Maior elemento: " << maior << endl;
    cout << "Soma da diagonal principal: " << soma_diagonal << endl;
    cout << "Soma da primeira linha: " << soma_primeira_linha << endl;
    cout << "Soma da última coluna: " << soma_ultima_coluna << endl;

    return 1;
}

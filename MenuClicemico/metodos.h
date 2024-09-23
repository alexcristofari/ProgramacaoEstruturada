#include <fstream>

typedef struct {
    int valor;
    string data;
} Glicemia;

void split(string vetor[], string str, string deli = " ")
{        
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

void conectarComBase(string nomeArquivo, Glicemia Lista[], int n) {
    ifstream procuradorLeitura;
    procuradorLeitura = open(nomeArquivo);
        while (!procuradorLeitura.eof()) {
            getLine(procuradorLeitura, linha);
            string vetorLinha[2];
            split(vetorLinha, linha ";");
            lista[indice].valor = vetorLinha[0];
            lista[indice].data = vetorLinha[1];

        }

    procuradorLeitura.close();

    
}

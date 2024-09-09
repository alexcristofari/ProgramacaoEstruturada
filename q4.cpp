#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definição da struct Paciente
struct Paciente {
    string nome;
    int idade;
    int tipoDiabetes;  // 1 para tipo 1, 2 para tipo 2
};

// Função para cadastrar um paciente
void cadastrarPaciente(vector<Paciente> &pacientes) {
    Paciente novoPaciente;

    // Limpa o buffer de entrada para garantir que getline funcione corretamente
    cin.ignore();  // Ignora o caractere de nova linha remanescente no buffer

    cout << "Digite o nome do paciente: ";
    getline(cin, novoPaciente.nome);  // Lê o nome completo do paciente

    cout << "Digite a idade do paciente: ";
    cin >> novoPaciente.idade;

    do {
        cout << "Digite o tipo de diabetes (1 para Tipo 1 ou 2 para Tipo 2): ";
        cin >> novoPaciente.tipoDiabetes;
    } while (novoPaciente.tipoDiabetes != 1 && novoPaciente.tipoDiabetes != 2);

    // Adiciona o novo paciente ao vetor
    pacientes.push_back(novoPaciente);
    cout << "Paciente cadastrado com sucesso!" << endl;
}

// Função para listar todos os pacientes cadastrados
void listarPacientes(const vector<Paciente> &pacientes) {
    if (pacientes.empty()) {
        cout << "Nenhum paciente cadastrado!" << endl;
        return;
    }

    cout << "\nLista de Pacientes Cadastrados:\n";
    for (size_t i = 0; i < pacientes.size(); ++i) {
        cout << "Paciente " << i + 1 << ":\n";
        cout << "Nome: " << pacientes[i].nome << "\n";
        cout << "Idade: " << pacientes[i].idade << "\n";
        cout << "Tipo de Diabetes: " << (pacientes[i].tipoDiabetes == 1 ? "Tipo 1" : "Tipo 2") << "\n\n";
    }
}

// Função para exibir o menu e obter a escolha do usuário
int exibirMenu() {
    int opcao;
    cout << "\n--- Menu ---\n";
    cout << "1. Cadastrar Paciente\n";
    cout << "2. Listar Pacientes\n";
    cout << "3. Sair\n";
    cout << "Escolha uma opcao: ";
    cin >> opcao;
    return opcao;
}

// Função principal
int main() {
    vector<Paciente> pacientes;
    int opcao;

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case 1:
                cadastrarPaciente(pacientes);
                break;
            case 2:
                listarPacientes(pacientes);
                break;
            case 3:
                cout << "Saindo do programa...\n";
                break;
            default:
                cout << "Opcao invalida! Tente novamente.\n";
                break;
        }
    } while (opcao != 3);

    return 0;
}

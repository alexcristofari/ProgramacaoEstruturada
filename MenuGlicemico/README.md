# Menu Glicêmico

Este projeto implementa um sistema simples para gerenciar índices glicêmicos, permitindo listar, adicionar e armazenar novos índices em um arquivo CSV.

## Funcionalidades

O sistema possui um menu interativo com as seguintes opções:

1. **Listar Índices Glicêmicos**: Exibe os valores glicêmicos cadastrados, juntamente com as respectivas datas.
2. **Cadastrar Novo Índice Glicêmico**: Permite ao usuário inserir um novo valor glicêmico e a data correspondente. O valor é então salvo na lista e também atualizado no arquivo `glicemia.csv`.
3. **Sair**: Encerra o programa.

### Como o sistema funciona:

- O programa lê os índices glicêmicos de um arquivo chamado `glicemia.csv` no formato `valor;data`.
- Quando um novo índice é cadastrado, ele é salvo tanto na memória quanto no arquivo `glicemia.csv`, garantindo a persistência dos dados.

## Estrutura do Projeto

MenuGlicemico/ │ ├── principal.cpp # Arquivo principal que contém a função main ├── metodos.cpp # Arquivo contendo as funções para manipulação de glicemia ├── metodos.h # Arquivo de cabeçalho contendo as definições e declarações ├── glicemia.csv # Arquivo CSV onde os índices glicêmicos são armazenados └── README.md # Este arquivo, com instruções sobre o projeto


## Requisitos

- **Compilador C++**: Você precisará de um compilador como o `g++` (parte do GCC) ou qualquer outro compilador C++.
- **Sistema Operacional**: O código foi desenvolvido e testado no Windows, mas deve funcionar em outros sistemas com pequenas adaptações.

## Executando o Projeto

### Passo 1: Clonar o Repositório

Clone o repositório do GitHub em sua máquina local:

```bash
git clone https://github.com/alexcristofari/ProgramacaoEstruturada.git


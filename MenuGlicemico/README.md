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

``bash

git clone https://github.com/alexcristofari/ProgramacaoEstruturada.git

---

## Passo 2: Navegar até o diretório do projeto
bash
Copiar código
cd ProgramacaoEstruturada/MenuGlicemico

## Passo 3: Compilar o código
No terminal, use o seguinte comando para compilar o código:

bash
Copiar código
g++ principal.cpp metodos.cpp -o principal.exe

## Passo 4: Executar o programa
Após a compilação, você pode executar o programa:

bash
Copiar código
.\principal.exe

## Passo 5: Utilizando o programa
Listar os Índices Glicêmicos: Escolha a opção 1 no menu para ver os índices glicêmicos cadastrados.
Cadastrar Novo Índice Glicêmico: Escolha a opção 2 para adicionar um novo índice glicêmico (valor e data).
Sair: Escolha a opção 3 para encerrar o programa.
Formato do arquivo glicemia.csv
O arquivo glicemia.csv será atualizado automaticamente sempre que um novo índice glicêmico for cadastrado. O formato esperado do arquivo é o seguinte:

plaintext
Copiar código

120;12/09/2024

100;11/09/2024

95;10/09/2024

Onde o primeiro valor é o índice glicêmico e o segundo valor é a data no formato dd/mm/aaaa.


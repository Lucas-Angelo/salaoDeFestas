#include <iostream>
#include <stdio.h>
#include "munit.h"

using namespace std;
#include <string>
#include <time.h>
#include "FornecedorClass.h"
#include "helpers/ModelHelper.h"
#include <fstream>

int funcaoFornecedor(){

printf ("Hello world");

return 0;
}

void procuraFornecedor() {
    cout << "\n------------>PESQUISA DE FORNECEDOR<------------" << endl;
    string nome;
    cout << "Pesquisar por nome: ";
    cin >> nome;
    FornecedorClass f;
    int i=0;
    ifstream inFile;
    // Abrir o arquivo para leitura
    inFile.open("files/fornecedor.txt");
    string line;
    // Ler linha por linha até o fim do arquivo.
    while (getline(inFile, line)) {
        // Se encontrar o codigo do funcionario, quebrar a linha e definir os atributos da classe
        if(ModelHelper::split(';', line, 1).find(nome) != std::string::npos) {
          f.codigo = atoi(ModelHelper::split(';',line, 0).c_str());
          f.nome = ModelHelper::split(';',line, 1);
          f.telefone = ModelHelper::split(';',line, 2);
          f.produto = ModelHelper::split(';',line, 3);
          cout << "-------------------------------------------------------------" << endl;
          cout << "Código: " << f.codigo << endl;
          cout << "Nome: " << f.nome << endl;
          cout << "Telefone: " << f.telefone << endl;
          cout << "Produto: " << f.produto << endl;
          cout << "-------------------------------------------------------------" << endl;
        }
    }
}


#include <iostream>
#include <stdio.h>
#include "munit.h"

using namespace std;
#include <string>
#include <time.h>
#include "ClienteClass.h"
#include "helpers/ModelHelper.h"
#include <fstream>


int funcaoCliente()
{
    ClienteClass cli;
    setlocale(LC_ALL,"portuguese"); //colocar acento
    srand((unsigned int) time(NULL)); //configura a funcao aleatoria

    printf("\n------------>CADASTRO DE CLIENTE<------------\n");
    cli.codigo = rand();

    printf("\nDigite o nome: ");
    getline(cin >> ws,cli.nome);

    printf("\nDigite o endereço: ");
    getline(cin >> ws,cli.endereco);

    printf("\nDigite o telefone: ");
    cin>>cli.telefone;

    printf("\nDigite a data de nascimento: ");
    getline(cin >> ws,cli.dtNascimento);

    cli.save();

    return 0;
}

void procuraCliente() {
    cout << "\n------------>PESQUISA DE CLIENTES<------------" << endl;
    string nome;
    cout << "Pesquisar por nome: ";
    cin >> nome;
    ClienteClass c;
    int i=0;
    ifstream inFile;
     // Abrir o arquivo para leitura
    inFile.open("files/client.txt");
    string line;
    // Ler linha por linha até o fim do arquivo.
    while (getline(inFile, line)) {
        // Se encontrar o nome do cliente, quebrar a linha e definir os atributos da classe
        if(ModelHelper::split(';', line, 1).find(nome) != std::string::npos) {
            c.codigo = atoi(ModelHelper::split(';',line, 0).c_str());
            c.nome = ModelHelper::split(';',line, 1);
            c.endereco = ModelHelper::split(';',line, 2);
            c.telefone = atoi(ModelHelper::split(';',line, 3).c_str());
            c.dtNascimento = ModelHelper::split(';',line, 4);
            cout << "-------------------------------------------------------------" << endl;
            cout << "Código: " << c.codigo << endl;
            cout << "Nome: " << c.nome << endl;
            cout << "Endereço: " << c.endereco << endl;
            cout << "Data de Nascimento: " << c.dtNascimento << endl;
            cout << "Telefone: " << c.telefone << endl;
            cout << "-------------------------------------------------------------" << endl;
            i++;
        }
    }
    if(i == 0) cout << "------------------------\nNenhum item encontrado\n------------------------";
}




#include <iostream>
#include <stdio.h>
#include "munit.h"
#include <locale.h>
#include <ctype.h>

using namespace std;
#include <string.h>
#include <time.h>
#include "ClienteClass.h"
#include "helpers/ModelHelper.h"
#include <fstream>
#include "helpers/DateHelper.h"

string salvarDatas();
unsigned long salvarTelefones();// unsigned so pega valor positivo
int funcaoCliente()
{

    ClienteClass cli;
    setlocale(LC_ALL,"portuguese"); //colocar acento
    srand((unsigned int) time(NULL)); //configura a funcao aleatoria
    char c='a';
    while(toupper(c)!='C') {
        cout << "\n------------>CADASTRO DE CLIENTE<------------" << endl;

        cout << "\nDigite o nome: ";
        getline(cin >> ws,cli.nome);

        cout <<"Digite o endereço: ";
        getline(cin >> ws,cli.endereco);//ws pega a linha inteira

        cli.telefone = salvarTelefones();
        cli.dtNascimento = salvarDatas();

        cout << "\n\nDADOS DO CLIENTE:\n" << endl;
        printf("Código: %d\n", cli.codigo);
        cout << "Nome: " + cli.nome << endl;
        cout << "Endereço: " << cli.endereco << endl;
        cout << "Telefone: " << cli.telefone << endl;
        cout << "Data: " + cli.dtNascimento << endl;

        printf("\n--->CONFIRMAR DADOS<---");
        printf("\nC - Para confirmar");
        printf("\nR - Para refazer");
        printf("\nOs dados inseridos estão corretos? ");
        cin >> c;
    }
    cli.save();
    return 0;
}

void procuraCliente() {
    cout << "\n------------>PESQUISA DE CLIENTES<------------" << endl;
    string nome;
    cout << "Pesquisar por nome: ";
    getline(cin >> ws, nome);
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

unsigned long salvarTelefones() {
    unsigned long long int telefone=0;
    do {
        cin.seekg(0,ios::end);
        cin.clear();
        cout << "Digite o telefone: ";
        cin >> telefone;
        if (cin.fail()) { //entra aqui se houver algum erro
            cin.ignore(0xFFFF, '\n');
            cin.clear();
            cout << "~ ERRO : ENTRADA INVÁLIDA ~" << endl;
        }
    } while(telefone < 1000000000 || telefone > 9999999999 );
    return telefone;
}

string salvarDatas()
{
    DateHelper dh; //Chamar classe DataHelper, que verifica se a data inserida é válida
    cout << "Digite a data(dd/mm/AAAA): ";
    string data = dh.inputDate(); //Equivale ao cin da data, chamando a função para verificar se é válida
    cout << "data: " << data;
    return data;
}





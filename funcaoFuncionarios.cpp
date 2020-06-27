#include <iostream>
#include <locale.h>
#include <ctype.h>
#include <string>
#include <time.h>
using namespace std;

#include "FuncionariosClass.h"
#include "helpers/ModelHelper.h"

string salvarNome();
string salvarTelefone();
string salvarFuncao();
float salvarSalario();
char salvarTipo();


int funcaoFuncionarios()
{
    setlocale(LC_ALL,"portuguese"); //Adicionar caracteres especiais
    FuncionariosClass funcionarios; //Orientar a objeto por meio da classe



    char confirmar;
    cout << "\n>>> CADASTRAR FUNCIONÁRIO <<<" << endl;

    do {

        funcionarios.nome = salvarNome(); //Receber nome digitado.

        funcionarios.telefone = salvarTelefone(); //Receber telefone digitado.

        funcionarios.funcao = salvarFuncao(); //Receber Função do funcionário digitada.

        funcionarios.salario = salvarSalario(); //Receber salário digitado.

        funcionarios.tipo = salvarTipo(); //Receber tipo digitado.


        cout << "\nDados do funcionário:" << endl;
        cout << "Código: " << funcionarios.codigo << endl;
        cout << "Nome: " << funcionarios.nome << endl;
        cout << "Telefone: " << funcionarios.telefone << endl;
        cout << "Função: " << funcionarios.funcao << endl;
        cout << "Salário: " << funcionarios.salario << endl;
        cout << "Tipo: " << funcionarios.tipo << "\n" << endl;

        cout << "\n---> Confirmar dados <---" << endl;
        cout << "C - Para confirmar" << endl;
        cout << "R - Para refazer" << endl;
        cout << "Os dados inseridos estão corretos? ";
        cin >> confirmar;
    } while (toupper(confirmar)!='C');

    funcionarios.save(); //Salvar os dados do objeto classe funcionarios no arquivo

    cout << "\n---> FUNCIONÁRIO CADASTRADO COM SUCESSO <---\n\n" << endl;


    return 0;
}

string salvarNome() //Função para pegar o nome.
{
    string nome;
    cout << "Digite o nome? ";
    getline(cin >> ws,nome); //Capturar string/linha(nome) do funcionário.
    return nome;
}

string salvarTelefone() //Função para pegar o telefone do funcionário.
{
    int verificador=0, x, i;
    string telefone;
    cout << "Digite o telefone: ";
    do
    {
        getline(cin >> ws,telefone);
        for(i=0; i<telefone.length(); i++)
        {
            x=isdigit(telefone[i])?1:2; //1 para numerais, 2 para caracteres.
            if(x==1)
            {
                verificador++; //Se for numeral, incrementa.
            }
        }
        if(verificador<10)
        {
            cout << "Número de telefone inválido! [Mínimo de 10 números (DDD + número)]" << endl;
            cout << "Digite um telefone válido: ";
        }
    } while (verificador<10); //Se tiver no minimo 10 numerais, conclui.
    return telefone;
}

string salvarFuncao() //Funcao para pegar a funcao do funcionario.
{
    string funcao;
    cout << "Digite a Função: ";
    getline(cin >> ws,funcao);
    return funcao;
}

float salvarSalario() //Funcao para pegar o salario do funcionario.
{
    float salario;
    cout << "Digite o salário: ";
    do
    {
        fflush(stdin);
        cin >> salario;
        if(salario < 0)
        {
            cout << "Salário inválido!\nDigite um salário positivo: ";

        }
    } while (salario < 0);
    return salario;
}

char salvarTipo() //Funcao para pegar o tipo do funcionario.
{
    char tipo;
    cout << "Menu de opções:";
    cout << "\nT - Para temporário\nF - Para fixo";
    cout << "\nDigite o tipo do funcionário? ";
    do {
        fflush(stdin);
        cin >> tipo;
        tipo = toupper(tipo);
        if(tipo!='T' && tipo!='F')
        {
            cout << "Informe uma opçõe valida(T ou F): ";
        }
    } while (tipo!='T' && tipo!='F');

    return tipo;
}

void procuraFuncionario() {
    cout << "\n------------>PESQUISA DE FUNCIONÁRIOS<------------" << endl;
    string nome;
    cout << "Pesquisar por nome: ";
    getline(cin >> ws, nome);
    FuncionariosClass f;
    int i=0;
    ifstream inFile;
    // Abrir o arquivo para leitura
    inFile.open("files/funcionario.txt");
    string line;
    // Ler linha por linha atÃ© o fim do arquivo.
    while (getline(inFile, line)) {
        // Se encontrar o codigo do funcionario, quebrar a linha e definir os atributos da classe
        if((ModelHelper::split(';', line, 1)).find(nome) != std::string::npos) {
          f.codigo = atoi(ModelHelper::split(';',line, 0).c_str());
          f.nome = ModelHelper::split(';',line, 1);
          f.telefone = ModelHelper::split(';',line, 2);
          f.funcao = ModelHelper::split(';',line, 3);
          f.salario = atof(ModelHelper::split(';',line, 4).c_str());
          f.tipo = ModelHelper::split(';',line, 5)[0];
          cout << "-------------------------------------------------------------" << endl;
          cout << "Código: " << f.codigo << endl;
          cout << "Nome: " << f.nome << endl;
          cout << "Telefone: " << f.telefone << endl;
          cout << "Função: " << f.funcao << endl;
          cout << "Salário: " << f.salario << endl;
          cout << "Tipo: " << f.tipo << endl;
          cout << "-------------------------------------------------------------" << endl;
        }
    }
    if(i == 0) cout << "------------------------\nNenhum item encontrado\n------------------------";
}

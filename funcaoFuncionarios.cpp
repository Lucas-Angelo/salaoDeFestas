#include <iostream>
#include <stdio.h>
#include "munit.h"
#include <locale.h>
#include <ctype.h>

using namespace std;
#include <string>
#include <time.h>
#include "FuncionariosClass.h"

unsigned int gerarCodigo();
string salvarNome();
string salvarTelefone();
string salvarFuncao();
float salvarSalario();
char salvarTipo();


int funcaoFuncionarios()
{
    setlocale(LC_ALL,"portuguese"); //
    FuncionariosClass funcionarios;

    cout << ">>> CADASTRAR FUNCION�RIO <<<" << endl;

    funcionarios.codigo = gerarCodigo(); //Capturar c�digo aleat�rio gerado.

    funcionarios.nome = salvarNome(); //Receber nome digitado.
    cout << funcionarios.nome << endl;

    funcionarios.telefone = salvarTelefone(); //Receber telefone digitado.
    cout << funcionarios.telefone << endl;

    funcionarios.funcao = salvarFuncao(); //Receber fun��o do funcion�rio digitada.
    cout << funcionarios.funcao << endl;

    funcionarios.salario = salvarSalario(); //Receber sal�rio digitado.
    cout << funcionarios.salario << endl;


    funcionarios.tipo = salvarTipo(); //Receber tipo digitado.
    switch (funcionarios.tipo)
    {
        case 'T':
            cout << "Tempor�rio\n" << endl;
            break;
        case 'F':
            cout << "Fixo\n" << endl;
            break;
        default:
            cout << "Erro, por favor tente novamente.\n" << endl;
            break;
    }



    return 0;
}

unsigned int gerarCodigo() //Fun��o para gerar o c�digo aleat�rio
{
    srand((unsigned int)time(NULL)); //S� deve ser chamada uma �nica vez, para configurar o gerador de c�digo aleat�rio(rand), baseado no time.
    unsigned int codigo = rand(); //Salvar o c�digo usando rand, com as configura��es do srand.
    cout << "\nO c�digo �: " << codigo << endl;
    return codigo;
}

string salvarNome() //Fun��o para pegar o nome.
{
    string nome;
    cout << "Qual � o nome? ";
    getline(cin >> ws,nome); //Capturar string/linha(nome) do funcion�rio.
    return nome;
}

string salvarTelefone() //Fun��o para pegar o telefone do funcion�rio.
{
    string telefone;
    cout << "Digite o telefone: ";
    getline(cin >> ws,telefone);
    return telefone;
}

string salvarFuncao() //Fun��o para pegar a fun��o do funcion�rio.
{
    string funcao;
    cout << "Digite a fun��o: ";
    getline(cin >> ws,funcao);
    return funcao;
}

float salvarSalario() //Fun��o para pegar o sal�rio do funcion�rio.
{
    float salario;
    cout << "Digite o sal�rio: ";
    cin >> salario;
    return salario;
}

char salvarTipo() //Fun��o para pegar o tipo do funcion�rio.
{
    char tipo;
    cout << "\nMenu de op��es:";
    cout << "\nT - Para tempor�rio\nF - Para fixo";
    cout << "\nQual o tipo do funcion�rio? ";
    do
    {
        scanf(" %c", &tipo);
        tipo = toupper(tipo);
        cout << tipo << endl;
        if(tipo!='T' && tipo!='F')
        {
            cout << "Informe uma op��o v�lida(T ou F): ";
        }
    } while (tipo!='T' && tipo!='F');
    return tipo;
}

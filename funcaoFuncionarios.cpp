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

    cout << ">>> CADASTRAR FUNCIONÁRIO <<<" << endl;

    funcionarios.codigo = gerarCodigo(); //Capturar código aleatório gerado.

    funcionarios.nome = salvarNome(); //Receber nome digitado.
    cout << funcionarios.nome << endl;

    funcionarios.telefone = salvarTelefone(); //Receber telefone digitado.
    cout << funcionarios.telefone << endl;

    funcionarios.funcao = salvarFuncao(); //Receber função do funcionário digitada.
    cout << funcionarios.funcao << endl;

    funcionarios.salario = salvarSalario(); //Receber salário digitado.
    cout << funcionarios.salario << endl;


    funcionarios.tipo = salvarTipo(); //Receber tipo digitado.
    switch (funcionarios.tipo)
    {
        case 'T':
            cout << "Temporário\n" << endl;
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

unsigned int gerarCodigo() //Função para gerar o código aleatório
{
    srand((unsigned int)time(NULL)); //Só deve ser chamada uma única vez, para configurar o gerador de código aleatório(rand), baseado no time.
    unsigned int codigo = rand(); //Salvar o código usando rand, com as configurações do srand.
    cout << "\nO código é: " << codigo << endl;
    return codigo;
}

string salvarNome() //Função para pegar o nome.
{
    string nome;
    cout << "Qual é o nome? ";
    getline(cin >> ws,nome); //Capturar string/linha(nome) do funcionário.
    return nome;
}

string salvarTelefone() //Função para pegar o telefone do funcionário.
{
    string telefone;
    cout << "Digite o telefone: ";
    getline(cin >> ws,telefone);
    return telefone;
}

string salvarFuncao() //Função para pegar a função do funcionário.
{
    string funcao;
    cout << "Digite a função: ";
    getline(cin >> ws,funcao);
    return funcao;
}

float salvarSalario() //Função para pegar o salário do funcionário.
{
    float salario;
    cout << "Digite o salário: ";
    cin >> salario;
    return salario;
}

char salvarTipo() //Função para pegar o tipo do funcionário.
{
    char tipo;
    cout << "\nMenu de opções:";
    cout << "\nT - Para temporário\nF - Para fixo";
    cout << "\nQual o tipo do funcionário? ";
    do
    {
        scanf(" %c", &tipo);
        tipo = toupper(tipo);
        cout << tipo << endl;
        if(tipo!='T' && tipo!='F')
        {
            cout << "Informe uma opção válida(T ou F): ";
        }
    } while (tipo!='T' && tipo!='F');
    return tipo;
}

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


    char confirmar;
    cout << "\n>>> CADASTRAR FUNCION�RIO <<<" << endl;

    do
    {

        funcionarios.codigo = gerarCodigo(); //Capturar c�digo aleat�rio gerado.

        funcionarios.nome = salvarNome(); //Receber nome digitado.

        funcionarios.telefone = salvarTelefone(); //Receber telefone digitado.

        funcionarios.funcao = salvarFuncao(); //Receber fun��o do funcion�rio digitada.

        funcionarios.salario = salvarSalario(); //Receber sal�rio digitado.

        funcionarios.tipo = salvarTipo(); //Receber tipo digitado.


        cout << "\nDados do funcion�rio:" << endl;
        printf("C�digo: %d\n", funcionarios.codigo);
        cout << "Nome: " + funcionarios.nome << endl;
        cout << "Telefone: " + funcionarios.telefone << endl;
        cout << "Fun��o: " + funcionarios.funcao << endl;
        printf("Sal�rio: %.2f\n", funcionarios.salario);
        printf("Tipo: %c\n", funcionarios.tipo);

        printf("\n---> Confirmar dados <---");
        printf("\nC - Para confirmar");
        printf("\nR - Para refazer");
        printf("\nOs dados inseridos est�o corretos? ");
        cin >> confirmar;
    } while (toupper(confirmar)!='C');

    cout << "\n---> FUNCION�RIO CADASTRADO COM SUCESSO <---\n\n" << endl;



    return 0;
}

unsigned int gerarCodigo() //Fun��o para gerar o c�digo aleat�rio
{
    srand((unsigned int)time(NULL)); //S� deve ser chamada uma �nica vez, para configurar o gerador de c�digo aleat�rio(rand), baseado no time.
    unsigned int codigo;
    codigo = rand(); //Salvar o c�digo usando rand, com as configura��es do srand.
    return codigo;
}

string salvarNome() //Fun��o para pegar o nome.
{
    string nome;
    cout << "Digite o nome? ";
    getline(cin >> ws,nome); //Capturar string/linha(nome) do funcion�rio.
    return nome;
}

string salvarTelefone() //Fun��o para pegar o telefone do funcion�rio.
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
            cout << "N�mero de telefone inv�lido! [M�nimo de 10 n�meros (DDD + n�mero)]" << endl;
            cout << "Digite um telefone v�lido: ";
        }
    } while (verificador<10); //Se tiver no m�nimo 10 numerais, conclui.
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
    do
    {
        scanf("%f", &salario);
        if(salario < 0)
        {
            cout << "Sal�rio inv�lido!\nDigite um sal�rio positivo: ";

        }
    } while (salario < 0);
    return salario;
}

char salvarTipo() //Fun��o para pegar o tipo do funcion�rio.
{
    char tipo;
    cout << "Menu de op��es:";
    cout << "\nT - Para tempor�rio\nF - Para fixo";
    cout << "\nDigite o tipo do funcion�rio? ";
    do
    {
        scanf(" %c", &tipo);
        tipo = toupper(tipo);
        if(tipo!='T' && tipo!='F')
        {
            cout << "Informe uma op��o v�lida(T ou F): ";
        }
    } while (tipo!='T' && tipo!='F');

    return tipo;
}

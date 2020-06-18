#include <iostream>
#include <locale.h>
#include <ctype.h>
#include <string>
#include <time.h>
using namespace std;

#include "FuncionariosClass.h"
#include "helpers/ModelHelper.h"

unsigned int gerarCodigo();
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
        cout << "C�digo: " << funcionarios.codigo << endl;
        cout << "Nome: " << funcionarios.nome << endl;
        cout << "Telefone: " << funcionarios.telefone << endl;
        cout << "Fun��o: " << funcionarios.funcao << endl;
        cout << "Sal�rio: " << funcionarios.salario << endl;
        cout << "Tipo: " << funcionarios.tipo << "\n" << endl;

        cout << "\n---> Confirmar dados <---" << endl;
        cout << "C - Para confirmar" << endl;
        cout << "R - Para refazer" << endl;
        cout << "Os dados inseridos est�o corretos? ";
        cin >> confirmar;
    } while (toupper(confirmar)!='C');

    funcionarios.save(); //Salvar os dados do objeto classe funcionarios no arquivo

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
        fflush(stdin);
        cin >> salario;
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
        fflush(stdin);
        cin >> tipo;
        tipo = toupper(tipo);
        if(tipo!='T' && tipo!='F')
        {
            cout << "Informe uma op��o v�lida(T ou F): ";
        }
    } while (tipo!='T' && tipo!='F');

    return tipo;
}

void procuraFuncionario() {
    cout << "\n------------>PESQUISA DE FUNCION�RIOS<------------" << endl;
    string nome;
    cout << "Pesquisar por nome: ";
    getline(cin >> ws, nome);
    FuncionariosClass f;
    int i=0;
    ifstream inFile;
    // Abrir o arquivo para leitura
    inFile.open("files/funcionario.txt");
    string line;
    // Ler linha por linha at� o fim do arquivo.
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
          cout << "C�digo: " << f.codigo << endl;
          cout << "Nome: " << f.nome << endl;
          cout << "Telefone: " << f.telefone << endl;
          cout << "Fun��o: " << f.funcao << endl;
          cout << "Sal�rio: " << f.salario << endl;
          cout << "Tipo: " << f.tipo << endl;
          cout << "-------------------------------------------------------------" << endl;
        }
    }
    if(i == 0) cout << "------------------------\nNenhum item encontrado\n------------------------";
}

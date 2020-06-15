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
    cout << "\n>>> CADASTRAR FUNCIONÁRIO <<<" << endl;

    do
    {

        funcionarios.codigo = gerarCodigo(); //Capturar código aleatório gerado.

        funcionarios.nome = salvarNome(); //Receber nome digitado.

        funcionarios.telefone = salvarTelefone(); //Receber telefone digitado.

        funcionarios.funcao = salvarFuncao(); //Receber função do funcionário digitada.

        funcionarios.salario = salvarSalario(); //Receber salário digitado.

        funcionarios.tipo = salvarTipo(); //Receber tipo digitado.


        cout << "\nDados do funcionário:" << endl;
        printf("Código: %d\n", funcionarios.codigo);
        cout << "Nome: " + funcionarios.nome << endl;
        cout << "Telefone: " + funcionarios.telefone << endl;
        cout << "Função: " + funcionarios.funcao << endl;
        printf("Salário: %.2f\n", funcionarios.salario);
        printf("Tipo: %c\n", funcionarios.tipo);

        printf("\n---> Confirmar dados <---");
        printf("\nC - Para confirmar");
        printf("\nR - Para refazer");
        printf("\nOs dados inseridos estão corretos? ");
        cin >> confirmar;
    } while (toupper(confirmar)!='C');

    cout << "\n---> FUNCIONÁRIO CADASTRADO COM SUCESSO <---\n\n" << endl;



    return 0;
}

unsigned int gerarCodigo() //Função para gerar o código aleatório
{
    srand((unsigned int)time(NULL)); //Só deve ser chamada uma única vez, para configurar o gerador de código aleatório(rand), baseado no time.
    unsigned int codigo;
    codigo = rand(); //Salvar o código usando rand, com as configurações do srand.
    return codigo;
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
    } while (verificador<10); //Se tiver no mínimo 10 numerais, conclui.
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
    do
    {
        scanf("%f", &salario);
        if(salario < 0)
        {
            cout << "Salário inválido!\nDigite um salário positivo: ";

        }
    } while (salario < 0);
    return salario;
}

char salvarTipo() //Função para pegar o tipo do funcionário.
{
    char tipo;
    cout << "Menu de opções:";
    cout << "\nT - Para temporário\nF - Para fixo";
    cout << "\nDigite o tipo do funcionário? ";
    do
    {
        scanf(" %c", &tipo);
        tipo = toupper(tipo);
        if(tipo!='T' && tipo!='F')
        {
            cout << "Informe uma opção válida(T ou F): ";
        }
    } while (tipo!='T' && tipo!='F');

    return tipo;
}

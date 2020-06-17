#include <iostream>
#include <locale.h>
#include <string>
#include <time.h>

using namespace std;

#include "FestaClass.h"
#include "ClienteClass.h"
#include "helpers/DateHelper.h"

#include "munit.h"


unsigned int receberCodigoCliente();
unsigned int gerarCodigoFesta();
int salvarConvid();

int funcaoFesta()
{
    setlocale(LC_ALL,"portuguese"); //Adicionar caracteres especiais
    FestaClass festa; //Orientar a objeto por meio da classe

    festa.codigo_cliente = receberCodigoCliente();

    if(festa.codigo_cliente == 0) //Se o usuário desistiu de cadastrar a festa.
    {
        cout << "\nSaindo do cadastro de festas..." << endl;
    }
    else // Caso o código tenha sido encontado, continuar cadastro de festa
    {
        char confirmar;
        cout << "\n>>> CADASTRAR FESTA <<<" << endl;

        do
        {

            festa.codigo = gerarCodigoFesta();

            festa.qtdConvidados = salvarConvid();


            cout << "\nDados da festa:" << endl;
            cout << "Código: " << festa.codigo << endl;
            cout << "Quantidade de convidados: " << festa.qtdConvidados << "\n" << endl;

            cout << "\n---> Confirmar dados <---" << endl;
            cout << "C - Para confirmar" << endl;
            cout << "R - Para refazer" << endl;
            cout << "Os dados inseridos estão corretos? ";
            cin >> confirmar;
        } while (toupper(confirmar)!='C');

    }

}

unsigned int receberCodigoCliente()
{
    unsigned int codigo;
    ClienteClass verificarExistencia;
    cout << "\nInforme o código do cliente(Digite 0 para sair): ";
    do
    {
        cin >> codigo;
        verificarExistencia = ClienteClass::get(codigo);
        if(verificarExistencia.codigo==0 && codigo!=0) //Só mostrar essa mensagem se o código do cliente não estiver cadastrado, e o usuário não tiver digitado 0 para sair.
        {
            cout << "Informe um código existente(Digite 0 para sair): ";
        }
    } while (verificarExistencia.codigo==0 && codigo!=0); //Enquanto o usuário não informar o código de um cliente cadastrado, não passa a etapa. Se digitar 0 no código, ele finaliza o cadastro de festa

    if(verificarExistencia.codigo==0 && codigo==0) // Se o cliente digitou 0, a função de cadastrar festa é finalizada.
    {
        return 0;
    }
    else // Caso tenha encontrado o código nos arquivos, retornar código.
    {
        return codigo;
    }

}

unsigned int gerarCodigoFesta() //Função para gerar o código aleatório da festa
{
    srand((unsigned int)time(NULL)); //Só deve ser chamada uma única vez, para configurar o gerador de código aleatório(rand), baseado no time.
    unsigned int codigo;
    codigo = rand(); //Salvar o código usando rand, com as configurações do srand.
    return codigo;
}

int salvarConvid()
{
    int qtd;
    cout << "\nQual a quantidade de convidados? ";
    do
    {
        cin >> qtd;
        if(qtd < 0)
        {
            cout << "Números negativos são inválidos!" << endl;
            cout << "Digite uma quantidade válida: ";
        }
    } while (qtd < 0);

    return qtd;
}

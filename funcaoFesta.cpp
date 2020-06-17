#include <iostream>
#include <stdio.h>
#include "munit.h"
#include <locale.h>

using namespace std;
#include <string>
#include <time.h>
#include "FestaClass.h"
#include "ClienteClass.h"

int receberCodigoCliente();

int funcaoFesta()
{
    setlocale(LC_ALL,"portuguese"); //Adicionar caracteres especiais
    FestaClass festa; //Orientar a objeto por meio da classe

    festa.codigo_cliente = receberCodigoCliente();

    if(festa.codigo_cliente == 0) //Se o usu�rio desistiu de cadastrar a festa.
    {
        cout << "Saindo do cadastro de festas..." << endl;
    }
    else // Caso o c�digo tenha sido encontado, continuar cadastro de festa
    {
        cout << "continuando" << endl;
    }

}

int receberCodigoCliente()
{
    int codigo;
    ClienteClass verificarExistencia;
    cout << "\nInforme o c�digo do cliente(Digite 0 para sair): ";
    do
    {
        cin >> codigo;
        verificarExistencia = ClienteClass::get(codigo);
        if(verificarExistencia.codigo==0 && codigo!=0) //S� mostrar essa mensagem se o c�digo do cliente n�o estiver cadastrado, e o usu�rio n�o tiver digitado 0 para sair.
        {
            cout << "Informe um c�digo existente(Digite 0 para sair): ";
        }
    } while (verificarExistencia.codigo==0 && codigo!=0); //Enquanto o usu�rio n�o informar o c�digo de um cliente cadastrado, n�o passa a etapa. Se digitar 0 no c�digo, ele finaliza o cadastro de festa

    if(verificarExistencia.codigo==0 && codigo==0) // Se o cliente digitou 0, a fun��o de cadastrar festa � finalizada.
    {
        return 0;
    }
    else // Caso tenha encontrado o c�digo nos arquivos, retornar c�digo.
    {
        return codigo;
    }

}

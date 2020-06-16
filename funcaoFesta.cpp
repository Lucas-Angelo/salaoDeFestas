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

    if(festa.codigo_cliente == 0) //Se o usuário desistiu de cadastrar a festa.
    {
        cout << "Saindo do cadastro de festas..." << endl;
    }
    else // Caso o código tenha sido encontado, continuar cadastro de festa
    {
        cout << "continuando" << endl;
    }

}

int receberCodigoCliente()
{
    int codigo;
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

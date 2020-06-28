#ifndef CONTRATOCLASS_H
#define CONTRATOCLASS_H

#include <iostream>
#include <stdio.h>
#include "munit.h"
#include <locale.h>
#include <ctype.h>

using namespace std;

#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "helpers/ModelHelper.h"
#include "funcaoFesta.h"
#include "ClienteClass.h"
#include "FestaClass.h"
unsigned int receberCodigoClientes();
unsigned int codigoFesta(string nome);
unsigned int codigoData(string data);
int funcaoRelatorio()
{
    unsigned int receberCodigoClientes();
    int op=0;
    setlocale(LC_ALL,"portuguese");
    cout <<"\n---------------->RELATÓRIO<-------------------"  << endl;
    cout <<"\n1-Cliente\n2-Data\n3-Voltar\nDeseja pesquisar por: ";
    cin >> op;

    if(op==1)
    {
        cout << "\n------------>POR CLIENTE<------------" << endl;
        string nome;
        cout << "Digite o nome do Cliente: ";
        getline(cin >> ws, nome);
        codigoFesta(nome);
    }
    else if(op==2)
    {
        ClienteClass c;
        FestaClass f;
        cout << "\n------------>POR DATA<------------" << endl;
        string data;
        cout << "Digite a Data(dd/mm/AAAA): ";
        getline(cin >> ws, data);
        codigoData(data);
    }
    return 0;
}
unsigned int codigoFesta(string nome)
{
    int i=0;
    FestaClass f;
    ClienteClass c;

    ifstream inFile;
    inFile.open("files/client.txt");
    string line,cod_festa;

    while (getline(inFile, line))
            {
                if(ModelHelper::split(';', line, 1).find(nome) != std::string::npos)
                {
                    cod_festa = (ModelHelper::split(';',line, 0).c_str());
                }
            }

    inFile.close();
    inFile.open("files/party.txt");

    while (getline(inFile, line))
            {
                if(ModelHelper::split(';', line,7) == cod_festa)
                {
                    f.codigo = atoi(ModelHelper::split(';',line, 0).c_str());
                    f.qtdConvidados = atoi(ModelHelper::split(';',line, 1).c_str());
                    f.dt = ModelHelper::split(';',line, 2);
                    f.diaSemana = atoi(ModelHelper::split(';',line, 3).c_str());
                    f.hora_inicio = ModelHelper::split(';',line, 4);
                    f.hora_fim = ModelHelper::split(';',line, 5);
                    f.tema = ModelHelper::split(';',line, 6);
                    f.codigo_cliente = atoi(ModelHelper::split(';',line, 7).c_str());
                    cout << "-------------------------------------------------------------" << endl;
                    cout << "Código: " << f.codigo << endl;
                    cout << "Tema: " <<    f.tema  << endl;
                    cout << "Quantidade de convidados: " << f.qtdConvidados << endl;
                    cout << "Data: " << f.dt << endl;
                    cout << "Dia da semana: " << f.diaSemana << endl;
                    cout << "Hora de inicio: " << f.hora_inicio << endl;
                    cout << "Hora de termino: " <<  f.hora_fim  << endl;
                    cout << "-------------------------------------------------------------" << endl;
                    i++;
                }
            }
             if(i == 0)
                {
                cout << "------------------------\nNenhum item encontrado\n------------------------";
                }
    return f.codigo;
}

unsigned int codigoData(string data)
{
    int i=0;
    FestaClass f;
    ClienteClass c;

    ifstream inFile;
     inFile.open("files/party.txt");
    string line;

    while (getline(inFile, line))
            {
                if(ModelHelper::split(';', line,2) == data)
                {
                    f.codigo = atoi(ModelHelper::split(';',line, 0).c_str());
                    f.qtdConvidados = atoi(ModelHelper::split(';',line, 1).c_str());
                    f.dt = ModelHelper::split(';',line, 2);
                    f.diaSemana = atoi(ModelHelper::split(';',line, 3).c_str());
                    f.hora_inicio = ModelHelper::split(';',line, 4);
                    f.hora_fim = ModelHelper::split(';',line, 5);
                    f.tema = ModelHelper::split(';',line, 6);
                    f.codigo_cliente = atoi(ModelHelper::split(';',line, 7).c_str());
                    cout << "-------------------------------------------------------------" << endl;
                    cout << "Código: " << f.codigo << endl;
                    cout << "Tema: " <<    f.tema  << endl;
                    cout << "Quantidade de convidados: " << f.qtdConvidados << endl;
                    cout << "Data: " << f.dt << endl;
                    cout << "Dia da semana: " << f.diaSemana << endl;
                    cout << "Hora de inicio: " << f.hora_inicio << endl;
                    cout << "Hora de termino: " <<  f.hora_fim  << endl;
                    cout << "-------------------------------------------------------------" << endl;
                    i++;
                }
            }
                if(i == 0)
                {
                cout << "------------------------\nNenhum item encontrado\n------------------------";
                }
    return f.codigo;
}

#endif // CONTRATOCLASS_H

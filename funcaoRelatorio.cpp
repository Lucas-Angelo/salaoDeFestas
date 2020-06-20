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
int funcaoRelatorio()
{
    unsigned int receberCodigoClientes();
    int op=0;
    setlocale(LC_ALL,"portuguese");
    cout <<"\n---------------->RELATORIO<-------------------"  << endl;
    cout <<"\n1-Cliente\n2-Data\nDeseja pesquisar por: ";
    cin >> op;

    if(op==1)
    {
        cout << "\n------------>POR CLIENTE<------------" << endl;
        string nome;
        cout << "Digite o nome do Cliente: ";
        getline(cin >> ws, nome);
        ClienteClass c;
        FestaClass f;
        int i=0;
        ifstream inFile;
         // Abrir o arquivo para leitura
        inFile.open("files/client.txt");
        string line;
        // Ler linha por linha até o fim do arquivo.
        while (getline(inFile, line))
            {
                // Se encontrar o nome do cliente, quebrar a linha e definir os atributos da classe
                if(ModelHelper::split(';', line, 1).find(nome) != std::string::npos)
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
        if(i == 0) cout << "------------------------\nNenhum item encontrado\n------------------------";
    }
    else if(op==2)
    {
        ClienteClass c;
        FestaClass f;
        cout << "\n------------>POR DATA<------------" << endl;
        string nome;
        cout << "Digite a Data: ";
        getline(cin >> ws, f.dt);

        int i=0;
        ifstream inFile;
         // Abrir o arquivo para leitura
        inFile.open("files/client.txt");
        string line;
        // Ler linha por linha até o fim do arquivo.
        while (getline(inFile, line))
            {
                // Se encontrar o nome do cliente, quebrar a linha e definir os atributos da classe
                if(ModelHelper::split(';', line, 1).find(f.dt) != std::string::npos)
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
        if(i == 0) cout << "------------------------\nNenhum item encontrado\n------------------------";



    }
    return 0;
}





#endif // CONTRATOCLASS_H

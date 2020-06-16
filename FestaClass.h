#ifndef FESTACLASS_H
#define FESTACLASS_H

using namespace std;
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include "helpers/ModelHelper.h"

class FestaClass
{
    public:
        FestaClass();
        unsigned int codigo = NULL;
        int qtdConvidados;
        string dt;
        int diaSemana;
        string hora_inicio;
        string hora_fim;
        string tema;
        unsigned int codigo_cliente;
        int save() {
            ofstream file;
            file.open ("files/party.txt", std::ios_base::app);
            file << codigo << ";" << qtdConvidados << ";"  << dt << ";" << diaSemana  << ";" << hora_inicio  << ";" << hora_fim  << ";" << tema << ";" << codigo_cliente << "\n";
            file.close();
            return 1;
        }
        static FestaClass get(int cod) {
            // Abrir o arquivo para leitura
            ifstream inFile;
            inFile.open("files/party.txt");
            stringstream ss;
            ss<<cod;
            string cd;
            ss>>cd;
            string line;
            FestaClass f;
            // Ler linha por linha até o fim do arquivo.
            while (getline(inFile, line)) {
                // Se encontrar o codigo da festa, quebrar a linha e definir os atributos da classe
                if(ModelHelper::split(';', line, 0) ==  cd) {
                    f.codigo = atoi(ModelHelper::split(';',line, 0).c_str());
                    f.qtdConvidados = atoi(ModelHelper::split(';',line, 1).c_str());
                    f.dt = ModelHelper::split(';',line, 2);
                    f.diaSemana = atoi(ModelHelper::split(';',line, 3).c_str());
                    f.hora_inicio = ModelHelper::split(';',line, 4);
                    f.hora_fim = ModelHelper::split(';',line, 5);
                    f.tema = ModelHelper::split(';',line, 6);
                    f.codigo_cliente = atoi(ModelHelper::split(';',line, 7).c_str());
                }
            }
            return f;
        }
};

#endif // FESTACLASS_H

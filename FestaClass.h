#ifndef FESTACLASS_H
#define FESTACLASS_H

using namespace std;
#include <string>
#include <fstream>
#include "ModelHelper.h"

class FestaClass
{
    public:
        FestaClass();
        int codigo = NULL;
        int qtdConvidados;
        string dt;
        int diaSemana;
        string hora_inicio;
        string hora_fim;
        string tema;
        int codigo_cliente;
        int save() {
            ofstream file;
            file.open ("files/party.txt", std::ios_base::app);
            file << codigo << ";" << qtdConvidados << ";"  << dt << ";" << diaSemana  << ";" << hora_inicio  << ";" << hora_fim  << ";" << tema << ";" << codigo_cliente << "\n";
            file.close();
        }
        static FestaClass get(int cod) {
            // Abrir o arquivo para leitura
            ifstream inFile;
            inFile.open("files/party.txt");
            int codLength = to_string(cod).length();
            string line;
            FestaClass f;
            // Ler linha por linha até o fim do arquivo.
            while (getline(inFile, line)) {
                // Se encontrar o codigo da festa, quebrar a linha e definir os atributos da classe
                if(ModelHelper::split(';', line, 0) ==  to_string(cod)) {
                    f.codigo = stoi(ModelHelper::split(';',line, 0));
                    f.qtdConvidados = stoi(ModelHelper::split(';',line, 1));
                    f.dt = ModelHelper::split(';',line, 2);
                    f.diaSemana = stoi(ModelHelper::split(';',line, 3));
                    f.hora_inicio = ModelHelper::split(';',line, 4);
                    f.hora_fim = ModelHelper::split(';',line, 5);
                    f.tema = ModelHelper::split(';',line, 6);
                    f.codigo_cliente = stoi(ModelHelper::split(';',line, 7));
                }
            }
            return f;
        }
};

#endif // FESTACLASS_H

#ifndef FUNCIONARIOSCLASS_H
#define FUNCIONARIOSCLASS_H

using namespace std;
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "helpers/ModelHelper.h"

class FuncionariosClass
{
    public:
        FuncionariosClass();
        unsigned int codigo = NULL;
        string nome;
        string telefone;
        string funcao;
        float salario;
        char tipo;
        int save() {
            ofstream file;
            file.open ("files/funcionario.txt", std::ios_base::app);
            file << codigo << ";" << nome << ";"  << telefone << ";" << funcao << ";"  << salario << ";"  << tipo << "\n";
            file.close();
            return 1;
        }
        static FuncionariosClass get(int cod) {
            // Abrir o arquivo para leitura
            ifstream inFile;
            inFile.open("files/funcionario.txt");
            stringstream ss;
            ss<<cod;
            string cd;
            ss>>cd;
            string line;
            FuncionariosClass f;
            f.codigo = 0;
            // Ler linha por linha até o fim do arquivo.
            while (getline(inFile, line)) {
                // Se encontrar o codigo do funcionario, quebrar a linha e definir os atributos da classe
                if(ModelHelper::split(';', line, 0) ==  cd) {
                    f.codigo = atoi(ModelHelper::split(';',line, 0).c_str());
                    f.nome = ModelHelper::split(';',line, 1);
                    f.telefone = ModelHelper::split(';',line, 2);
                    f.funcao = ModelHelper::split(';',line, 3);
                    f.salario = atof(ModelHelper::split(';',line, 4).c_str());
                    f.tipo = ModelHelper::split(';',line, 5)[0];
                }
            }
            return f;
        }
};

#endif // FUNCIONARIOSCLASS_H

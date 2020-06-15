#ifndef FUNCIONARIOSCLASS_H
#define FUNCIONARIOSCLASS_H

using namespace std;
#include <string>
#include <fstream>
#include "helpers/ModelHelper.h"

class FuncionariosClass
{
    public:
        FuncionariosClass();
        int codigo = NULL;
        string nome;
        unsigned long telefone;
        string funcao;
        float salario;
        char tipo;
        int save() {
            ofstream file;
            file.open ("files/funcionario.txt", std::ios_base::app);
            file << codigo << ";" << nome << ";"  << telefone << ";" << funcao << ";"  << salario << ";"  << tipo << "\n";
            file.close();
        }
        static FuncionariosClass get(int cod) {
            // Abrir o arquivo para leitura
            ifstream inFile;
            inFile.open("files/funcionario.txt");
            int codLength = to_string(cod).length();
            string line;
            FuncionariosClass f;
            // Ler linha por linha até o fim do arquivo.
            while (getline(inFile, line)) {
                // Se encontrar o codigo do funcionario, quebrar a linha e definir os atributos da classe
                if(ModelHelper::split(';', line, 0) ==  to_string(cod)) {
                    f.codigo = stoi(ModelHelper::split(';',line, 0));
                    f.nome = ModelHelper::split(';',line, 1);
                    f.telefone = stoi(ModelHelper::split(';',line, 2));
                    f.funcao = ModelHelper::split(';',line, 3);
                    f.salario = stof(ModelHelper::split(';',line, 4));
                    f.tipo = ModelHelper::split(';',line, 5)[0];
                }
            }
            return f;
        }
};

#endif // FUNCIONARIOSCLASS_H

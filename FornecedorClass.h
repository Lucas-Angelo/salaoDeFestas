#ifndef FORNECEDORCLASS_H
#define FORNECEDORCLASS_H

using namespace std;
#include <string>
#include <fstream>
#include "ModelHelper.h"

class FornecedorClass
{
    public:
        FornecedorClass();
        int codigo = NULL;
        string nome;
        string telefone;
        string produto;
        int save() {
            ofstream file;
            file.open ("files/fornecedor.txt", std::ios_base::app);
            file << codigo << ";" << nome << ";"  << telefone << ";" << produto << "\n";
            file.close();
        }
        static FornecedorClass get(int cod) {
            // Abrir o arquivo para leitura
            ifstream inFile;
            inFile.open("files/fornecedor.txt");
            int codLength = to_string(cod).length();
            string line;
            FornecedorClass f;
            // Ler linha por linha até o fim do arquivo.
            while (getline(inFile, line)) {
                // Se encontrar o codigo do fornecedor, quebrar a linha e definir os atributos da classe
                if(ModelHelper::split(';', line, 0) ==  to_string(cod)) {
                    f.codigo = stoi(ModelHelper::split(';',line, 0));
                    f.nome = ModelHelper::split(';',line, 1);
                    f.telefone = ModelHelper::split(';',line, 2);
                    f.produto = ModelHelper::split(';',line, 3);
                }
            }
            return f;
        }
};

#endif // FORNECEDORCLASS_H

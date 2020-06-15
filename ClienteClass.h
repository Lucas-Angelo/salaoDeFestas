#ifndef CLIENTECLASS_H
#define CLIENTECLASS_H

using namespace std;
#include <string>
#include <fstream>
#include "helpers/ModelHelper.h"

// http://prntscr.com/sjryho
class ClienteClass
{
    public: ClienteClass();
        int codigo  = NULL;
        string nome;
        string endereco;
        unsigned long telefone;
        string dtNascimento;
        int save() {
            ofstream file;
            file.open ("files/client.txt", std::ios_base::app);
            file << codigo << ";" << nome << ";" << endereco << ";" << telefone << ";" << dtNascimento << "\n";
            file.close();
        }
        static ClienteClass get(int cod) {
            // Abrir o arquivo para leitura
            ifstream inFile;
            inFile.open("files/client.txt");
            int codLength = to_string(cod).length();
            string line;
            ClienteClass c;
            // Ler linha por linha até o fim do arquivo.
            while (getline(inFile, line)) {
                // Se encontrar o codigo do cliente, quebrar a linha e definir os atributos da classe
                if(ModelHelper::split(';', line, 0) ==  to_string(cod)) {
                    c.codigo = stoi(ModelHelper::split(';',line, 0));
                    c.nome = ModelHelper::split(';',line, 1);
                    c.endereco = ModelHelper::split(';',line, 2);
                    c.telefone = stoi(ModelHelper::split(';',line, 3));
                    c.dtNascimento = ModelHelper::split(';',line, 4);
                }
            }
            return c;
        }

};

#endif // CLIENTECLASS_H

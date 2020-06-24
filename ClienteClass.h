#ifndef CLIENTECLASS_H
#define CLIENTECLASS_H

using namespace std;
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include "helpers/ModelHelper.h"
#include <vector>
// http://prntscr.com/sjryho
class ClienteClass
{
    public: ClienteClass();
        unsigned int codigo  = NULL;
        string nome;
        string endereco;
        unsigned long long int telefone;
        string dtNascimento;
        int save() {
            ofstream file;
            file.open ("files/client.txt", std::ios_base::app);
            file << codigo << ";" << nome << ";" << endereco << ";" << telefone << ";" << dtNascimento << "\n";
            file.close();
            return 1;
        }
        static ClienteClass get(int cod) {
            // Abrir o arquivo para leitura
            ifstream inFile;
            inFile.open("files/client.txt");
            stringstream ss;
            ss<<cod;
            string cd;
            ss>>cd;
            string line;
            ClienteClass c;
            // Ler linha por linha até o fim do arquivo.
            while (getline(inFile, line)) {
                // Se encontrar o codigo do cliente, quebrar a linha e definir os atributos da classe
                if(ModelHelper::split(';', line, 0) ==  cd) {
                    c.codigo = atoi(ModelHelper::split(';',line, 0).c_str());
                    c.nome = ModelHelper::split(';',line, 1);
                    c.endereco = ModelHelper::split(';',line, 2);
                    c.telefone = atoi(ModelHelper::split(';',line, 3).c_str());
                    c.dtNascimento = ModelHelper::split(';',line, 4);
                }
            }
            return c;
        }
        static vector<ClienteClass> getByName(string name) {
            ifstream inFile;
            string line;
            vector<ClienteClass> clientes;
            inFile.open("files/client.txt");
            int i = 0, j=0;
            while (getline(inFile, line)) {
                if(ModelHelper::split(';', line, 1).find(name) != std::string::npos) {
                    ClienteClass c;
                    c.codigo = atoi(ModelHelper::split(';',line, 0).c_str());
                    c.nome = ModelHelper::split(';',line, 1);
                    c.endereco = ModelHelper::split(';',line, 2);
                    c.telefone = atoi(ModelHelper::split(';',line, 3).c_str());
                    c.dtNascimento = ModelHelper::split(';',line, 4);
                    clientes.push_back(c);
                }
            }
            return clientes;
        }
};

#endif // CLIENTECLASS_H

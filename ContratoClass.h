#ifndef CONTRATOCLASS_H
#define CONTRATOCLASS_H

using namespace std;
#include <fstream>
#include "helpers/ModelHelper.h"


class ContratoClass
{
    public:
        ContratoClass();
        int codigo = NULL;
        float valor_total;
        float desconto;
        float valor_final;
        char formaPagamento;
        char status;
        int codigo_festa;
        int save() {
            ofstream file;
            file.open ("files/contract.txt", std::ios_base::app);
            file << codigo << ";" << valor_total << ";"  << desconto << ";" << valor_final  << ";" << formaPagamento  << ";" << status  << ";" << codigo_festa << "\n";
            file.close();
        }
        static ContratoClass get(int cod) {
            // Abrir o arquivo para leitura
            ifstream inFile;
            inFile.open("files/contract.txt");
            int codLength = to_string(cod).length();
            string line;
            ContratoClass c;
            // Ler linha por linha até o fim do arquivo.
            while (getline(inFile, line)) {
                // Se encontrar o codigo do contrato, quebrar a linha e definir os atributos da classe
                if(ModelHelper::split(';', line, 0) ==  to_string(cod)) {
                    c.codigo = stoi(ModelHelper::split(';',line, 0));
                    c.valor_total = stof(ModelHelper::split(';',line, 1));
                    c.desconto = stof(ModelHelper::split(';',line, 2));
                    c.valor_final = stof(ModelHelper::split(';',line, 3));
                    c.formaPagamento = ModelHelper::split(';',line, 4)[0];
                    c.status = ModelHelper::split(';',line, 5)[0];
                    c.codigo_festa = stoi(ModelHelper::split(';',line, 6));
                }
            }
            return c;
        }
};

#endif // CONTRATOCLASS_H

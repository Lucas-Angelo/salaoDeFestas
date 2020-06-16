#ifndef CONTRATOCLASS_H
#define CONTRATOCLASS_H

using namespace std;
#include <fstream>
#include <sstream>
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
            return 1;
        }
        static ContratoClass get(int cod) {
            // Abrir o arquivo para leitura
            ifstream inFile;
            inFile.open("files/contract.txt");
            stringstream ss;
            ss<<cod;
            string cd;
            ss>>cd;
            int codLength = cd.length();
            string line;
            ContratoClass c;
            // Ler linha por linha até o fim do arquivo.
            while (getline(inFile, line)) {
                // Se encontrar o codigo do contrato, quebrar a linha e definir os atributos da classe
                if(ModelHelper::split(';', line, 0) == cd) {
                    c.codigo = atoi(ModelHelper::split(';',line, 0).c_str());
                    c.valor_total = atof(ModelHelper::split(';',line, 1).c_str());
                    c.desconto = atof(ModelHelper::split(';',line, 2).c_str());
                    c.valor_final = atof(ModelHelper::split(';',line, 3).c_str());
                    c.formaPagamento = ModelHelper::split(';',line, 4)[0];
                    c.status = ModelHelper::split(';',line, 5)[0];
                    c.codigo_festa = atoi(ModelHelper::split(';',line, 6).c_str());
                }
            }
            return c;
        }
};

#endif // CONTRATOCLASS_H

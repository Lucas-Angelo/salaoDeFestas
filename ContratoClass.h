#ifndef CONTRATOCLASS_H
#define CONTRATOCLASS_H

using namespace std;
#include <fstream>

class ContratoClass
{
    public:
        ContratoClass();
        int codigo;
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
};

#endif // CONTRATOCLASS_H

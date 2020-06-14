#ifndef FORNECEDORCLASS_H
#define FORNECEDORCLASS_H

using namespace std;
#include <string>
#include <fstream>

class FornecedorClass
{
    public:
        FornecedorClass();
        int codigo;
        string nome;
        string telefone;
        string produto;
        int save() {
            ofstream file;
            file.open ("files/fornecedor.txt", std::ios_base::app);
            file << codigo << ";" << nome << ";"  << telefone << ";" << produto << "\n";
            file.close();
        }
};

#endif // FORNECEDORCLASS_H

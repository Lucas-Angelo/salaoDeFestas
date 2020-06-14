#ifndef FUNCIONARIOSCLASS_H
#define FUNCIONARIOSCLASS_H

using namespace std;
#include <string>
#include <fstream>

class FuncionariosClass
{
    public:
        FuncionariosClass();
        int codigo;
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
};

#endif // FUNCIONARIOSCLASS_H

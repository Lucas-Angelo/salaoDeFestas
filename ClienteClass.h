#ifndef CLIENTECLASS_H
#define CLIENTECLASS_H

using namespace std;
#include <string>
#include <fstream>

// http://prntscr.com/sjryho
class ClienteClass
{
    public: ClienteClass();
        int codigo;
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
};

#endif // CLIENTECLASS_H

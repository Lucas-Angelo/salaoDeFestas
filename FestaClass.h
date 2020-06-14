#ifndef FESTACLASS_H
#define FESTACLASS_H

using namespace std;
#include <string>
#include <fstream>

class FestaClass
{
    public:
        FestaClass();
        int codigo;
        int qtdConvidados;
        string dt;
        int diaSemana;
        string hora_inicio;
        string hora_fim;
        string tema;
        int codigo_cliente;
        int save() {
            ofstream file;
            file.open ("files/party.txt", std::ios_base::app);
            file << codigo << ";" << qtdConvidados << ";"  << dt << ";" << diaSemana  << ";" << hora_inicio  << ";" << hora_fim  << ";" << tema << ";" << codigo_cliente << "\n";
            file.close();
        }
};

#endif // FESTACLASS_H

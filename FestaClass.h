#ifndef FESTACLASS_H
#define FESTACLASS_H

using namespace std;
#include <string>

class FestaClass
{
    public:
        FestaClass();
        int codigo;
        int qtdConvidados;
        string dt;
        int diaSemana;
        int hora_inicio;
        int minuto_inicio;
        int hora_fim;
        int minuto_fim;
        string tema;
        int codigo_cliente;
};

#endif // FESTACLASS_H

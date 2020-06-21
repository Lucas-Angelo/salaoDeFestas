#ifndef MODELHELPER_H
#define MODELHELPER_H

using namespace std;
#include <string>
#include <time.h>

class ModelHelper
{
    public:
        ModelHelper();
        static string split(char separator, string line, int index) {
            string txt = "";
            int indexLocal = 0;
            for(int i=0; i<line.length(); i++) {
                if(line[i] == ';') {
                    if(line[i]  == indexLocal) break;
                    indexLocal++;
                }
                else if(indexLocal == index)
                    txt += line[i];
            }
            return txt;
        }
        static unsigned int generateID() {
            srand((unsigned int)time(NULL)); //Só deve ser chamada uma única vez, para configurar o gerador de código aleatório(rand), baseado no time.
            unsigned int codigo;
            codigo = rand(); //Salvar o código usando rand, com as configurações do srand.
            return codigo;
        }
};

#endif // MODELHELPER_H

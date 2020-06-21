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
            srand((unsigned int)time(NULL)); //S� deve ser chamada uma �nica vez, para configurar o gerador de c�digo aleat�rio(rand), baseado no time.
            unsigned int codigo;
            codigo = rand(); //Salvar o c�digo usando rand, com as configura��es do srand.
            return codigo;
        }
};

#endif // MODELHELPER_H

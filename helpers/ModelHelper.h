#ifndef MODELHELPER_H
#define MODELHELPER_H

using namespace std;
#include <string>

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
};

#endif // MODELHELPER_H

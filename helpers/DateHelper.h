#ifndef DATEHELPER_H
#define DATEHELPER_H

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

class DateHelper
{
    public:
        DateHelper();
        string inputDate(){
            int day=1, month=1, year=1000, is_leap = 0, is_valid = 1;
            do {
                cin.seekg(0,ios::end);
                cin.ignore(0xFFFF, '\n');
                cin.clear();
                is_valid = 1;
                cin >> day;
                if (cin.fail()) { //entra aqui se houver algum erro
                    cin.ignore(0xFFFF, '\n');
                    cin.clear();
                }
                // Validando se o inicio da data (o dia) possui / no final
               if (cin.get() != '/')
                    is_valid = 0;
                cin >> month;
                if (cin.fail()) { //entra aqui se houver algum erro
                    cin.ignore(0xFFFF, '\n');
                    cin.clear();
                }
                 // Validando se o inicio da data (o mes) possui / no final
                if (cin.get() != '/')
                    is_valid = 0;

                cin >> year;
                if (cin.fail()) { //entra aqui se houver algum erro
                    cin.ignore(0xFFFF, '\n');
                    cin.clear();
                }
               if(year < 1000 || year > 9999)
                    is_valid = 0;
                // Validar se o ano for bissexo
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                    is_leap = 1;

               if(month < 0 || month > 12)
                    is_valid = 0;
                else {
                    // Validar se o dia é válido baseado no mes, e no ano caso bissexto.
                    if (month == 2) {
                        if (is_leap && day == 29)
                            is_valid = 1;
                        else if (day > 28)
                            is_valid = 0;
                    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                        if (day > 30 || day < 1)
                         is_valid = 0;
                    } else if(day > 31  || day < 1)
                        is_valid = 0;
                }
                if(is_valid == 0) {
                     cout << "Data Invalida! Digite no formato dd/mm/yyyy" << endl << "Digite a data: ";
                }

            } while(is_valid == 0);

            stringstream ss, ss2, ss3;
            string sd,sm,sy;
            ss<<day;
            ss>>sd;
            ss2<<month;
            ss2>>sm;
            ss3<<year;
            ss3>>sy;
            if(sm.length() == 1) sm = '0' + sm;
            if(sd.length() == 1) sd = '0' + sd;
            return sd + "/" + sm + "/" + sy;
        }
        string inputTime(){
            int hour, minute, valid;
            do {
                cin.seekg(0,ios::end);
                cin.clear();
                valid = 1;
                cin >> hour;
                if (cin.get() != ':')
                    valid = 0;
                cin >> minute;

                if((hour < 0 || hour > 24) || (minute < 0 || minute > 60))
                    valid = 0;

                if(valid == 0)
                    cout << "Hora Invalida! Digite no formato HH:mm" << endl << "Digite a hora: ";
            } while(valid == 0);

            stringstream ss1, ss2;
            string sh, sm;
            ss1<<hour;
            ss1>>sh;
            ss2<<minute;
            ss2>>sm;
            if(hour < 10) sh = '0' + sh;
            if(minute < 10) sm = '0'  + sm;
            if(minute % 10 == 0) sm = sm + '0';
            if(hour % 10 == 0) hour = hour + '0';
            return sh + ":" + sm;
        }

    protected:

    private:
};

#endif // DATEHELPER_H

#ifndef DATEHELPER_H
#define DATEHELPER_H

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdlib.h>

class DateHelper
{
    public:
        DateHelper();
        string inputDate(){
            int day, month, year, is_leap = 0, is_valid = 1;
            do {
                is_valid = 1;
                cin >> day;
                // Validando se o inicio da data (o dia) possui / no final
               if (cin.get() != '/')
                    is_valid = 0;

                cin >> month;
                 // Validando se o inicio da data (o mes) possui / no final
                if (cin.get() != '/')
                    is_valid = 0;

                cin >> year;
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
                if(is_valid == 0)
                    cout << "Data Invalida! Digite no formato dd/mm/yyyy" << endl;
            } while(is_valid == 0);

            //return to_string(day)  + "/" + to_string(month) + "/" + to_string(year);
            return "";
        }
        string inputTime(){
            int hour, minute, valid;
            do {
                valid = 1;
                cin >> hour;
                if (cin.get() != ':')
                    valid = 0;
                cin >> minute;

                if((hour < 0 || hour > 24) || (minute < 0 || minute > 60))
                    valid = 0;

                if(valid == 0)
                    cout << "Hora Invalida! Digite no formato HH:mm" << endl;
            } while(valid == 0);
            return "S";
        }

    protected:

    private:
};

#endif // DATEHELPER_H

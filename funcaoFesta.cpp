#include <iostream>
#include <locale.h>
#include <string>
#include <time.h>

using namespace std;

#include "FestaClass.h"
#include "ClienteClass.h"
#include "helpers/DateHelper.h"
#include "funcaoContrato.h"
#include "munit.h"
#include <vector>


unsigned int receberCodigoCliente();
int salvarConvid();
string salvarData();
int salvarDia(string date);
string salvarHoraInicio();
string salvarHoraFim();
int verificarHorarios(string horaInicio, string horaFim);
string salvarHoraInicioSabado();
string salvarHoraFimSabado();
string salvarTema();
int verificarCoincidencia(string data, string horaInicio, string horaFim);


int funcaoFesta()
{
    setlocale(LC_ALL,"portuguese"); //Adicionar caracteres especiais
    FestaClass festa; //Orientar a objeto por meio da classe

    festa.codigo_cliente = receberCodigoCliente();

    if(festa.codigo_cliente == 0) //Se o usu√°rio desistiu de cadastrar a festa.
        cout << "\nSaindo do cadastro de festas..." << endl;
    else  {// Caso o c√≥digo tenha sido encontado, continuar cadastro de festa
        char confirmar;
        cout << "\n>>> CADASTRAR FESTA <<<" << endl;

        int conferir=0;
        do {

            festa.qtdConvidados = salvarConvid();

            if(festa.diaSemana!=7)
            do {
                festa.dt = salvarData();
                festa.diaSemana = salvarDia(festa.dt);

                if(festa.diaSemana!=7) {
                    do {
                        festa.hora_inicio = salvarHoraInicio();
                        festa.hora_fim = salvarHoraFim();

                        conferir = verificarHorarios(festa.hora_inicio, festa.hora_fim);

                        if(conferir==0)
                            cout << "A festa pode ter no m·ximo 4 horas de duraÁ„o!" << endl;

                        if(festa.hora_inicio == festa.hora_fim) {
                            cout << "A festa n„o pode comeÁar e acabar na mesma hora! ";
                            conferir = 0;
                        }
                    } while (conferir==0);
                } else {
                    do {
                        festa.hora_inicio = salvarHoraInicioSabado();
                        festa.hora_fim = salvarHoraFimSabado();

                        conferir = verificarHorarios(festa.hora_inicio, festa.hora_fim);

                        if(festa.hora_inicio=="Negado" || festa.hora_fim=="Negado")
                            cout << "Os ˙nicos hor·rios aos s·bados s„o de 12 ‡s 16 e 18 ‡s 22." << endl;

                        if(conferir==0)
                            cout << "A festa pode ter no m·ximo 4 horas de duraÁ„o!" << endl;

                    } while (festa.hora_inicio=="Negado" || festa.hora_fim=="Negado" || conferir==0);
                }

                if(verificarCoincidencia(festa.dt, festa.hora_inicio, festa.hora_fim) != 1)
                {
                    cout << "Desculpe, j· existe uma festa cadastrada nesse hor·rio." << endl << "Por favor, tente novamente." << endl;
                }

            } while (verificarCoincidencia(festa.dt, festa.hora_inicio, festa.hora_fim) != 1); //Verificar se hor√°rios coincidem

            festa.tema = salvarTema();
            string weekNames[7] = { "Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado" };

            cout << "\nDados da festa:" << endl;
            cout << "CÛdigo: " << festa.codigo << endl;
            cout << "Quantidade de convidados: " << festa.qtdConvidados << endl;
            cout << "Data da festa: " << festa.dt << endl;
            cout << "Dia da festa: " << weekNames[festa.diaSemana - 1] << endl;
            cout << "Hora do inÌcio: " << festa.hora_inicio << endl;
            cout << "Hora do fim: " << festa.hora_fim << endl;
            cout << "Tema: " << festa.tema << "\n" << endl;

            cout << "\n---> Confirmar dados <---" << endl;
            cout << "C - Para confirmar" << endl;
            cout << "R - Para refazer" << endl;
            cout << "Os dados inseridos est„o corretos? ";
            cin >> confirmar;
        } while (toupper(confirmar)!='C');
        festa.save();
        funcaoContrato(festa);

    }

}

unsigned int receberCodigoCliente() {
    string nome;
    int i, codigo;
    cout << "\nInforme o nome do cliente(Digite 0 para sair): ";
    getline(cin >> ws,nome);
    if(nome == "0") return 0;
    vector<ClienteClass> c = ClienteClass::getByName(nome);
    for (i=0; i<c.size(); i++) {
        cout << "-------------------------------------------------------------" << endl;
        cout << "CÛdigo: " << c[i].codigo << endl;
        cout << "Nome: " << c[i].nome << endl;
        cout << "EndereÁo: " << c[i].endereco << endl;
        cout << "Data de Nascimento: " << c[i].dtNascimento << endl;
        cout << "Telefone: " << c[i].telefone << endl;
        cout << "-------------------------------------------------------------" << endl;
    }

    if(i == 1)
        return c[0].codigo;
    else if(i == 0) {
        cout << "Nenhum resultado encontrado!" << endl;
        return receberCodigoCliente();
    } else {
        cout << "Multiplos usu·rios encontrados." << endl << "Digite o cÛdigo do cliente desejado: ";
        cin >> codigo;
        ClienteClass cli = ClienteClass::get(codigo);
        if(cli.codigo == 0) {
            cout << "CÛdigo Inv·lido" << endl;
            return receberCodigoCliente();
        } else
            return cli.codigo;
    }
}

int salvarConvid() //funÁ„o para receber a quantidade de convidados
{
    int qtd;
    cout << "\nQual a quantidade de convidados? ";
    do
    {
        cin >> qtd;
        if(qtd <= 0)
        {
            cout << "N˙meros negativos ou nulos s„o inv·lidos!" << endl;
            cout << "Digite uma quantidade v·lida: ";
        }
        if(qtd > 100)
        {
            cout << "O m·ximo de convidados s„o 100." << endl;
            cout << "Digite uma quantidade v·lido: ";
        }
    } while (qtd <= 0 || qtd > 100);

    return qtd;
}

string salvarData() {
    DateHelper dh; //Chamar classe DataHelper, que verifica se a data inserida È v·lida
    cout << "Formato de data aceit·vel: dd/mm/aaaa" << endl;
    cout << "Digite a data: ";
    string data = dh.inputDate(); //Equivale ao cin da data, chamando a funÁ„o para verificar se √© v√°lida
    return data;
}

int salvarDia(string date) {
    int d = atoi(date.substr(0, 2).c_str()); //22/06/2020
    int m = atoi(date.substr(3, 2).c_str());
    int y = atoi(date.substr(6, 4).c_str());

	int year = 1000, isLeap = 0, daysFromStart = 0, weekday = 3 ,i;
	while(year <= y) {
		isLeap = 0;
		if(weekday > 6)
			weekday = abs(7 - weekday);
		if((year % 4==0 && year % 100 != 0) || year % 400 == 0) { //Leap Year
			weekday += 2;
			isLeap = 1;
		} else //Normal Year
			weekday++;
		year++;
	}
	if(isLeap == 1) weekday--;
	for(i=0; i< m - 1;i++) {
		if(i == 1) daysFromStart += (isLeap == 1) ? 29: 28;
		else if(i == 3 || i == 5 || i == 8 || i == 10) daysFromStart += 30;
		else daysFromStart += 31;
	}
	daysFromStart += d-2;
	for(i = 0; i<daysFromStart; i++)
		weekday = (weekday == 6)? 0: weekday + 1;
	return  (weekday + 1);
}

string salvarHoraInicio()
{
    DateHelper tm;
    cout << "Formato de hor·rio aceit·vel: HH:mm" << endl;
    cout << "Digite o hor·rio do inÌcio: ";
    string hora = tm.inputTime(); //Equivale ao cin da hora de inicio, chamando a funÁ„o para verificar se √© v√°lido

    return hora;
}

string salvarHoraFim()
{
    DateHelper tm;
    cout << "Digite o hor·rio do fim: ";
    string hora = tm.inputTime(); //Equivale ao cin da hora de fim, chamando a funÁ„o para verificar se √© v√°lido

    return hora;
}

int verificarHorarios(string horaInicio, string horaFim)
{
    //inÌcio do sistema de verificar se a festa tem no m·ximo 4 horas de duraÁ„o
    string inicioHora, inicioMinuto;
    string fimHora, fimMinuto;

    inicioHora = horaInicio.substr(0,2); //Salvar a hora de inicio
    inicioMinuto = horaInicio.substr(3,2); //E salvar os minutos que inicia tamb√©m

    fimHora = horaFim.substr(0,2); //Salvar a hora de fim
    fimMinuto = horaFim.substr(3,2);//E salvar os minutos que finaliza tamb√©m

    int somaInicio=0, somaFim=0;

    somaInicio = (atoi(inicioHora.c_str()) * 60) + atoi(inicioMinuto.c_str()); //Agora converter as strings de horas e minutos de inÌcio, em ints. E transformar as horas em minutos.
    somaFim = (atoi(fimHora.c_str()) * 60) + atoi(fimMinuto.c_str()); //Mesma convers√£o e transforma√ß√£o para as horas e minutos de fim.
    //Fim do sistema de verificar se a festa tem no m·ximo 4 horas de duraÁ„o

    if((somaFim-somaInicio)<=240 && atoi(inicioHora.c_str()) < atoi(fimHora.c_str())) //Se a diferenÁa de minutos do inÌcio da festa, para o final, for menor que 240min(4 horas), festa aceita.
        return 1;
    else //Festa n√£o aceita, ultrapassou limite de 4 horas.
        return 0;

}

string salvarHoraInicioSabado()
{
    string hora;
    int verificarSabado=0;

    DateHelper tm;
    cout << "Digite o hor·rio do inicio: ";
    hora = tm.inputTime(); //Equivale ao cin da hora de fim, chamando a funÁ„o para verificar se √© v√°lido

    int horaInicioInt = horaInicioInt=atoi(hora.c_str());
    if(horaInicioInt!=12 && horaInicioInt!=13 && horaInicioInt!=14 && horaInicioInt!=15 && horaInicioInt!=16)
    {
        return "Negado";
    }
    else
    {
        return hora;
    }
}

string salvarHoraFimSabado()
{
    string hora;

    DateHelper tm;
    cout << "Digite o hor·rio do fim: ";
    hora = tm.inputTime(); //Equivale ao cin da hora de fim, chamando a funÁ„o para verificar se √© v√°lido

    int horaFimInt = horaFimInt=atoi(hora.c_str());
    if(horaFimInt!=12 && horaFimInt!=13 && horaFimInt!=14 && horaFimInt!=15 && horaFimInt!=16)
    {
        return "Negado";
    }
    else
    {
        return hora;
    }
}

string salvarTema()
{
    string tema;
    cout << "Qual o tema? ";
    getline(cin >> ws,tema);

    return tema;
}

int verificarCoincidencia(string data, string horaInicio, string horaFim)
{
    int inicioHora, inicioMinuto, fimHora, fimMinuto;

    inicioHora = atoi(horaInicio.substr(0,2).c_str()); //Salvar a hora de inicio
    inicioMinuto = atoi(horaInicio.substr(3,2).c_str()); //E salvar os minutos que inicia tamb√©m

    fimHora = atoi(horaFim.substr(0,2).c_str()); //Salvar a hora de fim
    fimMinuto = atoi(horaFim.substr(3,2).c_str());//E salvar os minutos que finaliza tamb√©m

    int resposta = 1;
    ifstream inFile;
    inFile.open("files/party.txt");
    string line;
    FestaClass f;
    while (getline(inFile, line))  {
        if(ModelHelper::split(';', line, 2) ==  data) {

            int inicioHoraFile, inicioMinutoFile, fimHoraFile, fimMinutoFile;

            inicioHoraFile = atoi((ModelHelper::split(';',line, 4)).substr(0,2).c_str());
            fimHoraFile = atoi((ModelHelper::split(';',line, 5)).substr(0,2).c_str());

            if(inicioHora < inicioHoraFile && fimHora < fimHoraFile && fimHora < inicioHoraFile) // A hora inicial passada È antes do inicio da festa e a hora final da festa È antes do inicio e do fim da festa, ent„o LIBERADA
                continue;
            else if((inicioHora > inicioHoraFile && inicioHora < fimHoraFile) || (fimHora > inicioHoraFile && fimHora < fimHoraFile)) // Festa comeÁa ou termina entre os hor·rios de outra festa NEGADO
                return 0;
            else { // Festa inicia na mesma hora que outra acaba, assim verificamos os minutos
                inicioMinutoFile = atoi((ModelHelper::split(';',line, 4)).substr(3).c_str());
                fimMinutoFile = atoi((ModelHelper::split(';',line, 5)).substr(3).c_str());

                if((fimMinutoFile == inicioMinuto || inicioMinuto > fimMinutoFile) && fimHoraFile == inicioHora) // Festa inicia, assim que a ultima termina
                    continue;
                else return 0;

                cout << inicioMinutoFile << endl << fimMinutoFile << endl << inicioMinuto << endl << fimMinuto;
            }
        }
    }

    return resposta;

}

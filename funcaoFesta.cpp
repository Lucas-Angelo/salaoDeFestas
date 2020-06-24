#include <iostream>
#include <locale.h>
#include <string>
#include <time.h>

using namespace std;

#include "FestaClass.h"
#include "ClienteClass.h"
#include "helpers/DateHelper.h"

#include "munit.h"


unsigned int receberCodigoCliente();
unsigned int gerarCodigoFesta();
int salvarConvid();
string salvarData();
int salvarDia();
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

    if(festa.codigo_cliente == 0) //Se o usu�rio desistiu de cadastrar a festa.
    {
        cout << "\nSaindo do cadastro de festas..." << endl;
    }
    else // Caso o c�digo tenha sido encontado, continuar cadastro de festa
    {
        char confirmar;
        cout << "\n>>> CADASTRAR FESTA <<<" << endl;

        int conferir=0;
        do
        {

            festa.codigo = gerarCodigoFesta();

            festa.qtdConvidados = salvarConvid();

            do
            {

                festa.dt = salvarData();

                festa.diaSemana = salvarDia();

                if(festa.diaSemana!=7)
                do
                {
                    festa.hora_inicio = salvarHoraInicio();
                    festa.hora_fim = salvarHoraFim();

                    conferir = verificarHorarios(festa.hora_inicio, festa.hora_fim);
                    if(conferir==0)
                    {
                        cout << "A festa pode ter no m�ximo 4 horas de dura��o!" << endl;
                    }
                } while (conferir==0);
                else
                {
                    do
                    {
                        festa.hora_inicio = salvarHoraInicioSabado();
                        festa.hora_fim = salvarHoraFimSabado();

                        conferir = verificarHorarios(festa.hora_inicio, festa.hora_fim);

                        if(festa.hora_inicio=="Negado" || festa.hora_fim=="Negado")
                        {
                            cout << "Os �nicos hor�rios aos s�bados s�o de 12 �s 16 e 18 �s 22." << endl;
                        }

                        if(conferir==0)
                        {
                            cout << "A festa pode ter no m�ximo 4 horas de dura��o!" << endl;
                        }

                    } while (festa.hora_inicio=="Negado" || festa.hora_fim=="Negado" || conferir==0);
                }

                if(verificarCoincidencia(festa.dt, festa.hora_inicio, festa.hora_fim) != 1)
                {
                    cout << "Desculpe, j� existe uma festa cadastrada nesse hor�rio." << endl << "Por favor, tente novamente." << endl;
                }

            } while (verificarCoincidencia(festa.dt, festa.hora_inicio, festa.hora_fim) != 1); //Verificar se hor�rios coincidem

            festa.tema = salvarTema();


            cout << "\nDados da festa:" << endl;
            cout << "C�digo: " << festa.codigo << endl;
            cout << "Quantidade de convidados: " << festa.qtdConvidados << endl;
            cout << "Data da festa: " << festa.dt << endl;
            cout << "Dia da festa: " << festa.diaSemana << endl;
            cout << "Hora do in�cio: " << festa.hora_inicio << endl;
            cout << "Hora do fim: " << festa.hora_fim << endl;
            cout << "Tema: " << festa.tema << "\n" << endl;

            cout << "\n---> Confirmar dados <---" << endl;
            cout << "C - Para confirmar" << endl;
            cout << "R - Para refazer" << endl;
            cout << "Os dados inseridos est�o corretos? ";
            cin >> confirmar;
        } while (toupper(confirmar)!='C');

        festa.save();

    }

}

unsigned int receberCodigoCliente()
{
    unsigned int codigo;
    ClienteClass verificarExistencia;
    cout << "\nInforme o c�digo do cliente(Digite 0 para sair): ";
    do
    {
        cin >> codigo;
        verificarExistencia = ClienteClass::get(codigo);
        if(verificarExistencia.codigo==0 && codigo!=0) //S� mostrar essa mensagem se o c�digo do cliente n�o estiver cadastrado, e o usu�rio n�o tiver digitado 0 para sair.
        {
            cout << "Informe um c�digo existente(Digite 0 para sair): ";
        }
    } while (verificarExistencia.codigo==0 && codigo!=0); //Enquanto o usu�rio n�o informar o c�digo de um cliente cadastrado, n�o passa a etapa. Se digitar 0 no c�digo, ele finaliza o cadastro de festa

    if(verificarExistencia.codigo==0 && codigo==0) // Se o cliente digitou 0, a fun��o de cadastrar festa � finalizada.
    {
        return 0;
    }
    else // Caso tenha encontrado o c�digo nos arquivos, retornar c�digo.
    {
        return codigo;
    }

}

unsigned int gerarCodigoFesta() //Fun��o para gerar o c�digo aleat�rio da festa
{
    srand((unsigned int)time(NULL)); //S� deve ser chamada uma �nica vez, para configurar o gerador de c�digo aleat�rio(rand), baseado no time.
    unsigned int codigo;
    codigo = rand(); //Salvar o c�digo usando rand, com as configura��es do srand.
    return codigo;
}

int salvarConvid() //Fun��o para receber a quantidade de convidados
{
    int qtd;
    cout << "\nQual a quantidade de convidados? ";
    do
    {
        cin >> qtd;
        if(qtd < 0)
        {
            cout << "N�meros negativos s�o inv�lidos!" << endl;
            cout << "Digite uma quantidade v�lida: ";
        }
        if(qtd < 100)
        {
            cout << "O m�ximo de convidados s�o 100." << endl;
            cout << "Digite uma quantidade v�lida: ";
        }
    } while (qtd <= 0 || qtd > 100);

    return qtd;
}

string salvarData()
{
    DateHelper dh; //Chamar classe DataHelper, que verifica se a data inserida � v�lida
    cout << "Formato de data aceit�vel: dd/mm/aaaa" << endl;
    cout << "Digite a data: ";
    string data = dh.inputDate(); //Equivale ao cin da data, chamando a fun��o para verificar se � v�lida
    return data;
}

int salvarDia()
{
    int numeroDia;

    cout << "Menu de op��es para dia da semana: " << endl;
    cout << "1 - Para Domingo" << endl;
    cout << "2 - Para Segunda-feira" << endl;
    cout << "3 - Para Ter�a-feira" << endl;
    cout << "4 - Para Quarta-feira" << endl;
    cout << "5 - Para Quinta-feira" << endl;
    cout << "6 - Para Sexta-feira" << endl;
    cout << "7 - Para S�bado" << endl;
    cout << "Quando ser�? ";
    do
    {
        cin >> numeroDia;
        if(numeroDia < 1 || numeroDia > 7)
        {
            cout << "Digite um n�mero v�lido!" << endl;
        }
    } while (numeroDia < 1 || numeroDia > 7);

    return numeroDia;
}

string salvarHoraInicio()
{
    DateHelper tm;
    cout << "Formato de hor�rio aceit�vel: HH:mm" << endl;
    cout << "Digite o hor�rio do in�cio: ";
    string hora = tm.inputTime(); //Equivale ao cin da hora de inicio, chamando a fun��o para verificar se � v�lido

    return hora;
}

string salvarHoraFim()
{
    DateHelper tm;
    cout << "Digite o hor�rio do fim: ";
    string hora = tm.inputTime(); //Equivale ao cin da hora de fim, chamando a fun��o para verificar se � v�lido

    return hora;
}

int verificarHorarios(string horaInicio, string horaFim)
{
    //In�cio do sistema de verificar se a festa tem no m�ximo 4 horas de dura��o
    string inicioHora, inicioMinuto;
    string fimHora, fimMinuto;

    inicioHora = horaInicio.substr(0,2); //Salvar a hora de inicio
    inicioMinuto = horaInicio.substr(3,2); //E salvar os minutos que inicia tamb�m

    fimHora = horaFim.substr(0,2); //Salvar a hora de fim
    fimMinuto = horaFim.substr(3,2);//E salvar os minutos que finaliza tamb�m

    int somaInicio=0, somaFim=0;

    somaInicio = (atoi(inicioHora.c_str()) * 60) + atoi(inicioMinuto.c_str()); //Agora converter as strings de horas e minutos de in�cio, em ints. E transformar as horas em minutos.
    somaFim = (atoi(fimHora.c_str()) * 60) + atoi(fimMinuto.c_str()); //Mesma convers�o e transforma��o para as horas e minutos de fim.
    //Fim do sistema de verificar se a festa tem no m�ximo 4 horas de dura��o

    if((somaFim-somaInicio)<=240) //Se a difern�a de minutos do in�cio da festa, para o final, for menor que 240min(4 horas), festa aceita.
    {
        return 1;
    }
    else //Festa n�o aceita, ultrapassou limite de 4 horas.
    {
        return 0;
    }

}

string salvarHoraInicioSabado()
{
    string hora;
    int verificarSabado=0;

    DateHelper tm;
    cout << "Digite o hor�rio do inicio: ";
    hora = tm.inputTime(); //Equivale ao cin da hora de fim, chamando a fun��o para verificar se � v�lido

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
    cout << "Digite o hor�rio do fim: ";
    hora = tm.inputTime(); //Equivale ao cin da hora de fim, chamando a fun��o para verificar se � v�lido

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
    string inicioHora, inicioMinuto;
    string fimHora, fimMinuto;

    inicioHora = horaInicio.substr(0,2); //Salvar a hora de inicio
    inicioMinuto = horaInicio.substr(3,2); //E salvar os minutos que inicia tamb�m

    fimHora = horaFim.substr(0,2); //Salvar a hora de fim
    fimMinuto = horaFim.substr(3,2);//E salvar os minutos que finaliza tamb�m

    int inicioEmMinutosEscrito = atoi(inicioHora.c_str())*60 + atoi(inicioMinuto.c_str());
    int fimEmMinutosEscrito = atoi(fimHora.c_str())*60 + atoi(fimMinuto.c_str());

    string inicioHoraArquivo, inicioMinutoArquivo;
    int horarioInicioArquivo;

    string fimHoraArquivo, fimMinutoArquivo;
    int horarioFimArquivo;

    int resposta = 1;
    ifstream inFile;
    inFile.open("files/party.txt");
    string line;
    FestaClass f;
    while (getline(inFile, line))
    {
        if(ModelHelper::split(';', line, 2) ==  data)
        {

            inicioHoraArquivo = (ModelHelper::split(';',line, 4)).substr(0,2);
            inicioMinutoArquivo = (ModelHelper::split(';',line, 4)).substr(3,2);
            horarioInicioArquivo = (atoi(inicioHoraArquivo.c_str()))*60 + atoi(inicioMinutoArquivo.c_str());

            fimHoraArquivo = (ModelHelper::split(';',line, 4)).substr(0,2);
            fimMinutoArquivo = (ModelHelper::split(';',line, 4)).substr(3,2);
            horarioFimArquivo = (atoi(fimHoraArquivo.c_str()))*60 + atoi(fimMinutoArquivo.c_str());


            if(inicioEmMinutosEscrito == horarioInicioArquivo || fimEmMinutosEscrito <= horarioFimArquivo) //Se tiver mesmo hor�rio de in�cio e fim
                resposta=0;

            if(fimEmMinutosEscrito >= horarioInicioArquivo && fimEmMinutosEscrito<=inicioEmMinutosEscrito) //Se o in�cio for no meio de outra festa
                resposta=0;

            if(inicioEmMinutosEscrito <= horarioInicioArquivo && fimEmMinutosEscrito >= horarioInicioArquivo) //Se o fim for no meio de outra festa
                resposta=0;

        }
    }

    return resposta;

}

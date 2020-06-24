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

    if(festa.codigo_cliente == 0) //Se o usuário desistiu de cadastrar a festa.
    {
        cout << "\nSaindo do cadastro de festas..." << endl;
    }
    else // Caso o código tenha sido encontado, continuar cadastro de festa
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
                        cout << "A festa pode ter no máximo 4 horas de duração!" << endl;
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
                            cout << "Os únicos horários aos sábados são de 12 às 16 e 18 às 22." << endl;
                        }

                        if(conferir==0)
                        {
                            cout << "A festa pode ter no máximo 4 horas de duração!" << endl;
                        }

                    } while (festa.hora_inicio=="Negado" || festa.hora_fim=="Negado" || conferir==0);
                }

                if(verificarCoincidencia(festa.dt, festa.hora_inicio, festa.hora_fim) != 1)
                {
                    cout << "Desculpe, já existe uma festa cadastrada nesse horário." << endl << "Por favor, tente novamente." << endl;
                }

            } while (verificarCoincidencia(festa.dt, festa.hora_inicio, festa.hora_fim) != 1); //Verificar se horários coincidem

            festa.tema = salvarTema();


            cout << "\nDados da festa:" << endl;
            cout << "Código: " << festa.codigo << endl;
            cout << "Quantidade de convidados: " << festa.qtdConvidados << endl;
            cout << "Data da festa: " << festa.dt << endl;
            cout << "Dia da festa: " << festa.diaSemana << endl;
            cout << "Hora do início: " << festa.hora_inicio << endl;
            cout << "Hora do fim: " << festa.hora_fim << endl;
            cout << "Tema: " << festa.tema << "\n" << endl;

            cout << "\n---> Confirmar dados <---" << endl;
            cout << "C - Para confirmar" << endl;
            cout << "R - Para refazer" << endl;
            cout << "Os dados inseridos estão corretos? ";
            cin >> confirmar;
        } while (toupper(confirmar)!='C');

        festa.save();

    }

}

unsigned int receberCodigoCliente()
{
    unsigned int codigo;
    ClienteClass verificarExistencia;
    cout << "\nInforme o código do cliente(Digite 0 para sair): ";
    do
    {
        cin >> codigo;
        verificarExistencia = ClienteClass::get(codigo);
        if(verificarExistencia.codigo==0 && codigo!=0) //Só mostrar essa mensagem se o código do cliente não estiver cadastrado, e o usuário não tiver digitado 0 para sair.
        {
            cout << "Informe um código existente(Digite 0 para sair): ";
        }
    } while (verificarExistencia.codigo==0 && codigo!=0); //Enquanto o usuário não informar o código de um cliente cadastrado, não passa a etapa. Se digitar 0 no código, ele finaliza o cadastro de festa

    if(verificarExistencia.codigo==0 && codigo==0) // Se o cliente digitou 0, a função de cadastrar festa é finalizada.
    {
        return 0;
    }
    else // Caso tenha encontrado o código nos arquivos, retornar código.
    {
        return codigo;
    }

}

unsigned int gerarCodigoFesta() //Função para gerar o código aleatório da festa
{
    srand((unsigned int)time(NULL)); //Só deve ser chamada uma única vez, para configurar o gerador de código aleatório(rand), baseado no time.
    unsigned int codigo;
    codigo = rand(); //Salvar o código usando rand, com as configurações do srand.
    return codigo;
}

int salvarConvid() //Função para receber a quantidade de convidados
{
    int qtd;
    cout << "\nQual a quantidade de convidados? ";
    do
    {
        cin >> qtd;
        if(qtd < 0)
        {
            cout << "Números negativos são inválidos!" << endl;
            cout << "Digite uma quantidade válida: ";
        }
        if(qtd < 100)
        {
            cout << "O máximo de convidados são 100." << endl;
            cout << "Digite uma quantidade válida: ";
        }
    } while (qtd <= 0 || qtd > 100);

    return qtd;
}

string salvarData()
{
    DateHelper dh; //Chamar classe DataHelper, que verifica se a data inserida é válida
    cout << "Formato de data aceitável: dd/mm/aaaa" << endl;
    cout << "Digite a data: ";
    string data = dh.inputDate(); //Equivale ao cin da data, chamando a função para verificar se é válida
    return data;
}

int salvarDia()
{
    int numeroDia;

    cout << "Menu de opções para dia da semana: " << endl;
    cout << "1 - Para Domingo" << endl;
    cout << "2 - Para Segunda-feira" << endl;
    cout << "3 - Para Terça-feira" << endl;
    cout << "4 - Para Quarta-feira" << endl;
    cout << "5 - Para Quinta-feira" << endl;
    cout << "6 - Para Sexta-feira" << endl;
    cout << "7 - Para Sábado" << endl;
    cout << "Quando será? ";
    do
    {
        cin >> numeroDia;
        if(numeroDia < 1 || numeroDia > 7)
        {
            cout << "Digite um número válido!" << endl;
        }
    } while (numeroDia < 1 || numeroDia > 7);

    return numeroDia;
}

string salvarHoraInicio()
{
    DateHelper tm;
    cout << "Formato de horário aceitável: HH:mm" << endl;
    cout << "Digite o horário do início: ";
    string hora = tm.inputTime(); //Equivale ao cin da hora de inicio, chamando a função para verificar se é válido

    return hora;
}

string salvarHoraFim()
{
    DateHelper tm;
    cout << "Digite o horário do fim: ";
    string hora = tm.inputTime(); //Equivale ao cin da hora de fim, chamando a função para verificar se é válido

    return hora;
}

int verificarHorarios(string horaInicio, string horaFim)
{
    //Início do sistema de verificar se a festa tem no máximo 4 horas de duração
    string inicioHora, inicioMinuto;
    string fimHora, fimMinuto;

    inicioHora = horaInicio.substr(0,2); //Salvar a hora de inicio
    inicioMinuto = horaInicio.substr(3,2); //E salvar os minutos que inicia também

    fimHora = horaFim.substr(0,2); //Salvar a hora de fim
    fimMinuto = horaFim.substr(3,2);//E salvar os minutos que finaliza também

    int somaInicio=0, somaFim=0;

    somaInicio = (atoi(inicioHora.c_str()) * 60) + atoi(inicioMinuto.c_str()); //Agora converter as strings de horas e minutos de início, em ints. E transformar as horas em minutos.
    somaFim = (atoi(fimHora.c_str()) * 60) + atoi(fimMinuto.c_str()); //Mesma conversão e transformação para as horas e minutos de fim.
    //Fim do sistema de verificar se a festa tem no máximo 4 horas de duração

    if((somaFim-somaInicio)<=240) //Se a difernça de minutos do início da festa, para o final, for menor que 240min(4 horas), festa aceita.
    {
        return 1;
    }
    else //Festa não aceita, ultrapassou limite de 4 horas.
    {
        return 0;
    }

}

string salvarHoraInicioSabado()
{
    string hora;
    int verificarSabado=0;

    DateHelper tm;
    cout << "Digite o horário do inicio: ";
    hora = tm.inputTime(); //Equivale ao cin da hora de fim, chamando a função para verificar se é válido

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
    cout << "Digite o horário do fim: ";
    hora = tm.inputTime(); //Equivale ao cin da hora de fim, chamando a função para verificar se é válido

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
    inicioMinuto = horaInicio.substr(3,2); //E salvar os minutos que inicia também

    fimHora = horaFim.substr(0,2); //Salvar a hora de fim
    fimMinuto = horaFim.substr(3,2);//E salvar os minutos que finaliza também

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


            if(inicioEmMinutosEscrito == horarioInicioArquivo || fimEmMinutosEscrito <= horarioFimArquivo) //Se tiver mesmo horário de início e fim
                resposta=0;

            if(fimEmMinutosEscrito >= horarioInicioArquivo && fimEmMinutosEscrito<=inicioEmMinutosEscrito) //Se o início for no meio de outra festa
                resposta=0;

            if(inicioEmMinutosEscrito <= horarioInicioArquivo && fimEmMinutosEscrito >= horarioInicioArquivo) //Se o fim for no meio de outra festa
                resposta=0;

        }
    }

    return resposta;

}

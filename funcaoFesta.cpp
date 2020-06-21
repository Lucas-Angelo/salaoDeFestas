#include <iostream>
#include <locale.h>
#include <string>
#include <time.h>

using namespace std;

#include "FestaClass.h"
#include "ClienteClass.h"
#include "helpers/DateHelper.h"

#include "munit.h"
#include <vector>


unsigned int receberCodigoCliente();
unsigned int gerarCodigoFesta();
int salvarConvid();
string salvarData();
int salvarDia(string date);
string salvarHoraInicio();
string salvarHoraFim();
int verificarHorarios(string horaInicio, string horaFim);
string salvarHoraInicioSabado();
string salvarHoraFimSabado();
string salvarTema();

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

            festa.dt = salvarData();

            festa.diaSemana = salvarDia(festa.dt);

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
                    if(festa.hora_inicio=="Negado" || festa.hora_fim=="Negado")
                    {
                        cout << "Os horários de 12 às 16 e 18 às 22 estão reservados." << endl;
                    }
                } while (festa.hora_inicio=="Negado" || festa.hora_fim=="Negado");
            }

            festa.tema = salvarTema();
            string weekNames[7] = { "Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado" };

            cout << "\nDados da festa:" << endl;
            cout << "Código: " << festa.codigo << endl;
            cout << "Quantidade de convidados: " << festa.qtdConvidados << endl;
            cout << "Data da festa: " << festa.dt << endl;
            cout << "Dia da festa: " << weekNames[festa.diaSemana - 1] << endl;
            cout << "Hora do início: " << festa.hora_inicio << endl;
            cout << "Hora do fim: " << festa.hora_fim << endl;
            cout << "Tema: " << festa.tema << "\n" << endl;

            cout << "\n---> Confirmar dados <---" << endl;
            cout << "C - Para confirmar" << endl;
            cout << "R - Para refazer" << endl;
            cout << "Os dados inseridos estão corretos? ";
            cin >> confirmar;
        } while (toupper(confirmar)!='C');

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
        cout << "Código: " << c[i].codigo << endl;
        cout << "Nome: " << c[i].nome << endl;
        cout << "Endereço: " << c[i].endereco << endl;
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
        cout << "Multiplos usuários encontrados." << endl << "Digite o código do cliente desejado: ";
        cin >> codigo;
        ClienteClass cli = ClienteClass::get(codigo);
        if(cli.codigo == 0) {
            cout << "Código Inválido" << endl;
            return receberCodigoCliente();
        } else
            return cli.codigo;
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
    } while (qtd < 0);

    return qtd;
}

string salvarData() {
    DateHelper dh; //Chamar classe DataHelper, que verifica se a data inserida é válida
    cout << "Formato de data aceitável: dd/mm/aaaa" << endl;
    cout << "Digite a data: ";
    string data = dh.inputDate(); //Equivale ao cin da data, chamando a função para verificar se é válida
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
        return hora;
    }
    else
    {
        return "Negado";
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
        return hora;
    }
    else
    {
        return "Negado";
    }
}

string salvarTema()
{
    string tema;
    cout << "Qual o tema? ";
    getline(cin >> ws,tema);

    return tema;
}

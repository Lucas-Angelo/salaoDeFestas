#include "funcaoContrato.h"
#include <iostream>
#include <stdio.h>
#include "munit.h"
#include <locale.h>
#include <ctype.h>
#include <string>
#include <time.h>
#include "ContratoClass.h"
#include "FestaClass.h"
#include "helpers/ModelHelper.h"
using namespace std;

int funcaoContrato()
{

    ContratoClass contrato;
    FestaClass festa;
    int prossiga=0; //variavel de controle
    char confirmar;

    cout << "\n>>> GERAR CONTRATO <<<\n";


    do  //pede um codigo de festa ate encontrar um que existe e que o usuario confirme seus dados
    {
        cout << "Codigo da festa que deseja gerar contrato (digite 0 para cancelar operação): ";
        cin >> contrato.codigo_festa;
        if (cin.fail()) //se for detectado erro na leitura
        {
            cin.clear(); // limpa flag de erro
            cout << "~ ERRO : ENTRADA NÃO NUMÉRICA DIGITADA ~" << endl;
        }
        else {
        if (contrato.codigo_festa==0)
        {
            cout << "\n\n!!!-- Operação Cancelada --!!!\n\n";
            return 0;
        }

        festa = festa.get(contrato.codigo_festa);

        if (festa.codigo!=contrato.codigo_festa)    //
            cout << "!!!Codigo de festa nao registrado!!!\n";
        else    //Confirma dados da festa para prosseguir com cadastro de contrato
        {
            cout << "\nConfirmacao dos dados da festa:" << endl;
            printf("Código: %d\n", festa.codigo);
            cout << "Código do Cliente:  "<< festa.codigo_cliente << endl;
            cout << "Data: " << festa.dt << endl;
            cout << "Dia da Semana: " << festa.diaSemana << endl;
            cout << "Horário: " << festa.hora_inicio <<" - "<< festa.hora_fim << endl;
            printf("Quantidade de convidados: %d\n", festa.qtdConvidados);
            cout << "Tema: " << festa.tema << endl;

            printf("\n---> Confirmar dados <---");
            printf("\nC - Para confirmar");
            printf("\nR - Para buscar outra festa");
            printf("\nOs dados inseridos estão corretos? ");
            cin.ignore(0xFFFF, '\n'); //ignora o lixo gerado no cin
            cin >> confirmar;
            if (toupper(confirmar)=='C')
                prossiga=1;
        }
        }
        cin.ignore(0xFFFF, '\n'); //ignora o lixo gerado no cin


    }while (!prossiga); //repete até encontrar codigo de festa que existe

    do {

        contrato.valor_total = CalculaValorTotal(festa.diaSemana, festa.qtdConvidados);
        cout << "Valor da festa: " << contrato.valor_total;
        cout << "\nVoce pode ganhar descontos pela forma de pagamento de acordo com a tabela abaixo:\n";
        cout << " __________________\n"  ;
        cout << "|Pagamento|Desconto|\n" ;
        cout << "|_________|________|\n" ;
        cout << "|A vista  |     10%|\n" ;
        cout << "|2 vezes  |      5%|\n" ;
        cout << "|3 vezes  |      2%|\n" ;
        cout << "|4 ou +   |      0%|\n" ;
        cout << "|_________|________|\n" ;

        cout << "\nEm quantas vezes deseja pagar? ";
        do
        {
            cin  >> contrato.formaPagamento;
            if (contrato.formaPagamento<'1'||contrato.formaPagamento>'9')
                cout << "INVALIDO (formas de pagamento validas : 1 a 9 vezes)";
            cin.ignore(0xFFFF,'\n');
        }while (contrato.formaPagamento<'1'||contrato.formaPagamento>'9');

        contrato.desconto = CalculaDesconto(contrato.valor_total, contrato.formaPagamento);
        contrato.valor_final = contrato.valor_total - contrato.desconto;


        contrato.status='A'; //status = "a pagar"

        //confirmação do contrato
        cout << "\nConfirmacao do contrato:" << endl;
        printf("Código: %d\n", contrato.codigo);
        cout << "Código da festa: " << contrato.codigo_festa << endl;
        cout << "Pagamento em " << contrato.formaPagamento << " vez(es)" << endl;
        cout << "Valor Total: " << contrato.valor_total << endl;
        cout << "Desconto: " << contrato.desconto << endl;
        cout << "Valor com Desconto: " << contrato.valor_final << endl;

        printf("\n---> Confirmar dados <---");
        printf("\nC - Para confirmar");
        printf("\nR - Para refazer");
        printf("\nOs dados estão corretos? ");
        cin >> confirmar;
        cin.ignore(0xFFFF,'\n');
    } while (toupper(confirmar)!='C');
    contrato.save();
    return 0;
}

float CalculaValorTotal(int dia, int convidados)
{
    if (dia>=2&&dia<=5)//valores a pagar para dia da semana
        {
            if (convidados<=30)
                return 1899;
            else if (convidados<=50)
                return 2199;
            else if (convidados<=80)
                return 3199;
            else if (convidados<=100)
                return 3799;
        }
        else //finais de semana
        {
            if (convidados<=30)
                return 2099;
            else if (convidados<=50)
                return 2299;
            else if (convidados<=80)
                return 3499;
            else if (convidados<=100)
                return 3999;
        }
        return 0;
}
float CalculaDesconto(float valor, char pagamento)
{
    switch (pagamento) //calculo do desconto
    {
    case '1':
        return valor*10/100;   //10% de desconto
    case '2':
        return valor*5/100;    //5% de desconto
    case '3':
        return valor*2/100;    //2% de desconto
    default:
        return 0;              //sem desconto
    }
    return 0;
}

int atualizaContrato()
{
    ContratoClass contrato;
    int i, prossiga=0, linha;
    char confirmar;
    string line;

    cout << "\n>>> ATUALIZAÇÃO DE CONTRATO <<<\n";


    do  //pede um codigo de contrato ate encontrar um que existe e que o usuario confirme seus dados
    {
        cout << "Codigo do contrato que deseja atualizar (digite 0 para cancelar operação): ";
        cin >> contrato.codigo;
        if (cin.fail()) //se for detectado erro na leitura
        {
            cin.clear(); // limpa flag de erro
            cout << "~ ERRO : ENTRADA NÃO NUMÉRICA DIGITADA ~" << endl;
        }
        else {
        if (contrato.codigo==0)
        {
            cout << "\n\n!!!-- Operação Cancelada --!!!\n\n";
            return 0;
        }

        contrato = contrato.get(contrato.codigo);

        if (contrato.codigo==NULL)    //
            cout << "!!!Codigo de contrato nao registrado!!!\n";
        else    //Confirma dados da contrato para prosseguir com cadastro de contrato
        {
            //confirmação do contrato
            cout << "\nConfirmacao do contrato:" << endl;
            printf("Código: %d\n", contrato.codigo);
            cout << "Código da festa: " << contrato.codigo_festa << endl;
            cout << "Pagamento em " << contrato.formaPagamento << " vez(es)" << endl;
            cout << "Valor Total: " << contrato.valor_total << endl;
            cout << "Desconto: " << contrato.desconto << endl;
            cout << "Valor com Desconto: " << contrato.valor_final << endl;
            cout << "Status: " << contrato.status << endl;


            printf("\n---> Confirmar dados <---");
            printf("\nC - Para confirmar");
            printf("\nR - Para buscar outro contrato");
            printf("\nOs dados estão corretos? ");
            cin >> confirmar;
            if (toupper(confirmar)=='C')
                prossiga=1;
        }
        }
        cin.ignore(0xFFFF, '\n');

    }while (!prossiga); //repete até encontrar codigo de contrato que existe


    do
    {
        cout << "\nAtualizar o contrato para pago ('p') ou para cancelado ('c'): ";
        cin >> contrato.status;
        cin.ignore(0xFFFF,'\n');
        contrato.status = toupper(contrato.status);
        if (contrato.status!='P'&&contrato.status!='C')
            cout << "!!!Invalido!!!\n";
    }while (contrato.status!='P'&&contrato.status!='C');


    ifstream fileContrato;
    ofstream fileNovo;

    fileContrato.open("files/contract.txt");

    stringstream ss;
    string cd;
    ss << contrato.codigo;
    ss >> cd;
    for (i=1, linha=0; getline(fileContrato,line) && linha!=i ;i++)       //descobre qual a linha do contrato selecionado
    {
        if (ModelHelper::split(';', line, 0) == cd)
            linha=i;    //quando o codigo corresponde, armazena sua linha e sai do for (linha==i)
    }

    fileNovo.open("files/novo.txt");
    fileContrato.close();
    fileContrato.open("files/contract.txt");;
    for (i=1;getline(fileContrato,line);i++)
    {
        if (i==linha)
        {
            fileNovo << contrato.codigo << ";" << contrato.valor_total << ";"  << contrato.desconto << ";" << contrato.valor_final  << ";" << contrato.formaPagamento  << ";" << contrato.status  << ";" << contrato.codigo_festa << "\n";
        }
        else
        {
            fileNovo << line << endl;
        }
    }

    fileContrato.close();
    fileNovo.close();

    remove ("files/contract.txt");
    rename ("files/novo.txt","files/contract.txt");

    cout << "\n\n---- Contrato " << contrato.codigo << " Atualizado ----\n\n";

    return 0;

}




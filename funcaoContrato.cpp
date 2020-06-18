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
        cout << "Codigo da festa que deseja gerar contrato: ";
        cin >> contrato.codigo_festa;
        festa = festa.get(contrato.codigo_festa);

        if (festa.codigo!=contrato.codigo_festa)    //
            cout << "!!!Codigo de festa nao registrado!!!\n";
        else    //Confirma dados da festa para prosseguir com cadastro de contrato
        {
            cout << "\nConfirmacao dos dados da festa:" << endl;
            printf("C�digo: %d\n", festa.codigo);
            cout << "C�digo do Cliente:  "<< festa.codigo_cliente << endl;
            cout << "Data: " << festa.dt << endl;
            cout << "Dia da Semana: " << festa.diaSemana << endl;
            cout << "Hor�rio: " << festa.hora_inicio <<" - "<< festa.hora_fim << endl;
            printf("Quantidade de convidados: %d\n", festa.qtdConvidados);
            cout << "Tema: " << festa.tema << endl;

            printf("\n---> Confirmar dados <---");
            printf("\nC - Para confirmar");
            printf("\nR - Para buscar outra festa");
            printf("\nOs dados inseridos est�o corretos? ");
            cin >> confirmar;
            if (toupper(confirmar)=='C')
                prossiga=1;
        }


    }while (!prossiga); //repete at� encontrar codigo de festa que existe

    do
    {

        contrato.codigo = gerarCodigoo(); //Capturar c�digo aleat�rio gerado.

        if (festa.diaSemana>=2&&festa.diaSemana<=5)//valores a pagar para dia da semana
        {
            if (festa.qtdConvidados<=30)
                contrato.valor_total=1899;
            else if (festa.qtdConvidados<=50)
                contrato.valor_total=2199;
            else if (festa.qtdConvidados<=80)
                contrato.valor_total=3199;
            else if (festa.qtdConvidados<=100)
                contrato.valor_total=3799;
            else
                cout << "Festa ultrapassa capacidade maxima do salao";
        }
        else //finais de semana
        {
            if (festa.qtdConvidados<=30)
                contrato.valor_total=2099;
            else if (festa.qtdConvidados<=50)
                contrato.valor_total=2299;
            else if (festa.qtdConvidados<=80)
                contrato.valor_total=3499;
            else if (festa.qtdConvidados<=100)
                contrato.valor_total=3999;
            else
                cout << "Festa ultrapassa capacidade maxima do salao";
        }
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
        cin  >> contrato.formaPagamento;

        switch (contrato.formaPagamento) //calculo do novo valor a pagar
        {
        case '1':
            contrato.desconto=contrato.valor_total*10/100.0;
            break;
        case '2':
            contrato.desconto=contrato.valor_total*5/100.0;
            break;
        case '3':
            contrato.desconto=contrato.valor_total*2/100.0;
            break;
        default:
            contrato.desconto=0;
            break;
        }
        contrato.valor_final=contrato.valor_total-contrato.desconto;


        contrato.status='a'; //status = "a pagar"

        //confirma��o do contrato
        cout << "\nConfirmacao do contrato:" << endl;
        printf("C�digo: %d\n", contrato.codigo);
        cout << "C�digo da festa: " << contrato.codigo_festa << endl;
        cout << "Pagamento em " << contrato.formaPagamento << " vez(es)" << endl;
        cout << "Valor Total: " << contrato.valor_total << endl;
        cout << "Desconto: " << contrato.desconto << endl;
        cout << "Valor com Desconto: " << contrato.valor_final << endl;

        printf("\n---> Confirmar dados <---");
        printf("\nC - Para confirmar");
        printf("\nR - Para refazer");
        printf("\nOs dados est�o corretos? ");
        cin >> confirmar;
    } while (toupper(confirmar)!='C');
    contrato.save();
}


unsigned int gerarCodigoo() //Fun��o para gerar o c�digo aleat�rio
{
    srand((unsigned int)time(NULL)); //S� deve ser chamada uma �nica vez, para configurar o gerador de c�digo aleat�rio(rand), baseado no time.
    unsigned int codigo;
    codigo = rand(); //Salvar o c�digo usando rand, com as configura��es do srand.
    return codigo;
}




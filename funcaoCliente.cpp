#include <iostream>
#include <stdio.h>
#include "munit.h"

using namespace std;
#include <string>
#include <time.h>
#include "ClienteClass.h"


int funcaoCliente()
{
    ClienteClass cli;
    setlocale(LC_ALL,"portuguese"); //colocar acento
    srand((unsigned int) time(NULL)); //configura a funcao aleatoria

    printf("\n------------>CADASTRO DE CLIENTE<------------\n");
    cli.codigo = rand();

    printf("\nDigite o nome do Cliente: ");
    getline(cin >> ws,cli.nome);

    printf("\nDigite o endereço do Cliente: ");
    getline(cin >> ws,cli.endereco);

    printf("\nDigite o telefone do Cliente: ");
    cin>>cli.telefone;

    printf("\nDigite a data de nascimento do Cliente: ");
    getline(cin >> ws,cli.dtNascimento);

    return 0;
}




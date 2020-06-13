#include <iostream>
#include <stdio.h>
#include "munit.h"
#include <locale>

using namespace std;
#include <string>
#include <time.h>
#include "ClienteClass.h"
#include "FuncionariosClass.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int idade=0;
    float peso=72.5;
    char sexo = 'B';

    ClienteClass cliente;
    cliente.codigo=142;
    cliente.nome = "Lucas Angelo";
    cliente.nome += " Oliveira";
    cliente.salario = 440.50;

    FuncionariosClass funcionarios;
    funcionarios.codigo=69;
    funcionarios.nome= "Kid Benguis";
    funcionarios.salario= 666.00;
    funcionarios.telefone=553740028922;
    funcionarios.tipo='t';


    printf("Codigo: %i\n", funcionarios.codigo);
    cout << funcionarios.nome + '\n';
    printf("Salario: %.2f\n", funcionarios.salario);
    printf("Telefone: %l", funcionarios.telefone);
    if(funcionarios.tipo=='t')
        printf("Funcionário TEMPORARIO\n\n");
    else
        printf("Funcionario PERMANENTE\n\n");

    printf("%i\n", idade);
    printf("%i\n", cliente.codigo);
    printf("%f\n", peso);
    printf("%f\n", cliente.salario);

    cout << cliente.nome + '\n';
    cout << "Ola Mundo!\n\n" << endl;

    int idades[4];
    char respostasProva[4];
    ClienteClass clientes[4];

    srand(time(NULL));
    printf("Exemplificando receber dados\n");
    for(int i=0;i<4;i++) {
        clientes[i].codigo = rand();
        printf("Qual é o nome do cliente: ");
        scanf("%s", &clientes[i].nome);
        printf("Qual é o Salario do Cliente: ");
        scanf("%f", &clientes[i].salario);
    }

    for(int i=0;i<4;i++) {
            printf("ID:  %i\n", clientes[i].codigo);
            cout << "Nome do cliente " + clientes[i].nome + '\n';
            printf("Salario: R$%.2f\n\n", clientes[i].salario);
    }

    printf("FIM");


    return 0;
}

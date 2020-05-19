#include <iostream>
#include "munit.h"

using namespace std;
#include <string>
#include <time.h>
#include "ClienteClass.h"

int main()
{
    //Vou dar uns exemplos antes de variavel:
    int idade=0; // Armazena valores inteiros
    float peso=72.5; // Grava valores dos conjuntos dos reais
    char sexo = 'B';//Armazena um caracter

    //Importando classe ClienteClass para entender melhor o que tem dentro ver o arquivo ClienteClass.h (Ver antes de continuar)
    // Armazena um objeto da Classe Cliente
    ClienteClass cliente;
    cliente.codigo=142;
    cliente.nome = "Lucas Angelo";
    cliente.nome += " Oliveira";
    cliente.salario = 440.50;

    // Como funciona as variaveis dentro do objeto:
    printf("%i\n", idade);
    printf("%i\n", cliente.codigo);
    printf("%f\n", peso);
    printf("%f\n", cliente.salario);
    // Para printar o string é diferente, puts não funciona, puts é apenas para vetores de char[]
    cout << cliente.nome + '\n';
    cout << "Ola Mundo!\n\n" << endl;

    //Só que nesse trabalho não queremos apenas um cliente não é mesmo ? Então vamos no vetor:
    int idades[4]; // Armazena um conjunto de valores inteiros
    char respostasProva[4]; // Armazena um conjunto de caracteres
    ClienteClass clientes[4]; // Armazena um conjunto de objetos do cliente

    srand(time(NULL)); //Inicia a função para buscar numeros randomicos
    printf("Exemplificando receber dados\n");
    for(int i=0;i<4;i++) {
        clientes[i].codigo = rand(); //Gera ids randomicos (Não os que queremos pois esse pode repetir)
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

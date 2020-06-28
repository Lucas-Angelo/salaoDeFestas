#include <iostream>
#include <stdio.h>
#include "munit.h"
#include <locale.h>
#include <ctype.h>

using namespace std;

#include <string>
#include <time.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "helpers/ModelHelper.h"
#include "FornecedorClass.h"

string salvaNome();
string salvaTelefone();
string salvaProduto();



int funcaoFornecedor(){

    setlocale(LC_ALL,"portuguese"); //Adicionar caracteres especiais
    FornecedorClass fornecedor; //Orientar a objeto por meio da classe

    char confirmar;
    cout << "\n--->CADASTRO DE FORNECEDOR<---" << endl;

    do {

        fornecedor.nome = salvaNome(); //Receber nome digitado.
        fornecedor.telefone = salvaTelefone(); //Receber telefone digitado.
        fornecedor.produto = salvaProduto(); //Receber fun��o do fornecedor digitada.

        cout << "\nDados do fornecedor:" << endl;
        printf("C�digo: %d\n", fornecedor.codigo);
        cout << "Nome: " + fornecedor.nome << endl;
        cout << "Telefone: " + fornecedor.telefone << endl;
        cout << "Produto Fornecido: " + fornecedor.produto << endl;

        printf("\n---> Confirmar dados <---");
        printf("\nC - Para confirmar");
        printf("\nR - Para refazer");
        printf("\nOs dados inseridos est�o corretos? ");
        cin >> confirmar;
    } while (toupper(confirmar)!='C');

    fornecedor.save(); //Salvar os dados do objeto classe funcionarios no arquivo

    cout << "\n---> FORNECEDOR CADASTRADO COM SUCESSO <---\n\n" << endl;

return 0;
}

string salvaNome() //Fun��o para pegar o nome.
{
    string nome;
    cout << "\nDigite o nome: ";
    getline(cin >> ws,nome); //Capturar string/linha(nome) do funcion�rio.
    return nome;
}

string salvaTelefone() //Fun��o para pegar o telefone do funcion�rio.
{
    int verificador=0, x, i;
    string telefone;
    cout << "Digite o telefone: ";
    do
    {
        getline(cin >> ws,telefone);
        for(i=0; i<telefone.length(); i++)
        {
            x=isdigit(telefone[i])?1:2; //1 para numerais, 2 para caracteres.
            if(x==1)
            {
                verificador++; //Se for numeral, incrementa.
            }
        }
        if(verificador<10)
        {
            cout << "Numero de telefone invalido! [Minimo de 10 numeros (DDD + numero)]" << endl;
            cout << "Digite um telefone valido: ";
        }
    } while (verificador<10); //Se tiver no m�nimo 10 numerais, conclui.
    return telefone;
}

string salvaProduto()
{
    int verificador=0, x, i;
    string produto;
    cout << "Digite o produto: ";
    getline(cin >> ws,produto);
    return produto;
}


void procuraFornecedor() {
    cout << "\n------------>PESQUISA DE FORNECEDOR<------------" << endl;
    string nome;
    cout << "Pesquisar por nome: ";
    getline(cin >> ws, nome);
    FornecedorClass f;
    int i=0;
    ifstream inFile;
    // Abrir o arquivo para leitura
    inFile.open("files/fornecedor.txt");
    string line;
    // Ler linha por linha at� o fim do arquivo.
    while (getline(inFile, line)) {
        // Se encontrar o codigo do funcionario, quebrar a linha e definir os atributos da classe
        if(ModelHelper::split(';', line, 1).find(nome) != std::string::npos) {
          f.codigo = atoi(ModelHelper::split(';',line, 0).c_str());
          f.nome = ModelHelper::split(';',line, 1);
          f.telefone = ModelHelper::split(';',line, 2);
          f.produto = ModelHelper::split(';',line, 3);
          cout << "-------------------------------------------------------------" << endl;
          cout << "C�digo: " << f.codigo << endl;
          cout << "Nome: " << f.nome << endl;
          cout << "Telefone: " << f.telefone << endl;
          cout << "Produto: " << f.produto << endl;
          cout << "-------------------------------------------------------------" << endl;
          i++;
        }
    }
    if(i == 0) cout << "------------------------\nNenhum item encontrado\n------------------------";
}

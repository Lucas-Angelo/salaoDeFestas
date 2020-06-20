#include <iostream>
#include <stdio.h>
#include "munit.h"
#include "funcaoFuncionarios.h"
#include "funcaoFornecedor.h"

using namespace std;
#include <string>
#include <time.h>
#include "ClienteClass.h"
#include "FornecedorClass.h"
#include "funcaoCliente.h"


using namespace std;
void printArt();

int main() {
  int op = 0, cad;
  setlocale(LC_ALL, "portuguese");
  printArt();
  while (op != 3)
    {
    cout << "\n---------------->MENU DE OPCOES<----------------" << endl;
    cout << "\n1-Cadastrar\n2-Pesquisar\n3-Sair\nDigite uma opcao: ";
    cin >> op;
    cad = 0;
    if (op == 1)
    {
      cout << "\n------------>OPCOES DE CADASTRO<------------" << endl;
      cout << "\n1-Cliente\n2-Funcionario\n3-Fornecedor\n4-Festa\n5-Voltar\nDigite o que gostaria de cadastrar: ";
      cin >> cad;
      switch (cad)
      {
      case 1:
        funcaoCliente();
        break;
      case 2:
        funcaoFuncionarios(op, cad);
        break;
      case 3:
        funcaoFornecedor();
        break;
      case 4:
        //festa
        break;

      default:
        cad = 0;
      }
    } else if (op == 2)
    {
      cout << "\n------------>OPCOES DE PESQUISA<------------" << endl;
      cout << "\n1-Cliente\n2-Funcionario\n3-Fornecedor\n4-Voltar\nDigite o que gostaria de pesquisar: ";
      cin >> cad;
      switch (cad)
      {
      case 1:
        procuraCliente();
        break;
      case 2:
        procuraFuncionario();
        break;
      case 3:
        //procurar fornecedor
        funcaoFornecedor();
        break;
      case 4:
        //procurar festa
        break;
      default:
        cad = 0;
      }
    }
  }
    return 0;
}

void printArt() {
  cout << "-----------------------------------------------------" << endl;
  cout << "     Salao de Festas - Patati Patata       " << endl;
  cout << "   _                             .-." << endl;
  cout << "  / )  .-.    ___          __   (   )" << endl;
  cout << " ( (  (   ) .'___)        (__'-._) (" << endl;
  cout << "  \\ '._) (,'.'               '.     '-." << endl;
  cout << "   '.      /  \"\\               '    -. '." << endl;
  cout << "     )    /   \\ \\   .-.   ,'.   )  (  ',_)    _" << endl;
  cout << "   .'    (     \\ \\ (   \ . .' .'    )    .-. ( \ " << endl;
  cout << "  (  .''. '.    \\ \\|  .' .' ,',--, /    (   ) ) )" << endl;
  cout << "   \\ \\   ', :    \\    .-'  ( (  ( (     _) (,' / " << endl;
  cout << "    \\ \\   : :    )  / _     ' .  \ \  ,'      / " << endl;
  cout << "  ,' ,'   : ;   /  /,' '.   /.'  / / ( (\    (" << endl;
  cout << "  '.'      \"   (    .-'. \       ''   \_)\    \ " << endl;
  cout << "                \\  |    \ \__             )    )" << endl;
  cout << "              ___\\ |     \___;           /  , /" << endl;
  cout << "             /  ___)                    (  ( (" << endl;
  cout << "             '.'                         ) ;) ;" << endl;
  cout << "                                        (_/(_/" << endl;
  cout << "----------------------------------------------------" << endl;

}

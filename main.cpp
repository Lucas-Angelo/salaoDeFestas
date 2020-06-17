#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

#include "munit.h"

#include "funcaoCliente.h"
#include "funcaoFuncionarios.h"
#include "funcaoFesta.h"
#include "funcaoFornecedor.h"

#include "helpers/DateHelper.h"

void printArt();

int main()
{
    int op=0,cad,pes;
    setlocale(LC_ALL,"portuguese");



    printArt();

    while(op!=3)
    {
      printf("\n---------------->MENU DE OPCOES<----------------\n");
      printf("\n1-Cadastrar\n2-Pesquisar\n3-Sair\nDigite uma opcao: ");
      scanf("%d",&op);
      cad=0;
      pes=0;
      if(op ==1)
      {
        printf("\n------------>OPCOES DE CADASTRO<------------\n");
        printf("\n1-Cliente\n2-Funcionario\n3-Fornecedor\n4-Festa\n5-Voltar\nDigite o que gostaria de cadastrar: ");
        scanf("%d",&cad);
      }
      else if(op==2)
      {
        printf("\n------------>OPCOES DE PESQUISA<------------\n");
        printf("\n1-Cliente\n2-Funcionario\n3-Fornecedor\n4-Voltar\nDigite o que gostaria de pesquisar: ");
        scanf("%d",&pes);
      }

      if(cad !=0)
      {
          switch(cad)
          {
          case 1:
            funcaoCliente(); //Cadastrar e salvar dados do cliente.
          break;
          case 2:
            funcaoFuncionarios(); //Cadastrar e salvar dados do funcionário.
          break;
          case 3:
            funcaoFornecedor (); //Cadastrar e salvar dados do fornecedor.
          break;
          case 4:
            funcaoFesta(); //Cadastrar e salvar dados da festa.
          break;
          default:
            cad=0;
        }
      }
      if(pes !=0)
      {
          switch(pes)
          {
          case 1:
             procuraCliente();
          break;
          case 2:
           procuraFuncionario();
          break;
          case 3:
           //procurar fornecedor
           procuraFornecedor();
          break;
          case 4:
            //procurar festa
            procuraCliente();
          break;
          default:
            pes=0;
        }
      }
    }

    return 0;
}

void printArt(){
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

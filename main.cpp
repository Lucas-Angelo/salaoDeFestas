#include <iostream>
#include <stdio.h>
#include "munit.h"
#include "funcaoFuncionarios.h"
#include "funcaoFesta.h"
#include "funcaoFornecedor.h"
#include "funcaoContrato.h"

using namespace std;
#include <string>
#include <time.h>
#include "ClienteClass.h"
#include "FornecedorClass.h"
#include "funcaoCliente.h"
#include "helpers/DateHelper.h"

using namespace std;
void printArt();

int main()
{
    int op=0,cad,pes,att=0;
    setlocale(LC_ALL,"portuguese");
    printArt();
    while(op!=4)
    {
      printf("\n---------------->MENU DE OPCOES<----------------\n");
      printf("\n1-Cadastrar\n2-Pesquisar\n3-Atualizar\n4-Sair\nDigite uma opcao: ");
      scanf("%d",&op);
      cad=0;
      pes=0;
      if(op ==1)
      {
        printf("\n------------>OPCOES DE CADASTRO<------------\n");
        printf("\n1-Cliente\n2-Funcionario\n3-Fornecedor\n4-Festa\n5-Contrato\n6-Voltar\nDigite o que gostaria de cadastrar: ");
        scanf("%d",&cad);
      }
      else if(op==2)
      {
        printf("\n------------>OPCOES DE PESQUISA<------------\n");
        printf("\n1-Cliente\n2-Funcionario\n3-Fornecedor\n4-Voltar\nDigite o que gostaria de pesquisar: ");
        scanf("%d",&pes);
      }
      else if (op==3)
      {
          printf("\n------------>OPCOES DE ATULAIZAÇÃO<------------\n");
          printf("\n1-Contrato\n2-Voltar\nDigite o que gostaria de atualizar: ");
          scanf("%d",&att);
      }

      if(cad !=0)
      {
          switch(cad)
          {
          case 1:
            funcaoCliente();
          break;
          case 2:
            funcaoFuncionarios(op);
          break;
          case 3:
            funcaoFornecedor ();
          break;
          case 4:
            funcaoFesta();
          break;
          case 5:
            funcaoContrato();
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
        if(att !=0)
      {
          switch(att)
          {
          case 1:
             atualizaContrato();
          default:
            att=0;
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
    cout << "  ,' ,'   : ;   /  /,' '.   /.'    / / ( (\    (" << endl;
    cout << "  '.'      \"   (    .-'. \       ''   \_)\    \ " << endl;
    cout << "                \\  |    \ \__             )    )" << endl;
    cout << "              ___\\ |     \___;           /  , /" << endl;
    cout << "             /  ___)                    (  ( (" << endl;
    cout << "             '.'                         ) ;) ;" << endl;
    cout << "                                        (_/(_/" << endl;
    cout << "----------------------------------------------------" << endl;


}

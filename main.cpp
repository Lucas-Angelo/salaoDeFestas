#include <iostream>
#include <stdio.h>
#include "munit.h"

using namespace std;
#include <string>
#include <time.h>
#include "ClienteClass.h"
#include "FornecedorClass.h"
#include "funcaoCliente.h"
void printArt();
int main()
{
    int op=0,cad;
    setlocale(LC_ALL,"portuguese");
    printArt();
    while(op!=3)
    {
      printf("\n---------------->MENU DE OP��ES<----------------\n");
      printf("\n1-Cadastrar\n2-Pesquisar\n3-Sair\nDigite uma opcao: ");
      scanf("%d",&op);
      cad=0;
      if(op ==1)
      {
        printf("\n------------>OP��ES DE CADASTRO<------------\n");
        printf("\n1-Cliente\n2-Funcionario\n3-Fornecedor\n4-Festa\n5-Sair\nDigite o que gostaria de cadastrar: ");
        scanf("%d",&cad);
      }
      if(cad !=0)
      {
          switch(cad)
          {
          case 1:
            funcaoCliente();
          break;
          case 2:
            //colocar a funcao  funcionario
          break;
          case 3:
            //colocar a funcao  fornecedor
          break;
          case 4:
            //colocar a funcao  festa
          break;
          default:
            cad=0;
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
    cout << "  \ '._) (,'.'               '.     '-." << endl;
    cout << "   '.      /  \"\               '    -. '." << endl;
    cout << "     )    /   \ \   .-.   ,'.   )  (  ',_)    _" << endl;
    cout << "   .'    (     \ \ (   \ . .' .'    )    .-. ( \ " << endl;
    cout << "  (  .''. '.    \ \|  .' .' ,',--, /    (   ) ) )" << endl;
    cout << "   \ \   ', :    \    .-'  ( (  ( (     _) (,' / " << endl;
    cout << "    \ \   : :    )  / _     ' .  \ \  ,'      / " << endl;
    cout << "  ,' ,'   : ;   /  /,' '.   /.'  / / ( (\    (" << endl;
    cout << "  '.'      \"   (    .-'. \       ''   \_)\    \ " << endl;
    cout << "                \  |    \ \__             )    )" << endl;
    cout << "              ___\ |     \___;           /  , /" << endl;
    cout << "             /  ___)                    (  ( (" << endl;
    cout << "             '.'                         ) ;) ;" << endl;
    cout << "                                        (_/(_/" << endl;
    cout << "----------------------------------------------------" << endl;


}

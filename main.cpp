#include <iostream>
#include <stdio.h>
#include "munit.h"
#include "funcaoFornecedor.h"

using namespace std;
#include <string>
#include <time.h>
#include "ClienteClass.h"
#include "FornecedorClass.h"
#include "funcaoCliente.h"
int main()
{
    int op=0,cad;
    setlocale(LC_ALL,"portuguese");

    while(op!=3)
    {
      printf("\n------------>MENU DE OPÇÕES<------------\n");
      printf("\n1-Cadastrar\n2-Pesquisar\n3-Sair\nDigite uma opcao: ");
      scanf("%d",&op);
      cad=0;
      if(op ==1)
      {
        printf("\n------------>OPÇÕES DE CADASTRO<------------\n");
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
            funcaoFornecedor ();
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

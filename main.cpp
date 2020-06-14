#include <iostream>
#include <stdio.h>
#include "munit.h"
#include "funcaoFuncionarios.h"

using namespace std;
#include <string>
#include <time.h>
#include "ClienteClass.h"
#include "FornecedorClass.h"
int main()
{
    int op=0,cad=0;
    while(op!=3)
    {
      printf("Digite uma opcao:\n1-cadastrar\n2-Pesquisar\n3-SAIR\n");
      scanf("%d",&op);
      cad=0;
      if(op ==1)
      {
        printf("Digite o que gostaria de cadastrar:\n1-cliente\n2-funcionario\n3-fornecedor\n4-festa\n");
        scanf("%d",&cad);
      }
      if(cad !=0)
      {
          switch(cad)
          {
          case 1:
            //colocar a funcao cliente aqui
          break;
          case 2:
            funcaoFuncionarios();
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

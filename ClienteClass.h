#ifndef CLIENTECLASS_H
#define CLIENTECLASS_H

using namespace std;
#include <string>

/*
Coment�rio do Henrique:
Normalmente � o mesmo nome do arquivo.
Para criar uma classe utilizando o codeblocks v� em -> File->New->Class (se o seu estiver em pt, traduz isso ae t� ok?)
Depois na tela de configura��o fica assim:  http://prntscr.com/sjryho
Ap�s isso ele vai perguntar se quer gerar para debug e release, e sim voc� quer.
*/
class ClienteClass
{
    /*
    Coment�rio do Henrique:
    Modificador public, n�o vou explicar o que � isso, � mat�ria pra frente da facul, s� saiba o seguinte,  colocando como public d� para pegar essas variaveis em outros arquivos
    Todas as variaveis aqui dentro compoem o objeto, vou exemplificar na fun��o main.
    */
    public: ClienteClass();
        int codigo;
        /*
        Coment�rio do Henrique:
        Essa forma de String que eu vou fazer aqui em baixo � mais facil que a que Ivre passou, por�m estamos conferindo com ela se pode usar isso, caso n�o possa, vai ser aquele bagulho de nome[255],gets,puts e o krl^4
        */
        string nome;
        string endereco;
        unsigned long telefone;
        string dtNascimento;
        float salario;
};

#endif // CLIENTECLASS_H

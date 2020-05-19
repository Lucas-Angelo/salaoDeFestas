#ifndef CLIENTECLASS_H
#define CLIENTECLASS_H

using namespace std;
#include <string>

/*
Comentário do Henrique:
Normalmente é o mesmo nome do arquivo.
Para criar uma classe utilizando o codeblocks vá em -> File->New->Class (se o seu estiver em pt, traduz isso ae tá ok?)
Depois na tela de configuração fica assim:  http://prntscr.com/sjryho
Após isso ele vai perguntar se quer gerar para debug e release, e sim você quer.
*/
class ClienteClass
{
    /*
    Comentário do Henrique:
    Modificador public, não vou explicar o que é isso, é matéria pra frente da facul, só saiba o seguinte,  colocando como public dá para pegar essas variaveis em outros arquivos
    Todas as variaveis aqui dentro compoem o objeto, vou exemplificar na função main.
    */
    public: ClienteClass();
        int codigo;
        /*
        Comentário do Henrique:
        Essa forma de String que eu vou fazer aqui em baixo é mais facil que a que Ivre passou, porém estamos conferindo com ela se pode usar isso, caso não possa, vai ser aquele bagulho de nome[255],gets,puts e o krl^4
        */
        string nome;
        string endereco;
        unsigned long telefone;
        string dtNascimento;
        float salario;
};

#endif // CLIENTECLASS_H

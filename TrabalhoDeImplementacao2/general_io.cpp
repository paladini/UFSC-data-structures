#include <algorithm>
#include <sstream>
#include <iostream> //cout
#include <fstream> //fstream
#include <cstring> //strcpy
#include <dirent.h>
#include <sys/stat.h>
#include <cstdlib>
#include "registro.hpp"
#include "estruturas/avl_tree.h"
#include "estruturas/doubly_linked_list.h"
#include <strings.h>
#include <vector>
using namespace std;

Registro ler_arquivo(string nomeDoArquivo) {
    
    // Abre o arquivo para leitura
    ifstream arquivoLido(nomeDoArquivo.c_str());

    // Verifica se o arquivo está mesmo aberto.
    if (arquivoLido.is_open()) {

        // O nome do arquivo é "ManPages/nomeDoComando.txt". Pega apenas o nomeDoComando.
        int pos_barra = nomeDoArquivo.find_last_of("/") + 1;
        int pos_ponto = nomeDoArquivo.find_last_of(".");
        int quantidadeDeCaracteres = pos_ponto - pos_barra;
        string nomeDoComando = nomeDoArquivo.substr(pos_barra, quantidadeDeCaracteres);

        // Copia todo o conteúdo do arquivo para o char "conteudo".
        char conteudo[200000];
        std::stringstream buffer;
        buffer << arquivoLido.rdbuf(); // lê o arquivo inteiro e coloca na variável buffer
        strcpy(conteudo, buffer.str().c_str());

        // Pega o nome do comando e armazena em uma variável.                
        char comando[80];
        strcpy(comando, nomeDoComando.c_str());

        // Cria um registro.
        Registro mr(comando, conteudo);

        // Fecha o arquivo.
        arquivoLido.close();

        // Retorna o registro criado.
        return mr;

    } else {
        throw "Arquivo não pode ser lido. Método ler_arquivo.";
    }
}

int procurar(int argc, char **argv) {

    // Pegando nome da página que está sendo procurada.
    string nomeDaPagina = argv[1];
    bool encontrouComando = false;

    // Carrega o arquivo de chaves primárias
    ifstream chavesPrimarias("chavesPrimarias.dat");

    // Enquanto não atingir o fim do arquivo vai procurando pelo comando
    string nomeDoComandoAtual, conteudo;
    while(!chavesPrimarias.eof()) {

        // Armazena apenas a primeira palavra, que é justamente o nome do comando.
        chavesPrimarias >> nomeDoComandoAtual;

        // Verifica se o comandoAtual é o comando procurado pelo usuário.
        if(strcasecmp(nomeDoComandoAtual.c_str(), argv[1]) == 0) {

            // Pega o conteúdo e pára quando encontra o "end of text" (\3), armazenando tudo em "conteudo".
            getline(chavesPrimarias, conteudo, '\3');

            // Imprime o conteúdo e sai.
            cout << conteudo;
            encontrouComando = true;
            break;
        } else {

            // Extrai todos os caracteres até o próximo \3 e ignora eles para o programa poder
            // analisar a próxima manpage. 
            chavesPrimarias.ignore(numeric_limits<streamsize>::max(), '\3');
        }
    }

    // Fecha o arquivo
    chavesPrimarias.close();

    if (!encontrouComando) {
        cout << "Desculpe, não foi possível encontrar esse comando." << endl;
    }
}

int indexar(int argc, char **argv){
    // Árvore AVL que armazena as chaves por indexação primária.
    avl_tree<Registro> indicesPrimarios;

    // Percorre todos os arquivos da pasta "ManPages/" (quando esta é passada como argumento utilizando "ManPages/*")
    for(int i = 1; i < argc; i++) {
        string nomeDoArquivo = argv[i];
        Registro mr = ler_arquivo(nomeDoArquivo);

        indicesPrimarios.insert(mr);
    }

    // Criando arquivo de saída
    ofstream arquivoSaida { "chavesPrimarias.dat" };  

    // Verificando se arquivo de saida foi aberto
    if(arquivoSaida.is_open()) {

        // Pega todos os registros da árvore AVL EM ORDEM e armazena no output.
        doubly_linked_list<Registro> registrosEmOrdem = indicesPrimarios.breadth_first();
        for(int i = 0; i < registrosEmOrdem.size(); i++) {
            arquivoSaida << registrosEmOrdem.at(i).retornarComando(); 
            arquivoSaida << " ";
            arquivoSaida << registrosEmOrdem.at(i).retornarConteudo();
            arquivoSaida << "\3"; // termina a escrita com um caracter "end of text".
        }

        // Fecha o arquivo.
        arquivoSaida.close();

    } else{
        return -1;
    }

    return 0;
}

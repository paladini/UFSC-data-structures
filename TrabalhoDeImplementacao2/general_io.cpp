#include <algorithm>
#include <sstream>
#include <iostream> //cout
#include <fstream> //fstream
#include <cstring> //strcpy
#include <dirent.h>
#include <sys/stat.h>
#include <strings.h>
#include <vector>
#include <cstdlib>
#include "utils/removedor_conectivos.cpp"
#include "registro.hpp"
#include "palavra.hpp"
#include "estruturas/avl_tree.h"
#include "estruturas/doubly_linked_list.h"
// #include "estruturas/NoAVL.hpp"

using namespace std;

/** Lê um arquivo do disco e armazena o seu conteúdo em um objeto Registro.
* Esse método lê um arquivo com disco com diretório fornecido como argumento e realiza duas coisas:
*
*   1 - Extrai o nome do comando do diretório fornecido e armazena.
*   2 - Lê o arquivo, extrai o conteúdo e armazena.
*
* Esses dados são armazenados em um objeto do tipo "Registro", que logo em seguida é 
* retornado para o método que o chamou.
*
* @param nomeDoArquivo o nome do arquivo que se deseja ler.
* @return Registro um registro que foi criado a partir do dado lido.
*/
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

/** Pesquisa no arquivo de indexação por chave primária o comando buscado pelo usuário.
* Este método verifica todo o arquivo "chavesPrimarias.dat" em busca do comando
* que está sendo pesquisado pelo usuário. Caso o comando procurado seja encontrado, é impresso
* na tela o "help" desse comando. Caso o comando não seja encontrado, imprime uma mensagem 
* informando o usuário do erro.
* @param busca O termo ou comando pesquisado pelo usuário.
*/
void procurar_chave_primaria(string busca) {

    bool encontrouComando = false;

    // Carrega o arquivo de chaves primárias
    ifstream chavesPrimarias("chavesPrimarias.dat");

    // Enquanto não atingir o fim do arquivo vai procurando pelo comando
    string nomeDoComandoAtual, conteudo;
    while(!chavesPrimarias.eof()) {

        // Armazena apenas a primeira palavra, que é justamente o nome do comando.
        chavesPrimarias >> nomeDoComandoAtual;

        // Verifica se o comandoAtual é o comando procurado pelo usuário.
        if(strcasecmp(nomeDoComandoAtual.c_str(), busca.c_str()) == 0) {

            // Pega o conteúdo e pára quando encontra o "end of text" (\3), armazenando tudo em "conteudo".
            getline(chavesPrimarias, conteudo, '\3');

            // Imprime o conteúdo e sai.
            cout << conteudo << endl;
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

    // Caso não tenha encontrado o comando, imprime um aviso ao usuário.
    if (!encontrouComando) {
        cout << "Desculpe, não foi possível encontrar esse comando." << endl;
    }
}

/** Indexa todas as manpages por chave primária e chave secundária.
* Método responsável por indexar todas as manpages por chave primária e chave secundária.
* Percorre as manpages dadas de acordo com o primeiro parâmetro do argv, lê cada arquivo e
* armazena em um Registro. Esse registro é adicionado como um índice primária e depois
* as suas palavras são refinadas através do removedor de conectivos para só então
* ser indexado por chave secundária.
*
* Depois de todo esse processo, escreve os arquivos indexados em "chvesPrimarias.dat" e 
* "chavesSecundarias.dat".
*
* @param argc Parâmetro passado como argumento ao programa na hora da execução.
* @param argv Parâmetro passado como argumento ao programa na hora da execução.
* @return int retorna 0 se o processo de indexação ocorreu como o esperado e retorna -1 caso algo tenha dado errado.
*/
int indexar(int argc, char **argv){

    // Árvore AVL que armazena as chaves por indexação primária.
    avl_tree<Registro> indicesPrimarios; 

    // Árvore AVL que armazena as chaves por indexação secundária.
    avl_tree<Palavra> indicesSecundarios;

    // Percorre todos os arquivos da pasta "ManPages/" (quando esta é passada como argumento utilizando "ManPages/*")
    for(int i = 1; i < argc; i++) {

        // Lê o arquivo manpage atual.
        string nomeDoArquivo = argv[i];
        Registro mr = ler_arquivo(nomeDoArquivo);

        // Adiciona na lista de índices primários
        indicesPrimarios.insert(mr);

        // Cria lista de conectivos proibidos e remove todas as palavras inválidas
        criar_lista_conectivos();
        vector<string> palavras_limpas = removedor_conectivos(mr.retornarConteudo());

        // Cria o índice das palavras inválidas
        for (int j = 0; j < palavras_limpas.size(); j++) {
            
            // Verifica se palavra já está nos índices secundários, se já estiver adiciona
            // o comando recém descoberto que possui essa palavra. Caso não exista no índice
            // secundário, adiciona.
            try{
                Palavra tentativa = indicesSecundarios.find(palavras_limpas.at(i))
                tentativa.adicionarComandosQueContem(mr.retornarComando());
            } catch (std::range_error& e) {
                Palavra p(palavras_limpas.at(i));
                p.adicionarComandosQueContem(mr.retornarComando());
                indicesSecundarios.insert(p);
            }
        }

    }

    // Criando arquivo de saída
    ofstream arquivoSaida("chavesPrimarias.dat");  

    // Verificando se arquivo de saida foi aberto
    if (arquivoSaida.is_open()) {

        // Pega todos os registros da árvore AVL EM ORDEM e armazena no output.
        vector<Registro> registrosEmOrdem = indicesPrimarios.breadth_first();
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

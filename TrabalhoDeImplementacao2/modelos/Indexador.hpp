#ifndef INDEXADOR_HPP_
#define INDEXADOR_HPP_
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
#include <list>
#include <limits>
#include <string>
#include "Registro.hpp"
#include "Palavra.hpp"
#include "Leitor.hpp"
#include "../estruturas/avl_tree.h"
#include "../estruturas/Lista.hpp"
#include "../utils/funcoes_strings.hpp"

using namespace std;
/** Classe Indexador.
* Essa classe servirá para indexar todas as manpages fornecidas como argumento ao programa.
* É responsável por criar os arquivos de índice por chave primária e por chave secundária.
*/
class Indexador {
 private:
        // Árvore AVL que armazena as chaves por indexação primária.
        avl_tree<Registro> indicesPrimarios; 

        // Árvore AVL que armazena as chaves por indexação secundária.
        avl_tree<Palavra> indicesSecundarios;

        // Armazena o argc passado como programa para o programa.
        int argc;

        // Armazena o argv passado como argumento para o programa.
        char **argv;

 public:
    /** Construtor padrão do Indexador.
    * Recebe como argumentos o argc e o argv passados para o programa. Os armazena em suas variáveis
    * privadas para uso futuro.
    */
    Indexador(int _argc, char **_argv) {
        argc = _argc;
        argv = _argv;
    }
    
    /**
    * Método que inicia o processo de indexação das manpages.
    */
    void criarIndexacao() {
        gerarIndex();
        gerarPrimarias();
        gerarSecundarias();
    }
    
    /**Método Indexar.
    * Indexa todas as manpages por chave primária e chave secundária.
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
    void gerarIndex(){
        // Percorre todos os arquivos da pasta "ManPages/" (quando esta é passada como argumento utilizando "ManPages/*")
        funcoes_strings conectivos;
        cout << "Criou a lista dos conectivos a serem removidos..." << endl;

        for(int i = 1; i < argc; i++) {
            cout << "Indexando manpages [ " << i << " de " << argc - 1 << " ]" << endl;

            // Lê o arquivo manpage atual.
            Leitor *read = new Leitor(argv[i]);
            Registro mr = read->ler_arquivo();

            // Adiciona na lista de índices primários
            indicesPrimarios.insert(mr);

            // Verifica palavra por palavra.
            string temp, comando = mr.retornarComando();
            stringstream stream(mr.retornarConteudo());
            while(stream >> temp) {

                // Coloca string em minúsculo
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

                // Limpa a palavra
                string limpa = conectivos.remover_conectivo_unica_palavra(temp);
                if(limpa.size() > 2) {

                    // Verifica se palavra já está nos índices secundários, se já estiver adiciona
                    // o comando recém descoberto que possui essa palavra. Caso não exista no índice
                    // secundário, adiciona.
                    try{
                        indicesSecundarios.find(limpa).adicionarComandosQueContem(comando);
                    } catch (std::range_error& e) {
                        Palavra p(limpa);
                        p.adicionarComandosQueContem(comando);
                        indicesSecundarios.insert(p);
                    }
                }

                // Limpa a string para a próxima palavra.
                temp.clear();
            }
        }
    }

    /**
    * Método que gera o arquivo de indexação das chaves primárias.
    * O arquivo escrito tem o nome de chavesPrimarias.dat e contém todas as 
    * chaves primárias em um protocolo criado exclusivamente para essa aplicação.
    */
    void gerarPrimarias() {
        // Criando arquivo de saída
        ofstream arquivoSaida("chavesPrimarias.dat");  

        // Verificando se arquivo de saida foi aberto
        if (arquivoSaida.is_open()) {

            // Pega todos os registros da árvore AVL EM ORDEM e armazena no arquivoSaida.
            vector<Registro> registrosEmOrdem = indicesPrimarios.breadth_first();
            for(int i = 0; i < registrosEmOrdem.size(); i++) {
                arquivoSaida << registrosEmOrdem.at(i).retornarComando(); 
                arquivoSaida << " ";
                arquivoSaida << registrosEmOrdem.at(i).retornarConteudo();
                arquivoSaida << "\3"; // termina a escrita com um caracter "end of text".
            }
            // Fecha o arquivo.
            arquivoSaida.close();

        }
    }

    /**
    * Método que gera o arquivo de indexação das chaves secundárias.
    * O arquivo escrito tem o nome de chavesSecundarias.dat e contém todas as 
    * chaves secundárias em um protocolo criado exclusivamente para essa aplicação.
    */
    void gerarSecundarias(){
        
        // Chaves secundárias
        ofstream chavesSecundarias("chavesSecundarias.dat");
        if (chavesSecundarias.is_open()) {
            
            // Pega todos os índices secundários
            vector<Palavra> palavrasEmOrdem = indicesSecundarios.breadth_first();
            for(int i = 0; i < palavrasEmOrdem.size(); i++) {
                
                // Armazena a palavra no arquivo (ou a "key")
                chavesSecundarias << palavrasEmOrdem.at(i).retornarPalavra();

                // Armazena todos os comandos que contem essa palavra
                Lista<string> comandos = palavrasEmOrdem.at(i).retornarComandosQueContem();
                for(int j = 0; j < comandos.retornaTamanho(); j++) {
                    chavesSecundarias << ' ' << comandos.retornaDado(j);
                }

                // Armazena um final de linha
                chavesSecundarias << endl;
            }

            // Fecha o arquivo.
            chavesSecundarias.close();

        }
    }
};
#endif
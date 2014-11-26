#ifndef BUSCADOR_HPP_
#define BUSCADOR_HPP_
#include <strings.h>
#include "../utils/funcoes_strings.hpp"
#include "../estruturas/Lista.hpp"
/**Classe Buscador
*Esta classe será responsável por buscar uma chave primária ou secundária nos arquivos .dat.
*Imprimindo o que foi encontrado na tela.
*/
class Buscador {
 private:
 	// Variável que armazena os termos de busca inseridos pelo usuário.
    string busca;

 public:
    /**Construtor do Buscador
    *Este contrutor receberá como parâmetro uma string com o nome do que o usuário quer buscar.
    *@param _busca Será o nome que o usuário quer procurar. Sendo armazenado na variável privada
    *busca da classe.
    */
	Buscador(string _busca) {
		busca = _busca;
	}
	 /**Método procurar_chave_secundaria.
    * Pesquisa no arquivo de indexação por chaves secundárias de acordo com os termos de busca do usuário. 
    * Esse método serve para fazer uma pesquisa por chaves secundárias de acordo com os critérios
    * de busca do usuário.
    *
    * Essa busca é exclusivamente conjuntiva, ou seja, os termos pesquisados pelo usuário serão 
    * utilizados de forma conjuntiva (E / and), mostrando apenas os comandos que possuem TERMO1 e
    * TERMO2 ao mesmo tempo.  
    *
    */
    void procurar_chave_secundaria() {

        // Uma lista com todos os comandos encontrados para os termos fornecidos.
        Lista<string> resultados;

        // Cria objeto que ajudará com métodos úteis para manipulação de strings
        funcoes_strings *func = new funcoes_strings();

        // Separa a string de busca fornecida pelo usuário em uma lista de termos.
        Lista<string> termos = func->separar_em_palavras(busca);

        // Pesquisa por cada termo independentemente.
        for(int i = 0; i < termos.retornaTamanho(); i++) {

            // Lê o arquivo de chaves secundárias
            ifstream chavesSecundarias("chavesSecundarias.dat");
            string temp;

            // Enquanto não atingir o fim do arquivo, continua procurando.
            while(!chavesSecundarias.eof()) {

                // Pega a primeira palavra e armazena em temp.
                chavesSecundarias >> temp;

                // Se a palavra for igual ao termo buscado pelo usuário
                if (strcasecmp(temp.c_str(),termos.retornaDado(i).c_str()) == 0) {

                    string linhaInteira;
                    
                    // Armazena a linha inteira (ou seja, todos os Comandos que contém essa palavra).
                    getline(chavesSecundarias, linhaInteira, '\n');
                    temp.clear();

                    // Armazena todos os comandos que contém essa palavra.
                    stringstream line(linhaInteira);
                    // doubly_linked_list<string> comandosQueContemPalavra;
                    Lista<string> comandosQueContemPalavra;

                    // Pega um comando por vêz e adiciona na lista encadeada "comandosQueContemPalavra".
                    while(line >> temp) {
                        comandosQueContemPalavra.adiciona(temp);
                        temp.clear();
                    }

                    // Faz a intersecção entre duas listas encadeadas, de acordo com algoritmo do professor.
                    if (resultados.retornaTamanho() > 0) {
                        resultados.interseccao(&comandosQueContemPalavra);
                    } else {
                        swap(resultados, comandosQueContemPalavra);
                    }
                }
            }
        }

        // Printa os valores
        if (resultados.retornaTamanho() > 0) {
            cout << "Essas são as páginas que contém os termos pesquisados:" << endl;
            for(int i = 0; i < resultados.retornaTamanho(); i++) {
                cout << resultados.retornaDado(i) << endl;  
            }
        } else {
            cout << "Os termos não foram encontrados, por favor, faça outra busca." << endl;
        }
    }

    /**Método procurar_chave_primaria.
    * Pesquisa no arquivo de indexação por chave primária o comando buscado pelo usuário.
    * Este método verifica todo o arquivo "chavesPrimarias.dat" em busca do comando
    * que está sendo pesquisado pelo usuário. Caso o comando procurado seja encontrado, é impresso
    * na tela o "help" desse comando. Caso o comando não seja encontrado, imprime uma mensagem 
    * informando o usuário do erro.
    */
    void procurar_chave_primaria() {

        // Variável para armazenar se o comando pesquisado foi encontrado ou não.
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
};
#endif
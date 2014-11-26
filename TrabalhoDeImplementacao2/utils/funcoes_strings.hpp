#ifndef FUNCOES_STRINGS_HPP_
#define FUNCOES_STRINGS_HPP_
#include <iostream> //cout
#include <fstream> //fstream
#include <cstring> //strcpy
// #include <vector>
#include <algorithm>	
#include <strings.h>
#include "../estruturas/Lista.hpp"
using namespace std;

/** Classe funcao_strings.
* Essa classe fornece diversas funções úteis para manipulação e criação de strings, char pointers
* e similares. Contém métodos para separar textos em vetores de palavras, remover conectivos proibidos,
* e muitas outras funções e procedimentos úteis para o programa.
*/
class funcoes_strings {
 private:

 	// Armazena todos os conectivos proibidos especificados pelo enunciado do problema.
 	Lista<string>* conectivosProibidos;

 	/**Método criarPronomes.
 	 * Adiciona pronomes em inglês à lista de conectivos proibidos.
 	 */
	void criarPronomes() {
		conectivosProibidos->adiciona("I");
		conectivosProibidos->adiciona("me");
		conectivosProibidos->adiciona("we");
		conectivosProibidos->adiciona("us");
		conectivosProibidos->adiciona("you");
		conectivosProibidos->adiciona("she");
		conectivosProibidos->adiciona("her");
		conectivosProibidos->adiciona("he");
		conectivosProibidos->adiciona("him");
		conectivosProibidos->adiciona("it");
		conectivosProibidos->adiciona("they");
		conectivosProibidos->adiciona("them");
		conectivosProibidos->adiciona("what");
		conectivosProibidos->adiciona("which");
		conectivosProibidos->adiciona("who");
		conectivosProibidos->adiciona("whom");
		conectivosProibidos->adiciona("whose");
		conectivosProibidos->adiciona("whichever");
		conectivosProibidos->adiciona("whoever");
		conectivosProibidos->adiciona("whomever");
		conectivosProibidos->adiciona("this");
		conectivosProibidos->adiciona("these");
		conectivosProibidos->adiciona("that");
		conectivosProibidos->adiciona("those");
		conectivosProibidos->adiciona("anybody");
		conectivosProibidos->adiciona("anyone");
		conectivosProibidos->adiciona("anything");
		conectivosProibidos->adiciona("each");
		conectivosProibidos->adiciona("either");
		conectivosProibidos->adiciona("everybody");
		conectivosProibidos->adiciona("everyone");
		conectivosProibidos->adiciona("everything");
		conectivosProibidos->adiciona("neither");
		conectivosProibidos->adiciona("nobody");
		conectivosProibidos->adiciona("nothing");
		conectivosProibidos->adiciona("one");
		conectivosProibidos->adiciona("somebody");
		conectivosProibidos->adiciona("someone");
		conectivosProibidos->adiciona("something");
		conectivosProibidos->adiciona("both");
		conectivosProibidos->adiciona("few");
		conectivosProibidos->adiciona("many");
		conectivosProibidos->adiciona("several");
		conectivosProibidos->adiciona("all");
		conectivosProibidos->adiciona("any");
		conectivosProibidos->adiciona("most");
		conectivosProibidos->adiciona("none");
		conectivosProibidos->adiciona("some");
		conectivosProibidos->adiciona("myself");
		conectivosProibidos->adiciona("ourselves");
		conectivosProibidos->adiciona("yourself");
		conectivosProibidos->adiciona("yourselves");
		conectivosProibidos->adiciona("himself");
		conectivosProibidos->adiciona("herself");
		conectivosProibidos->adiciona("itself");
		conectivosProibidos->adiciona("themselves");
		conectivosProibidos->adiciona("my");
		conectivosProibidos->adiciona("your");
		conectivosProibidos->adiciona("his");
		conectivosProibidos->adiciona("its");
		conectivosProibidos->adiciona("is");
		conectivosProibidos->adiciona("our");
		conectivosProibidos->adiciona("your");
		conectivosProibidos->adiciona("their");
		conectivosProibidos->adiciona("mine");
		conectivosProibidos->adiciona("yours");
		conectivosProibidos->adiciona("his");
		conectivosProibidos->adiciona("hers");
		conectivosProibidos->adiciona("ours");
		conectivosProibidos->adiciona("yours");
		conectivosProibidos->adiciona("theirs");
	}
	/**Método criarPreposicoes.
 	 * Adiciona preposições em inglês à lista de conectivos proibidos.
 	 */
	void criarPreposicoes() {
		conectivosProibidos->adiciona("aboard");
		conectivosProibidos->adiciona("about");
		conectivosProibidos->adiciona("above");
		conectivosProibidos->adiciona("across");
		conectivosProibidos->adiciona("after");
		conectivosProibidos->adiciona("against");
		conectivosProibidos->adiciona("ahead");
		conectivosProibidos->adiciona("along");
		conectivosProibidos->adiciona("amid");
		conectivosProibidos->adiciona("amidst");
		conectivosProibidos->adiciona("among");
		conectivosProibidos->adiciona("around");
		conectivosProibidos->adiciona("as");
		conectivosProibidos->adiciona("aside");
		conectivosProibidos->adiciona("at");
		conectivosProibidos->adiciona("athwart");
		conectivosProibidos->adiciona("atop");
		conectivosProibidos->adiciona("barring");
		conectivosProibidos->adiciona("because");
		conectivosProibidos->adiciona("before");
		conectivosProibidos->adiciona("behind");
		conectivosProibidos->adiciona("below");
		conectivosProibidos->adiciona("beneath");
		conectivosProibidos->adiciona("beside");
		conectivosProibidos->adiciona("besides");
		conectivosProibidos->adiciona("between");
		conectivosProibidos->adiciona("beyond");
		conectivosProibidos->adiciona("but");
		conectivosProibidos->adiciona("by");
		conectivosProibidos->adiciona("circa");
		conectivosProibidos->adiciona("concerning");
		conectivosProibidos->adiciona("despite");
		conectivosProibidos->adiciona("down");
		conectivosProibidos->adiciona("during");
		conectivosProibidos->adiciona("except");
		conectivosProibidos->adiciona("excluding");
		conectivosProibidos->adiciona("following");
		conectivosProibidos->adiciona("for");
		conectivosProibidos->adiciona("from");
		conectivosProibidos->adiciona("in");
		conectivosProibidos->adiciona("including");
		conectivosProibidos->adiciona("inside");
		conectivosProibidos->adiciona("instead");
		conectivosProibidos->adiciona("into");
		conectivosProibidos->adiciona("like");
		conectivosProibidos->adiciona("minus");
		conectivosProibidos->adiciona("near");
		conectivosProibidos->adiciona("of");
		conectivosProibidos->adiciona("off");
		conectivosProibidos->adiciona("on");
		conectivosProibidos->adiciona("onto");
		conectivosProibidos->adiciona("opposite");
		conectivosProibidos->adiciona("out");
		conectivosProibidos->adiciona("outside");
		conectivosProibidos->adiciona("over");
		conectivosProibidos->adiciona("past");
		conectivosProibidos->adiciona("plus");
		conectivosProibidos->adiciona("prior");
		conectivosProibidos->adiciona("regarding");
		conectivosProibidos->adiciona("regardless");
		conectivosProibidos->adiciona("save");
		conectivosProibidos->adiciona("since");
		conectivosProibidos->adiciona("tan");
		conectivosProibidos->adiciona("through");
		conectivosProibidos->adiciona("till");
		conectivosProibidos->adiciona("to");
		conectivosProibidos->adiciona("toward");
		conectivosProibidos->adiciona("towards");
		conectivosProibidos->adiciona("under");
		conectivosProibidos->adiciona("underneath");
		conectivosProibidos->adiciona("unlike");
		conectivosProibidos->adiciona("until");
		conectivosProibidos->adiciona("up");
		conectivosProibidos->adiciona("upon");
		conectivosProibidos->adiciona("versus");
		conectivosProibidos->adiciona("via");
		conectivosProibidos->adiciona("with");
		conectivosProibidos->adiciona("within");
		conectivosProibidos->adiciona("without");
	}
	/**Método criarConjuncoes.
 	 * Adiciona conjunções em inglês à lista de conectivos proibidos.
 	 */
	void criarConjuncoes() {
		conectivosProibidos->adiciona("for");
		conectivosProibidos->adiciona("and");
		conectivosProibidos->adiciona("nor");
		conectivosProibidos->adiciona("but");
		conectivosProibidos->adiciona("or");
		conectivosProibidos->adiciona("yet");
		conectivosProibidos->adiciona("so");
	}
	/**Método criarArtigos.
 	 * Adiciona artigos em inglês à lista de conectivos proibidos.
 	 */
	void criarArtigos() {
		conectivosProibidos->adiciona("a");
		conectivosProibidos->adiciona("an");
		conectivosProibidos->adiciona("the");
		conectivosProibidos->adiciona("no");
	}

 public:
	/** Criar lista dos conectivos proibidos que são descritos no enunciado do problema.
	* Adiciona à variável "conectivosProibidos" todos os conectivos proibidos que são descritos
	* no enunciado do problema (artigos, conjunções, preposição e pronome). 
	*/
	funcoes_strings() {
		// Armazena todos os conectivos proibidos especificados pelo enunciado do problema
		conectivosProibidos = new Lista<string>();

		// Adiciona artigos à lista de conectivos proibidos.
		criarArtigos();

		// Adiciona conjunções à lista de conectivos proibidos.
		criarConjuncoes();
		
		// Adiciona preposições à lista de conectivos proibidos.
		criarPreposicoes();
		
		// Adiciona pronomes à lista de conectivos proibidos.
		criarPronomes();

	}

	/** Remove os conectivos de uma palavra.
	* Esse método é responsável por verificar se essa é uma das palavras "proibidas" do programa
	* e caso seja deve tratar de alguma forma. As palavras "proibidas" são todas com menos de 
	* 3 caracteres e que estejam na lista dos conectivos proibidos. Todas as palavras restantes
	* poderão ser indexadas como chave secundária.
	*
	* @param string palavra a ser limpada / ter os conectivos removidos. 
	* @return string Retorna a própria palavra caso ela seja permitida ou retorna "" caso não seja.
	*/
	string remover_conectivo_unica_palavra(string palavra) {

		palavra = remover_caracteres_especiais(palavra);
		if (palavra.size() >= 3) {
			for(int i = 0; i < conectivosProibidos->retornaTamanho(); i++) {
				if(conectivosProibidos->retornaDado(i) == palavra) {
					return "";
				}
			}
		}
		return palavra;
	}

	/** Método que remove caracteres especiais de uma string dada.
	* Este método recebe uma string e deleta alguns caracteres especiais pré-definidos com o
	* intuíto de uma indexação por chave secundária ser melhor.
	* @param string palavra A palavra que terá seus caracteres especiais removidos. 
	* @return a string com os caracteres especiais removidos.
	*/
	string remover_caracteres_especiais(string palavra) {
		// Removendo caracteres especiais
		char caracteres[] = "<>():'#;,.";
		for (int i = 0; i < strlen(caracteres); ++i) {
			palavra.erase(remove(palavra.begin(), palavra.end(), caracteres[i]), palavra.end());
		}
		return palavra;
	}

	/** Método que separa os termos de busca em um vetor de strings.
	* Esse método serve para separar os termos de busca inseridos pelo usuário (no formato "termo1 termo2 termo3")
	* em um vetor de strings contendo 1 termo por posição. Isso será útil para poder fazer a 
	* busca disjuntiva por chave secundária depois.
	*
	* @param string o argumento com todos os termos de busca separados por espaços em branco.
	* @return vector<string> Um vetor contendo todas os termos conjuntivos de busca.
	*/
	Lista<string> separar_em_palavras(string busca) {

		// Atributo para armazenar todos as palavras da busca.
		Lista<string> termos;

		// Forma mais fácil de buscar palavra por palavra de um texto.
		string temp;
		stringstream stream(busca);
		while(stream >> temp) {
			termos.adiciona(temp);
		}
		
		return termos;
	}

};
#endif
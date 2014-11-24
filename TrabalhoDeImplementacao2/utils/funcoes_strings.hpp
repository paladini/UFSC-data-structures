#include <iostream> //cout
#include <fstream> //fstream
#include <cstring> //strcpy
#include <vector>
#include <strings.h>
using namespace std;

/** Classe funcao_strings.
* Essa classe fornece diversas funções úteis para manipulação e criação de strings, char pointers
* e similares. 
*
* Contém métodos para separar textos em vetores de palavras, remover conectivos proibidos,
* e muitas outras funções e procedimentos úteis para o programa.
*/
class funcoes_strings {
 private:

 	// Armazena todos os conectivos proibidos especificados pelo enunciado do problema.
 	vector<string>* conectivosProibidos;

 	/** 
 	 * Adiciona pronomes em inglês à lista de conectivos proibidos.
 	 */
	void criarPronomes() {
		conectivosProibidos->push_back("I");
		conectivosProibidos->push_back("me");
		conectivosProibidos->push_back("we");
		conectivosProibidos->push_back("us");
		conectivosProibidos->push_back("you");
		conectivosProibidos->push_back("she");
		conectivosProibidos->push_back("her");
		conectivosProibidos->push_back("he");
		conectivosProibidos->push_back("him");
		conectivosProibidos->push_back("it");
		conectivosProibidos->push_back("they");
		conectivosProibidos->push_back("them");
		conectivosProibidos->push_back("what");
		conectivosProibidos->push_back("which");
		conectivosProibidos->push_back("who");
		conectivosProibidos->push_back("whom");
		conectivosProibidos->push_back("whose");
		conectivosProibidos->push_back("whichever");
		conectivosProibidos->push_back("whoever");
		conectivosProibidos->push_back("whomever");
		conectivosProibidos->push_back("this");
		conectivosProibidos->push_back("these");
		conectivosProibidos->push_back("that");
		conectivosProibidos->push_back("those");
		conectivosProibidos->push_back("anybody");
		conectivosProibidos->push_back("anyone");
		conectivosProibidos->push_back("anything");
		conectivosProibidos->push_back("each");
		conectivosProibidos->push_back("either");
		conectivosProibidos->push_back("everybody");
		conectivosProibidos->push_back("everyone");
		conectivosProibidos->push_back("everything");
		conectivosProibidos->push_back("neither");
		conectivosProibidos->push_back("nobody");
		conectivosProibidos->push_back("nothing");
		conectivosProibidos->push_back("one");
		conectivosProibidos->push_back("somebody");
		conectivosProibidos->push_back("someone");
		conectivosProibidos->push_back("something");
		conectivosProibidos->push_back("both");
		conectivosProibidos->push_back("few");
		conectivosProibidos->push_back("many");
		conectivosProibidos->push_back("several");
		conectivosProibidos->push_back("all");
		conectivosProibidos->push_back("any");
		conectivosProibidos->push_back("most");
		conectivosProibidos->push_back("none");
		conectivosProibidos->push_back("some");
		conectivosProibidos->push_back("myself");
		conectivosProibidos->push_back("ourselves");
		conectivosProibidos->push_back("yourself");
		conectivosProibidos->push_back("yourselves");
		conectivosProibidos->push_back("himself");
		conectivosProibidos->push_back("herself");
		conectivosProibidos->push_back("itself");
		conectivosProibidos->push_back("themselves");
		conectivosProibidos->push_back("my");
		conectivosProibidos->push_back("your");
		conectivosProibidos->push_back("his");
		conectivosProibidos->push_back("its");
		conectivosProibidos->push_back("is");
		conectivosProibidos->push_back("our");
		conectivosProibidos->push_back("your");
		conectivosProibidos->push_back("their");
		conectivosProibidos->push_back("mine");
		conectivosProibidos->push_back("yours");
		conectivosProibidos->push_back("his");
		conectivosProibidos->push_back("hers");
		conectivosProibidos->push_back("ours");
		conectivosProibidos->push_back("yours");
		conectivosProibidos->push_back("theirs");
	}
	/** 
 	 * Adiciona preposições em inglês à lista de conectivos proibidos.
 	 */
	void criarPreposicoes() {
		conectivosProibidos->push_back("aboard");
		conectivosProibidos->push_back("about");
		conectivosProibidos->push_back("above");
		conectivosProibidos->push_back("across");
		conectivosProibidos->push_back("after");
		conectivosProibidos->push_back("against");
		conectivosProibidos->push_back("ahead");
		conectivosProibidos->push_back("along");
		conectivosProibidos->push_back("amid");
		conectivosProibidos->push_back("amidst");
		conectivosProibidos->push_back("among");
		conectivosProibidos->push_back("around");
		conectivosProibidos->push_back("as");
		conectivosProibidos->push_back("aside");
		conectivosProibidos->push_back("at");
		conectivosProibidos->push_back("athwart");
		conectivosProibidos->push_back("atop");
		conectivosProibidos->push_back("barring");
		conectivosProibidos->push_back("because");
		conectivosProibidos->push_back("before");
		conectivosProibidos->push_back("behind");
		conectivosProibidos->push_back("below");
		conectivosProibidos->push_back("beneath");
		conectivosProibidos->push_back("beside");
		conectivosProibidos->push_back("besides");
		conectivosProibidos->push_back("between");
		conectivosProibidos->push_back("beyond");
		conectivosProibidos->push_back("but");
		conectivosProibidos->push_back("by");
		conectivosProibidos->push_back("circa");
		conectivosProibidos->push_back("concerning");
		conectivosProibidos->push_back("despite");
		conectivosProibidos->push_back("down");
		conectivosProibidos->push_back("during");
		conectivosProibidos->push_back("except");
		conectivosProibidos->push_back("excluding");
		conectivosProibidos->push_back("following");
		conectivosProibidos->push_back("for");
		conectivosProibidos->push_back("from");
		conectivosProibidos->push_back("in");
		conectivosProibidos->push_back("including");
		conectivosProibidos->push_back("inside");
		conectivosProibidos->push_back("instead");
		conectivosProibidos->push_back("into");
		conectivosProibidos->push_back("like");
		conectivosProibidos->push_back("minus");
		conectivosProibidos->push_back("near");
		conectivosProibidos->push_back("of");
		conectivosProibidos->push_back("off");
		conectivosProibidos->push_back("on");
		conectivosProibidos->push_back("onto");
		conectivosProibidos->push_back("opposite");
		conectivosProibidos->push_back("out");
		conectivosProibidos->push_back("outside");
		conectivosProibidos->push_back("over");
		conectivosProibidos->push_back("past");
		conectivosProibidos->push_back("plus");
		conectivosProibidos->push_back("prior");
		conectivosProibidos->push_back("regarding");
		conectivosProibidos->push_back("regardless");
		conectivosProibidos->push_back("save");
		conectivosProibidos->push_back("since");
		conectivosProibidos->push_back("tan");
		conectivosProibidos->push_back("through");
		conectivosProibidos->push_back("till");
		conectivosProibidos->push_back("to");
		conectivosProibidos->push_back("toward");
		conectivosProibidos->push_back("towards");
		conectivosProibidos->push_back("under");
		conectivosProibidos->push_back("underneath");
		conectivosProibidos->push_back("unlike");
		conectivosProibidos->push_back("until");
		conectivosProibidos->push_back("up");
		conectivosProibidos->push_back("upon");
		conectivosProibidos->push_back("versus");
		conectivosProibidos->push_back("via");
		conectivosProibidos->push_back("with");
		conectivosProibidos->push_back("within");
		conectivosProibidos->push_back("without");
	}
	/** 
 	 * Adiciona conjunções em inglês à lista de conectivos proibidos.
 	 */
	void criarConjuncoes() {
		conectivosProibidos->push_back("for");
		conectivosProibidos->push_back("and");
		conectivosProibidos->push_back("nor");
		conectivosProibidos->push_back("but");
		conectivosProibidos->push_back("or");
		conectivosProibidos->push_back("yet");
		conectivosProibidos->push_back("so");
	}
	/** 
 	 * Adiciona artigos em inglês à lista de conectivos proibidos.
 	 */
	void criarArtigos() {
		conectivosProibidos->push_back("a");
		conectivosProibidos->push_back("an");
		conectivosProibidos->push_back("the");
		conectivosProibidos->push_back("no");
	}

 public:
	/** Criar lista dos conectivos proibidos que são descritos no enunciado do problema.
	* Adiciona à variável "conectivosProibidos" todos os conectivos proibidos que são descritos
	* no enunciado do problema (artigos, conjunções, preposição e pronome). 
	*/
	funcoes_strings() {
		// Armazena todos os conectivos proibidos especificados pelo enunciado do problema
		conectivosProibidos = new vector<string>();

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
		if (palavra.size() >= 3) {
			for(int i = 0; i < conectivosProibidos->size(); i++) {
				if(conectivosProibidos->at(i) == palavra) {
					return "";
				}
			}
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
	vector<string> separar_em_palavras(string busca) {

		// Atributo para armazenar todos as palavras da busca.
		vector<string> termos;

		// Forma mais fácil de buscar palavra por palavra de um texto.
		string temp;
		stringstream stream(busca);
		while(stream >> temp) {
			termos.push_back(temp);
		}
		
		return termos;
	}

};
/** Classe Palavra.
* Essa clase servirá para armazenar as palavras que fazem a indexação por chaves secundárias 
* do problema proposto. Serão armazenadas todas as palavras-chave do conteúdo das manpages e
* também todos
*
*/
#include <string>
#include "estruturas/doubly_linked_list.h"
#include <algorithm>

class Palavra {
private:

	// Atributo palavra.
	string palavra;

	// Lista duplamente encadeada que contém todos os comandos que estão associados à essa palavra.
	doubly_linked_list<string> comandosQueContem;

public:

	/** Construtor padrão da classe Palavra.
	* Recebe apenas uma palavra como argumento.
	* @param string a palavra que está sendo criada.
	*/
	Palavra(string _palavra) {
		palavra = _palavra;
	}

	/** Associa mais um comando a esta palavra.  
	* Este método faz sentido pois queremos armazenar todos os comandos que referenciam determinada
	* palavra. Só faz essa associação caso esse comando ainda não esteja associado com esta palavra.
	* 
	* @param string comando que vai ser associado com essa palavra.
	*/
	void adicionarComandosQueContem(string comando) {
		if(!comandosQueContem.has(comando)) {
			comandosQueContem.push_back(comando);
		}
	}

	/** 
	* Retorna a lista duplamente encadeada de comandos que estão associados à essa palavra.
	*/
	doubly_linked_list<string> retornarComandosQueContem() {
		return comandosQueContem;
	}

	/** 
	* Retorna o atributo palavra.
	*/
	string retornarPalavra() {
		return palavra;
	}
	
	/**
	* Sobrescrita do operador "<", que agora funciona de acordo com ordem das strings. 
	*/
	bool operator<(const Palavra& rhs) const {
		return palavra < rhs.palavra;
	}

};
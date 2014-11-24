#include <string>
// #include "estruturas/ListaEnc.hpp"
#include "estruturas/doubly_linked_list.h"
// #include <list>
// #include <vector>
#include <algorithm>

class Palavra {
private:
	string palavra;
	doubly_linked_list<string> comandosQueContem;
	// vector<string> comandosQueContem;
	// ListaEnc<string> comandosQueContem;
	// list<string> comandosQueContem;

public:

	Palavra(string _palavra) {
		palavra = _palavra;
	}

	void adicionarComandosQueContem(string comando) {
		// Verifica se NÃO existe na lista de comandos que contem.
		if(!comandosQueContem.has(comando)) {
			comandosQueContem.push_back(comando);
		}
		// if(!(std::find(comandosQueContem.begin(), comandosQueContem.end(), comando) != comandosQueContem.end())){
		// 	comandosQueContem.push_back(comando);
		// }
		// if (!comandosQueContem.contem(comando)) {
		// }
	}

	doubly_linked_list<string> retornarComandosQueContem() {
		return comandosQueContem;
	}

	string retornarPalavra() {
		return palavra;
	}
	
	bool operator<(const Palavra& rhs) const {
		return palavra < rhs.palavra;
	}

};
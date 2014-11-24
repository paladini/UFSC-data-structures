#include <iostream>
#include <cstdio>
#include <string>
#include "general_io.cpp"

using std::string;
using namespace std;

/** Método limparTela.
* Método que "limpa a tela" (basicamente dando vários clear na tela).
*/
void limparTela() {
	for (int i = 0; i < 10; i++) {
		system("clear");
	}
}

int pedirParaEspecificarBusca() {
	int opcao = -1, tentativas = 0;
	string dica = "";
	while (opcao < 1 || opcao > 2) {
		if (tentativas == 1) {
			dica = "[ COMANDO INVÁLIDO ]";
		}
		limparTela();
		cout << "Procurar por? " << dica << "\n" << endl;
		cout << "1 - Comando" << endl;
		cout << "2 - Palavra" << endl;
		cin >> opcaoDoUsuario;
		tentativas++;
	}
	return opcao;
}

int main(int argc, char **argv) {

	int opcaoDoUsuario = -1;
	limparTela();

	// Fazendo pergunta ao usuário
	cout << "O que você deseja fazer?\n" << endl;
	cout << "1 - Indexar" << endl;
	cout << "2 - Procurar" << endl;
	cout << "3 - Sair" << endl;
	cin >> opcaoDoUsuario;

	// Repetindo pergunta, caso seja necessário.
	while(opcaoDoUsuario < 1 || opcaoDoUsuario > 3) {
		limparTela();
		cout << "O que você deseja fazer? [OPÇÃO INVÁLIDA]\n" << endl;
		cout << "1 - Indexar" << endl;
		cout << "2 - Procurar" << endl;
		cout << "3 - Sair" << endl;
		cin >> opcaoDoUsuario;
	}

	// Detecta o que o usuário fez.
	switch(opcaoDoUsuario) {
			case 1: {
				limparTela();
				cout << "Comecando indexacao dos arquivos da manpages..." << endl;
				indexar(argc, argv);
				break;
			}
			case 2: {
				limparTela();

				// TERMINAR ISSO.
				// int tipoBusca = pedirParaEspecificarBusca();

				// switch(tipoBusca) {
				// 	case 1: {
				// 		pedir
				// 		break;
				// 	}
				// 	case 2: {

				// 	}
				// }
				// string pedirNome = pedirNomeDoComando();
				// procurar(argc, argv);
				// break;
			}
			default: {
				limparTela();
				cout << "Saindo..." << endl;
				break;
			}
	}

	return 0;
}
#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <limits>
#include "general_io.cpp"

using std::string;
using namespace std;

bool executar = true;
/** Método limparTela.
* Método que "limpa a tela" (basicamente dando vários clear na tela).
*/
void limparTela() {
	for (int i = 0; i < 10; i++) {
		system("clear");
	}
}

string pegarTermosBusca(int opcao) {
	string busca = "";

	// Imprimindo a opção que o usuário escolheu.
	string tipoDeBusca;
	if (opcao == 1) {
		tipoDeBusca = "[ PESQUISA POR COMANDO ]";
	} else {
		if (opcao == 2) {
			tipoDeBusca = "[ PESQUISA POR PALAVRAS ]";
		}
	}

	// Tentando pegar input do usuário
	while (busca.size() < 3) {
		limparTela();
		cout << tipoDeBusca << endl;
		cout << "Digite a busca que deseja realizar: "; // << endl;
		cin >> busca;		
	}
	return busca;
}

int especificarBusca() {
	int opcao = -1, tentativas = 0;
	string dica = "";
	while (opcao < 1 || opcao > 2) {
		if (tentativas == 1) {
			dica = "[ COMANDO INVÁLIDO ]";
		}
		limparTela();
		cout << "Por favor, seleciona uma opção. " << dica << endl;
		cout << "1 - Comando" << endl;
		cout << "2 - Palavra\n" << endl;
		cout << "Procurar por: "; //<< dica << endl;
		cin >> opcao;
		tentativas++;
	}
	return opcao;
}

int menuPrincipal() {
	int opcaoDoUsuario = -1, tentativas = 0;
	string status = "";

	// Fazendo pergunta ao usuário
	while(opcaoDoUsuario < 1 || opcaoDoUsuario > 3) {
		if (tentativas == 1) {
			status = " [ COMANDO INVÁLIDO ] ";
		}
		limparTela();
		cout << "O que você deseja fazer?" << status << "\n" << endl;
		cout << "1 - Indexar" << endl;
		cout << "2 - Procurar" << endl;
		cout << "3 - Sair\n" << endl;
		cout << "Opção: ";
		cin >> opcaoDoUsuario;
		tentativas++;
	}

	return opcaoDoUsuario;
}

int main(int argc, char **argv) {
	while(executar) {

		// Pede ao usuário
		int opcaoDoUsuario = menuPrincipal();

		// Detecta o que o usuário fez.
		switch(opcaoDoUsuario) {
			case 1: {
				limparTela();
				cout << "Comecando indexacao dos arquivos da manpages..." << endl;
				indexar(argc, argv);
				cout << "Indexado com sucesso!" << endl;
				sleep(2);
				break;
			}
			case 2: {
				limparTela();
				int opcao = especificarBusca();
				string busca = pegarTermosBusca(opcao);
				limparTela();

				cout << "COMANDO: " << busca << "\n" << endl;
				if (opcao == 1) {
					procurar_chave_primaria(busca);
				}
				if (opcao == 2) {
					cout << "De boa!" << endl;
				}

				// Esperando pelo input do usuário para avançar / voltar ao menu principal.
				string variavelQualquer;
				cout << "[ Para continuar pressione QUALQUER TECLA e depois ENTER ]" << endl;
				cin >> variavelQualquer;
				break;
			}
			default: {
				limparTela();
				cout << "Saindo..." << endl;
				sleep(2);
				executar = false;
				limparTela();
				break;
			}
		}
	}
	

	return 0;
}
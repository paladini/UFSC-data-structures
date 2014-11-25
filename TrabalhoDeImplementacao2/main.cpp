#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <limits>
#include "modelos/Indexador.hpp"
#include "modelos/Buscador.hpp"
//#include "leitor.hpp"

using std::string;
using namespace std;

// Variável auxiliar para determinar se o loop do programa continua.
bool executar = true;

/** Método limparTela.
* Método que "limpa a tela" (basicamente dando vários clear na tela).
*/
void limparTela() {
	for (int i = 0; i < 10; i++) {
		system("clear");
	}
}

/** Pede ao usuário os termos para busca nos arquivos de índice.
* Este método pede ao usuário os termos de busca que ele deseja utilizar na pesquisa
* por chaves primárias ou secundárias. 
* @param int opcao A opcao de busca que o usuário informou anteriormente. (1 = pesquisa por comando | 2 = pesquisa por palavras)
* @return os termos de busca inseridos pelo usuário.
*/
string pegarTermosBusca(int opcao) {
	string busca = "";

	// Imprimindo a opção que o usuário escolheu.
	string tipoDeBusca;
	if (opcao == 1) {
		tipoDeBusca = "[ PESQUISA POR COMANDO ]";
		while (busca.size() < 3) {
			limparTela();
			cout << tipoDeBusca << endl;
			cout << "Digite a busca que deseja realizar: ";
			cin >> busca;		
		}
	} else {
		if (opcao == 2) {
			tipoDeBusca = "[ PESQUISA POR PALAVRAS ]";
			while (busca.size() < 3) {
				limparTela();
				cout << tipoDeBusca << endl;
				cout << "Digite a busca que deseja realizar: ";

				// Precisa ser getline para poder pegar todos os termos e não somente os termos até o primeiro espaço.
				getline(cin, busca);		
			}
		}
	}

	return busca;
}

/** Tela que pede para o usuário que tipo de busca ele quer fazer.
* Essa tela pergunta ao usuário se ele deseja fazer uma busca por Comando (opção "1"),
* por Palavra (opção "2") ou se ele deseja voltar ao menu principal (opção "3").
*
* @return int a opção do usuário.
*/
int especificarBusca() {
	int opcao = -1, tentativas = 0;
	string dica = "";
	while (opcao < 1 || opcao > 3) {
		if (tentativas == 1) {
			dica = "[ COMANDO INVÁLIDO ]";
		}
		limparTela();
		cout << "Por favor, seleciona uma opção. " << dica << endl;
		cout << "1 - Comando" << endl;
		cout << "2 - Palavra" << endl;
		cout << "3 - Voltar\n" << endl;
		cout << "Procurar por: "; //<< dica << endl;
		cin >> opcao;
		tentativas++;
	}
	return opcao;
}

/** Tela que imprime para o usuário o menu principal do programa.
* Essa tela é a tela principal do programa. Ela pergunta ao usuário qual ação este deseja
* tomar e retorna um inteiro indicando para o main() do programa qual é a ação desejada.
*
* @return int a opção do usuário.
*/
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
		cout << "1 - Começar a execução" << endl;
		cout << "2 - Procurar" << endl;
		cout << "3 - Sair\n" << endl;
		cout << "Opção: ";
		cin >> opcaoDoUsuario;
		tentativas++;
	}

	return opcaoDoUsuario;
}

/** Rotina principal do programa.
* Esse método é responsável por gerenciar o programa, manter o fluxo de execução e tomar as decisões
* de acordo com as entradas do usuário. 
*/
int main(int argc, char **argv) {

	// Cria objeto indexador.
	Indexador *index = new Indexador(argc, argv);

	while(executar) {

		// Pede ao usuário
		int opcaoDoUsuario = menuPrincipal();
		// Detecta o que o usuário fez.
		switch(opcaoDoUsuario) {

			// Indexar arquivos
			case 1: {
				limparTela();
				cout << "Comecando indexacao dos arquivos da manpages..." << endl;
				index->criarIndexacao();
				cout << "Indexado com sucesso!" << endl;
				sleep(2);
				break;
			}

			// Pesquisar
			case 2: {
				limparTela();
				int opcao = especificarBusca();
				
				// Voltar ao menu principal
				if(opcao == 3){
					break;
				}

				string busca = pegarTermosBusca(opcao);
				Buscador *buscar = new Buscador(busca);
				limparTela();

				// Pesquisar por comando
				if (opcao == 1) {
					cout << "COMANDO: " << busca << "\n" << endl;
					buscar->procurar_chave_primaria();
				}
				// Pesquisar por termos
				if (opcao == 2) {
					cout << "TERMOS: " << busca << "\n" << endl;
					buscar->procurar_chave_secundaria();
				}

				// Esperando pelo input do usuário para avançar / voltar ao menu principal.
				string variavelQualquer = "";
				cout << "\n[ Para continuar pressione QUALQUER TECLA e depois ENTER ]" << endl;
				while(variavelQualquer.size() < 1) {
					cin >> variavelQualquer;
				}
				break;
			}
			default: {
				limparTela();
				cout << "Saindo..." << endl;
				sleep(1);
				executar = false;
				limparTela();
				break;
			}
		}
	}
	
	return 0;
}
#include <iostream>
#include <stdlib.h>
#include "Sistema.hpp"
#include <cstdio>
#include <string>

using std::string;

// Variáveis
int opcao = -1;
int tempoAberturaSemaforo = -1;
int tempoDeExecucao = -1;
int temporizacao = -1;
string temporizacaoUtilizada;

/** Método limparTela.
* Método que "limpa a tela" (basicamente dando vários clear na tela).
*/
void limparTela() {
	for (int i = 0; i < 10; i++) {
		system("clear");
	}
}

/** Método pedeMetrica.
* Método que pede ao usuário uma métrica de temporização (segundos / minutos / horas).
* Essa métrica será multiplicada depois pelo tempo de execução do programa e pelo tempo de 
* abertura dos semáforos.
*/
void pedeTemporizacao() {
	bool continuar = true;
	while(continuar) {
		limparTela();
		int opt;
		std::cout << "Qual a temporização deseja usar?" << std::endl;
		std::cout << "\n\t1 - Padrão (Segundos)" << std::endl;
		std::cout << "\t2 - Minutos" << std::endl;
		std::cout << "\t3 - Horas" << std::endl;
		std::cout << "\nOpção escolhida:" << std::endl;
		std::cin >> opt;
		if(opt > 0) {
			continuar = false;

			switch(opt) {
				case 1: {
					temporizacao = 1;
					temporizacaoUtilizada = "segundo(s)";
					break;
				}
				case 2: {
					temporizacao = 60;
					temporizacaoUtilizada = "minuto(s)";
					break;
				}
				case 3: {
					temporizacao = 3600;
					temporizacaoUtilizada = "hora(s)";
					break;
				}
				default: {
					std::cout << "Problema na temporizacao!" << std::endl;
				}
			}
		}
	}
}

/** Método pedeTempoDeExecucao.
* Método que pede ao usuário o tempo de execucação do sistema, que depois será multiplicado
* pela temporização escolhida pelo usuário anteriormente (segundos / minutos / horas).
*/
void pedeTempoDeExecucao() {
	bool continuar = true;
	while(continuar) {
		limparTela();
		std::cout << "Informe o tempo de execução (em " << temporizacaoUtilizada << "):" << std::endl;
		std::cin >> tempoDeExecucao;
		if(tempoDeExecucao > 0) {
			continuar = false;
		}
	}
}

/** Método pedeTempoSemaforo.
* Método que pede ao usuário o tempo que cada semáforo ficara aberto e/ou fechado, ou seja, o intervalo
* de cada semáforo. Esse valor também será multiplicado pela temporização escolhida pelo usuário
* anteriormente (segundos / minutos / horas).
*/
void pedeTempoSemaforo() {
	bool continuar = true;
	while(continuar) {
		limparTela();
		std::cout << "Informe o tempo de abertura do semáforo (em " << temporizacaoUtilizada << "):" << std::endl;
		std::cin >> tempoAberturaSemaforo;
		if(tempoAberturaSemaforo > 0) {
			continuar = false;
		}
	}
}

int main() {
	limparTela();
	std::cout << "" << std::endl;
	std::cout << "=====================================================" << std::endl;
	std::cout << "#      S I M U L A D O R   D E   T R Á F E G O      #" << std::endl;
	std::cout << "=====================================================" << std::endl;
	std::cout << "\n\t1 - Iniciar!" << std::endl;
	std::cout << "\t2 - Sair!" << std::endl;
	std::cout << "\nPor favor, escolha uma opção: " << std::endl;
	std::cin >> opcao;
	
	switch (opcao) {	
		case 1: {
			limparTela();
			pedeTemporizacao();
			pedeTempoDeExecucao();
			pedeTempoSemaforo();
			limparTela();
			Sistema *sistema = new Sistema(tempoAberturaSemaforo*temporizacao, tempoDeExecucao*temporizacao);
			sistema->iniciar();
			break;
		}
		default: {
			limparTela();
			std::cout << "Opção inválida! Saindo..." << std::endl;
			break;
		}
	}
	return 0;
}

/*ART BY PALADINI*/
#include <iostream>
#include <stdlib.h>
#include "Sistema.hpp"
#include <cstdio>
#include <string>

using std::string;

// Variáveis
int opcao = -1;
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
int pedeTemporizacao() {
	while(true){
		limparTela();
		int opt = -1;
		std::cout << "Qual a temporização deseja usar?" << std::endl;
		std::cout << "\n\t1 - Padrão (Segundos)" << std::endl;
		std::cout << "\t2 - Minutos" << std::endl;
		std::cout << "\t3 - Horas" << std::endl;
		std::cout << "\nOpção escolhida:" << std::endl;
		std::cin >> opt;
		if(opt > 0) {
			switch(opt) {
				case 1: {
					temporizacaoUtilizada = "segundo(s)";
					return 1;
				}
				case 2: {
					temporizacaoUtilizada = "minuto(s)";
					return 60;
				}
				case 3: {
					temporizacaoUtilizada = "hora(s)";
					return 3600;
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
*
* @return int Inteiro fornecido pelo usuário que indica.
*/
int pedeTempoDeExecucao() {
	int tempoDeExecucao = -1;
	while(true) {
		limparTela();
		std::cout << "Informe o tempo de execução (em " << temporizacaoUtilizada << "):" << std::endl;
		std::cin >> tempoDeExecucao;
		if(tempoDeExecucao > 0) {
			return tempoDeExecucao;
		}
	}
}

/** Método pedeTempoSemaforo.
* Método que pede ao usuário o tempo que cada semáforo ficara aberto e/ou fechado, ou seja, o intervalo
* de cada semáforo. Esse valor também será multiplicado pela temporização escolhida pelo usuário
* anteriormente (segundos / minutos / horas).
* 
* @return int Inteiro fornecido pelo usuário que indica quanto tempo os semaforos ficaram abertos / fechados.
*/
int pedeTempoSemaforo() {
	// bool continuar = true;
	int tempoAberturaSemaforo = -1;
	// while(continuar) {
	while(true) {
		limparTela();
		std::cout << "Informe o tempo de abertura do semáforo (em " << temporizacaoUtilizada << "):" << std::endl;
		std::cin >> tempoAberturaSemaforo;
		if(tempoAberturaSemaforo > 0) {
			return tempoAberturaSemaforo;
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
			int temporizacao = pedeTemporizacao();
			int tempoDeExecucao = pedeTempoDeExecucao();
			int tempoAberturaSemaforo = pedeTempoSemaforo();
			limparTela();
			Sistema *sistema = new Sistema(tempoAberturaSemaforo*temporizacao, tempoDeExecucao*temporizacao);
			return sistema->iniciar();
		}
		case 2: {
			limparTela();
			std::cout << "Obrigado por utilizar o    S I M U L A D O R   D E   T R A F E G O    9 0 0 0  " << std::endl;
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
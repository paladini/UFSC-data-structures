#include <iostream>
#include <stdlib.h>
#include "Sistema.hpp"
#include <cstdio>

// Variáveis
int opcao = -1;
int tempoAberturaSemaforo = -1;
int tempoDeExecucao = -1;

void limparTela() {
	for (int i = 0; i < 10; i++) {
		system("clear");
	}
}

void pedeTempoDeExecucao() {
	bool continuar = true;
	while(continuar) {
		std::cout << "Informe o tempo de execução: " << std::endl;
		std::cin >> tempoDeExecucao;
		if(tempoDeExecucao > 0) {
			continuar = false;
		}
	}
}

void pedeTempoSemaforo() {
	bool continuar = true;
	while(continuar) {
		std::cout << "Informe o tempo de abertura do semáforo: " << std::endl;
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
			pedeTempoDeExecucao();
			pedeTempoSemaforo();
			Sistema *sistema = new Sistema(tempoAberturaSemaforo, tempoDeExecucao);
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
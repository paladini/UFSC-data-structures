#include <iostream>
#include <stdlib.h>
#include "Sistema.hpp"

// Variáveis
int opcao = -1;
int tempoAberturaSemaforo = -1;
int tempoDeExecucao = -1;

void limparTela() {
	for(int i = 0; i < 10; i++) {
		system("clear");
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

int main() {
	limparTela();
	std::cout << "" << std::endl;
	std::cout << "=====================================================" << std::endl;
	std::cout << "#   S I M U L A D O R   D E   T R A F E G O  9000   #" << std::endl;
	std::cout << "=====================================================" << std::endl;
	std::cout << "\n\t1 - O barato é louco e o processo é lento... a não ser que 'cê tenha um processador quadcore, que ai processo fica menos lento" << std::endl;
	std::cout << "\t2 - A treta é barata" << std::endl;
	std::cout << "\t3 - Sair" << std::endl;
	std::cout << "\nPor favor, escolha uma opção: " << std::endl;
	std::cin >> opcao;

	switch (opcao) {
		case 1:
			limparTela();
			pedeTempoDeExecucao();
			pedeTempoSemaforo();
			Sistema sistema = new Sistema(tempoAberturaSemaforo, tempoDeExecucao);
			sistema.queComecemOsJogos();
			break;
		case 2: 
			limparTela();
			std::cout << "A treta é barata" << std::endl;
			break;
		case 3:
			limparTela();
			std::cout << "Qual o negócio?" << std::endl;
			std::cout << "comer..." << std::endl;
			break;
		default:
			limparTela();
			std::cout << "Opção inválida! Saindo..." << std::endl;
			return -1;
	}
	return 0;
}

/*ART BY PALADINI*/
#include <iostream>
#include <stdlib.h>
#include "Sistema.hpp"

// Variáveis
int opcao = -1;
long tempoAberturaSemaforo = -1;
long long tempoDeExecucao = -1;

void limparTela() {
	for(int i = 0; i < 10; i++) {
		system("clear");
	}
}

void pedeTempoDeExecucao() {
	bool continuar = true;
	while(continuar) {
		std::cout << "Informe o tempo de execução: " << std::endl;
		std::cin >> tempoDeExecucao;
		if(tempoDeExecucao > 0) {
			continuar = false; // overflow de int 128 bits faz o input ficar sendo executado, tratar o overflow
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
	std::cout << "#      S I M U L A D O R   D E   T R A F E G O      #" << std::endl;
	std::cout << "=====================================================" << std::endl;
	std::cout << "\n\t1 - O barato é louco e o processo é lento... a não ser que 'cê tenha um processador quadcore, que ai processo fica menos lento" << std::endl;
	std::cout << "\t2 - Se você quer parar com a zueira." << std::endl;
	std::cout << "\t3 - A treta é barata" << std::endl;
	std::cout << "\t4 - Sair" << std::endl;
	std::cout << "\nPor favor, escolha uma opção: " << std::endl;
	
	switch (opcao) {	
		case 1: {
			limparTela();
			pedeTempoDeExecucao();
			pedeTempoSemaforo();
			Sistema *sistema = new Sistema(tempoAberturaSemaforo, tempoDeExecucao);
			sistema->iniciar();
			break;
		}
		case 2: {
			limparTela();
			std::cout << "A zueira não para, ela não tem limites." << std::endl;
			break;
		}
		case 3: {
			limparTela();
			std::cout << "A treta é barata." << std::endl;
			break;
		}
		case 4: {
			limparTela();
			std::cout << "Qual o negócio?" << std::endl;
			std::cout << "comer..." << std::endl;
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
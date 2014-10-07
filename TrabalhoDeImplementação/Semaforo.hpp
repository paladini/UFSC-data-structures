#ifndef SEMAFORO_HPP
#define SEMAFORO_HPP
#include "Lista.hpp"
#include "Pista.hpp"
#include "ExcecaoSinalVermelho.hpp"
#include <iostream>
#include <cstdio>

class Semaforo {
 private:
	Lista<Pista<Carro>*>* pistas;
	Pista<Carro>* pistaLocal;
	int tempoIntervalo;
	int *probabilidades;
	int tempoQueVaiAbrir; 
	bool aberto;
 public:
 	// array[] = {atual, frente, direita, esquerda};
 	// ATUAL = 0;
 	// FRENTE = 1;
 	// ESQUERDA = 2;
 	// DIREITA = 3;
 	// 0 0 0 0 0 0 0 0 1 2

 	// COLOCAR NO CONSTRUTOR SE SEMÁFORO ESTÁ ABERTO OU FECHADO.
	Semaforo(bool _estaAberto, Pista<Carro>* arranjo[], int *_probabilidades, int _tempoIntervalo /*, int _carroNoSistema*/) {
		pistas = new Lista<Pista<Carro>*>(3);
		probabilidades = _probabilidades;
		// pistas.adiciona (pistaLocal);
		tempoIntervalo = _tempoIntervalo;
		tempoQueVaiAbrir = 0;
		aberto = _estaAberto;
		pistaLocal = arranjo[0];
		pistas->adiciona(arranjo[1]);
		pistas->adiciona(arranjo[2]);
		pistas->adiciona(arranjo[3]);
	}

	Pista<Carro>* passaCarro() {
		Carro c = pistaLocal->primeiro();

		int pistaEscolhida = calculaProbabilidade(c);
		Pista<Carro>* proxima = pistas->mostra(pistaEscolhida);
		if(isAberto()) {
			if (!proxima->estaCheia(c) && isAberto()) {
				pistaLocal->removeCarro();
				proxima->adicionaCarro(c);
				return proxima;
			} else {
				proxima = pistaLocal;
			}
		} else {
			throw ExcecaoSinalVermelho;
		}
		return proxima;
	}
	
	// void atualiza(int tempoAtual, int tempoSemaforo) {
	// 	if (tempoAtual <= tempoSemaforo) {
	// 		std::cout << "A traffic light is green. Actual time is " << tempoAtual << std::endl;
	//         passaCarro(tempoAtual);
	//         // pistaLocal->atualizaPista(tempoAtual, tempoSemaforo);
	// 	} else {
	// 		// tinha um else aqui
	// 		std::cout << "A traffic light is red. Actual time is " << tempoAtual << std::endl;	
	//     	pistaLocal->atualizaPista(tempoAtual, tempoSemaforo);
 //    	}
 //    	std::cout << "A traffic light is red. Actual time is " << tempoAtual << std::endl;	
 //    }
	
	//listaCircular com todos as pistas e atualizar elas separadas dos semaforos.
	// void passaCarro(int tempoAtual) {
	// 	if (!pistaLocal->filaVazia()) {
	// 		Carro carroAtual = pistaLocal->primeiro();
	// 		bool possivel = true;
	// 		Pista<Carro>* proxima;
	// 		while (possivel) {
	// 			if (pistaLocal->estaNoSemaforo(carroAtual, tempoAtual) 
	// 				&& pistaLocal->getFonte() && !pistaLocal->filaVazia()) {
	// 				carroAtual = pistaLocal->primeiro();
	// 			  	int pistaEscolhida = calculaProbabilidade(carroAtual);
	// 			    proxima = pistas->mostra(pistaEscolhida);
	// 			    //this->proximaPista(carroAtual->getProbabilidade());
	// 			    std::cout << "A car passed through a traffic light" << std::endl;
	// 			   	proxima->adicionaCarro(carroAtual);
	// 				pistaLocal->removeCarroSemMensagem(tempoAtual);
	// 	    	} else {
	// 	    		possivel = false;
	// 	    	}
	//     	}
	// 	}
	// }

	void trocarAberto(int tempoAtual) {
		if (aberto) {
			aberto = false;
			calculeProximoEvento(tempoAtual);
		} else {
			aberto = true;
		}
	}

	int calculeProximoEvento(int tempoAtual) {
		tempoQueVaiAbrir = tempoAtual + tempoIntervalo;
		return tempoQueVaiAbrir;
	}

	int calculaProbabilidade(Carro c) {
		int *prob = probabilidades;
		int numPistas = pistas->retornaTamanho();
		int probabilidadeDoCarro = c.getProbabilidade();					//sorteio de um nr inteiro entre 1 e 100
		int valorComp[numPistas];						//vetor para valores de comparação do Método de Monte Carlo
		valorComp[0] = prob[0];							//o primeiro valor de comparacao é a primeira probabilidade
		for (int i = 1; i < (numPistas - 1); i++) {
			valorComp[i] = valorComp[i - 1] + prob[i];	//soma as faixas de comparação
		}
		for (int i = 0; i < numPistas; i++) {
			if (probabilidadeDoCarro <= valorComp[i]) {
				return i;
			}
		}
		return -1;
	}

	int retornaIntervalo() {
		return tempoIntervalo;
	}

	bool isAberto() {
		return aberto;
	}

	Pista<Carro>* retornaPistaLocal() {
		return pistaLocal;
	}

	int retornarTempoQueVaiAbrir() {
		return tempoQueVaiAbrir;
	}
};

#endif

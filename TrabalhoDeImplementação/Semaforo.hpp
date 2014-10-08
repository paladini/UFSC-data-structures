#ifndef SEMAFORO_HPP
#define SEMAFORO_HPP
#include "Lista.hpp"
#include "Pista.hpp"
#include "ExcecaoSinalVermelho.hpp"
#include <iostream>
#include <cstdio>
/** Classe Semáforo
* Esta classe será responsável por representar um semáforo no sistema. Será instanciado objetos dessa classe
* para representar semáforos e métodos para executar suas funções que são, basicamente: passar o carro, trocar
* o seu estado, calcular a próxima vez que o semáforo estará aberto e a probabilidade de um carro virar em uma
* pista.
*/
class Semaforo {
 private:
	Lista<Pista*>* pistas;
	Pista* pistaLocal;
	int tempoIntervalo;
	int *probabilidades;
	int tempoQueVaiAbrir; 
	bool aberto;
 public:
/* Construtor Semáforo
* Construirá um semáforo com o número de pistas ligadas à ele, a probabilidade de um carro virar e
* o intervalo do semáforo. Note que elementos são adicionados na lista pistas dentro do construtor.
*/
	Semaforo(bool _estaAberto, Pista* arranjo[], int *_probabilidades, int _tempoIntervalo) {
		pistas = new Lista<Pista*>(3);
		probabilidades = _probabilidades;
		tempoIntervalo = _tempoIntervalo;
		tempoQueVaiAbrir = 0;
		aberto = _estaAberto;
		pistaLocal = arranjo[0];
		pistas->adiciona(arranjo[1]);
		pistas->adiciona(arranjo[2]);
		pistas->adiciona(arranjo[3]);
	}

	Pista* passaCarro() {
		Carro* c = pistaLocal->primeiro();

		int pistaEscolhida = calculaProbabilidade(c);
		Pista* proxima = pistas->mostra(pistaEscolhida);
		if(isAberto()) {
			if (!proxima->estaCheia(c)) {
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

	int calculaProbabilidade(Carro* c) {
		int *prob = probabilidades;
		int numPistas = pistas->retornaTamanho();
		int probabilidadeDoCarro = c->getProbabilidade();
		int valorComp[numPistas];
		valorComp[0] = prob[0];					
		for (int i = 1; i < (numPistas - 1); i++) {
			valorComp[i] = valorComp[i - 1] + prob[i];
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

	Pista* retornaPistaLocal() {
		return pistaLocal;
	}

	int retornarTempoQueVaiAbrir() {
		return tempoQueVaiAbrir;
	}
};

#endif

#ifndef PISTA_HPP_
#define PISTA_HPP_
#include "FilaEnc.hpp"
#include "Carro.hpp"
#include <iostream>

template<typename T>
class Pista : public FilaEnc<T> {
private: 
	int tamanho, espacoOcupado, velocidadeMedia, proximaAtividade, tempoPadraoDeChegada, intervaloInvocacao, tempoDeInvocacao, tempoDeInvocacaoPositivo,tempoDeInvocacaoNegativo;
	bool fonte;

public:
	Pista(int tam, int _velocidadeMedia, bool _fonte, int _intervaloInvocacao, int _tempoDeInvocacao) : FilaEnc<Carro>() {
		tamanho = tam;
		espacoOcupado = 0;
		velocidadeMedia = _velocidadeMedia;
		proximaAtividade = calculeProximoEvento(0);
		tempoPadraoDeChegada = tamanho / velocidadeMedia;
		fonte = _fonte;
		tempoDeInvocacaoPositivo = _tempoDeInvocacao + _intervaloInvocacao;
		tempoDeInvocacaoNegativo = _tempoDeInvocacao - _intervaloInvocacao;
		if (!fonte) {
			tempoDeInvocacaoPositivo = 0;
			tempoDeInvocacaoNegativo = 0;
		}
	}

	void adicionaCarro(Carro c) {
		int espacoOcupadoComCarro = espacoOcupado + c.getTamanho();
		if (espacoOcupadoComCarro > tamanho) {
			throw -1; // Excecao pista cheia / bloqueada
		}
		this->inclui(c);
		espacoOcupado = espacoOcupadoComCarro;
	}

	void removeCarro() {
		T carroRetirado = this->retira();
		// carroNoSistema++;
	}

	void atualiza(int tempoAtual, int tempoSemaforo) {
	    if (fonte) {
	        if (tempoAtual + tempoSemaforo > proximaAtividade) {
	            std::cout << "A car just arrived!" << std::endl;
	      	    adicionaCarro(Carro(tempoAtual));
	        	calculeProximoEvento(tempoAtual);
	      	}
	      	return;
	    }
	    std::cout << "A car's gone!" << std::endl;
	    removeCarro();
	    calculeProximoEvento(tempoAtual);
	}

	void calculeProximoEvento(int tempoAtual) {
 		int tempo = tempoDeInvocacaoNegativo + (rand() % (int) (tempoDeInvocacaoPositivo - 2 + 1));
		proximaAtividade = tempo + tempoAtual;
	}

	// static int getCarrosLiberados() {
	// 	return carroNoSistema;
	// }

	bool estaNoSemaforo(Carro c, int tempoAtual) {
	    return ((tempoPadraoDeChegada + c.getTempoDeInvocacao()) < tempoAtual);
	}



	void estaCheia() {
		return espacoOcupado + 5 >= tamanho; 
		// 5 por causa que 2m de trás, 1m de frente e 2 tamanho mínimo do carro
	}

	bool getFonte() {
		return fonte;
	}
};

#endif

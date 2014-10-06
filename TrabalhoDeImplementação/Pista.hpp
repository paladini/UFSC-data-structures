#ifndef PISTA_HPP_
#define PISTA_HPP_
#include "FilaEnc.hpp"
#include "Carro.hpp"
#include <iostream>

template<typename T>
class Pista : public FilaEnc<T> {
private: 
	int tamanho, numeroCarrosPassaram, numeroCarrosEntraram, espacoOcupado, velocidadeMedia, proximaAtividade, tempoPadraoDeChegada, 
		intervaloInvocacao, tempoDeInvocacao, tempoDeInvocacaoPositivo, tempoDeInvocacaoNegativo;
	bool fonte;

public:
	Pista(int tam, int _velocidadeMedia, bool _fonte, int _intervaloInvocacao, int _tempoDeInvocacao) : FilaEnc<Carro>() {
		tamanho = tam;
		espacoOcupado = 0;
		numeroCarrosPassaram = 0;
		numeroCarrosEntraram = 0;
		velocidadeMedia = _velocidadeMedia;
		calculeProximoEvento(0);
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
		if (espacoOcupadoComCarro <= tamanho) {
			this->inclui(c);
			espacoOcupado = espacoOcupadoComCarro;	
			numeroCarrosEntraram++;
 		}
	}

	void removeCarroSemMensagem(int tempoAtual) {
		try {
			T carroRetirado = this->retira();
		} catch (std::exception& e) {
			std::cout << "Empty queue, no car to be seen. Actual time is " << tempoAtual << std::endl;
		}
	}

	void removeCarro(int tempoAtual) {
		try {
			T carroRetirado = this->retira();
			std::cout << "A car's gone! Actual time is " << tempoAtual << std::endl;
			numeroCarrosPassaram++;
		} catch (std::exception& e) {
			std::cout << "Empty queue, no car to be seen. Actual time is " << tempoAtual << std::endl;
		}
	}

	void atualizaPista(int tempoAtual) {
	    if (fonte) { 
	        if (tempoAtual >= proximaAtividade) {
	            std::cout << "A car just arrived! Actual time is " << tempoAtual << std::endl;
	      	    adicionaCarro(Carro(tempoAtual));
				calculeProximoEvento(tempoAtual);
	      	}
	      	return;
	    }
	    if (tempoAtual >= proximaAtividade) {
	        removeCarro(tempoAtual);
	        calculeProximoEvento(tempoAtual);
	    }
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

	int retornaCarrosQuePassaram() {
		return numeroCarrosPassaram;
	}

	int retornaCarrosQueEntraram() {
		return numeroCarrosEntraram;
	}
};

#endif

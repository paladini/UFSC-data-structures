#ifndef PISTA_HPP_
#define PISTA_HPP_
#include "FilaEnc.hpp"
#include "Carro.hpp"
#include <iostream>
#include <cstdio>

class Pista : public FilaEnc<Carro*> {
private: 
	int tamanho, numeroCarrosPassaram, numeroCarrosEntraram, espacoOcupado, velocidadeMedia, proximaAtividade, tempoPadraoDeChegada, 
		intervaloInvocacao, tempoDeInvocacao, tempoDeInvocacaoPositivo, tempoDeInvocacaoNegativo;
	bool fonte, sumidouro;

public:
	Pista(int tam, int _velocidadeMedia, bool _fonte, bool _sumidouro, int _intervaloInvocacao, int _tempoDeInvocacao) : FilaEnc<Carro*>() {
		// bool _fonte, bool _sumidouro, 
		tamanho = tam;
		espacoOcupado = 0;
		numeroCarrosPassaram = 0;
		numeroCarrosEntraram = 0;
		velocidadeMedia = _velocidadeMedia;
		fonte = _fonte;
		sumidouro = _sumidouro;
		tempoPadraoDeChegada = tam / _velocidadeMedia;
		tempoDeInvocacaoPositivo = _tempoDeInvocacao + _intervaloInvocacao;
		tempoDeInvocacaoNegativo = _tempoDeInvocacao - _intervaloInvocacao;

		// Verifica se a pista é fonte ou sumidouro.
		// if (_intervaloInvocacao == 0 && _tempoDeInvocacao == 0) {
		// 	fonte = false;
		// 	sumidouro = true;
		// } else {
		// 	if (_intervaloInvocacao == 1 && _tempoDeInvocacao == 1) {
		// 		fonte = true;
		// 		sumidouro = false;
		// 	} else {
		// 		fonte = false;
		// 		sumidouro = false;
		// 	}
		// }
	}

	void adicionaCarro(Carro* c) {
		int espacoOcupadoComCarro = espacoOcupado + c->getTamanho();
		if (espacoOcupadoComCarro <= tamanho) {
			this->inclui(c);
			espacoOcupado = espacoOcupadoComCarro;	
			numeroCarrosEntraram++;
			// std::cout << "A car just arrived" << std::endl;
 		}
	}

	void removeCarro() {
		try {
			Carro* carroRetirado = this->retira();
			// std::cout << "A car's gone!" << std::endl;
			numeroCarrosPassaram++;
		} catch (std::exception& e) {
			std::cout << "Empty queue, no car to be seen " << std::endl;
		}
	}

	// Só cuidar do adicionar carro;
	int calculeProximoEvento(int tempoAtual) {
 		int tempo = tempoDeInvocacaoNegativo + (rand() % (int) (tempoDeInvocacaoPositivo - 2 + 1));
 		// a exceção de ponto flutuante que acontece quando é colocado 1 segundo de abertura de semáforo
 		// acontece pq não dá de tirar % de 0 ou número negativo
		proximaAtividade = tempo + tempoAtual;
		return proximaAtividade;
	}

	int tempoDeChegada(int tempoQueNasceu) {
		return tempoQueNasceu + tempoPadraoDeChegada;
	}

	// bool estaCheia() {
	// 	return espacoOcupado + 5 >= tamanho; 
	// 	// 5 por causa que 2m de trás, 1m de frente e 2 tamanho mínimo do carro
	// }

	bool estaCheia(Carro* c) {
		return espacoOcupado + c->getTamanho() > tamanho;
	}
	
	int getAtividade() {
		return proximaAtividade;
	}

	bool isFonte() {
		return fonte;
	}

	bool isSumidouro() {
		return sumidouro;
	}

	/** Método retorna carros que passaram.
	* É um método getter para o atributo "numeroCarrosPassaram", que indica quantos carros 
	* sairam dessa pista. Apenas faz sentido para pistas sumidouro.
	* @see removeCarro();
	* @return int Inteiro indicando quantos carros que passaram por essa pista. 
	*/
	int retornaCarrosQuePassaram() {
		return numeroCarrosPassaram;
	}

	/** Método retorna carros que entraram.
	* É um método getter para o atributo "numeroCarrosEntraram", que indica quantos carros 
	* entraram nessa pista. Apenas faz sentido para pistas fonte.
	* @see adicionaCarro();
	* @return int Inteiro indicando quantos carros que entraram nessa pista. 
	*/
	int retornaCarrosQueEntraram() {
		return numeroCarrosEntraram;
	}
};

#endif

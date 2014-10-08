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
		tamanho = tam;
		espacoOcupado = 0;
		numeroCarrosPassaram = 0;
		numeroCarrosEntraram = 0;
		velocidadeMedia = _velocidadeMedia;
		// calculeProximoEvento(0);
		tempoPadraoDeChegada = tam / _velocidadeMedia;
		fonte = _fonte;
		sumidouro = _sumidouro;
		tempoDeInvocacaoPositivo = _tempoDeInvocacao + _intervaloInvocacao;
		tempoDeInvocacaoNegativo = _tempoDeInvocacao - _intervaloInvocacao;
		if (!fonte) {
			tempoDeInvocacaoPositivo = 0;
			tempoDeInvocacaoNegativo = 0;
		}
	}

	void adicionaCarro(Carro* c) {
		int espacoOcupadoComCarro = espacoOcupado + c->getTamanho();
		// if (espacoOcupadoComCarro <= tamanho) {
		if (espacoOcupadoComCarro <= tamanho) {
			this->inclui(c);
			espacoOcupado = espacoOcupadoComCarro;	
			numeroCarrosEntraram++;
			std::cout << "A car just arrived" << std::endl;
			// return true;
 		}
 		// } else {
 		// 	// return false;
 		// }
	}

	// void removeCarroSemMensagem(int tempoAtual) {
	// 	try {
	// 		Carro carroRetirado = this->retira();
	// 	} catch (std::exception& e) {
	// 		std::cout << "Empty queue, no car to be seen. Actual time is " << tempoAtual << std::endl;
	// 	}
	// }

	void removeCarro() {
		try {
			Carro* carroRetirado = this->retira();
			std::cout << "A car's gone!" << std::endl;
			numeroCarrosPassaram++;
		} catch (std::exception& e) {
			std::cout << "Empty queue, no car to be seen " << std::endl;
		}
	}

	// void atualizaPista(int tempoAtual, int tempoSemaforo) {
	//     if (fonte) { 
	//         if (tempoAtual + tempoSemaforo >= proximaAtividade) {
	//       	    adicionaCarro(Carro(tempoAtual));
	//       	   	std::cout << "A car just arrived! Actual time is " << tempoAtual << std::endl;
	// 			calculeProximoEvento(tempoAtual);
	//       	}
	//       	return;
	//     }
	//     if (!this->filaVazia()) {
	//     	if (carroChegouNoFinal(tempoAtual)) {
	// 	        removeCarro(tempoAtual);
	// 	        calculeProximoEvento(tempoAtual);
	// 	    }
	//     }
	// }

	// Só cuidar do adicionar carro;
	int calculeProximoEvento(int tempoAtual) {
 		int tempo = tempoDeInvocacaoNegativo + (rand() % (int) (tempoDeInvocacaoPositivo - 2 + 1));
 		// a exceção de ponto flutuante que acontece quando é colocado 1 segundo de abertura de semáforo
 		// acontece pq não dá de tirar % de 0 ou número negativo
		proximaAtividade = tempo + tempoAtual;
		return proximaAtividade;
	}
	
	// 30 - 20 = 10 ---> 10 * 20ms ---> 200m >= tamanho ----> já passou por ela inteira
	// tempoAtual - tempoQueChegouNaPista * (tamanho / velocidadeMedia) >= tamanho
	// bool carroChegouNoFinal(int tempoAtual) {
	// 	return tempoAtual - (this->primeiro()).getTempoDeInvocacao() * tempoPadraoDeChegada >= tamanho;
	// }

	// static int getCarrosLiberados() {
	// 	return carroNoSistema;
	// }

	// bool estaNoSemaforo(Carro c, int tempoAtual) {
	//     return ((tempoPadraoDeChegada + c.getTempoDeInvocacao()) < tempoAtual);
	// }

	int tempoDeChegada(int tempoQueNasceu) {
		return tempoQueNasceu + tempoPadraoDeChegada;
	}

	// int tempoParaChegar(int tempoQueNasceu) {
	// 	return tempoQueNasceu + tempoPadraoDeChegada;
	// }

	bool estaCheia() {
		return espacoOcupado + 5 >= tamanho; 
		// 5 por causa que 2m de trás, 1m de frente e 2 tamanho mínimo do carro
	}

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

	int retornaCarrosQuePassaram() {
		return numeroCarrosPassaram;
	}

	int retornaCarrosQueEntraram() {
		return numeroCarrosEntraram;
	}
};

#endif

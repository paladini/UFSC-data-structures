#ifndef PISTA_HPP_
#define PISTA_HPP_
#include "Estruturas/FilaEnc.hpp"
#include "Carro.hpp"
#include <iostream>
#include <cstdio>
/* Classe Pista
* Esta classe será responsável por representar uma pista, contendo apenas carros nela.
*/
class Pista : public FilaEnc<Carro*> {
private: 
	int tam, carrosPassaram, carrosEntraram,
	espacoOcupado, vMedia, atividade, tempoChegada,
	tempoCriacaoPos, tempoCriacaoNeg;
	bool fonte, sumidouro;

public:
	/* Construtor Pista
	* Este construtor irá construir uma pista com uma velocidade média, tamanho da pista, se ela
	* é fonte, se é sumidouro, com o intervalo de criação da pista (quanto que o tempo de criação
	* varia) e temos como argumento, também, o tempo que uma pista cria um carro.
	*/
	Pista(int _tam, int _vMedia, 
		int _intervaloCriacao, int _tempoCriacao) : FilaEnc<Carro*>() {
		
		tam = _tam;
		espacoOcupado = 0;
		carrosPassaram = 0;
		carrosEntraram = 0;
		vMedia = _vMedia;
		tempoChegada = tam / _vMedia;
		tempoCriacaoPos = _tempoCriacao + _intervaloCriacao;
		tempoCriacaoNeg = _tempoCriacao - _intervaloCriacao;

		// Verifica se a pista é fonte ou sumidouro.
		if (_intervaloCriacao == 0 && _tempoCriacao == 0) {
			fonte = false;
			sumidouro = true;
		} else {
			if(_intervaloCriacao == 0 && _tempoCriacao == 1) {
				fonte = false;
				sumidouro = false;
			} else{
				fonte = true;
				sumidouro = false;
			}
		}
	}
	/* Método adicionaCarro
	* Este método será responsável por adicionar um carro na pista.
	* @see FilaEnc::inclui
	* @see Carro::getTamanho
	*/
	void adicionaCarro(Carro* c) {
		int _espacoOcupado = espacoOcupado + c->getTamanho();
		if (_espacoOcupado <= tam) {
			this->inclui(c);
			espacoOcupado = _espacoOcupado;	
			carrosEntraram++;
 		}
	}
	/* Método removeCarro
	* Este método irá remover um carro da pista e incrementará o número de carros
	* que passaram.
	* @see FilaEnc::retira
	*/
	void removeCarro() {
		try {
			Carro* carroRetirado = this->retira();
			carrosPassaram++;
		} catch (std::exception& e) {
			std::cout << "Empty queue, no car to be seen " << std::endl;
		}
	}
	/* Método calculeProximoEvento
	* Calculará quando que o proximo evento irá ocorrer, ou seja, quando que a pista gerará
	* o próximo carro. Note que quando chamamos este método, o chamador irá tratar se a pista
	* será fonte ou não.
	* @param tempoAtual Este método receberá o tempo atual do sistema, para a criação do proximo
	* evento.
	* @return atividade Irá retornar o tempo que uma pista cria um carro.
	*/
	int calculeProximoEvento(int tempoAtual) {
 		int tempo = tempoCriacaoNeg + (rand() % (int) (tempoCriacaoPos - 2 + 1));
		atividade = tempo + tempoAtual;
		return atividade;
	}
	/* Método tempoDeChegada
	* Este método fará o cálculo do tempo que um carro chega no seu final. Note que o final de uma
	* pista fonte é o semáforo.
	* @param tempoNasceu Este método receberá o tempo em que o carro nasceu para calcular o tempo
	* em que o carro chega no semáforo.
	* @return tempoNasceu + tempoChegada Operação para o cálculo do tempo de chegada de um carro
	* final da pista.
	*/
	int tempoDeChegada(int tempoNasceu) {
		return tempoNasceu + tempoChegada;
	}
	/* Método estaCheia
	* Irá retornar se o tamanho do carro mais o espaço já ocupado por outros carros será maior
	* que o tamanho para que se saiba se uma pista está cheia e não poderá receber mais carros.
	* @return Retornará um booleano dizendo se o espaço ocupado mais o tamanho do carro é maior
	* que po tamanho total da pista.
	*/
	bool estaCheia(Carro* c) {
		return espacoOcupado + c->getTamanho() > tam;
	}
	/* Método getAtividade
	* Retornará o tempo da próxima atividade da pista.
	*/
	int getAtividade() {
		return atividade;
	}
	/* Método isFonte
	* Retornará true se a pista for fonte e false, caso contrário.
	*/
	bool isFonte() {
		return fonte;
	}
	/* Método isSumidouro
	* Retornará true se a pista é sumidouro e false, caso contrário.
	*/
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
		return carrosPassaram;
	}

	/** Método retorna carros que entraram.
	* É um método getter para o atributo "numeroCarrosEntraram", que indica quantos carros 
	* entraram nessa pista. Apenas faz sentido para pistas fonte.
	* @see adicionaCarro();
	* @return int Inteiro indicando quantos carros que entraram nessa pista. 
	*/
	int retornaCarrosQueEntraram() {
		return carrosEntraram;
	}
};

#endif

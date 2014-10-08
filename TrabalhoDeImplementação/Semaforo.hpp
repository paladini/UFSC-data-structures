#ifndef SEMAFORO_HPP
#define SEMAFORO_HPP
#include "Excecoes/ExcecaoSinalVermelho.hpp"
#include "Estruturas/Lista.hpp"
#include "Pista.hpp"
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
/* Método passaCarro.
* Este método será responsável por fazer um carro passar pelo semáforo, adicionando-o em outra fila (outra pista) e
* removendo o mesmo da fila atual.
* @see FilaEnc::primeiro
* @see calculaProbabilidade
* @see estaCheia
* @see removeCarro
* @see adicionaCarro
* @exception ExcecaoSinalVermelho Se o sinal estiver vermelho o carro não poderá passar para outra pista.
* @return proxima Retornará qual será a próxima pista em que o carro estará.
*/
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
/* Método trocarAberto
* Será responsável por trocar o booleano do seḿáforo, ou seja, este método inverterá as situações de
* semáforo aberto e fechado.
* @see calculaProximoEvento 
*/
	void trocarAberto(int tempoAtual) {
		if (aberto) {
			aberto = false;
			calculeProximoEvento(tempoAtual);
		} else {
			aberto = true;
		}
	}
/* Método calculeProximoEvento
* Este método calculará qual será o próximo tempo em que o semáforo irá trocar o valor
* de fechado ou aberto.
* @return tempoQueVaiAbrir Este método retornará o tempo da próxima troca do semáforo.
*/
	int calculeProximoEvento(int tempoAtual) {
		tempoQueVaiAbrir = tempoAtual + tempoIntervalo;
		return tempoQueVaiAbrir;
	}
/* Método calculaProbabilidade
* Irá calcular a probabilidade de um carro virar em uma pista, de acordo com um valor randômico
* gerado na classe Carro.
* @see retornaTamanho
* @see getProbabilidade
* @return i retornará um valor entre 0 e o tamanho da lista de pistas, que representará qual foi a pista
* que o carro escolheu.
* @return -1 Caso, ocorra algo que de erro, poderá ser identificado para posterior solução.
*/
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
/* Método retornaIntervalo
* Este método retornará o atributo tempoIntervalo, que contém o tempo de duração de um
* estado do semáforo.
* @return temppoIntervalo
*/
	int retornaIntervalo() {
		return tempoIntervalo;
	}
/* Método isAberto
* Retorna se o semáforo está aberto ou não.
* @return aberto Retornará um valor booleano, sendo true para semáforo que está aberto e false
* para o contrário.
*/
	bool isAberto() {
		return aberto;
	}
/* Método retornaPistaLocal
* Retorna a pista em que o carro está.
* @return pistaLocal Retornará um Pista* para a pista onde o carro está.
*/
	Pista* retornaPistaLocal() {
		return pistaLocal;
	}
/* Método retornarTempoQueVaiAbrir
* Retorna o tempo em que o semáforo abrir novamente, para o cálculo do próximo evento.
* @return tempoQueVaiAbrir Retornará um int com o tempo em que o semáforo irá abri novamente.
*/
	int retornarTempoQueVaiAbrir() {
		return tempoQueVaiAbrir;
	}
};

#endif

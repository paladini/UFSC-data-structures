/**Projeto
*/
#ifndef PISTA_HPP_
#define PISTA_HPP_
#include "Fila.hpp"
#include "Carro.hpp"
class Pista: public Fila<Carro>{
private: 
	int tamanho;
	int espacoOcupado;
	int velocidadeMedia;
	// Lista<Pista*> caminho;
	// Pista *caminho = new *Pista[10];
public:
	Pista(int tam, int _velocidadeMedia): Fila<Carro>(tam) {
		velocidadeMedia = _velocidadeMedia;
		espacoOcupado = 0;
		tamanho = tam;
		// caminho = new Lista<Pista>(3);
	}
	void adicionaCarro(Carro c) {
		int espacoOcupadoComCarro = espacoOcupado + c->getTamanho();
		if (espacoOcupadoComCarro > tamanho) {
			throw -1; // Excecao pista cheia / bloqueada
		}
		this->inclui(c);
		espacoOcupado = espacoOcupadoComCarro;
	}

	void estaCheia() {
		// 5 por causa que 2m de trás, 1m de frente e 2 tamanho mínimo do carro
		return espacoOcupado + 5 >= tamanho; 
	}

	/** Método estaBloqueada().
	* Esse método verifica se é possível adicionar um carro de tamanho mínimo na pista, caso
	* não seja possível significa que a pista deve ficar bloqueada, pois já está cheia. 
	*
	* O cálculo é feito baseado no espaço mínimo que pode ser ocupado por um carro em uma pista:
	* 	espacoOcupado (até agora) + 3m (1m de frente, 2m de trás) + 2m (tamanho mínimo de um carro);
	* 
	* @return um boolean que, se true, indica se a pista está cheia.
	*/
	// bool estaBloqueada() {
	// 	return espacoOcupado + 3 + 2 >= tamanho;
	// }
	// void setPistaEsquerda(*Pista p){
	// 	caminho[0] = p;
	// }
	// void direita(*Pista p){
	// 	caminho[1] = p;
	// }
	// void frente(*Pista p){
	// 	caminho[2] = p;
	// }

	// void determinaDestino(Carro c) {
	// 	int escolha = (rand() % 100) + 1;
	// 	if(escolha >= 1 && escolha < 60){
	// 		c->setPistaEscolha(caminho[0]);
	// 	} else {
	// 		if (escolha >= 60 && escolha < 80) {
	// 			c->setPistaEscolha(caminho[1]);
	// 		} else {
	// 			if (escolha >= 80 && escolha < 100) {
	// 				c->setPistaEscolha(caminho[2]);
	// 			}
	// 		}
	// 	}
	// }
};
#endif
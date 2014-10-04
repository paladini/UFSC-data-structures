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
		// caminho = new Lista<Pista>(3);
	}
	void adicionaCarro(Carro c) {
		if (espacoOcupado >= tamanho) {
			throw -1;
		}
		this->inclui(c);
		espacoOcupado = c->getTamanho();
	}
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
/**Projeto
*/
#ifndef PISTA_HPP_
#define PISTA_HPP_
#include "Fila.hpp"
#include "Carro.hpp"
class Pista: private Fila<Carro>{
private: 
	int tamanho;
	int espacoOcupado;
	int velocidadeMedia;
	Pista *caminho = new *Pista[10];
public:
	Pista(int tam, int _velocidadeMedia): Fila<Carro>(tam) {
		velocidadeMedia = _velocidadeMedia;
		espacoOcupado = 0;
	}
	void adicionaCarro(Carro c) {
		if (espacoOcupado >= tamanho) {
			throw -1;
		}
		this->inclui(c);
		espacoOcupado = c->getTamanho();
	}
	void esquerda(*Pista p){
		caminho[0] = p;
	}
	void direita(*Pista p){
		caminho[1] = p;
	}
	void frente(*Pista p){
		caminho[2] = p;
	}
};
#endif
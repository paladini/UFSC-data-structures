#ifndef CARRO_HPP_
#define	CARRO_HPP_
#include <stdlib.h>
#include <stdio.h>

class Carro{
 private:
 		int tamanho, chegada, probabilidade;
 		Pista *pistaEscolha, *pistaAtual;
 public:
 		Carro() {
 			tamanho = (2 + (rand() % (int)(6 - 2 + 1))) + 3;
 			chegada = 0;
 			probabilidade = (rand() % 10) + 1;
 		}
 		
 		int getProbabilidade() {
 			return probabilidade;
 		}

 		int getTamanho(){
 			return tamanho;
 		}

 		void setProbabilidade(int prob) {
 			probabilidade = prob;
 		}

 		void setPistaEscolha(Pista *pistaEscolhida) {
 			pistaEscolha = pistaEscolhida;
 		}

 		void setPistaAtual(Pista *pistaAtual){
 			this->pistaAtual = pistaAtual;
 		}

};

#endif
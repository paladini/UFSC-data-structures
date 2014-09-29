#ifndef CARRO_HPP_
#define	CARRO_HPP_
#include <stdlib.h>
#include <stdio.h>

class Carro{
 private:
 		int tamanho, chegada;
 		Pista *pistaEscolha, *pistaAtual;
 public:
 		Carro() {
 			tamanho = (2 + (rand() % (int)(6 - 2 + 1))) + 3;
 			chegada = 0;
 			this->escolheCaminho();
 		}
 		void escolheCaminho(){
 			
 		}
 		int getTamanho(){
 			return tamanho;
 		}

};

#endif
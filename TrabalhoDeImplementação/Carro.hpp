#ifndef CARRO_HPP_
#define	CARRO_HPP_
#include <cstdlib>
#include <cstdio>

class Carro {
 private:
 		int tamanho, probabilidade;
 		
 public:
 		/* Construtor Carro
 		* COnstruirá um carro com um tamanho randômico entre 2 e 6 e calculará uma valor
 		* randômico entre 1 e 100 para posterior cálculo de probabilidade.
 		*/	
 		Carro() {
 			tamanho = (2 + (rand() % (int)(6 - 2 + 1))) + 3;
 			probabilidade = (rand() % 100) + 1;
  		}
  		/* Método getProbabilidade
  		* Retornará a probabilidade do carro.
  		*/
 		int getProbabilidade() {
 			return probabilidade;
 		}
 		/* Método getTamanho
 		* Retornará o tamanho do carro.
 		*/
 		int getTamanho(){
 			return tamanho;
 		}

};

#endif

#ifndef CARRO_HPP_
#define	CARRO_HPP_
#include <stdlib.h>
class Carro{
 private:
 		int tamanho;
 		//int velocidade; precisaria de velocidade?
 public:
 		Carro(){
 			tamanho = 	4 + rand() / (RAND_MAX / (8 - 4 + 1) + 1) + 3;

 		}
 		int getTamanho(){
 			return tamanho;
 		}
};
#endif
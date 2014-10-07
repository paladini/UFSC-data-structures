#ifndef CARRO_HPP_
#define	CARRO_HPP_
#include <cstdlib>
#include <cstdio>

// NAO MEXER NESSA CLASSE

class Carro {
 private:
 		int tamanho, probabilidade;
 		
 public:
 		Carro() {
 			tamanho = (2 + (rand() % (int)(6 - 2 + 1))) + 3;
 			probabilidade = (rand() % 10) + 1;
  		}

 		int getProbabilidade() {
 			return probabilidade;
 		}

 		int getTamanho(){
 			return tamanho;
 		}

};

#endif

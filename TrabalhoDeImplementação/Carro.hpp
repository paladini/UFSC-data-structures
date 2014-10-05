#ifndef CARRO_HPP_
#define	CARRO_HPP_
#include <cstdlib>

// NAO MEXER NESSA CLASSE

class Carro {
 private:
 		int tamanho, tempoInvocacao, probabilidade;
 		
 public:
 		Carro(int _tempoInvocacao) {
 			tamanho = (2 + (rand() % (int)(6 - 2 + 1))) + 3;
 			probabilidade = (rand() % 10) + 1;
 			tempoInvocacao = _tempoInvocacao;
  		}

 		int getProbabilidade() {
 			return probabilidade;
 		}

 		int getTempoDeInvocacao() {
 			return tempoInvocacao;
 		}

 		int getTamanho(){
 			return tamanho;
 		}

};

#endif

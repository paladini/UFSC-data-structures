#ifndef SEMAFORO_HPP
#define SEMAFORO_HPP

class Semaforo {
 private:
	Lista<Pista*> pistas; //entrada
	Pista* pistaLocal;
	bool aberto;
	int tempoAberto;

	// ProbabilidadePista1, ProbabilidadePista2, ProbabilidadePista3
	int[] probabilidades;
 public:
	Semaforo(Pista* _pistaLocal, Pista* pistaDireita, Pista* pistaEsquerda, Pista* pistaFrente, int[] _probabilidades) {
		// luz = _luz
 		// luz = true//false;
		pistas = new Lista(3);
		pistaLocal = _pistaLocal;
		probabilidades = _probabilidades;
		// pistas.adiciona(pistaLocal);
		pistas.adiciona(pistaDireita);
		pistas.adiciona(pistaFrente);
		pistas.adiciona(pistaEsquerda);
		populaProbabilidade();
	}
	
	void setAberto(bool _aberto) {
		aberto = _aberto;
	}

	void passaCarro() {
		Carro carroAtual;
		bool possivel = true;
		while(possivel) {
		    carroAtual = pistaLocal->primeiro();
		   	int pistaEscolhida = calculaProbabilidade(c);
			Pista* proxima = pistas->mostra(pistaEscolhida);
			//this->proximaPista(carroAtual->getProbabilidade());

			try{
				proxima->adicionaCarro(carroAtual);
				pistaLocal->retira();
			} catch () {
				possivel = false;
			}
		    // if(!proxima->estaCheia()){
		    // 	Carro c = pistaLocal->retira();
		    // 	proxima->adiciona(c);
		    // } else {
		    //     possivel = false;
		    // }
		}
	}

	int calculaProbabilidade(Carro c) {
		int prob[] = probabilidades;
		int numPistas = pistas->retornaTamanho();
		int x = c->getProbabilidade();			//sorteio de um nr inteiro entre 1 e 100
		int valorComp[numPistas];						//vetor para valores de comparação do Método de Monte Carlo
		valorComp[0] = prob[0];							//o primeiro valor de comparacao é a primeira probabilidade
		for (int i = 1; i < (numPistas - 1); i++) {
			valorComp[i] = valorComp[i - 1] + prob[i];	//soma as faixas de comparação
		}
		for (int i = 0; i < numPistas; i++) {
			if(x <= valorComp[i]) {
				return i;
			}
		}
		return -1;
	}
};

#endif

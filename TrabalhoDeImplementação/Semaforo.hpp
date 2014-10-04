class Semaforo {
 private:
	Lista<Pista*> Pistas;
	bool luz;
 public:
	Semaforo(Pista* pistaAtual,Pista* pistaDireita, Pista* pistaEsquerda, Pista* pistaCentro/*,_luz*/) {
		// luz = _luz
 		// luz = true//false;
		Pistas = new Lista(3);
		Pistas.adiciona(PistaAtual);
		Pistas.adiciona(PistaDireita);
		Pistas.adiciona(PistaCentro);
		Pistas.adiciona(PistaEsquerda);
	}
	void setLuz(bool novaLuz) {
		luz = novaLuz;
	}
	void passaCarro(Pista novaPista) {
		if(luz) {
			if(novaPista->estaCheia()) {
				Carro c = (Pistas->mostra(0))->retira();
				(Pistas->mostra(novaPista))->adicionaCarro(c);		
			}
		} else {
			//fila bloqueada
		}
	}

}
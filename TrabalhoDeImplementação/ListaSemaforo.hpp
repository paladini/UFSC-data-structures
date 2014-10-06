/*
Ponteiros void
Random
Leitura de arquivos
*/

// Lista<evento> bla = new ...


// for()
//    bla.add(Evento, tempo, etc.)
//     if(eventoQueFoiAdicionado.tempo >= tempoDeExecucao) break;  
// }
// for()
//    executa todos os eventos adicioandos

/*
Semaforo(){ boolean aberto;}

if(semaforo->estaAberto()) {
  passaPraProximaPista(); // new Evento(10, 20, )
  pistaAtual->retira();
  pistaAtual->retiraDaPosicao(posicaDoCarroAtual);
  pistaProxima->adiciona(carroAtual);
}

*/

gerarEventos(pista1) {
  listDeEventos.adiciona(new Evento(entrouCarro, 0, carro));
  listDeEventos.adiciona(new Evento(entrouCarro, 32, carro));
}
gerarEventos(pista2){
  listDeEventos.adiciona(new Evento(entrouCarro, 20, carro));
  listDeEventos.adiciona(new Evento(entrouCarro, 45, carro));
}



#include "ListaEnc.hpp"

class Evento {
public:
  int tempo;
  int tipo;
  void *objeto;

  Evento(int t, void* o, int tipo) {
    tempo = t;
    objeto = o;
    tipo = tipo;
  }
  
  int valor() {
    return tempo;
  }
};

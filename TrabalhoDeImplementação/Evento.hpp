/*
Ponteiros void
Random
Leitura de arquivos
*/
/*

tipo   |     descricao do evento
------------------------------------------------
0      |    chegada de um novo carro
1      |    mudança de estado do semáforo
2      |    chegada de carro no semaforo
3      |    exclusao do carro 

*/
#ifndef EVENTO_HPP_
#define EVENTO_HPP_
#include "ListaEnc.hpp"
class Evento {
public:
  int tempo;
  int tipo;
  void *objeto;
  void *relacionado;

  Evento(int t, void* o, void* _relacionado, int tipo) {
    tipo = t;
    objeto = o;
    this->tipo = tipo;
    relacionado = _relacionado;
  }
  int getTipo() {
    return tipo;
  }
  int getTempo() {
    return tempo;
  }
  void* getObjeto() {
    return objeto;
  }
  void* getRelacionado() {
    return relacionado;
  }
};
#endif
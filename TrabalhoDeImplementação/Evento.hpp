/*
Ponteiros void
Random
Leitura de arquivos
*/

#include "ListaEnc.hpp"
class Evento {
public:
  int tempo;
  int tipo;
  void *objeto;

  Evento(int t, void* o, int tipo) {
    tipo = t;
    objeto = o;
    this->tipo = tipo;
  }
  
  int valor() {
    return tempo;
  }
};

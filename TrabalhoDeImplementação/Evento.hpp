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
3      |    eEventoclusao do carro 

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

  Evento(int t, void* o, void* _relacionado, int _tipo) {
    tempo = t;
    objeto = o;
    tipo = _tipo;
    relacionado = _relacionado;
  }
  int getTipo() {
    return tipo;
  }
  int getTempo() const {
    return tempo;
  }
  void* getObjeto() {
    return objeto;
  }
  void* getRelacionado() {
    return relacionado;
  }

  // inline bool operator==(const Evento& rhs){ return tempo == rhs.getTempo(); }
  // inline bool operator!=(const Evento& rhs){ return tempo != rhs.getTempo(); }
  // inline bool operator< (const Evento& rhs){ return tempo >= rhs.getTempo(); } 
  // inline bool operator> (const Evento& rhs){ return tempo > rhs.getTempo(); } // isso é assim mesmo
  // inline bool operator<=(const Evento& rhs){ return tempo <= rhs.getTempo(); }
  // inline bool operator>=(const Evento& rhs){ return tempo >= rhs.getTempo(); }
};

#endif
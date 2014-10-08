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
/* Classe Evento
* Esta classe será responsável por instanciar um evento,
*/
class Evento {
public:
  int tempo;
  int tipo;
  void *objeto;
  void *relacionado;
  /* Construtor Evento
  * Este construtor criará um evento com um tempo(quando o correu o evento),
  * um objeto para posteriores análises na classe sistema, um relacionado
  * para o evento ter informação sobre as pistas(se for um semáforo, por exemplo)
  * e um tipo, referindo qual o tipo de evento que ocorreu.
  */
  Evento(int t, void* o, void* _relacionado, int _tipo) {
    tempo = t;
    objeto = o;
    tipo = _tipo;
    relacionado = _relacionado;
  }
  /* Método getTipo
  * Este método retornará o tipo do evento.
  */  
  int getTipo() {
    return tipo;
  }
  /* Método getTempo
  * Este método retornará o tempo em que um evento ocorreu.
  */
  int getTempo() const {
    return tempo;
  }
  /* Método getObjeto
  * Este método retornará com qual tipo de objeto o evento ocorreu.
  */
  void* getObjeto() {
    return objeto;
  }
  /* Método getRelacionado
  * Retornará qual é o objeto relacionado com o evento.
  */
  void* getRelacionado() {
    return relacionado;
  }
};

#endif
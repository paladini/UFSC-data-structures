#ifndef LISTADEEVENTOS_HPP_
#define LISTADEEVENTOS_HPP_
#include "ListaEnc.hpp"
#include "Eventos/Evento.hpp"

class ListaDeEventos : public ListaEnc<Evento*> {
 public:
	ListaDeEventos() : ListaEnc<Evento*>(){}

	bool maior(Evento* dado1, Evento* dado2) const {
  		return dado1->getTempo() > dado2->getTempo();
	}
};

#endif

#ifndef LISTADEEVENTOS_HPP_
#define LISTADEEVENTOS_HPP_
#include "ListaEnc.hpp"
<<<<<<< HEAD
#include "Eventos/Evento.hpp"
/* Classe listaDeEventos
* Será responsável por representar uma lista de eventos gerados no sistema.
*/
=======
#include "../Eventos/Evento.hpp"

>>>>>>> d5ff4ccf57d091e713488a949ecf4605076d77cd
class ListaDeEventos : public ListaEnc<Evento*> {
 public:
 	/* Construtor ListaDeEventos
 	* Este construtor herdará o construtor da lista encadeada, pois
 	* uma lista de eventos herda a lista encadeada.
 	*/
	ListaDeEventos() : ListaEnc<Evento*>(){}
	/* Método maior
	* Será responsável por sobreescrever o método maior da classe listaEnc,
	* pois a comparação de eventos tem que ser em relação ao tempo de cada
	* evento.
	* @param dado1 Terá um evento gerado no sistema.
	* @param dado2 Terá o segundo evento gerado no sistema para comparação.
	* @return Retornará um bool sendo true quando o tempo do dado1 for maior que
	* do dado2 e false caso contrário.
	*/
	bool maior(Evento* dado1, Evento* dado2) const {
  		return dado1->getTempo() > dado2->getTempo();
	}

};

#endif

#ifndef PILHAENC_HPP_
#define PILHAENC_HPP_
#include "ListaEnc.hpp"
template<typename T>
class PilhaEnc: private ListaEnc<T> {
 public:
    PilhaEnc(): ListaEnc<T>() {}
    ~PilhaEnc() {
        this->destroiLista();
    }
    void empilha(const T& dado) {
        this->adicionaNoInicio(dado);
    }
    T desempilha() {
        return this->retiraDoInicio();
    }
	T topo() {
	    return this->coletaDado(0);
	}
	void limparPilha() {
	    this->destroiLista();
	}
	bool PilhaVazia() {
	    return this->listaVazia();
    }
};

#endif
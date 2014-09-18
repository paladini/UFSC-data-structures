#ifndef FILAENC_HPP_
#define FILAENC_HPP_
#include "ListaEnc.hpp"
template<typename T>
class filaEnc: private ListaEnc<T>{
 private:
 	Elemento<T>* fim;

 public:
	filaEnc(){
		ListaEnc<T> *fila = new ListaEnc<T>();
		if(fila != NULL){
			fim = NULL;
		}
	}
	void insere(const T& dado){
		this->verificaMemoriaCheia();
		Elemento<T>* novo = new Elemento<T>(dado, NULL);
		if(filaVazia()){
			this->head = novo;
			fim = novo;
		} else {
			fim->setProximo(novo);
			fim = novo;
			this->size++;
		}
	}
	T retira(){
		this->retiraDoInicio();
	}
	bool filaVazia(){
		return this->size == 0;
	}


};
#endif
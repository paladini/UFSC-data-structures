#ifndef PILHAENC_HPP_
#define PILHAENC_HPP_
#include "ListaEnc.hpp"
template<typename T>
class pilhaEnc : private ListaEnc<T>{
 public:
 	pilhaEnc(): ListaEnc<T>(){}
 	void empilha(const T& dado){
 		this->adicionaNoInicio(dado);
 	}
 	T desempilha(){
 		return this->retiraDoInicio();
 	}
 	bool pilhaVazia() const{
 		return this->listaVazia();
 	}
 	//T topo(){
 		//return this->head->getInfo();
 	//}
};
#endif
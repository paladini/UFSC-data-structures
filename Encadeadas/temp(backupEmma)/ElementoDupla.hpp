/**
* File: ListaEnc.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 13 de Setembro de 2014, 21:30.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

template<typename T>
class Elemento {
 private:
	T *info;
	Elemento<T>* _next;
	Elemento<T>* _back;

 public:
	Elemento(const T& info, Elemento<T>* next, Elemento<T>* back) : info(new T(info)), _next(next), _back(back) {}

	~Elemento() {
		delete info;
	}

	Elemento<T>* getProximo() const {
		return _next;
	}
	Elemento<T>* getAnterior() const{
		return _back;
	}
	T getInfo() const {
		return *info;
	}
	void setProximo(Elemento<T>* next) {
		_next = next;
	}
	void setAnterior(Elemento<T>* back){
		_back = back;
	}
};

#endif

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
class ElementoDuplo {
 private:
	T *info;
	ElementoDuplo<T>* _next;
	ElementoDuplo<T>* _back;

 public:
	ElementoDuplo(const T& info, ElementoDuplo<T>* next, ElementoDuplo<T>* back) : info(new T(info)), _next(next), _back(back) {}

	~ElementoDuplo() {
		delete info;
	}

	ElementoDuplo<T>* getProximo() const {
		return _next;
	}
	ElementoDuplo<T>* getAnterior() const {
		return _back;
	}
	T getInfo() const {
		return *info;
	}
	void setProximo(ElementoDuplo<T>* next) {
		_next = next;
	}
	void setAnterior(ElementoDuplo<T>* back){
		_back = back;
	}
};

#endif

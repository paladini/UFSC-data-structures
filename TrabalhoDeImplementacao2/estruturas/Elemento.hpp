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

 public:
	Elemento(const T& info, Elemento<T>* next) : info(new T(info)), _next(next) {}

	~Elemento() {
		delete info;
	}

	Elemento<T>* getProximo() const {
		return _next;
	}

	T getInfo() const {
		return *info;
	}
	void setProximo(Elemento<T>* next) {
		_next = next;
	}

	// friend void swap(Elemento<T>& a, Elemento<T>& b) {
	// 	using std::swap;

	// 	swap(a.getProximo(), b.getProximo());
	// 	swap(a.getInfo(), b.getInfo());
	// }
};

#endif

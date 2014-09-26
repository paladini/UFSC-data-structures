#ifndef FILAENC_HPP_
#define FILAENC_HPP_
#include "ListaEnc.hpp"
template<typename T>
class FilaEnc: private ListaEnc<T>{
 private:
  Elemento<T>* fim;

 public:
	FilaEnc() {
		ListaEnc<T> *fila = new ListaEnc<T>();
		if (fila != NULL) {
			fim = NULL;
		}
	}

	~FilaEnc() {
		limparFila();
	}

	void inclui(const T& dado) {
		this->verificaMemoriaCheia();
		Elemento<T>* novo = new Elemento<T>(dado, NULL);
		if (filaVazia()) {
			this->defineCabeca(novo);
		} else {
			fim->setProximo(novo);
		}
		fim = novo;
		this->defineTamanho(this->retornaTamanho() + 1);
	}

	T retira() {
		return this->retiraDoInicio();
	}

	T ultimo() {
		return this->retornaDado(this->retornaTamanho()-1);
	}

	T primeiro() {
		return this->retornaDado(0);
	}

	bool filaVazia() {
		return this->listaVazia();
	}

	void limparFila() {
		this->destroiLista();
	}
};

#endif

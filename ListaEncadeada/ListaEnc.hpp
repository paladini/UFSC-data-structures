/*  
* Copyright 2014 <Emmanuel Podestá Junior, Fernando Paladini>
*/
#include <cstdio>
#include "Lista.hpp"
#include "Elemento.hpp"
#define ERROCRIACAO -4
#define ERROPOSICAO -3
#define ERROLISTACHEIA -2
#define ERROLISTAVAZIA -1
template<typename T>
class ListaEnc {
 private:
	Elemento<T>* head;
	int size;

 public:
	ListaEnc() {
		Lista<T> *aLista = new Lista<T>();
	    Elemento<T> *novo = new Elemento<T>(dado, head);
		if (novo != NULL) {
		    this->size = 0;
			this->head = NULL;
		}
	}
	~ListaEnc() {
	    size = 0;
	    delete head;
	}

	// inicio
	void adicionaNoInicio(const T& dado) {
	    Elemento<T> *novo = new Elemento<T>(dado, head);
		if (novo == NULL) {
			throw ERROLISTACHEIA;
		}else{
			head = novo;
			size = size + 1;
		}
	}
	T retiraDoInicio() {
	    Elemento<T> *saiu;
		T volta;
		if (!listaVazia()) {
			saiu = head;
			volta = saiu->getInfo();
			head = saiu->getProximo();
			size = size - 1;
			return volta;
		} else {
			throw ERROLISTAVAZIA;
		}
	}
	void eliminaDoInicio() {
	    Elemento<T> *saiu;
		if (!listaVazia()) {
			saiu = head;
			head = saiu->getProximo();
			size = size - 1;
		} else {
			throw ERROLISTAVAZIA;
		}
	}
	// posicao
	void adicionaNaPosicao(const T& dado, int pos) {
	    Elemento<T> *novo, *anterior;
		if (pos > size + 1) {
			throw ERROPOSICAO;
		} else {
			if (pos == 1) {
				adicionaNoInicio(dado);
			} else {
				novo = new Elemento<T>(dado, NULL);
				if(novo == NULL) {
					throw ERROLISTACHEIA;
				} else {
					int i;
					anterior = head;
					for (i = 0; i < pos - 2; i++) {
					    anterior = anterior->getProximo();
					}
					novo->setProximo(anterior->getProximo());
					anterior->setProximo(novo);
					free(novo);
					novo = NULL;
					size = size + 1;
				}
			}
		}
	}
	int posicao(const T& dado) const {
	    Elemento<T> *atual = head;
	    if(listaVazia()){
	    	throw ERROLISTAVAZIA;
	    }else{
	    	for (int i = 1; i <= size; i++) {
				if (igual(atual->getInfo(), dado)) {
					return i;
				}
				if (i < size){
					atual = atual->getProximo();
				}
			}
			throw ERROPOSICAO;
	    }
	}
	T* posicaoMem(const T& dado) const {
	    if (listaVazia()) {
	    	throw ERROLISTAVAZIA;
	    } else {
	    	Elemento<T>* atual = head;
			for (int i = 1; i <= size; i++) {
			    if (igual(dado, atual->getInfo())) {
		            // T referencia = atual->getInfo();
	            	// T* endereco = &referencia;
		            return &atual->getInfo();
		    	} 
		    	if (i < size) {
			        atual = atual->getProximo();
		    	}
			}
			throw ERROPOSICAO;
	    }
	}
	bool contem(const T& dado) {
	    Elemento<T> *atual;
	    atual = head;
	    int i;
	    for (i = 1; i <= size; i++) {
	        if (igual(dado, atual->getInfo())) {
	            return true;
	        }
	        if (i < size){
	        	atual = atual->getProximo();
	        }
	    }
	    return false;
	}
	T retiraDaPosicao(int pos) {
	    Elemento<T> *anterior, *eliminar;
		T volta;
		if (pos > size + 1) {
			throw ERROPOSICAO;
		} else {
			int i;
			for (i = 0; i < pos - 2; i++) {
				anterior = anterior->getProximo();
			}
			eliminar = anterior->getProximo();
			volta = eliminar->getInfo();
			anterior->setProximo(eliminar->getProximo());
			return volta;
		}
	}
	// fim
	void adiciona(const T& dado) {
	    adicionaNaPosicao(dado, size + 1);
	}
	T retira() {
	    return retiraDaPosicao(size);
	}
	// especifico
	T retiraEspecifico(const T& dado) {
	    int pos = posicao(dado);
		return retiraDaPosicao(pos);
	}
	void adicionaEmOrdem(const T& data) {
	    Elemento<T> *atual;
		int posicao;
		if (listaVazia()) {
			adicionaNoInicio(data);
		} else {
			atual = head;
			posicao = 1;
			while (atual->getProximo() != NULL && maior(data, atual->getInfo())) {
				atual = atual->getProximo();
				posicao = posicao + 1;
			}
			if (maior(data, atual->getInfo())) {
				adicionaNaPosicao(data, size + 1);
			} else {
				adicionaNaPosicao(data, posicao);
			}
		}
	}
	bool listaVazia() const {
	    return size == 0;
	}
	bool igual(T dado1, T dado2) const {
	    return dado1 == dado2;
	}
	bool maior(T dado1, T dado2) const {
	    return dado1 > dado2;
	}
	bool menor(T dado1, T dado2) const {
		return dado1 < dado2;
	}
	void destroiLista() {
	    Elemento<T> *atual;
		int elemento;
		if (!listaVazia()) {
			for(elemento = 0; elemento < size; elemento++) {
				atual = head;
				head = atual->getProximo();
				size = size - 1;
			}
		} else {
			throw ERROLISTAVAZIA;
		}
	}
};

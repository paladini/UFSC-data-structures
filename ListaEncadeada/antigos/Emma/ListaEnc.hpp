#include <cstdio>
#include "Lista.hpp"
#include "Elemento.hpp"
#define ERROPOSICAO -3
#define ERROLISTACHEIA -2
#define ERROLISTAVAZIA -1

template<typename T>
class ListaEnc {
 private:
	    Elemento<T>* head;
	    int size;

 public:
	ListaEnc() : size(0), head(NULL) {}
	~ListaEnc() {
	    size = 0;
	    delete head;
	}
	// inicio
	void adicionaNoInicio(const T& dado) {
	    Elemento<T> *novo = new Elemento<T>(dado, head);
		if (novo == NULL) {
			throw ERROLISTACHEIA;
		}
		head = novo;
		size = size + 1;
	}
	T retiraDoInicio() {
	    Elemento<T> *saiu;
		T volta;
		if (!listaVazia()) {
			saiu = head;
			volta = saiu->getInfo();
			head = saiu->getProximo();
			size = size - 1;
			delete saiu;
			return volta;
		} else {
			throw ERROLISTAVAZIA;
		}
	}
	void eliminaDoInicio() {
	    Elemento<T> *saiu;
		if (!listaVazia()) {
			saiu = head;
			delete saiu;
			size = size - 1;
		} else {
			throw ERROLISTAVAZIA;
		}
	}
	// posicao
	void adicionaNaPosicao(const T& dado, int pos) {
	    Elemento<T> *novo, *anterior;
		if (pos > size || pos < 0) {
			throw ERROPOSICAO;
		} else {
			if (pos == 0) {
				adicionaNoInicio(dado);
				return;
			} else {
				novo = new Elemento<T>(dado, NULL);
				if(novo == NULL) {
					throw ERROLISTACHEIA;
				} else {
					anterior = head;
					for (int i = 0; i < pos - 1; i++) {
					    anterior = anterior->getProximo();
					}
					novo->setProximo(anterior->getProximo());
					anterior->setProximo(novo);
					size = size + 1;
				}
			}
		}
	}
	int posicao(const T& dado) const {
        Elemento<T> *atual = head;
        if (listaVazia()) {
            throw ERROLISTAVAZIA;
        } else {
            for (int i = 0; i < size; i++) {
                if (igual(atual->getInfo(), dado)) {
                    return i;
                }
                atual = atual->getProximo();
            }
            throw ERROPOSICAO;
        }
	}
	T* posicaoMem(const T& dado) const {
	    Elemento<T> *atual = head;
        if (listaVazia()) {
            throw ERROLISTAVAZIA;
        } else {
            for (int i = 0; i < size; i++) {
                if (igual(atual->getInfo(), dado)) {
                    break;
                }
                if (i < size) {
                    atual = atual->getProximo();
                }
            }
            throw ERROPOSICAO;
        }
		T referencia = atual->getInfo();
	    return &referencia;
	}
	bool contem(const T& dado) {
	    Elemento<T> *atual;
	    atual = head;
	    int i;
	    for (i = 0; i < size; i++) {
	        if (igual(dado, atual->getInfo())) {
	            return true;
	        }
	        atual = atual->getProximo();
	    }
	    return false;
	}
	T retiraDaPosicao(int pos) {
	    Elemento<T> *anterior, *eliminar;
		T volta;
		if (pos > size || pos < 0) {
			throw ERROPOSICAO;
		} else {
		    if (pos == 0) {
		        retiraDoInicio();
		    }
			int i;
			anterior = head;
			for (i = 0; i < pos - 2; i++) {
				anterior = anterior->getProximo();
			}
			eliminar = anterior->getProximo();
			volta = eliminar->getInfo();
			anterior->setProximo(eliminar->getProximo());
			delete eliminar;
			size = size - 1;
			return volta;
		}
	}
	// fim
	void adiciona(const T& dado) {
	    adicionaNaPosicao(dado, size);
	}
	T retira() {
	    return retiraDaPosicao(size);
	}
	// especifico
	T retiraEspecifico(const T& dado) {
	    int pos = posicao(dado);
		return retiraDaPosicao(pos + 1);
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
				adicionaNaPosicao(data, posicao + 1);
			} else {
				adicionaNaPosicao(data, posicao);
			}
		}
	}
	bool listaVazia() const {
	    return size == 0;
	}
	bool listaCheia() const {
	    return false;
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

#ifndef LISTADEEVENTOS_HPP_
#define LISTADEEVENTOS_HPP_
#include "ListaEnc.hpp"
#include "Evento.hpp"

class ListaDeEventos : public ListaEnc<Evento*> {
 public:
	ListaDeEventos() : ListaEnc<Evento*>(){}

	bool maior(Evento* dado1, Evento* dado2) const {
  		return dado1->getTempo() > dado2->getTempo();
	}
	
	ListaDeEventos* mergeSort() {
        if(this->retornaTamanho() < 2) {
            return this;
        }
        int meio = this->retornaTamanho() / 2;
        ListaDeEventos* esquerda = new ListaDeEventos();
        ListaDeEventos* direita = new ListaDeEventos();
        Elemento<Evento*>* anterior = this->retornaCabeca();

        for (int i = 0; i < meio -1 ; i++) {
            anterior = anterior->getProximo();
        }
        direita->defineCabeca(anterior->getProximo());
        esquerda->defineCabeca(this->retornaCabeca());
        anterior->setProximo(0);
        esquerda->defineTamanho(meio);
        direita->defineTamanho(this->retornaTamanho() - meio);
        esquerda = esquerda->mergeSort();
        direita = direita->mergeSort();

        return merge(direita, esquerda);
    }

    ListaDeEventos* merge(ListaDeEventos* dir, ListaDeEventos* esq) {
        ListaDeEventos* resultado = new ListaDeEventos();
        while (dir->retornaTamanho() > 0 || esq->retornaTamanho() > 0) {
            if (dir->retornaTamanho() > 0 && esq->retornaTamanho() > 0) {
                if (esq->retornaCabeca()->getInfo()->getTempo() <= dir->retornaCabeca()->getInfo()->getTempo()){
                    resultado->adiciona(esq->retiraDoInicio());
                } else {
                    resultado->adiciona(dir->retiraDoInicio());
                }
            } else if (esq->retornaTamanho() > 0) {
                resultado->adiciona(esq->retiraDoInicio());
            } else if (dir->retornaTamanho() > 0) {
                resultado->adiciona(dir->retiraDoInicio());
            }
        }
        return resultado;
    }
    
    void adicionaNoInicioEvento(Evento*& dado) {
        // verificaMemoriaCheia();
        Elemento<Evento*>* novo = new Elemento<Evento*>(dado, 0);
        if(novo == 0){
            throw ExcecaoListaCheia;
        }
        novo->setProximo(retornaCabeca());
        defineCabeca(novo);
        defineTamanho(retornaTamanho() + 1);
    }
};

#endif

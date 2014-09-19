/** Copyright[2014]<Emmanuel Podestá Junior>
*/
#ifndef LISTADUPLA_HPP_
#define LISTADUPLA_HPP_
#include "ElementoDupla.hpp"
#include "ExcecaoErroPosicao.hpp"
#include "ExcecaoListaCheia.hpp"
#include "ExcecaoListaVazia.hpp"
#include <iostream>
template <typename T>
class ListaDupla{
 private:
 		Elemento<T>* head;
 		int size;

 		void verificaPosicaoInvalida(int pos) {
            if (pos > size || pos < 0) {
                throw ExcecaoErroPosicao;
            }
        }

         bool verificaMemoriaCheia() {
            Elemento<T> *novo = new Elemento<T>(0, NULL);
            if (novo == NULL) {
                throw ExcecaoListaCheia;
            }
            delete novo;
            return true;
        }


 public:
 	ListaDupla(){
 		head = NULL;
 		size = 0;
 	}
 	~ListaDupla(){
 		destroiLista();
 	}
    void destroiLista(){
        if(!listaVazia()){
            Elemento<T>* eliminar;
            while(head != NULL){
                eliminar = head;
                head = eliminar->getProximo();
                delete eliminar;
            }
        } else {
            throw ExcecaoListaVazia;
        }
    }
    void adiciona(const T& dado){
        adicionaNaPosicao(dado, size);
    }
 	void adicionaNoInicio(const T& dado){
 		verificaMemoriaCheia();
 		Elemento<T>* novo = new Elemento<T>(dado, head, NULL);
 		head = novo;
 		if(novo->getProximo() != NULL){
 			(novo->getProximo())->setAnterior(novo);
 		}
 		size++;
 	}
    T retira(){
        return retiraDaPosicao(size - 1);
    }
 	T retiraDoInicio(){
        if(listaVazia()){
            throw ExcecaoListaVazia;
        }
        Elemento<T>* saiu;
        T volta;
        saiu = head;
        volta = saiu->getInfo();
        head = saiu->getProximo();
        if(head != NULL){
            head = head->setAnterior(NULL);
        }
        size--;
        free(saiu);
        return volta;
    }
    T retiraEspecifico(const T& dado){
        int posicao = posicao(dado);
        retiraDaPosicao(posicao);
    }
    void AdicionaNaPosicao(const T& dado, int pos){
        Elemento<T>* novo = new Elemento<T>(dado, head, NULL);
        Elemento<T>* anterior;
        if(pos > size || pos < 0){
            throw ExcecaoErroPosicao;
        }
        if(pos == 0){
            adicionaNoInicio(dado);
        } else {
            verificaMemoriaCheia();
            anterior = head;
            for(int i = 0; i < pos - 1; i++){
                anterior = anterior->getProximo();
            }
            novo->setProximo() = anterior->getProximo();
            if(novo->getProximo() != NULL){
                (novo->getProximo())->setAnterior(novo);
            }
            novo->setAnterior(anterior);
            head->setProximo(novo);
            size++;
        }
    }
    T retiraDaPosicao(int pos){
        if (pos > size || pos < 0) {
            throw ExcecaoErroPosicao;
        }
        if(pos == 0){
            retiraDoInicio();
        }
        Elemento<T>* eliminar, anterior;
        T volta;
        anterior = head;
        for(int i = 0; i < pos - 1; i++){
            anterior = anterior->getProximo();
        }    
        eliminar = anterior->getProximo();
        volta = eliminar->getInfo();
        anterior->setProximo(eliminar->getProximo());
        if(eliminar->getProximo() != NULL){
            (eliminar->getProximo())->setAnterior(anterior);
        }
        size--;
        delete eliminar;
        return volta;
    }
    void adicionaEmOrdem(const T& dado){
        verificaMemoriaCheia();
        Elemento<T>* atual;
        int posicao = 0;
        atual = head;
        while(atual != NULL && maior(dado, atual->getInfo())){
            atual = atual->getProximo();
            posicao++;
        }
        if(maior(dado, atual->getProximo())){
            AdicionaNaPosicao(dado, posicao + 1);
        } else {
            adicionaNaPosicao(dado, posicao);
        }
    }
    bool listaVazia(){
        return size == 0;
    }
    int posicao(const T& dado){
        Elemento<T>* atual;
        int posicao;
        for(int i = 0; i < size; i++){
            if(igual(dado, atual->getInfo())){
                return i;
            }
            atual = atual->getProximo();
            posicao++;
        }
        if(posicao >= size){
            throw ExcecaoErroPosicao;
        }
    }
    bool maior(const T& dado1, const T& dado2) const{
        return dado1 > dado2;
    }
    bool menor(const T& dado1, const T& dado2) const{
        return dado1 < dado2;
    }
    bool igual(const T& dado1, const T& dado2) const{
        return dado1 == dado2;
    }
};
#endif
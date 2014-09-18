/** Copyright[2014]<Emmanuel Podestá Junior>
*/
#ifndef LISTADUPLA_HPP_
#define LISTADUPLA_HPP_
#include "ElementoDupla.hpp"
#include "ExcecaoErroPosicao.hpp"
#include "ExcecaoListaCheia.hpp"
#include "ExcecaoListaVazia.hpp"
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
 	void adicionaNoInicio(const T& dado){
 		verificaMemoriaCheia();
 		Elemento<T>* novo = new Elemento<T>(dado, head, NULL);
 		head = novo;
 		if(novo->getProximo() != NULL){
 			(novo->getProximo())->setAnterior(novo);
 		}
 		size++;
 	}
 	

};
#endif
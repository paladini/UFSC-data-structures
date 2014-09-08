/*
 * ListaEncadeada.hpp
 *
 *  Created on: 03/09/2014
 *      Author: podesta
 */

#ifndef LISTAENCADEADA_HPP_
#define LISTAENCADEADA_HPP_
#define ERROPOSICAO -3
#define ERROLISTACHEIA -2
#define ERROLISTAVAZIA -1
#include "tElemento.hpp"
#include <cstdio>
template <typename T>
class tLista{
private:
	tElemento *dados;
	int tamanho;

public:
	Lista* criaLista(){
		Lista *aLista;
		aLista = new Lista();
		if(aLista != NULL){
			tamanho = 0;
			dados = NULL;
		}
		return aLista;
	}
	void adiciona(T* dado){
		adicionaNaPosicao(dado, tamanho + 1);
	}
	void adicionaNoInicio(T *dado){
		tElemento<T> *novo;
		novo = new tElemento<T>();
		if(novo == NULL)
			throw ERROLISTACHEIA;
		novo->proximo = dados;
		novo->info = dado;
		dados = novo;
		tamanho = tamanho + 1;
	}
	int adicionaNaPosicao(T* dado, int posicao){
		tElemento<T> *novo, *anterior;
		if(posicao > tamanho + 1){
			throw ERROPOSICAO;
		} else {
			if(posicao == 1){
				return adicionaNoInicio(dado);
			} else {
				novo = new tElemento();
				if(novo == NULL){
					throw ERROLISTACHEIA;
				} else {
					int i;
					anterior = dados;
					for(i = 0; i < posicao - 2; i++){
						anterior = anterior->proximo;
					}
					novo->proximo = anterior->proximo;
					novo->info = dado;
					anterior->proximo = novo;
					tamanho = tamanho + 1;
					return tamanho;
				}
			}
		}
	}
	int adicionaEmOrdem(T* dado){
		tElemento<T> *atual;
		int posicao;
		if (ListaVazia()) {
			return adicionaNoInicio(dado);
		} else {
			atual = dados;
			posicao = 1;
			while (atual->proximo != NULL && maior(dado, atual->info)) {
				atual = atual->proximo;
				posicao = posicao + 1;
			}
			if(maior(dado, atual->info)){
				return adicionaNaPosicao(dado, tamanho + 1);
			} else {
				return adicionaNaPosicao(dado, posicao);
			}
		}
	}

	void retira(){
		retiraDaPosicao(tamanho);
	}
	T* retiraDoInicio(){
		tElemento<T> *saiu;
		T *volta;
		if(!ListaVazia()){
			saiu = dados;
			volta = saiu->info;
			dados = saiu->proximo;
			tamanho = tamanho - 1;
			free(saiu);
			return volta;
		} else {
			throw ERROLISTAVAZIA;
		}
	}
	int eliminaDoInicio(){
		tElemento<T> *saiu;
		if(!ListaVazia()){
			saiu = dados;
			dados = saiu->proximo;
			tamanho = tamanho - 1;
			free(saiu->proximo);
			free(saiu);
			return tamanho;
		} else {
			throw ERROLISTAVAZIA;
		}
	}
	T* retiraDaPosicao(int posicao){
		tElemento<T> *anterior, *eliminar;
		T* volta;
		if(posicao > tamanho + 1){
			throw ERROPOSICAO;
		} else {
			int i;
			anterior = dados;
			for(i = 0; i < posicao - 2; i++){
				anterior = anterior->proximo;
			}
			eliminar = anterior->proximo;
			volta = eliminar->info;
			anterior->proximo = eliminar->proximo;
			free(eliminar);
			return volta;
		}
	}
	int retiraEspecifico(T* dado){
		int posicao = posicao(dado);
		return adicionaNaPosicao(dado, posicao);
	}
	int posicao(T* dado){
		tElemento<T> *atual;
		atual = dados;
		int i;
		for(i = 0; i <= tamanho; i++){
			if(igual(atual->info, dado)){
				break;
			}
		}
		if(i > tamanho){
			throw ERROPOSICAO;
		}
		return i;
	}
	bool ListaVazia() {
		return tamanho == 0;
	}
	bool maior(T* dado1, T* dado2){
		return dado1 > dado2;
	}
	bool menor(T* dado1, T* dado2){
		return dado1 < dado2;
	}
	bool igual(T* dado1, T* dado2){
		return dado1 == dado2;
	}
};




#endif /* LISTAENCADEADA_HPP_ */

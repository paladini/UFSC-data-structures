/**
* File: Lista.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 25 de Agosto de 2014, 20:52.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
/** Classe Lista.
* A classe Lista implementa uma lista de vetores simples, não-encadeada, que tem métodos
* como fornecer posição do ponteiro, adicionar elemento no início, adicionar elemento na posição,
* remover item da posição, remover do início, existe, entre outros.
*/
#ifndef LISTA_HPP_
#define LISTA_HPP_
#define MAXLISTA 10
#include "ExcecaoListaCheia.hpp"
#include "ExcecaoListaVazia.hpp"
#include "ExcecaoErroPosicao.hpp"
template<typename T>
/*
	Prezei pela performance e reusabilidade de código em detrimento da claridade dos métodos.
*/
class Lista{
 private:
	T *dados;
	int ultimo, tamanho;

 public:
	Lista() {
		dados = new T[MAXLISTA];
		tamanho = MAXLISTA;
		limparLista();
	}

	explicit Lista(int tamanhoDaLista) {
		dados = new T[tamanhoDaLista];
		tamanho = tamanhoDaLista;
		limparLista();
	}

	~Lista() {
		limparLista();
		delete[] dados;
	}
	void limparLista() {
		ultimo = -1;
	}

	void adiciona(T dado) {
		adicionaNaPosicao(dado, ultimo+1);
	}

	void adicionaNoInicio(T dado) {
		adicionaNaPosicao(dado, 0);
	}

	void adicionaNaPosicao(T dado, int posicao) {
		if(listaCheia()) {
			throw ExcecaoListaCheia;
		} else {
			if(posicao < 0 || posicao > ultimo + 1) {
				throw ExcecaoErroPosicao;
			} else {
				ultimo = ultimo + 1;
				int i;
				for(i = ultimo; i > posicao; i--) {
					if(i >= posicao) {
						dados[i] = dados[i - 1];
					}
				}
				dados[posicao] = dado;
			}
		}
	}
	void adicionaEmOrdem(T dado) {
		if(listaCheia()) {
		 	throw ExcecaoListaCheia;
		} else {
			int posicao = 0;
			for(int i = 0; i < ultimo; i++) {
				if(dado > dados[i]) {
				    posicao++;
				}
			}
			adicionaNaPosicao(dado, posicao);
		}
	}

	T retira() {
		return retiraDaPosicao(ultimo);
	}

	T retiraDoInicio() {
		return retiraDaPosicao(0);
	}

	T retiraDaPosicao(int posicao) {
		T dadoRetorno;
		if(listaVazia()) {
			throw ExcecaoListaVazia;
		} else {
			if(posicao < 0 || posicao > ultimo) {
				throw ExcecaoErroPosicao;
			} else {
				dadoRetorno = dados[posicao];
				ultimo = ultimo - 1;
				int i;
				for(i = posicao; i < ultimo; i++) {
					dados[i] = dados[i+1];
				}
				return dadoRetorno;
			}
		}
	}

	T retiraEspecifico(T dado) {
		int indice = posicao(dado);
		return retiraDaPosicao(indice);
	}

	int posicao(T dado) {
		int posicao = 0;
		for(int i = 0; i <= ultimo; i++) {
			if(igual(dado, dados[i])) {
				break;
			} else {
				posicao++;
			}
		}
		if(posicao > ultimo) {
			throw ExcecaoErroPosicao;
		} else {
			return posicao;
		}
	}

	bool contem(T dado) {
		try {
			posicao(dado);
		} catch(std::exception& e) {
			return false;
		}
		return true;
	}

	bool igual(T dado1, T dado2) {
		return dado1 == dado2;
	}

	bool maior(T dado1, T dado2) {
		return dado1 > dado2;
	}
	bool menor(T dado1, T dado2) {
		return dado1 < dado2;
	}

	bool listaCheia() {
		return ultimo == tamanho - 1;
	}

	bool listaVazia() {
		return ultimo == -1;
	}

	void destroiLista() {
		limparLista();
	}
};
#endif /* LISTA_HPP_ */

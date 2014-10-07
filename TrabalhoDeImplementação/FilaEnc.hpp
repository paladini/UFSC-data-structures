/*
 * File:   FilaEnc.hpp
 * @author: Emmanuel Podestá, Fernando Paladini.
 * @since: Created on 26 de Setembro de 2014, 20:35
 * Copyright 2014 Emmanuel Podestá, Fernando Paladini.
 * < Na verdade é Copyleft, MIT License \o/ >
 */
#ifndef FILAENC_HPP_
#define FILAENC_HPP_
#include "ListaEnc.hpp"
template<typename T>
 /** Classe Fila Encadeada
 * Essa classe representará uma fila encadeada que herda métodos e atributos da ListaEncadeada.
 */
class FilaEnc: private ListaEnc<T>{
 private:
  Elemento<T>* fim;

 public:
 	/** Construtor da fila encadeada sem argumento.
     * Este construtor tem o mesmo comportamento do contrutor da classe ListaEncadeada, exceto que declara
     * o atributo "fim" (específico da FilaEnc) como NULL.
     * @see ListaEnc<T>()
     */
	FilaEnc() {
		ListaEnc<T> *fila = new ListaEnc<T>();
		if (fila != NULL) {
			fim = NULL;
		}
	}

	/** Destrutor da fila encadeada.
     * Esse destrutor desaloca a memória que foi alocada para a FilaEncadeada limpando todos os elementos dela.
     */
	~FilaEnc() {
		limparFila();
	}

	/** Método inclui.
     * Este método é responsável por incluir um dado na fila encadeada. 
     * @see filaVazia();
     * @see ListaEnc<T>::verificarMemoriaCheia();
     */
	void inclui(const T& dado) {
		// this->verificaMemoriaCheia();
		Elemento<T>* novo = new Elemento<T>(dado, NULL);
		if (filaVazia()) {
			this->defineCabeca(novo);
		} else {
			fim->setProximo(novo);
		}
		fim = novo;
		this->defineTamanho(this->retornaTamanho() + 1);
	}

	/** Método retira.
     * Este método tem a função de retirar um elemento da fila encadeada. Basicamente utiliza o método
     * retiraDoInicio(), da Fila Encadeada.
     * @see ListaEnc<T>::retiraDoInicio()
     * @return O objeto retirado da fila encadeada.
     */
	T retira() {
		return this->retiraDoInicio();
	}

	/** Método ultimo.
     * Retorna o último elemento da Fila Encadeada sem removê-lo da estrutura de dados.
     * @see ListaEnc<T>::retornaDado();
     * @return Retorna o último elemento da Fila Encadeada.
     */
	T ultimo() {
		return this->retornaDado(this->retornaTamanho()-1);
	}

	/** Método primeira.
     * Retorna o primeiro elemento da Fila Encadeada sem removê-lo da estrutura de dados.
     * Basicamente chama o método "retornaDado()" da classa superior na posição 0, ou seja,
     * retorna o elemento que está no começo da estrutura de dados.
     * @see ListaEnc<T>::retornaDado();
     * @return Retorna o primeiro elemento da Fila Encadeada.
     */
	T primeiro() {
		return this->retornaDado(0);
	}

	/** Método FilaVazia.
     * Este método tem a função de verificar se a fila está ou não vazia. 
     * Chama o método listaVazia() da classe superior, ListaEncadeada.
     * @see ListaEnc<T>::listaVazia();
     * @return um boolean que, se true, indica que a fila está vazia.
     */
	bool filaVazia() {
		return this->listaVazia();
	}

	/** Método limparFIla.
     * Este método tem a função desacolar toda a memória alocada por esta estrutura de dados 
     * (com o objetivo de evitar segmentation fault's). Chama o método destróiLista da classe superior.
     * @see ListaEnc<T>::destroiLista();
     */
	void limparFila() {
		this->destroiLista();
	}
};

#endif

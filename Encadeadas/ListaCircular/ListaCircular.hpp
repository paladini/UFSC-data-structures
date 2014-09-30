/**
* File: ListaCirc.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 28 de Setembro de 2014, 21:30.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
/** Classe ListaCirc.
* A classe ListaCirc implementa a estrutura de dados lista circular simples, uma lista formada por
* uma "head", que é um ponteiro para um objeto do tipo Elemento; e um "size", que indica o tamanho
* dessa lista circular simples.
*/
#ifndef LISTACIRC_HPP_
#define LISTACIRC_HPP_
#include <cstdio>
#include "Elemento.hpp"
#include "ListaEnc.hpp"
#include "ExcecaoErroPosicao.hpp"
#include "ExcecaoListaCheia.hpp"
#include "ExcecaoListaVazia.hpp"
template<typename T>
class ListaCirc: public ListaEnc<T> {
 private:
    Elemento<T>* sentinel;

 public:
    /** Construtor padrão da ListaCirc.
    * O construtor padrão da ListaCirc constroi uma lista circular simples vazia e "head" apontando para NULL.
    */
    ListaCirc(): ListaEnc<T>() {
        sentinel = new Elemento<T>(0, 0);
        this->defineCabeca(sentinel);
        sentinel->setProximo(this->retornaCabeca());
    }
    /** Destrutor padrão da ListaCirc.
    * O destrutor padrão da ListaCirc destrói a lista circular simples.
    */
    ~ListaCirc() {
        destroiLista();
    }
    // Início
    /** Adiciona um novo elemento no começo da Lista Circular Simples.
    * Este método recebe um dado do tipo T e adiciona este elemento no começo da lista.
    * @param dado O dado que será inserido dentro da lista.
    * @exception ExcecaoListaCheia Exceção que indica que um novo dado não pode ser adicionado, pois não há mais espaço em memória.
    */
    void adicionaNoInicio(const T& dado) {
        this->verificaMemoriaCheia();
        Elemento<T> *novo = new Elemento<T>(dado, sentinel->getProximo());
        sentinel->setProximo(novo);
        this->defineTamanho(this->retornaTamanho() + 1);
    }
    /** Retira um elemento no começo da lista circular simples.
    * Este método retira o primeiro elemento da lista circular simples, retornando o objeto retirado.
    * @see listaVazia()
    * @return O elemento que estava no começo da lista ou NULL caso a lista esteja vazia.
    */
    T retiraDoInicio() {
        if (!this->listaVazia()) {
            Elemento<T> *saiu = sentinel->getProximo();
            T volta = saiu->getInfo();
            sentinel->setProximo(saiu->getProximo());
            this->defineTamanho(this->retornaTamanho() - 1);
            delete saiu;
            return volta;
        }
        throw ExcecaoListaVazia;
    }
    /** Elimina um elemento no começo da lista circular simples.
    * Este método elimina o primeiro elemento da lista circular simples, ou seja, destrói o objeto sem retornar qualquer valor.
    * Chama o método "retiraDoInicio()" e caso este método retorne um objeto T, apaga esse objeto da memória.
    * @see retiraDoInicio()
    * @exception ExcecaoListaVazia Exceção que indica que o dado não pode ser eliminado pois a lista está vazia.
    */
    void eliminaDoInicio() {
        if (!this->listaVazia()) {
            Elemento<T> *saiu = sentinel->getProximo();
            sentinel->setProximo(saiu->getProximo());
            this->defineTamanho(this->retornaTamanho() - 1);
            delete saiu;
        }
        throw ExcecaoListaVazia;
    }
    // Posição
    /** Adiciona um novo elemento na posição dada.
    * Este método recebe um dado do tipo T e adiciona este elemento na posição "pos".
    * @param dado O dado que será inserido dentro da lista.
    * @param pos A posição em que o dado será adicionado.
    * @exception ExcecaoListaCheia Exceção que indica que um novo dado não pode ser adicionado, pois não há mais espaço em memória.
    * @exception ExcecaoErroPosicao A posição dada excedeu o tamanho dessa estrutura, ou seja, foi maior do que "size + 1".
    */
    void adicionaNaPosicao(const T& dado, int pos) {
        this->verificaPosicaoInvalida(pos);
        if (pos == 0) {
            adicionaNoInicio(dado);
            return;
        }
        this->verificaMemoriaCheia();
        Elemento<T> *anterior = sentinel->getProximo();
        for (int i = 0; i < pos - 1; i++) {
            anterior = anterior->getProximo();
        }
        Elemento<T> *novo = new Elemento<T>(dado, anterior->getProximo());
        anterior->setProximo(novo);
        this->defineTamanho(this->retornaTamanho() + 1);
    }
    /** Verifica a posição de um dado dentro da lista circular simples.
    * Este método recebe um dado que será analisado para verificar se este dado está dentro da Lista.
    * @param dado O dado que será verificado a existência dentro da lista.
    * @exception ExcecaoListaVazia Exceção que indica que a lista está vazia, ou seja, não tem como esse dado existir dentro da lista circular simples.
    * @exception ExcecaoErroPosicao Exceção que indica que o dado do tipo T fornecido não está presente na lista.
    * @return um inteiro que indica a posição em que o dado se encontrava.
    */
    int posicao(const T& dado) const {
        if (this->listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            Elemento<T> *atual = sentinel->getProximo();
            for (int i = 0; i < this->retornaTamanho(); i++) {
               if (this->igual(atual->getInfo(), dado)) {
                    return i;
                }
                atual = atual->getProximo();
            }
            throw ExcecaoErroPosicao;
        }
    }
    /** Verifica a posição de memória de um dado já inserido na Lista.
    * Este método recebe um dado que será analisado para verificar se este dado está dentro da Lista.
    * @param dado O dado que será verificado a existência dentro da lista.
    * @see listaVazia()
    * @see igual(const T dado1, const T dado2)
    * @exception ExcecaoListaVazia Exceção que indica que a lista está vazia, ou seja, não tem como esse dado existir dentro da lista circular simples.
    * @exception ExcecaoErroPosicao Exceção que indica que o dado do tipo T fornecido não está presente na lista.
    * @return um ponteiro para T que indica a posição de memória em que o dado se encontrava.
    */
    T* posicaoMem(const T& dado) const {
        if (this->listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            Elemento<T> *atual = sentinel->getProximo();
            for (int i = 0; i < this->retornaTamanho(); i++) {
                if (this->igual(atual->getInfo(), dado)) {
                    return &atual->getInfo();
                }
                atual = atual->getProximo();
            }
        }
        throw ExcecaoErroPosicao;
    }
    /** Verifica se determinado dado existe dentro da lista circular simples.
    * Este método recebe um dado que será analisado para verificar se este dado está dentro da Lista.
    * @param dado O dado que será verificado a existência dentro da lista.
    * @see posicao(const T& dado)
    * @return um boolean que indica se o dado está presente (true) ou não (false) dentro da lista.
    */
    bool contem(const T& dado) {
        try {
            posicao(dado);
            return true;
        } catch(std::exception& e) {
            return false;
        }
    }
    /** Retira um elemento de dentro da lista de acordo com a posição dada.
    * Este método recebe um inteiro que indica a posição de um dado que se deseja retirar da lista circular simples.
    * @param pos A posição do dado que se deseja retirar.
    * @see retiraDoInicio()
    * @see retornaAnterior(int pos)
    * @return um objeto T que foi retirado da posição especificada. Retorna NULL se não conseguiu pegar um dado dessa posição.
    */
    T retiraDaPosicao(int pos) {
        T volta;
        this->verificaPosicaoInvalida(pos);
        if (pos == 0) {
            retiraDoInicio();
        } else {
            Elemento<T> *anterior = sentinel->getProximo();
            for (int i = 0; i < pos - 2; i++) {
                anterior = anterior->getProximo();
            }
            Elemento<T> *eliminar = anterior->getProximo();
            volta = eliminar->getInfo();
            anterior->setProximo(eliminar->getProximo());
            delete eliminar;
            this->defineTamanho(this->retornaTamanho() - 1);
        }
        return volta;
    }
// Fim
/** Adiciona um novo elemento no final da Lista.
* Este método recebe um dado do tipo T e adiciona este elemento no final da lista, ou seja, adiciona esse dado na última posição da lista.
* @param dado O dado que será inserido dentro da lista.
* @see adicionaNaPosicao(const T& dado, int pos)
* @exception ExcecaoListaCheia Exceção que indica que um novo dado não pode ser adicionado, pois não há mais espaço em memória.
* @exception ExcecaoErroPosicao A posição dada excedeu o tamanho dessa estrutura, ou seja, foi maior do que "size + 1".
*/
    void adiciona(const T& dado) {
        adicionaNaPosicao(dado, this->retornaTamanho());
    }
/** Retira o último elemento da Lista.
* Este método retira o último elemento da lista circular simples.
* @see retiraDaPosicao(int pos)
* @return o dado do tipo T que foi retirado do final da Lista.
*/
    T retira() {
        return retiraDaPosicao(this->retornaTamanho());
    }
    
// Específico
/** Adiciona um novo elemento ordenado de forma ascendente.
* Este método recebe um dado do tipo T e adiciona este elemento na posição "pos".
* @param dado O dado que será inserido dentro da lista.
* @param pos A posição em que o dado será adicionado.
* @exception ExcecaoListaCheia Exceção que indica que um novo dado não pode ser adicionado, pois não há mais espaço em memória.
* @exception ExcecaoErroPosicao A posição dada excedeu o tamanho dessa estrutura, ou seja, foi maior do que "size + 1".
*/
    void adicionaEmOrdem(const T& data) {
        Elemento<T> *atual;
        int posicao;
        if (this->listaVazia()) {
            adicionaNoInicio(data);
        } else {
            atual = sentinel->getProximo();
            posicao = 1;
            while (atual->getProximo() != sentinel &&
                    this->maior(data, atual->getInfo())) {
                atual = atual->getProximo();
                posicao++;
            }
            if (this->maior(data, atual->getInfo())) {
                adicionaNaPosicao(data, posicao + 1);
            } else {
                adicionaNaPosicao(data, posicao);
            }
        }
    }

    /** Método responsável por destruir a Lista Circular.
    * Destrói a lista circular simples e desaloca todo o espaço de memória por ela ocupado.
    */
    void destroiLista() {
        Elemento<T> *atual;
        if (!this->listaVazia()) {
            for (int i = 0; i < this->retornaTamanho(); i++) {
                atual = sentinel->getProximo();
                sentinel->setProximo(atual->getProximo());
                delete atual;
            }
        }
        this->defineTamanho(0);
    }
    /** Retorna um dado de determinada posição sem removê-lo da lista circular.
    * @param posicao Dado a ser comparado que ficará à esquerda do operador de comparação.
    * @return Retorna o dado da posição informada - se ele existir, caso contrário retorna uma exceção.
    */
    T retornaDado(int posicao) {
        this->verificaPosicaoInvalida(posicao);
        if (this->listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            Elemento<T> *atual = sentinel->getProximo();
            if (posicao == 0) {
                return atual->getInfo();
            }
            for (int i = 0; i < posicao; i++) {
                atual = atual->getProximo();
            }
            return atual->getInfo();
        }
    }
};
#endif

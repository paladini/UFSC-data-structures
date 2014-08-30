/*
 * File:   Pilha.hpp
 * Author: podesta
 *
 * Created on 22 de Agosto de 2014, 16:11
 */

#ifndef PILHA_HPP
#define	PILHA_HPP
#include "EstruturaLinear.hpp"
template<typename T>
class Pilha : private EstruturaLinear<T> {
 public:
    Pilha() : EstruturaLinear<T>() {
    }

    Pilha<T>(int t) : EstruturaLinear<T>(t) {
    }

    void empilha(T dado) {
        EstruturaLinear<T>::insere(dado);
    }

    T desempilha() {
        if (!(PilhaVazia())) {
            this->ponteiro = this->ponteiro - 1;
            return this->m_dados[this->ponteiro + 1];
        } else {
            throw EMPTYERROR;
        }
    }

    bool PilhaVazia() {
        return EstruturaLinear<T>::estaVazio();
    }

    T topo() {
        return EstruturaLinear<T>::Ponteiro();
    }

    void limparPilha() {
        EstruturaLinear<T>::limpar();
    }

    bool PilhaCheia() {
        return EstruturaLinear<T>::estaCheio();
    }

    int getPosTopo() {
        return EstruturaLinear<T>::getPosPonteiro();
    }
};


#endif	/* PILHA_HPP */

/*
 * File:   EstruturaLinear.hpp
 * Author: podesta
 *
 * Created on 25 de Agosto de 2014, 20:52
 */

#ifndef ESTRUTURALINEAR_HPP
#define	ESTRUTURALINEAR_HPP
#define FULLERROR -1
#define EMPTYERROR -2
#define MAX 100
template<typename T>
class EstruturaLinear {
 protected:
     T *m_dados;
     int ponteiro, tamanhoDaEstrutura;

 public:
     EstruturaLinear() {
         m_dados = new T[MAX];
         tamanhoDaEstrutura = MAX;
         limpar();
     }
     EstruturaLinear<T>(int tamanho) {
         m_dados = new T[tamanho];
         tamanhoDaEstrutura = tamanho;
         limpar();
     }
     ~EstruturaLinear() {
        delete[] m_dados;
    }
     void insere(T dado) {
        if (!estaCheio()) {
                this->m_dados[++ponteiro] = dado;
            } else {
                throw FULLERROR;
            }
     }
     void limpar() {
         ponteiro = -1;
     }
     T Ponteiro() {
         if (!estaVazio()) {
             return m_dados[ponteiro];
         } else {
             throw EMPTYERROR;
         }
     }
     int getPosPonteiro() {
         if (!estaVazio()) {
             return ponteiro;
         } else {
             throw EMPTYERROR;
         }
     }
     bool estaVazio() {
         return (ponteiro == -1);
     }
     bool estaCheio() {
         return (ponteiro == tamanhoDaEstrutura - 1);
     }
};


#endif	/* ESTRUTURALINEAR_HPP */


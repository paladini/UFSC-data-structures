/*
 * File:   FIla.hpp
 * Author: podesta
 *
 * Created on 23 de Agosto de 2014, 20:35
 */

#ifndef FILA_HPP
#define	FILA_HPP
#define MAXFILA 100
#include "EstruturaLinear.hpp"
// #include "EstruturaLinearVazia.hpp"
template<typename T>
class Fila : private EstruturaLinear<T> {
 public:
     Fila() : EstruturaLinear<T>(){}
     Fila<T>(int tam) : EstruturaLinear<T>(tam){}
     void inclui(T dado){
         EstruturaLinear<T>::insere(dado);
     }
     T retira(){ // dúvida ordem de decrementação do ponteiro
         if(!filaVazia()){
             T valorRetirado = this->m_dados[0];
             for(int k = 0; k < this->ponteiro; k++){
                 this->m_dados[k] = this->m_dados[k + 1];
             }
             this->ponteiro = this->ponteiro - 1;
             return valorRetirado;
         } else {
             throw EstruturaLinearVazia::EstruturaLinearVazia();
         }
     }
     T ultimo(){
         return EstruturaLinear<T>::Ponteiro();
     }
     void inicializaFila(){
         EstruturaLinear<T>::limpar();
     }
     bool filaVazia(){
         return EstruturaLinear<T>::estaVazio();
     }
     bool filaCheia(){
         return EstruturaLinear<T>::estaCheio();
     }
     int getPosUltimo(){
         return EstruturaLinear<T>::getPosPonteiro();
     }
};

#endif	/* FILA_HPP */


/*
 * File:   Fila.hpp
 * @author: Emmanuel Podestá, Fernando Paladini.
 * @since: Created on 23 de Agosto de 2014, 20:35
 * Copyright 2014 Emmanuel Podestá, Fernando Paladini.
 * < Na verdade é Copyleft, MIT License \o/ >
 */

#ifndef FILA_HPP
#define	FILA_HPP
#define MAXFILA 100
#include "EstruturaLinear.hpp"
 
template<typename T>
/** Classe Fila
 * Essa classe representará uma fila que herda métodos e atributos
 *
 */
class Fila : private EstruturaLinear<T> {
 public:
     /** Construtor da fila sem argumento.
     * Este construtor tem o mesmo comportamento do contrutor da classe Estrutura Linear, pois a classe Fila herda o seu construtor.
     * @see EstruturaLinear<T>()
     */
     Fila() : EstruturaLinear<T>() {}

     /** Construtor da fila com argumento.
     * Seu comportamento é o mesmo do construtor da Estrutura Linear com argumento. Note que como especificado anteriormente
     * construtores e alguns métodos terão o mesmo comportamento dos métodos da classe Estrutura Linear.
     * @see EstruturaLinear<T>(t)
     */
     Fila<T>(int tam) : EstruturaLinear<T>(tam) {}

     /** Método inclui.
     * Este método é responsável por incluir um dado na fila. 
     * Chama o método insere() da classe superior, EstruturaLinear.
     * @see EstruturaLinear<T>::insere(dado)
     */
     void inclui(T dado) {
         EstruturaLinear<T>::insere(dado);
     }

     /** Método retira.
     * Este método tem a função de retirar um elemento da fila. Antes de mais nada, verifica se a fila
     * está vazia. Se estiver, lança uma exceção de erro chamada EMPTYERROR. Caso a fila não esteja vazia
     * prossegue e retira o primeiro elemento da fila (chamado de "último"). Após, itera sobre todos os 
     * elementos da fila piuxando eles uma posição para frente (m_dados[k] = m_dados[k+1]).
     * Só então decrementa o ponteiro e retorna o valor retirado da frente da fila. 
     * @see filaVazia()
     * @return Um objeto do tipo da instância instanciada.
     */
     T retira() {   // dúvida ordem de decrementação do ponteiro
         if (!filaVazia()) {
             T valorRetirado = this->m_dados[0];
             for (int k = 0; k < this->ponteiro; k++) {
                 this->m_dados[k] = this->m_dados[k + 1];
             }
             this->ponteiro = this->ponteiro - 1;
             return valorRetirado;
         } else {
             throw EMPTYERROR;
         }
     }

     /** Método ultimo.
     * Sua função é a mesma do método Ponteiro da classe Estrutura Linear. Verifica-se onde o ponteiro está posicionado e retiramos
     * um dado de sua posição. Note que como o método Ponteiro possui uma exceção se tentar adquirir o dado de uma Estrutura Linear vazia
     * pode-se perceber que os dois métodos, getUltimo e Ponteiro, retornarão o valor do último dado. Logo, como o método retorna um dado
     * da Fila, seu retorno deverá ser um tipo qualquer.
     * @see EstruturaLinear<T>::Ponteiro()
     * @return o objeto do tipo da instancia que está como ultimo elemento da fila.
     */
     T ultimo() {
         return EstruturaLinear<T>::Ponteiro();
     }

     /**
      * 
      * @see EstruturaLinear<T>::limpar()
      */
     void inicializaFila() {
         EstruturaLinear<T>::limpar();
     }

     /** Método FilaVazia.
     * Este método tem a função de verificar se a fila está ou não vazia. 
     * Chama o método estaVazio() da classe superior, EstruturaLinear.
     * @see EstruturaLinear<T>::estaVazio()
     * @return um boolean que, se true, indica que a fila está vazia.
     */
     bool filaVazia() {
         return EstruturaLinear<T>::estaVazio();
     }

     /** Método filaCheia.
     * Sua função é verificar se a fila está cheia ou vazia. 
     * Chama o método estaCheio() da classe superior, EstruturaLinear.
     * @see EstruturaLinear<T>::estaCheio()
     * @return um boolean que, se true, indica que a fila está cheia.
     */
     bool filaCheia() {
         return EstruturaLinear<T>::estaCheio();
     }

     /** Método getUltimo.
     * Sua função se resume em adquirir a posição do ultimo da fila, é análoga ao atributo ponteiro da classe superior. 
     * Chama o método getPosPonteiro() da classe superior, EstruturaLinear.
     * @see EstruturaLinear<T>::getPosPonteiro()
     * @return um inteiro que indica qual o índice do objeto que está em último na fila.
     */
     int getUltimo(){
         return EstruturaLinear<T>::getPosPonteiro();
     }
};

#endif	/* FILA_HPP */

            
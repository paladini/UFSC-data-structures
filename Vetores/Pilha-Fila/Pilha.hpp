/** 
 * File:   Pilha.hpp
 * @author: Emmanuel Podestá, Fernando Paladini.
 * @since: Created on 22 de Agosto de 2014, 16:11
 * Copyright 2014 Emmanuel Podestá, Fernando Paladini.
 * < Na verdade é Copyleft, MIT License \o/ >
 */

#ifndef PILHA_HPP
#define	PILHA_HPP
#include "EstruturaLinear.hpp"

template<typename T>
/** Classe Pilha.
 * Essa classe será responsável por representar uma pilha que herda métodos e atributos da classe Estrutura Linear. Tendo
 * como métodos: empilha, limparPilha, PilhaVazia, PilhaCheia, topo, getPosTopo, onde tais métodos são herdados da classe
 * Estrutura Linear, pois o seu comportamento é o mesmo. A classe Pilha utiliza todos os métodos de sua classe superior
 * menos o método desempilha, pois como neste projeto temos a classe Fila que possui um comportamento diferente na questçao de
 * "desempilhar" um elemento.
 */
class Pilha : private EstruturaLinear<T> {
 public:
    /** Construtor da Pilha sem argumento.
     * Este construtor tem o mesmo comportamento do contrutor da classe Estrutura Linear, pois a classe Pilha herda o seu construtor.
     * @see EstruturaLinear<T>()
     */
    Pilha() : EstruturaLinear<T>() {
    }

    /** Construtor da pilha com argumento.
     * Seu comportamento é o mesmo do construtor da Estrutura Linear com argumento. Note que como especificado anteriormente
     * construtores e alguns métodos terão o mesmo comportamento dos métodos da classe Estrutura Linear.
     * @see EstruturaLinear<T>(t)
     */
    Pilha<T>(int t) : EstruturaLinear<T>(t) {
    }

    /** Método Empilha.
     * Este método é responsável por empilhar um dado na Pilha. Empilhando-o no topo dela e somando uma posição no valor do ponteiro.
     * Note que o método empilha herda o comportamento do método insere da Estrutura Linear.
     * @see EstruturaLinear<T>::insere(dado)
     */
    void empilha(T dado) {
        EstruturaLinear<T>::insere(dado);
    }

    /** Método desempilha.
     * Este método tem a função de desempilhar um elemento da Pilha. Para isso é feito uma verificação se a Pilha está ou não vazia, pois
     * se a Pilha estiver vazia não teremos como retirar elemento algum. Contudo, se ela n estiver vazia podemos desempilhar um elemento
     * diminuindo o valor do ponteiro (ou topo no contexto da Pilha) e "tirando" o valor que estava naquela posição. Pode-se perceber
     * que não retiramos efetivamente o dado, mas só "escondemos" ele da Pilha.
     * @see PilhaVazia()
     * @return Um objeto do tipo da instância instanciada.
     */
    T desempilha() {
        if (!(PilhaVazia())) {
            this->ponteiro = this->ponteiro - 1;
            return this->m_dados[this->ponteiro + 1];
        } else {
            throw EMPTYERROR;
        }
    }

    /** Método PilhaVazia.
     * Este método tem a função de verificar se a Pilha está ou não vazia. Ele possui o mesmo comportamento do método estaVazio
     * da Estrutura Linear. Onde verifica-se a posição do ponteiro e compara a mesma com -1.
     * @see EstruturaLinear<T>::estaVazio()
     * @return um boolean que, se true, indica que a pilha está vazia.
     */
    bool PilhaVazia() {
        return EstruturaLinear<T>::estaVazio();
    }

    /** Método topo.
     * Sua função é a mesma do método Ponteiro da classe Estrutura Linear. Verifica-se onde o ponteiro está posicionado e retiramos
     * um dado de sua posição. Note que como o método Ponteiro possui uma exceção se tentar adquirir o dado de uma Estrutura Linear vazia
     * pode-se perceber que os dois métodos, topo e Ponteiro, retornarão o valor do último dado. Logo, como o método retorna um dado
     * da Pilha, seu retorno deverá ser um tipo qualquer.
     * @see EstruturaLinear<T>::Ponteiro()
     * @return o objeto do tipo da instancia que está no Topo da Pilha.
     */
    T topo() {
        return EstruturaLinear<T>::Ponteiro();
    }

    /** Método limparPilha.
     * Este método é analogo ao método limpar da classe Estrutura Linear, pois o comportamento do limparPilha é dado pelo próprio
     * método limpar da classe superior.
     * @see EstruturaLinear<T>::limpar()
     */
    void limparPilha() {
        EstruturaLinear<T>::limpar();
    }

    /** Método PilhaCheia.
     * Sua função é verificar se a Pilha está cheia ou vazia. Para conseguir executar esta verificação, o método faz seu comportamento
     * de acordo com o comportamento do estaCheio da Estrutura Linear. Note que o método PilhaCheia retornar o que o método da Estrutura
     * Linear retornar. Logo, a execução deste método, depende da execução do estaCheio.
     * @see EstruturaLinear<T>::estaCheio()
     * @return um boolean que, se true, indica que a pilha está cheia.
     */
    bool PilhaCheia() {
        return EstruturaLinear<T>::estaCheio();
    }

    /** Método getPosTopo.
     * Sua função se resume em adquirir a posição do topo da pilha que, como a Pilha herda atributos da classe Estrutura Linear,
     * é análoga ao atributo ponteiro da classe superior. Contudo, já possuimos uma classe que coleta esta informação que é o
     * método getPosPonteiro. Logo, podemos atribuir o comportamento do getPosTopo para este método. Note que ele
     * retorna com o valor retornado pela execução do getPosPonteiro.
     * @see EstruturaLinear<T>::getPosPonteiro()
     * @return um inteiro que indica qual o índice do objeto que está no topo da pilha.
     */
    int getPosTopo() {
        return EstruturaLinear<T>::getPosPonteiro();
    }
};


#endif	/* PILHA_HPP */



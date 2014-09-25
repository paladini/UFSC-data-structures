/** 
 * File:   PilhaEnc.hpp
 * @author: Emmanuel Podestá, Fernando Paladini.
 * @since: Created on 25 de Setembro de 2014, 14:00
 * Copyright 2014 Emmanuel Podestá, Fernando Paladini.
 * < Na verdade é Copyleft, MIT License \o/ >
 */
#ifndef PILHAENC_HPP_
#define PILHAENC_HPP_
#include "ListaEnc.hpp"
template<typename T>
 /** Classe Pilha Encadeada.
 * Essa classe será responsável por representar uma pilha que herda métodos e atributos da classe Lista Encadeada. Tendo
 * como métodos: empilha, desempilha, limparPilha, PilhaVazia e topo. A classe Pilha utiliza todos os métodos de sua classe superior: ListaEnc.
 */
class PilhaEnc: private ListaEnc<T> {
 public:
    /** Construtor da Pilha Encadeada sem argumento.
     * Este construtor tem o mesmo comportamento do contrutor da classe Lista Encadeada.
     * @see ListaEnc<T>()
     */
    PilhaEnc(): ListaEnc<T>() {}

    /** Destrutor da Pilha Encadeada.
     * Este destrutor utiliza o método destroiLista() para limpar da memória todos os dados da PilhaEncadeada.
     * @see ListaEnc<T>::destroiLista()
     */
    ~PilhaEnc() {
        this->destroiLista();
    }

    /** Método Empilha.
     * Este método é responsável por empilhar um dado na Pilha Encadeada. 
     * Empilhando-o no topo dela e somando uma posição no valor do ponteiro.
     * @param dado O dado que será adicionado no topo da Pilha. 
     * @see ListaEnc<T>::adicionaNoInicio(dado)
     */
    void empilha(const T& dado) {
        this->adicionaNoInicio(dado);
    }

    /** Método desempilha.
     * Este método tem a função de desempilhar um elemento da Pilha. Para isso é feito uma verificação se a Pilha está ou não vazia, pois
     * se a Pilha estiver vazia não teremos como retirar elemento algum. Contudo, se ela não estiver vazia podemos desempilhar um elemento
     * diminuindo o valor do ponteiro (ou topo no contexto da Pilha) e "tirando" o valor que estava naquela posição. Pode-se perceber
     * que não retiramos efetivamente o dado, mas só "escondemos" ele da Pilha.
     * @see ListaEnc<T>::retiraDoInicio()
     * @return O objeto que estava no topo da pilha encadeada.
     */
    T desempilha() {
        return this->retiraDoInicio();
    }

    /** Método topo.
     * Retorna o dado que está no topo da Pilha Encadeada sem removê-lo.
     * @see ListaEnc<T>::coletaDado(0)
     * @return O objeto que está no topo da pilha encadeada.
     */
    T topo() {
        return this->coletaDado(0);
    }

    /** Método LimparPilha.
     * Este método é analogo ao método limpar da classe Estrutura Linear, pois o comportamento do limparPilha é dado pelo próprio
     * método limpar da classe superior.
     * @see PilhaEnc<T>::destroiLista()
     */
    void limparPilha() {
        this->destroiLista();
    }

    /** Método PilhaVazia.
     * Este método tem a função de verificar se a Pilha está ou não vazia.
     * @see ListaEnc<T>::listaVazia()
     * @return um boolean que, se true, indica que a pilha encadeada está vazia.
     */
    bool PilhaVazia() {
        return this->listaVazia();
    }
};

#endif

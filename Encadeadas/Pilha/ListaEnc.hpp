/**
* File: ListaEnc.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 13 de Setembro de 2014, 21:30.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
/** Classe ListaEnc.
* A classe ListaEnc implementa a estrutura de dados lista encadeada, uma lista formada por
* uma "head", que é um ponteiro para um objeto do tipo Elemento; e um "size", que indica o tamanho
* dessa lista encadeada.
*/
#include <cstdio>
#include "Elemento.hpp"
#include "ExcecaoErroPosicao.hpp"
#include "ExcecaoListaCheia.hpp"
#include "ExcecaoListaVazia.hpp"
template<typename T>
class ListaEnc {
 private:
    Elemento<T>* head;
    int size;
/** Verifica se a posição dada é inválida.
* Este método recebe uma posição e verifica se ela está dentro da "range" possível para essa Lista.
* @param pos A posição que precisa ser acessada.
* @exception ExcecaoErroPosicao Exceção que indica que a posição inserida é inválida (não está na range da Lista).
*/
    void verificaPosicaoInvalida(int pos) {
        if (pos > size || pos < 0) {
            throw ExcecaoErroPosicao;
        }
    }
/** Verifica se é possível alocar mais objetos na memória.
* Este método tenta criar um novo objeto na memória e verifica se o seu valor é NULL.
* Caso seja, significa que a memória está cheia e que não há mais espaço para alocação de novos elementos / objetos.
* @exception ExcecaoListaCheia Exceção que indica que um novo dado não pode ser adicionado, pois não há mais espaço em memória.
*/
    bool verificaMemoriaCheia() {
        Elemento<T> *novo = new Elemento<T>(0, NULL);
        if (novo == NULL) {
            throw ExcecaoListaCheia;
        }
        delete novo;
        return true;
    }

 public:
/** Construtor padrão da ListaEnc.
* O construtor padrão da ListaEnc constroi uma lista encadeada vazia e "head" apontando para NULL.
*/
    ListaEnc() {
        size = 0;
        head = NULL;
    }
/** Destrutor padrão da ListaEnc.
* O destrutor padrão da ListaEnc destrói a lista encadeada atribuindo à "size" o valor 0 e deletando o ponteiro "head".
*/
    ~ListaEnc() {
       destroiLista();
    }
// Início
/** Adiciona um novo elemento no começo da Lista Encadeada.
* Este método recebe um dado do tipo T e adiciona este elemento no começo da lista.
* @param dado O dado que será inserido dentro da lista.
* @exception ExcecaoListaCheia Exceção que indica que um novo dado não pode ser adicionado, pois não há mais espaço em memória.
*/
    void adicionaNoInicio(const T& dado) {
        verificaMemoriaCheia();
        Elemento<T> *novo = new Elemento<T>(dado, head);
        head = novo;
        size++;
    }
/** Retira um elemento no começo da Lista Encadeada.
* Este método retira o primeiro elemento da Lista Encadeada, retornando o objeto retirado.
* @see listaVazia()
* @return O elemento que estava no começo da lista ou NULL caso a lista esteja vazia.
*/
    T retiraDoInicio() {
        if (!listaVazia()) {
            Elemento<T> *saiu = head;
            T volta = saiu->getInfo();
            head = saiu->getProximo();
            size--;
            delete saiu;
            return volta;
        }
        throw ExcecaoListaVazia;
    }
/** Elimina um elemento no começo da Lista Encadeada.
* Este método elimina o primeiro elemento da Lista Encadeada, ou seja, destrói o objeto sem retornar qualquer valor.
* Chama o método "retiraDoInicio()" e caso este método retorne um objeto T, apaga esse objeto da memória.
* @see retiraDoInicio()
* @exception ExcecaoListaVazia Exceção que indica que o dado não pode ser eliminado pois a lista está vazia.
*/
    void eliminaDoInicio() {
        T elemento = retiraDoInicio();
        delete elemento->getInfo();
        delete elemento;
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
        verificaPosicaoInvalida(pos);
        if (pos == 0) {
            adicionaNoInicio(dado);
            return;
        }
            verificaMemoriaCheia();
            Elemento<T> *anterior = head;
            for (int i = 0; i < pos - 1; i++) {
                anterior = anterior->getProximo();
            }
            Elemento<T> *novo = new Elemento<T>(dado, anterior->getProximo());
            anterior->setProximo(novo);
            size++;
    }
/** Verifica a posição de um dado dentro da Lista Encadeada.
* Este método recebe um dado que será analisado para verificar se este dado está dentro da Lista.
* @param dado O dado que será verificado a existência dentro da lista.
* @exception ExcecaoListaVazia Exceção que indica que a lista está vazia, ou seja, não tem como esse dado existir dentro da Lista Encadeada.
* @exception ExcecaoErroPosicao Exceção que indica que o dado do tipo T fornecido não está presente na lista.
* @return um inteiro que indica a posição em que o dado se encontrava.
*/
    int posicao(const T& dado) const {
        if (listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            Elemento<T> *atual = head;
            for (int i = 0; i < size; i++) {
               if (igual(atual->getInfo(), dado)) {
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
* @exception ExcecaoListaVazia Exceção que indica que a lista está vazia, ou seja, não tem como esse dado existir dentro da Lista Encadeada.
* @exception ExcecaoErroPosicao Exceção que indica que o dado do tipo T fornecido não está presente na lista.
* @return um ponteiro para T que indica a posição de memória em que o dado se encontrava.
*/
    T* posicaoMem(const T& dado) const {
        if (listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            Elemento<T> *atual = head;
            for (int i = 0; i < size; i++) {
                if (igual(atual->getInfo(), dado)) {
                    return &atual->getInfo();
                }
                atual = atual->getProximo();
            }
        }
        throw ExcecaoErroPosicao;
    }
/** Verifica se determinado dado existe dentro da Lista Encadeada.
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
* Este método recebe um inteiro que indica a posição de um dado que se deseja retirar da Lista Encadeada.
* @param pos A posição do dado que se deseja retirar.
* @see retiraDoInicio()
* @see retornaAnterior(int pos)
* @return um objeto T que foi retirado da posição especificada. Retorna NULL se não conseguiu pegar um dado dessa posição.
*/
    T retiraDaPosicao(int pos) {
        T volta;
        verificaPosicaoInvalida(pos);
        if (pos == 0) {
            retiraDoInicio();
        } else {
            Elemento<T> *anterior = head;
            for (int i = 0; i < pos - 2; i++) {
                anterior = anterior->getProximo();
            }
            Elemento<T> *eliminar = anterior->getProximo();
            volta = eliminar->getInfo();
            anterior->setProximo(eliminar->getProximo());
            delete eliminar;
            size--;
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
        adicionaNaPosicao(dado, size);
    }
/** Retira o último elemento da Lista.
* Este método retira o último elemento da Lista Encadeada.
* @see retiraDaPosicao(int pos)
* @return o dado do tipo T que foi retirado do final da Lista.
*/
    T retira() {
        return retiraDaPosicao(size);
    }
// Específico
/** Retira um objeto específico da Lista Encadeada.
* Este método retira o primeiro objeto da Lista Encadeada que tem o mesmo valor do dado fornecido.
* @see retiraDaPosicao(int pos)
* @see posicao(int pos)
* @return o objeto do tipo T que foi retirado da Lista. Retorna NULL caso esse objeto não exista.
*/
    T retiraEspecifico(const T& dado) {
        int pos = posicao(dado);
        return retiraDaPosicao(pos + 1);
    }
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
        if (listaVazia()) {
            adicionaNoInicio(data);
        } else {
            atual = head;
            posicao = 1;
            while (atual->getProximo() != NULL &&
                  maior(data, atual->getInfo())) {
                atual = atual->getProximo();
                posicao++;
            }
            if (maior(data, atual->getInfo())) {
                adicionaNaPosicao(data, posicao + 1);
            } else {
                adicionaNaPosicao(data, posicao);
            }
        }
    }
// Diversos
/** Método que verifica se a Lista está vazia.
* Verifica se o "size" da Lista Encadeada é zero, se for, retorna true.
* @return Retorna um boolean que mostra se a lista encadeada está vazia ou não.
*/
    bool listaVazia() const {
        return size == 0;
    }
/** Verifica se um dado1 do Tipo T é igual a um dado2 do Tipo T.
* @param dado1 Dado a ser comparado a igualdade.
* @param dado2 Dado a ser comparado a igualdade.
* @return um boolean que indica se os dados são iguais ou não.
*/
    bool igual(T dado1, T dado2) const {
        return dado1 == dado2;
    }
/** Verifica se o dado1 do lado esquerdo do operador é maior do que o dado do lado direito do operador.
* @param dado1 Dado a ser comparado que ficará à esquerda do operador de comparação.
* @param dado2 Dado a ser comparado que ficará à direita do operador de comparação.
* @return um boolean que mostra se um dado é maior que outro.
*/
    bool maior(T dado1, T dado2) const {
        return dado1 > dado2;
    }
/** Verifica se o dado1 do lado esquerdo do operador é menor do que o dado do lado direito do operador.
* @param dado1 Dado a ser comparado que ficará à esquerda do operador de comparação.
* @param dado2 Dado a ser comparado que ficará à direita do operador de comparação.
* @return um boolean verificando se um dado é menor que o outro.
*/
    bool menor(T dado1, T dado2) const {
        return dado1 < dado2;
    }
/** Método responsável por destruir a Lista Encadeada.
* Destrói a lista encadeada e desaloca todo o espaço de memória por ela ocupado.
*/
    void destroiLista() {
        Elemento<T> *atual;
        if (!listaVazia()) {
            while(head != NULL) {
                atual = head;
                head = atual->getProximo();
                delete atual;
            }
        } else {
            delete head;
        }
        size = 0;
    }
    /** Retorna um dado de determinada posição sem removê-lo da lista encadeada.
    * @param posicao Dado a ser comparado que ficará à esquerda do operador de comparação.
    * @return Retorna o dado da posição informada - se ele existir, caso contrário retorna uma exceção.
    */
    T coletaDado(int posicao) {
        verificaPosicaoInvalida(posicao);
        if (listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            Elemento<T> *atual = head;
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

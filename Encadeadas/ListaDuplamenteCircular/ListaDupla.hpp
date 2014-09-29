/**
* File: ListaDupla.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 27 de Setembro de 2014, 21:30.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
/** Classe ListaDupla.
* A classe ListaDupla implementa a estrutura de dados lista duplamente encadeada, uma lista formada por
* uma "head", que é um objeto do tipo ElementoDuplo (que contém um dado do tipo T e um ponteiro para o elemento anterior e para o próximo); 
* e um "size", que indica o tamanho dessa lista duplamente encadeada.
*/
#ifndef LISTADUPLA_HPP
#define LISTADUPLA_HPP
#include "ElementoDupla.hpp"
#include "ExcecaoErroPosicao.hpp"
#include "ExcecaoListaCheia.hpp"
#include "ExcecaoListaVazia.hpp"
template<typename T>
class ListaDupla {
 private:
        ElementoDuplo<T>* head;
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
            ElementoDuplo<T> *novo = new ElementoDuplo<T>(0, NULL, NULL);
            if (novo == NULL) {
                throw ExcecaoListaCheia;
            }
            delete novo;
            return true;
        }

 public:
    /** Construtor padrão da ListaDupla.
    * O construtor padrão da ListaDupla constroi uma lista duplamente encadeada vazia e "head" apontando para NULL.
    */
    ListaDupla() {
        head = NULL;
        size = 0;
    }

    /** Destrutor padrão da ListaDupla.
    * O destrutor padrão da ListaDupla destrói a lista duplamente encadeada atribuindo à "size" o valor 0 e deletando o ponteiro "head".
    * @see destroiListaDuplo();
    */
    ~ListaDupla() {
        destroiListaDuplo();
    }

    // Início
    /** Adiciona um novo elemento no começo da Lista Duplamente Encadeada.
    * Este método recebe um dado do tipo T e adiciona este elemento no começo da lista.
    * @param dado O dado que será inserido dentro da lista.
    * @see verificaMemoriaCheia();
    * @exception ExcecaoListaCheia Exceção que indica que um novo dado não pode ser adicionado, pois não há mais espaço em memória.
    */
    void adicionaNoInicioDuplo(const T& dado) {
        verificaMemoriaCheia();
        ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, head, NULL);
        head = novo;
        if (novo->getProximo() != NULL) {
            (novo->getProximo())->setAnterior(novo);
        }
        size++;
    }

    /** Retira um elemento no começo da Lista Duplamente Encadeada.
    * Este método retira o primeiro elemento da Lista Duplamente Encadeada, retornando o objeto retirado.
    * @see listaVazia()
    * @exception ExcecaoListaVazia Exceção que indica que um dado não pode ser retirado da lista, pois ela está vazia.
    * @return O elemento que estava no começo da lista caso esta não esteja vazia.
    */
    T retiraDoInicioDuplo() {
        if (listaVazia()) {
            throw ExcecaoListaVazia;
        }
        ElementoDuplo<T>* saiu;
        T volta;
        saiu = head;
        volta = saiu->getInfo();
        head = saiu->getProximo();
        if (head != NULL) {
            head->setAnterior(NULL);
        }
        size--;
        free(saiu);
        return volta;
    }

    /** Elimina um elemento no começo da Lista Duplamente Encadeada.
    * Este método elimina o primeiro elemento da Lista Duplamente Encadeada, ou seja, destrói o objeto sem retornar qualquer valor.
    * Chama o método "retiraDoInicio()" e caso este método retorne um objeto T, apaga esse objeto da memória.
    * @see retiraDoInicioDuplo()
    * @exception ExcecaoListaVazia Exceção que indica que o dado não pode ser eliminado pois a lista está vazia.
    */
    void eliminaDoInicioDuplo() {
        T elemento = retiraDoInicioDuplo();
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
    * @see verificaMemoriaCheia();
    * @see adicionaNoInicioDuplo(dado);
    */
    void adicionaNaPosicaoDuplo(const T& dado, int pos) {
        verificaMemoriaCheia();
        ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, NULL, NULL);
        ElementoDuplo<T>* anterior;
        if (pos > size || pos < 0) {
            throw ExcecaoErroPosicao;
        }
        if (pos == 0) {
            adicionaNoInicioDuplo(dado);
        } else {
            anterior = head;
            for (int i = 0; i < pos - 1; i++) {
                anterior = anterior->getProximo();
            }
            novo->setProximo(anterior->getProximo());
            if (novo->getProximo() != NULL) {
                (novo->getProximo())->setAnterior(novo);
            }
            novo->setAnterior(anterior);
            anterior->setProximo(novo);
            size++;
        }
    }

    /** Verifica a posição de um dado dentro da Lista Duplamente Encadeada.
    * Este método recebe um dado que será analisado para verificar se este dado está dentro da Lista.
    * @param dado O dado que será verificado a existência dentro da lista.
    * @exception ExcecaoListaVazia Exceção que indica que a lista está vazia, ou seja, não tem como esse dado existir dentro da Lista Duplamente Encadeada.
    * @exception ExcecaoErroPosicao Exceção que indica que o dado do tipo T fornecido não está presente na lista.
    * @return um inteiro que indica a posição em que o dado se encontrava.
    */
    int posicaoDuplo(const T& dado) const {
        if (listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            ElementoDuplo<T> *atual = head;
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
    * @exception ExcecaoListaVazia Exceção que indica que a lista está vazia, ou seja, não tem como esse dado existir dentro da Lista Duplamente Encadeada.
    * @exception ExcecaoErroPosicao Exceção que indica que o dado do tipo T fornecido não está presente na lista.
    * @return um ponteiro para T que indica a posição de memória em que o dado se encontrava.
    */
    T* posicaoMemDuplo(const T& dado) const {
        if (listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            ElementoDuplo<T> *atual = head;
            for (int i = 0; i < size; i++) {
                if (igual(atual->getInfo(), dado)) {
                    return &atual->getInfo();
                }
                atual = atual->getProximo();
            }
        }
        throw ExcecaoErroPosicao;
    }

    /** Verifica se determinado dado existe dentro da Lista Duplamente Encadeada.
    * Este método recebe um dado que será analisado para verificar se este dado está dentro da Lista.
    * @param dado O dado que será verificado a existência dentro da lista.
    * @see posicaoDuplo(const T& dado)
    * @return um boolean que indica se o dado está presente (true) ou não (false) dentro da lista.
    */
    bool contemDuplo(const T& dado) {
        try {
            posicaoDuplo(dado);
            return true;
        } catch(std::exception& e) {
            return false;
        }
    }

    /** Retira um elemento de dentro da lista de acordo com a posição dada.
    * Este método recebe um inteiro que indica a posição de um dado que se deseja retirar da Lista Duplamente Encadeada.
    * @param pos A posição do dado que se deseja retirar.
    * @see retiraDoInicioDuplo()
    * @see retornaAnterior(int pos)
    * @exception ExcecaoErroPosicao Exceção que indica que a posição dada é invalida. 
    * @return um objeto T que foi retirado da posição especificada.
    */
    T retiraDaPosicaoDuplo(int pos) {
        if (pos > size || pos < 0) {
            throw ExcecaoErroPosicao;
        }
        if (pos == 0) {
            return retiraDoInicioDuplo();
        }
        ElementoDuplo<T>* eliminar;
        ElementoDuplo<T>* anterior = head;
        T volta;
        for (int i = 0; i < pos - 1; i++) {
            anterior = anterior->getProximo();
        }
        eliminar = anterior->getProximo();
        volta = eliminar->getInfo();
        anterior->setProximo(eliminar->getProximo());
        if (eliminar->getProximo() != NULL) {
            (eliminar->getProximo())->setAnterior(anterior);
        }
        size--;
        delete eliminar;
        return volta;
    }

    // Fim
    /** Adiciona um novo elemento no final da Lista.
    * Este método recebe um dado do tipo T e adiciona este elemento no final da lista, ou seja, adiciona esse dado na última posição da lista.
    * @param dado O dado que será inserido dentro da lista.
    * @see adicionaNaPosicaoDuplo(const T& dado, int pos)
    * @exception ExcecaoListaCheia Exceção que indica que um novo dado não pode ser adicionado, pois não há mais espaço em memória.
    * @exception ExcecaoErroPosicao A posição dada excedeu o tamanho dessa estrutura, ou seja, foi maior do que "size + 1".
    */
    void adicionaDuplo(const T& dado) {
        adicionaNaPosicaoDuplo(dado, size);
    }

    /** Retira o último elemento da Lista.
    * Este método retira o último elemento da Lista Duplamente Encadeada.
    * @see retiraDaPosicaoDuplo(int pos)
    * @return o dado do tipo T que foi retirado do final da Lista.
    */
    T retiraDuplo() {
        return retiraDaPosicaoDuplo(size - 1);
    }

    // Específico
    /** Retira um objeto específico da Lista Duplamente Encadeada.
    * Este método retira o primeiro objeto da Lista Duplamente Encadeada que tem o mesmo valor do dado fornecido.
    * @see retiraDaPosicaoDuplo(int pos)
    * @see posicaoDuplo(int pos)
    * @return o objeto do tipo T que foi retirado da Lista.
    */
    T retiraEspecificoDuplo(const T& dado) {
        int posicao = posicaoDuplo(dado);
        return retiraDaPosicaoDuplo(posicao);
    }

    /** Retorna um dado de determinada posição sem removê-lo da lista duplamente encadeada.
    * @see verificaPosicaoInvalida(pos)
    * @see listaVazia()
    * @return Retorna o dado da posição informada - se ele existir, caso contrário retorna uma exceção.
    */
    T mostra(int pos) {
        verificaPosicaoInvalida(pos);
        if (listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            ElementoDuplo<T> *atual = head;
            if (pos == 0) {
                return atual->getInfo();
            }
            for (int i = 0; i < pos; i++) {
                atual = atual->getProximo();
            }
            return atual->getInfo();
        }
    }

    /** Adiciona um novo elemento ordenado de forma ascendente.
    * Este método recebe um dado do tipo T e adiciona este elemento na posição "pos".
    * @param dado O dado que será inserido dentro da lista.
    * @param pos A posição em que o dado será adicionado.
    * @exception ExcecaoListaCheia Exceção que indica que um novo dado não pode ser adicionado, pois não há mais espaço em memória.
    * @exception ExcecaoErroPosicao A posição dada excedeu o tamanho dessa estrutura, ou seja, foi maior do que "size + 1".
    * @see verificaMemoriaCheia();
    * @see adicionaNoInicioDuplo(data);
    * @see adicionaNaPosicaoDuplo(data, posicao);
    */
    void adicionaEmOrdem(const T& data) {
        verificaMemoriaCheia();
        ElementoDuplo<T>* atual;
        int posicao;
        if (listaVazia()) {
            adicionaNoInicioDuplo(data);
        } else {
            atual = head;
            posicao = 0;
            while (atual->getProximo() != NULL &&
            maior(data, atual->getInfo())) {
                atual = atual->getProximo();
                posicao++;
            }
            if (maior(data, atual->getInfo())) {
                adicionaNaPosicaoDuplo(data, posicao + 1);
            } else {
                adicionaNaPosicaoDuplo(data, posicao);
            }
        }
    }

    /** Método ver último.
    * É um método "getter" para o atributo "size" dessa classe.
    * @return O tamanho da estrutura de dados.
    */
    int verUltimo() {
        return size;
    }

    // Diversos
    /** Método que verifica se a Lista está vazia.
    * Verifica se o "size" da Lista Duplamente Encadeada é zero, se for, retorna true.
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

    /** Método responsável por destruir a Lista Duplamente Encadeada.
    * Destrói a lista duplamente encadeada e desaloca todo o espaço de memória por ela ocupado.
    * @see listaVazia();
    */
    void destroiListaDuplo(){
       ElementoDuplo<T> *atual;
        if (!listaVazia()) {
            while (head != NULL) {
                atual = head;
                head = atual->getProximo();
                delete atual;
            }
        } else {
            delete head;
        }
        size = 0;
    }
};

#endif

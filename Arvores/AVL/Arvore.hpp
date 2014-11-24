/**
* File: Arvore.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 08 de Novembro de 2014.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
/** Classe NoBinario.
* A classe "nó binário" implementa a estrutura de dados "árvore binária de busca", também conhecida como BST.
*  Pelas próprias características das árvores binárias, um nodo pode ter uma subárvore, por conseguinte
*  precisamos apenas de uma classe nodo para formar uma árvore, uma vez que esta nada mais é do que 
*  um conjunto de nodos relacionados. 
*/
#ifndef NOBINARIO_H_
#define NOBINARIO_H_
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <iostream>

template<typename T>
class NoBinario {
 protected:
    T* dado;
    NoBinario<T>* esquerda;
    NoBinario<T>* direita;

    /** Método balanco_insere(NoBinario<T>* arv).
    * Método auxiliar para fazer a inserção balanceada, que será utilizada na árvore AVL. 
    * Na classe nó binário esse método não tem nenhuma utilidade prática, mas para fins
    * de facilidade na herança de métodos foi colocado aqui como virtual.
    */
    virtual NoBinario<T>* balanco_insere(NoBinario<T>* arv) { return arv; }

    /** Método balanco_remove(NoBinario<T>* arv).
    * Método auxiliar para fazer a remoção balanceada, que será utilizada na árvore AVL. 
    * Na classe nó binário esse método não tem nenhuma utilidade prática, mas para fins
    * de facilidade na herança de métodos foi colocado aqui como virtual.
    */
    virtual NoBinario<T>* balanco_remove(NoBinario<T>* arv) { return arv; }

    virtual void atualiza(NoBinario<T>* arv) {}

    /* Armazenará o resultado do percorrimento em "preOrdem", "emOrdem" ou "posOrdem" da árvore binária. */
    std::vector<NoBinario<T>* > elementos;

 public:

    /** Construtor do nó binário.
    * O construtor da nó binário constroi um nodo que contêm um dado
    * e faz com que as subárvores da direita e esquerda apontem para NULL.
    *
    * @param dado O dado T que esse nodo conterá.
    */
    NoBinario<T>(const T& dado):
                dado(new T(dado)), esquerda(NULL), direita(NULL) {}

    /** Destrutor padrão da nó binário.
    * O destrutor padrão da nó binário limpa o vector "elementos", que aloca NoBinario<T> quando
    * a lista é percorida em preOrdem, posOrdem ou emOrdem. 
    */
    virtual ~NoBinario<T>() {
        elementos.clear();
    }

    /** Método getDado(). 
    * Retorna o dado armazenado neste nodo.
    * @return Retorna o dado T armazenado neste nodo.
    */
    T* getDado() {
        return this->dado;
    }

    /** Método getElementos(). 
    * Retorna um vetor de NoBinario<T> que contém todos os nós binários dessa árvore (incluindo as 
    * subárvores da esquerda e à direita e seus descendentes). Esses elementos estão em ordem de acordo
    * com o método de percorrimento escolhido (preOrdem, emOrdem, posOrdem).
    * @return Vetor de NoBinario<T> na posição do método de percorrimento escolhio (preOrdem, emOrdem, posOrdem).   
    */
    std::vector<NoBinario<T>*> getElementos() {
        return elementos;
    }

    /** Método busca().
    * Busca por um dado T no nodo binário passado como argumento. Caso o 
    * dado não esteja no próprio nodo binário passado, começa a buscar pelos descendentes
    * do nodo enviado como argumento. Caso não consiga encontrar nenhum nodo que contenha esse dado,
    * retorna -1.  
    * @param dado O dado que será buscado dentro da árvore.
    * @param ptr A raiz da árvore em que o dado será buscado.
    * @see getDado();
    * @return O dado T que foi procurado. 
    */
    T* busca(const T& dado, NoBinario<T>* ptr) {
        while (ptr != NULL && *(ptr->dado) != dado) {
            if (*(ptr->getDado()) < dado) {
                ptr = ptr->getDireita();
            } 
           else {
                 ptr = ptr->getEsquerda();
            }
        }
        if (ptr == NULL) {
            throw -1; // Throw para dizer que o dado não está presente
        }
        return ptr->getDado();
    }

    /** Método inserir(T& dado, NoBinario<T>* raiz).
    * Insere um novo elemento na árvore binária que foi passada como argumento.
    * Este método recebe um dado do tipo T e insere no lugar apropriado na raiz da árvore que foi 
    * passada como argumento. 
    * @param dado O dado que será inserido na árvore binária.
    * @param raiz A raiz da árvore em que o dado será inserido.
    * @see balanco_insere();
    * @return Retorna a própria raiz que foi passada como argumento. 
    */
    NoBinario<T>* inserir(const T& _dado, NoBinario<T>* raiz) {
        NoBinario<T>* novo;
        NoBinario<T>* novaRaiz;
        if (_dado < *(raiz->dado)) {
            if (raiz->esquerda == NULL) {
                novo = novoNo(_dado);
                raiz->esquerda = novo;
                novaRaiz = balanco_insere(raiz);
                raiz = novaRaiz;
            } else {
                raiz->esquerda = inserir(_dado, raiz->esquerda);
                novaRaiz = balanco_insere(raiz);
                raiz = novaRaiz;
            }
            atualiza(raiz);
        }
        if (_dado > *raiz->dado) {
            if (raiz->direita == NULL) {
                novo = novoNo(_dado);
                raiz->direita = novo;
                novaRaiz = balanco_insere(raiz);
                raiz = novaRaiz;
            } else {
                raiz->direita = inserir(_dado, raiz->direita);
                novaRaiz = balanco_insere(raiz);
                raiz = novaRaiz;
            }
            atualiza(raiz);

        }
        atualiza(raiz);
        return raiz;
    }

    /** Método remover(NoBinario<T>* raiz, T& dado).
    * Remove um determinado elemento da árvore binária.
    * Este método recebe um dado do tipo T e remove esse dado caso o mesmo exista
    * na árvore binária ou em suas respectivas subárvores.
    * @param raiz A raiz da árvore em que o dado será removido.
    * @param dado O dado que será removido na árvore binária.
    * @see balanco_remove();
    * @return Retorna NULL. 
    */
    NoBinario<T>* remover(NoBinario<T>* raiz, const T& _dado) {
        NoBinario<T>* filho = new NoBinario<T>(0);
        NoBinario<T>* temp = new NoBinario<T>(0);
        if (raiz == NULL) {
            return raiz;
        }
        if (_dado < *raiz->dado) {  // Vai para a esquerda
            raiz->esquerda = remover(raiz->esquerda, _dado);
            raiz = balanco_remove(raiz);
            atualiza(raiz);
            return raiz;
        }
        if (_dado > *raiz->dado) {
            raiz->direita = remover(raiz->direita, _dado);
            raiz = balanco_remove(raiz);
            atualiza(raiz);
            return raiz;
        }
        if (raiz->direita != NULL && raiz->esquerda != NULL) {
            temp = minimo(raiz->direita); 
            raiz->dado = temp->dado;
            raiz->direita = remover(raiz->direita, *raiz->dado);
            raiz = balanco_remove(raiz);
            atualiza(raiz);
            return raiz;
        }
        temp = raiz;
        if (raiz->direita != NULL) {  // filho direita
            filho = raiz->direita;
            raiz = balanco_remove(raiz);
            atualiza(raiz);
            return filho;
        }
        if (raiz->esquerda != NULL) {
            filho = raiz->esquerda;
            raiz = balanco_remove(raiz);            
            atualiza(raiz);
            return filho;
        }
        delete raiz;  //  Folha.
        return NULL;
    }

    /** Método minimo(NoBinario<T>* raiz).
    * Retorna o menor nó binário desta árvore.
    * Este método recebe a raiz de uma árvore binária e procura recursivamente pelo menor
    * nodo da árvore. 
    * @param raiz A raiz da árvore em que o menor nodo será procurado.
    * @return Retorna o menor nodo da árvore binária. 
    */
    NoBinario<T>* minimo(NoBinario<T>* raiz) {
        NoBinario<T>* root;
        if (raiz->esquerda != NULL) {
            root = minimo(raiz->esquerda);
        } else {
            root = raiz;
        }
        return root;
    }

    /** Método preOrdem(NoBinario<T>* raiz).
    * Percorre toda a árvore em preOrdem e adiciona os nodos binários ao vector "elementos".
    * @param raiz A raiz da árvore em que o percorrimento será realizado.
    */
    void preOrdem(NoBinario<T>* raiz) {
        if (raiz != NULL) {
                elementos.push_back(raiz);
                preOrdem(raiz->esquerda);
                preOrdem(raiz->direita);
            }
    }

    /** Método emOrdem(NoBinario<T>* raiz).
    * Percorre toda a árvore em emOrdem e adiciona os nodos binários ao vector "elementos".
    * @param raiz A raiz da árvore em que o percorrimento será realizado.
    */
    void emOrdem(NoBinario<T>* raiz) {
        if (raiz != NULL) {
            emOrdem(raiz->esquerda);
            elementos.push_back(raiz);
            emOrdem(raiz->direita);
       }
    }

    /** Método posOrdem(NoBinario<T>* raiz).
    * Percorre toda a árvore em posOrdem e adiciona os nodos binários ao vector "elementos".
    * @param raiz A raiz da árvore em que o percorrimento será realizado.
    */
    void posOrdem(NoBinario<T>* raiz) {
        if (raiz != NULL) {
            posOrdem(raiz->esquerda);
            posOrdem(raiz->direita);
            elementos.push_back(raiz);
       }
    }

    /** Método getEsquerda().
    * Método que retorna o filho à esquerda do nó binário atual.
    * @return Retorna o NoBinario<T> que é o filho à esquerda do nó binário atual.
    */
    NoBinario<T>* getEsquerda() {
        return esquerda;
    }

    /** Método setEsquerda(NoBinario<T>* novo).
    * Substitui o antigo filho à esquerda do nó binário atual por outro que foi recebido como argumento.
    * @param novo O novo filho à esquerda do nó binário atual.
    */
    void setEsquerda(NoBinario<T>* novo) {
        this->esquerda = novo;
    }

    /** Método getDireita().
    * Método que retorna o filho à direita do nó binário atual.
    * @return Retorna o NoBinario<T> que é o filho à direita do nó binário atual.
    */
    NoBinario<T>* getDireita() {
        return direita;
    }

    /** Método setDireita(NoBinario<T>* novo).
    * Substitui o antigo filho à direita do nó binário atual por outro que foi recebido como argumento.
    * @param novo O novo filho à direita do nó binário atual.
    */
    void setDireita(NoBinario<T>* novo) {
        direita = novo;
    }
    /**Método novoNo
    * Este método retorna um novo Nó que será adicionando na Árvore Binária.
    */
    virtual NoBinario<T>* novoNo(const T& dado) {
        return new NoBinario<T>(dado);
    }
};

#endif /* NOBINARIO_HPP_ */

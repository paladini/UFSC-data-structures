#include <cstdio>
#include "Elemento.hpp"
#include "ListaEnc.hpp"
#include "ExcecaoErroPosicao.hpp"
#include "ExcecaoListaCheia.hpp"
#include "ExcecaoListaVazia.hpp"
template<typename T>
class ListaCirc: private ListaEnc<T> {
 private:
    Elemento<T>* sentinel;

 public:
    ListaCirc(): ListaEnc<T>() {
        sentinel = new Elemento<T>(NULL, NULL);
        // sentinel->setProximo(sentinel);
        this->defineCabeca(sentinel);
        this->defineTamanho(1);
    }

    ~ListaCirc() {
        destroiLista();
    }

    void adicionaNoInicio(const T& dado) {
        // this->adicionaNoInicio(dado);
        this->verificaMemoriaCheia();
        Elemento<T> *novo = new Elemento<T>(dado, sentinel->getProximo());
        sentinel->setProximo(novo);
        this->defineTamanho(this->retornaTamanho() + 1);
    }

    T retiraDoInicio() {
        if (!listaVazia()) {
            Elemento<T> *saiu = sentinel->getProximo();
            T volta = saiu->getInfo();
            sentinel->setProximo(saiu->getProximo());
            this->defineTamanho(this->retornaTamanho() - 1);
            delete saiu;
            return volta;
        }
        throw ExcecaoListaVazia;
    }
    
    void eliminaDoInicio() {
        this->eliminaDoInicio();
    }
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
    int posicao(const T& dado) const {
        if (listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            Elemento<T> *atual = sentinel->getProximo();
            for (int i = 0; i < this->retornaTamanho(); i++) {
               if (igual(atual->getInfo(), dado)) {
                    return i;
                }
                atual = atual->getProximo();
            }
            throw ExcecaoErroPosicao;
        }
    }
    T* posicaoMem(const T& dado) const {
        if (listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            Elemento<T> *atual = sentinel->getProximo();
            for (int i = 0; i < this->retorneTamanho(); i++) {
                if (igual(atual->getInfo(), dado)) {
                    return &atual->getInfo();
                }
                atual = atual->getProximo();
            }
        }
        throw ExcecaoErroPosicao;
    }
    bool contem(const T& dado) {
        return this->contem(dado);
    }
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
    void adiciona(const T& dado) {
        adicionaNaPosicao(dado, this->retornaTamanho());

    }
    T retira() {
        return this->retira();
    }
    T retiraEspecifico(const T& dado) {
        return this->retiraEspecifico(dado);
    }
    T mostra(int pos) {
        verificaPosicaoInvalida(posicao);
        if (listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            Elemento<T> *atual = sentinel->getProximo();
            if (pos == 0) {
                return atual->getInfo();
            }
            for (int i = 0; i < pos; i++) {
                atual = atual->getProximo();
            }
            return atual->getInfo();
        }
    }
    void adicionaEmOrdem(const T& data) {
        if (listaVazia()) {
            adicionaNoInicio(data);
        } else {
            Elemento<T> *atual = sentinel->getProximo();
            int posicao = 0;
            for (int i = 0; i < this->retornaTamanho(); i++) {
                if (maior(data, atual->getInfo())) {
                    break;
                } else {
                    posicao++;
                }
            }
            if (maior(data, atual->getInfo())) {
                adicionaNaPosicao(data, posicao + 1);
            } else {
                adicionaNaPosicao(data, posicao);
            }
        }
    }
    int verUltimo() {
        return this->retornaTamanho();
    }
    bool listaVazia() const {
        return this->retornaTamanho() == 1;
    }
    bool igual(T dado1, T dado2) const {
        return dado1 == dado2;
    }
    bool maior(T dado1, T dado2) const {
        return dado1 > dado2;
    }
    bool menor(T dado1, T dado2) const {
        return dado1 < dado2;
    }
    void destroiLista() {
        Elemento<T> *atual;
        if (!listaVazia()) {
            for (int i = 0; i < this->retornaTamanho(); i++) {
                atual = sentinel->getProximo();
                sentinel->setProximo(atual->getProximo());
                delete atual;
            }
            delete sentinel->getProximo();
        }
        this->defineTamanho(1);
    }
};

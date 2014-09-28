#include "ElementoDupla.hpp"
#include "ExcecaoErroPosicao.hpp"
#include "ExcecaoListaCheia.hpp"
#include "ExcecaoListaVazia.hpp"
template<typename T>
class ListaDuplaCirc {
 private:
    ElementoDuplo<T>* head;
    ElementoDuplo<T>* sentinel;
    int size;

    void verificaPosicaoInvalida(int pos) {
        if (pos > size || pos < 0) {
            throw ExcecaoErroPosicao;
        }
    }
    bool verificaMemoriaCheia() {
        ElementoDuplo<T> *novo = new ElementoDuplo<T>(0, NULL, NULL);
        if (novo == NULL) {
            throw ExcecaoListaCheia;
        }
        delete novo;
        return true;
    }

 public:
    ListaDuplaCirc() {
        head = sentinel;
        sentinel = new ElementoDuplo<T>(NULL, NULL, NULL);
        size = 0;
    }
    ~ListaDuplaCirc() {
        destroiListaDuplo();
    }
    void adicionaNoInicioDuplo(const T& dado) {
        verificaMemoriaCheia();
        ElementoDuplo<T> *novo = new
             ElementoDuplo<T>(dado, sentinel->getProximo(), sentinel);
        if (listaVazia()) {
            novo->setProximo(sentinel);
        }
        sentinel->setProximo(novo);
        size++;
    }
    T retiraDoInicioDuplo() {
        if (!listaVazia()) {
            ElementoDuplo<T> *saiu = sentinel->getProximo();
            T volta = saiu->getInfo();
            sentinel->setProximo(saiu->getProximo());
            (saiu->getProximo())->setAnterior(sentinel);
            size--;
            delete saiu;
            return volta;
        }
        throw ExcecaoListaVazia;
    }
    void eliminaDoInicioDuplo()  {
        T elemento = retiraDoInicioDuplo();
        delete elemento->getInfo();
        delete elemento;
    }
    void adicionaNaPosicaoDuplo(const T& dado, int pos) {
        verificaPosicaoInvalida(pos);
        if (pos == 0) {
            adicionaNoInicioDuplo(dado);
            return;
        }
        verificaMemoriaCheia();
        ElementoDuplo<T> *novo = new ElementoDuplo<T>(dado, NULL, NULL);
        ElementoDuplo<T> *anterior = sentinel->getProximo();
        for (int i = 0; i < pos - 1; i++) {
            anterior = anterior->getProximo();
        }
        novo->setProximo(anterior->getProximo());
        novo->setAnterior(anterior);
        anterior->setProximo(novo);
        if (pos == size) {
            novo->setProximo(sentinel);
            (novo->getProximo())->setAnterior(novo);
        }
        size++;
    }
    int posicaoDuplo(const T& dado) const {
        if (listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            ElementoDuplo<T> *atual = sentinel->getProximo();
            for (int i = 0; i < size; i++) {
               if (igual(atual->getInfo(), dado)) {
                    return i;
                }
                atual = atual->getProximo();
            }
            throw ExcecaoErroPosicao;
        }
    }
    T* posicaoMemDuplo(const T& dado) const {
        if (listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            ElementoDuplo<T> *atual = sentinel->getProximo();
            for (int i = 0; i < size; i++) {
                if (igual(atual->getInfo(), dado)) {
                    return &atual->getInfo();
                }
                atual = atual->getProximo();
            }
        }
        throw ExcecaoErroPosicao;
    }
    bool contemDuplo(const T& dado) {
        try {
            posicaoDuplo(dado);
            return true;
        } catch(std::exception& e) {
            return false;
        }
    }
    T retiraDaPosicaoDuplo(int pos) {
        T volta;
        verificaPosicaoInvalida(pos);
        if (pos == 0) {
            retiraDoInicioDuplo();
        } else {
            ElementoDuplo<T> *anterior = sentinel->getProximo();
            for (int i = 0; i < pos - 2; i++) {
                anterior = anterior->getProximo();
            }
            ElementoDuplo<T> *eliminar = anterior->getProximo();
            volta = eliminar->getInfo();
            anterior->setProximo(eliminar->getProximo());
            (eliminar->getProximo())->setAnterior(anterior);
            delete eliminar;
            size--;
        }
        return volta;
    }
    void adicionaDuplo(const T& dado) {
        adicionaNaPosicaoDuplo(dado, size);
    }
    T retiraDuplo() {
        return retiraDaPosicaoDuplo(size);
    }
    T retiraEspecificoDuplo(const T& dado) {
        int pos = posicaoDuplo(dado);
        return retiraDaPosicaoDuplo(pos + 1);
    }
    T mostra(int pos) {
        verificaPosicaoInvalida(pos);
        if (listaVazia()) {
            throw ExcecaoListaVazia;
        } else {
            ElementoDuplo<T> *atual = sentinel->getProximo();
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
        ElementoDuplo<T> *atual;
        int posicao;
        if (listaVazia()) {
            adicionaNoInicioDuplo(data);
        } else {
            atual = sentinel->getProximo();
            posicao = 1;
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
    int verUltimo() {
        return size - 1;
    }
    bool listaVazia() const {
        return size == 0;
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
    void destroiListaDuplo() {
        ElementoDuplo<T> *atual;
        if (!listaVazia()) {
            for (int i = 0; i < size; i++) {
                atual = sentinel->getProximo();
                sentinel->setProximo(atual->getProximo());
                delete atual;
            }
        }
        size = 0;
    }
};

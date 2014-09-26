/** Copyright[2014]<Emmanuel Podestá Junior>
*/
#include "ElementoDupla.hpp"
#include "ExcecaoErroPosicao.hpp"
#include "ExcecaoListaCheia.hpp"
#include "ExcecaoListaVazia.hpp"
template<typename T>
class ListaDupla {
 private:
        ElementoDuplo<T>* head;
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
    ListaDupla() {
        head = NULL;
        size = 0;
    }
    ~ListaDupla() {
        destroiListaDuplo();
    }
    void adicionaNoInicioDuplo(const T& dado) {
        verificaMemoriaCheia();
        ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, head, NULL);
        head = novo;
        if (novo->getProximo() != NULL) {
            (novo->getProximo())->setAnterior(novo);
        }
        size++;
    }
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
    void eliminaDoInicioDuplo() {
        T elemento = retiraDoInicioDuplo();
        delete elemento->getInfo();
        delete elemento;
    }
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
    bool contemDuplo(const T& dado) {
        try {
            posicaoDuplo(dado);
            return true;
        } catch(std::exception& e) {
            return false;
        }
    }
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
    void adicionaDuplo(const T& dado) {
        adicionaNaPosicaoDuplo(dado, size);
    }
    T retiraDuplo() {
        return retiraDaPosicaoDuplo(size - 1);
    }
    T retiraEspecificoDuplo(const T& dado) {
        int posicao = posicaoDuplo(dado);
        return retiraDaPosicaoDuplo(posicao);
    }
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
    void adicionaEmOrdem(const T& data) {
        verificaMemoriaCheia();
        ElementoDuplo<T>* atual;
        int posicao;
        if (listaVazia()) {
            adicionaNoInicioDuplo(data);
        } else {
            atual = head;
            posicao = 0;
            while (atual->getProximo() != NULL && maior(data, atual->getInfo())) {
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
        return size;
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
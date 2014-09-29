/**
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 28 de Setembro de 2014, 01:08.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
/** Classe ListaDuplaCirc.
* Esta classe implementa a estrutura de dados Lista Duplamente Encadeada Circular,
*sendo uma lista formada por um "head", que é um ponteiro para um dado(neste caso, a Lista),
*um sentinel, que é, também, um ponteiro para um dado e um inteiro size que detém o tamanho
*da Lista.
*/
#ifndef LISTACIRCDUPLA_HPP_
#define LISTACIRCDUPLA_HPP_
#include <cstdio>
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
 /** Construtor Padrão da ListaDuplaCirc.
 * Seu construtor constroi uma lista vazia, com seu head apontando para seu sentinel e este apontando
 * para valores anteriores e posteriores nulos, com dado nulo.
 */
    ListaDuplaCirc() {
        head = sentinel;
        sentinel = new ElementoDuplo<T>(0, NULL, NULL);
        size = 0;
    }
 /** Destrutor padrão da ListaDuplaCirc.
 * Seu destrutor destroi todos os elementos da lista, porém não destroi o seu sentinel. Além disso,
 * determina size igual 0;
 *@see destroiListaDuplo().
 */
    ~ListaDuplaCirc() {
        destroiListaDuplo();
    }
 /** Adiciona um novo elemento no inicio da lista dupla circular.
 * Este método recebe um dado e o adiciona no inicio da Lista.
 *@param dado O dado que será inserido na lista.
 *@see listaVazia().
 */
    void adicionaNoInicioDuplo(const T& dado) {
        verificaMemoriaCheia();
        ElementoDuplo<T> *novo = new ElementoDuplo<T>(dado, sentinel->getProximo(), sentinel);
        if (listaVazia()) {
            novo->setProximo(sentinel);
        }
        sentinel->setProximo(novo);
        size++;
    }
 /** Retira um elemento no começo da lista dupla circular.
 * Este método é responsável por retirar um elemento do inicio da lista e retornar sua informação.
 *@see listaVazia().
 *@exception @exception ExcecaoListaVazia Exceção que indica que a lista está vazia, logo
 * não tem como retirar algo dela.
 *@return O elemento que estava no começo da lista ou NULL caso a lista esteja vazia.
 */
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
 /** Elimina o primeiro elemento da lista.
 * Este método é responsável por eliminar um elemento da lista e não retorna sua informação.
 *@see retiraDoInicioDuplo.
 */
    void eliminaDoInicioDuplo()  {
        T elemento = retiraDoInicioDuplo();
        delete elemento->getInfo();
        delete elemento;
    }
 /** Adiciona um elemento em uma dada posicao.
 * Este método recebe um dado e o adiciona em uma posição, que , também, é enviada a ele.
 *@see adicionaNoInicioDuplo.
 *@see verificaPosicaoInvalida.
 *@see verificaMemoriaCheia.
 *@param dado O dado a ser inserido na lista.
 *@param pos A posicao em que o dado vai ser inserido.
 */
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
 /** Retorna a posicao de um dado.
 * O método recebe um dado e o procura na lista, retonando a sua posição.
 *@see listaVazia.
 *@exception ExcecaoErroPosicao Indica que a posição é invalida, pois não existe na lista.
 *@return um inteiro que indica a posição em que o dado se encontrava.
 */
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
/** Verifica a posição de memória de um dado já inserido na Lista.
* Este método recebe um dado que será analisado para verificar se este dado está dentro da Lista.
* @param dado O dado que será verificado a existência dentro da lista.
* @see listaVazia()
* @see igual(const T dado1, const T dado2)
* @exception ExcecaoListaVazia Exceção que indica que a lista está vazia, ou seja, não tem como esse dado existir dentro da Lista Encadeada.
* @exception ExcecaoErroPosicao Exceção que indica que o dado do tipo T fornecido não está presente na lista.
* @return um ponteiro para T que indica a posição de memória em que o dado se encontrava.
*/
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
 /** Verifica se determinado dado existe dentro da Lista Dupla Circular.
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
* Este método recebe um inteiro que indica a posição de um dado que se deseja retirar da Lista Dupla Circular.
* @param pos A posição do dado que se deseja retirar.
* @see retiraDoInicioDuplo()
* @return O a informação do dado que foi retirado da posição especificada. Retorna NULL se não conseguiu pegar um dado dessa posição.
*/
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
* Este método retira o último elemento da Lista Dupla Circular.
* @see retiraDaPosicaoDuplo(int pos)
* @return o dado do tipo T que foi retirado do final da Lista.
*/
    T retiraDuplo() {
        return retiraDaPosicaoDuplo(size);
    }
 /** Retira um objeto específico da Lista Dupla Circular.
* Este método retira o primeiro objeto da Lista Dupla Circular que tem o mesmo valor do dado fornecido.
* @see retiraDaPosicaoDuplo(int pos)
* @see posicaoDuplo(int pos)
* @return o objeto do tipo T que foi retirado da Lista. Retorna NULL caso esse objeto não exista.
*/
    T retiraEspecificoDuplo(const T& dado) {
        int pos = posicaoDuplo(dado);
        return retiraDaPosicaoDuplo(pos + 1);
    }
 /** Método que mostra o dado presente em uma dada posição.
 * Este método recebe uma posição que é analisada e, se está posição existir na lista, irá retornar
 * a informação presente na mesma.
 *@see listaVazia.
 *@see verificaPosicaoInvalida(int pos).
 *@return Retorna a informação presente no dado na respectiva posição.
 */
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
 /** Adiciona um novo elemento ordenado de forma ascendente.
* Este método recebe um dado do tipo T e adiciona este elemento na posição "pos".
* @param dado O dado que será inserido dentro da lista.
* @param pos A posição em que o dado será adicionado.
* @exception ExcecaoListaCheia Exceção que indica que um novo dado não pode ser adicionado, pois não há mais espaço em memória.
* @exception ExcecaoErroPosicao A posição dada excedeu o tamanho dessa estrutura, ou seja, foi maior do que "size + 1".
*/
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
 /** Método que veirifica a posicao do ultimo elemento.
 * @return Retorna o tamanho da lista menos um, o que indica a posição do último elemento da lista.
 */
    int verUltimo() {
        return size - 1;
    }
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
 /** Método responsável por destruir a Lista Dupla Circular.
* Destrói a lista encadeada e desaloca todo o espaço de memória por ela ocupado.
*/
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


#endif

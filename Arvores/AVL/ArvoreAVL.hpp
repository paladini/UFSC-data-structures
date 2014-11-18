/**
* File: ArvoreAVL.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 10 de Novembro de 2014.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
/** Classe ArvoreAVL.
* A classe "árvore AVL" implementa a estrutura de dados "Árvore AVL", também conhecida como 
* Árvore Balanceada por Altura.  
*/
#ifndef ARVOREAVL_HPP_ 
#define ARVOREAVL_HPP_
#include "Arvore.hpp"
#include <algorithm>
template <typename T>
class ArvoreAVL: public NoBinario<T> {
 private:

 	/** Calcula o máximo entre dois número.s
	* Calcula e retorna o número máximo entre dois números dados.
	* @param a primeiro número a ser comparado.
	* @param o segundo número a ser comparado.
	* @return O maior número entre os dois fornecidos (o máximo).
	*/
 	int maximo(int a, const int b) {
 		if (a > b) {
 			return a;
 		}
 		if (a == b) {
 			return a;
 		}
 		return b;
 	}

 	/** Atualiza o nodo corrente.
 	* Método que verifica a altura do nodo dado (corrente) e o atualiza de acordo
 	* com os valores da altura dos seus filhos da esquerda e da direita. 
 	* @Param arv o nodo que terá sua altura atualizada.
 	*/
    void atualiza(NoBinario<T>* arv) {
    	if (arv->getEsquerda() == NULL && arv->getDireita() == 	NULL) {
    		arv->setAltura(0);
    	}
    	arv->setAltura(maximo(altura(arv->getEsquerda()), altura(arv->getDireita())) + 1);
    }

    /** Faz o rebalanceamento da árvore AVL, caso necessário.
 	* Após um novo nodo ser inserido na árvore binária (NoBinario), este método é chamado para
 	* realizar o rebalanceamento da árvore AVL. Este método sobrescreve o método definido em NoBinario. 
 	* @param arv a raiz da árvore que será rebalanceada.
 	* @see dup_roda_esq(NoBinario<T>* raiz)
 	* @see simp_roda_esq(NoBinario<T>* raiz)
 	* @see dup_roda_dir(NoBinario<T>* raiz)
 	* @see simp_roda_dir(NoBinario<T>* raiz)
 	* @see fator(NoBinario<T>* raiz)
 	* @see NoBinario::getDireita()
 	* @see NoBinario::setEsquerda()
 	* @return a raiz da árvore AVL rebalanceada já rotacionada e corrigida.
 	*/
 	NoBinario<T>* balanco_insere(NoBinario<T>* arv) {
 		NoBinario<T>* novaRaiz;
		if (fator(arv) == 2/*altura(arv->getDireita()) > altura(arv->getEsquerda())*/) {
 			if (fator(arv->getDireita()) == 1) {
 				novaRaiz = dup_roda_esq(arv);
 			} 
 			if (fator(arv->getDireita()) == -1) {
 				novaRaiz = simp_roda_esq(arv);
 			}
		}
		if (fator(arv) == -2/*altura(arv->getDireita()) < altura(arv->getEsquerda())*/) {
			if (fator(arv->getEsquerda()) == -1) {
 				novaRaiz = dup_roda_dir(arv);
			} 
			if (fator(arv->getEsquerda()) == 1) {
				novaRaiz = simp_roda_dir(arv);
			}
		}
		return arv;
 	}

 public:

    /** Construtor do ArvoreAVL.
    * O construtor da árvore AVL constroi um nodo que contêm um dado
    * e faz com que as subárvores da direita e esquerda apontem para NULL herdando de NoBinario e 
    * chamando o seu construtor para realizar essas funções.
    * @param dado O dado T que esse nodo conterá.
    */
 	ArvoreAVL(const T& dado): NoBinario<T>(dado){}

 	/** Destrutor padrão de ArvoreAVL.
    * O destrutor padrão da árvore avl não tem o que destruir antes de ser eliminado, pois
    * estende de NoBinario e este cuida do gerenciamento e deleção de atributos necessários. 
    */
 	~ArvoreAVL() {}

 	/** Insere um novo elemento na árvore AVL.
    * Método que realiza a adição de novos elementos / nodos em uma árvore semi-balanceada (AVL). Utiliza
    * o método "inserir" da classe herdada NoBinario, que vai realizar todo o conjunto de instruções 
    * necessárias para realizar a inserção do nodo e fazer os possíveis rebalanceamentos.
    * @param raiz A raiz da árvore AVL onde se pretende inserir o novo elemento / nodo.
    * @param info A informação que será adicionada dentro do novo nodo inserio na árvore.
    * @see NoBinario<T>::inserir(T& dado, NoBinario<T>* raiz)
    * @return O nó que acabou de ser adicionado.
    */
 	NoBinario<T>* insere(NoBinario<T>* raiz, const T& info)  {
 		NoBinario<T>* arv = NoBinario<T>::inserir(info, raiz);
 		return arv;
 	}

 	/** Remove um elemento da árvore AVL.
    * Método que realiza a remoção de um elemento / nodo em uma árvore semi-balanceada (AVL). Utiliza
    * o método "remover" da classe herdada NoBinario, que vai realizar todo o conjunto de instruções 
    * necessárias para realizar a remoção do nodo e fazer os possíveis rebalanceamentos.
    * @param raiz A raiz da árvore AVL onde se pretende remove o elemento / nodo.
    * @param info A informação do dado que será removido da árvore.
    * @see NoBinario<T>::remover(NoBinario<T>* raiz, T& dado)
    * @return O nó que acabou de ser removido.
    */
 	NoBinario<T>* remove(NoBinario<T>* raiz, const T& info) {
 		NoBinario<T>* arv = NoBinario<T>::remover(raiz, info);
 		return arv;
    }

    /** Método altura().
    * Método que retorna a altura da raiz da árvore AVL dada.
    * @return Retorna a altura da árvore AVL dada.
    */
 	int altura(NoBinario<T>* raiz) {
 		if (raiz == NULL) {
 			return -1;
 		}
 		return raiz->getAltura();
 	}

 	/** Retorna o "fator" de desbalanceamento da árvre.
 	* Esse método calcula o "fator de desbalanceamento" de uma árvore, ou seja, calcula
 	* a altura das subárvores do nodo raiz e retorna para que posteriormente possa ser
 	* analisado se a árvore AVL precisa ser rebalanceada.
 	* 
 	* @param raiz A raiz da árvore que será analisada.
 	* @return O "fator" de desbalanceamento da árvore ou zero, caso a raiz da mesma seja null.
 	*/
 	int fator(NoBinario<T>* raiz) {
 		if (raiz == NULL) {
 			return 0;
 		}
 		return (altura(raiz->getEsquerda()) - altura(raiz->getDireita()));
 	}

 	/** Verifica se determinada raiz tem uma árvore balanceada.
 	* [Tomar cuidado] Os dois retornos possíveis desse método são:
 	* 		Está balanceada -> retorna FALSE
 	*		Está desbalanceada -> retorna TRUE
 	*
 	* @param raiz A raiz da árvore que será analisada.
 	* @return Verdadeiro, caso a AVL NÃO ESTEJA DESBALANCEADA e FALSO CASO A AVL ESTEJA BALANCEADA.
 	*/
 	bool balanceado(NoBinario<T>* raiz) {
 		int absolute = std::abs(altura(raiz->getEsquerda()) - altura(raiz->getDireita()));
 		return absolute > 1;
 	}

 	/** Método para realizar rotação dupla à esquerda.
 	* Realiza um rebalanceamento na árvore AVL que é chamado de "rotação dupla à esquerda".
 	* @param raiz O nodo que será rebalanceado.
 	* @see NoBinario::setAltura(int i)
 	* @see Nobinario::setEsquerda(NoBinario<T>* novo)
 	* @see NoBinario::setDireita(NoBinario<T>* novo)
 	* @set NoBinario::getAltura()
 	* @see NoBinario::getDireita()
 	* @see NoBinario::getEsquerda()
 	* @see altura(NoBinario<T>* raiz
	* @see maximo(int a, int b)
	* @return O nodo já com rotação dupla à esquerda realizada (já balanceado).
 	*/
 	NoBinario<T>* dup_roda_esq(NoBinario<T>* raiz) {
 		/*Rotacione entre k1 e k2*/
 		raiz->setEsquerda(simp_roda_esq(raiz->getEsquerda()));
 		/*Rotacione entre k3 e k2*/
 		return simp_roda_dir(raiz);	
 	}

 	/** Método para realizar rotação dupla à direita.
 	* Realiza um rebalanceamento na árvore AVL que é chamado de "rotação dupla à direita".
 	* @param raiz O nodo que será rebalanceado.
 	* @see NoBinario::setAltura(int i)
 	* @see Nobinario::setEsquerda(NoBinario<T>* novo)
 	* @see NoBinario::setDireita(NoBinario<T>* novo)
 	* @set NoBinario::getAltura()
 	* @see NoBinario::getDireita()
 	* @see NoBinario::getEsquerda()
 	* @see altura(NoBinario<T>* raiz
	* @see maximo(int a, int b)
	* @return O nodo já com rotação dupla à direita realizada (já balanceado).
 	*/
 	NoBinario<T>* dup_roda_dir(NoBinario<T>* raiz) {
 		/*Rotacione entre k1 e k2*/
 		raiz->setDireita(simp_roda_dir(raiz->getDireita()));
 		/*Rotacione entre k3 e k2*/
 		return simp_roda_esq(raiz);
 	}

 	/** Método para realizar rotação simples à esquerda.
 	* Realiza um rebalanceamento na árvore AVL que é chamado de "rotação simples à esquerda".
 	* @param raiz O nodo que será rebalanceado.
 	* @see NoBinario::setAltura(int i)
 	* @see Nobinario::setEsquerda(NoBinario<T>* novo)
 	* @see NoBinario::setDireita(NoBinario<T>* novo)
 	* @set NoBinario::getAltura()
 	* @see NoBinario::getDireita()
 	* @see NoBinario::getEsquerda()
 	* @see altura(NoBinario<T>* raiz
	* @see maximo(int a, int b)
	* @return O nodo já com rotação simples à esquerda realizada (já balanceado).
 	*/
 	NoBinario<T>* simp_roda_esq(NoBinario<T>* raiz) {
 		NoBinario<T>* novaRaiz = raiz;
 		novaRaiz = raiz->getEsquerda();
 		raiz->setEsquerda(novaRaiz->getDireita());
 		novaRaiz->setDireita(raiz);
 		//atualizar alturas
 		raiz->setAltura(maximo(altura(raiz->getEsquerda()), altura(raiz->getDireita()) + 1));
 		novaRaiz->setAltura(maximo(altura(novaRaiz->getEsquerda()), raiz->getAltura()) + 1);
 		return novaRaiz;
 	}

 	/** Método para realizar rotação simples à direita.
 	* Realiza um rebalanceamento na árvore AVL que é chamado de "rotação simples à direita".
 	* @param raiz O nodo que será rebalanceado.
 	* @see NoBinario::setAltura(int i)
 	* @see Nobinario::setEsquerda(NoBinario<T>* novo)
 	* @see NoBinario::setDireita(NoBinario<T>* novo)
 	* @set NoBinario::getAltura()
 	* @see NoBinario::getDireita()
 	* @see NoBinario::getEsquerda()
 	* @see altura(NoBinario<T>* raiz
	* @see maximo(int a, int b)
	* @return O nodo já com rotação simples à direita realizada (já balanceado).
 	*/
 	NoBinario<T>* simp_roda_dir(NoBinario<T>* raiz) {
 		NoBinario<T>* novaRaiz = raiz;
 		novaRaiz = raiz->getDireita();
 		raiz->setDireita(novaRaiz->getEsquerda());
 		novaRaiz->setEsquerda(raiz);
 		//atualizar alturas
 		raiz->setAltura(maximo(altura(raiz->getDireita()), altura(raiz->getEsquerda()) + 1));
 		novaRaiz->setAltura(maximo(altura(novaRaiz->getDireita()), raiz->getAltura()) + 1);
 		return novaRaiz;
 	}
};
#endif
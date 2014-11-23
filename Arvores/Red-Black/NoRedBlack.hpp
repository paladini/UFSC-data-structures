/**
* File: NoRedBlack.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 23 de Novembro de 2014.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
/** Classe NoRedBlack.
* A classe "nó red-black" implementa a estrutura de dados "árvore red-black", também conhecida como árvore rubro-negra.
*  Pelas próprias características das árvores red-blacks, um nodo pode ter uma subárvore, por conseguinte
*  precisamos apenas de uma classe nodo para formar uma árvore, uma vez que esta nada mais é do que 
*  um conjunto de nodos relacionados. 
*/
#ifndef NOREDBLACK_HPP_
#define NOREDBLACK_HPP_
#include "Arvore.hpp"
template <typename T>
class NoRedBlack: public NoBinario<T>	 {
 private:
 	
 	/* Variável do tipo T que será armazenada nesse nodo. */
 	T* info;

 	/* Ponteiro para o filho à esquerda do nodo atual. */
 	NoRedBlack<T>* esquerda;

 	/* Ponteiro para o filho à direita do nodo atual. */
 	NoRedBlack<T>* direita;

 	/* Ponteiro para o nodo pai desse nó. */
 	NoRedBlack<T>* pai;

 	/* Atributo que diz a cor do nodo. Se for verdadeiro (1), cor é rubra, caso seja falso (0), é preta. */
 	bool cor; // 1 = rubro; 0 = negro;
 	NoRedBlack<T>* balanco_insere(NoRedBlack<T>* raiz) { }
 public:

 	/** Construtor de NoRebBlack.
    * O construtor da nó red-black constroi um nodo que contêm um dado, uma cor (rubro)
    * e faz com que as subárvores da direita, esquerda e pai apontem para NULL (NULL == 0).
    *
    * @param dado O dado T que esse nodo conterá.
    */
 	NoRedBlack<T>(const T& dado) : cor(true), pai(0), esquerda(0), direita(0), info(new T(dado)) {}

 	/** Insere um novo elemento na árvore red-black e faz os rebalanceamentos necessários.
    * Método que realiza a adição de novos elementos / nodos em uma árvore rubro-negra (RB). Utiliza
    * o método "insereArvBusca"  que vai realizar todo o conjunto de instruções 
    * necessárias para realizar a inserção do nodo. Depois faz os possíveis
    * rebalanceamentos (rotações e recoloração).
    * @param raiz A raiz da árvore red-black onde se pretende inserir o novo elemento / nodo.
    * @param info A informação que será adicionada dentro do novo nodo inserido na árvore.
    * @see NoRedBlack<T>::insereArvBusca(NoRedBlack<T>* raiz, const T& info)
    */
 	void insereRB (NoRedBlack<T>* raiz, const T& info){
 		NoRedBlack<T>* atual, pai, avo, nodo;
 		nodo = InsereArvBusca(raiz, info);
 		nodo->cor = true;
 		atual = nodo;
 		while (atual != raiz && (atual->pai)->cor == true) {
 			pai = atual->pai;
 			avo = pai->pai;
 			if (avo->esquerda == pai) {
 				PassoCE_esq(atual, pai, avo);
 			} else {
 				PassoCE_dir(atual, pai, avo);
 			}
 		}
 		raiz->cor = false;
 	}

 	/** Insere um novo elemento na árvore red-black.
    * Método que realiza a adição de novos elementos / nodos em uma árvore rubro-negra (RB).
    * @param raiz A raiz da árvore red-black onde se pretende inserir o novo elemento / nodo.
    * @param info A informação que será adicionada dentro do novo nodo inserido na árvore.
    * @return O nó que acabou de ser adicionado.
    */
 	NoRedBlack<T>* InsereArvBusca(NoRedBlack<T>* raiz, const T& info) {
 		NoRedBlack<T>* nodo;
 		if (info < *(raiz->dado)) {
            if (raiz->esquerda == NULL) {
                nodo = new NoRedBlack<T>(info);
                raiz->esquerda = nodo;
            } else {
                InsereArvBusca(raiz->esquerda, info);
            }
        }
        if (info > *raiz->dado) {
            if (raiz->direita == NULL) {
                nodo = new NoRedBlack<T>(info);
                raiz->direita = nodo;
            } else {
                InsereArvBusca(raiz->direita, info);
            }
        }
        return nodo;
    }

    /** Remove um elemento da árvore red-black.
    * Método que realiza a remoção de um elemento / nodo em uma árvore rubro-negra (RB).
    * Após realizar a remoção do nodo, faz os rebalanceamentos necessários (rotações e recolorações).
    * @param raiz A raiz da árvore RB onde se pretende remove o elemento / nodo.
    * @param info A informação do dado que será removido da árvore.
    * @return null.
    */
    NoRedBlack<T>* remover(NoRedBlack<T>* raiz, const T& dado) {
    	NoRedBlack<T>* filho = new NoRedBlack<T>*(0);
        NoRedBlack<T>* temp = new NoRedBlack<T>*(0);
        if (raiz == NULL) {
            return raiz;
        }
        if (dado < *raiz->info) {
            raiz->esquerda = remover(raiz->esquerda, dado);
            temp = (raiz->esquerda)->pai;
            passoCE_esq(raiz->esquerda, temp, temp->pai);
            return raiz;
	        }
        if (dado > *raiz->info) {
            raiz->direita = remover(raiz->direita, dado);
            temp = (raiz->direita)->pai;
            passoCE_dir(raiz->direita, temp, temp->pai);
            return raiz;
        }
        if (raiz->direita != NULL && raiz->esquerda != NULL) {
            minimo = minimo(raiz->direita); 
            substituto = passoCED(minimo, raiz);
            raiz->info = substituto->info;
            raiz->direita = remover(raiz->direita, *raiz->info);
            return raiz;
        }
        temp = raiz;
        if (raiz->direita != NULL) {
            filho = raiz->direita;
            return filho;
        }
        if (raiz->esquerda != NULL) {
            filho = raiz->esquerda;
            return filho;
        }
        delete raiz;
        return NULL;
    }

    /** Método para realizar a correção e elevação da deleção.
 	* Determina qual será o passo de correção e elevação da deleção necessário e o faz
 	* para que a árvore seja corrigida.
 	* @param raiz O nodo que será rebalanceado.
	* @return O nodo com a correção realizada.
 	*/
	NoRedBlack<T>* passoCED(NoRedBlack<T>* w, NoRedBlack<T>* raiz) {
		while(w != raiz) {
			if (w == w->pai->esquerda) {
				w = passoCED_esq(w, raiz);
			} else {
				w = passoCED_dir(w, raiz);
			}
		}
		return w;
	}

	/** Método para realizar rotação à direita.
 	* Realiza um rebalanceamento na árvore red-black que é chamado de "rotação à direita".
 	* @param raiz O nodo que será rebalanceado.
	* @return O nodo já com rotação à direita realizada (já balanceado).
 	*/
 	NoRedBlack<T>* roda_dir (NoRedBlack<T>* arv) {
 		NoRedBlack<T>* y, superior; // pai
 		bool lado = false; // 1 == esquerda; 0 == direita;

 		superior = arv->pai;
 		if (superior->esquerda == arv) {
 			lado = true; // lado = esquerda;
 		}
 		y = arv->esquerda;
 		y->pai = superior;
 		arv->esquerda = y->direita;
 		(arv->esquerda)->pai = arv;
 		y->direita = arv;
 		(y->direita)->pai = y;
 		if (lado) {
 			superior->esquerda = y;
 		} else {
 			superior->direita = y;
 		}
 		return y;

 	}

 	/** Método para realizar rotação à esquerda.
 	* Realiza um rebalanceamento na árvore red-black que é chamado de "rotação à esquerda".
 	* @param raiz O nodo que será rebalanceado.
	* @return O nodo já com rotação à esquerda realizada (já balanceado).
 	*/
 	NoRedBlack<T>* roda_esq (NoRedBlack<T>* arv) {
 		NoRedBlack<T>* y, superior; // pai
 		bool lado = false; // 1 == esquerda; 0 == direita;

 		superior = arv->pai;
 		if (superior->esquerda == arv) {
 			lado = true; // lado = esquerda;
 		}
 		y = arv->esquerda;
		y->pai = superior;
		arv->esquerda = y->direita;
		(arv->esquerda)->pai = arv;
		y->direita = arv;
		(y->direita)->pai = y;
 		if (lado) {
 			superior->esquerda = y;
 		} else {
 			superior->direita = y;
 		}
 		return y;
 	}

 	/** Método para realizar a correção e elevação à esquerda.
 	* Realiza o passo de correção e elevação à esquerda.
 	* @param raiz O nodo que será corrigido.
	* @return O nodo com a correção realizada.
 	*/
 	void passoCE_esq(NoRedBlack<T>* atual, NoRedBlack<T>* pai, NoRedBlack<T>* avo){
		NoRedBlack<T> *tio = avo->direita;
		if(tio->cor == true) {
			//caso 1
			pai->cor = false;
			avo->cor = true;
			tio->cor = false;
			atual = avo;
		} else {
			//sobe 2 níveis
			if(pai->dir == atual) {
				//caso 2
				roda_esq(pai);
				atual = atual->esquerda;
				//reseta atual

			}
			pai->cor = false;
			//caso3
			avo->cor = true;
			roda_dir(avo);
		}
	}

	/** Método para realizar a correção e elevação à direita.
 	* Realiza o passo de correção e elevação à direita.
 	* @param raiz O nodo que será corrigido.
	* @return O nodo com a correção realizada.
 	*/
	void passoCE_dir(NoRedBlack<T>* atual, NoRedBlack<T>* pai, NoRedBlack<T>* avo){
		NoRedBlack<T> *tio = avo->esquerda;
		if(tio->cor == true) {
			//caso 1
			pai->cor = false;
			avo->cor = true;
			tio->cor = false;
			atual = avo;
		} else {
			//sobe 2 níveis
			if(pai->esquerda = atual) {
				//caso 2
				roda_dir(pai);
				atual = atual->direita;
				//reseta atual

			}
			pai->cor = false;
			//caso3
			avo->cor = true;
			roda_esq(avo);
		}
	}

	/** Método para realizar a correção e elevação da deleção à esquerda.
 	* Realiza o passo de correção e elevação da deleção à esquerda.
 	* @param raiz O nodo que será corrigido.
	* @return O nodo com a correção realizada.
 	*/
	NoRedBlack<T>* passoCED_esq(NoRedBlack<T>* w, NoRedBlack<T>* raiz) {
		NoRedBlack<T>* y;
		y = w->pai->direita;
		if (y->cor == true) {
			y->cor = false;
			w->pai->cor = true;
			roda_esq(w->pai);
			y = w->pai->direita;
		}
		if (y->esquerda->cor == false && y->direita->cor == false) {
			y->cor = true;
			w = w->pai;
		} else {
			if (y->direita->cor == false) {
				y->esquerda->cor = false;
				y->cor = true;
				roda_dir(y);
				y = w->pai->direita;
			}
			y->cor = w->pai->cor;
			w->pai->cor = false;
			y->direita->cor = false;
			roda_esq(w->pai);
			w = raiz;
		}
		return w;
	}

	/** Método para realizar a correção e elevação da deleção à direita.
 	* Realiza o passo de correção e elevação da deleção à direita.
 	* @param raiz O nodo que será corrigido.
	* @return O nodo com a correção realizada.
 	*/
	NoRedBlack<T>* passoCED_dir(NoRedBlack<T>* w, NoRedBlack<T>* raiz) {
		NoRedBlack<T>* y;
		y = w->pai->esquerda;
		if (y->cor == true) {
			y->cor = false;
			w->pai->cor = true;
			roda_dir(w->pai);
			y = w->pai->esquerda;
		}
		if (y->esquerda->cor == false && y->direita->cor == false) {
			y->cor = true;
			w = w->pai;
		} else {
			if (y->esquerda->cor == false) {
				y->direita->cor = false;
				y->cor = true;
				roda_esq(y);
				y = w->pai->esquerda;
			}
			y->cor = w->pai->cor;
			w->pai->cor = false;
			y->esquerda->cor = false;
			roda_dir(w->pai);
			w = raiz;
		}
		return w;
	}

	/** Método minimo(NoRebBlack<T>* raiz).
    * Retorna o menor nó red-black desta árvore.
    * Este método recebe a raiz de uma árvore red-black e procura recursivamente pelo menor
    * nodo da árvore. 
    * @param raiz A raiz da árvore em que o menor nodo será procurado.
    * @return Retorna o menor nodo da árvore red-black. 
    */
	NoRedBlack<T>* minimo(NoRedBlack<T>* raiz) {
        NoRedBlack<T>* root;
        if (raiz->esquerda != NULL) {
            root = minimo(raiz->esquerda);
        } else {
            root = raiz;
        }
        return root;
    }
};

#endif
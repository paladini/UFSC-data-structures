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
 	T* info;
 	NoRedBlack<T>* esquerda;
 	NoRedBlack<T>* direita;
 	NoRedBlack<T>* pai;
 	bool cor; // 1 = rubro; 0 = negro;
 	NoRedBlack<T>* balanco_insere(NoRedBlack<T>* raiz) {

 	}
 public:
 	NoRedBlack<T>(const T& dado) : cor(true), pai(0), esquerda(0), direita(0), info(new T(dado)) {}

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
// NoRedBlack<T>* minimo;
//     	NoRedBlack<T>* substituto;

//     	NoRedBlack<T>* filho = new NoRedBlack<T>*(0);
//         NoRedBlack<T>* temp = new NoRedBlack<T>*(0);
//         if (raiz == NULL) {
//             return raiz;
//         }
//         if (dado < *raiz->info) {  // Vai para a esquerda
//             raiz->esquerda = remover(raiz->esquerda, dado);
//             passoCE_esq(filho, filho->pai, filho->avo);
//             return raiz;
//         }
//         if (dado > *raiz->info) {
//             raiz->direita = remover(raiz->direita, dado);
//             return raiz;
//         }
//         if (raiz->direita != NULL && raiz->esquerda != NULL) {
//             minimo = minimo(raiz->direita); 
//             substituto = passoCED(minimo, raiz);
//             raiz->info = substituto->info;
//             raiz->direita = remover(raiz->direita, *raiz->info);
//             return raiz;
//         }
//         temp = raiz;
//         if (raiz->direita != NULL) {  // filho direita
//             filho = raiz->direita;
//             return filho;
//         }
//         if (raiz->esquerda != NULL) {
//             filho = raiz->esquerda;
//             return filho;
//         }
//         delete raiz;  //  Folha.
//         return NULL;

#endif
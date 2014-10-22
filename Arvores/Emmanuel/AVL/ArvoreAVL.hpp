// identificar rotação dupla?
#ifndef ARVOREAVL_HPP_ 
#define ARVOREAVL_HPP_
#include "Arvore.hpp"
#include <algorithm>
template <typename T>
class NoBinario: public Arvore {
 private:
 	int altura;

 	NoBinario<T>* balanco_insere(NoBinario<T>* arv) {
 		NoBinario<T>* novaRaiz, novaRaizDupla;
 		if (!arv->balanceado()) {
 			if (altura(arv->esquerda) > altura(arv->direita)) {
	 			if (altura((arv->esquerda)->esquerda)) > 
	 					altura((arv->esquerda)->direita) {
	 				novaRaiz = simp_roda_esq(arv);
	 			} else {
	 				novaRaiz = dup_roda_esq(arv);
	 			}
			} else {
				if (altura((arv->direita)->direita) > 
					altura((arv->direita)->esquerda)) {
	 				novaRaiz = simp_roda_dir(arv);
				} else {
					novaRaiz = dup_roda_dir(arv)
				}
			}
		}
 		return arv;
 	}

 	NoBinario<T>* balanco_remove(NoBinario<T>* arv) {
		NoBinario<T>* novaRaiz, novaRaizDupla;
 		if (!arv->balanceado()) {
 			if (altura(arv->esquerda) > altura(arv->direita)) {
	 			if (altura((arv->esquerda)->esquerda)) > 
	 					altura((arv->esquerda)->direita) {
	 				novaRaiz = simp_roda_esq(arv);
	 			} else {
	 				novaRaiz = dup_roda_esq(arv);
	 			}
			} else {
				if (altura((arv->direita)->direita) > 
					altura((arv->direita)->esquerda)) {
	 				novaRaiz = simp_roda_dir(arv);
				} else {
					novaRaiz = dup_roda_dir(arv)
				}
			}
		}
 		return arv; 
 	}

 public:
 	NoBinario<T>* insere(NoBinario<T>* raiz, const T& info)  {
 		NoBinario<T>* arv = NoBinario<T>::inserir(info, raiz);
 		arv->altura = std::max(altura(arv->esquerda), altura(arv->direita));
 		return arv;
 	}

 	NoBinario<T>* remove(NoBinario<T>* raiz, const T& info) {
 		NoBinario<T>* arv = NoBinario<T>::remover(raiz, info);
 		arv->altura = std::max(altura(arv->esquerda), altura(arv->direita));
 		return arv;
    }

 	int altura(NoBinario<T>* raiz) {
 		if (raiz == NULL) {
 			return -1;
 		}
 		return raiz->altura;
 	}

 	bool balanceado(NoBinario<T>* raiz) {
 		double absolute = abs(altura(raiz->direita) - altura(raiz->esquerda));
 		return absolute < 2;
 	}

 	NoBinario<T>* dup_roda_esq(NoBinario<T>* raiz) {
 		/*Rotacione entre k1 e k2*/
 		raiz->setEsquerda(simp_roda_dir(raiz->esquerda));
 		/*Rotacione entre k3 e k2*/
 		return simp_roda_esq(raiz);
 	}

 	NoBinario<T>* dup_roda_dir(NoBinario<T>* raiz) {
 		/*Rotacione entre k1 e k2*/
 		raiz->setDireita(simp_roda_esq(raiz->direita));
 		/*Rotacione entre k3 e k2*/
 		return simp_roda_dir(raiz);
 	}

 	NoBinario<T>* simp_roda_esq(NoBinario<T>* raiz) {
 		NoBinario<T>* novaRaiz;
 		novaRaiz = raiz->esquerda;
 		raiz->esquerda = novaRaiz->direita;
 		novaRaiz->direita = raiz;
 		//atualizar alturas
 		raiz->altura = std::max(altura(raiz->esquerda), altura(raiz->direita)) + 1;
 		novaRaiz->altura = std::max(altura(novaRaiz->esquerda), raiz->altura) + 1;
 		return novaRaiz;
 	}

 	NoBinario<T>* simp_roda_dir(NoBinario<T>* raiz) {
 		NoBinario<T>* novaRaiz;
 		novaRaiz = raiz->direita;
 		raiz->direita = novaRaiz->esquerda;
 		novaRaiz->esquerda = raiz;
 		//atualizar alturas
 		raiz->altura = std::max(altura(raiz->direita), altura(raiz->esquerda)) + 1;
 		novaRaiz->altura = std::max(altura(novaRaiz->direita), raiz->altura)) + 1;
 		return novaRaiz;
 	}
};
#endif
#ifndef ARVOREAVL_HPP_ 
#define ARVOREAVL_HPP_
#include "Arvore.hpp"
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
template <typename T>
class ArvoreAVL: public NoBinario<T> {
 private:
	NoBinario<T>* balanco_insere_esq(NoBinario<T>* arv) {
 		NoBinario<T>* novaRaiz = arv;
 		if (rotate(arv) == 2) {
	 		if (rotate(arv->getEsquerda()) == -1) {
	 			novaRaiz = dup_roda_esq(arv->getEsquerda());
	 		} else {
				novaRaiz = simp_roda_esq(arv->getEsquerda());
			}
		}
		atualiza(arv);
		return novaRaiz;
	}

	NoBinario<T>* balanco_insere_dir(NoBinario<T>* arv) {
 		NoBinario<T>* novaRaiz = arv;
 		if (rotate(arv) == -2) {
			if (rotate(arv->getDireita()) == 1) {
					novaRaiz = dup_roda_dir(arv->getDireita());
			} else {
				novaRaiz = simp_roda_dir(arv->getDireita());
			}
		}
		atualiza(arv);
		return novaRaiz;
	}

 	void atualiza(NoBinario<T>* arv) {
 		arv->setAltura(std::max(altura(arv->getEsquerda()), altura(arv->getDireita())) + 1);
  	}

 public:
 	ArvoreAVL<T>(const T& dado): NoBinario<T>(dado){}

 	~ArvoreAVL<T>() {}

 	NoBinario<T>* insere(NoBinario<T>* raiz, const T& info)  {
 		NoBinario<T>* arv = NoBinario<T>::inserir(info, raiz);
 		return arv;
 	}

 	NoBinario<T>* remove(NoBinario<T>* raiz, const T& info) {
 		NoBinario<T>* arv = NoBinario<T>::remover(raiz, info);
 		return arv;
    }

 	int altura(NoBinario<T>* raiz) {
 		if (raiz == NULL) {
 			return -1;
 		}
 		return raiz->getAltura();
 	}

 	NoBinario<T>* dup_roda_esq(NoBinario<T>* raiz) {
 		/*Rotacione entre k1 e k2*/
 		if (raiz == NULL) {
 			return raiz;
 		}
 		raiz->setEsquerda(simp_roda_dir(raiz->getEsquerda()));
 		/*Rotacione entre k3 e k2*/
 		return simp_roda_esq(raiz);
 	}

 	NoBinario<T>* dup_roda_dir(NoBinario<T>* raiz) {
 		/*Rotacione entre k1 e k2*/
 		if (raiz == NULL) {
 			return raiz;
 		}
 		raiz->setDireita(simp_roda_esq(raiz->getDireita()));
 		/*Rotacione entre k3 e k2*/
 		return simp_roda_dir(raiz);
 	}

 // 	bool balanceado(NoBinario<T>* raiz) {
	// 	double absolute = abs(altura(raiz->direita) - altura(raiz->esquerda));
	// 	return absolute < 2;
	// }

	int rotate(NoBinario<T>* arv) {
		return (arv == NULL)? 0 : altura(arv->getEsquerda()) - altura(arv->getDireita());
	}

 	NoBinario<T>* simp_roda_esq(NoBinario<T>* raiz) {
 		
 		NoBinario<T>* novaRaiz = raiz;
 		if (raiz == NULL) {
 			return raiz;
 		}
 		novaRaiz = raiz->getDireita();
 		raiz->setDireita(novaRaiz->getEsquerda());
 		novaRaiz->setEsquerda(raiz);
 		//atualizar alturas
 		raiz->setAltura(std::max(altura(raiz->getDireita()), altura(raiz->getEsquerda())) + 1);
 		novaRaiz->setAltura(std::max(altura(novaRaiz->getDireita()), raiz->getAltura()) + 1);
 		return novaRaiz;
 	}

 	NoBinario<T>* simp_roda_dir(NoBinario<T>* raiz) {
 		NoBinario<T>* novaRaiz = raiz;
 		if (raiz == NULL) {
 			return raiz;
 		}
 		novaRaiz = raiz->getEsquerda();
 		raiz->setEsquerda(novaRaiz->getDireita());
 		novaRaiz->setDireita(raiz);
 		//atualizar alturas
 		raiz->setAltura(std::max(altura(raiz->getEsquerda()), altura(raiz->getDireita())) + 1);
 		novaRaiz->setAltura(std::max(altura(novaRaiz->getEsquerda()), raiz->getAltura()) + 1);
 		return novaRaiz;
 	}

 	
};
#endif
/*
1 - árvore AVL
2 - árvore B
3 - árvore AVL
4 - estruturas lineares
5 - árvore B
6 - estruturas lineares
7 - lista encadeada
8 - questão da prova de exemplo
9 - estruturas vetoriais
10 - deleção em árvore de busca
11 - estruturas vetoriais
12 - complexidade de algoritmos

PROVA PRÁTICA
->ESTRUTURA LINEAR;
*/

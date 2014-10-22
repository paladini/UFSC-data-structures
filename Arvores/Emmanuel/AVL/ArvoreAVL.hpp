// identificar rotação dupla?
#ifndef ARVOREAVL_HPP_ 
#define ARVOREAVL_HPP_
#include "Arvore.hpp"
template <typename T>
class NoBinario: public Arvore {
 private:

 	NoBinario<T>* balanco_insere(NoBinario<T>* arv) {
 		NoBinario<T>* novaRaiz, novaRaizDupla;
 		if (!arv->balanceado()) {
 			if (altura(arv->getEsquerda()) > altura(arv->getDireita())) {
	 			if (altura((arv->getEsquerda())->getEsquerda()) > 
	 					altura((arv->getEsquerda())->getDireita()) {
	 				novaRaiz = simp_roda_esq(arv);
	 			} else {
	 				novaRaiz = simp_roda_esq(arv);
	 				novaRaizDupla = simp_roda_dir(novaRaiz);
	 			}
			} else {
				if (altura((arv->getDireita())->getDireita()) > 
					altura((arv->getDireita())->getEsquerda())) {
	 				novaRaiz = simp_roda_dir(arv);
				} else {
					novaRaiz = simp_roda_dir(arv);
					novaRaizDupla = simp_roda_esq(novaRaiz);
				}
			}
		}
 		return arv;
 	}
 	NoBinario<T>* balanco_remove(NoBinario<T>* arv) {

 	}
 public:
 	NoBinario<T>* insere(NoBinario<T>* raiz, const T& info)  {
 		return Arvore<T>::inserir(info, raiz);
 	}

 	NoBinario<T>* remove(NoBinario<T>* raiz, const T& info) {
 		NoBinario<T>* filho, temp;
 		if (raiz == NULL) {
 			return raiz;
 		}
 		if (info < raiz->getInfo()) { // Vai para a esquerda
 			raiz->setEsquerda(deletar(raiz->getEsquerda(), info));
 			return raiz;
 		}
 		if (info > raiz->getInfo()) {
 			raiz->setDireita(deletar(raiz->getDireita(), info));
 			return raiz;
 		}
 		if (raiz->getDireita() != NULL && raiz->getEsquerda() != NULL) {
 			temp = minimo(raiz->getDireita());
 			raiz->setInfo(temp->getInfo());
 			raiz->setDireita(deletar(raiz->getDireita(), raiz->getInfo()));
 			balanceado_remove(raiz);
 			return raiz;
 		}
 		temp = raiz;
 		if (raiz->getDireita() != NULL) { // filho direita
 			filho = raiz->getDireita();
 			return filho;
 		}
 		if (raiz->getEsquerda() != NULL) {
 			filho = raiz->getEsquerda();
 			return filho;
 		}
 		delete raiz; // Folha.
 		return NULL;
 	}

 	int altura(NoBinario<T>* raiz) {
 		if (raiz == NULL) {
 			return -1;
 		}
 		return raiz->getAltura();
 	}

 	bool balanceado(NoBinario<T>* raiz) {
 		double absolute = abs(altura(raiz->getDireita()) - altura(raiz->getEsquerda()));
 		return absolute < 2;
 	}

 	NoBinario<T>* simp_roda_esq(NoBinario<T>* raiz) {
 		NoBinario<T>* novaRaiz;
 		novaRaiz = raiz->getEsquerda();
 		raiz->setEsquerda(novaRaiz->getDireita());
 		novaRaiz->setDireita(raiz);
 		//atualizar alturas
 		raiz->setAltura(maximo(altura(raiz->getEsquerda()), altura(raiz->getDireita())) + 1);
 		novaRaiz->setAltura(maximo(altura(novaRaiz->getEsquerda()), altura(novaRaiz->getAltura())) + 1);
 		return novaRaiz;
 	}

 	NoBinario<T>* simp_roda_dir(NoBinario<T>* raiz) {
 		NoBinario<T>* novaRaiz;
 		novaRaiz = raiz->getDireita();
 		raiz->setDireita(novaRaiz->getEsquerda());
 		novaRaiz->setEsquerda(raiz);
 		//atualizar alturas
 		raiz->setAltura(maximo(altura(raiz->getDireita()), altura(raiz->getEsquerda())) + 1);
 		novaRaiz->setAltura(maximo(altura(novaRaiz->getDireita()), altura(raiz->getAltura())) + 1);
 		return novaRaiz;
 	}
};
#endif
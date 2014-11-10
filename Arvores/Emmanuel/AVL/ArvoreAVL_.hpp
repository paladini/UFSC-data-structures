// identificar rotação dupla?
#ifndef ARVOREAVL_HPP_ 
#define ARVOREAVL_HPP_
#include "Arvore.hpp"
#include <algorithm>
template <typename T>
class ArvoreAVL: public NoBinario<T> {
 private:

    void atualiza(NoBinario<T>* arv) {
    	arv->setAltura(std::max(altura(arv->getEsquerda()), altura(arv->getDireita())) + 1);
    }

 	NoBinario<T>* balanco_insere(NoBinario<T>* arv) {
 		NoBinario<T>* novaRaiz;
 		if (!balanceado(arv)) {
 			if (altura(arv->getEsquerda()) < altura(arv->getDireita())) {
	 			if (fator(arv->getDireita()) == 1) {
	 				novaRaiz = dup_roda_dir(arv->getEsquerda());
	 			} else {
	 				novaRaiz = simp_roda_dir(arv->getEsquerda());
	 			}
			} else {
				if (fator(arv->getEsquerda()) == -1) {
	 				novaRaiz = simp_roda_dir(arv->getDireita());
				} 
				novaRaiz = simp_roda_esq(arv);
			}
		}
		atualiza(arv);
 		return arv;
 	}

 	// NoBinario<T>* balanco_remove(NoBinario<T>* arv) {
		// NoBinario<T>* novaRaiz, novaRaizDupla;
 	// 	if (!arv->balanceado()) {
 	// 		if (altura(arv->getEsquerda()) > altura(arv->getDireita())) {
	 // 			if (altura((arv->getEsquerda())->getEsquerda())) > 
	 // 					altura((arv->getEsquerda())->getDireita()) {
	 // 				novaRaiz = simp_roda_esq(arv);
	 // 			} else {
	 // 				novaRaiz = dup_roda_esq(arv);
	 // 			}
		// 	} else {
		// 		if (altura((arv->getDireita())->getDireita()) > 
		// 			altura((arv->getDireita())->getEsquerda())) {
	 // 				novaRaiz = simp_roda_dir(arv);
		// 		} else {
		// 			novaRaiz = dup_roda_dir(arv)
		// 		}
		// 	}
		// }
 	// 	return arv; 
 	// }

 public:
 	ArvoreAVL<T>(const T& dado): NoBinario<T>(dado){}
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

 	int fator(NoBinario<T>* raiz) {
 		if (raiz == NULL) {
 			return -1;
 		}
 		return (altura(raiz->getEsquerda()) - altura(raiz->getDireita()));
 	}

 	bool balanceado(NoBinario<T>* raiz) {
 		double absolute = abs(altura(raiz->getDireita()) - altura(raiz->getEsquerda()));
 		return absolute < 2;
 	}

 	NoBinario<T>* dup_roda_esq(NoBinario<T>* raiz) {
 		/*Rotacione entre k1 e k2*/
 		raiz->setEsquerda(simp_roda_dir(raiz->getEsquerda()));
 		/*Rotacione entre k3 e k2*/
 		return simp_roda_esq(raiz);
 	}

 	NoBinario<T>* dup_roda_dir(NoBinario<T>* raiz) {
 		/*Rotacione entre k1 e k2*/
 		raiz->setDireita(simp_roda_esq(raiz->getDireita()));
 		/*Rotacione entre k3 e k2*/
 		return simp_roda_dir(raiz);
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
 		raiz->setAltura(std::max(altura(raiz->getDireita()), altura(raiz->getEsquerda()) + 1));
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
 		raiz->setAltura(std::max(altura(raiz->getEsquerda()), altura(raiz->getDireita()) + 1));
 		novaRaiz->setAltura(std::max(altura(novaRaiz->getEsquerda()), raiz->getAltura()) + 1);
 		return novaRaiz;
 	}
};
#endif
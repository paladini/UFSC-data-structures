// identificar rotação dupla?
#ifndef ARVOREAVL_HPP_ 
#define ARVOREAVL_HPP_
#include "Arvore.hpp"
#include <algorithm>
template <typename T>
class ArvoreAVL: public NoBinario<T> {
 private:

 	int maximo(int a, const int b) {
 		if (a > b) {
 			return a;
 		}
 		if (a == b) {
 			return a;
 		}
 		return b;
 	}

    void atualiza(NoBinario<T>* arv) {
    	if (arv->getEsquerda() == NULL && arv->getDireita() == 	NULL) {
    		arv->setAltura(0);
    	}
    	arv->setAltura(maximo(altura(arv->getEsquerda()), altura(arv->getDireita())) + 1);
    }

 	NoBinario<T>* balanco_insere(NoBinario<T>* arv) {
 		NoBinario<T>* novaRaiz;
 			if (fator(arv) == 2) {
	 			if (fator(arv->getDireita()) == 1) {
	 				novaRaiz = dup_roda_esq(arv);
	 			} 
	 			if (fator(arv->getDireita()) == -1) {
	 				novaRaiz = simp_roda_esq(arv);
	 			}
			}
			if (fator(arv) == -2) {
				if (fator(arv->getEsquerda()) == -1) {
	 				novaRaiz = dup_roda_dir(arv);
				} 
				if (fator(arv->getEsquerda()) == 1) {
					novaRaiz = simp_roda_dir(arv);
				}
			}
			return arv;
 	}

 	NoBinario<T>* balanco_remove(NoBinario<T>* arv) {
 		NoBinario<T>* novaRaiz;
 			if (fator(arv) == 2) {
	 			if (fator(arv->getDireita()) == 1) {
	 				novaRaiz = dup_roda_esq(arv);
	 			} 
	 			if (fator(arv->getDireita()) == -1) {
	 				novaRaiz = simp_roda_esq(arv);
	 			}
			}
			if (fator(arv) == -2) {
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
 	ArvoreAVL(const T& dado): NoBinario<T>(dado){}
 	~ArvoreAVL() {}
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
 			return 0;
 		}
 		return (altura(raiz->getEsquerda()) - altura(raiz->getDireita()));
 	}

 	bool balanceado(NoBinario<T>* raiz) {
 		int absolute = std::abs(altura(raiz->getEsquerda()) - altura(raiz->getDireita()));
 		return absolute > 1;
 	}

 	NoBinario<T>* dup_roda_esq(NoBinario<T>* raiz) {
 		
 		
 		/*Rotacione entre k1 e k2*/
 		raiz->setEsquerda(simp_roda_esq(raiz->getEsquerda()));
 		/*Rotacione entre k3 e k2*/
 		return simp_roda_dir(raiz);	
 	}

 	NoBinario<T>* dup_roda_dir(NoBinario<T>* raiz) {
 		/*Rotacione entre k1 e k2*/
 		raiz->setDireita(simp_roda_dir(raiz->getDireita()));
 		/*Rotacione entre k3 e k2*/
 		return simp_roda_esq(raiz);
 	}

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
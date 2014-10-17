#ifndef NOBINARIO_H_
#define NOBINARIO_H_
#include <iostream>
#include <cstdio>
#include <vector>
template <typename T>
class NoBinario {
 private:
   T* dado;
   NoBinario<T>* esquerda;
   NoBinario<T>* direita;
   virtual NoBinario<T>* balanco_insere(NoBinario<T>* arv) { return arv; }; // Para ajudar nos herancas
   virtual NoBinario<T>* balanco_remove(NoBinario<T>* arv) { return arv; }; // Para ajudar nos herancas
   std::vector<NoBinario<T> > elementos; //push_back(), e getEsquerdaeLEMENTO{elementos.data()} No lugar dos prints

 public:
 	NoBinario<T>(const T& dado): dado(new T(dado)), esquerda(NULL), direita(NULL) {}

 	virtual ~NoBinario<T>() {
 		//fazer destruição;
 	}

 	T* getDado() {
 		// return  elementos[];// coletar qual dado?
 	}

 	NoBinario<T>* getElementos() {
 		return elementos.data();
 	}

 	virtual NoBinario<T>* inserir(NoBinario<T>* raiz, const T& info) {
 		NoBinario<T>* novo;
 		if (info < raiz->getInfo()) {
 			if (raiz->getEsquerda() == NULL) {
 				novo = new NoBinario<T>(NULL, NULL, info);
 				raiz->setEsquerda(novo);
 			} else {
 				inserir(raiz->getEsquerda(), info);
 			}
 		} else {
 			if (raiz->getDireita() == NULL) {
 				novo = new NoBinario<T>(NULL, NULL, info);
 				raiz->setDireita(novo);
 			} else {
 				inserir(raiz->getDireita(), info);
 			}
 		}
 	}
 	virtual NoBinario<T>* remover(NoBinario<T>* raiz, const T& info) {
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
 			temp = minimo(raiz->getDireita()); // mínimo?
 			raiz->setInfo(temp->getInfo());
 			raiz->setDireita(deletar(raiz->getDireita(), raiz->getInfo()));
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
 	void preOrdem(NoBinario<T>* raiz) {
 		if (raiz != NULL) {
 			elementos.push_back(raiz->getInfo());
 			preOrdem(raiz->getEsquerda());
 			preOrdem(raiz->getDireita());
 		}
 	}
 	void emOrdem(NoBinario<T>* raiz) {
 		if (raiz != NULL) {
 			emOrdem(raiz->getEsquerda());
 			elementos.push_back(raiz->getInfo());
 			emOrdem(raiz->getDireita());
 		}
 	}
 	void posOrdem(NoBinario<T>* raiz) {
 		if (raiz != NULL) {
 			posOrdem(raiz->getEsquerda());
 			posOrdem(raiz->getDireita());
 			elementos.push_back(raiz->getInfo());
 		}
 	}
 	T* busca(const T& info, NoBinario<T>* ptr) {
 		while(ptr != NULL && ptr->getInfo() != info) {
 			if (ptr->getInfo() < info) {
 				ptr = ptr->getDireita();
 			} else {
 				ptr = ptr->getEsquerda();
 			}
 		}
 		return ptr->getInfo();
 	}
 	NoBinario<T>* minimo(NoBinario<T>* raiz) {
 		if (raiz != NULL) {
 			minimo(raiz->getEsquerda()); 			
 		}
 		return raiz;

 	}
};
#endif

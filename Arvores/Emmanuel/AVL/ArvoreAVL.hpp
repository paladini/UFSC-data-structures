#include "Arvore.hpp"
#include "NodeAVL.hpp"
template <typename T>
class ArvoreAVL: public Arvore {
 public:
 	void insere(NodeAVL<T>* raiz, const T& info) {
 		Node<T>* novo;
 		if (info < raiz->getInfo()) {
 			if (raiz->getEsquerda() == NULL) {
 				novo = new Node<T>(0, NULL, NULL, info);
 				raiz->setEsquerda(novo);
 			} else {
 				insere(raiz->getEsquerda(), info);
 			}
	 		if (!balanceado(raiz)) {
	 			if (altura(raiz->getEsquerda()) > altura(raiz->getDireita())) {
	 				//identificar situação para rotação dupla;
	 				simp_roda_esq(raiz);
	 			} else {
	 				simp_roda_dir(raiz);
	 			}
	  		}
 		} else if(raiz->getDireita() == NULL) {
 			novo = new Node<T>(0, NULL, NULL, info);
 			raiz->setDireita(novo);
 			} else {
 				insere(raiz->getDireita(), info);
 			}
	 		if (!balanceado(raiz)) {
	 			if (altura(raiz->getEsquerda()) > altura(raiz->getDireita())) {
	 				//identificar situação para rotação dupla;
	 				simp_roda_esq(raiz);
				} else {
	 				simp_roda_dir(raiz);
				}
			}
 	}

 	NodeAVL<T>* deletar(NodeAVL<T>* raiz, const T& info) {
 		Node<T>* filho, temp;
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

 	int altura(NodeAVL<T>* raiz) {
 		if (raiz == NULL) {
 			return -1;
 		}
 		return raiz->getAltura();
 	}

 	bool balanceado(NodeAVL<T>* raiz) {
 		double absolute = abs(altura(raiz->getDireita()) - altura(raiz->getEsquerda()));
 		return absolute < 2;
 	}

 	NodeAVL<T>* simp_roda_esq(NodeAVL<T>* raiz) {
 		NodeAVL<T>* novaRaiz;
 		novaRaiz = raiz->getEsquerda();
 		raiz->setEsquerda(novaRaiz->getDireita());
 		novaRaiz->setDireita(raiz);
 		//atualizar alturas
 		raiz->setAltura(maximo(altura(raiz->getEsquerda()), altura(raiz->getDireita())) + 1);
 		novaRaiz->setAltura(maximo(altura(novaRaiz->getEsquerda()), altura(novaRaiz->getAltura())) + 1);
 		return novaRaiz;
 	}

 	NodeAVL<T>* simp_roda_dir(NodeAVL<T>* raiz) {
 		NodeAVL<T>* novaRaiz;
 		novaRaiz = raiz->getDireita();
 		raiz->setDireita(novaRaiz->getEsquerda());
 		novaRaiz->setEsquerda(raiz);
 		//atualizar alturas
 		raiz->setAltura(maximo(altura(raiz->getDireita()), altura(raiz->getEsquerda())) + 1);
 		novaRaiz->setAltura(maximo(altura(novaRaiz->getDireita()), altura(raiz->getAltura())) + 1);
 		return novaRaiz;
 	}
}
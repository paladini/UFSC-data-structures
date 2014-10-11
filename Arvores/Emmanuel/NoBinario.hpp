#include <iostream>
#include "Node.hpp"
template <typename T>
class Arvore {
 private:
 public:
 	~Arvore() {}
 	void insere(Node<T>* raiz, const T& info) {
 		Node<T>* novo;
 		if (info < raiz->getInfo()) {
 			if (raiz->getEsquerda() == NULL) {
 				novo = new Node<T>(NULL, NULL, info);
 				raiz->setEsquerda(novo);
 			} else {
 				insere(raiz->getEsquerda(), info);
 			}
 		} else {
 			if (raiz->getDireita() == NULL) {
 				novo = new Node<T>(NULL, NULL, info);
 				raiz->setDireita(novo);
 			} else {
 				insere(raiz->getDireita(), info);
 			}
 		}
 	}
 	Node<T>* deletar(Node<T>* arv, const T& info) {
 		Node<T>* filho, temp;
 		if (arv == NULL) {
 			return arv;
 		}
 		if (info < arv->getInfo()) { // Vai para a esquerda
 			arv->setEsquerda(deletar(arv->getEsquerda(), info));
 			return arv;
 		}
 		if (info > arv->getInfo()) {
 			arv->setDireita(deletar(arv->getDireita(), info));
 			return arv;
 		}
 		if (arv->getDireita() != NULL && arv->getEsquerda() != NULL) {
 			temp = arv->getDireita(); // mínimo?
 			arv->setInfo(temp->getInfo());
 			arv->setDireita(deletar(arv->getDireita(), arv->getInfo()));
 			return arv;
 		}
 		temp = arv;
 		if (arv->getDireita() != NULL) { // filho direita
 			filho = arv->getDireita();
 			return filho;
 		}
 		if (arv->getEsquerda() != NULL) {
 			filho = arv->getEsquerda();
 			return filho;
 		}
 		delete arv; // Folha.
 		return NULL;
 	}
 	void preOrdem(Node<T>* raiz) {
 		if (raiz != NULL) {
 			std::cout << raiz->getInfo() << std::endl;
 			preOrdem(raiz->getEsquerda());
 			preOrdem(raiz->getDireita());
 		}
 	}
 	void emOrdem(Node<T>* raiz) {
 		if (raiz != NULL) {
 			emOrdem(raiz->getEsquerda());
 			std::cout<< raiz->getInfo << std::endl;
 			emOrdem(raiz->getDireita());
 		}
 	}
 	void posOrdem(Node<T>* raiz) {
 		if (raiz != NULL) {
 			posOrdem(raiz->getEsquerda());
 			posOrdem(raiz->getDireita());
 			std::cout << raiz->getInfo << std::endl;
 		}
 	}
 	Node<T>* busca(const T& info, Node<T>* ptr) {
 		while(ptr != NULL && ptr->getInfo() != info) {
 			if (ptr->getInfo() < info) {
 				ptr = ptr->getDireita();
 			} else {
 				ptr = ptr->getEsquerda();
 			}
 		}
 		return ptr;
 	}
};
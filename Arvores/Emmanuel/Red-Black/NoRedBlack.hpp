#ifndef NOREDBLACK_HPP_
#define NOREDBLACK_HPP_
template <typename T>
class NoRedBlack {
 private:
 	T* info;
 	NoRedBlack<T>* esquerda;
 	NoRedBlack<T>* direita;
 	NoRedBlack<T>* pai;
 	bool cor; // 1 = rubro; 0 = negro;

 public:

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
 	
 	void InsereRB (NoRedBlack<T> *raiz, T* info, NoRedBlack<T>* nodo){
 		NoRedBlack<T>* atual, pai, avo;
 		InsereArvBusca(raiz, info, nodo); // ??
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
 			raiz->cor = false;
 		}

 	}

 	PassoCE_esq
(nodoRB *atual, *pai, *avô)
nodoRB *tio;
início
tio <- avô->dir;
SE
tio->cor =
rubro
ENTÃO
//caso 1
pai->cor <- negro;
avô->cor <-
rubro
;
tio->cor <- negro;
atual <- avô;
//sobe 2 níveis
SENÃO
SE
pai->dir = atual
ENTÃO
//caso 2
roda_esq(pai);
atual <- atual->esq;
//reseta atual
FIMSE
pai->cor <- negro;
//caso3
avô->cor <-
rubro
;
roda_dir(avô);
FIMSE
fim PassoCE-esq
 };
#endif
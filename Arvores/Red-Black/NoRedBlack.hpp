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
 	
 	void insereRB (NoRedBlack<T>* raiz, const T& info, NoRedBlack<T>* nodo){
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
	NoRedBlack<T>* passoCED(NoRedBlack<T>* w, raiz) {
		while(w != raiz) {
			if (w == w->pai->esquerda) {
				w = passoCED_esq(w, raiz);
			} else {
				w = passoCE_dir(w, raiz);
			}
		}
		return w;
	}
	NoRedBlack<T>* passoCED_esq(NoRedBlack<T>* w, raiz) {
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
};
#endif
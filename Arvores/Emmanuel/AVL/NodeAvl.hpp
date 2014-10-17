#ifndef NODEAVL_HPP_
#define NODEAVL_HPP_
template <typename T>
class NodeAVL {
 private:
 	T* info;
 	NodeAVL<T>* esquerda;
 	NodeAVL<T>* direita;
 	int altura;
 public:
 	NodeAVL(int alt, Node<T>* esq, Node<T>* dir, const T& info) : 
 			altura(alt), esquerda(esq), direita(dir), info(T(info)) {}

 	~NodeAVL() {
 		delete info;
 	}
 	T getInfo() {
 		return info;
 	}
 	void setInfo(const T& _info) {
 		info = _info;
 	}
 	void setEsquerda(Node<T>* _esquerda) {
 		esquerda = _esquerda;
 	}

 	void setDireita(Node<T>* _direita) {
 		direita = _direita;
 	}

 	void setAltura(int alt) {
 		altura = alt;
 	}

 	int getAltura() {
 		return altura;
 	}
 	Node<T>* getDireita() const {
 		return direita;
 	}

 	Node<T>* getEsquerda() const {
 		return esquerda;
 	} 
};
#endif /*NODEAVL_HPP_*/
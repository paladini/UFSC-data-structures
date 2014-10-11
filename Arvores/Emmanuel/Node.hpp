#ifndef NODE_HPP_
#define NODE_HPP_
template <typename T>
class Node {
 private:
 	Node<T>* esquerda;
 	Node<T>* direita;
 	T* info;
 public:
 	Node(Node<T>* esq, Node<T>* dir, const T& info) : esquerda(esq), direita(dir), info(new T(info)) {}

 	~Node() {
 		delete info;
 	}
 	T* getInfo() {
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

 	Node<T>* getDireita() const {
 		return direita;
 	}

 	Node<T>* getEsquerda() const {
 		return esquerda;
 	} 
};
#endif
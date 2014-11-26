/**
*@author: Ranieri
*/
#ifndef AVL_TREE_H_
#define AVL_TREE_H_
#include <string>
#include <algorithm>
#include <list>
#include <stdexcept>
#include <vector>
#include "doubly_linked_list.h"
/**Classe Avl_tree
*Esta classe será responsável por criar uma árvore AVL balanceada. Respeitando suas
*características de busca, inserção e deleção. 
*/
template<typename T, template<typename > class Container = doubly_linked_list>
class avl_tree {
	using size_type = std::size_t;
 private:
	/**Struct Nodo.
	*Este struct será responsável por representar um nodo da Árvore AVL. Com altura, nodo
	*esquerda, nodo direita e dado.
	*/
	struct no {
		no(const T& dado) :
				_altura(1), esquerda(nullptr), direita(nullptr), _dado(dado) {
		}

		size_type _altura;
		no* esquerda;
		no* direita;
		T _dado;
	};
	/**Método busca
	*Este método irá buscar um dado em uma subárvore ou árvore. Retornando
	*um dado, ou uma exceção, caso o dado não seja encontrado.
	*@param root Subárvore enviada como parâmetro.
	*@param dado Dado para ser encontrado.
	*/
	T& busca(no* root, const T& dado) {
		if (root != nullptr) {
			if (dado < root->_dado)
				return busca(root->esquerda, dado);
			if (root->_dado < dado)
				return busca(root->direita, dado);
			else {
				return root->_dado;
			}
		}
		throw std::range_error("Item not found on the tree.");
	}
	/**Método fator.
	*Este método será o idenficador se uma subárvore está balanceada, ou
	*desbalanceada.
	@param root Subárvore enviada como parâmetro.
	*/
	int fator(no* root) const {
		return (root == nullptr) ?
				0 : altura(root->esquerda) - altura(root->direita);
	}
	/**Método altura
	*Retornará a altura do nodo.
	*@param root Subárvore enviada como parâmetro
	*/
	size_type altura(no* root) const {
		return (root == nullptr) ? 0 : root->_altura;
	}
	/**Método insere.
	*Este método irá inserir um elemento dado na subárvore root. Balanceando e reformando.
	*a árvore conforme a inserção.
	*@see struct no.
	*@see fator(no* root).
	*@see rotatedireita().
	*@see rotateesquerda().
	*@param root Subárvore onde o dado será inserido.
	*@param dado Dado a ser inserido na subárvore.
	*@return root Será retornado a subárvore.
	*/
	no* insere(no* root, const T& dado) {
		// If we busca a null root, we found the right spot.
		if (root == nullptr)
			return root = new no(dado);

		// If root's value is greater than insereed value, try to insere to the left.
		else if (dado < root->_dado) {
			root->esquerda = insere(root->esquerda, dado);

			// If the fator of root unbalancing is 2, we have a left-left or left-right case.
			if (fator(root) == 2) {

				// If the fator of the left no is -1, we have a left-right case.
				if (fator(root->esquerda) == -1)
					root->esquerda = rotateesquerda(root->esquerda);

				// The tree is now guaranteedly a left-left case.
				root = rotatedireita(root);
			}
		}

		// If root's value is lesser than insereed value, try to insere to the right.
		else if (root->_dado < dado) {
			root->direita = insere(root->direita, dado);

			// If the fator of root unbalancing is -2, we have a right-left or right-right case.
			if (fator(root) == -2) {

				// If the fator of the right no is 1, we have a right-left case.
				if (fator(root->direita) == 1)
					root->direita = rotatedireita(root->direita);

				// The tree is now guaranteedly a right-right case.
				root = rotateesquerda(root);
			}

			// If root's value is equal to insereed value, we have an exception.
			// TODO: busca a better exception to throw.
		} else
			throw std::exception();

		// Recalculate the no altura according to the insereion.
		root->_altura = std::max(altura(root->esquerda), altura(root->direita)) + 1;
		return root;
	}
	/**Método rotateesquerda.
	*Este método fará a rotação à esquerda da subárvore, para mante-la balanceada.
	*(Nomeclatura não baseada na pos-comp).
	*@param root Subárvore que irá ser rotacionada.
	*@return aux Será a nova raiz da subárvore após a rotação.
	*/
	no* rotateesquerda(no* root) {
		no* aux;
		aux = root->direita;
		root->direita = aux->esquerda;
		aux->esquerda = root;
		root->_altura = std::max(altura(root->esquerda), altura(root->direita)) + 1;
		aux->_altura = std::max(altura(aux->esquerda), altura(aux->direita)) + 1;
		return aux;
	}
	/**Método rotatedireita.
	*Este método fará a rotação à direita da subárvore, para mante-la balanceada.
	*(Nomeclatura não baseada na pos-comp).
	*@param root Subárvore que irá ser rotacionada.
	*@return aux Será a nova raiz da subárvore após a rotação.
	*/
	no* rotatedireita(no* root) {
		no* aux;
		aux = root->esquerda;
		root->esquerda = aux->direita;
		aux->direita = root;
		root->_altura = std::max(altura(root->esquerda), altura(root->direita)) + 1;
		aux->_altura = std::max(altura(aux->esquerda), altura(aux->direita)) + 1;
		return aux;
	}
	/**Método remove.
	*Este método irá remover um dado específico da subárvore root.
	*@see fator(no* root);
	*@see rotatedireita(no* root);
	*@see rotateesquerda(no* root);
	*@return root Será retornada a subárvore de onde o dado será removido.
	*/
	no* remove(no* root, const T& dado) {
		// If we busca a nullptr, the dado does not exist in this tree.
		if (root == nullptr)
			throw std::exception();

		// The same of insereion works here. Find where the dado must be, rebalance if needed.
		else if (dado < root->_dado) {
			root->esquerda = remove(root->esquerda, dado);
			if (fator(root) == 2) {
				if (fator(root->esquerda) == -1)
					root = rotateesquerda(root->esquerda);
				root = rotatedireita(root);
			}
		} else if (root->_dado < dado) {
			root->direita = remove(root->direita, dado);

			if (fator(root) == -2) {
				if (fator(root->direita) == 1)
					root = rotatedireita(root->direita);
				root = rotateesquerda(root);
			}
		}

		// If root's value is equal to removed value, we found the no to remove.
		else {

			// Leaf case: just delete the actual no.
			if (root->esquerda == nullptr && root->direita == nullptr) {
				delete root;
				return nullptr;
			}

			// If there is only right child, replace the to-be-deleted no and delete it.
			if (root->esquerda == nullptr) {
				no* aux = root->direita;
				delete root;
				return aux;
			}

			// If there is only left child, replace the to-be-deleted no and delete it.
			if (root->direita == nullptr) {
				no* aux = root->esquerda;
				delete root;
				return aux;
			}

			// If there are both children, busca the immediately next value, swap and retry to remove.
			no* aux = root->direita;
			while (aux->esquerda != nullptr)
				aux = aux->esquerda;
			std::swap(root->_dado, aux->_dado);
			root->direita = remove(root->direita, dado);
		}

		// Recalculate the no altura according to the removal.
		root->_altura = std::max(altura(root->esquerda), altura(root->direita)) + 1;
		return root;
	}
	/**Método emOrdem.
	*Método que irá colocar em um "container" os elementos de uma árvore.
	*Sendo eles postos em ordem(e,r,d).
	*/
	void emOrdem(no* root, Container<T>& container) const {
		if (root != nullptr) {
			emOrdem(root->esquerda, container);
			container.push_back(root->_dado);
			emOrdem(root->direita, container);
		}
	}
	/**Método preOrdem.
	*Método que irá colocar em um "container" os elementos de uma árvore.
	*Sendo eles postos em pre-ordem(r,e,d).
	*/
	void preOrdem(no* root, Container<T>& container) const {
		if (root != nullptr) {
			container.push_back(root->_dado);
			preOrdem(root->esquerda, container);
			preOrdem(root->direita, container);
		}
	}
	/**Método posOrdem.
	*Método que irá colocar em um "container" os elementos de uma árvore.
	*Sendo eles posto em pós-ordem(e,d,r).
	*/
	void posOrdem(no* root, Container<T>& container) const {
		if (root != nullptr) {
			posOrdem(root->esquerda, container);
			posOrdem(root->direita, container);
			container.push_back(root->_dado);
		}
	}
	/**Método copiarArvore
	*Este método irá copiar toda a árvore para um novo nodo aux.
	*@param other_root Árvore a ser copida.
	*@return aux Árvore copiada será retornada na variável aux.
	*/
	no* copiarArvore(no* other_root) {
		// To recursively copy, create a new no, recursively copy it's left and right child, then return it to be attached.
		no* aux = new no(other_root->_dado);
		aux->esquerda = copiarArvore(other_root->esquerda);
		aux->direita = copiarArvore(other_root->direita);
		return aux;
	}
	/**Método deletarArvore.
	*Este método irá deleter toda a Árvore recursivamente.
	*@param root Será a Árvore a ser deletada.
	*/
	void deletarArvore(no* root) {
		// To recursively delete, recursively delete both children if they exist, then delete.
		if (root != nullptr) {
			deletarArvore(root->esquerda);
			deletarArvore(root->direita);
			delete root;
		}
	}

	using self = avl_tree<T>;

public:
	/**Construtor padrão da avl_tree().
	*Construirá uma árvore de tamanho zero e raiz nula.
	*/
	avl_tree() :
			tamanho(0), _root(nullptr) {
	}
	/**Construtor com argumento da avl_tree().
	*Construirá uma árvore com um argumento, que será a raiz da árvore.
	*Note que ela irá copiar a Árvore e a setará como root.
	*@param other Será o nodo raiz.
	*@see copiarArvore(no* other_root);
	*/
	avl_tree(const self& other) {
		_root = copiarArvore(other._root);
	}
	/**Destrutor da avl_tree
	*Irá deletar toda a Árvore.
	*@see deletarArvore(no* root)
	*/
	~avl_tree() {
		deletarArvore(_root);
	}
	/**Método busca
	*Irá chamar o método privado busca.
	*@see busca(no* root, const T& dado)
	*/
	T& busca(const T& dado) {
		return busca(_root, dado);
	}
	/**Método contem
	*Irá buscar na Árvore um dado, sendo esse passado como parâmetro.
	*@param dado Dado a ser pesquisado.
	*@return bool Para identificar se o dado foi encontrado ou não.
	*/
	bool contem(const T& dado) {
		try {
			busca(_root, dado);
			return true;
		} catch (std::exception& e) {
			return false;
		}
	}
	/**Método altura
	*Irá retornar a altura da Raiz.
	*@see altura(no* _root)
	*@return altura(_root) Retornará a altura da Raiz.
	*/
	size_type altura() const {
		return altura(_root);
	}
	/**Método size
	*Retornará o tamanho total da Árvore.
	*@return tamanho Retornará o tamanho total da Árovore.
	*/
	size_type size() const {
		return tamanho;
	}
	/**Método insere.
	*Irá chamar o método insere da classe avl_tree e irá aumentar o tamanho total
	*da Árvore.
	*@see insere(no* root, const T& dado).
	*/
	void insere(const T& dado) {
		_root = insere(_root, dado);
		++tamanho;
	}
	/**Método remove
	*Irá chamar o método remove da classe avl_tree e diminuirá o tamanho total
	*da Árvore.
	*@see remove(no* root, const T& dado).
	*/
	void remove(const T& dado) {
		_root = remove(_root, dado);
		--tamanho;
	}
	/**Método emOrdem.
	*Irá chamar o método emOrdem privado na classe, e retornará o "conteiner" por ela
	*retornado.
	*@see emOrdem.
	*/
	Container<T> emOrdem() const {
		Container<T> container;
		emOrdem(_root, container);
		return container;
	}
	/**Método preOrdem.
	*Retornará o container que foi criado pela chamada do método preOrdem.
	*@see preOrdem(no* root, Container<T>& container).
	*/
	Container<T> preOrdem() const {
		Container<T> container;
		preOrdem(_root, container);
		return container;
	}
	/**Método posOrdem.
	*Retornará o container criado pelo método posOrdem.
	*@see posOrdem.
	*@return container Retornará container feito pelo método chamado.
	*/
	Container<T> posOrdem() const {
		Container<T> container;
		posOrdem(_root, container);
		return container;
	}
	/**Método breadth_first.
	*Este método será responsável por armazenar em um std::vector os nodos nível a nível
	*de uma Árvore. 
	*@return dados Retornará o vetor dados com os nodos dos níveis de uma árvore.
	*/
	std::vector<T> breadth_first() const {
		Container<no*> nos;
		std::vector<T> dados;
		if (_root != nullptr) {
			nos.push_back(_root);
			
			for (auto no : nos) {
				if (no->esquerda != nullptr) {
					nos.push_back(no->esquerda);
				}
				if (no->direita != nullptr) {
					nos.push_back(no->direita);
				}
				dados.push_back(no->_dado);
			}
		}
		return dados;
	}

	// ListaEncadeada<T> breadth_first() const {
	// 	ListaEncadeada<Elemento<T>> nos;
	// 	ListaEncadeada<T> dados;
	// 	if (_root != nullptr) {
	// 		nos.push_back(_root);
			
	// 		for (auto no : nos) {
	// 			if (no->esquerda != nullptr) {
	// 				nos.push_back(no->esquerda);
	// 			}
	// 			if (no->direita != nullptr) {
	// 				nos.push_back(no->direita);
	// 			}
	// 			dados.push_back(no->_dado);
	// 		}
	// 	}
	// 	return dados;
	// }

	// Container<T> breadth_first() const {
	// 	Container<no*> nos;
	// 	Container<T> dados;
	// 	if (_root != nullptr) {
	// 		nos.push_back(_root);
			
	// 		for (auto no : nos) {
	// 			if (no->esquerda != nullptr) {
	// 				nos.push_back(no->esquerda);
	// 			}
	// 			if (no->direita != nullptr) {
	// 				nos.push_back(no->direita);
	// 			}
	// 			dados.push_back(no->_dado);
	// 		}
	// 	}
	// 	return dados;
	// }

/*	T** to_array() const {
		T** dados = nullptr;
		if (_root != nullptr) {
			size_type _length = 1 << (altura(_root) - 1);
			no** nos = new no*[_length];
			dados = new T*[_length];

			if (tamanho) {
				nos[0] = _root;
				dados[0] = new T(_root->_dado);
				for (size_type i = 0, pos = 0; i < _length >> 1; ++i) {
					++pos;
					if (nos[i] != nullptr) {
						nos[pos] = nos[i]->esquerda;
						dados[pos] = new T(nos[i]->_dado);
						++pos;
						nos[pos] = nos[i]->direita;
						dados[pos] = new T(nos[i]->_dado);
					} else {
						nos[pos] = nullptr;
						dados[pos] = nullptr;
						++pos;
						nos[pos] = nullptr;
						dados[pos] = nullptr;

					}
				}
			}
			delete[] nos;
		}
		return dados;
	}
	*/

	private:
		size_type tamanho;
		no* _root;

};

#endif /* AVL_TREE_H_ */

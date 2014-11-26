#ifndef LISTA_ENCADEDADA_HPP_
#define LISTA_ENCADEDADA_HPP_
#include <algorithm>
#include <strings.h>
#include <vector>
template <typename T>
class Lista : public std::vector<T> {
	public:

		/**
		*	Construtor padrão da classe IndiceSecundario.
		*/
		Lista() : std::vector<T>() {}

		Lista<T>* interseccao(Lista<T> *outra){
			Lista<T> *interseccao = new Lista<T>();
			T procurado;

			for (int i = this->size()-1; i > 0; i--) {
				procurado = this->at(i);
				for (int j = outra->size()-1; j > 0; j--) {
					if (outra->at(j) == procurado) {
						interseccao->push_back(procurado);
					}
				}
			}

			// std::swap(*this, interseccao);
			return interseccao;
		}

		void adiciona(T objeto) {
			this->push_back(objeto);
		}

		bool contem(T objeto) {
			return std::find(this->begin(), this->end(), objeto) != this->end();
		}

		T retornaDado(int posicao) {
			return this->at(posicao);
		}

		int retornaTamanho() {
			return this->size();
		}

};
#endif
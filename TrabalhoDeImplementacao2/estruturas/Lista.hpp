#ifndef LISTA_ENCADEDADA_HPP_
#define LISTA_ENCADEDADA_HPP_
#include <algorithm>
#include <strings.h>
#include <vector>
/** Classe Lista.
* Essa clase implementa uma estruturas de dados denominada "lista de vetores"
* que pode ser de qualquer tipo (pois implementa templates) e também tem um 
* método especial que calcula a intersecção entre duas estruturas dessas (ou seja, 
* duas listas de vetores).
*/
template <typename T>
class Lista {
	public:

		/**
		*	Construtor padrão da classe IndiceSecundario.
		*/
		Lista() {}

		/** Método intersecção.
		* Recebe uma Lista<T> como argumento e retorna todos os elementos em comum entre 
		* essas duas listas (a lista fornecida e o "this"). Esse resultado servirá para
		* fazermos a busca por chave secundária dentro dos arquivos das manpages já indexado
		* anteriormente.
		*/
		Lista<T>* interseccao(Lista<T> *outra){
			Lista<T> *interseccao = new Lista<T>();
			T procurado;

			for (int i = this->retornaTamanho()-1; i > 0; i--) {
				procurado = this->retornaDado(i);
				for (int j = outra->retornaTamanho()-1; j > 0; j--) {
					if (outra->retornaDado(j) == procurado) {
						interseccao->adiciona(procurado);
					}
				}
			}

			std::swap(this->l, interseccao->l);
			return interseccao;
		}

		/** Método adiciona.
		* Método que adiciona um novo objeto à lista de vetor.
		*/
		void adiciona(T objeto) {
			l.push_back(objeto);
		}

		/** Método contem.
		* Método que verifica se a lista de vetor contem determinado objeto.
		*/
		bool contem(T objeto) {
			return std::find(l.begin(), l.end(), objeto) != l.end();
		}

		/** Método retornaDado.
		* Retorna um dado de acordo com a posição fornecida pelo usuário.
		*/
		T retornaDado(int posicao) {
			return l.at(posicao);
		}

		/** Método retornaTamanho.
		* Retorna o tamanho dessa estrutura de dados.
		*/
		int retornaTamanho() {
			return l.size();
		}

	private:
		// Lista de vetores que essa classe tem.
		std::vector<T> l;

};
#endif
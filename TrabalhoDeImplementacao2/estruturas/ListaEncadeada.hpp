#ifndef LISTA_ENCADEDADA_HPP_
#define LISTA_ENCADEDADA_HPP_

// #include <vector>
#include <algorithm>
#include <strings.h>
#include <vector>
#include "../modelos/Palavra.hpp"
#include "ListaEnc.hpp"
template <typename T>
class Lista : public std::vector<T>() {
	public:

		/**
		*	Construtor padrão da classe IndiceSecundario.
		*/
		ListaEncadeada() : ListaEnc<T>(){}

		ListaEncadeada<T>* interseccao(ListaEncadeada<T> *outra) {
			ListaEncadeada<T> *interseccao = new ListaEncadeada<T>();
			T procurado;

			for (int i = this->retornaTamanho()-1; i > 0; i--) {
				procurado = this->retornaDado(i);
				for (int j = outra->retornaTamanho()-1; j > 0; j--) {
					if (outra->retornaDado(j) == procurado) {
						interseccao->adiciona(procurado);
					}
				}
			}

			return interseccao;
		}
		// ListaEncadeada<T>& interseccao(ListaEncadeada<T>& outra) {
		// 	ListaEncadeada<T> interseccao;
		// 	for(int i = 0; i < this->retornaTamanho(); i++) {
		// 		auto it = this->retornaDado(i);
		// 		for(int j = 0; j < outra.retornaTamanho(); j++) {
		// 			auto that = this->retornaDado(j);
		// 			if(it == that) {
		// 				interseccao.adicionaNoInicio(it);
		// 				break;
		// 			}
		// 		}
		// 	}
			
		// 	// Invertendo os dois.
			
		// 	// for (auto it : *this) {
		// 	// 	for (auto that : outra) {
		// 	// 		if (it == that) {
		// 	// 			intersection.push_back(it);
		// 	// 			break;
		// 	// 		}
		// 	// 	}
		// 	// }
		// 	// ListaEncadeada<T> temp = *this;
		// 	// this = interseccao;
		// 	// interseccao = temp;
		// 	std::swap(*this, interseccao);
		// 	return *this;
		// }

		friend void swap(ListaEncadeada<T>& a, ListaEncadeada<T>& b) {
			using std::swap;

			auto temp = a.retornaCabeca();
			int tamanho = a.retornaTamanho();
			a.defineCabeca(b.retornaCabeca());
			a.defineTamanho(b.retornaTamanho());

			b.defineTamanho(tamanho);
			b.defineCabeca(temp);
			// swap(a.retornaCabeca(), b.retornaCabeca());
			// swap(a.retornaTamanho(), b.retornaTamanho());
		}

		/**
		* Método que verifica se determinado Objeto existe nessa estrutura de dados.
		* @param objeto Objeto que será verificada a existência dentro dessa estrutura.
		* @return boolean indicando se o objeto está presente (true) ou não (false) na estrutura.
		*/
		// bool has(T objeto) {
		// 	return std::find(this->begin(), this->end(), objeto) != this->end();
		// }

};
#endif
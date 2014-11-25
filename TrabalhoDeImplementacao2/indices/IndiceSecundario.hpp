#ifndef INDICE_SECUNDARIO_HPP_
#define INDICE_SECUNDARIO_HPP_

#include <vector>
#include <algorithm>
#include "../modelos/Palavra.hpp"

class IndiceSecundario : public vector<Palavra> {
	public:

		IndiceSecundario<Palavra>& intersect(const IndiceSecundario<Palavra>& other) {
			IndiceSecundario<Palavra> intersection;
			for (auto it : *this) {
				for (auto that : other) {
					if (it == that) {
						intersection.push_back(it);
						break;
					}
				}
			}
			std::swap(*this, intersection);
			return *this;
		}

		/**
		* Método que verifica se determinada Palavra existe nessa estrutura de dados.
		* @param palavra Palavra que será verificada a existência dentro dessa estrutura.
		* @return boolean indicando se a palavra está presente (true) ou não (false) na estrutura.
		*/
		bool has(Palavra palavra) {
			return std::find(this->begin(), this->end(), palavra) != this->end();
		}

};
#endif;
/*
 * Lista.hpp
 *
 *  Created on: 31/08/2014
 *      Author: podesta
 */

#ifndef LISTA_HPP_
#define LISTA_HPP_
#define MAXLISTA 100
#define ERROLISTACHEIA -1
#define ERROLISTAVAZIA -2
#define ERROPOSICAO -3
template<typename T>
class Lista {
 private:
		T *dados;
		int ultimo, tamanho;
 public:
	Lista(){
		dados = new T[MAXLISTA];
		ultimo = -1;
		tamanho = MAXLISTA;
	}
	Lista<T>(int tam){
		dados = new T[tam];
		ultimo = -1;
		tamanho = tam;
	}
	~Lista(){
		ultimo = -1;
	}
	int adiciona(T dado){
		if(!listaCheia()){
			dados[++ultimo] = dado;
			return ultimo;
		} else {
			throw ERROLISTACHEIA;
		}
	}
	int adicionaNoInicio(T dado){
		int posicao;
		if(!listaCheia()){
			ultimo = ultimo + 1;
			for(posicao = ultimo; posicao > 0; posicao--){
				dados[posicao] = dados[posicao -1];
			}
			dado[0] = dado;
			return 0;
		} else {
			throw ERROLISTACHEIA;
		}
	}
	int adicionaNaPosicao(T dado, int destino){
		int posicao;
		if(listaCheia()){
			throw ERROLISTACHEIA;
		} else {
			if(destino < 0 || destino > ultimo + 1)
				throw ERROPOSICAO;
			ultimo = ultimo + 1;
			for(posicao = ultimo; posicao > destino; posicao--){
				dados[posicao] = dados[posicao - 1];
			}
			dados[destino] = dado;
			return destino;
		}
	}
	int adicionaEmOrdem(T dado){
		int posicao = 0;
		if(listaCheia()){
			throw ERROLISTACHEIA;
		} else {
			for(int i = 0; i <= ultimo; i++){
				if(dado > dados[posicao]){
					posicao++;
				}else{
					break;
				}
			}
			return adicionaNaPosicao(dado, posicao);
		}
	}

	T retira(){
		if(!listaVazia()){
			ultimo = ultimo - 1;
			return dados[ultimo + 1];
		} else {
			throw ERROLISTAVAZIA;
		}
	}
	T retiraDoInicio(){
		int posicao;
		if(!listaVazia()){
			ultimo = ultimo - 1;
			int valor = dados[0];
			for(posicao = 0; posicao <= ultimo; posicao++){
				dados[posicao] = dados[posicao + 1];
			}
			return valor;
		} else {
			throw ERROLISTAVAZIA;
		}
	}
	T retiraDaPosicao(int fonte){
		int posicao, valor;
		if(!listaVazia()){
			ultimo = ultimo - 1;
			valor = dados[fonte];
			for(posicao = fonte; posicao <= ultimo; posicao++){
				dados[posicao] = dados[posicao + 1];
			}
			return valor;
		} else {
			throw ERROLISTAVAZIA;
		}
	}
	T retiraEspecifico(T dado){
		int posicao;
		if(!listaVazia()){
			posicao = posicao(dado);
			if(posicao < 0){
				throw ERROPOSICAO;
			}else{
				return retiraDaPosicao(posicao);
			}
		}else{
			throw ERROLISTAVAZIA;
		}
	}
	bool listaCheia(){
		return ultimo == tamanho -1;
	}

	bool listaVazia(){
		return ultimo == -1;
	}
	int posicao(T dado){
		int posicao = 0;
		for(int i = 0; i <= ultimo; i++){
			if(igual(dado, dados[posicao])){
				break;
			}else{
				posicao++;
			}
		}
		if(posicao > ultimo){
			throw ERROPOSICAO;
		}else{
			return posicao;
		}
	}
	bool contem(T dado){
		int igual = 0;
		for(int i = 0; i < tamanho; i++){
			if(igual(dados[i], dado)){
				igual = 1;
			}
		}
		if(igual == 1){
			return true;
		} else {
			return false;
		}
	}
	bool igual(T dado1, T dado2){
		return T::operator=(dado2);
	}
	bool maior(T dado1, T dado2){
		return T::operator>(dado2);
	}
	bool menor(T dado1, T dado2){
		return T::operator<(dado2);
	}

};

#endif /* LISTA_HPP_ */

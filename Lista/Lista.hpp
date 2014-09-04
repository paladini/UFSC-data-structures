/**
 * File: Lista.hpp
 * @author: Emmanuel Podestá, Fernando Paladini.
 * @since: Created on 25 de Agosto de 2014, 20:52.
 * Copyright 2014 Emmanuel Podestá, Fernando Paladini.
 * < Na verdade é Copyleft, MIT License \o/ >
 */

/** Classe Lista.
 * A classe Lista implementa uma lista de vetores simples, não-encadeada, que tem métodos
 * como fornecer posição do ponteiro, adicionar elemento no início, adicionar elemento na posição,
 * remover item da posição, remover do início, existe, entre outros.
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

	/** Construtor padrão da Lista.
	 * O construtor padrão da Lista constroi uma lista de tamanho "MAXLISTA", uma constante definida no escopo da classe.
	 * O "tamanho" da lista será também definido com o valor de "MAXLISTA".
	 * @see limpar()
	 */
	Lista(){
		dados = new T[MAXLISTA];
		tamanho = MAXLISTA;
		limpar();
	}

	/** Construtor da Lista recebendo como argumento o tamanho da lista a ser criada.
	 * O construtor da Lista constrói uma lista de tamanho "tam".  Além disso, o "tamanho" da lista será também definido co mo valor de "tam".
	 * @param tam Argumento que informa qual é o tamanho da lista que será criada.
	 * @see limpar()
	 */
	Lista<T>(int tam){
		dados = new T[tam];
		tamanho = tam;
		limpar();
	}

	/** Destrutor padrão da Lista.
	 * O destrutor padrão da lista desaloca a memória dinâmica alocada para este objeto. Antes disso, zera o tamanho da lista.
	 * @see limpar()
	 */
	~Lista(){
		limpar();
		delete[] dados;
	}

	/** Adiciona um novo elemento no final da Lista.
	 * Este método recebe um dado do tipo T e adiciona este elemento no final da lista, ou seja, adiciona esse dado na última posição da lista.
	 * @param dado O dado que será inserido dentro da lista. Precisa ser do mesmo tipo de dados que a lista armazena.
	 * @see listaCheia()
	 * @exception ERROLISTACHEIA Exceção que indica que um novo dado não pode ser adicionado, pois a lista já está cheia.
	 * @return um inteiro que indica a posição do último elemento a ser adicionado na lista (no caso, o último).
	 */
	int adiciona(T dado){
		if(!listaCheia()){
			dados[++ultimo] = dado;
			return ultimo;
		} else {
			throw ERROLISTACHEIA;
		}
	}

	/** Adiciona um novo elemento no início da Lista.
	 * Este método recebe um dado do tipo T e adiciona este elemento no início da lista, ou seja, adiciona esse dado na posição zero.
	 * @param dado O dado que será inserido dentro da lista. Precisa ser do mesmo tipo de dados que a lista armazena.
	 * @see listaCheia()
	 * @exception ERROLISTACHEIA Exceção que indica que um novo addo não pode ser adicionado, pois a lista já está cheia.
	 * @return um inteiro que indica a posição do último elemento a ser adicionado na lista (no caso, zero).
	 */
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

	/** Adiciona um novo elemento em uma posição específica da Lista.
	 * Este método recebe um dado do tipo T e adiciona este elemento em determinada posição.
	 * @param posicao A posição na lista em que o dado será adicionado.
	 * @param dado O dado a ser inserido na Lista.
	 * @see listaCheia()
	 * @exception ERROLISTACHEIA Exceção que indica que um novo dado não pode ser adicionado, pois a lista já está cheia.
	 * @return um inteiro que indica a posição do último elemento a ser adicionado na lista (no caso, o "destino").
	 */
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

	/** Adiciona um novo elemento seguindo a ordem da Lista.
	 * Este método recebe um dado do tipo T e adiciona este elemento em determinada posição.
	 * @param dado O dado a ser inserido na Lista.
	 * @see listaCheia()
	 * @exception ERROLISTACHEIA Exceção que indica que um novo dado não pode ser adicionado, pois a lista já está cheia.
	 * @return um inteiro que indica a posição do último elemento a ser adicionado na lista (no caso, a posição encontrada que está de acordo com a ordenação da Lista).
	 */
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

	/** Retira o último elemento da Lista.
	 * Este método retira o último elemento da Lista e decrementa o ponteiro da Lista.
	 * @see listaVazia()
	 * @exception ERROLISTAVAIZA Exceção que indica que um dado não pode ser retirado, pois a lista já está vazia.
	 * @return o dado do tipo T que foi retirado do final da Lista.
	 */
	T retira(){
		if(!listaVazia()){
			ultimo = ultimo - 1;
			return dados[ultimo + 1];
		} else {
			throw ERROLISTAVAZIA;
		}
	}

	/** Retira o primeiro elemento da Lista.
	 * Este método retira o primeiro elemento da Lista e traz todos os dados uma posição para frente.
	 * @see listaVazia()
	 * @exception ERROLISTAVAZIA Exceção que indica que um dado não pode ser retirado, pois a lsita já está vazia.
	 * @return o dado do tipo T que foi retirado do início da Lista.
	 */
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

	/** Retira um elemento em uma posição específica da Lista.
	 * @see listaVazia()
	 * @param fonte A posição do dado a ser retirado.
	 * @exception ERROLISTAVAZIA Exceção que indica que um dado não pode ser retirado, pois a lsita já está vazia.
	 * @return o dado do tipo T que foi retirado da posição específica da Lista.
	 */
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

	/** Retira um elemento da Lista, se este objeto existir dentro da Lista.
	 * @see listaVazia()
	 * @param dado A posição do dado a ser retirado.
	 * @exception ERROPOSICAO Exceção que indica que o dado enviado via argumento não existe dentro dessa Lista, logo não pode ser removido.
	 * @exception ERROLISTAVAZIA Exceção que indica que um dado não pode ser retirado, pois a lsita já está vazia.
	 * @return o dado do tipo T que foi retirado.
	 */
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

	/** Verifica se a Lista está cheia.
	 * @return um boolean que indica se a Lista está cheia ou não.
	 */
	bool listaCheia(){
		return ultimo == tamanho -1;
	}

	/** Verifica se a lista está vazia.
	 * @return um boolean que indica se a Lista está vazia ou não.
	 */
	bool listaVazia(){
		return ultimo == -1;
	}

	/** Verifica se um determinado elemento existe na Lista. Se sim, retorna a sua posição.
	 * @param dado O dado que será verificado a existência dentro da Lista.
	 * @exception ERROPOSICAO Exceção que indica que o elemento enviado via argumento não existe dentro dessa Lista.
	 * @return a posição do elemento que foi encontrado na Lista.
	 */
	int posicao(T dado){
		int posicao = 0;
		for(int i = 0; i <= ultimo; i++){
			if(dado == dados[posicao]){
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

	/** Verifica se a Lista contêm o elemento especificado.
	 * @param dado O dado que será verificado a existência dentro da Lista.
	 * @return um boolean que indica se a Lista contêm ou não o elemento especificado.
	 */
	bool contem(T dado){
		int igual = 0;
		for(int i = 0; i < tamanho; i++){
			if(dados[i] == dado){
				igual = 1;
			}
		}
		return igual == 1;
	}

	/** Limpa a Lista, ou seja, declara que o "último" elemento é igual a -1.
	 */
	void limpar(){
		ultimo = -1;
	}

};

#endif /* LISTA_HPP_ */

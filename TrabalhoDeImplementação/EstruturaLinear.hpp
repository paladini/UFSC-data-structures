/*
* File: EstruturaLinear.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 25 de Agosto de 2014, 20:52
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/

/** Classe Estrutura Linear
 * A classe Estrutura Linear terá como funções inserir, limpar,
 * fornecer a posição do ponteiro e o valor do elemento que
 * está apontado pelo mesmo, métodos para verificar se a Estrutura está cheia
 * ou vazia e contrutures. Essa classe será herdada pelas classes pilha e fila
 * presentes nesse projeto.
 */
#ifndef ESTRUTURALINEAR_HPP
#define ESTRUTURALINEAR_HPP
#define FULLERROR -1
#define EMPTYERROR -2
#define MAX 100
template<typename T>
class EstruturaLinear {
 protected:
	T *m_dados;
	int ponteiro, tamanhoDaEstrutura;

 public:
    /** Construtor da estrutura linear sem argumentos
     * Teremos um construtor sem nenhum argumento, onde o tamanho do array será determinado pela constante MAX que está determinada
     * no código. O construtor alocará espaço na memória para o array com tipo modificável e determinará a variável tamanhoDaEstrutura com
     * o tamanho alocado pelo construtor na hora da construção do array. Além de que ele será responsável por limpar a Estrutura, ou seja,
     * fazer com que a localização do ponteiro esteja situada na posição -1, determinando uma estrutura vazia.
     * @see limpar()
     */
	EstruturaLinear() {
		m_dados = new T[MAX];
		tamanhoDaEstrutura = MAX;
		limpar();
	}
    /** Construtor da Estrutura Linear com argumento
     * Suas funções são semelhantes a do construtor sem argumento, com a diferença de que o construtor alocará na mémoria um tamanho
     * que será adquirido por meio do argumento, não mais por meio de uma constante definida no código.
     * @see limpar()
     */
	EstruturaLinear<T>(int tamanho) {
		m_dados = new T[tamanho];
		tamanhoDaEstrutura = tamanho;
		limpar();
	}
    /** Destrutor da EstruturaLinear
     * Irá destruir o arranjo construido pela alocação no construtor.
     */
	~EstruturaLinear() {
		delete[] m_dados;
	}
    /** Método insere
     *	Este método será responsável por inserir um dado trazido como argumento na estrutura. Para isso, é preciso verificar
     * se a estrutura está cheia, se não estiver será inserido o dado na proxima posição do array. Note que a posição do
     * array é determinada pelo ponteiro, onde ele estiver será a posição do fim da estrutura. Contudo, se a estrutura
     * estiver cheia será lançado uma exceção para ser tratada por algum método ou classe.
     * @see estaCheio()
     */
	void insere(T dado) {
		if (!estaCheio()) {
			this->m_dados[++ponteiro] = dado;
		} else {
			throw FULLERROR;
		}
	}
    /** Método limpar
     * Será responsável por limpar a estrutura colocando a posição do ponteiro em -1. Logo, todos os valores que estavam na estrutura serão
     * determinados como lixo, e não estarão mais incluidos na estrutura.
     */
	void limpar() {
		ponteiro = -1;
	}
    /** Método Ponteiro
     * Esse método tem a função de retornar o valor do elemento na posição que o ponteiro indica. Contudo, é necessário avaliar se a estrutura
     * está vazia, pois se estiver não terá nenhum valor para ser retornado. Logo terá que retornar uma exceção. Note que como o retorno do
     * método será um elemento da estrutura, e ela pode armazenar qualquer valor por causa do template, é necessario que o tipo de retorno
     * do método seja T.
     * @see estaVazio()
     * @return o objeto do tipo instanciado que está no topo da estrutura de dados linear.
     */
	T Ponteiro() {
		if (!estaVazio()) {
			return m_dados[ponteiro];
		} else {
			throw EMPTYERROR;
		}
	}
    /** Método getPosPonteiro
     * Esse método tem a responsabilidade de retornar a posição do ponteiro, onde ele está indicando. Porém, análogo ao método Ponteiro
     * terá que avaliar se a estrutura está cheia ou vazia, pois se estiver vazia o ponteiro indicará a posição -1, por isso terá que
     * mandar uma exceção indicando estrutura vazia.
     * @see estaVazio()
     * @return um inteiro indicando a posição do ponteiro da estrutura de dados linear ("topo" ou "frente").
     */
	int getPosPonteiro() {
		if (!estaVazio()) {
			return ponteiro;
		} else {
			throw EMPTYERROR;
		}
	}
    /** Método estaVazio
     * Este método retornará verdadeiro se a posição do ponteiro estiver em -1, pois isso indicará que nenhum elemento foi adicionado
     * e a estrutura estará vazia. Contudo, retornará falso caso o contrário
     * @return um boolean que, se verdadeiro, indica que a estrutura de dados está vazia.
     */
	bool estaVazio() {
		return (ponteiro == -1);
	}
    /** Método estaCheio
     * Este método retornará verdadeiro caso a posição indicada pelo ponteiro se igualar a variável tamanhoDaEstrutura decrementada de 1, pois
     * a posição do array começa em 0, ou seja, se uma estrutra for alocada com 10 posições, a última posição será 9.
     * @return um boolean que, se verdadeiro, indica que a estrutura de dados está vazia.
     */
	bool estaCheio() {
		return (ponteiro == tamanhoDaEstrutura - 1);
	}
};
#endif /* ESTRUTURALINEAR_HPP */

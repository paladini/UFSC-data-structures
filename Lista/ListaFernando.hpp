#ifndef LISTA_HPP_
#define LISTA_HPP_

#define MAXLISTA 10
template<typename T>
class ListaFernando{
private:
	T *dados;
	int ultimo, tamanho;

public:
	ListaFernando(){
		dados = new T[MAXLISTA];
		tamanho = MAXLISTA;
		limparLista();
	}

	ListaFernando(int tamanhoDaLista){
		dados = new T[tamanhoDaLista];
		tamanho = tamanhoDaLista;
		limparLista();
	}

	~ListaFernando(){
		limparLista();
		delete[] dados;
	}

	void limparLista(){
		ultimo = -1;
	}


};
#endif /* LISTA_HPP_ */
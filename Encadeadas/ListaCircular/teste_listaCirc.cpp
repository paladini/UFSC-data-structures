#include "gtest/gtest.h"
#include "ListaCircular.hpp"
// Não consegui fazer eliminaNoInicio e posicaoMem!
int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

class Objeto{
};

class TesteListaCirc: public ::testing::Test{
 protected:
	ListaCirc<int> l = ListaCirc<int>();
	ListaCirc<Objeto*> lobj = ListaCirc<Objeto*>();
};

TEST_F(TesteListaCirc, ListaVazia) {
	ASSERT_TRUE(l.listaVazia());
	ASSERT_TRUE(lobj.listaVazia());
}

TEST_F(TesteListaCirc, ListaVaziaNeg) {
	l.adiciona(0);
	ASSERT_FALSE(l.listaVazia());
	lobj.adiciona(0);
	ASSERT_FALSE(lobj.listaVazia());
}

TEST_F(TesteListaCirc, Adiciona) {
	for (int i = 0; i < 10; i++) {
		l.adiciona(i);
	}
	ASSERT_EQ(l.posicao(6), 6);
	
}

TEST_F(TesteListaCirc, Contem) {
	l.adiciona(0);
	ASSERT_TRUE(l.contem(0));
	Objeto *obj = new Objeto();
	lobj.adiciona(obj);
	ASSERT_TRUE(lobj.contem(obj));
}

TEST_F(TesteListaCirc, ContemNeg) {
	l.adiciona(0);
	l.adiciona(1);
	l.adiciona(2);
	ASSERT_FALSE(l.contem(8));
	Objeto *obj = new Objeto();
	Objeto *obj0 = new Objeto();
	lobj.adiciona(obj);
	lobj.adiciona(obj0);
	lobj.retira();
	ASSERT_FALSE(lobj.contem(obj0));
}

TEST_F(TesteListaCirc, AdicionaNoInicio) {
	l.adicionaNoInicio(0);
	l.adicionaNoInicio(1);
	l.adicionaNoInicio(2);
	ASSERT_EQ(l.posicao(2), 0);
	Objeto *obj = new Objeto();
	Objeto *obj0 = new Objeto();
	lobj.adicionaNoInicio(obj);
	lobj.adicionaNoInicio(obj0);
	ASSERT_EQ(lobj.posicao(obj0), 0);
}

TEST_F(TesteListaCirc, AdicionaNaPosicao) {
	l.adiciona(0);
	l.adiciona(1);
	l.adiciona(2);
	l.adicionaNaPosicao(8, 1);
	ASSERT_EQ(l.posicao(8), 1);
	Objeto *obj0 = new Objeto();
	Objeto *obj1 = new Objeto();
	Objeto *obj2 = new Objeto();
	lobj.adiciona(obj0);
	lobj.adiciona(obj1);
	lobj.adicionaNaPosicao(obj2, 1);
	ASSERT_EQ(lobj.posicao(obj2), 1);

}

TEST_F(TesteListaCirc, ExcecaoAdicionaNaPosicao) {
	for (int i = 0; i < 10; i++) {
		l.adicionaNaPosicao(i, i);
	}
	EXPECT_ANY_THROW(l.adicionaNaPosicao(11, 12));
}

TEST_F(TesteListaCirc, AdicionaEmOrdem) {
	for (int i = 10; i > 0; i--) {
		l.adicionaEmOrdem(i);
	}
	for (int i = 0; i < 10; i++) {
		ASSERT_TRUE(l.menor(i, i+1));
	}
}

TEST_F(TesteListaCirc, Retira) {
	l.adiciona(0);
	l.adiciona(1);
	ASSERT_EQ(l.retira(), 1);
}

TEST_F(TesteListaCirc, RetiraDaPosicao) {
	for (int i = 0; i < 10; i++) {
		l.adiciona(i);
	}
	l.adicionaNaPosicao(9, 6);
	ASSERT_EQ(l.retiraDaPosicao(7), 9);
}

TEST_F(TesteListaCirc, RetiraDoInicio) {
	for (int i = 0; i < 10; i++) {
		l.adiciona(i);
	}
	ASSERT_EQ(l.retiraDoInicio(), 0);
}


TEST_F(TesteListaCirc, Posicao) {
	for (int i = 0; i < 10; i++) {
		l.adiciona(i);
	}
	l.adicionaNaPosicao(100, 6);
	ASSERT_EQ(l.posicao(100), 6);
}

TEST_F(TesteListaCirc, ExcecaoPosicao) {
	l.adiciona(0);
	l.adiciona(1);
	EXPECT_ANY_THROW(l.posicao(10));
}

TEST_F(TesteListaCirc, DestroiLista) {
	for (int i = 0; i < 15; i++) {
		l.adiciona(i);
	}
	l.destroiLista();
	ASSERT_TRUE(l.listaVazia());
}

TEST_F(TesteListaCirc, RetornaDado) {
	for (int i = 0; i < 10; i++) {
		l.adiciona(i);
	}
	l.adicionaNaPosicao(10, 7);
	ASSERT_EQ(l.retornaDado(7), 10);
}

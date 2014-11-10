#include "gtest/gtest.h"
#include "ListaCircDupla.hpp"
// Não consegui fazer eliminaNoInicio e posicaoMem!
int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

class Objeto{
public:	
	int a;

	Objeto(){
		
	}

	Objeto(int amerenda){
		a = amerenda;
	}

	bool operator==(const Objeto& rhs) const {
		return a == rhs.a;
	}
	bool operator>(const Objeto& rhs) const {
		return a > rhs.a;
	}
	bool operator<(const Objeto& rhs) const {
		return a < rhs.a;
	}

};

class TesteListaDuplaCirc: public ::testing::Test{
 protected:
	ListaDuplaCirc<int> l = ListaDuplaCirc<int>();
	ListaDuplaCirc<Objeto> lobj = ListaDuplaCirc<Objeto>();
};

TEST_F(TesteListaDuplaCirc, ListaVazia) {
	ASSERT_TRUE(l.listaVazia());
	ASSERT_TRUE(lobj.listaVazia());
}

TEST_F(TesteListaDuplaCirc, ListaVaziaNeg) {
	l.adicionaDuplo(0);
	ASSERT_FALSE(l.listaVazia());
	Objeto obj0(0);
	lobj.adicionaDuplo(obj0);
	ASSERT_FALSE(lobj.listaVazia());
}

TEST_F(TesteListaDuplaCirc, AdicionaDuplo) {
	for (int i = 0; i < 10; i++) {
		l.adicionaDuplo(i);
	}
	ASSERT_EQ(l.retiraDuplo(), 9);
	Objeto obj0(0);
	Objeto obj1(1);
	lobj.adicionaDuplo(obj0);
	lobj.adicionaDuplo(obj1);
	ASSERT_EQ(lobj.posicaoDuplo(obj0), 0);
}

TEST_F(TesteListaDuplaCirc, ContemDuplo) {
	l.adicionaDuplo(0);
	ASSERT_TRUE(l.contemDuplo(0));
	Objeto obj(0);
	lobj.adicionaDuplo(obj);
	ASSERT_TRUE(lobj.contemDuplo(obj));
}

TEST_F(TesteListaDuplaCirc, ContemDuploNeg) {
	l.adicionaDuplo(0);
	l.adicionaDuplo(1);
	l.adicionaDuplo(2);
	ASSERT_FALSE(l.contemDuplo(8));
	Objeto obj(0);
	Objeto obj0(1);
	lobj.adicionaDuplo(obj);
	lobj.adicionaDuplo(obj0);
	lobj.retiraDuplo();
	ASSERT_FALSE(lobj.contemDuplo(obj0));
}

TEST_F(TesteListaDuplaCirc, AdicionaNoInicioDuplo) {
	l.adicionaNoInicioDuplo(0);
	l.adicionaNoInicioDuplo(1);
	l.adicionaNoInicioDuplo(2);
	ASSERT_EQ(l.posicaoDuplo(0), 2);
	Objeto obj(0);
	Objeto obj0(1);
	lobj.adicionaNoInicioDuplo(obj);
	lobj.adicionaNoInicioDuplo(obj0);
	ASSERT_EQ(lobj.posicaoDuplo(obj0), 0);
}

TEST_F(TesteListaDuplaCirc, AdicionaNaPosicaoDuplo) {
	l.adicionaDuplo(0);
	l.adicionaDuplo(1);
	l.adicionaDuplo(2);
	l.adicionaDuplo(3);
	l.adicionaNaPosicaoDuplo(10, 1);
	ASSERT_EQ(l.posicaoDuplo(10), 1);
	Objeto obj0(0);
	Objeto obj1(1);
	Objeto obj2(2);
	Objeto obj3(3);
	lobj.adicionaDuplo(obj0);
	lobj.adicionaDuplo(obj1);
	lobj.adicionaDuplo(obj2);
	lobj.adicionaNaPosicaoDuplo(obj3, 2);
	ASSERT_EQ(lobj.posicaoDuplo(obj3), 2);

}

TEST_F(TesteListaDuplaCirc, ExcecaoAdicionaNaPosicaoDuplo) {
	for (int i = 0; i < 10; i++) {
		l.adicionaNaPosicaoDuplo(i, i);
	}
	EXPECT_ANY_THROW(l.adicionaNaPosicaoDuplo(20, 12));
}

TEST_F(TesteListaDuplaCirc, AdicionaEmOrdemDuplo) {
	for (int i = 10; i > 0; i--) {
		l.adicionaEmOrdem(i);
	}
	for (int i = 0; i < 10; i++) {
		ASSERT_TRUE(l.menor(i, i+1));
	}
}

TEST_F(TesteListaDuplaCirc, RetiraDuplo) {
	l.adicionaDuplo(0);
	l.adicionaDuplo(1);
	ASSERT_EQ(l.retiraDuplo(), 1);
	Objeto obj0(0);
	Objeto obj1(1);
	lobj.adicionaDuplo(obj0);
	lobj.adicionaDuplo(obj1);
	ASSERT_EQ(lobj.retiraDuplo(), obj1);
}

TEST_F(TesteListaDuplaCirc, RetiraEspecifico) {
	for (int i = 0; i < 10; i++) {
		l.adicionaDuplo(i);
	}
	ASSERT_EQ(l.retiraEspecificoDuplo(7), 7);
}

TEST_F(TesteListaDuplaCirc, ExcecaoRetiraEspecifico) {
	for (int i = 0; i < 10; i++) {
		l.adicionaDuplo(i);
	}
	EXPECT_ANY_THROW(l.retiraEspecificoDuplo(11));
}


TEST_F(TesteListaDuplaCirc, RetiraDaPosicaoDuplo) {
	for (int i = 0; i < 10; i++) {
		l.adicionaDuplo(i);
	}
	l.adicionaNaPosicaoDuplo(20, 6);
	ASSERT_EQ(l.retiraDaPosicaoDuplo(7), 20);
}

TEST_F(TesteListaDuplaCirc, RetiraDaPosicaoExcecao) {
	for (int i = 0; i < 10; i++) {
		l.adicionaDuplo(i);
	}
	EXPECT_ANY_THROW(l.retiraEspecificoDuplo(11));
}


TEST_F(TesteListaDuplaCirc, RetiraDoInicioDuplo) {
	for (int i = 0; i < 10; i++) {
		l.adicionaNoInicioDuplo(i);
	}
	ASSERT_EQ(l.retiraDoInicioDuplo(), 9);
}

TEST_F(TesteListaDuplaCirc, PosicaoDuplo) {
	for (int i = 0; i < 10; i++) {
		l.adicionaDuplo(i);
	}
	l.adicionaNaPosicaoDuplo(100, 6);
	ASSERT_EQ(l.posicaoDuplo(100), 6);
}

TEST_F(TesteListaDuplaCirc, ExcecaoPosicaoDuplo) {
	l.adicionaDuplo(0);
	l.adicionaDuplo(1);
	EXPECT_ANY_THROW(l.posicaoDuplo(10));
}

TEST_F(TesteListaDuplaCirc, DestroiListaDuplo) {
	for (int i = 0; i < 15; i++) {
		l.adicionaDuplo(i);
	}
	l.destroiListaDuplo();
	ASSERT_TRUE(l.listaVazia());
}

TEST_F(TesteListaDuplaCirc, Mostra) {
	for (int i = 0; i < 10; i++) {
		l.adicionaDuplo(i*10);
	}
	l.adicionaNaPosicaoDuplo(10, 7);
	ASSERT_EQ(l.mostra(7), 10);
}


TEST_F(TesteListaDuplaCirc, Igual) {
	Objeto obj0(10);
	Objeto obj1(10);
	ASSERT_TRUE(lobj.igual(obj0, obj1));
}

TEST_F(TesteListaDuplaCirc, Maior) {
	Objeto obj0(50);
	Objeto obj1(20);
	ASSERT_TRUE(lobj.maior(obj0, obj1));
}


TEST_F(TesteListaDuplaCirc, Menor) {
	Objeto obj0(20);
	Objeto obj1(50);
	ASSERT_TRUE(lobj.menor(obj0, obj1));
}


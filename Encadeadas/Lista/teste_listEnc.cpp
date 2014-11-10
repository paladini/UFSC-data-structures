#include <stdio.h>
#include <gtest/gtest.h>
#include "ListaEnc.hpp"
int main(int argc, char* argv[]){
	::testing::InitGoogleTest(&argc, argv);
	int y = RUN_ALL_TESTS();
	return y;
}

class Objeto{
public:	
	int v;

	Objeto(){
		
	}

	Objeto(int valor){
		v = valor;
	}

	bool operator==(const Objeto& rhs) const {
		return v == rhs.v;
	}

	bool operator>(const Objeto& rhs) const {
		return v > rhs.v;
	}

	bool operator<(const Objeto& rhs) const {
		return v < rhs.v;
	}

};

class TesteListaEnc: public ::testing::Test{
protected:
	ListaEnc<int> l = ListaEnc<int>();
	ListaEnc<Objeto> lobj = ListaEnc<Objeto>();
};

TEST_F(TesteListaEnc, ListaVazia) {
	ASSERT_TRUE(l.listaVazia());
}

TEST_F(TesteListaEnc, ListaVaziaNeg) {
	l.adiciona(0);
	ASSERT_FALSE(l.listaVazia());
}

TEST_F(TesteListaEnc, AdicionaEmOrdem){
	l.adiciona(0);
	l.adiciona(1);
	l.adicionaEmOrdem(2);
	ASSERT_EQ(l.posicao(2), 2);
}
TEST_F(TesteListaEnc, AdicionaNoInicio){
	l.adiciona(10);
	l.adiciona(20);
	l.adiciona(30);
	l.adicionaNoInicio(9);
	ASSERT_EQ(l.posicao(9), 0);

}

TEST_F(TesteListaEnc, AdicionaNaPosicao){
	l.adiciona(8);
	l.adiciona(8);
	l.adiciona(7);
	l.adiciona(6);
	l.adicionaNaPosicao(9,2);
	ASSERT_EQ(l.posicao(9),2);
}

TEST_F(TesteListaEnc, Contem) {
	for (int i = 0; i < 5; i++) {
		l.adiciona(i * 5);
	}
	ASSERT_TRUE(l.contem(10));
}

TEST_F(TesteListaEnc, ContemNeg) {
	l.adiciona(0);
	l.adiciona(2);
	ASSERT_FALSE(l.contem(9));
}

TEST_F(TesteListaEnc, IgualObj) {
	Objeto obj0(10);
	Objeto obj1(10);
	ASSERT_TRUE(lobj.igual(obj0, obj1));
}

TEST_F(TesteListaEnc, MenorObj) {
	Objeto obj0(10);
	Objeto obj1(20);
	ASSERT_TRUE(lobj.menor(obj0, obj1));
}

TEST_F(TesteListaEnc, MaiorObj) {
	Objeto obj0(20);
	Objeto obj1(10);
	ASSERT_TRUE(lobj.maior(obj0, obj1));
}

TEST_F(TesteListaEnc, destroiLista) {
	l.adiciona(0);
	l.adiciona(1);
	l.adiciona(2);
	l.destroiLista();
	ASSERT_TRUE(l.listaVazia());
}

TEST_F(TesteListaEnc, Posicao) {
	for (int i = 0; i < 10; i++) {
		l.adicionaEmOrdem(i);
	}
	ASSERT_EQ(l.posicao(9), 9);
}

TEST_F(TesteListaEnc, PosicaoNeg) {
	for (int i = 0; i < 10; i++) {
		l.adiciona(i * 2);
	}
	EXPECT_ANY_THROW(l.posicao(3));
}

TEST_F(TesteListaEnc, Retira) {
	for (int i = 0; i < 10; i++) {
		l.adiciona(i);
	}
	ASSERT_EQ(l.retira(), 9);
}

TEST_F(TesteListaEnc, RetiraObj) {
	Objeto obj0(20);
	Objeto obj1(10);
	Objeto obj2(40);
	lobj.adiciona(obj0);
	lobj.adiciona(obj1);
	lobj.adiciona(obj2);
	ASSERT_EQ(lobj.retira(), obj2);

}

TEST_F(TesteListaEnc, RetiraDoInicio) {
	Objeto obj0(20);
	Objeto obj1(10);
	Objeto obj2(40);
	lobj.adiciona(obj0);
	lobj.adiciona(obj1);
	lobj.adiciona(obj2);
	lobj.retiraDoInicio();
	ASSERT_EQ(lobj.retiraDoInicio(), obj1);
}

TEST_F(TesteListaEnc, RetiraEspecifico) {
	Objeto obj0(0);
	Objeto obj1(1);
	Objeto obj2(2);
	Objeto obj3(3);
	Objeto obj4(4);

	lobj.adiciona(obj0);
	lobj.adiciona(obj1);
	lobj.adiciona(obj2);
	lobj.adiciona(obj3);
	lobj.adiciona(obj4);
	ASSERT_EQ(lobj.retiraEspecifico(obj3), 3);
}


TEST_F(TesteListaEnc, Igual) {
	Objeto obj0(10);
	Objeto obj1(10);
	ASSERT_TRUE(lobj.igual(obj0, obj1));
}

TEST_F(TesteListaEnc, Maior) {
	Objeto obj0(50);
	Objeto obj1(20);
	ASSERT_TRUE(lobj.maior(obj0, obj1));
}


TEST_F(TesteListaEnc, Menor) {
	Objeto obj0(20);
	Objeto obj1(50);
	ASSERT_TRUE(lobj.menor(obj0, obj1));
}

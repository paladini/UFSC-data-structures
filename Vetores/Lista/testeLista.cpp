#include <stdio.h>
#include <gtest/gtest.h>
#include "Lista.hpp"
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

class TesteLista: public ::testing::Test{
protected:
	Lista<int> l = Lista<int>(10);
	Lista<Objeto> lobj = Lista<Objeto>(100);
};

TEST_F(TesteLista, ListaCheia){
	for (int i = 0; i < 10; i++) {
		l.adiciona(i);
	}
	ASSERT_TRUE(l.listaCheia());
}

TEST_F(TesteLista, ListaVazia) {
	ASSERT_TRUE(l.listaVazia());
}

TEST_F(TesteLista, ListaVaziaNeg) {
	l.adiciona(0);
	ASSERT_FALSE(l.listaVazia());
}

TEST_F(TesteLista, AdicionaEmOrdem){
	l.adiciona(0);
	l.adiciona(1);
	l.adicionaEmOrdem(2);
	ASSERT_EQ(l.posicao(2), 2);
}
TEST_F(TesteLista, AdicionaNoInicio){
	l.adiciona(10);
	l.adiciona(20);
	l.adiciona(30);
	l.adicionaNoInicio(9);
	ASSERT_EQ(l.posicao(9), 0);

}

TEST_F(TesteLista, AdicionaNaPosicao){
	l.adiciona(8);
	l.adiciona(8);
	l.adiciona(7);
	l.adiciona(6);
	l.adicionaNaPosicao(9,2);
	ASSERT_EQ(l.posicao(9),2);
}

TEST_F(TesteLista, Contem) {
	for (int i = 0; i < 5; i++) {
		l.adiciona(i * 5);
	}
	ASSERT_TRUE(l.contem(10));
}

TEST_F(TesteLista, ContemNeg) {
	l.adiciona(0);
	l.adiciona(2);
	ASSERT_FALSE(l.contem(9));
}

TEST_F(TesteLista, IgualObj) {
	Objeto obj0(10);
	Objeto obj1(10);
	ASSERT_TRUE(lobj.igual(obj0, obj1));
}

TEST_F(TesteLista, MenorObj) {
	Objeto obj0(10);
	Objeto obj1(20);
	ASSERT_TRUE(lobj.menor(obj0, obj1));
}

TEST_F(TesteLista, MaiorObj) {
	Objeto obj0(20);
	Objeto obj1(10);
	ASSERT_TRUE(lobj.maior(obj0, obj1));
}

TEST_F(TesteLista, destroiLista) {
	l.adiciona(0);
	l.adiciona(1);
	l.adiciona(2);
	l.destroiLista();
	ASSERT_TRUE(l.listaVazia());
}

TEST_F(TesteLista, Posicao) {
	for (int i = 0; i < 10; i++) {
		l.adicionaEmOrdem(i);
	}
	ASSERT_EQ(l.posicao(9), 9);
}

TEST_F(TesteLista, PosicaoNeg) {
	for (int i = 0; i < 10; i++) {
		l.adiciona(i * 2);
	}
	EXPECT_ANY_THROW(l.posicao(3));
}

TEST_F(TesteLista, Retira) {
	for (int i = 0; i < 10; i++) {
		l.adiciona(i);
	}
	ASSERT_EQ(l.retira(), 9);
}

TEST_F(TesteLista, RetiraObj) {
	Objeto obj0(20);
	Objeto obj1(10);
	Objeto obj2(40);
	lobj.adiciona(obj0);
	lobj.adiciona(obj1);
	lobj.adiciona(obj2);
	ASSERT_EQ(lobj.retira(), obj2);

}

TEST_F(TesteLista, RetiraDoInicio) {
	Objeto obj0(20);
	Objeto obj1(10);
	Objeto obj2(40);
	lobj.adiciona(obj0);
	lobj.adiciona(obj1);
	lobj.adiciona(obj2);
	lobj.retiraDoInicio();
	ASSERT_EQ(lobj.retiraDoInicio(), obj1);
}

TEST_F(TesteLista, RetiraEspecifico) {
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
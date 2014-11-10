#include <stdio.h>
#include <gtest/gtest.h>
#include "ListaDupla.hpp"
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
	ListaDupla<int> l = ListaDupla<int>();
	ListaDupla<Objeto> lobj = ListaDupla<Objeto>();
};

TEST_F(TesteLista, ListaVaziaDuplo) {
	ASSERT_TRUE(l.listaVazia());
}

TEST_F(TesteLista, ListaVaziaNegDuplo) {
	l.adicionaDuplo(0);
	ASSERT_FALSE(l.listaVazia());
}

TEST_F(TesteLista, AdicionaEmOrdemDuplo){
	l.adicionaDuplo(0);
	l.adicionaDuplo(1);
	l.adicionaEmOrdem(2);
	ASSERT_EQ(l.posicaoDuplo(2), 2);
}
TEST_F(TesteLista, AdicionaNoInicioDuplo){
	l.adicionaDuplo(10);
	l.adicionaDuplo(20);
	l.adicionaDuplo(30);
	l.adicionaNoInicioDuplo(9);
	ASSERT_EQ(l.posicaoDuplo(9), 0);

}

TEST_F(TesteLista, AdicionaNaPosicaoDuplo){
	l.adicionaDuplo(8);
	l.adicionaDuplo(8);
	l.adicionaDuplo(7);
	l.adicionaDuplo(6);
	l.adicionaNaPosicaoDuplo(9,2);
	ASSERT_EQ(l.posicaoDuplo(9),2);
}

TEST_F(TesteLista, ContemDuplo) {
	for (int i = 0; i < 5; i++) {
		l.adicionaDuplo(i * 5);
	}
	ASSERT_TRUE(l.contemDuplo(10));
}

TEST_F(TesteLista, ContemNegDuplo) {
	l.adicionaDuplo(0);
	l.adicionaDuplo(2);
	ASSERT_FALSE(l.contemDuplo(9));
}

TEST_F(TesteLista, IgualObjDuplo) {
	Objeto obj0(10);
	Objeto obj1(10);
	ASSERT_TRUE(lobj.igual(obj0, obj1));
}

TEST_F(TesteLista, MenorObjDuplo) {
	Objeto obj0(10);
	Objeto obj1(20);
	ASSERT_TRUE(lobj.menor(obj0, obj1));
}

TEST_F(TesteLista, MaiorObjDuplo) {
	Objeto obj0(20);
	Objeto obj1(10);
	ASSERT_TRUE(lobj.maior(obj0, obj1));
}

TEST_F(TesteLista, destroiListaDuplo) {
	l.adicionaDuplo(0);
	l.adicionaDuplo(1);
	l.adicionaDuplo(2);
	l.destroiListaDuplo();
	ASSERT_TRUE(l.listaVazia());
}

TEST_F(TesteLista, PosicaoDuplo) {
	for (int i = 0; i < 10; i++) {
		l.adicionaEmOrdem(i);
	}
	ASSERT_EQ(l.posicaoDuplo(9), 9);
}

TEST_F(TesteLista, PosicaoNegDuplo) {
	for (int i = 0; i < 10; i++) {
		l.adicionaDuplo(i * 2);
	}
	EXPECT_ANY_THROW(l.posicaoDuplo(3));
}

TEST_F(TesteLista, RetiraDuplo) {
	for (int i = 0; i < 10; i++) {
		l.adicionaDuplo(i);
	}
	ASSERT_EQ(l.retiraDuplo(), 9);
}

TEST_F(TesteLista, RetiraObjDuplo) {
	Objeto obj0(20);
	Objeto obj1(10);
	Objeto obj2(40);
	lobj.adicionaDuplo(obj0);
	lobj.adicionaDuplo(obj1);
	lobj.adicionaDuplo(obj2);
	ASSERT_EQ(lobj.retiraDuplo(), obj2);

}

TEST_F(TesteLista, retiraDoInicioDuplo) {
	Objeto obj0(20);
	Objeto obj1(10);
	Objeto obj2(40);
	lobj.adicionaDuplo(obj0);
	lobj.adicionaDuplo(obj1);
	lobj.adicionaDuplo(obj2);
	lobj.retiraDoInicioDuplo();
	ASSERT_EQ(lobj.retiraDoInicioDuplo(), obj1);
}

TEST_F(TesteLista, retiraEspecificoDuplo) {
	Objeto obj0(0);
	Objeto obj1(1);
	Objeto obj2(2);
	Objeto obj3(3);
	Objeto obj4(4);

	lobj.adicionaDuplo(obj0);
	lobj.adicionaDuplo(obj1);
	lobj.adicionaDuplo(obj2);
	lobj.adicionaDuplo(obj3);
	lobj.adicionaDuplo(obj4);
	ASSERT_EQ(lobj.retiraEspecificoDuplo(obj3), 3);
}

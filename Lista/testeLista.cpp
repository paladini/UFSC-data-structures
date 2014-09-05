#include <stdio.h>
#include <gtest/gtest.h>
#include "Lista.hpp"
int main(int argc, char* argv[]){
	::testing::InitGoogleTest(&argc, argv);
	int y = RUN_ALL_TESTS();
	return y;
}
class TesteLista: public ::testing::Test{
protected:
	Lista<int> l = Lista<int>(10);
};
TEST_F(TesteLista, ListaCheia){
	l.adiciona(0);
	l.adiciona(1);
	l.adiciona(2);
	l.adiciona(3);
	l.adiciona(4);
	l.adiciona(5);
	l.adiciona(6);
	l.adiciona(7);
	l.adiciona(8);
	l.adiciona(9);
	ASSERT_TRUE(l.listaCheia());
}
TEST_F(TesteLista, AdicionaEmOrdem){
	l.adicionaEmOrdem(1);
	l.adicionaEmOrdem(2);
	ASSERT_EQ(l.posicao(1), 0);
	ASSERT_EQ(l.posicao(2), 1);
}
TEST_F(TesteLista, AdicionaNoInicio){
	l.adiciona(6);
	l.adiciona(8);
	l.adiciona(20);
	l.adicionaNoInicio(9);
	ASSERT_EQ(l.posicao(9), 0);

}
TEST_F(TesteLista, AdicionaNaPosicao){
	l.adiciona(8);
	l.adiciona(8);
	l.adiciona(7);
	l.adiciona(6);
	l.adicionaNaPosicao(9,3);
	ASSERT_EQ(l.posicao(9),3);
}
TEST_F(TesteLista, adicionaEmOrdem){
	l.adiciona(9);
	l.adiciona(8);
	l.adiciona(7);
	l.adiciona(6);
	l.adicionaEmOrdem(5);
	ASSERT_EQ(l.posicao(5), 4);
}

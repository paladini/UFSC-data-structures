/* Copyleft [2014] <Fernando Paladini, Emmanuel Podestá Junior>
 * TesteFila.cpp
 */

#include <stdio.h>
#include <gtest/gtest.h>
#include "../Fila.hpp"
#include "Objeto.hpp"

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    int a = RUN_ALL_TESTS();
    return a;
}

class TesteFila: public ::testing::Test{
 protected:
    Fila<int> fila = Fila<int>(10);
    Fila<Objeto> filaobj = Fila<Objeto>(100);
};

TEST_F(TesteFila, FilaVazia) {
    ASSERT_TRUE(fila.filaVazia());
}

TEST_F(TesteFila, ExcecaoFilaVaziaElementoComplexo) {
	EXPECT_ANY_THROW(filaobj.retira());
}

TEST_F(TesteFila, InsereElemento) {
	fila.inclui(0);
	ASSERT_EQ(0, fila.ultimo());
}

TEST_F(TesteFila, InsereElementoComplexo) {
	Objeto objeto(10);
	filaobj.inclui(objeto);
	ASSERT_EQ(objeto, filaobj.ultimo());
}

TEST_F(TesteFila, FilaCheia) {
	fila.inclui(0);
	fila.inclui(1);
	fila.inclui(2);
	fila.inclui(3);
	fila.inclui(4);
	fila.inclui(5);
	fila.inclui(6);
	fila.inclui(7);
	fila.inclui(8);
	fila.inclui(9);
	ASSERT_TRUE(fila.filaCheia());
}

TEST_F(TesteFila, FilaCheiaElementosComplexos) {
	for(int i = 0; i < 100; i++){
		Objeto objeto(i);
		filaobj.inclui(objeto);
	}
	ASSERT_TRUE(filaobj.filaCheia());
}


TEST_F(TesteFila, RetiraIndiceUltimo) {
	fila.inclui(0);
	fila.inclui(1);

    fila.retira(); // deve ser o "0"
	ASSERT_EQ(0, fila.getUltimo());
}

TEST_F(TesteFila, RetiraValorUltimo) {
	fila.inclui(0);
	fila.inclui(1);

    fila.retira();
	ASSERT_EQ(1, fila.ultimo());
}

TEST_F(TesteFila, RetiraRetornandoElementoRetirado) {
	int zero = 0;
	fila.inclui(zero);
	fila.inclui(1);

	int dadoRetirado = fila.retira(); // deve ser o "0"
	ASSERT_EQ(&zero, &dadoRetirado);
}

TEST_F(TesteFila, Ultimo) {
	fila.inclui(0);
	fila.inclui(1);
	ASSERT_EQ(1, fila.ultimo());
}

TEST_F(TesteFila, UltimaPosicao) {
	fila.inclui(0);
	fila.inclui(1);
	fila.inclui(2);
	ASSERT_EQ(2, fila.getUltimo());
}

TEST_F(TesteFila, UltimaPosicaoElementoComplexo){
	Objeto obj0(10);
	Objeto obj1(5);
	Objeto obj2(2);

	filaobj.inclui(obj0);
	filaobj.inclui(obj1);
	filaobj.inclui(obj2);
	ASSERT_EQ(2, fila.getUltimo());
}

TEST_F(TesteFila, ExcecaoFilaCheia) {
	fila.inclui(0);
	fila.inclui(1);
	fila.inclui(2);
	fila.inclui(3);
	fila.inclui(4);
	fila.inclui(5);
	fila.inclui(6);
	fila.inclui(7);
	fila.inclui(8);
	fila.inclui(9);
	EXPECT_ANY_THROW(fila.inclui(10));
}

TEST_F(TesteFila, ExcecaoFilaCheiaElementoComplexo) {
	for(int i = 0; i < 100; i++){
		Objeto obj(i*2);
		filaobj.inclui(obj);
	}

	Objeto elementoQueEstouraFila(5);
	EXPECT_ANY_THROW(filaobj.inclui(elementoQueEstouraFila));
}


TEST_F(TesteFila, LimpaFila) {
	fila.inclui(0);
	fila.inclui(1);
	fila.inclui(2);
	fila.inclui(3);
	fila.inclui(4);
	fila.inclui(5);
	fila.inicializaFila(); // LimparFila, não sei pq se chama assim
	EXPECT_ANY_THROW(fila.getUltimo());
}

TEST_F(TesteFila, LimpaFilaElementoComplexo){
	for(int i = 0; i < 50; i++){
		Objeto obj(i*4);
		filaobj.inclui(obj);
	}
	filaobj.inicializaFila(); // LimparFila, não sei pq se chama assim
	EXPECT_ANY_THROW(filaobj.getUltimo());
}


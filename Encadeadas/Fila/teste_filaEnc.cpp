/* Copyleft [2014] <Fernando Paladini, Emmanuel Podestá Junior>
 * TesteFila.cpp
 */

#include <stdio.h>
#include <gtest/gtest.h>
#include "FilaEnc.hpp"


int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    int a = RUN_ALL_TESTS();
    return a;
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

};

class TesteFila: public ::testing::Test{
 protected:
    FilaEnc<int> fila = FilaEnc<int>();
    FilaEnc<Objeto> filaobj = FilaEnc<Objeto>();
};

TEST_F(TesteFila, FilaVazia) {
    ASSERT_TRUE(fila.filaVazia());
}

TEST_F(TesteFila, FilaVaziaNeg) {
	fila.inclui(0);
	ASSERT_FALSE(fila.filaVazia());
}

TEST_F(TesteFila, ExcecaoFilaVaziaElementoComplexo) {
	EXPECT_ANY_THROW(filaobj.retira());
}

TEST_F(TesteFila, Inclui) {
	fila.inclui(0);
	ASSERT_EQ(0, fila.ultimo());
}

TEST_F(TesteFila, IncluiComplexo) {
	Objeto objeto(10);
	filaobj.inclui(objeto);
	ASSERT_EQ(objeto, filaobj.ultimo());
}


TEST_F(TesteFila, Primeiro) {
	fila.inclui(0);
	fila.inclui(1);
	ASSERT_EQ(0, fila.primeiro());
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
	ASSERT_EQ(zero, dadoRetirado);
}

TEST_F(TesteFila, Ultimo) {
	fila.inclui(0);
	fila.inclui(1);
	ASSERT_EQ(1, fila.ultimo());
}

TEST_F(TesteFila, LimpaFila) {
	for (int i = 0; i < 10; i++) {
		fila.inclui(i);
	}
	fila.limparFila();
	ASSERT_TRUE(fila.filaVazia());
}

TEST_F(TesteFila, LimpaFilaElementoComplexo){
	for(int i = 0; i < 50; i++){
		Objeto obj(i*4);
		filaobj.inclui(obj);
	}
	filaobj.limparFila(); // LimparFila, não sei pq se chama assim
	EXPECT_ANY_THROW(filaobj.ultimo());
}


/* Copyleft [2014] <Fernando Paladini, Emmanuel Podestá Junior>
 * TesteFila.cpp
 */

#include <stdio.h>
#include <gtest/gtest.h>
#include "Fila.hpp"


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
    Fila<int> fila = Fila<int>(10);
    Fila<Objeto> filaobj = Fila<Objeto>(100);
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

TEST_F(TesteFila, FilaCheia) {
	for (int i = 0; i < 10; i++) {
		fila.inclui(i);
	}
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
	ASSERT_EQ(zero, dadoRetirado);
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

// TEST_F(TesteFila, UltimaPosicaoElementoComplexo){
// 	Objeto obj0(0);
// 	Objeto obj1(1);
// 	Objeto obj2(2);

// 	filaobj.inclui(obj0);
// 	filaobj.inclui(obj1);
// 	filaobj.inclui(obj2);
// 	ASSERT_EQ(2, fila.getUltimo());
// }

TEST_F(TesteFila, ExcecaoFilaCheia) {
	for (int i = 0; i < 10; i++) {
		fila.inclui(i);
	}
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
	for (int i = 0; i < 10; i++) {
		fila.inclui(i);
	}
	fila.inicializaFila(); // LimparFila, não sei pq se chama assim
	ASSERT_TRUE(fila.filaVazia());
}

TEST_F(TesteFila, LimpaFilaElementoComplexo){
	for(int i = 0; i < 50; i++){
		Objeto obj(i*4);
		filaobj.inclui(obj);
	}
	filaobj.inicializaFila(); // LimparFila, não sei pq se chama assim
	EXPECT_ANY_THROW(filaobj.getUltimo());
}


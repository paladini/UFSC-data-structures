/* Copyleft [2014] <Fernando Paladini, Emmanuel Podestá Junior>
 * TestePilha.cpp
 */

#include <gtest/gtest.h>
#include "PilhaEnc.hpp"


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
class TestePilha: public ::testing::Test{
 protected:
    PilhaEnc<int> p = PilhaEnc<int>();
    PilhaEnc<Objeto> pobj = PilhaEnc<Objeto>();
};

TEST_F(TestePilha, PilhaVazia) {
    ASSERT_TRUE(p.PilhaVazia());
}

TEST_F(TestePilha, PilhaVaziaNeg) {
	p.empilha(0);
	ASSERT_FALSE(p.PilhaVazia());
}
TEST_F(TestePilha, Empilha) {
	p.empilha(0);
	p.empilha(1);
	ASSERT_EQ(1, p.topo());
}

TEST_F(TestePilha, Desempilha) {
	p.empilha(0);
	p.empilha(1);
	ASSERT_EQ(1, p.desempilha());
}

TEST_F(TestePilha, Topo) {
	p.empilha(0);
	ASSERT_EQ(0, p.topo());
}

TEST_F(TestePilha, ExcecaoTopo) {
	EXPECT_ANY_THROW(p.topo());
}

TEST_F(TestePilha, ExcecaoDesempilha) {
	EXPECT_ANY_THROW(p.desempilha());
}

TEST_F(TestePilha, LimpaPilha) {
	for (int i = 0; i < 10; i++) {
		p.empilha(i);
	}
	p.limparPilha();
	ASSERT_TRUE(p.PilhaVazia());
}

// Arrumar isso aqui
TEST_F(TestePilha, DesempilhaEComparaPonteiros){
	Objeto objeto1(10);
	Objeto objeto2(7);
	Objeto objeto3(4);
	pobj.empilha(objeto1);
	pobj.empilha(objeto2);
	pobj.empilha(objeto3);

	// Testando se ponteiro confere com o endereço do objeto colocado na pilha
	Objeto obj = pobj.desempilha();
	ASSERT_EQ(objeto3, obj);

	obj = pobj.desempilha();
	ASSERT_EQ(objeto2, obj);

	obj = pobj.desempilha();
	ASSERT_EQ(objeto1, obj);
}

/*TEST_F(TestePilha, ExcecaoPilhaVaziaObjetosComplexos){
	Objeto *objeto1 = new Objeto();
	Objeto *objeto2 = new Objeto();
	Objeto *objeto3 = new Objeto();	
	pobj.empilha(*objeto1);
	pobj.empilha(*objeto2);
	pobj.empilha(*objeto3);
	
	pobj.desempilha();
	pobj.desempilha();
	pobj.desempilha();
	EXPECT_ANY_THROW(pobj.desempilha());
}
*/

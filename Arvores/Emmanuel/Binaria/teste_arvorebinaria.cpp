#include "gtest/gtest.h"
#include "Arvore.hpp"
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	int v = RUN_ALL_TESTS();
	return v;
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
class TesteArvoreBinaria: public ::testing::Test{
 protected:
	NoBinario<int>* arv = new NoBinario<int>(10);
	Objeto obj = Objeto(10);
	NoBinario<Objeto>* arvObj = new NoBinario<Objeto>(obj);
};


TEST_F(TesteArvoreBinaria, Insere) {
	arv->inserir(8, arv);
	arv->inserir(9, arv);
	arv->emOrdem(arv);
	NoBinario<int>* elemento = arv->getElementos();
	ASSERT_EQ(*elemento->getDado(), 8);
	elemento++;
	ASSERT_EQ(*elemento->getDado(), 9);
	elemento++;
	ASSERT_EQ(*elemento->getDado(), 10);
}

TEST_F(TesteArvoreBinaria, RemoverSemFilhos) {
	arv->inserir(9, arv);
	NoBinario<int>* root = arv->remover(arv, 9);
	EXPECT_ANY_THROW(*(arv->busca(9, arv)));
}

TEST_F(TesteArvoreBinaria, RemoverFilhoEsquerda) {
	arv->inserir(8, arv);
	arv->inserir(7, arv);
	NoBinario<int>* root = arv->remover(arv, 8);
	EXPECT_ANY_THROW(*(arv->busca(8, arv)));
	arv->emOrdem(arv);
	NoBinario<int>* elemento = arv->getElementos();
	ASSERT_EQ(*(elemento->getDado()), 7);
}

TEST_F(TesteArvoreBinaria, RemoverFilhoDireita) {
	arv->inserir(8, arv);
	arv->inserir(9, arv);
	NoBinario<int>* root = arv->remover(arv, 8);
	EXPECT_ANY_THROW(*(arv->busca(8, arv)));
	arv->emOrdem(arv);
	NoBinario<int>* elemento = arv->getElementos();
	ASSERT_EQ(*(elemento->getDado()), 9);
}

TEST_F(TesteArvoreBinaria, RemoverDoisFilhos) {
	arv->inserir(8, arv);
	arv->inserir(9, arv);
	arv->inserir(7, arv);
	NoBinario<int>* root = arv->remover(arv, 8);
	arv->emOrdem(arv);
	NoBinario<int>* elemento = arv->getElementos();
	ASSERT_EQ(7, *(elemento->getDado()));
	elemento++;
	ASSERT_EQ(9, *(elemento->getDado()));
}

TEST_F(TesteArvoreBinaria, Busca) {
	arv->inserir(8, arv);
	arv->inserir(9, arv);
	arv->inserir(7, arv);
	ASSERT_EQ(*(arv->busca(9, arv)), 9);
}

TEST_F(TesteArvoreBinaria, BuscaExcecao) {
	arv->inserir(8, arv);
	arv->inserir(7, arv);
	arv->inserir(9, arv);
	EXPECT_ANY_THROW(*(arv->busca(20, arv)));	
}

TEST_F(TesteArvoreBinaria, Minimo) {
	arv->inserir(8, arv);
	arv->inserir(9, arv);
	arv->inserir(11, arv);
	arv->inserir(7, arv);
	NoBinario<int>* root = arv->minimo(arv);
	ASSERT_EQ(*(root->getDado()), 7);
}

TEST_F(TesteArvoreBinaria, EmOrdem) {
	arv->inserir(8, arv);
	arv->inserir(11, arv);
	arv->inserir(20, arv);
	arv->inserir(9, arv);
	arv->inserir(7, arv);
	arv->inserir(6, arv);
	arv->emOrdem(arv);
	NoBinario<int>* elementos = arv->getElementos();
	ASSERT_EQ(6, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(7, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(8, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(9, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(10, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(11, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(20, *(elementos->getDado()));

}

TEST_F(TesteArvoreBinaria, PosOrdem) {
	arv->inserir(8, arv);
	arv->inserir(11, arv);
	arv->inserir(20, arv);
	arv->inserir(9, arv);
	arv->inserir(7, arv);
	arv->inserir(6, arv);
	arv->posOrdem(arv);
	NoBinario<int>* elementos = arv->getElementos();
	ASSERT_EQ(6, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(7, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(9, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(8, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(20, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(11, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(10, *(elementos->getDado()));
}

TEST_F(TesteArvoreBinaria, PreOrdem) {
	arv->inserir(8, arv);
	arv->inserir(11, arv);
	arv->inserir(20, arv);
	arv->inserir(9, arv);
	arv->inserir(7, arv);
	arv->inserir(6, arv);
	arv->preOrdem(arv);
	NoBinario<int>* elementos = arv->getElementos();
	ASSERT_EQ(10, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(8, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(7, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(6, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(9, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(11, *(elementos->getDado()));
	elementos++;
	ASSERT_EQ(20, *(elementos->getDado()));
}
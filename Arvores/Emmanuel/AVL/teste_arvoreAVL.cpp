#include "gtest/gtest.h"
#include "ArvoreAVL.hpp"
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
	ArvoreAVL<int>* arv = new ArvoreAVL<int>(10);
	Objeto obj = Objeto(10);
	ArvoreAVL<Objeto>* arvObj = new ArvoreAVL<Objeto>(obj);
};


TEST_F(TesteArvoreAVL, InsereTestandoRotacaoDupla) {
	arv->insere(arv, 9);
	arv->insere(arv, 5);
	arv->insere(arv, 7);
	arv->insere(arv, 6);
	arv->insere(arv, 11);
	arv->emOrdem(arv);
	NoBinario<int>* elemento = arv->getElementos();
	ASSERT_EQ(*elemento->getDado(), 8);
	elemento++;
	ASSERT_EQ(*elemento->getDado(), 9);
	elemento++;
	ASSERT_EQ(*elemento->getDado(), 10);
}

TEST_F(TesteArvoreBinaria, RemoverSemFilhos) {
	arv->insere(arv, 9);
	NoBinario<int>* root = arv->remove(arv, 9);
	EXPECT_ANY_THROW(*(arv->busca(9, arv)));
}

TEST_F(TesteArvoreBinaria, RemoverFilhoEsquerda) {
	arv->insere(arv, 8);
	arv->insere(arv, 7);
	NoBinario<int>* root = arv->remove(arv, 8);
	EXPECT_ANY_THROW(*(arv->busca(8, arv)));
	arv->emOrdem(arv);
	NoBinario<int>* elemento = arv->getElementos();
	ASSERT_EQ(*(elemento->getDado()), 7);
}

TEST_F(TesteArvoreBinaria, RemoverFilhoDireita) {
	arv->insere(arv, 8);
	arv->insere(arv, 9);
	NoBinario<int>* root = arv->remove(arv, 8);
	EXPECT_ANY_THROW(*(arv->busca(8, arv)));
	arv->emOrdem(arv);
	NoBinario<int>* elemento = arv->getElementos();
	ASSERT_EQ(*(elemento->getDado()), 9);
}

TEST_F(TesteArvoreBinaria, RemoverDoisFilhos) {
	arv->insere(arv, 8);
	arv->insere(arv, 9);
	arv->insere(arv, 7);
	NoBinario<int>* root = arv->remove(arv, 8);
	arv->emOrdem(arv);
	NoBinario<int>* elemento = arv->getElementos();
	ASSERT_EQ(7, *(elemento->getDado()));
	elemento++;
	ASSERT_EQ(9, *(elemento->getDado()));
}

TEST_F(TesteArvoreBinaria, Busca) {
	arv->insere(arv, 8);
	arv->insere(arv, 9);
	arv->insere(arv, 7);
	ASSERT_EQ(*(arv->busca(9, arv)), 9);
}

TEST_F(TesteArvoreBinaria, BuscaExcecao) {
	arv->insere(arv, 8);
	arv->insere(arv, 7);
	arv->insere(arv, 9);
	EXPECT_ANY_THROW(*(arv->busca(20, arv)));	
}

TEST_F(TesteArvoreBinaria, Minimo) {
	arv->insere(arv, 8);
	arv->insere(arv, 9);
	arv->insere(arv, 11);
	arv->insere(arv, 7);
	NoBinario<int>* root = arv->minimo(arv);
	ASSERT_EQ(*(root->getDado()), 7);
}

TEST_F(TesteArvoreBinaria, EmOrdem) {
	arv->insere(arv, 8);
	arv->insere(arv, 11);
	arv->insere(arv, 20);
	arv->insere(arv, 9);
	arv->insere(arv, 7);
	arv->insere(arv, 6);
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
	arv->insere(arv, 8);
	arv->insere(arv, 11);
	arv->insere(arv, 20);
	arv->insere(arv, 9);
	arv->insere(arv, 7);
	arv->insere(arv, 6);
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
	arv->insere(arv, 8);
	arv->insere(arv, 11);
	arv->insere(arv, 20);
	arv->insere(arv, 9);
	arv->insere(arv, 7);
	arv->insere(arv, 6);
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
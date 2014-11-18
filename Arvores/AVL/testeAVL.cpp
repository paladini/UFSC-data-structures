// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota
#include "gtest/gtest.h"
#include "ArvoreAVL.hpp"
#include <cstdlib>
#include <vector>

int main (int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class Objeto {};

class ArvoreAVLTest: public ::testing::Test {
 protected:
    ArvoreAVL<int> *inteiro = new ArvoreAVL<int>(10);
    ArvoreAVL<Objeto> *obj = new ArvoreAVL<Objeto>(Objeto());
};

TEST_F(ArvoreAVLTest, inserir) {
    int h;
    // Rotações à esquerda
    
    for (h = 0; h < 10; h++) {
        ASSERT_NO_THROW(inteiro->insere(inteiro, h));
    }
    ASSERT_EQ(0, *(inteiro->busca(0, inteiro)));
    // for (h = 0; h < 10; h++) {
    //     ASSERT_EQ(h, *(inteiro->busca(h, inteiro)));
    // }
    for (h = 11; h < 20; h++) {
        EXPECT_ANY_THROW(inteiro->busca(h, inteiro));
    }
}

TEST_F(ArvoreAVLTest, insereRotacaoSimplesEsquerda) {
    // ASSERT_NO_THROW(inteiro->inserir(9, inteiro));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 11));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 12));
    //Rotação simples à esquerda
    inteiro->emOrdem(inteiro);
    
    NoBinario<int>* elementos = inteiro->getElementos();
    
    // ASSERT_EQ(1, inteiro->getAltura());
    // ASSERT_EQ(9, *(elementos->getDado()));
    // elementos++;
    ASSERT_EQ(10, *(elementos->getDado()));
    elementos++;
    ASSERT_EQ(11, *(elementos->getDado()));
    elementos++;
    ASSERT_EQ(12, *(elementos->getDado()));
}

TEST_F(ArvoreAVLTest, insereRotacaoSimplesDireita) {
    ASSERT_NO_THROW(inteiro->inserir(9, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    // Rotação simples à direita
    inteiro->emOrdem(inteiro);
    
    NoBinario<int>* elementos = inteiro->getElementos();
    
    // ASSERT_EQ(1, inteiro->getAltura());
    ASSERT_EQ(8, *(elementos->getDado()));
    elementos++;
    ASSERT_EQ(9, *(elementos->getDado()));
    elementos++;
    ASSERT_EQ(10, *(elementos->getDado()));
}

TEST_F(ArvoreAVLTest, insereRotacaoDuplaDireita) {
    ASSERT_NO_THROW(inteiro->inserir(7, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    // Rotação dupla à direita
    inteiro->emOrdem(inteiro);
    
    NoBinario<int>* elementos = inteiro->getElementos();
    
    ASSERT_EQ(7, *(elementos->getDado()));
    elementos++;
    ASSERT_EQ(8, *(elementos->getDado()));
    elementos++;
    ASSERT_EQ(10, *(elementos->getDado()));
}

TEST_F(ArvoreAVLTest, insereRotacaoDuplaEsquerda) {
    ASSERT_NO_THROW(inteiro->inserir(12, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(11, inteiro));
    // Rotação dupla à esquerda
    inteiro->emOrdem(inteiro);
    
    NoBinario<int>* elementos = inteiro->getElementos();
    
    ASSERT_EQ(10, *(elementos->getDado()));
    elementos++;
    ASSERT_EQ(11, *(elementos->getDado()));
    elementos++;
    ASSERT_EQ(12, *(elementos->getDado()));
}

TEST_F(ArvoreAVLTest, remover) {
    int h;
    for (h = 0; h < 10; h++) {
        ASSERT_NO_THROW(inteiro->inserir(h, inteiro));
    }
    
    for (h = 0; h < 10; h++) {
        ASSERT_EQ(h, *(inteiro->busca(h, inteiro)));
    }
    
    for (h = 0; h < 10; h++) {
        ASSERT_NO_THROW(inteiro->remover(inteiro, h));
    }
    
    for (h = 0; h < 10; h++) {
        ASSERT_ANY_THROW(inteiro->busca(h, inteiro));
    }
}

TEST_F(ArvoreAVLTest, busca) {
    int h;
    for(h = 0; h < 10; h++) {
        ASSERT_NO_THROW(inteiro->inserir(h, inteiro));
    }
    
    for(h = 0; h < 10; h++) {
        ASSERT_EQ(h, *(inteiro->busca(h, inteiro)));
    }
    
    for (h = 11; h < 20; h++) {
        ASSERT_ANY_THROW(inteiro->busca(h, inteiro));
    }
}

TEST_F(ArvoreAVLTest, minimo) {
    int h;
    ASSERT_EQ(10, *(inteiro->minimo(inteiro)->getDado()));
    for (h = 9; h >= 0; h--) {
        ASSERT_NO_THROW(inteiro->inserir(h, inteiro));
        ASSERT_EQ(h, *(inteiro->minimo(inteiro)->getDado()));
    }
}

TEST_F(ArvoreAVLTest, getAltura) {
    // ASSERT_EQ(0, inteiro->getAltura());
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(12, inteiro));
    // ASSERT_EQ(1, inteiro->getAltura());
    
    ASSERT_NO_THROW(inteiro->inserir(9, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(11, inteiro));
    // ASSERT_EQ(1, inteiro->getAltura());
    
    ASSERT_NO_THROW(inteiro->inserir(7, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(13, inteiro));
    // ASSERT_EQ(1, inteiro->getAltura());
}

TEST_F(ArvoreAVLTest, removerRotacaoSimplesDireita) {
    ASSERT_NO_THROW(inteiro->inserir(5, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(15, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(14, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(16, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(6, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(13, inteiro));
    ASSERT_NO_THROW(inteiro->remover(inteiro, 15));
    // Rotação simples à direita
    inteiro->emOrdem(inteiro);
    
    NoBinario<int>* elementos = inteiro->getElementos();
    
    //ASSERT_EQ(1, inteiro->getAltura());
    ASSERT_EQ(5, *(elementos->getDado()));
    elementos++; 

    ASSERT_EQ(6, *(elementos->getDado()));
    elementos++; 

    ASSERT_EQ(10, *(elementos->getDado()));
    elementos++; 

    ASSERT_EQ(13, *(elementos->getDado()));
    elementos++; 

    ASSERT_EQ(14, *(elementos->getDado()));
    elementos++; 

    ASSERT_EQ(16, *(elementos->getDado()));
}

TEST_F(ArvoreAVLTest, removerRotacaoDuplaDireita) {
    ASSERT_NO_THROW(inteiro->insere(inteiro, 4));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 15));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 14));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 17));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 6));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 20));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 13));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 25));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 7));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 8));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 2));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 26));
    ASSERT_NO_THROW(inteiro->insere(inteiro, 18));
    ASSERT_NO_THROW(inteiro->remove(inteiro, 26));
    ASSERT_NO_THROW(inteiro->remove(inteiro, 25));
    // Rotação dupla à direita
    inteiro->emOrdem(inteiro);
    
    NoBinario<int>* elementos = inteiro->getElementos();
    
    ASSERT_EQ(2, *(elementos->getDado()));
    elementos++;

    ASSERT_EQ(4, *(elementos->getDado()));
    elementos++;

    ASSERT_EQ(6, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(7, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(8, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(10, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(13, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(14, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(15, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(17, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(18, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(20, *(elementos->getDado()));
}

TEST_F(ArvoreAVLTest, removerRotacaoDuplaEsquerda) {
    ASSERT_NO_THROW(inteiro->inserir(4, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(15, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(14, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(17, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(6, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(20, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(13, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(25, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(7, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(8, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(2, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(26, inteiro));
    ASSERT_NO_THROW(inteiro->inserir(16, inteiro));
    ASSERT_NO_THROW(inteiro->remover(inteiro, 14));
    ASSERT_NO_THROW(inteiro->remover(inteiro, 13));
    // Rotação dupla à esquerda
    inteiro->emOrdem(inteiro);
    
    NoBinario<int>* elementos = inteiro->getElementos();
    
    ASSERT_EQ(2, *(elementos->getDado()));
    elementos++;

    ASSERT_EQ(4, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(6, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(7, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(8, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(10, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(15, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(16, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(17, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(20, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(25, *(elementos->getDado()));
    elementos++;
    
    ASSERT_EQ(26, *(elementos->getDado()));
}
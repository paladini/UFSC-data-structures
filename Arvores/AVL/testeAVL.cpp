// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#include <vector>
#include "gtest/gtest.h"
#include "ArvoreAVL.hpp"

int main(int argc, char **argv) {
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
    // Rotações à Direita
    for (h = 1; h < 10; h++) {
        inteiro = inteiro->inserir(h, inteiro);
    }
    for (h = 1; h < 11; h++) {
        ASSERT_EQ(h, *(inteiro->busca(h, inteiro)));
    }
    for (h = 11; h < 20; h++) {
        ASSERT_ANY_THROW(inteiro->busca(h, inteiro));
    }
}

TEST_F(ArvoreAVLTest, insereRotacaoSimplesDireita) {
    inteiro = inteiro->inserir(11, inteiro);
    inteiro = inteiro->inserir(12, inteiro);

    // Rotação simples à Direita
    inteiro->emOrdem(inteiro);

    std::vector<ArvoreAVL<int>* > elementos = inteiro->getElementos();

    ASSERT_EQ(1, inteiro->getAltura());
    ASSERT_EQ(10, *(elementos[0]->getDado()));
    ASSERT_EQ(11, *(elementos[1]->getDado()));
    ASSERT_EQ(12, *(elementos[2]->getDado()));
}

TEST_F(ArvoreAVLTest, insereRotacaoSimplesEsquerda) {
    inteiro = inteiro->inserir(9, inteiro);
    inteiro = inteiro->inserir(8, inteiro);
    // Rotação simples à Direita
    inteiro->emOrdem(inteiro);

    std::vector<ArvoreAVL<int>* > elementos = inteiro->getElementos();

    ASSERT_EQ(1, inteiro->getAltura());
    ASSERT_EQ(8, *(elementos[0]->getDado()));
    ASSERT_EQ(9, *(elementos[1]->getDado()));
    ASSERT_EQ(10, *(elementos[2]->getDado()));
}

TEST_F(ArvoreAVLTest, insereRotacaoDuplaEsquerda) {
    inteiro = inteiro->inserir(7, inteiro);
    inteiro = inteiro->inserir(8, inteiro);
    // Rotação dupla à Direita
    inteiro->emOrdem(inteiro);

    std::vector<ArvoreAVL<int>* > elementos = inteiro->getElementos();

    ASSERT_EQ(1, inteiro->getAltura());
    ASSERT_EQ(7, *(elementos[0]->getDado()));
    ASSERT_EQ(8, *(elementos[1]->getDado()));
    ASSERT_EQ(10, *(elementos[2]->getDado()));
}

TEST_F(ArvoreAVLTest, insereRotacaoDuplaDireita) {
    inteiro = inteiro->inserir(12, inteiro);
    inteiro = inteiro->inserir(11, inteiro);
    // Rotação dupla à Direita
    inteiro->emOrdem(inteiro);

    std::vector<ArvoreAVL<int>* > elementos = inteiro->getElementos();

    ASSERT_EQ(1, inteiro->getAltura());
    ASSERT_EQ(10, *(elementos[0]->getDado()));
    ASSERT_EQ(11, *(elementos[1]->getDado()));
    ASSERT_EQ(12, *(elementos[2]->getDado()));
}

TEST_F(ArvoreAVLTest, removerRotacaoSimplesDireita) {
    inteiro = inteiro->inserir(5, inteiro);
    inteiro = inteiro->inserir(15, inteiro);
    inteiro = inteiro->inserir(14, inteiro);
    inteiro = inteiro->inserir(16, inteiro);
    inteiro = inteiro->inserir(6, inteiro);
    inteiro = inteiro->inserir(17, inteiro);
    inteiro = inteiro->inserir(13, inteiro);
    inteiro = inteiro->inserir(18, inteiro);
    inteiro = inteiro->inserir(7, inteiro);
    inteiro = inteiro->inserir(8, inteiro);
    inteiro = inteiro->inserir(3, inteiro);
    inteiro = inteiro->inserir(19, inteiro);
    inteiro = inteiro->remover(inteiro, 15);
    // Rotação simples à Direita
    inteiro->emOrdem(inteiro);

    std::vector<ArvoreAVL<int>* > elementos = inteiro->getElementos();

    ASSERT_EQ(3, inteiro->getAltura());
    ASSERT_EQ(3, *(elementos[0]->getDado()));
    ASSERT_EQ(5, *(elementos[1]->getDado()));
    ASSERT_EQ(6, *(elementos[2]->getDado()));
    ASSERT_EQ(7, *(elementos[3]->getDado()));
    ASSERT_EQ(8, *(elementos[4]->getDado()));
    ASSERT_EQ(10, *(elementos[5]->getDado()));
    ASSERT_EQ(13, *(elementos[6]->getDado()));
    ASSERT_EQ(14, *(elementos[7]->getDado()));
    ASSERT_EQ(16, *(elementos[8]->getDado()));
    ASSERT_EQ(17, *(elementos[9]->getDado()));
    ASSERT_EQ(18, *(elementos[10]->getDado()));
    ASSERT_EQ(19, *(elementos[11]->getDado()));
}

TEST_F(ArvoreAVLTest, removerRotacaoSimplesEsquerda) {
    inteiro = inteiro->inserir(5, inteiro);
    inteiro = inteiro->inserir(15, inteiro);
    inteiro = inteiro->inserir(14, inteiro);
    inteiro = inteiro->inserir(16, inteiro);
    inteiro = inteiro->inserir(6, inteiro);
    inteiro = inteiro->inserir(13, inteiro);
    inteiro = inteiro->remover(inteiro, 15);
    // Rotação simples à Direita
    inteiro->emOrdem(inteiro);

    std::vector<ArvoreAVL<int>* > elementos = inteiro->getElementos();

    ASSERT_EQ(2, inteiro->getAltura());
    ASSERT_EQ(5, *(elementos[0]->getDado()));
    ASSERT_EQ(6, *(elementos[1]->getDado()));
    ASSERT_EQ(10, *(elementos[2]->getDado()));
    ASSERT_EQ(13, *(elementos[3]->getDado()));
    ASSERT_EQ(14, *(elementos[4]->getDado()));
    ASSERT_EQ(16, *(elementos[5]->getDado()));
}

TEST_F(ArvoreAVLTest, removerRotacaoDuplaEsquerda) {
    inteiro = inteiro->inserir(4, inteiro);
    inteiro = inteiro->inserir(15, inteiro);
    inteiro = inteiro->inserir(14, inteiro);
    inteiro = inteiro->inserir(17, inteiro);
    inteiro = inteiro->inserir(6, inteiro);
    inteiro = inteiro->inserir(20, inteiro);
    inteiro = inteiro->inserir(13, inteiro);
    inteiro = inteiro->inserir(25, inteiro);
    inteiro = inteiro->inserir(7, inteiro);
    inteiro = inteiro->inserir(8, inteiro);
    inteiro = inteiro->inserir(2, inteiro);
    inteiro = inteiro->inserir(26, inteiro);
    inteiro = inteiro->inserir(18, inteiro);
    inteiro = inteiro->remover(inteiro, 26);
    inteiro = inteiro->remover(inteiro, 25);
    // Rotação dupla à Direita
    inteiro->emOrdem(inteiro);

    std::vector<ArvoreAVL<int>* > elementos = inteiro->getElementos();

    ASSERT_EQ(3, inteiro->getAltura());
    ASSERT_EQ(2, *(elementos[0]->getDado()));
    ASSERT_EQ(4, *(elementos[1]->getDado()));
    ASSERT_EQ(6, *(elementos[2]->getDado()));
    ASSERT_EQ(7, *(elementos[3]->getDado()));
    ASSERT_EQ(8, *(elementos[4]->getDado()));
    ASSERT_EQ(10, *(elementos[5]->getDado()));
    ASSERT_EQ(13, *(elementos[6]->getDado()));
    ASSERT_EQ(14, *(elementos[7]->getDado()));
    ASSERT_EQ(15, *(elementos[8]->getDado()));
    ASSERT_EQ(17, *(elementos[9]->getDado()));
    ASSERT_EQ(18, *(elementos[10]->getDado()));
    ASSERT_EQ(20, *(elementos[11]->getDado()));
}


TEST_F(ArvoreAVLTest, insercao1) {
    inteiro = inteiro->inserir(1, inteiro);
    inteiro = inteiro->inserir(2, inteiro);

    ASSERT_EQ(2,  *(inteiro->getDado()));
    ASSERT_EQ(1,  *(inteiro->getEsquerda()->getDado()));
    ASSERT_EQ(10, *(inteiro->getDireita()->getDado()));
}


TEST_F(ArvoreAVLTest, insercao) {
    inteiro = inteiro->inserir(1, inteiro);
    inteiro = inteiro->inserir(2, inteiro);
    inteiro = inteiro->inserir(3, inteiro);
    inteiro = inteiro->inserir(4, inteiro);
    inteiro = inteiro->inserir(5, inteiro);
    inteiro = inteiro->inserir(6, inteiro);
    inteiro = inteiro->inserir(7, inteiro);
    inteiro = inteiro->inserir(8, inteiro);
    inteiro = inteiro->inserir(9, inteiro);

    ASSERT_EQ(4, *(inteiro->getDado()));
    ASSERT_EQ(2, *(inteiro->getEsquerda()->getDado()));
    ASSERT_EQ(1, *(inteiro->getEsquerda()->getEsquerda()->getDado()));
    ASSERT_EQ(3, *(inteiro->getEsquerda()->getDireita()->getDado()));

    ASSERT_EQ(8, *(inteiro->getDireita()->getDado()));
    ASSERT_EQ(6, *(inteiro->getDireita()->getEsquerda()->getDado()));
    ASSERT_EQ(5, *(inteiro->getDireita()->getEsquerda()->getEsquerda()->getDado()));
    ASSERT_EQ(7, *(inteiro->getDireita()->getEsquerda()->getDireita()->getDado()));

    ASSERT_EQ(10, *(inteiro->getDireita()->getDireita()->getDado()));
    ASSERT_EQ(9,  *(inteiro->getDireita()->getDireita()->getEsquerda()->getDado()));
}

TEST_F(ArvoreAVLTest, removerRotacaoDuplaDireita) {
    inteiro = inteiro->inserir(4, inteiro);
    inteiro = inteiro->inserir(15, inteiro);
    inteiro = inteiro->inserir(14, inteiro);
    inteiro = inteiro->inserir(17, inteiro);
    inteiro = inteiro->inserir(6, inteiro);
    inteiro = inteiro->inserir(20, inteiro);
    inteiro = inteiro->inserir(13, inteiro);
    inteiro = inteiro->inserir(25, inteiro);
    inteiro = inteiro->inserir(7, inteiro);
    inteiro = inteiro->inserir(8, inteiro);
    inteiro = inteiro->inserir(2, inteiro);
    inteiro = inteiro->inserir(26, inteiro);
    inteiro = inteiro->inserir(16, inteiro);
    inteiro = inteiro->remover(inteiro, 14);
    inteiro = inteiro->remover(inteiro, 13);
    // Rotação dupla à Direita
    inteiro->emOrdem(inteiro);

    std::vector<ArvoreAVL<int>* > elementos = inteiro->getElementos();

    ASSERT_EQ(3, inteiro->getAltura());
    ASSERT_EQ(2, *(elementos[0]->getDado()));
    ASSERT_EQ(4, *(elementos[1]->getDado()));
    ASSERT_EQ(6, *(elementos[2]->getDado()));
    ASSERT_EQ(7, *(elementos[3]->getDado()));
    ASSERT_EQ(8, *(elementos[4]->getDado()));
    ASSERT_EQ(10, *(elementos[5]->getDado()));
    ASSERT_EQ(15, *(elementos[6]->getDado()));
    ASSERT_EQ(16, *(elementos[7]->getDado()));
    ASSERT_EQ(17, *(elementos[8]->getDado()));
    ASSERT_EQ(20, *(elementos[9]->getDado()));
    ASSERT_EQ(25, *(elementos[10]->getDado()));
    ASSERT_EQ(26, *(elementos[11]->getDado()));
}


TEST_F(ArvoreAVLTest, remover) {
    int h;
    for (h = 0; h < 10; h++) {
        inteiro = inteiro->inserir(h, inteiro);
    }

    for (h = 0; h < 10; h++) {
        ASSERT_EQ(h, *(inteiro->busca(h, inteiro)));
    }

    for (h = 0; h < 10; h++) {
        inteiro = inteiro->remover(inteiro, h);
    }

    for (h = 0; h < 10; h++) {
        ASSERT_ANY_THROW(inteiro->busca(h, inteiro));
    }
}

TEST_F(ArvoreAVLTest, busca) {
    int h;
    for (h = 0; h < 10; h++) {
        inteiro = inteiro->inserir(h, inteiro);
    }

    for (h = 0; h < 10; h++) {
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
        inteiro = inteiro->inserir(h, inteiro);
        ASSERT_EQ(h, *(inteiro->minimo(inteiro)->getDado()));
    }
}

TEST_F(ArvoreAVLTest, getAltura) {
    ASSERT_EQ(0, inteiro->getAltura());
    inteiro = inteiro->inserir(8, inteiro);
    inteiro = inteiro->inserir(12, inteiro);
    ASSERT_EQ(1, inteiro->getAltura());

    inteiro = inteiro->inserir(9, inteiro);
    inteiro = inteiro->inserir(11, inteiro);
    ASSERT_EQ(2, inteiro->getAltura());

    inteiro = inteiro->inserir(7, inteiro);
    inteiro = inteiro->inserir(13, inteiro);
    ASSERT_EQ(2, inteiro->getAltura());
}
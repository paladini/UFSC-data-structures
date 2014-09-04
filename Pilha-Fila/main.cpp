/* 
 * File:   main.cpp
 * Author: podesta
 * 
 * Created on 20 de Agosto de 2014, 18:41
 */

#include "main.h"
#include "Pilha.hpp"
#include "Fila.hpp"

#include <iostream>

int main() {
    Pilha<int> mypilha = Pilha<int>(10);
    mypilha.empilha(0);
    mypilha.empilha(1);
    mypilha.empilha(2);
    mypilha.empilha(3);
    mypilha.empilha(4);
    mypilha.empilha(5);
    mypilha.empilha(6);
    mypilha.empilha(7);
    mypilha.empilha(8);
    int x = mypilha.desempilha();

    std::cout << "Valor DO elemento desempilhado: " << x << std::endl;
    ;
    //////////////////////////////////////////////////////////////////////
    Fila<int> myfila = Fila<int>(10);
    myfila.Inclui(0);
    myfila.Inclui(1);
    myfila.Inclui(2);
    myfila.Inclui(3);
    myfila.Inclui(4);
    myfila.Inclui(5);
    myfila.Inclui(6);
    myfila.Inclui(7);
    myfila.Inclui(8);
    myfila.Inclui(9);
    int y = myfila.Retira();
    int z = myfila.Retira();
    int ultimo = myfila.Ultimo();
    int posicao = myfila.getPosUltimo();
    std::cout << "O valor retirado foi: " << y << z << std::endl;
    std::cout << "O valor do ultimo é: " << ultimo << "E sua posição é: " << posicao << std::endl;



};


/*
 * File:   main.cpp
 * Author: podesta
 *
 * Created on 20 de Agosto de 2014, 18:41
 */

//#include "Main.h"
#include "Pilha.hpp"
#include "Fila.hpp"
#include "EstruturaLinear.hpp"
#include <iostream>
int main(){
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

    std::cout << "Valor DO elemento desempilhado: " <<  x << std::endl;
    	//mypilha.limparPilha();
    	//int v = mypilha.getPosTopo();
        //std::cout << "Valor DO elemento desempilhado: " <<  v << std::endl;

    Fila<int> myfila = Fila<int>(10);
    myfila.inclui(0);
    myfila.inclui(1);
    myfila.inclui(2);
    myfila.inclui(3);
    myfila.inclui(4);
    myfila.inclui(5);
    myfila.inclui(6);
    myfila.inclui(7);
    myfila.inclui(8);
    myfila.inclui(9);
    int y = myfila.retira();
    int z = myfila.retira();
    int ultimo = myfila.ultimo();
    int posicao = myfila.getPosUltimo();
    std::cout << "O valor retirado foi: " << y << " e " << z <<  std::endl;
    std::cout << "O valor do ultimo é: " << ultimo << "\n E sua posição é: " << posicao <<std::endl;

};

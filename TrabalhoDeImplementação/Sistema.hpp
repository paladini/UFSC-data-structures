#ifndef SISTEMA_HPP_
#define SISTEMA_HPP_
#include "Semaforo.hpp"
#include "ListaCirc.hpp"
#include "Pista.hpp"
#include "Carro.hpp"
#include <iostream>

class Sistema {
    ListaCirc<Semaforo> semaforos;
    int tempoAtual;
    int tempoSemaforo;
    int tempoDeExecucao;
    
    Sistema(int _tempoSemaforo, int _tempoDeExecucao) {
        semaforos = ListaCirc<Semaforo>();  
        tempoAtual = 0;
        tempoSemaforo = _tempoSemaforo;
        tempoDeExecucao = _tempoDeExecucao;
        instanciar();
    }

    void instanciar() { //tamanho, velocidadeMedia, fonte
        Pista<Carro>* n1sul    = new Pista<Carro>(500, 60, true, tempoSemaforo, 0);
        Pista<Carro>* n1norte  = new Pista<Carro>(500, 60, false, tempoSemaforo, 0);
        Pista<Carro>* n2sul    = new Pista<Carro>(500, 40, true, tempoSemaforo, 0);
        Pista<Carro>* n2norte  = new Pista<Carro>(500, 40, false, tempoSemaforo, 0);
        Pista<Carro>* o1oeste  = new Pista<Carro>(2000, 80, false, tempoSemaforo, 0);
        Pista<Carro>* o1leste  = new Pista<Carro>(2000, 80, true, tempoSemaforo, 0);
        Pista<Carro>* s1sul    = new Pista<Carro>(500, 60, false, tempoSemaforo, 0);
        Pista<Carro>* s1norte  = new Pista<Carro>(500, 60, true, tempoSemaforo, 0);
        Pista<Carro>* s2sul    = new Pista<Carro>(500, 40, false, tempoSemaforo, 0);
        Pista<Carro>* s2norte  = new Pista<Carro>(500, 40, true, tempoSemaforo, 0);
        Pista<Carro>* l1lista  = new Pista<Carro>(400, 30, false, tempoSemaforo, 0);
        Pista<Carro>* l1oeste  = new Pista<Carro>(400, 30, true, tempoSemaforo, 0);
        Pista<Carro>* c1oeste  = new Pista<Carro>(300, 60, false, tempoSemaforo, 0);
        Pista<Carro>* c1leste  = new Pista<Carro>(300, 60, false, tempoSemaforo, 0);

        // backup, deixar aqui até commit (tudo correto)
        // Semaforo o1leste = new Semaforo(0, o1leste, s1sul, n1norte, c1leste, {10, 10, 80});
        // Semaforo c1leste = new Semaforo(1, c1leste, s2sul, n2norte, l1leste, {30, 30, 40});
        // Semaforo l1oeste = new Semaforo(2, l1oeste, n2norte, s2sul, c1oeste, {});
        // Semaforo c1oeste = new Semaforo(2, c1oeste, n1norte, s1sul, o1oeste, {30, 30, 40});
        // nao juntar
        // Semaforo s1norte = new Semaforo(3, s1norte, c1leste, o1oeste, n1norte, {80, 10, 10});
        // Semaforo s2norte = new Semaforo(4, s2norte, l1leste, c1oeste, n2norte, {40, 30, 30});
        // nao juntar
        // Semaforo n1sul = new Semaforo(5, n1sul, o1oeste, c1leste, s1sul, {10, 10, 80});
        // Semaforo n2sul = new Semaforo(6, n2sul, c1oeste, l1leste, s2sul, {30, 40, 30});

        // Semáforos
        // id, pistaLocal, pistaDireita, pistaEsquerda, pistaFrente, probabilidades
        // {atual, frente, direita, esquerda}, probabilidades
        Pista arg1[] = {o1leste, c1leste, s1sul, n1norte};
        int arg2[] = {80, 10, 10};
        Semaforo* so1leste = new Semaforo(arg1, arg2);

        arg1 = {c1leste, l1leste, s2sul, n2norte};
        arg2 = {40, 30, 30};
        Semaforo* sc1leste = new Semaforo(arg1,arg2);

        arg1 = {c1oeste, o1oeste, s1sul, n1norte};
        arg2 = {40, 30, 30};
        Semaforo* sc1oeste = new Semaforo(arg1,arg2);

        // nao juntar
        arg1 = {s1norte, n1norte, c1leste, o1oeste};
        arg2 = {10, 10, 80};
        Semaforo* ss1norte = new Semaforo(arg1,arg2);

        arg1 = {s2norte, c1oeste, s2sul, l1leste};
        arg2 = {30, 30, 40};
        Semaforo* ss2norte = new Semaforo(arg1,arg2);

        // nao juntar
        arg1 = {n1sul, s1sul, c1leste, o1oeste};
        arg2 = {10, 80, 10};
        Semaforo* sn1sul = new Semaforo(arg1, arg2);

        arg1 = {n2sul, n2norte, l1leste, c1oeste};
        arg2 = {30, 40, 30};
        Semaforo* sn2sul = new Semaforo(arg1,arg2);

        // Adicionando na lista de semáforos
        semaforos->adiciona(so1leste);
        semaforos->adiciona(sc1leste);
        // semaforos->adiciona(sl1oeste);
        semaforos->adiciona(sc1oeste);
        semaforos->adiciona(ss1norte);
        semaforos->adiciona(ss2norte);
        semaforos->adiciona(sn1sul);
        semaforos->adiciona(sn2sul);
    }

    void atualizarSistema() {
        while (tempoAtual < tempoDeExecucao) {
            for (int i = 0; i < 2; i++) {
                (semaforos->retornaDado(i))->atualiza(tempoAtual); // 0 e 1 são os semaforos da  principal do sistema
            }
            tempoAtual += tempoSemaforo;
            for (int i = 2; i < 4; i++) {
                (semaforos->retornaDado(i))->atualiza(tempoAtual);
            }
            tempoAtual += tempoSemaforo;
            for (int i = 4; i < semaforos->(retornaTamanho() - 4); i++) {
                (semaforos->retornaDado(i))->atualiza(tempoAtual);
                tempoAtual += tempoSemaforo;
            }
        }
        //int carros = getCarrosLiberados();
        std::cout << "Foram simulados " << tempoAtual << " segundos e " << " carros passaram pelo sistema." << std::endl; 
    }
};

#endif

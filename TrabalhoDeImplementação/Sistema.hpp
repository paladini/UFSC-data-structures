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
        Pista<Carro>* n1sul    = new Pista<Carro>(500, 60, true);
        Pista<Carro>* n1norte  = new Pista<Carro>(500, 60, false);
        Pista<Carro>* n2sul    = new Pista<Carro>(500, 40, true);
        Pista<Carro>* n2norte  = new Pista<Carro>(500, 40, false);
        Pista<Carro>* o1oeste  = new Pista<Carro>(2000, 80, false);
        Pista<Carro>* o1leste  = new Pista<Carro>(2000, 80, true);
        Pista<Carro>* s1sul    = new Pista<Carro>(500, 60, false);
        Pista<Carro>* s1norte  = new Pista<Carro>(500, 60, true);
        Pista<Carro>* s2sul    = new Pista<Carro>(500, 40, false);
        Pista<Carro>* s2norte  = new Pista<Carro>(500, 40, true);
        Pista<Carro>* l1lista  = new Pista<Carro>(400, 30, false);
        Pista<Carro>* l1oeste  = new Pista<Carro>(400, 30, true);
        Pista<Carro>* c1oeste  = new Pista<Carro>(300, 60, false);
        Pista<Carro>* c1leste  = new Pista<Carro>(300, 60, false);

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
        Semaforo* o1leste = new Semaforo(0, o1leste, s1sul, n1norte, c1leste, {10, 10, 80});
        Semaforo* c1leste = new Semaforo(1, c1leste, s2sul, n2norte, l1leste, {30, 30, 40});

        Semaforo* c1oeste = new Semaforo(2, c1oeste, n1norte, s1sul, o1oeste, {30, 30, 40});
        // nao juntar
        Semaforo* s1norte = new Semaforo(3, s1norte, c1leste, o1oeste, n1norte, {80, 10, 10});
        Semaforo* s2norte = new Semaforo(4, s2norte, l1leste, s2sul, c1oeste, {40, 30, 30});
        // nao juntar
        Semaforo* n1sul = new Semaforo(5, n1sul, o1oeste, c1leste, s1sul, {10, 80, 10});
        Semaforo* n2sul = new Semaforo(6, n2sul, c1oeste, l1leste, n2norte, {30, 40, 30});

        // Adicionando na lista de semáforos
        semaforos->adiciona(o1leste);
        semaforos->adiciona(c1leste);
        semaforos->adiciona(l1oeste);
        semaforos->adiciona(c1oeste);
        semaforos->adiciona(s1norte);
        semaforos->adiciona(s2norte);
        semaforos->adiciona(n1sul);
        semaforos->adiciona(n2sul);
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

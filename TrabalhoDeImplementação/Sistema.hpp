#ifndef SISTEMA_HPP_
#define SISTEMA_HPP_
#include "ListaCirc.hpp"
#include "Semaforo.hpp"
#include "ListaEnc.hpp"
#include <iostream>

class Sistema {
 public:
    ListaCirc<Semaforo*>* semaforos;
    ListaCirc<Pista<Carro>*>* pistas;
    ListaEnc<Evento> listaDeEventos;
    int tempoAtual, tempoSemaforo, tempoDeExecucao;
    int carrosQuePassaram = 0;
    int carrosQueEntraram = 0;
    
    Sistema(int _tempoSemaforo, int _tempoDeExecucao) {
        this->semaforos = new ListaCirc<Semaforo*>();  
        this->pistas = new ListaCirc<Pista<Carro>*>();
        // this->listaDeEventos = new ListaEnc<Evento>({
            //inline bool operato> (const T& b, const T& c) {return b.getTempo() > c.getTempo()}
        // });
        tempoAtual = 0;
        tempoSemaforo = _tempoSemaforo;
        tempoDeExecucao = _tempoDeExecucao;
        instanciar();
    }

    void instanciar() { //tamanho, velocidadeMedia, fonte
        Pista<Carro>* n1sul    = new Pista<Carro>(500, 60, true, false, 5, 20);
        Pista<Carro>* n1norte  = new Pista<Carro>(500, 60, false, true, 0, 0);
        Pista<Carro>* n2sul    = new Pista<Carro>(500, 40, true, false, 5, 20);
        Pista<Carro>* n2norte  = new Pista<Carro>(500, 40, false, true, 0, 0);
        Pista<Carro>* o1oeste  = new Pista<Carro>(2000, 80, false, true, 0, 0);
        Pista<Carro>* o1leste  = new Pista<Carro>(2000, 80, true, false, 2, 10);
        Pista<Carro>* s1sul    = new Pista<Carro>(500, 60, false, true, 0, 0);
        Pista<Carro>* s1norte  = new Pista<Carro>(500, 60, true, false, 7, 30);
        Pista<Carro>* s2sul    = new Pista<Carro>(500, 40, false, true, 0, 0);
        Pista<Carro>* s2norte  = new Pista<Carro>(500, 40, true, false, 15, 60);
        Pista<Carro>* l1leste  = new Pista<Carro>(400, 30, false, true, 0, 0);
        Pista<Carro>* l1oeste  = new Pista<Carro>(400, 30, true, false, 2, 10);
        Pista<Carro>* c1oeste  = new Pista<Carro>(300, 60, false, false, 0, 0);
        Pista<Carro>* c1leste  = new Pista<Carro>(300, 60, false, false, 0, 0);

        // Adicionando na lista
        pistas->adiciona(n1sul);
        pistas->adiciona(n1norte);
        pistas->adiciona(n2sul);
        pistas->adiciona(n2norte);
        pistas->adiciona(o1oeste);
        pistas->adiciona(o1leste);
        pistas->adiciona(s1sul);
        pistas->adiciona(s1norte);
        pistas->adiciona(s2sul);
        pistas->adiciona(s2norte);
        pistas->adiciona(l1leste);
        pistas->adiciona(l1oeste);
        pistas->adiciona(c1oeste);                
        pistas->adiciona(c1leste);

        // backup, deixar aqui até commit (tudo correto)
        // Semaforo o1leste = new Semaforo(0, o1leste, s1sul, n1norte, c1leste, {10, 10, 80});
        // Semaforo c1leste = new Semaforo(1, c1leste, s2sul, n2norte, l1leste, {30, 30, 40});
        // Semaforo l1oeste = new Semaforo(2, l1oeste, n2norte, s2sulint *grid = new int[3];, c1oeste, {});
        // Semaforo c1oeste = new Semaforo(2, c1oeste, n1norte, s1sul, o1oeste, {30, 30, 40});
        // nao juntar
        // Semaforo s1norte = new Semaforo(3, s1norte, c1leste, o1oeste, n1norte, {80, 10, 10});
        // Semaforo s2norte = new Semaforo(4, s2norte, l1leste, c1oeste, n2norte, {40, 30, 30});
        // nao juntar
        // Semaforo n1sul = new Semaforo(5, n1sul, o1oeste, c1leste, s1sul, {10, 10, 80});
        // Semaforo n2sul = new Semaforo(6, n2sul, c1oeste, l1leste, s2sul, {30, 40, 30});

        // Semáforos
        // {atual, frente, direita, esquerda}, probabilidades
        Pista<Carro>* arg1[4] = {o1leste, c1leste, s1sul, n1norte};
        int arg2[3] = {80, 10, 10};
        Semaforo* so1leste = new Semaforo(arg1, arg2, tempoSemaforo);
   
        Pista<Carro>* arg3[4] = {c1leste, l1leste, s2sul, n2norte};
        int arg4[3] = {40, 30, 30};
        Semaforo* sc1leste = new Semaforo(arg3, arg4, tempoSemaforo);

        Pista<Carro>* arg5[4] = {c1oeste, o1oeste, s1sul, n1norte};
        int arg6[3] = {40, 30, 30};
        Semaforo* sc1oeste = new Semaforo(arg1,arg2, tempoSemaforo);
        
        Pista<Carro>* arg7[4] = {s1norte, n1norte, c1leste, o1oeste};
        int arg8[3] = {10, 10, 80};
        Semaforo* ss1norte = new Semaforo(arg1,arg2, tempoSemaforo);
      
        Pista<Carro>* arg9[4] = {s2norte, c1oeste, s2sul, l1leste};
        int arg10[3] = {30, 30, 40};
        Semaforo* ss2norte = new Semaforo(arg1,arg2, tempoSemaforo);
       
        Pista<Carro>* arg11[4] = {n1sul, s1sul, c1leste, o1oeste};
        int arg12[3] = {10, 80, 10};
        Semaforo* sn1sul = new Semaforo(arg1, arg2, tempoSemaforo);

        Pista<Carro>* arg13[4] = {n2sul, n2norte, l1leste, c1oeste};
        int arg14[3] = {30, 40, 30};
        Semaforo* sn2sul = new Semaforo(arg1,arg2, tempoSemaforo);

        // Adicionando na lista de semáforos
        semaforos->adiciona(so1leste);
        semaforos->adiciona(sc1leste);
        semaforos->adiciona(ss1norte);
        semaforos->adiciona(ss2norte);
        semaforos->adiciona(sn1sul);
        semaforos->adiciona(sn2sul);
        semaforos->adiciona(sc1oeste);
    }

    int iniciar() {
        gerarEventos();
        return executarEventos();
    }

    void gerarEventos() {
        
        // Gera eventos de adicionar carros
        for(int i = 0; i < pistas->retornaTamanho(); i++) {
            Pista<Carro>* pistaAtual = pistas->retornaDado(i);
            if (pistaAtual->isFonte()) {
                int tempoInterno = tempoAtual;
                while(tempoInterno < tempoDeExecucao) {
                    Carro* carro = new Carro();
                    Evento evento = new Evento(pistaAtual->calculeProximoEvento(tempoInterno), carro, pistaAtual, 0);
                    listaDeEventos->adiciona(evento);
                    tempoInterno = evento->getTempo();
                }
            }
        }

        // Gera eventos de troca de semaforos    
        // TODO: depois trocar de lugar com o for de baixo, vai estar demorando mais tempo.
        for(int i = 0; i < semaforos->retornaTamanho(); i+=2) {
            int tempoInterno = tempoDeExecucao;
            while(tempoInterno < tempoDeExecucao) {
                Semaforo* atual = semaforos->retornaDado(i);
                Semaforo* proximo = semaforos->retornaDado(i+1);
                Evento evento = new Evento(atual->calculeProximoEvento(tempoInterno), atual, NULL, 1);
                tempoInterno = evento->getTempo();
                Evento evento = new Evento(tempoInterno, proximo, NULL, 1);
            }
        }

        // Gera eventos de chegada de carros no semaforo
        for (int i = 0; i < listaDeEventos->retornaTamanho(); i++) {
            if(listaDeEventos->retornaDado(i)->getTipo() == 0){
                int tempoChegada = listaDeEventos->retornaDado(i)->getTempo();
                Pista<Carro>* atual = listaDeEventos->retornaDado(i)->getRelacionado();
                Semaforo* semaforo = procurarPorSemaforo(atual);
                Evento evento = new Evento(atual->tempoDeChegada(tempoAtual, tempoChegada), atual, semaforo, 2);
                // Evento evento = new Evento(atual->tempoDeChegada(tempoAtual, tempoChegada), semaforo, NULL, 2);
                
            }
        }


        // Gera eventos remove carro de sumidouros
        for(int i = 0; i < pistas->retornaTamanho(); i++) {
            Pista<Carro>* pistaAtual = pistas->retornaDado(i);
            if (!pistaAtual->isFonte()) {
                int tempoInterno = tempoAtual;
                while(tempoInterno < tempoDeExecucao) {
                    Carro* carro = new Carro();
                    Evento evento = new Evento(pistaAtual->calculeProximoEvento(tempoInterno), carro, pistaAtual, 3);
                    listaDeEventos->adiciona(evento);
                    tempoInterno = evento->getTempo();
                }
            }
        }

        ordenarVetorEventos();
    }

    Semaforo* procurarPorSemaforo(Pista<Carro>* pista) {
        for(int i = 0; i < semaforos->retornaTamanho(); i++){   
            Semaforo* atual = semaforos->retornaDado(i);
            if(atual->retornaPistaLocal() == pista) {
                return atual;
            }
        }
    }

    void ordenarVetorEventos() {
        Evento x;
        int i, j, k;
        for(int i = 1; i < listaDeEventos->retornaTamanho() - 1; i++) {
            k = i;
            x = listaDeEventos->retornaDado(i);
            for (int j = i + 1; listaDeEventos->retornaTamanho(); j++) {
                if (listaDeEventos->retornaDado(j)->getTempo() < x->getTempo()) {
                    k = j;
                    x = listaDeEventos->retornaDado(k);
                }
            }
            listaDeEventos->retornaDado(k) = listaDeEventos->retornaDado(i);
            listaDeEventos->retornaDado(i) = x;
        }
    }

    int executarEventos() {
        for(int i = 0; i < listaDeEventos->retornaTamanho(); i++) {

            Evento* eventoAtual = listaDeEventos->retornaDado(i);
            switch (eventoAtual->getTipo()) {

                case 0: { // adiciona carro
                    Pista<Carro>* pista = eventoAtual->getRelacionado();
                    pista->adicionaCarro(eventoAtual->getObjeto());
                    tempoAtual = eventoAtual->getTempo();
                    break;
                }
                case 1: { // troca semaforo
                    Semaforo* semaforo = eventoAtual->getObjeto();
                    semaforo->trocarAberto();
                    tempoAtual = eventoAtual->getTempo();
                    break;
                }
                case 2: { // carro chegou no final da pista
                    Pista<Carro>* pista = eventoAtual->getObjeto();
                    Semaforo* semaforo = eventoAtual->getRelacionado();
                    semaforo->passaCarro(pista);
                    tempoAtual = eventoAtual->getTempo();
                    break;
                }
                case 3: { // carro chegou no final de uma pista sumidouro
                    
                }
                default: {
                    std::cout << "Algo deu errado, por favor verificar o metodo executarEventos()." << std::endl;
                    return -1;
                }
            }
        }
        return 0;
    }


    void atualizarSistema() {

        // // TODO: FAZER A VERIFICACAO DENTRO DE CADA SEMAFORO->ATUALIZA
        // while (tempoAtual < tempoDeExecucao) {
        //     // pistaLocal->atualizaPista(tempoAtual);
        //     for (int i = 0; i < 2; i++) {
        //         semaforos->retornaDado(i)->atualiza(tempoAtual, tempoDeExecucao); // 0 e 1 são os semaforos da  principal do sistema
        //     }
        //     if (tempoAtual < tempoDeExecucao) {
        //         tempoAtual += tempoSemaforo;
        //     }
        //     // pistaLocal->atualizaPista(tempoAtual);
        //     for (int i = 2; i < 4; i++) {
        //         semaforos->retornaDado(i)->atualiza(tempoAtual, tempoDeExecucao);
        //     }
        //     if (tempoAtual < tempoDeExecucao) {
        //         tempoAtual += tempoSemaforo;
        //     }
        //     // pistaLocal->atualizaPista(tempoAtual);
        //     for (int i = 4; i < (semaforos->retornaTamanho() - 4); i++) {
        //         semaforos->retornaDado(i)->atualiza(tempoAtual, tempoDeExecucao);
        //         tempoAtual += tempoSemaforo;
        //     }
        // }

        // Contando carros que foram e sairam das pistas;
        contarCarros();
        std::cout << "Foram simulados " << tempoAtual << " segundos." << std::endl;
        std::cout << carrosQueEntraram << " carros entraram no sistema." << std::endl;
        std::cout << carrosQuePassaram << " carros passaram pelo sistema." << std::endl;
    }

    // void atualizarSistema() {

    //     // TODO: FAZER A VERIFICACAO DENTRO DE CADA SEMAFORO->ATUALIZA
    //     while (tempoAtual < tempoDeExecucao) {
    //         for (int i = 0; i < 2; i++) {
    //             semaforos->retornaDado(i)->atualiza(tempoAtual, tempoDeExecucao); // 0 e 1 são os semaforos da  principal do sistema
    //         }
    //         tempoAtual += tempoSemaforo;
    //         for (int i = 2; i < 4; i++) {
    //             semaforos->retornaDado(i)->atualiza(tempoAtual, tempoDeExecucao);
    //         }
    //         tempoAtual += tempoSemaforo;
    //         for (int i = 4; i < (semaforos->retornaTamanho() - 4); i++) {
    //             semaforos->retornaDado(i)->atualiza(tempoAtual, tempoDeExecucao);
    //             tempoAtual += tempoSemaforo;
    //         }
    //     }
    //     //int carros = getCarrosLiberados();

    //     int contarCarros = contarCarros();
    //     std::cout << "Foram simulados " << tempoAtual << " segundos e " << " carros passaram pelo sistema." << std::endl; 
    // }

    void contarCarros() {
        for (int i = 0; i < pistas->retornaTamanho(); i++) {
            carrosQueEntraram = carrosQueEntraram + pistas->retornaDado(i)->retornaCarrosQueEntraram();
            carrosQuePassaram = carrosQuePassaram + pistas->retornaDado(i)->retornaCarrosQuePassaram();
        }
    }

};

#endif

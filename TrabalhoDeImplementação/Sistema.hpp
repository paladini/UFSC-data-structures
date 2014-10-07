#ifndef SISTEMA_HPP_
#define SISTEMA_HPP_
#include "ListaCirc.hpp"
#include "Evento.hpp"
#include "Semaforo.hpp"
#include <iostream>
#include <cstdio>

class Sistema {
 public:
    ListaCirc<Semaforo*>* semaforos;
    ListaCirc<Pista<Carro>*>* pistas;
    ListaEnc<Evento*>* listaDeEventos;
    int tempoAtual, tempoSemaforo, tempoDeExecucao;
    int carrosQuePassaram = 0;
    int carrosQueEntraram = 0;
    
    Sistema(int _tempoSemaforo, int _tempoDeExecucao) {
        this->semaforos = new ListaCirc<Semaforo*>();  
        this->pistas = new ListaCirc<Pista<Carro>*>();
        this->listaDeEventos = new ListaEnc<Evento*>();
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
        Semaforo* so1leste = new Semaforo(true, arg1, arg2, tempoSemaforo);
   
        Pista<Carro>* arg3[4] = {c1leste, l1leste, s2sul, n2norte};
        int arg4[3] = {40, 30, 30};
        Semaforo* sc1leste = new Semaforo(true, arg3, arg4, tempoSemaforo);

        Pista<Carro>* arg5[4] = {c1oeste, o1oeste, s1sul, n1norte};
        int arg6[3] = {40, 30, 30};
        Semaforo* sc1oeste = new Semaforo(false, arg5, arg6, tempoSemaforo);
        
        Pista<Carro>* arg7[4] = {s1norte, n1norte, c1leste, o1oeste};
        int arg8[3] = {10, 10, 80};
        Semaforo* ss1norte = new Semaforo(false, arg7, arg8, tempoSemaforo);
      
        Pista<Carro>* arg9[4] = {s2norte, c1oeste, s2sul, l1leste};
        int arg10[3] = {30, 30, 40};
        Semaforo* ss2norte = new Semaforo(false, arg9, arg10, tempoSemaforo);
       
        Pista<Carro>* arg11[4] = {n1sul, s1sul, c1leste, o1oeste};
        int arg12[3] = {10, 80, 10};
        Semaforo* sn1sul = new Semaforo(false, arg11, arg12, tempoSemaforo);

        // {atual, frente, direita, esquerda}, probabilidades
        Pista<Carro>* arg13[4] = {n2sul, s2sul, c1oeste, l1oeste};
        int arg14[3] = {30, 40, 30};
        Semaforo* sn2sul = new Semaforo(false, arg13, arg14, tempoSemaforo);

        Pista<Carro>* arg15[4] = {l1oeste, c1oeste, n2norte, s2sul};
        int arg16[3] = {30, 30, 40};
        Semaforo* sl1oeste = new Semaforo(false, arg15, arg16, tempoSemaforo);

        // Adicionando na lista de semáforos
        semaforos->adiciona(sn1sul);
        semaforos->adiciona(sn2sul);
        
        semaforos->adiciona(sc1oeste);
        semaforos->adiciona(sl1oeste);

        semaforos->adiciona(ss1norte);
        semaforos->adiciona(ss2norte);

        semaforos->adiciona(so1leste);
        semaforos->adiciona(sc1leste);
    }

    int iniciar() {
        gerarEventos();
        return executarEventos();
    }

    void gerarEventos() {

        // Gera eventos de adicionar carros
        // int tamanho = pistas->
        for(int i = 0; i < pistas->retornaTamanho(); i++) {
            Pista<Carro>* pistaAtual = pistas->retornaDado(i);
            if (pistaAtual->isFonte()) {
                int tempoInterno = tempoAtual;
                while(tempoInterno < tempoDeExecucao) {
                    Carro* carro = new Carro();
                    int tempoProximoEvento = pistaAtual->calculeProximoEvento(tempoInterno);
                    if(tempoProximoEvento <= tempoDeExecucao) {
                        Evento* evento = new Evento(tempoProximoEvento, carro, pistaAtual, 0);
                        listaDeEventos->adiciona(evento);
                    }
                    tempoInterno = tempoProximoEvento;
                }
            }
        }

        // Gera eventos de troca de semaforos    
        // TODO: depois trocar de lugar com o for de baixo, vai estar demorando mais tempo.
        for(int i = 0; i < semaforos->retornaTamanho(); i+=2) {
            int tempoInterno = tempoAtual;
            while(tempoInterno < tempoDeExecucao) {
                Semaforo* atual = semaforos->retornaDado(i);
                Semaforo* proximo = semaforos->retornaDado(i+1);
                int tempoProximoEvento = atual->calculeProximoEvento(tempoInterno);
                if(tempoProximoEvento <= tempoDeExecucao) {
                    Evento* evento = new Evento(tempoProximoEvento, atual, NULL, 1);
                    Evento* evento2 = new Evento(tempoProximoEvento, proximo, NULL, 1);
                    listaDeEventos->adiciona(evento);
                    listaDeEventos->adiciona(evento2);
                }
                tempoInterno = tempoProximoEvento;
            }
        }

        // Gera eventos de chegada de carros no semaforo
        Pista<Carro>* atual;
        Semaforo* semaforo;
        Evento* evento;
        int tempoChegada;
        for (int i = 0; i < listaDeEventos->retornaTamanho(); i++) {
            if(listaDeEventos->retornaDado(i)->getTipo() == 0){
                tempoChegada = listaDeEventos->retornaDado(i)->getTempo();
                
                atual = (Pista<Carro>*) listaDeEventos->retornaDado(i)->getRelacionado();
                semaforo = procurarPorSemaforo(atual);
                int tempoProximoEvento = atual->tempoDeChegada(tempoChegada);
                if(tempoProximoEvento <= tempoDeExecucao) {
                    evento = new Evento(tempoProximoEvento, semaforo, NULL, 2);
                    listaDeEventos->adiciona(evento);
                } else {
                    break;
                }
            }
        }

        // Gera eventos que removem carro de sumidouros
        // for(int i = 0; i < pistas->retornaTamanho(); i++) {
        //     Pista<Carro>* pistaAtual = pistas->retornaDado(i);
        //     if (!pistaAtual->isFonte()) {
        //         int tempoInterno = tempoAtual;
        //         int tempoChegada = listaDeEventos->retornaDado(i)->getTempo();
        //         while(tempoInterno < tempoDeExecucao) {
        //             Carro* carro = new Carro();
        //             Evento* evento = new Evento(pistaAtual->tempoDeChegada(tempoInterno), carro, pistaAtual, 3);
        //             listaDeEventos->adiciona(evento);
        //             tempoInterno = evento->getTempo();
        //         }
        //     }
        // }
        // std::cout << "zueira" << std::endl;
        // ordenarVetorEventos();
        // ordenarLista();
        for(int i = 0; i < listaDeEventos->retornaTamanho(); i++) {
            std::cout << "Tempo do evento " << i << " é " << listaDeEventos->retornaDado(i)->getTempo() << std::endl;
        }
        // std::cout << "Tamanho lista de eventos: " << listaDeEventos->retornaTamanho() << std::endl;
    }

    Semaforo* procurarPorSemaforo(Pista<Carro>* pista) {
        for(int i = 0; i < semaforos->retornaTamanho(); i++){   
            Semaforo* atual = semaforos->retornaDado(i);
            if(atual->retornaPistaLocal() == pista) {
                return atual;
            }
        }
        return NULL;
    }

    // void gerarNovoEvento(bool continuaNaPista, Pista<Carro>* proximaPista, int _tempoChegada) {
    //     int tempoChegada = _tempoChegada;
    //     Pista<Carro>* atual = proximaPista;
    //     Semaforo* semaforo = procurarPorSemaforo(atual);
    //     Evento* evento;

    //     // Se não conseguiu achar um semáforo, significa que é sumidouro.
    //     if (semaforo == NULL) {
    //         // TODO: não é para passar o semaforo aqui.
    //         evento = new Evento(atual->tempoDeChegada(tempoChegada), semaforo, NULL, 3); 
    //     } else {
    //         evento = new Evento(atual->tempoDeChegada(tempoChegada), semaforo, NULL, 2);
    //     }
    //     listaDeEventos->adiciona(evento);

    //     ordenarVetorEventos();
    // }

    /**
    *
    * O carro chegou no semáforo, existem algumas coisas que podem acontecer:
    *
    *   1) Pista destino lotada -> nesse caso cria um evento desse mesmo carro que vai acontecer na próxima vez que o sinal estiver verde.
    *   2) ProximaPista é sumidouro -> cria um evento de que o carro vai ser deletado (tipo 3).
    *   3) ProximaPista é semaforo -> cria um evento de que o carro vai chegar no semáforo. (tipo 2)
    *   4) Sinal vermelho (o lançamento do throw) -> cria um evento no tempo seguinte de abertura do semáforo. (tempo de abertura do semaforo + 1)
    *
    */
    void executarCarroChegouNoSemaforo(Evento* eventoAtual) {
        
        Evento* evento;
        Semaforo* semaforo = (Semaforo*) eventoAtual->getObjeto();
        tempoAtual = eventoAtual->getTempo();
        int tempoProximoEvento = -1;
        try {
            Pista<Carro>* proximaPista = semaforo->passaCarro();

            // Se pista destino estiver lotada.
            if (proximaPista == semaforo->retornaPistaLocal()) {
                tempoProximoEvento = tempoAtual + (semaforo->retornaIntervalo() * 2);
                evento = new Evento(tempoProximoEvento, semaforo, NULL, 2); 
            } else {
                
                // Verifica se próxima pista é semaforo ou sumidouro.
                Semaforo* semaforo = procurarPorSemaforo(proximaPista);
                if (semaforo == NULL) { // sumidouro
                    tempoProximoEvento = proximaPista->tempoDeChegada(tempoAtual);
                    evento = new Evento(tempoProximoEvento, proximaPista, NULL, 3); 
                } else { // semaforo
                    tempoProximoEvento = proximaPista->tempoDeChegada(tempoAtual);
                    evento = new Evento(tempoProximoEvento, semaforo, NULL, 2);
                }
            }

        } catch(std::exception& e) { // sinal vermelho
            tempoProximoEvento = semaforo->retornarTempoQueVaiAbrir();
            evento = new Evento(tempoProximoEvento, semaforo, NULL, 2);
        }

        if(tempoProximoEvento != -1 && tempoProximoEvento <= tempoDeExecucao) {
            listaDeEventos->adiciona(evento);
        }
        // ordenarLista();
        // ordenarVetorEv;   ent    ;
    }

    int executarEventos() {
        for(int i = 0; i < listaDeEventos->retornaTamanho(); i++) {

            // Evento* eventoAtual = listaDeEventos->retornaDado(i);
            // std::cout << "Lista de eventos: " << listaDeEventos->retornaTamanho() << std::endl;
            Evento* menorEvento = listaDeEventos->retornaDado(i);
            for (int j = i+1; j < listaDeEventos->retornaTamanho(); j++) {
                if (menorEvento->getTempo() > listaDeEventos->retornaDado(j)->getTempo()) {
                    menorEvento = listaDeEventos->retornaDado(j);
                }
                // std::cout << i << "zueira" << j << std::endl;

            }
            Evento* eventoAtual = menorEvento;
            std::cout << "Tempo de evento atual: " << eventoAtual->getTempo() << "\n" << std::endl;

            if(eventoAtual->getTempo() >= tempoDeExecucao){
                break;
            }
            switch (eventoAtual->getTipo()) {
                case 0: { // adiciona carro
                    Pista<Carro>* pista = (Pista<Carro>*) eventoAtual->getRelacionado();
                    Carro* carro = (Carro*) eventoAtual->getObjeto();
                    pista->adicionaCarro(*carro);
                    tempoAtual = eventoAtual->getTempo();
                    break;
                }
                case 1: { // troca semaforo
                    Semaforo* semaforo = (Semaforo*) eventoAtual->getObjeto();
                    semaforo->trocarAberto(tempoAtual);
                    tempoAtual = eventoAtual->getTempo();
                    break;
                }
                case 2: { // carro chegou no semaforo
                    executarCarroChegouNoSemaforo(eventoAtual);
                    break;
                }
                case 3: { // carro chegou no final de uma pista sumidouro
                    Pista<Carro>* pista = (Pista<Carro>*) eventoAtual->getObjeto();
                    pista->removeCarro();
                    tempoAtual = eventoAtual->getTempo();
                    break;
                }
                default: {
                    std::cout << "Algo deu errado, por favor verificar o metodo executarEventos()." << std::endl;
                    return -1;
                }
                // tempoAtual = eventoAtual->getTempo();
            }
        }
        finalizarPrograma();
    }

    // void ordenarLista() {
    //     // Evento* um, dois, temp;
    //     int tamanho = listaDeEventos->retornaTamanho();
    //     for(int i = 0; i < tamanho; i++) {
    //         std::cout << i << "vezes" << std::endl;
    //         Evento* um = listaDeEventos->retornaDado(i);
    //         for(int j = 1; i < tamanho; j++) {
    //             Evento* dois = listaDeEventos->retornaDado(j);
    //             if(um->getTempo() > dois->getTempo()) {
    //                 Evento* temp = dois;
    //                 listaDeEventos->retiraDaPosicao(j);
    //                 listaDeEventos->adicionaNaPosicao(um, j);
    //                 listaDeEventos->retiraDaPosicao(i);
    //                 listaDeEventos->adicionaNaPosicao(temp, i);
    //             }
    //         }
    //     }
    // }

    // void BubbleSort(apvector <int> &num){
    // void BubbleSort(){
    //     Evento* i, j;
    //     int flag = 1;    // set flag to 1 to start first pass
    //     Evento* temp;             // holding variable
    //     int numLength = listaDeEventos->retornaTamanho(); 
    //     for(i = 1; (i <= numLength) && flag; i++) {
    //         flag = 0;
    //         for (j=0; j < (numLength -1); j++) {
    //             if (listaDeEventos->retornaDado(j+1)->getTempo() > num[j]) { 
    //                 // temp = num[j];             // swap elements
    //                 temp = listaDeEventos->retornaDado(j);
    //                 listaDeEventos->retiraDaPosicao(j);
    //                 listaDeEventos->adicionaNaPosicao(listaDeEventos->retornaDado(j+1), j);
    //                 listaDeEventos->retiraDaPosicao(j+1);
    //                 listaDeEventos->adicionaNaPosicao(temp, j+1);
    //                 // num[j+1] = temp;
    //                 flag = 1;               // indicates that a swap occurred.
    //                 // num[j] = num[j+1];
    //             }
    //         }
    //     }
    // }

    // void ordenarVetorEventos() {
    //     // Evento x = NULL;
    //     int i, j, k;
    //     for(int i = 1; i < listaDeEventos->retornaTamanho() - 1; i++) {
    //         k = i;
    //         std::cout << "Passou no for interno 1." << std::endl;
    //         Evento* x = listaDeEventos->retornaDado(i);
    //         for (int j = i + 1; listaDeEventos->retornaTamanho(); j++) {
    //             std::cout << "Passou no for interno 2." << std::endl;
    //             if ((listaDeEventos->retornaDado(j))->getTempo() < x->getTempo()) {
    //                 std::cout << "Passou no if, mas não foi maroto." << std::endl;
    //                 k = j;
    //                 x = listaDeEventos->retornaDado(k);
    //                  std::cout << "Passou no if maroto." << std::endl;
    //             }
    //         }
    //         std::cout << "Passou na porra toda." << std::endl;
    //         Evento* t = listaDeEventos->retiraDaPosicao(k);
    //         listaDeEventos->adicionaNaPosicao(listaDeEventos->retornaDado(i), k);
    //         t = listaDeEventos->retiraDaPosicao(i);
    //         listaDeEventos->adicionaNaPosicao(x, i);
    //     }
    // }

    // void void quick_sort(int arr[20],int low,int high) {
    //     int pivot,j,temp,i;
    //     if(0 < listaDeEventos->retornaTamanho()) {
    //         pivot = low;
    //         i = low;
    //         j = high;     
    //         while(i<j) {
    //             while((arr[i]<=arr[pivot])&&(i<high)) {
    //                 i++;
    //             }     
    //             while(arr[j]>arr[pivot]) {
    //                 j--;
    //             }     
    //             if(i<j) {
    //                 temp=arr[i];
    //                 arr[i]=arr[j];
    //                 arr[j]=temp;
    //             }
    //         }
    //         temp=arr[pivot];
    //         arr[pivot]=arr[j];
    //         arr[j]=temp;
    //         quick_sort(arr,low,j-1);
    //         quick_sort(arr,j+1,high);
    //     }
    // }

    void finalizarPrograma() {
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

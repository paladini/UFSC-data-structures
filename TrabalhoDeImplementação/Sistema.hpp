#ifndef SISTEMA_HPP_
#define SISTEMA_HPP_
#include "Estruturas/ListaCirc.hpp"
#include "Estruturas/ListaDeEventos.hpp"
#include "Eventos/Evento.hpp"
#include "Semaforo.hpp"
#include <iostream>
#include <cstdio>

class Sistema {
 public:
    ListaCirc<Semaforo*>* semaforos;
    ListaCirc<Pista*>* pistas;
    ListaDeEventos* listaEventos;
    int tempoAtual, tempoSemaforo, tempoDeExecucao;
    int carrosQuePassaram = 0;
    int carrosQueEntraram = 0;
    
    Sistema(int _tempoSemaforo, int _tempoDeExecucao) {
        this->semaforos = new ListaCirc<Semaforo*>();  
        this->pistas = new ListaCirc<Pista*>();
        this->listaEventos = new ListaDeEventos();
        tempoAtual = 0;
        tempoSemaforo = _tempoSemaforo;
        tempoDeExecucao = _tempoDeExecucao;
        instanciar();
    }

    void instanciar() {

        // Criação de pistas
        // int tam, int _velocidadeMedia, bool _fonte, bool _sumidouro, 
        //          int _intervaloInvocacao, int _tempoDeInvocacao
        // 
        // TODO: apagar a passagem de parametros fonte/sumidouro, se intervaloInvocacao
        // for zero 
        Pista* n1sul    = new Pista(500, 60, true, false, 5, 20);
        Pista* n1norte  = new Pista(500, 60, false, true, 0, 0);
        Pista* n2sul    = new Pista(500, 40, true, false, 5, 20);
        Pista* n2norte  = new Pista(500, 40, false, true, 0, 0);
        Pista* o1oeste  = new Pista(2000, 80, false, true, 0, 0);
        Pista* o1leste  = new Pista(2000, 80, true, false, 2, 10);
        Pista* s1sul    = new Pista(500, 60, false, true, 0, 0);
        Pista* s1norte  = new Pista(500, 60, true, false, 7, 30);
        Pista* s2sul    = new Pista(500, 40, false, true, 0, 0);
        Pista* s2norte  = new Pista(500, 40, true, false, 15, 60);
        Pista* l1leste  = new Pista(400, 30, false, true, 0, 0);
        Pista* l1oeste  = new Pista(400, 30, true, false, 2, 10);
        Pista* c1oeste  = new Pista(300, 60, false, false, 0, 0); 
        Pista* c1leste  = new Pista(300, 60, false, false, 0, 0); 

        // NÃO DELETAR ISSO, TÔ TESTANDO
        // Pista* n1sul    = new Pista(500, 60, 5, 20);
        // Pista* n1norte  = new Pista(500, 60, 0, 0);
        // Pista* n2sul    = new Pista(500, 40, 5, 20);
        // Pista* n2norte  = new Pista(500, 40, 0, 0);
        // Pista* o1oeste  = new Pista(2000, 80, 0, 0);
        // Pista* o1leste  = new Pista(2000, 80, 2, 10);
        // Pista* s1sul    = new Pista(500, 60, 0, 0);
        // Pista* s1norte  = new Pista(500, 60, 7, 30);
        // Pista* s2sul    = new Pista(500, 40, 0, 0);
        // Pista* s2norte  = new Pista(500, 40, 15, 60);
        // Pista* l1leste  = new Pista(400, 30, 0, 0);
        // Pista* l1oeste  = new Pista(400, 30, 2, 10);

        // Passa 1 no último argumento pois não é uma fonte nem sumidouro.
        // Pista* c1oeste  = new Pista(300, 60, 0, 1); 
        // Pista* c1leste  = new Pista(300, 60, 0, 1); 

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

        // Semáforos
        Pista* arg1[4] = {o1leste, c1leste, n1norte, s1sul};
        int arg2[3] = {80, 10, 10};
        Semaforo* so1leste = new Semaforo(true, arg1, arg2, tempoSemaforo);  

        Pista* arg3[4] = {c1leste, l1leste, n2norte, s2sul};
        int arg4[3] = {40, 30, 30};
        Semaforo* sc1leste = new Semaforo(true, arg3, arg4, tempoSemaforo);

        Pista* arg5[4] = {c1oeste, o1oeste, s1sul, n1norte};
        int arg6[3] = {40, 30, 30};
        Semaforo* sc1oeste = new Semaforo(false, arg5, arg6, tempoSemaforo);

        Pista* arg7[4] = {s1norte, n1norte, o1oeste, c1leste};
        int arg8[3] = {10, 10, 80};
        Semaforo* ss1norte = new Semaforo(false, arg7, arg8, tempoSemaforo);
      
        Pista* arg9[4] = {s2norte, n2norte, c1oeste, l1leste};
        int arg10[3] = {30, 30, 40};
        Semaforo* ss2norte = new Semaforo(false, arg9, arg10, tempoSemaforo);
       
        Pista* arg11[4] = {n1sul, s1sul, c1leste, o1oeste};
        int arg12[3] = {10, 80, 10};
        Semaforo* sn1sul = new Semaforo(false, arg11, arg12, tempoSemaforo);

        Pista* arg13[4] = {n2sul, s2sul, l1oeste, c1oeste};
        int arg14[3] = {30, 40, 30};
        Semaforo* sn2sul = new Semaforo(false, arg13, arg14, tempoSemaforo);

        Pista* arg15[4] = {l1oeste, c1oeste, s2sul, n2norte};
        int arg16[3] = {30, 30, 40};
        Semaforo* sl1oeste = new Semaforo(false, arg15, arg16, tempoSemaforo);

        // Adicionando na lista de semáforos "em pares"
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
        // std::cout << "Começou a gerar os eventos..." << std::endl;

        // Gera eventos de adicionar carros (tipo 0)
        for(int i = 0; i < pistas->retornaTamanho(); i++) {
            Pista* pistaAtual = pistas->retornaDado(i);
            if (pistaAtual->isFonte()) {
                int tempoInterno = tempoAtual;
                while(tempoInterno < tempoDeExecucao) {
                    Carro* carro = new Carro();
                    int tempoProximoEvento = pistaAtual->calculeProximoEvento(tempoInterno);
                    if(tempoProximoEvento <= tempoDeExecucao) {
                        Evento* evento = new Evento(tempoProximoEvento, carro, pistaAtual, 0);
                        listaEventos->adicionaEmOrdem(evento);
                    }
                    tempoInterno = tempoProximoEvento;
                }
            }
        }

        // Gera eventos de chegada de carros no semaforo (tipo 2)
        Pista* atual;
        Semaforo* semaforo;
        Evento* evento;
        int tempoChegada;
        for (int i = 0; i < listaEventos->retornaTamanho(); i++) {
            if(listaEventos->retornaDado(i)->getTipo() == 0){
                tempoChegada = listaEventos->retornaDado(i)->getTempo();
                atual = (Pista*) listaEventos->retornaDado(i)->getRelacionado();
                semaforo = procurarPorSemaforo(atual);
                int tempoProximoEvento = atual->tempoDeChegada(tempoChegada);
                if(tempoProximoEvento <= tempoDeExecucao) {
                    evento = new Evento(tempoProximoEvento, semaforo, NULL, 2);
                    listaEventos->adicionaEmOrdem(evento);
                }
            }
        }

        // Gera eventos de troca de semaforos (tipo 1)
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
                    listaEventos->adicionaEmOrdem(evento);
                    listaEventos->adicionaEmOrdem(evento2);
                }
                tempoInterno = tempoProximoEvento;
            }
        }
        // Gera eventos que removem carro de sumidouros
        // for(int i = 0; i < pistas->retornaTamanho(); i++) {
        //     Pista* pistaAtual = pistas->retornaDado(i);
        //     if (!pistaAtual->isFonte()) {
        //         int tempoInterno = tempoAtual;
        //         int tempoChegada = listaEventos->retornaDado(i)->getTempo();
        //         while(tempoInterno < tempoDeExecucao) {
        //             Carro* carro = new Carro();
        //             Evento* evento = new Evento(pistaAtual->tempoDeChegada(tempoInterno), carro, pistaAtual, 3);
        //             listaEventos->adicionaEmOrdem(evento);
        //             tempoInterno = evento->getTempo();
        //         }
        //     }
        // }
        // std::cout << "zueira" << std::endl;
        // ordenarVetorEventos();
        // ordenarLista();

        // for(int i = 0; i < listaEventos->retornaTamanho(); i++) {
        //     Evento* eventoAtual = listaEventos->retornaDado(i);
        //     // if(listaEventos->retornaDado(i)->getTipo() == 2){
        //         std::cout << "Evento numero: " << i << std::endl;
        //         std::cout << "Tipo: " << eventoAtual->getTipo() << std::endl;
        //         std::cout << "Tempo: " << eventoAtual->getTempo() << std::endl;
        //         std::cout << "==============================" << std::endl;
        //     // }
        //     // std::cout << "Tempo do evento " << i << " é " << listaEventos->retornaDado(i)->getTempo() << std::endl;
        // }

        // std::cout << "Tamanho lista de eventos: " << listaEventos->retornaTamanho() << std::endl;
    }

    Semaforo* procurarPorSemaforo(Pista* pista) {
        for(int i = 0; i < semaforos->retornaTamanho(); i++){   
            Semaforo* atual = semaforos->retornaDado(i);
            if(atual->retornaPistaLocal() == pista) {
                return atual;
            }
        }
        return NULL;
    }

    /** Método executarCarroQ    
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
            Pista* proximaPista = semaforo->passaCarro();

            // Se pista destino estiver lotada.
            if (proximaPista == semaforo->retornaPistaLocal()) {
                tempoProximoEvento = tempoAtual + (semaforo->retornaIntervalo() * 2);
                evento = new Evento(tempoProximoEvento, semaforo, NULL, 2); 
            } else {
                
                // Verifica se próxima pista é semaforo ou sumidouro.
                if (proximaPista->isSumidouro()) { // sumidouro
                    tempoProximoEvento = proximaPista->tempoDeChegada(tempoAtual);
                    evento = new Evento(tempoProximoEvento, proximaPista, NULL, 3);
                } else { // semaforo
                    Semaforo* semaforo = procurarPorSemaforo(proximaPista);
                    tempoProximoEvento = proximaPista->tempoDeChegada(tempoAtual);
                    evento = new Evento(tempoProximoEvento, semaforo, NULL, 2);
                }
                // Semaforo* semaforo = procurarPorSemaforo(proximaPista);
                // if (semaforo == NULL) { // sumidouro
                //     tempoProximoEvento = proximaPista->tempoDeChegada(tempoAtual);
                //     evento = new Evento(tempoProximoEvento, proximaPista, NULL, 3); 
                // } else { // semaforo
                //     tempoProximoEvento = proximaPista->tempoDeChegada(tempoAtual);
                //     evento = new Evento(tempoProximoEvento, semaforo, NULL, 2);
                // }
            }

        } catch(std::exception& e) { // sinal vermelho
            tempoProximoEvento = semaforo->retornarTempoQueVaiAbrir();
            evento = new Evento(tempoProximoEvento, semaforo, NULL, 2);
        }

        if(tempoProximoEvento != -1 && tempoProximoEvento <= tempoDeExecucao) {
            listaEventos->adicionaEmOrdem(evento);
        }

    }

    int executarEventos() {

        std::cout << "=================================================\n" << std::endl;
        std::cout << "\t       Executando eventos..." << std::endl;
        std::cout << "\n=================================================\n\n" << std::endl;


        // std::cout << "Começou a Executar os eventos..." << tempoDeExecucao << " segundo(s) restantes." << std::endl;
        for(int i = 0; i < listaEventos->retornaTamanho(); i++) {

            Evento* eventoAtual = listaEventos->retornaDado(i);
            // std::cout << "Lista de eventos: " << listaEventos->retornaTamanho() << std::endl;
            // Evento* menorEvento = listaEventos->retornaDado(i);
            // for (int j = 0; j < listaEventos->retornaTamanho(); j++) {
            //     if (menorEvento->getTempo() > listaEventos->retornaDado(j)->getTempo()) {
            //         menorEvento = listaEventos->retornaDado(j);
            //     }
            //     // std::cout << i << "zueira" << j << std::endl;
            // // }
            // Evento* eventoAtual = menorEvento;
            // std::cout << "Tempo de evento atual: " << tempoAtual << "\n" << std::endl;
            // std::cout << "Tipo Evento atual: " << eventoAtual->getTipo() << "\n" << std::endl;
            std::cout << "\r\t\t" << (tempoAtual * 100) / tempoDeExecucao << "% concluído(s).";
            
            if(tempoAtual >= tempoDeExecucao){
                break;
            }

            switch (eventoAtual->getTipo()) {
                case 0: { // adiciona carro
                    Pista* pista = (Pista*) eventoAtual->getRelacionado();
                    Carro* carro = (Carro*) eventoAtual->getObjeto();
                    pista->adicionaCarro(carro);
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
                    Pista* pista = (Pista*) eventoAtual->getObjeto();
                    pista->removeCarro();
                    tempoAtual = eventoAtual->getTempo();
                    break;
                }
                default: {
                    std::cout << "Algo deu errado, por favor verificar o metodo executarEventos()." << std::endl;
                    return -1;
                }
            }
            // std::cout << "Executando..." << tempoAtual << std::endl;
            listaEventos->retiraEspecifico(eventoAtual);
        }
        finalizarPrograma();
    }

    // void ordenarLista() {
    //     // Evento* um, dois, temp;
    //     int tamanho = listaEventos->retornaTamanho();
    //     for(int i = 0; i < tamanho; i++) {
    //         std::cout << i << "vezes" << std::endl;
    //         Evento* um = listaEventos->retornaDado(i);
    //         for(int j = 1; i < tamanho; j++) {
    //             Evento* dois = listaEventos->retornaDado(j);
    //             if(um->getTempo() > dois->getTempo()) {
    //                 Evento* temp = dois;
    //                 listaEventos->retiraDaPosicao(j);
    //                 listaEventos->adicionaNaPosicao(um, j);
    //                 listaEventos->retiraDaPosicao(i);
    //                 listaEventos->adicionaNaPosicao(temp, i);
    //             }
    //         }
    //     }
    // }

    // void BubbleSort(apvector <int> &num){
    // void BubbleSort(){
    //     Evento* i, j;
    //     int flag = 1;    // set flag to 1 to start first pass
    //     Evento* temp;             // holding variable
    //     int numLength = listaEventos->retornaTamanho(); 
    //     for(i = 1; (i <= numLength) && flag; i++) {
    //         flag = 0;
    //         for (j=0; j < (numLength -1); j++) {
    //             if (listaEventos->retornaDado(j+1)->getTempo() > num[j]) { 
    //                 // temp = num[j];             // swap elements
    //                 temp = listaEventos->retornaDado(j);
    //                 listaEventos->retiraDaPosicao(j);
    //                 listaEventos->adicionaNaPosicao(listaEventos->retornaDado(j+1), j);
    //                 listaEventos->retiraDaPosicao(j+1);
    //                 listaEventos->adicionaNaPosicao(temp, j+1);
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
    //     for(int i = 1; i < listaEventos->retornaTamanho() - 1; i++) {
    //         k = i;
    //         std::cout << "Passou no for interno 1." << std::endl;
    //         Evento* x = listaEventos->retornaDado(i);
    //         for (int j = i + 1; listaEventos->retornaTamanho(); j++) {
    //             std::cout << "Passou no for interno 2." << std::endl;
    //             if ((listaEventos->retornaDado(j))->getTempo() < x->getTempo()) {
    //                 std::cout << "Passou no if, mas não foi maroto." << std::endl;
    //                 k = j;
    //                 x = listaEventos->retornaDado(k);
    //                  std::cout << "Passou no if maroto." << std::endl;
    //             }
    //         }
    //         std::cout << "Passou na porra toda." << std::endl;
    //         Evento* t = listaEventos->retiraDaPosicao(k);
    //         listaEventos->adicionaNaPosicao(listaEventos->retornaDado(i), k);
    //         t = listaEventos->retiraDaPosicao(i);
    //         listaEventos->adicionaNaPosicao(x, i);
    //     }
    // }

    // void void quick_sort(int arr[20],int low,int high) {
    //     int pivot,j,temp,i;
    //     if(0 < listaEventos->retornaTamanho()) {
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

        // Contando carros que foram e sairam das pistas;
        contarCarros(); 
        std::cout << "\n\n\n============ R E S U L T A D O S ================\n\n";
        std::cout << "\tForam simulados " << tempoDeExecucao << " segundos." << std::endl;
        std::cout << "\t" << carrosQueEntraram << " carros entraram no sistema." << std::endl;
        std::cout << "\t" << carrosQuePassaram << " carros passaram pelo sistema." << std::endl;
        std::cout << "\t       Vazão: " << (((float)carrosQuePassaram) * 100)/((float)carrosQueEntraram) << "%." << std::endl;
        std::cout << "\n=================================================" << std::endl;
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
            Pista* pista = pistas->retornaDado(i);
            if (pista->isFonte()) {
                carrosQueEntraram = carrosQueEntraram + pista->retornaCarrosQueEntraram();
            } else {
                if (pista->isSumidouro()) {
                    carrosQuePassaram = carrosQuePassaram + pista->retornaCarrosQuePassaram();
                }
            }
        }
    }

};

#endif

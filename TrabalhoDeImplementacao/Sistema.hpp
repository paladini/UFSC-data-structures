/**
* File: Sistema.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on ∞ de Outubro de 2014, às ∞:∞.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
#ifndef SISTEMA_HPP_
#define SISTEMA_HPP_
#include "Estruturas/ListaCirc.hpp"
#include "Estruturas/ListaDeEventos.hpp"
#include "Eventos/Evento.hpp"
#include "Semaforo.hpp"
#include <iostream>
#include <cstdio>
/** Classe Sistema.
* A classe Sistema é a principal responsável pela execução do simulador de tráfego. Essa classe é 
* responsável por instanciar e associar todas as pistas e semáforos do Sistema, além de cuidar da 
* geração de eventos estáticos e dinâmicos, bem como a sua execução. 
*/
class Sistema {
 public:
    ListaCirc<Semaforo*>* semaforos;
    ListaCirc<Pista*>* pistas;
    ListaDeEventos* listaEventos;
    int tempoAtual, tempoSemaforo, tempoDeExecucao;
    int carrosQuePassaram = 0;
    int carrosQueEntraram = 0;
    
    /** Construtor da classe Sistema.
    * Esse construtor recebe dois argumentos que foram recebidos pelo usuário através do "main". 
    * 
    */
    Sistema(int _tempoSemaforo, int _tempoDeExecucao) {
        this->semaforos = new ListaCirc<Semaforo*>();  
        this->pistas = new ListaCirc<Pista*>();
        this->listaEventos = new ListaDeEventos();
        tempoAtual = 0;
        tempoSemaforo = _tempoSemaforo;
        tempoDeExecucao = _tempoDeExecucao;
        instanciar();
    }

    /** Método instanciar.
    * Responsável por instanciar todas as pistas e semáforos do sistema, além de fazer as 
    * "linkagens" entre os dois e adicioná-los nas listas de Pistas e Semáforos.
    */
    void instanciar() {

        // Criação de pistas
        Pista* n1sul    = new Pista(500, 60, 5, 20);
        Pista* n1norte  = new Pista(500, 60, 0, 0);
        Pista* n2sul    = new Pista(500, 40, 5, 20);
        Pista* n2norte  = new Pista(500, 40, 0, 0);
        Pista* o1oeste  = new Pista(2000, 80, 0, 0);
        Pista* o1leste  = new Pista(2000, 80, 2, 10);
        Pista* s1sul    = new Pista(500, 60, 0, 0);
        Pista* s1norte  = new Pista(500, 60, 7, 30);
        Pista* s2sul    = new Pista(500, 40, 0, 0);
        Pista* s2norte  = new Pista(500, 40, 15, 60);
        Pista* l1leste  = new Pista(400, 30, 0, 0);
        Pista* l1oeste  = new Pista(400, 30, 2, 10);
        
        // Passa 1 no último argumento pois não é uma fonte nem sumidouro.
        Pista* c1oeste  = new Pista(300, 60, 0, 1); 
        Pista* c1leste  = new Pista(300, 60, 0, 1); 

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

    /** Método iniciar()
    * Este método é chamado para começar a execução do sistema de simulação.
    * Primeiro chama o método gerarEventos(), que gera todos os eventos estáticos 
    * da simulação, depois chama o método executarEventos() que começa a executar todos
    * os eventos gerados anteriormente e também a gerar mais eventos dinâmicos.  
    *
    * @see gerarEventos();
    * @see executarEventos();
    * @return Inteiro inteiro que indica se a execução do programa foi bem sucedida ou não.
    */
    int iniciar() {
        gerarEventos();
        return executarEventos();
    }

    /** Método gerarEventos().
    * Este método gera todos os eventos estáticos e os armazena na lista de eventos.
    * Os eventos estáticos são:
    * 
    *    1) Eventos de adicionar carros na pista
    *    2) Eventos de carros chegando no semáforo
    *    3) Eventos de troca de semáforos
    *
    * Como todos esses métodos acontecerão até o final da execução independente de fatores externos
    * podem ser criados agora. Caso o evento que está sendo gerado tenha um tempo maior do que o tempo
    * total de execução do programa, este não é armazenado (adicionado) na lista de eventos.
    *
    * @see Pista::retornaTamanho();
    * @see Pista::retornaDado(int posicao);
    * @see Pista::isFonte();
    * @see Pista::calculeProximoEvento(int tempoAtual);
    * @see ListaDeEventos::adicionaEmOrdem(Evento* e);
    */
    void gerarEventos() {

        system("clear");
        std::cout << "=================================================\n" << std::endl;
        std::cout << "\t      Criando eventos(1 / 3)" << std::endl;
        std::cout << "\n=================================================\n\n" << std::endl;
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
                        tempoInterno = tempoProximoEvento;
                    } else {
                        break;
                    }
                }
            }
        }
        
        system("clear");
        std::cout << "\r=================================================\n" << std::endl;
        std::cout << "\r\t      Criando eventos(2 / 3)" << std::endl;
        std::cout << "\r\n=================================================\n\n" << std::endl;
        // Gera eventos de carros no semaforo (tipo 2)
        Pista* atual;
        Semaforo* semaforo;
        Evento* evento;
        int tempoChegada;
        int tamanhoOriginal = listaEventos->retornaTamanho();
        for (int i = 0; i < tamanhoOriginal; i++) {
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
        
        system("clear");    
        std::cout << "\r=================================================\n" << std::endl;
        std::cout << "\r\t      Criando eventos(3 / 3)" << std::endl;
        std::cout << "\r\n=================================================\n\n" << std::endl;
        // Gera eventos de troca de semaforos (tipo 1)
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

    }


    /** Método executarCarroChegouNoSemaforo.
    * 
    * Esse método é disparado quando algum carro chegou no semáforo. Um evento precisa acontecer
    * e um novo evento (baseado nesse acontecimento) precisa ser gerado para que o carro possa
    * continuar. 
    *  
    * O carro chegou no semáforo, existem algumas coisas que podem acontecer:
    *
    *   1) Pista destino lotada -> nesse caso cria um evento desse mesmo carro que vai acontecer na próxima vez que o sinal estiver verde.
    *   2) ProximaPista é sumidouro -> cria um evento de que o carro vai ser deletado (tipo 3).
    *   3) ProximaPista é semaforo -> cria um evento de que o carro vai chegar no semáforo. (tipo 2)
    *   4) Sinal vermelho (o lançamento do throw) -> cria um evento no tempo seguinte de abertura do semáforo. (tempo de abertura do semaforo + 1)
    *
    * @param eventoAtual O evento que aconteceu, ou seja, o evento que indica que um carro chegou no semáforo.
    * @see Semaforo::passaCarro()
    * @see Semaforo::retornarTempoQueVaiAbrir()
    * @see Semaforo::retornaPistaLocal()
    * @see Semaforo::retornaIntervalo()
    * @see Evento::getObjeto()
    * @see Evento::getTempo()
    * @see Pista::isSumidouro()
    * @see Pista::tempoChegada()
    * @see Sistema::procurarPorSemaforo()
    * @see ListaEnc::adicionaEmOrdem()
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
                tempoProximoEvento = tempoAtual + (semaforo->retornarTempoQueVaiAbrir());
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

        // Se o tempo do evento a ser criado > tempoDeExecucao, não precisa criar o evento.
        if(tempoProximoEvento != -1 && tempoProximoEvento <= tempoDeExecucao) {
            listaEventos->adicionaEmOrdem(evento);
        }

    }

    /** Método executarEventos.
    * Esse método começa a executar todos os eventos estáticos criados pelo método "geraEventos".
    * Ele pega cada evento da lista ordenada de eventos e realiza o evento. Utiliza um switch
    * para identificar que evento que é e poder executar da forma correta. Depois, atualiza o 
    * tempoAtual atribuindo-o o valor do tempo do evento executado. Em seguida, remove o 
    * eventoAtual da lista de eventos e pega o próximo da lista, que está ordenada de forma
    * ascendente.
    *
    * @return int Inteiro indicando se a execução foi bem sucedida ou não.
    */
    int executarEventos() {

        system("clear");
        std::cout << "=================================================\n" << std::endl;
        std::cout << "\t       Executando eventos..." << std::endl;
        std::cout << "\n=================================================\n\n" << std::endl;

        for(int i = 0; i < listaEventos->retornaTamanho(); i++) {
            Evento* eventoAtual = listaEventos->retornaDado(i);

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
            listaEventos->retiraEspecifico(eventoAtual);
        }
        finalizarPrograma();
        return 0;
    }


    /** Método finalizarPrograma.
    * Este método é o último chamado pelo sistema e serve para imprimir informações ao usuário.
    * Chama o método "contarCarros" que serve para contar todos os carros que entraram e sairam
    * das pistas, além de calcular a vazão do sistema e mostrar quantos segundos foram simulados.
    * @see contarCarros()
    */
    void finalizarPrograma() {
        contarCarros(); 
        std::cout << "\n\n\n============ R E S U L T A D O S ================\n\n";
        std::cout << "\tForam simulados " << tempoDeExecucao << " segundos." << std::endl;
        std::cout << "\t" << carrosQueEntraram << " carros entraram no sistema." << std::endl;
        std::cout << "\t" << carrosQuePassaram << " carros passaram pelo sistema." << std::endl;
        std::cout << "\t       Vazão: " << (((float)carrosQuePassaram) * 100)/((float)carrosQueEntraram) << "%." << std::endl;
        std::cout << "\n=================================================" << std::endl;
    }

    /** Método contarCarrros.
    * Este método faz uma iteração por todas as pistas do sistema e verifica em todas as 
    * pistas que fonte e sumidouro quantos carros entraram e quantos carros sairam
    * do sistema. Armazena o resultado dessa busca nas variáveis "carrosQueEntraram" e
    * "carrosQuePassaram".
    *
    * @see Pista::retornaDado(int i)
    * @see Pista::isFonte()
    * @see Pista::isSumidouro()
    * @see Pista::retornaCarrosQueEntraram()
    * @see Pista::retornaCarrosQuePassaram()
    */
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

    /** Método procurarPorSemaforo.
    * Esse método serve para descobrir qual semáforo "é dono" (tem PistaLocal) a pista fornecida
    * como argumento. Retorna NULL caso não encontro nenhum Semáforo "dono" da pista
    * (ou seja, ela provavelmente é sumidouro).
    *
    * @see Semaforo::retornaPistaLocal()
    * @see Semaforo::retornaTamanho()
    * @see Semaforo::retornaDado()
    * @return Semaforo* Retorna um ponteiro para o semáforo que é "dono" da pista fornecida como argumento. Caso não encontre retorna NULL.
    */
    Semaforo* procurarPorSemaforo(Pista* pista) {
        for(int i = 0; i < semaforos->retornaTamanho(); i++){   
            Semaforo* atual = semaforos->retornaDado(i);
            if(atual->retornaPistaLocal() == pista) {
                return atual;
            }
        }
        return NULL;
    }

};

#endif

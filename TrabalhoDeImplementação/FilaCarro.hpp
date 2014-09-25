/**Projeto
*/
#ifndef FILACARRO_HPP_
#define FILACARRO_HPP_
#include "Fila.hpp"
class FilaCarro: private Fila<T>{
 private: 
 		int tamanho;
 		int espaco;
 public:
 		FilaCarro(int tam): Fila<T>(tam){}
 		AdicionaCarro(Carro c){
 			if(i < tamanho){
 				this->inclui(c);
 				espaco = (c->getTamanho()) + 3;
 			} else {
 				//throw ou outra informação a ser enviada;
 			}
 		}
};
#endif
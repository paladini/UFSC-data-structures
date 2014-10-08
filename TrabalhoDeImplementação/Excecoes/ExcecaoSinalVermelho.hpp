/**
* File: ExcecaoSinalVermelho.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 6 de Setembro de 2014, 20:52.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
#ifndef EXCECAOSINALVERMELHO_HPP_
#define EXCECAOSINALVERMELHO_HPP_
#include <exception>
/** Classe ExcecaoSinalVermelho.
* A classe ExcecaoSinalVermelho é uma classe de Exceção disparada quando um carro está no semáforo
* mas este está vermelho.
*/
	class ExcecaoSinalVermelho : public std::exception {
 public:
		virtual const char* mostrarMensagem() const throw() {
			return "Exceção Sinal Vermelho: o carro chegou no semáforo mas este está vermelho!";
		}
} ExcecaoSinalVermelho;
#endif /* EXCECAOSINALVERMELHO_HPP_ */

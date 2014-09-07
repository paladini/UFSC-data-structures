/**
* File: ExcecaoListaCheia.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 6 de Setembro de 2014, 20:52.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
#ifndef EXCECAOLISTACHEIA_HPP_
#define EXCECAOLISTACHEIA_HPP_
#include <exception>
/** Classe ExcecaoListaCheia.
* A classe ExcecaoListaCheia é uma classe de Exceção disparada quando o usuário tenta inserir
* um elemento na estrutura de dados em questão mesmo com esta já estando cheia.
*/
class ExcecaoListaCheia : public std::exception {
 public:
	virtual const char* mostrarMensagem() const throw() {
		return "Exceção Lista Cheia!";
	}
} ExcecaoListaCheia;

#endif /* EXCECAOLISTACHEIA_HPP_ */

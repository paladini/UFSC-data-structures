/**
* File: ExcecaoListaVazia.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 6 de Setembro de 2014, 20:52.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
#ifndef EXCECAOLISTAVAZIA_HPP_
#define EXCECAOLISTAVAZIA_HPP_
#include <exception>
/** Classe ExcecaoListaVazia.
* A classe ExcecaoListaVazia é uma classe de Exceção disparada quando o usuário tenta recuperar
* um elemento da estrutura de dados em questão e essa estrutura encontra-se vazia.
*/
	class ExcecaoListaVazia : public std::exception {
 public:
		virtual const char* mostrarMensagem() const throw() {
			return "Exceção Lista Vazia!";
		}
} ExcecaoListaVazia;
#endif /* EXCECAOLISTAVAZIA_HPP_ */
